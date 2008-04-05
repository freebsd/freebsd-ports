--- ide/bin/launcher.sh.orig	Tue Jan 15 21:35:22 2008
+++ ide/bin/launcher.sh	Tue Jan 15 21:43:52 2008
@@ -191,12 +191,12 @@
 #-----------------------------------------------------------------------------
 AddVMOption()
 {
-  NEWOPD=`expr "$1" : '[^\=]*\=\(.*\)'`
+  NEWOPD=`expr -- "$1" : '[^\=]*\=\(.*\)'`
   if [ "X$NEWOPD" != "X" ]
   then
-    if [ "X`expr "$NEWOPD" : '.*\( \).*'`" != "X" ]
+    if [ "X`expr -- "$NEWOPD" : '.*\( \).*'`" != "X" ]
     then
-      NEWARG=`expr "$1" : '\([^\=]*\)\=.*'`
+      NEWARG=`expr -- "$1" : '\([^\=]*\)\=.*'`
       NEWARG="$NEWARG=\"$NEWOPD\""
     else
       NEWARG=$1
@@ -329,15 +329,15 @@
     while [ -h "$tmpvar" ]
     do
         tmpvar2=`ls -ls "$tmpvar"`
-        tmpvar2=`expr "$tmpvar2" : '.*-> \(.*\)$'`
-        if [ `expr "$tmpvar2" : "\.\/"` -gt 0 -o `expr "$tmpvar2" : "\.\.\/"` -gt 0 -o `expr "$tmpvar2" : ".*/.*"` -le 0 ]
+        tmpvar2=`expr -- "$tmpvar2" : '.*-> \(.*\)$'`
+        if [ `expr -- "$tmpvar2" : "\.\/"` -gt 0 -o `expr -- "$tmpvar2" : "\.\.\/"` -gt 0 -o `expr -- "$tmpvar2" : ".*/.*"` -le 0 ]
         then
           tmpvar="`dirname $tmpvar`/$tmpvar2"
         else
           tmpvar="$tmpvar2"
         fi
     done
-    tmpvar=`expr "$tmpvar" : '\(.*\)\/bin\/[^\/]*$'`
+    tmpvar=`expr -- "$tmpvar" : '\(.*\)\/bin\/[^\/]*$'`
     SetJavaHome "$tmpvar"
   fi
 }
@@ -610,8 +610,8 @@
         case $1 in 
           --*)
             NEWARG=`echo $1 | sed -e s/--//g`
-            NEWOPD=`expr "$NEWARG" : '[^\=]*\=\(.*\)'`
-            NEWARG=`expr "$NEWARG" : '\([^\=]*\)\=.*'`
+            NEWOPD=`expr -- "$NEWARG" : '[^\=]*\=\(.*\)'`
+            NEWARG=`expr -- "$NEWARG" : '\([^\=]*\)\=.*'`
             NEWARG=`echo $NEWARG | tr "[:upper:]" "[:lower:]"`
             case $NEWARG in
               setjavahome)         NEWARG="SetJavaHome" ;;
@@ -697,11 +697,11 @@
     if [ $? -gt 0 ]
     then
             s=`${JAVA} -version 2>&1`
-            if [ `expr "$s" : 'java version \"1\.[0-3]'` -gt 0 ]
+            if [ `expr -- "$s" : 'java version \"1\.[0-3]'` -gt 0 ]
             then
                     echo "Error: `GetShortProductName` doesn't run with JDK version prior to 1.4.x" 
             fi
-            if [ `expr "$s" : 'java version \"1\.[0-5].*\"'` -le 0 ]
+            if [ `expr -- "$s" : 'java version \"1\.[0-5].*\"'` -le 0 ]
             then
                     echo "Error: `GetShortProductName` can't recognize the JDK version"
             fi
