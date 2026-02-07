--- modules/doctools/mpformats/_html.tcl.orig	2016-02-04 05:14:14 UTC
+++ modules/doctools/mpformats/_html.tcl
@@ -129,7 +129,7 @@ proc stable {}         {return [markup "
 proc link   {text url} {return [markup "<a href=\"$url\">"]$text[markup </a>]}
 
 proc tcl_cmd {cmd} {return "[markup <b>]\[$cmd][markup </b>]"}
-proc wget    {url} {exec /usr/bin/wget -q -O - $url 2>/dev/null}
+proc wget    {url} {exec /usr/bin/fetch -q -o - $url 2>/dev/null}
 
 proc url {tag text url} {
     set body {
