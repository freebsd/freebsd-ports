--- libs/ext/cothreads/tests/cothreads.c.orig	Fri Jun 21 01:33:11 2002
+++ libs/ext/cothreads/tests/cothreads.c	Mon Jul 15 18:11:38 2002
@@ -79,10 +79,13 @@
   printf ("0: creating the gthreads\n");
   for (i=0; i<NGTHREADS; i++) {
     pthreadnum[i] = i+1;
-    if (posix_memalign (&stack, MAIN_STACK_SIZE, MAIN_STACK_SIZE))
+    stack = malloc (MAIN_STACK_SIZE * (1.0 + 1.0/16));
+    if (!stack)
       perror ("allocating pthread stack of size %d", MAIN_STACK_SIZE);
+    stack = (void*)((int)stack &~ (int)(MAIN_STACK_SIZE / 16 - 1));
+    stack += 1;
     pthread_attr_init (&attr[i]);
-    if (!pthread_attr_setstack (&attr[i], stack, MAIN_STACK_SIZE))
+    if (!pthread_attr_setstacksize (&attr[i], MAIN_STACK_SIZE))
       perror ("setting stack size");
     pthread_create (&thread[i], &attr[i], pthread, &pthreadnum[i]);
   }
