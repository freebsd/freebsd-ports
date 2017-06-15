--- src/gnu/io/NoSuchPortException.java.orig	2007-04-26 05:26:05 UTC
+++ src/gnu/io/NoSuchPortException.java
@@ -67,6 +67,9 @@ import java.util.*;
 
 public class NoSuchPortException extends Exception
 {
+	
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
+	
 	NoSuchPortException( String str )
 	{
 		super( str );
