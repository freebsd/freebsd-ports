Remove explicit initialization of m->flags and m->oflags because per
default vm_phys_alloc_contig() already initializes the page as unmanaged.
Chase move of PG_UNMANAGED flag from m->flags to m->oflags and renaming
to VPO_UNMANAGED for an additional assert.

Reviewed by:	kib
See:		http://svnweb.freebsd.org/base?view=revision&revision=224746
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2011-04-05 14:34:09.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2011-08-11 15:06:46.000000000 +0200
@@ -394,9 +394,13 @@
     pPage->wire_count = 1;
     pPage->pindex     = iPage;
     pPage->act_count  = 0;
-    pPage->oflags     = 0;
-    pPage->flags      = PG_UNMANAGED;
     atomic_add_int(&cnt.v_wire_count, 1);
+
+#if __FreeBSD_version >= 900040
+    Assert(pPage->oflags & VPO_UNMANAGED != 0);
+#else
+    Assert(pPage->flags & PG_UNMANAGED != 0);
+#endif
 }
 
 
