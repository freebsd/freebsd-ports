--- nodeop.c.orig	Fri May 19 16:50:54 1995
+++ nodeop.c	Sun Nov  5 13:39:44 2006
@@ -1,5 +1,5 @@
 #include <sys/types.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include "ansi.h"
 #include "host.h"
@@ -85,52 +85,50 @@
 }
 
 node_t*
-new_node(kind, va_alist)
-	node_kind_t kind;
-	va_dcl
+new_node(node_kind_t kind, ...)
 {
-	va_list args;
+	va_list ap;
 	node_t *n;
 
-	va_start(args);
+	va_start(ap, kind);
 
 	n = alloc_node(kind);
 
 	switch (node_classof(kind)) {
 	  case _Binary:
-		n->node.binary.l = va_arg(args, node_t*);
-		n->node.binary.r = va_arg(args, node_t*);
+		n->node.binary.l = va_arg(ap, node_t*);
+		n->node.binary.r = va_arg(ap, node_t*);
 		break;
 	  case _Unary:
-		n->node.unary = va_arg(args, node_t*);
+		n->node.unary = va_arg(ap, node_t*);
 		break;
 	  case _Pointer:
-		n->node.id.name = va_arg(args, char*);
+		n->node.id.name = va_arg(ap, char*);
 		break;
 	  case _Other:
 		switch (kind) {
 		  case _Elipsis:
 			break;
 		  case _String:
-			n->node.str.form = va_arg(args, char*);
-			n->node.str.len = va_arg(args, int);
+			n->node.str.form = va_arg(ap, char*);
+			n->node.str.len = va_arg(ap, int);
 			break;
 		  case _Sym:
-			n->node.sym = va_arg(args, symbol_t*);
+			n->node.sym = va_arg(ap, symbol_t*);
 			break;
 		  case _Type:
-			n->node.typ = va_arg(args, typeinfo_t*);
+			n->node.typ = va_arg(ap, typeinfo_t*);
 			break;
 		  case _Cond:
-			n->node.cond.bool = va_arg(args, node_t*);
-			n->node.cond.tru = va_arg(args, node_t*);
-			n->node.cond.fals = va_arg(args, node_t*);
+			n->node.cond.bool = va_arg(ap, node_t*);
+			n->node.cond.tru = va_arg(ap, node_t*);
+			n->node.cond.fals = va_arg(ap, node_t*);
 			break;
 		  case _FP_Number:
-			n->node.fval = va_arg(args, host_float_t);
+			n->node.fval = va_arg(ap, host_float_t);
 			break;
 		  case _Int_Number:
-			n->node.ival = va_arg(args, host_int_t);
+			n->node.ival = va_arg(ap, host_int_t);
 			break;
 		  default:
 			fatal(__FILE__,__LINE__,"Unandled noded - (%d)", kind);
@@ -142,7 +140,7 @@
 		break;
 	}
 
-	va_end(args);
+	va_end(ap);
 
 	return n;
 }
