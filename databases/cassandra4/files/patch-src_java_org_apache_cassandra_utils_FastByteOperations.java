--- src/java/org/apache/cassandra/utils/FastByteOperations.java.orig	2020-03-30 16:37:37 UTC
+++ src/java/org/apache/cassandra/utils/FastByteOperations.java
@@ -191,6 +191,20 @@ public class FastByteOperations
 
         static final boolean BIG_ENDIAN = ByteOrder.nativeOrder().equals(ByteOrder.BIG_ENDIAN);
 
+        private static byte unsafeGetByte(Object o, long offset)
+        {
+            return o == null
+                    ? theUnsafe.getByte(offset)
+                    : theUnsafe.getByte(o, offset);
+        }
+
+        private static long unsafeGetLong(Object o, long offset)
+        {
+            return o == null
+                    ? theUnsafe.getLong(offset)
+                    : theUnsafe.getLong(o, offset);
+        }
+
         public int compare(byte[] buffer1, int offset1, int length1, byte[] buffer2, int offset2, int length2)
         {
             return compareTo(buffer1, BYTE_ARRAY_BASE_OFFSET + offset1, length1,
@@ -214,7 +228,7 @@ public class FastByteOperations
             else
             {
                 obj1 = null;
-                offset1 = theUnsafe.getLong(buffer1, DIRECT_BUFFER_ADDRESS_OFFSET) + position1;
+                offset1 = unsafeGetLong(buffer1, DIRECT_BUFFER_ADDRESS_OFFSET) + position1;
             }
 
             return compareTo(obj1, offset1, length1, buffer2, BYTE_ARRAY_BASE_OFFSET + offset2, length2);
@@ -230,7 +244,7 @@ public class FastByteOperations
             if (src.hasArray())
                 System.arraycopy(src.array(), src.arrayOffset() + srcPosition, trg, trgPosition, length);
             else
-                copy(null, srcPosition + theUnsafe.getLong(src, DIRECT_BUFFER_ADDRESS_OFFSET), trg, trgPosition, length);
+                copy(null, srcPosition + unsafeGetLong(src, DIRECT_BUFFER_ADDRESS_OFFSET), trg, trgPosition, length);
         }
 
         public void copy(ByteBuffer srcBuf, int srcPosition, ByteBuffer trgBuf, int trgPosition, int length)
@@ -245,7 +259,7 @@ public class FastByteOperations
             else
             {
                 src = null;
-                srcOffset = theUnsafe.getLong(srcBuf, DIRECT_BUFFER_ADDRESS_OFFSET);
+                srcOffset = unsafeGetLong(srcBuf, DIRECT_BUFFER_ADDRESS_OFFSET);
             }
             copy(src, srcOffset + srcPosition, trgBuf, trgPosition, length);
         }
@@ -255,7 +269,7 @@ public class FastByteOperations
             if (trgBuf.hasArray())
                 copy(src, srcOffset, trgBuf.array(), trgBuf.arrayOffset() + trgPosition, length);
             else
-                copy(src, srcOffset, null, trgPosition + theUnsafe.getLong(trgBuf, DIRECT_BUFFER_ADDRESS_OFFSET), length);
+                copy(src, srcOffset, null, trgPosition + unsafeGetLong(trgBuf, DIRECT_BUFFER_ADDRESS_OFFSET), length);
         }
 
         public static void copy(Object src, long srcOffset, byte[] trg, int trgPosition, int length)
@@ -263,7 +277,7 @@ public class FastByteOperations
             if (length <= MIN_COPY_THRESHOLD)
             {
                 for (int i = 0 ; i < length ; i++)
-                    trg[trgPosition + i] = theUnsafe.getByte(src, srcOffset + i);
+                    trg[trgPosition + i] = unsafeGetByte(src, srcOffset + i);
             }
             else
             {
@@ -302,7 +316,7 @@ public class FastByteOperations
             else
             {
                 obj1 = null;
-                offset1 = theUnsafe.getLong(buffer1, DIRECT_BUFFER_ADDRESS_OFFSET);
+                offset1 = unsafeGetLong(buffer1, DIRECT_BUFFER_ADDRESS_OFFSET);
             }
             offset1 += buffer1.position();
             length1 = buffer1.remaining();
@@ -325,7 +339,7 @@ public class FastByteOperations
             else
             {
                 obj2 = null;
-                offset2 = theUnsafe.getLong(buffer, DIRECT_BUFFER_ADDRESS_OFFSET);
+                offset2 = unsafeGetLong(buffer, DIRECT_BUFFER_ADDRESS_OFFSET);
             }
             int length2 = limit - position;
             offset2 += position;
@@ -358,8 +372,8 @@ public class FastByteOperations
             int wordComparisons = minLength & ~7;
             for (int i = 0; i < wordComparisons ; i += Longs.BYTES)
             {
-                long lw = theUnsafe.getLong(buffer1, memoryOffset1 + i);
-                long rw = theUnsafe.getLong(buffer2, memoryOffset2 + i);
+                long lw = unsafeGetLong(buffer1, memoryOffset1 + i);
+                long rw = unsafeGetLong(buffer2, memoryOffset2 + i);
 
                 if (lw != rw)
                 {
@@ -372,8 +386,8 @@ public class FastByteOperations
 
             for (int i = wordComparisons ; i < minLength ; i++)
             {
-                int b1 = theUnsafe.getByte(buffer1, memoryOffset1 + i) & 0xFF;
-                int b2 = theUnsafe.getByte(buffer2, memoryOffset2 + i) & 0xFF;
+                int b1 = unsafeGetByte(buffer1, memoryOffset1 + i) & 0xFF;
+                int b2 = unsafeGetByte(buffer2, memoryOffset2 + i) & 0xFF;
                 if (b1 != b2)
                     return b1 - b2;
             }
