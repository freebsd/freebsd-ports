--- src/typesize.sh.orig	Tue Jul 27 13:24:17 2004
+++ src/typesize.sh	Thu Aug 19 18:30:43 2004
@@ -21,7 +21,7 @@
 	:
       else
 	x=$?
-	p=`echo $i | sed 's/ /_/g' | tr "[a-z]]" "[A-Z]"`
+	p=`echo $i | sed 's/ /_/g' | tr "[:lower:]" "[:upper:]"`
 	echo "#define SIZEOF_$p $x /* systype-info */"
       fi
     fi
