--- libpolyml/xwindows.cpp.orig	2020-07-17 08:44:22 UTC
+++ libpolyml/xwindows.cpp
@@ -7302,7 +7302,7 @@ static void DebugPrintWord(PolyWord P /* was X_Object 
                              : printf("Old Display <%p>",P.AsAddress()));
             return;
             
-        default:         printf("Pointer "ZERO_X"%p",P.AsAddress());
+        default:         printf("Pointer 'ZERO_X' %p", P.AsAddress());
             return;
         }
     }
