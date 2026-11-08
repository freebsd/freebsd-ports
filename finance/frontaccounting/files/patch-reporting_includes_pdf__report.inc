--- reporting/includes/pdf_report.inc.orig	2026-04-28 11:25:37 UTC
+++ reporting/includes/pdf_report.inc
@@ -1008,6 +1008,16 @@
     					$msg = _("Dear") . " " . $contact['name2'] . ",\n\n" 
     						. _("Attached you will find ") . " " . $subject ."\n\n";
 
+						$custom_email = array();
+						$email_template = company_path() . '/reporting/email_template.php';
+						if (is_file($email_template)) {
+							$format_email = include($email_template);
+							if (is_callable($format_email))
+								$custom_email = $format_email($contact, $this->formData, $this->company, $this->user);
+							if (isset($custom_email['body']))
+								$msg = $custom_email['body'];
+						}
+
 						if (isset($this->formData['payment_service']))
 						{
 							$amt = number_format($this->formData['document_amount'], user_price_dec());
@@ -1024,7 +1034,9 @@
 
 	    				$msg .= _("Kindest regards") . "\n\n";
     					$sender = $this->user . "\n" . $coy_name . "\n" . $this->company['postal_address'] . "\n" . $this->company['email'] . "\n" . $this->company['phone'];
-    					$mail->to(str_replace(",", "", $contact['name'].' '.$contact['name2']), $contact['email']);
+    					if (isset($custom_email['sender']))
+							$sender = $custom_email['sender'];
+						$mail->to(str_replace(",", "", $contact['name'].' '.$contact['name2']), $contact['email']);
     					$try++;
     					$mail->subject($subject);
     					$mail->text($msg . $sender);
