--- ../sw/source/filter/ww8/ww8par.cxx.orig	2003-02-07 01:34:02.000000000 +0900
+++ ../sw/source/filter/ww8/ww8par.cxx	2003-04-10 07:04:46.000000000 +0900
@@ -1558,11 +1558,20 @@
             if (bVer67)
             {
                 sal_Char aTest[2];
-                aTest[0] = (nUCode & 0xFF00) >> 8;
-                aTest[1] = (nUCode & 0x00FF);
-                String aTemp(aTest, 2, eSrcCharSet);
-                ASSERT(aTemp.Len() == 1, "so much for that theory");
-                *pWork = aTemp.GetChar(0);
+                if (nUCode >= 0x3000)
+                {
+                        aTest[0] = (nUCode & 0xFF00) >> 8;
+                        aTest[1] = (nUCode & 0x00FF);
+                        String aTemp(aTest, 2, eSrcCharSet);
+                        ASSERT(aTemp.Len() == 1, "so much for that theory");
+                        *pWork = aTemp.GetChar(0);
+                }
+                else
+                {
+                        aTest[0] = (nUCode & 0x00FF);
+                        String aTemp(aTest, 1, eSrcCharSet);
+                        *pWork = aTemp.GetChar(0);
+                }
             }
             else
 			    *pWork = nUCode;
@@ -3099,7 +3108,8 @@
 	{
         case 6:
         case 7:
-            if ( (0xa5dc != nMagic) && (0xa699 != nMagic) )
+            //if ( (0xa5dc != nMagic) && (0xa699 != nMagic) )	//Takashi Ono
+            if ( (0xa5dc != nMagic) && ( (0xa697 > nMagic) || (0xa699 < nMagic) ) )
             {
                 //JP 06.05.99: teste auf eigenen 97-Fake!
                 if (pStg && 0xa5ec == nMagic)
