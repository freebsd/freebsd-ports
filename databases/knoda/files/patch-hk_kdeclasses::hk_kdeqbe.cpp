--- hk_kdeclasses/hk_kdeqbe.cpp.orig	Thu Jul 15 22:28:21 2004
+++ hk_kdeclasses/hk_kdeqbe.cpp	Thu Jul 15 23:08:55 2004
@@ -388,7 +388,7 @@
   for (int i=0;i<p_private->p_table->numCols();++i)
   {
     if ( ((QComboTableItem*)(p_private->p_table->item(1,i)))->currentItem()>0 // field
-          || !(((QComboTableItem*)(p_private->p_table->item(1,i)))->text().isEmpty())
+          || !(((QComboTableItem*)(p_private->p_table->item(1,i)))->currentText().isEmpty())
        )
      { 
 
