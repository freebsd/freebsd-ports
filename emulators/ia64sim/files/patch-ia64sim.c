--- ia64sim.c.orig	2000-02-28 01:20:26 UTC
+++ ia64sim.c
@@ -779,7 +779,7 @@ int main(int argc, char **argv) {
 
    uint32 i;
 
-   printf("\nIA64 ISA simulator, version 0.4\n");
+   printf("\nIA64 ISA simulator, version 0.5\n");
    printf("Memory limits: 0x%08x-0x%08x\n", 0, MEMSIZE-1);
    printf("Try 'h' for help\n\n");
 
@@ -811,6 +811,9 @@ int main(int argc, char **argv) {
       printf("IA64sim>> ");
       fgets(cmd,sizeof(cmd),stdin);
 
+      if (feof(stdin))
+         return 0;
+
       nextchar = cmd;
       while(*nextchar) *nextchar++ = tolower(*nextchar);
 
