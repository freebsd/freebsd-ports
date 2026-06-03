--- src/typesize.sh.orig	2004-07-27 11:24:17 UTC
+++ src/typesize.sh
@@ -21,7 +21,7 @@ for i in "short" "int" "long " "unsigned short" "unsig
 	:
       else
 	x=$?
-	p=`echo $i | sed 's/ /_/g' | tr "[a-z]]" "[A-Z]"`
+	p=`echo $i | sed 's/ /_/g' | tr "[:lower:]" "[:upper:]"`
 	echo "#define SIZEOF_$p $x /* systype-info */"
       fi
     fi
