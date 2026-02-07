--- engine/main.c.orig	2013-10-11 21:31:28 UTC
+++ engine/main.c
@@ -976,7 +976,8 @@ static void check_prims(Label symbols1[])
   goto_len = goto_p[1]-goto_p[0];
   debugp(stderr, "goto * %p %p len=%ld\n",
 	 goto_p[0],symbols2[goto_p-symbols1],(long)goto_len);
-  if (memcmp(goto_p[0],symbols2[goto_p-symbols1],goto_len)!=0) { /* unequal */
+  if ((goto_len < 0) ||
+      memcmp(goto_p[0],symbols2[goto_p-symbols1],goto_len)!=0) { /* unequal */
     no_dynamic=1;
     debugp(stderr,"  not relocatable, disabling dynamic code generation\n");
     init_ss_cost();
@@ -1045,8 +1046,14 @@ static void check_prims(Label symbols1[])
       nonrelocs++;
       continue;
     }
-    assert(pi->length>=0);
-    assert(pi->restlength >=0);
+    if((pi->length<0) || (pi->restlength<0)) {
+      pi->length = endlabel-symbols1[i];
+      pi->restlength = 0;
+#ifndef BURG_FORMAT
+      debugp(stderr,"\n   adjust restlen: len/restlen < 0, %d/%d",
+	     pi->length, pi->restlength);
+#endif
+    };
     while (j<(pi->length+pi->restlength)) {
       if (s1[j]==s3[j]) {
 	if (s1[j] != s2[j]) {
