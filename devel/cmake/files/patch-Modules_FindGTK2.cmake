commit 508e8ca024e47baea342da85c7bbd014c7fd6c30
Author: Daniele E. Domenichelli <ddomenichelli@kde.org>
Date:   Mon Jun 17 17:31:10 2013 +0200

    FindGTK2: Detect gthread library

commit 76c72b9f14258933e4cf810da275bd2b931c5ac9
Author: Daniele E. Domenichelli <daniele.domenichelli@iit.it>
Date:   Wed Jul 31 17:39:38 2013 +0200

    FindGTK2: gthread-2.0 folder does not exist

    Partially revert commit 508e8ca024e47baea342da85c7bbd014c7fd6c30

--- Modules/FindGTK2.cmake.orig	2013-09-29 17:29:09.000000000 +0300
+++ Modules/FindGTK2.cmake	2013-09-29 17:29:42.000000000 +0300
@@ -463,6 +463,8 @@
         _GTK2_FIND_INCLUDE_DIR(GTK2_GDK_PIXBUF_INCLUDE_DIR gdk-pixbuf/gdk-pixbuf.h)
         _GTK2_FIND_LIBRARY    (GTK2_GDK_PIXBUF_LIBRARY gdk_pixbuf false true)
 
+        _GTK2_FIND_LIBRARY    (GTK2_GTHREAD_LIBRARY gthread false true)
+
         _GTK2_FIND_LIBRARY    (GTK2_GIO_LIBRARY gio false true)
 
         _GTK2_FIND_INCLUDE_DIR(GTK2_ATK_INCLUDE_DIR atk/atk.h)
