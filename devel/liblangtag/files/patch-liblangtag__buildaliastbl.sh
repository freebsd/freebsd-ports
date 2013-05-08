--- liblangtag/buildaliastbl.sh.orig	2012-12-13 03:59:17.000000000 -0500
+++ liblangtag/buildaliastbl.sh	2013-05-08 12:49:17.000000000 -0400
@@ -51,7 +51,7 @@
 static lt_localealias_t __lt_localealias_tables[] = {
 EOF
 
-iconv -f iso8859-1 -t utf-8 $1 | sed -e '/^#.*/{d};/^$/{d};' -e 's/^\([^ \t]*\)[ \t]*\([^ \t]*\)$/\t{"\1", "\2"},/'
+iconv -f iso8859-1 -t utf-8 $1 | awk '{ if ($0 !~ /^(#.*)?$/) { printf("\t{\"%s\", \"%s\"},\n", $1, $2); } }'
 
 cat<<EOF
 	{NULL, NULL}
