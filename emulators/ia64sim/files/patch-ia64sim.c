--- ia64sim.c.orig	Wed Mar  8 04:54:20 2000
+++ ia64sim.c	Tue Oct 10 16:34:36 2000
@@ -98,7 +98,7 @@
          stop(); /* Clear pending register hazzards */
       }
       else {
-         i1 = strtoll(first+1, &junk, 0);
+         i1 = strtoq(first+1, &junk, 0);
          if(*junk) {
             printf("3syntax error\n");
             return;
@@ -138,7 +138,7 @@
       }
    }
    else {
-      i1 = strtoll(first, &junk, 0);
+      i1 = strtoq(first, &junk, 0);
       if(*junk) {
          printf("6syntax error\n");
          return;
@@ -159,7 +159,7 @@
          size2 = sizeof(uint64);
       }
       else {
-         i2 = strtoll(second+1, &junk, 0);
+         i2 = strtoq(second+1, &junk, 0);
          if(*junk) {
             printf("7syntax error\n");
             return;
@@ -200,7 +200,7 @@
       }
    }
    else {
-      i2 = strtoll(second, &junk, 0);
+      i2 = strtoq(second, &junk, 0);
       if(*junk) {
          printf("Asyntax error\n");
          return;
@@ -289,7 +289,7 @@
 
    base = strtok(NULL, tokens);
    if(base) {
-      temp = strtoll(base, &junk, 0);
+      temp = strtoq(base, &junk, 0);
       if(*junk) {
          printf("2syntax error\n");
          return;
@@ -355,7 +355,7 @@
    }
    if(!second) base = 0;
    else {
-   base = strtoll(second, &junk, 0) & ~15;
+   base = strtoq(second, &junk, 0) & ~15;
    if(*junk) {
       printf("Invalid base address\n");
       return;
@@ -397,7 +397,7 @@
    }
    if(!second) base = 0;
    else {
-   base = strtoll(second, &junk, 0) & ~15;
+   base = strtoq(second, &junk, 0) & ~15;
    if(*junk) {
       printf("Invalid base address\n");
       return;
@@ -436,13 +436,13 @@
       return;
    }
 
-   base = strtoll(second, &junk, 0) & ~15;
+   base = strtoq(second, &junk, 0) & ~15;
    if(*junk) {
       printf("Invalid base address\n");
       return;
    }
 
-   module_size = strtoll(third, &junk, 0) & ~15;
+   module_size = strtoq(third, &junk, 0) & ~15;
    if(*junk) {
       printf("Invalid length\n");
       return;
@@ -512,7 +512,7 @@
      printf("Break point address is required\n"); 
      return;
    }
-   break_address = strtoll(first,&junk,0) & ~15;
+   break_address = strtoq(first,&junk,0) & ~15;
    if(*junk) {
      printf("Invalid break point address\n");
      return;
@@ -556,6 +556,9 @@
    while(1) {
       printf("IA64sim>> ");
       gets(cmd);
+
+      if (feof(stdin))
+         return 0;
 
       nextchar = cmd;
       while(*nextchar) *nextchar++ = tolower(*nextchar);
