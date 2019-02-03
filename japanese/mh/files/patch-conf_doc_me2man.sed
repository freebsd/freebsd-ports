--- conf/doc/me2man.sed.orig	1993-12-01 04:00:17 UTC
+++ conf/doc/me2man.sed
@@ -8,3 +8,7 @@
 /^\.DE$/c\
 .in -.5i\
 .SH DESCRIPTION
+## replace delimiter and padding character used with .fc macro
+s/^^\(.*\)~^\(.*\)$/\1	\2/
+## "\ " and "\0" losts the whitespace with mandoc
+s/\\[ 0]/ /g
