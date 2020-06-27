--- lib/python/ctypes/ctypesgencore/parser/preprocessor.py.orig	2020-06-03 13:26:22 UTC
+++ lib/python/ctypes/ctypesgencore/parser/preprocessor.py
@@ -123,7 +123,8 @@ class PreprocessorParser(object):
     def __init__(self, options, cparser):
         self.defines = ["inline=", "__inline__=", "__extension__=",
                         "_Bool=uint8_t", "__const=const", "__asm__(x)=",
-                        "__asm(x)=", "CTYPESGEN=1"]
+                        "__asm(x)=", "CTYPESGEN=1",
+			"__attribute__(x)=", "__aligned(x)=", "_Noreturn="]
 
         # On OSX, explicitly add these defines to keep from getting syntax
         # errors in the OSX standard headers.
