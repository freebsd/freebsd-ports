diff -ruN automata.c.orig automata.c
--- automata.c.orig	Mon May 28 11:13:24 2001
+++ automata.c	Wed Feb 20 02:37:27 2002
@@ -112,15 +112,15 @@
 /* 9          :          ;          <          =          > */
   '9' | F_A, ':' | F_A, ';' | F_A, '<' | F_A, '=' | F_A, '>' | F_A,
 /* ?          @          A          B          C          D */
-  '?' | F_A, '@' | F_A, 'A' | F_A, 'B' | F_A, 'C' | F_A, 'D' | F_A,
+  '?' | F_A, '@' | F_A,  8 | F_C_C, 26 | F_V,  16 | F_A,  13 | F_C_C,
 /* E          F          G          H          I          J */
-  6 | F_C_F, 'F' | F_A, 'G' | F_A, 'H' | F_A, 'I' | F_A, 'J' | F_A,
+  6 | F_C_F,  7 | F_C_C, 20 | F_C_C, 13 | F_V, 5 | F_V, 7 | F_V,
 /* K          L          M          N          O          P */
-  'K' | F_A, 'L' | F_A, 'M' | F_A, 'N' | F_A, 6 | F_V, 12 | F_V,
+  3 | F_V, 29 | F_V, 27 | F_V, 20 | F_V, 6 | F_V, 12 | F_V,
 /* Q          R          S          T          U          V */
-  10 | F_C_F, 3 | F_C_C, 'S' | F_A, 12 | F_C_C, 'U' | F_A, 'V' | F_A,
+  10 | F_C_F, 3 | F_C_C, 4 | F_C_C, 12 | F_C_C, 11 | F_V, 19 | F_C_C,
 /* W          X          Y          Z          [          \ */
-  15 | F_C_F, 'X' | F_A, 'Y' | F_A, 'Z' | F_A, '[' | F_A, '\\' | F_A,
+  15 | F_C_F, 18| F_C_C, 19 | F_V, 17 | F_C_C, '[' | F_A, '\\' | F_A,
 /* ]          ^          _          `          a          b */
   ']' | F_A, '^' | F_A, '_' | F_A, '`' | F_A, 8 | F_C_C, 26 | F_V,
 /* c          d          e          f          g          h */
@@ -412,7 +412,7 @@
      int c;
 {
   /* 모음의 범위 검색 */
-  if (c < 'L' || c > 'y')
+  if (c < 'A' || c > 'z')
     return 0;
 
   if (table_for_2_qwerty[c - '!'] & F_V)
@@ -435,9 +435,9 @@
     /* 0   1   2   3   4   5   6   7   8   9   :   ;   <   =   > */
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     /* ?   @   A   B   C   D   E   F   G   H   I   J   K   L   M */
-       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
+       0,  0,  17, 0,  25, 23, 8,  9,  29, 0,  0,  0,  0,  0,  0,
     /* N   O   P   Q   R   S   T   U   V   W   X   Y   Z   [   \ */
-       0,  0,  0,  0,  3,  0,  22, 0,  0,  0,  0,  0,  0,  0,  0,
+       0,  0,  0, 19,  3,  5,  22, 0,  28, 24, 27, 0, 26,  0,  0,
     /* ]   ^   _   `   a   b   c   d   e   f   g   h   i   j   k */
        0,  0,  0,  0,  17, 0,  25, 23, 8,  9,  29, 0,  0,  0,  0,
     /* l   m   n   o   p   q   r   s   t   u   v   w   x   y   z */
@@ -445,7 +445,7 @@
   };
 
   /* 종성의 범위 검색 */
-  if (c < 'R' || c > 'z')
+  if (c < 'A' || c > 'z')
     return 0;
 
   if (table_for_2_qwerty[c - '!'] & F_C_L)
