--- tests/rvm_basher.c.orig
+++ tests/rvm_basher.c
@@ -1579,20 +1579,10 @@
 /* print break point and limit */
 static void show_break()
     {
-    rvm_length_t    cur_brk;
 #ifdef RLIMIT_DATA
     struct rlimit   rlp;
 #endif
 
-    /* get current break point */
-    errno = 0;
-    if ((cur_brk=(rvm_length_t)sbrk(0)) == -1)
-        {
-        printf("\n? Error getting current break point\n");
-        printf("    errno = %d\n",errno);
-        CODA_ASSERT(rvm_false);
-        }
-
     /* get system maximum */
     errno = 0;
 #ifdef RLIMIT_DATA
@@ -1604,8 +1594,6 @@
         }
 
     /* print the limits */
-    printf("\nCurrent break point:         0x%lx\n",
-           RVM_ROUND_LENGTH_UP_TO_PAGE_SIZE(cur_brk+5*RVM_PAGE_SIZE));
     printf("Maximum data segment length: 0x%lx\n\n",rlp.rlim_max);
 #endif
     exit(0);
