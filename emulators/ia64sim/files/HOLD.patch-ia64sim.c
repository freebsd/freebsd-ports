$NetBSD: patch-ad,v 1.2 1999/12/10 15:14:03 soren Exp $

--- ia64sim.c.orig	Sun Dec  5 02:15:28 1999
+++ ia64sim.c	Fri Dec 10 15:55:16 1999
@@ -95,7 +95,7 @@
          currslot = SLOT0;
       }
       else {
-         i1 = strtoll(first+1, &junk, 0);
+         i1 = strtoq(first+1, &junk, 0);
          if(*junk) {
             printf("3syntax error\n");
             return;
@@ -135,7 +135,7 @@
       }
    }
    else {
-      i1 = strtoll(first, &junk, 0);
+      i1 = strtoq(first, &junk, 0);
       if(*junk) {
          printf("6syntax error\n");
          return;
@@ -156,7 +156,7 @@
          size2 = sizeof(uint64);
       }
       else {
-         i2 = strtoll(second+1, &junk, 0);
+         i2 = strtoq(second+1, &junk, 0);
          if(*junk) {
             printf("7syntax error\n");
             return;
@@ -197,7 +197,7 @@
       }
    }
    else {
-      i2 = strtoll(second, &junk, 0);
+      i2 = strtoq(second, &junk, 0);
       if(*junk) {
          printf("Asyntax error\n");
          return;
@@ -286,7 +286,7 @@
 
    base = strtok(NULL, tokens);
    if(base) {
-      temp = strtoll(base, &junk, 0);
+      temp = strtoq(base, &junk, 0);
       if(*junk) {
          printf("2syntax error\n");
          return;
@@ -338,7 +338,7 @@
       return;
    }
    
-   base = strtoll(second, &junk, 0) & ~15;
+   base = strtoq(second, &junk, 0) & ~15;
    if(*junk) {
       printf("Invalid base address\n");
       return;
@@ -422,6 +422,9 @@
    while(1) {
       printf("IA64sim>> ");
       gets(cmd);
+
+      if (feof(stdin))
+         return 0;
 
       nextchar = cmd;
       while(*nextchar) *nextchar++ = tolower(*nextchar);
