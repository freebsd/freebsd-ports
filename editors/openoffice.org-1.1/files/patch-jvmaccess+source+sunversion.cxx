--- ../jvmaccess/source/sunversion.cxx.orig	Sun Mar 30 00:40:02 2003
+++ ../jvmaccess/source/sunversion.cxx	Sun Mar 30 01:31:48 2003
@@ -102,6 +102,7 @@
         {
             //token can be "1", or "2_02"
             char* pUnderscore= strpbrk(tok,"_");
+            char* pLine= strpbrk(tok,"-");
             if( pUnderscore != NULL)
             {
                 // get the value before and after the underscore
@@ -115,6 +116,19 @@
                 // now get the part after "_"
                 m_nMinor= atoi( pUnderscore + 1);
             }
+            else if (pLine != NULL)
+            {
+                // get the value before and after the underscore
+                int len= pLine - tok;
+                char* pre= new char[len  + 1];
+                strncpy( pre, tok, len);
+                pre[len]= 0;
+                // convert the value before the "_" into a numeric value
+                arTokens[index]= atoi(pre);
+                delete[] pre;
+                // now get the part after "-"
+                m_nMinor= atoi( pLine + 1);
+            }
             else
             {
                 arTokens[index]= atoi(tok);
@@ -172,6 +186,19 @@
                     continue;
             }
         }
+        if(cCur == '-')
+        {
+            //check previous char
+            if(cLast >= 48 && cLast <= 57)
+            {
+                if(cNext == 'p')
+                    continue;
+            }
+        }
+        if(cCur == 'p')
+	{
+                    continue;
+	}
         //If we get here then the current character is not a number (0..9),'.','_'
         ret= false;
         break;
