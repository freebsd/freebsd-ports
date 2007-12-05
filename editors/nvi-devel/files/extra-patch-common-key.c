--- ../common/key.c.orig	2001-06-25 11:19:10.000000000 -0400
+++ ../common/key.c	2007-11-15 13:50:47.000000000 -0500
@@ -833,7 +833,7 @@
 	wp = sp->wp;
 	new_nelem = wp->i_nelem + add;
 	olen = wp->i_nelem * sizeof(wp->i_event[0]);
-	BINC_RET(sp, (char *)wp->i_event, olen, new_nelem * sizeof(wp->i_event[0]));
+	BINC_RET(sp, wp->i_event, olen, new_nelem * sizeof(wp->i_event[0]));
 	wp->i_nelem = olen / sizeof(wp->i_event[0]);
 	return (0);
 }
