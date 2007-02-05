--- build/post.mk.orig	Sun Feb  4 19:51:48 2007
+++ build/post.mk	Sun Feb  4 19:52:55 2007
@@ -33,7 +33,10 @@
 
 %.o: %.c
 	$(CC) $(CFLAGS) -c -o $@ $<
-	
+
+q_shared.o: q_shared.c
+	$(CC) $(CFLAGS) -fPIC -c -o $@ $<
+
 %.o: %.s
 	$(CC) $(CFLAGS) -x assembler-with-cpp -c -o $@ $<
 
