--- I7094/i7094_com.c.orig	2016-12-01 22:43:42 UTC
+++ I7094/i7094_com.c
@@ -1175,7 +1175,7 @@ char name[20];
 ln = uptr - coml_dev.units;
 sprintf (name, val? "Output queue %d": "Input queue %d", ln);
 lh = val? &com_outq[ln]: &com_inpq[ln];
-if (entc = com_show_qsumm (st, lh, name)) {
+if ((entc = com_show_qsumm (st, lh, name))) {
     for (i = 0, next = lh->head; next != 0;
          i++, next = com_pkt[next].next) {
         if ((i % 8) == 0)
