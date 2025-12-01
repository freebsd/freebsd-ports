Fix configure with Qt 6.10.

https://github.com/hluk/CopyQ/pull/3339/

--- src/platform/x11/x11platform.cmake.orig	2025-10-22 07:58:33 UTC
+++ src/platform/x11/x11platform.cmake
@@ -39,7 +39,7 @@ if (WITH_X11)
     set(copyq_LIBRARIES ${copyq_LIBRARIES} ${X11_LIBRARIES} ${X11_Xfixes_LIB})
 
     if(WITH_QT6)
-        if (QT_VERSION VERSION_GREATER_EQUAL "6.10.0")
+        if (Qt6_VERSION VERSION_GREATER_EQUAL "6.10.0")
             find_package(${copyq_qt} ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS GuiPrivate)
         endif()
         list(APPEND copyq_LIBRARIES Qt::GuiPrivate)
