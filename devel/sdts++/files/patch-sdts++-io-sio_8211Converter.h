--- sdts++/io/sio_8211Converter.h.orig	2002-12-03 21:48:05.000000000 +0300
+++ sdts++/io/sio_8211Converter.h	2012-03-11 19:56:04.000000000 +0300
@@ -51,14 +51,16 @@
                                      char const* data,
                                      long bitLength) const = 0;
 
-#ifdef VECTOR_ITERATOR_POINTER_NOT_EQUIVALENT
-      long makeFixedSubfield(sc_Subfield& subfield,
-                                     std::vector<char>::const_iterator & data,
-                                     long bitLength) const
-        {
-          return makeFixedSubfield( subfield, &data[0], bitLength );
-        }
-#endif
+// The overload, incorrectly permitted by Autoconf, is disabled
+
+// #ifdef VECTOR_ITERATOR_POINTER_NOT_EQUIVALENT
+//       long makeFixedSubfield(sc_Subfield& subfield,
+//                                      std::vector<char>::const_iterator & data,
+//                                      long bitLength) const
+//         {
+//           return makeFixedSubfield( subfield, &data[0], bitLength );
+//         }
+// #endif
 
       /// Variable width subfields
       /** Returns the length of the data converted. This does not__ included
@@ -68,15 +70,17 @@
                                    long maxLength,
                                    char delimiter) const;
 
-#ifdef VECTOR_ITERATOR_POINTER_NOT_EQUIVALENT
-      long makeVarSubfield(sc_Subfield& subfield,
-                                   std::vector<char>::const_iterator & data,
-                                   long maxLength,
-                                   char delimiter) const
-        {
-          return makeVarSubfield( subfield, &data[0], maxLength, delimiter );
-        }
-#endif
+// The overload, incorrectly permitted by Autoconf, is disabled
+
+// #ifdef VECTOR_ITERATOR_POINTER_NOT_EQUIVALENT
+//       long makeVarSubfield(sc_Subfield& subfield,
+//                                    std::vector<char>::const_iterator & data,
+//                                    long maxLength,
+//                                    char delimiter) const
+//         {
+//           return makeVarSubfield( subfield, &data[0], maxLength, delimiter );
+//         }
+// #endif
 
       /// Adds a "null field" (adds an end-of-field character) to the buffer.
       virtual long addEmptySubfield(sio_Buffer& buffer) const;
