--- parse.c.orig	Sat Apr 22 16:49:29 2000
+++ parse.c	Sat Aug  5 14:25:02 2000
@@ -407,10 +407,11 @@
       else if (!mutt_strcasecmp ("description", line + 8))
       {
 	mutt_str_replace (&p->description, c);
-	rfc2047_decode (p->description, p->description, mutt_strlen (p->description) + 1);
       }
     }
   }
+  if (p->description) rfc2047_decode (p->description, p->description, mutt_strlen (p->description) + 1);
+  if (p->filename) rfc2047_decode (p->filename, p->filename, mutt_strlen (p->filename) + 1);
   p->offset = ftell (fp); /* Mark the start of the real data */
   if (p->type == TYPETEXT && !p->subtype)
     p->subtype = safe_strdup ("plain");
