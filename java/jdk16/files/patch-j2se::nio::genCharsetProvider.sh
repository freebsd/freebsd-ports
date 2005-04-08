$FreeBSD$

--- ../../j2se/make/java/nio/genCharsetProvider.sh	8 Nov 2004 22:27:03 -0000	1.1.1.1
+++ ../../j2se/make/java/nio/genCharsetProvider.sh	24 Mar 2005 16:14:52 -0000
@@ -94,9 +94,9 @@
   }
 '
 
-$JAVA -cp $TMPDIR Hasher -i Aliases <$TMPDIR/aliases >>$OUT
-$JAVA -cp $TMPDIR Hasher -i Classes <$TMPDIR/classes >>$OUT
-$JAVA -cp $TMPDIR Hasher -i -e Cache -t Charset <$TMPDIR/classes >>$OUT
+$JAVA -cp $TMPDIR Hasher -i Aliases <$TMPDIR/aliases | egrep -v '^Java Hotspot' >>$OUT
+$JAVA -cp $TMPDIR Hasher -i Classes <$TMPDIR/classes | egrep -v '^Java Hotspot' >>$OUT
+$JAVA -cp $TMPDIR Hasher -i -e Cache -t Charset <$TMPDIR/classes | egrep -v '^Java Hotspot' >>$OUT
 
 
 # Constructor
