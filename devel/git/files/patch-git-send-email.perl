--- git-send-email.perl.orig	2017-03-21 10:10:31 UTC
+++ git-send-email.perl
@@ -27,6 +27,7 @@ use Term::ANSIColor;
 use File::Temp qw/ tempdir tempfile /;
 use File::Spec::Functions qw(catfile);
 use Error qw(:try);
+use Net::SMTP 2.34;
 use Git;
 use Git::I18N;
 
@@ -1355,7 +1356,6 @@ EOF
 
 		if ($smtp_encryption eq 'ssl') {
 			$smtp_server_port ||= 465; # ssmtp
-			require Net::SMTP::SSL;
 			$smtp_domain ||= maildomain();
 			require IO::Socket::SSL;
 
@@ -1365,35 +1365,22 @@ EOF
 				$IO::Socket::SSL::DEBUG = 1;
 			}
 
-			# Net::SMTP::SSL->new() does not forward any SSL options
-			IO::Socket::SSL::set_client_defaults(
-				ssl_verify_params());
-			$smtp ||= Net::SMTP::SSL->new($smtp_server,
-						      Hello => $smtp_domain,
-						      Port => $smtp_server_port,
-						      Debug => $debug_net_smtp);
+			$smtp = Net::SMTP->new($smtp_server,
+					       Hello => $smtp_domain,
+					       Port => $smtp_server_port,
+					       SSL => 1,
+					       ssl_verify_params(),
+					       Debug => $debug_net_smtp);
 		}
 		else {
-			require Net::SMTP;
-			$smtp_domain ||= maildomain();
 			$smtp_server_port ||= 25;
-			$smtp ||= Net::SMTP->new($smtp_server,
+			$smtp = Net::SMTP->new($smtp_server,
 						 Hello => $smtp_domain,
 						 Debug => $debug_net_smtp,
 						 Port => $smtp_server_port);
 			if ($smtp_encryption eq 'tls' && $smtp) {
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
+				$smtp->starttls(ssl_verify_params());
+				if ($smtp->code != 250) {
 					die sprintf(__("Server does not support STARTTLS! %s"), $smtp->message);
 				}
 			}
