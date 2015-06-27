--- src/gnu/io/SerialPortEvent.java.orig	2007-04-26 06:26:06.000000000 +0100
+++ src/gnu/io/SerialPortEvent.java	2015-05-11 16:51:34.000000000 +0100
@@ -76,6 +76,8 @@
 	public static final int PE                  =8;
 	public static final int FE                  =9;
 	public static final int BI                 =10;
+	
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	private boolean OldValue;
 	private boolean NewValue;
