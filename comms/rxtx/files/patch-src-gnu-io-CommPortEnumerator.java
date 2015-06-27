--- src/gnu/io/CommPortEnumerator.java.orig	2007-04-26 06:26:05.000000000 +0100
+++ src/gnu/io/CommPortEnumerator.java	2015-05-11 16:51:34.000000000 +0100
@@ -69,50 +69,79 @@
 class CommPortEnumerator implements Enumeration
 {
 	private CommPortIdentifier index;
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 	static
 	{
-		if (debug)
-			System.out.println("CommPortEnumerator:{}");
+		if (debug) System.out.println("CommPortEnumerator:Static{}");
 	}
 
 	CommPortEnumerator()
 	{
 	}
-/*------------------------------------------------------------------------------
-        nextElement()
-        accept:
-        perform:
-        return:
-        exceptions:
-        comments:
-------------------------------------------------------------------------------*/
+
 	public Object nextElement()
 	{
-		if(debug) System.out.println("CommPortEnumerator:nextElement()");
+		if (debug) System.out.println("CommPortEnumerator:nextElement()");
+		
 		synchronized (CommPortIdentifier.Sync)
 		{
-			if(index != null) index = index.next;
-			else index=CommPortIdentifier.CommPortIndex;
+			if(index != null)
+			{
+				index = index.next;
+			}
+			else
+			{
+				index=CommPortIdentifier.CommPortIndex;
+			}
+			if (debug) System.out.println(" CommPortEnumerator:nextElement(" + index + ")");
 			return(index);
 		}
 	}
-/*------------------------------------------------------------------------------
-        hasMoreElements()
-        accept:
-        perform:
-        return:
-        exceptions:
-        comments:
-------------------------------------------------------------------------------*/
+
 	public boolean hasMoreElements()
 	{
-		if(debug) System.out.println("CommPortEnumerator:hasMoreElements() " + CommPortIdentifier.CommPortIndex == null ? false : true );
+		if (debug) System.out.println("CommPortEnumerator:hasMoreElements()");
+		
+		if (CommPortIdentifier.CommPortIndex == null)
+		{
+			 if (debug) System.out.println(" ComPortIndex is null...");
+		}
+		else
+		{
+			if (debug) System.out.println(" ComPortIndex is not null...");
+		}
+		
 		synchronized (CommPortIdentifier.Sync)
 		{
-			if(index != null) return index.next == null ? false : true;
-			else return CommPortIdentifier.CommPortIndex == null ?
-				false : true;
+			if (debug) System.out.println(" Syncronised");
+			if(index != null) 
+			{
+				if (debug) System.out.println(" Valid index");
+				if (index.next == null)
+				{
+					if (debug) System.out.println("CommPortEnumerator:hasMoreElements: Exit(Next index is null - false)");
+					return false;
+				}
+				else
+				{
+					if (debug) System.out.println("CommPortEnumerator:hasMoreElements: Exit(Next index is not null - true)");
+					return true;
+				}
+			}
+			else 
+			{
+				if (debug) System.out.println(" Index is not valid");
+				if (CommPortIdentifier.CommPortIndex == null)
+				{
+					if (debug) System.out.println("CommPortEnumerator:hasMoreElements: Exit(CommPortIdentifier.CommPortIndex is null - false)");
+					return false;
+				}
+				else
+				{
+					if (debug) System.out.println("CommPortEnumerator:hasMoreElements: Exit(CommPortIdentifier.CommPortIndex is not null - true)");
+					return true;
+				}
+			}
 		}
 	}
 }
