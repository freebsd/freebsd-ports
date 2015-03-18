--- src/VBox/VMM/VMMR3/PDMDriver.cpp.orig	2015-03-02 10:10:12.000000000 -0500
+++ src/VBox/VMM/VMMR3/PDMDriver.cpp	2015-03-12 20:01:00.170988000 -0400
@@ -512,11 +512,7 @@
                 AssertLogRelRCReturn(rc, rc);
 
                 rc = CFGMR3ReplaceSubTree(*ppNode, pBelowThisCopy);
-                if (RT_FAILURE(rc))
-                {
-                    CFGMR3RemoveNode(pBelowThis);
-                    AssertLogRelReturn(("rc=%Rrc\n", rc), rc);
-                }
+                AssertLogRelRCReturnStmt(rc, CFGMR3RemoveNode(pBelowThis), rc);
             }
         }
         /*
