--- src/java/asts/stdprims/g.java.orig	1999-09-13 00:27:02.000000000 +0200
+++ src/java/asts/stdprims/g.java	2007-10-11 19:12:08.000000000 +0200
@@ -1,13 +1,13 @@
-package asts.StdPrims;
+package asts.stdprims;
 import java.io.*;
 
-final public class g extends asts.StdPkl.PklJava  {
+final public class g extends asts.stdpkl.PklJava  {
 
   public static void write_java_lang_String(String x,OutputStream s) {
     int sz = x.length();
     int i = 0;
     try {
-      asts.StdPkl.g.write_tag(sz,s); 
+      asts.stdpkl.g.write_tag(sz,s); 
       while(i < sz) {
 	s.write((byte)x.charAt(i++));
       }
@@ -17,7 +17,7 @@
   }
 
  public static String read_java_lang_String(InputStream s) {
-    int sz  = asts.StdPkl.g.read_tag(s);
+    int sz  = asts.stdpkl.g.read_tag(s);
     StringBuffer sb = new StringBuffer(sz);
     try {
       while(sz > 0) {
