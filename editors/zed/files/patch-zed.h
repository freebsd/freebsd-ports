--- zed.h.orig	Sun Nov 17 22:35:46 2002
+++ zed.h	Sun Nov 17 22:35:09 2002
@@ -123,8 +123,8 @@
   int lung;
   char dati[0];  // puntatore ai dati
 
-  friend editor; // solo pero' all'interno di ZED.H
-  friend list;
+  friend class editor; // solo pero' all'interno di ZED.H
+  friend class list;
  };
 
  protected:
