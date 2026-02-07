--- qmls/cdl.cpp.orig	2018-08-25 04:01:56 UTC
+++ qmls/cdl.cpp
@@ -125,7 +125,7 @@ istream& operator>>(istream& ins, CanonicalDecimalList
       case ',':
         if (index != 0)
         {
-          buf[index] = (char)NULL;
+          buf[index] = '\0';
           str = buf;
           inputStack.Push(str);
           index = 0;
@@ -175,7 +175,7 @@ istream& operator>>(istream& ins, CanonicalDecimalList
       case ',':
         if (index != 0)
         {
-          buf[index] = (char)NULL;
+          buf[index] = '\0';
           careStack.Push(atoi(buf));
           index = 0;
         }
@@ -226,7 +226,7 @@ istream& operator>>(istream& ins, CanonicalDecimalList
         case ',':
           if (index != 0)
           {
-            buf[index] = (char)NULL;
+            buf[index] = '\0';
             dontCareStack.Push(atoi(buf));
             index = 0;
           }
@@ -295,4 +295,4 @@ bool GetAlphaNumeric(istream& ins, char& ch)
     return true;
   }
   return false;
-}
\ No newline at end of file
+}
