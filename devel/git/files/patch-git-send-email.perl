Refactor send_message() to remove dependency on deprecated
Net::SMTP::SSL:

<http://search.cpan.org/~rjbs/Net-SMTP-SSL-1.04/lib/Net/SMTP/SSL.pm#DEPRECATED>

Signed-off-by: Mike Fisher <mfisher@csh.rit.edu>
--- git-send-email.perl.orig	2016-11-29 21:06:51 UTC
+++ git-send-email.perl
@@ -1335,10 +1335,13 @@ Message-Id: $message_id
 			die "The required SMTP server is not properly defined."
 		}
 
+		require Net::SMTP;
+		$smtp_domain ||= maildomain();
+		my $smtp_ssl = 0;
+
 		if ($smtp_encryption eq 'ssl') {
 			$smtp_server_port ||= 465; # ssmtp
-			require Net::SMTP::SSL;
-			$smtp_domain ||= maildomain();
+			$smtp_ssl = 1;
 			require IO::Socket::SSL;
 
 			# Suppress "variable accessed once" warning.
@@ -1347,37 +1350,31 @@ Message-Id: $message_id
 				$IO::Socket::SSL::DEBUG = 1;
 			}
 
-			# Net::SMTP::SSL->new() does not forward any SSL options
 			IO::Socket::SSL::set_client_defaults(
 				ssl_verify_params());
-			$smtp ||= Net::SMTP::SSL->new($smtp_server,
-						      Hello => $smtp_domain,
-						      Port => $smtp_server_port,
-						      Debug => $debug_net_smtp);
 		}
 		else {
-			require Net::SMTP;
-			$smtp_domain ||= maildomain();
 			$smtp_server_port ||= 25;
-			$smtp ||= Net::SMTP->new($smtp_server,
-						 Hello => $smtp_domain,
-						 Debug => $debug_net_smtp,
-						 Port => $smtp_server_port);
-			if ($smtp_encryption eq 'tls' && $smtp) {
-				require Net::SMTP::SSL;
-				$smtp->command('STARTTLS');
-				$smtp->response();
-				if ($smtp->code == 220) {
-					$smtp = Net::SMTP::SSL->start_SSL($smtp,
-									  ssl_verify_params())
-						or die "STARTTLS failed! ".IO::Socket::SSL::errstr();
-					$smtp_encryption = '';
-					# Send EHLO again to receive fresh
-					# supported commands
-					$smtp->hello($smtp_domain);
-				} else {
-					die "Server does not support STARTTLS! ".$smtp->message;
-				}
+		}
+
+		$smtp ||= Net::SMTP->new($smtp_server,
+					 Hello => $smtp_domain,
+					 Port => $smtp_server_port,
+					 Debug => $debug_net_smtp,
+					 SSL => $smtp_ssl);
+
+		if ($smtp_encryption eq 'tls' && $smtp) {
+			$smtp->command('STARTTLS');
+			$smtp->response();
+			if ($smtp->code == 220) {
+				$smtp->starttls(ssl_verify_params())
+					or die "STARTTLS failed! ".IO::Socket::SSL::errstr();
+				$smtp_encryption = '';
+				# Send EHLO again to receive fresh
+				# supported commands
+				$smtp->hello($smtp_domain);
+			} else {
+				die "Server does not support STARTTLS! ".$smtp->message;
 			}
 		}
 
