src/SFML/Window/Unix/WindowImplX11.cpp:1278:36: error: reinterpret_cast from 'nullptr_t' to 'void *' is not allowed
                                   reinterpret_cast<void*>(NULL));
                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- src/SFML/Window/Unix/WindowImplX11.cpp.orig	2017-02-08 11:29:16 UTC
+++ src/SFML/Window/Unix/WindowImplX11.cpp
@@ -1275,7 +1275,7 @@ void WindowImplX11::initialize()
                                    m_window,
                                    XNInputStyle,
                                    XIMPreeditNothing | XIMStatusNothing,
-                                   reinterpret_cast<void*>(NULL));
+                                   static_cast<void*>(NULL));
     }
     else
     {
