--- src/nativeinputserver.cpp.orig	Sun Feb 10 01:18:58 2002
+++ src/nativeinputserver.cpp	Sun Feb 24 14:25:35 2002
@@ -151,10 +151,31 @@
             }
             else {
                 mInput.erase(mInput.end() - 1);
-                Beep();
+                //Beep();
+                switch(c)
+                {
+                    case '0':
+                    case '1':
+                    case '2':
+                    case '3':
+                    case '4':
+                    case '5':
+                    case '6':
+                    case '7':
+                    case '8':
+                    case '9':
+                    case '+':
+                    case '=':
+                    case '-':
+                    case '_':
+                        goto Select;
+                    default:
+                        Beep();
+                }
             }
         }
     } else {
+Select:
         if (mList.mCount > 0) {
             switch (c) {
                 case 033:
@@ -210,6 +231,9 @@
                     if (c < mShownWords) {
                         s = Select(c);
                         rBuf = s;
+                        mpIme->Reset();
+                        mInput = "";
+                        mList.Reset();
                     } else
                         Beep();
                     break;
