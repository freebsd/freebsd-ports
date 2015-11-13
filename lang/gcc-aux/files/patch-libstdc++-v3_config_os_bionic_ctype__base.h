--- libstdc++-v3/config/os/bionic/ctype_base.h.orig	2014-01-02 22:30:10 UTC
+++ libstdc++-v3/config/os/bionic/ctype_base.h
@@ -40,6 +40,18 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
     // Non-standard typedefs.
     typedef const int* 		__to_type;
 
+#ifdef _CTYPE_U
+#define _U _CTYPE_U
+#define _L _CTYPE_L
+#define _D _CTYPE_D
+#define _S _CTYPE_S
+#define _P _CTYPE_P
+#define _C _CTYPE_C
+#define _X _CTYPE_X
+#define _B _CTYPE_B
+#define _N _CTYPE_D
+#endif
+
     // NB: Offsets into ctype<char>::_M_table force a particular size
     // on the mask type. Because of this, we don't use an enum.
     typedef char 		mask;
