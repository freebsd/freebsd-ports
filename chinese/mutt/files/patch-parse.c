--- parse.c.orig	2016-10-09 03:30:21.000000000 +0800
+++ parse.c	2016-12-02 11:18:42.603025000 +0800
@@ -393,7 +393,10 @@ static void parse_content_disposition (c
   {
     s = skip_email_wsp(s + 1);
     if ((s = mutt_get_parameter ("filename", (parms = parse_parameters (s)))))
-      mutt_str_replace (&ct->filename, s);
+       {
+ 	mutt_str_replace (&ct->filename, s);
+ 	rfc2047_decode (&ct->filename);
+       }
     if ((s = mutt_get_parameter ("name", parms)))
       ct->form_name = safe_strdup (s);
     mutt_free_parameter (&parms);
