--- Dialog.xs.orig	Mon Nov 27 23:15:18 2000
+++ Dialog.xs	Mon Nov 27 23:15:53 2000
@@ -314,11 +314,11 @@
 	New(0,item_list,2 * item_no,uchar*);
 	item_ptr = item_list;
 	for(i=0; i<item_no; i++) {
-	  *(item_ptr++) = item = SvPV(ST(i+5), na);
-	  tmpsz = na + 1;
+	  *(item_ptr++) = item = SvPV(ST(i+5), PL_na);
+	  tmpsz = PL_na + 1;
 	  if(tmpsz > size) size = tmpsz;
 	  len = strlen(item);
-	  *(item_ptr++) = item + len + (len < na);
+	  *(item_ptr++) = item + len + (len < PL_na);
 	}
 	New(0,result,size,char);
 	cancel = dialog_menu(title, prompt, height, width, menu_height,
@@ -346,10 +346,10 @@
 	New(0,item_list,3 * item_no,uchar*);
 	item_ptr = item_list;
 	for(i=0; i<item_no; i++) {
-	  *(item_ptr++) = item = SvPV(ST(i+5), na);
-	  size += na + 1;
+	  *(item_ptr++) = item = SvPV(ST(i+5), PL_na);
+	  size += PL_na + 1;
 	  len = strlen(item);
-	  *(item_ptr++) = item + len + (len < na);
+	  *(item_ptr++) = item + len + (len < PL_na);
 	  *(item_ptr++) = item + len;
 	}
 	New(0,result,size,char);
@@ -386,10 +386,10 @@
 	New(0,item_list,3 * item_no,uchar*);
 	item_ptr = item_list;
 	for(i=0; i<item_no; i++) {
-	  *(item_ptr++) = item = SvPV(ST(i+5), na);
-	  size += na + 1;
+	  *(item_ptr++) = item = SvPV(ST(i+5), PL_na);
+	  size += PL_na + 1;
 	  len = strlen(item);
-	  *(item_ptr++) = item + len + (len < na);
+	  *(item_ptr++) = item + len + (len < PL_na);
 	  *(item_ptr++) = item + len;
 	}
 	New(0,result,size,char);
