--- fwd_x11.c.orig	2022-03-01 13:41:18 UTC
+++ fwd_x11.c
@@ -398,7 +398,7 @@ static boolType setupX11Dll (const char *dllName)
             (ptr_XSetClipOrigin          = (tp_XSetClipOrigin)          dllFunc(x11Dll, "XSetClipOrigin"))          == NULL ||
             (ptr_XSetForeground          = (tp_XSetForeground)          dllFunc(x11Dll, "XSetForeground"))          == NULL ||
             (ptr_XSetFunction            = (tp_XSetFunction)            dllFunc(x11Dll, "XSetFunction"))            == NULL ||
-            (ptr_XSetLineAttributes      = (tp_XSetLineAttributes       dllFunc(x11Dll, "XSetLineAttributes"))      == NULL ||
+            (ptr_XSetLineAttributes      = (tp_XSetLineAttributes)      dllFunc(x11Dll, "XSetLineAttributes"))      == NULL ||
             (ptr_XSetStandardProperties  = (tp_XSetStandardProperties)  dllFunc(x11Dll, "XSetStandardProperties"))  == NULL ||
             (ptr_XSetWMHints             = (tp_XSetWMHints)             dllFunc(x11Dll, "XSetWMHints"))             == NULL ||
             (ptr_XSetWMProtocols         = (tp_XSetWMProtocols)         dllFunc(x11Dll, "XSetWMProtocols"))         == NULL ||
@@ -1609,9 +1609,9 @@ int XSetLineAttributes (Display *display, GC gc, unsig
     logFunction(printf("XSetLineAttributes(" FMT_U_MEM ", " FMT_U_MEM
                        ", %u, %d, &d, %d)\n",
                        (memSizeType) display, (memSizeType) gc,
-                       line_width, line_style, cap_stype, join_style););
+                       line_width, line_style, cap_style, join_style););
     funcResult = ptr_XSetLineAttributes(display, gc, line_width,
-                                        line_style, cap_stype, join_style);
+                                        line_style, cap_style, join_style);
     logFunction(printf("XSetLineAttributes --> %d\n", funcResult););
     return funcResult;
   } /* XSetLineAttributes */
