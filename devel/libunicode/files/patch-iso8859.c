--- iso8859.c.orig	Fri Oct 29 15:15:19 1999
+++ iso8859.c	Wed Jun  5 02:43:26 2002
@@ -271,6 +271,8 @@
 #define ISO_DEFINE(Num)							      \
 static char * n ## Num [] = { "8859-"  # Num,				      \
 			      "ISO-8859-" # Num,			      \
+			      "ISO_8859-1" # Num,                             \
+			      "ISO8859-" # Num,                               \
 			      NULL };					      \
 unicode_encoding_t P3 (unicode_iso8859_, Num, _encoding) =		      \
 {									      \
