--- src/src/main/java/jline/ConsoleRunner.java.orig	2007-03-09 16:32:28.000000000 +0100
+++ src/src/main/java/jline/ConsoleRunner.java	2007-09-24 19:22:42.000000000 +0200
@@ -17,6 +17,10 @@
  *  @author  <a href="mailto:mwp1@cornell.edu">Marc Prud'hommeaux</a>
  */
 public class ConsoleRunner {
+    private static ConsoleReader reader;
+
+    public static ConsoleReader getReader() { return reader; }
+
     public static final String property = "jline.history";
 
     public static void main(final String[] args) throws Exception {
@@ -36,7 +40,7 @@
         String mainClass = (String) argList.remove(0);
 
         // setup the inpout stream
-        ConsoleReader reader = new ConsoleReader();
+        reader = new ConsoleReader();
 
         if (historyFileName != null) {
             reader.setHistory(new History (new File
