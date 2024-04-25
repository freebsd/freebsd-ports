--- z80-asm.c.orig	2023-12-28 16:48:47 UTC
+++ z80-asm.c
@@ -218,7 +218,7 @@ if (!a && cross && (b=table_entries()))
 { struct info  *ele;
   ele= malloc(b*sizeof(struct info));
   for(a=0;next_table_entry(&ele[a].label,&ele[a].value,&ele[a].lineno);a++);
-  qsort(ele,b,sizeof(struct info),compare);
+  qsort(ele,b,sizeof(struct info),(void *)compare);
   printf("       Cross reference:\n");
   printf("      symbol value hexa  line\n");
   for (a=0;a<b;a++)
