--- src/xparser/SynSym.h.orig	Thu Feb 26 18:21:19 2004
+++ src/xparser/SynSym.h	Thu Feb 26 18:21:49 2004
@@ -54,8 +54,8 @@
 		String theType;
 };
 
-#define SymCast(Type, var) ((Type&)((var).cast(Type##::TheType)))
-#define ConstSymCast(Type, var) ((const Type&)((var).cast(Type##::TheType)))
+#define SymCast(Type, var) ((Type&)((var).cast(Type::TheType)))
+#define ConstSymCast(Type, var) ((const Type&)((var).cast(Type::TheType)))
 
 inline ostream &operator <<(ostream &os, const SynSym &sym) { return sym.print(os); }
 
