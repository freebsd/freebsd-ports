diff --git a/git-send-email.perl b/git-send-email.perl
index eea0a517f71b6..0d90439d9a8e5 100755
--- git-send-email.perl
+++ git-send-email.perl
@@ -1353,10 +1353,12 @@ sub send_message {
 			die __("The required SMTP server is not properly defined.")
 		}
 
+		require Net::SMTP;
+		my $use_net_smtp_ssl = version->parse($Net::SMTP::VERSION) < version->parse("2.34");
+		$smtp_domain ||= maildomain();
+
 		if ($smtp_encryption eq 'ssl') {
 			$smtp_server_port ||= 465; # ssmtp
-			require Net::SMTP::SSL;
-			$smtp_domain ||= maildomain();
 			require IO::Socket::SSL;
 
 			# Suppress "variable accessed once" warning.
@@ -1368,34 +1370,48 @@ sub send_message {
 			# Net::SMTP::SSL->new() does not forward any SSL options
 			IO::Socket::SSL::set_client_defaults(
 				ssl_verify_params());
-			$smtp ||= Net::SMTP::SSL->new($smtp_server,
-						      Hello => $smtp_domain,
-						      Port => $smtp_server_port,
-						      Debug => $debug_net_smtp);
+
+			if ($use_net_smtp_ssl) {
+				require Net::SMTP::SSL;
+				$smtp ||= Net::SMTP::SSL->new($smtp_server,
+							      Hello => $smtp_domain,
+							      Port => $smtp_server_port,
+							      Debug => $debug_net_smtp);
+			}
+			else {
+				$smtp ||= Net::SMTP->new($smtp_server,
+							 Hello => $smtp_domain,
+							 Port => $smtp_server_port,
+							 Debug => $debug_net_smtp,
+							 SSL => 1);
+			}
 		}
 		else {
-			require Net::SMTP;
-			$smtp_domain ||= maildomain();
 			$smtp_server_port ||= 25;
 			$smtp ||= Net::SMTP->new($smtp_server,
 						 Hello => $smtp_domain,
 						 Debug => $debug_net_smtp,
 						 Port => $smtp_server_port);
 			if ($smtp_encryption eq 'tls' && $smtp) {
-				require Net::SMTP::SSL;
-				$smtp->command('STARTTLS');
-				$smtp->response();
-				if ($smtp->code == 220) {
+				if ($use_net_smtp_ssl) {
+					$smtp->command('STARTTLS');
+					$smtp->response();
+					if ($smtp->code != 220) {
+						die sprintf(__("Server does not support STARTTLS! %s"), $smtp->message);
+					}
+					require Net::SMTP::SSL;
 					$smtp = Net::SMTP::SSL->start_SSL($smtp,
 									  ssl_verify_params())
-						or die "STARTTLS failed! ".IO::Socket::SSL::errstr();
-					$smtp_encryption = '';
-					# Send EHLO again to receive fresh
-					# supported commands
-					$smtp->hello($smtp_domain);
-				} else {
-					die sprintf(__("Server does not support STARTTLS! %s"), $smtp->message);
+						or die sprintf(__("STARTTLS failed! %s"), IO::Socket::SSL::errstr());
+				}
+				else {
+					$smtp->starttls(ssl_verify_params())
+						or die sprintf(__("STARTTLS failed! %s"), IO::Socket::SSL::errstr());
 				}
+				$smtp_encryption = '';
+				# Send EHLO again to receive fresh
+				# supported commands
+				$smtp->hello($smtp_domain);
 			}
 		}
 
