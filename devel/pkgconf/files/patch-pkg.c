--- ./pkg.c.orig	2013-03-16 02:19:13.000000000 +0100
+++ ./pkg.c	2013-03-17 23:47:38.808630318 +0100
@@ -890,7 +890,7 @@
 		}
 
 		pkgdep->flags |= PKG_PROPF_SEEN;
-		eflags = pkg_traverse(pkgdep, func, data, depth - 1, flags);
+		eflags |= pkg_traverse(pkgdep, func, data, depth - 1, flags);
 		pkgdep->flags &= ~PKG_PROPF_SEEN;
 		pkg_unref(pkgdep);
 	}
