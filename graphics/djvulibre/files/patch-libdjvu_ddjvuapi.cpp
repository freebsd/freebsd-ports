
$FreeBSD$

--- libdjvu/ddjvuapi.cpp.orig
+++ libdjvu/ddjvuapi.cpp
@@ -548,7 +548,7 @@
           ctx->mlist.del(s);
       }
     }
-  G_CATCH()
+  G_CATCH(ex)
     {
     }
   G_ENDCATCH;
