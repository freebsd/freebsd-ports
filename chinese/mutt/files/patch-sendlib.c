--- sendlib.c.orig	Fri Aug 11 11:28:58 2000
+++ sendlib.c	Fri Aug 11 11:29:19 2000
@@ -1825,13 +1825,14 @@
   rfc2047_encode_adrlist (env->from);
   rfc2047_encode_adrlist (env->mail_followup_to);
   rfc2047_encode_adrlist (env->reply_to);
-
+  /*
   if (env->subject)
   {
     rfc2047_encode_string (buffer, sizeof (buffer) - 1,
 			   (unsigned char *) env->subject);
     mutt_str_replace (&env->subject, buffer);
   }
+  */
   encode_headers (env->userhdrs);
 }
 
