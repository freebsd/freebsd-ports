This avoids errors list the following, where True is a C++
identifier used in scoped context; the #define eats it.

/usr/local/include/qt5/QtCore/qcborstreamreader.h:143:76: error: expected unqualified-id
    bool isFalse() const            { return isSimpleType(QCborSimpleType::False); }
                                                                           ^
lzma/7zTypes.h:98:15: note: expanded from macro 'False'
#define False 0

--- qmc2/lzma/7zTypes.h.orig	2020-05-30 14:14:41 UTC
+++ qmc2/lzma/7zTypes.h
@@ -94,8 +94,11 @@ typedef size_t SizeT;
 #endif
 
 typedef int Bool_7z;
+#ifndef __cplusplus
+/* Only for library internals */
 #define True 1
 #define False 0
+#endif
 
 
 #ifdef _WIN32
