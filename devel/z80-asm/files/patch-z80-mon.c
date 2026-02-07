--- z80-mon.c.orig	2023-12-28 16:53:32 UTC
+++ z80-mon.c
@@ -1359,7 +1359,7 @@ main(int argc,char **argv)
       if (labels=table_entries())
       {  ele= malloc(labels*sizeof(struct info));
          for(a=0;next_table_entry(&ele[a].label,&ele[a].value,&ele[a].lineno);a++);
-         qsort(ele,labels,sizeof(struct info),compare_addr);
+         qsort(ele,labels,sizeof(struct info),(void *)compare_addr);
       }
       next_label_index=0;
       old_pc=PC;
