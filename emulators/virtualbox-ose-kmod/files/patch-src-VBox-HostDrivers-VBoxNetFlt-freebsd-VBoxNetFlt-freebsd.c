Add VLAN trunking support to vboxnetflt

See:		http://lists.freebsd.org/pipermail/freebsd-emulation/2012-April/009698.html
Submitted by:	Landon J Fuller <landonf at plausible.coop>
--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2012-04-12 17:27:56.035382846 -0400
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	2012-04-12 17:30:13.038601065 -0400
@@ -439,6 +439,16 @@
         if (m == NULL)
             break;
 
+        /* Preprend a VLAN header for consumption by the virtual switch */
+        if (m->m_flags & M_VLANTAG) {
+            m = ether_vlanencap(m, m->m_pkthdr.ether_vtag);
+            if (m == NULL) {
+                printf("vboxflt: unable to prepend VLAN header\n");
+                break;
+            }
+            m->m_flags &= ~M_VLANTAG;
+        }
+
         for (m0 = m; m0 != NULL; m0 = m0->m_next)
             if (m0->m_len > 0)
                 cSegs++;
