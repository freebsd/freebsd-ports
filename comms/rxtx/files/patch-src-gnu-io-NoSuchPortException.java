--- src/gnu/io/NoSuchPortException.java.orig	2007-04-26 06:26:05.000000000 +0100
+++ src/gnu/io/NoSuchPortException.java	2015-05-11 16:51:34.000000000 +0100
@@ -67,6 +67,9 @@
 
 public class NoSuchPortException extends Exception
 {
+	
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
+	
 	NoSuchPortException( String str )
 	{
 		super( str );
