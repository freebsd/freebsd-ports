--- src/Rational_math.cpp.orig	Sat Feb  8 20:58:16 2003
+++ src/Rational_math.cpp	Sat Feb  8 21:01:38 2003
@@ -163,7 +163,7 @@
 for (i=0;i<21;i++)
      if (mpl_modul(per_table[i],real)) {
          up=per_table[i];
-         lo=round(up/real);
+         lo=floor(up/real);
          pass=true;
          break;
      }
