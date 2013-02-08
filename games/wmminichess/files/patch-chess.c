--- chess.c.bak	1999-09-14 02:15:50.000000000 +0900
+++ chess.c	2012-10-24 03:04:11.000000000 +0900
@@ -1972,7 +1972,7 @@
  *
  * RETURNS: N/A
  */
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
     {
     int toChild[2];
     int fromChild[2];
