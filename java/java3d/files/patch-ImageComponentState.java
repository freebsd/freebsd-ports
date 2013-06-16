work/java3d-1.5.2/j3d-core-utils/src/classes/share/com/sun/j3d/utils/scenegraph/io/state/javax/media/j3d
--- j3d-core-utils/src/classes/share/com/sun/j3d/utils/scenegraph/io/state/javax/media/j3d/ImageComponentState.java.orig
+++ j3d-core-utils/src/classes/share/com/sun/j3d/utils/scenegraph/io/state/javax/media/j3d/ImageComponentState.java
@@ -61,10 +61,7 @@ import com.sun.j3d.utils.scenegraph.io.r
 import com.sun.j3d.utils.scenegraph.io.retained.SGIORuntimeException;
 import java.awt.color.ColorSpace;
 import java.awt.image.DataBuffer;
-import com.sun.image.codec.jpeg.JPEGImageEncoder;
-import com.sun.image.codec.jpeg.JPEGImageDecoder;
-import com.sun.image.codec.jpeg.JPEGCodec;
-import com.sun.image.codec.jpeg.JPEGEncodeParam;
+import javax.imageio.ImageIO;
 
 public abstract class ImageComponentState extends NodeComponentState {
 
@@ -203,10 +200,9 @@ public abstract class ImageComponentStat
     
     private void writeBufferedImageJpegCompression( DataOutput out, BufferedImage image ) throws IOException {
         ByteArrayOutputStream byteStream = new ByteArrayOutputStream();
-        JPEGImageEncoder encoder = JPEGCodec.createJPEGEncoder( byteStream );
-
-        encoder.encode( image );
-        byteStream.close();
+        if (!ImageIO.write(image, "jpeg", byteStream)) {
+            throw new AssertionError("No JPEG encoder available");
+        }
         
         byte[] buffer = byteStream.toByteArray();
         out.writeInt( buffer.length );
@@ -261,11 +257,15 @@ public abstract class ImageComponentStat
         byte[] buffer = new byte[ size ];
         in.readFully( buffer );
         ByteArrayInputStream byteStream = new ByteArrayInputStream( buffer );
-        
-        JPEGImageDecoder decoder = JPEGCodec.createJPEGDecoder( byteStream );
-        byteStream.close();
-        
-        return decoder.decodeAsBufferedImage();
+        try {
+            BufferedImage img = ImageIO.read(byteStream);
+            if (img == null) {
+                throw new AssertionError("No ImageReader available.");
+            }
+            return img;
+        } finally {
+            byteStream.close();
+        }
     }
     
     private void writeColorModel( DataOutput out, ColorModel colorModel ) throws IOException {
