$FreeBSD$

--- ../../src/share/classes/java/util/TreeMap.java	4 Aug 1999 21:07:46 -0000	1.1.1.2
+++ ../../src/share/classes/java/util/TreeMap.java	12 Jul 2005 20:46:37 -0000
@@ -889,7 +889,7 @@
 		Object key = entry.getKey();
                 if (!inRange(key))
                     return false;
-                Entry node = getEntry(key);
+                TreeMap.Entry node = getEntry(key);
                 if (node!=null && valEquals(node.getValue(),entry.getValue())){
 		    deleteEntry(node);
 		    return true;
