--- gnats/edit-pr.sh.orig	2011-12-12 13:42:33.000000000 +0200
+++ gnats/edit-pr.sh	2011-12-12 13:43:51.000000000 +0200
@@ -169,7 +169,7 @@
 	    type="`$QUERY_PR --field-type $field`"
 	    case $type in
 		[Ee][Nn][Uu][Mm])
-		    values=`$QUERY_PR --valid-values $field | tr '\n' ' ' | sed 's/ *$//g; s/ / | /g;s/^/[ /;s/$/ ]/;`
+		    values=`$QUERY_PR --valid-values $field | tr '\n' ' ' | sed 's/ *$//g; s/ / | /g;s/^/[ /;s/$/ ]/;'`
 		    valslen=`echo "$values" | wc -c`
 		    if [ "$valslen" -gt 160 ]
 		    then
