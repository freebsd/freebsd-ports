--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Sort.c	Tue Feb 15 14:27:00 1994
+++ ./reuse/m2c/Sort.c	Thu Aug  5 18:49:34 2004
@@ -43,7 +43,7 @@
     (**link->Swap)(Lwb, j);
     QuickSort(link, Lwb, j - 1);
     Lwb = j + 1;
-  } EXIT_1:;
+  } ;
 }
 
 void Sort_Sort
