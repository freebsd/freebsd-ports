--- ia64sim.c.orig	Sun Feb 27 17:20:26 2000
+++ ia64sim.c	Sun May  6 11:51:41 2001
@@ -779,7 +779,7 @@
 
    uint32 i;
 
-   printf("\nIA64 ISA simulator, version 0.4\n");
+   printf("\nIA64 ISA simulator, version 0.5\n");
    printf("Memory limits: 0x%08x-0x%08x\n", 0, MEMSIZE-1);
    printf("Try 'h' for help\n\n");
 
@@ -810,6 +810,9 @@
    while(1) {
       printf("IA64sim>> ");
       fgets(cmd,sizeof(cmd),stdin);
+
+      if (feof(stdin))
+         return 0;
 
       nextchar = cmd;
       while(*nextchar) *nextchar++ = tolower(*nextchar);
