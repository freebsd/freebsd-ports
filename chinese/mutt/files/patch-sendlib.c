--- sendlib.c.orig	2016-12-02 11:18:42.515424000 +0800
+++ sendlib.c	2016-12-02 11:18:42.605557000 +0800
@@ -2494,7 +2494,7 @@ void mutt_prepare_envelope (ENVELOPE *en
   rfc2047_encode_adrlist (env->reply_to, "Reply-To");
   rfc2047_encode_string (&env->x_label);
 
-  if (env->subject)
+  if (env->subject && !option(OPTBBSISLAME))
   {
     rfc2047_encode_string (&env->subject);
   }
