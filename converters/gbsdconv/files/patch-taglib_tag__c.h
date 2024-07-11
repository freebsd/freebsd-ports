--- taglib/tag_c.h.orig	2014-02-15 21:45:54 UTC
+++ taglib/tag_c.h
@@ -29,7 +29,9 @@ extern "C" {
 extern "C" {
 #endif
 
-#if defined(_WIN32) || defined(_WIN64)
+#if defined(TAGLIB_STATIC)
+#define TAGLIB_C_EXPORT
+#elif defined(_WIN32) || defined(_WIN64)
 #ifdef MAKE_TAGLIB_C_LIB
 #define TAGLIB_C_EXPORT __declspec(dllexport)
 #else
@@ -41,7 +43,10 @@ extern "C" {
 #define TAGLIB_C_EXPORT
 #endif
 
-#ifndef BOOL
+#ifdef _MSC_VER
+/* minwindef.h contains typedef int BOOL */
+#include <windows.h>
+#elif !defined BOOL
 #define BOOL int
 #endif
 
@@ -55,14 +60,15 @@ extern "C" {
  *******************************************************************************/
 
 /*
- * These are used for type provide some type safety to the C API (as opposed to
- * using void *, but pointers to them are simply cast to the corresponding C++
+ * These are used to give the C API some type safety (as opposed to
+ * using void * ), but pointers to them are simply cast to the corresponding C++
  * types in the implementation.
  */
 
 typedef struct { int dummy; } TagLib_File;
 typedef struct { int dummy; } TagLib_Tag;
 typedef struct { int dummy; } TagLib_AudioProperties;
+typedef struct { int dummy; } TagLib_IOStream;
 typedef struct { int dummy; } TagLib_Mpeg_File;
 
 /*!
@@ -86,6 +92,22 @@ TAGLIB_C_EXPORT void taglib_free(void* pointer);
 TAGLIB_C_EXPORT void taglib_free(void* pointer);
 
 /*******************************************************************************
+ * Stream API
+ ******************************************************************************/
+
+/*!
+ * Creates a byte vector stream from \a size bytes of \a data.
+ * Such a stream can be used with taglib_file_new_iostream() to create a file
+ * from memory.
+ */
+TAGLIB_C_EXPORT TagLib_IOStream *taglib_memory_iostream_new(const char *data, unsigned int size);
+
+/*!
+ * Frees and closes the stream.
+ */
+TAGLIB_C_EXPORT void taglib_iostream_free(TagLib_IOStream *stream);
+
+/*******************************************************************************
  * File API
  ******************************************************************************/
 
@@ -99,7 +121,17 @@ typedef enum {
   TagLib_File_Speex,
   TagLib_File_TrueAudio,
   TagLib_File_MP4,
-  TagLib_File_ASF
+  TagLib_File_ASF,
+  TagLib_File_AIFF,
+  TagLib_File_WAV,
+  TagLib_File_APE,
+  TagLib_File_IT,
+  TagLib_File_Mod,
+  TagLib_File_S3M,
+  TagLib_File_XM,
+  TagLib_File_Opus,
+  TagLib_File_DSF,
+  TagLib_File_DSDIFF
 } TagLib_File_Type;
 
 /*!
@@ -118,12 +150,22 @@ TAGLIB_C_EXPORT TagLib_File *taglib_file_new_type(cons
 TAGLIB_C_EXPORT TagLib_File *taglib_file_new_type(const char *filename, TagLib_File_Type type);
 
 /*!
+ * Creates a TagLib file from a \a stream.
+ * A byte vector stream can be used to read a file from memory and write to
+ * memory, e.g. when fetching network data.
+ * The stream has to be created using taglib_memory_iostream_new() and shall be
+ * freed using taglib_iostream_free() \e after this file is freed with
+ * taglib_file_free().
+ */
+TAGLIB_C_EXPORT TagLib_File *taglib_file_new_iostream(TagLib_IOStream *stream);
+
+/*!
  * Frees and closes the file.
  */
 TAGLIB_C_EXPORT void taglib_file_free(TagLib_File *file);
 
 /*!
- * Returns true if the file is open and readble and valid information for
+ * Returns \c true if the file is open and readable and valid information for
  * the Tag and / or AudioProperties was found.
  */
 
@@ -136,7 +178,7 @@ TAGLIB_C_EXPORT TagLib_Tag *taglib_file_tag(const TagL
 TAGLIB_C_EXPORT TagLib_Tag *taglib_file_tag(const TagLib_File *file);
 
 /*!
- * Returns a pointer to the the audio properties associated with this file.  This
+ * Returns a pointer to the audio properties associated with this file.  This
  * will be freed automatically when the file is freed.
  */
 TAGLIB_C_EXPORT const TagLib_AudioProperties *taglib_file_audioproperties(const TagLib_File *file);
@@ -191,12 +233,12 @@ TAGLIB_C_EXPORT char *taglib_tag_genre(const TagLib_Ta
 TAGLIB_C_EXPORT char *taglib_tag_genre(const TagLib_Tag *tag);
 
 /*!
- * Returns the tag's year or 0 if year is not set.
+ * Returns the tag's year or 0 if the year is not set.
  */
 TAGLIB_C_EXPORT unsigned int taglib_tag_year(const TagLib_Tag *tag);
 
 /*!
- * Returns the tag's track number or 0 if track number is not set.
+ * Returns the tag's track number or 0 if the track number is not set.
  */
 TAGLIB_C_EXPORT unsigned int taglib_tag_track(const TagLib_Tag *tag);
 
@@ -284,14 +326,14 @@ TAGLIB_C_EXPORT TagLib_Mpeg_File *taglib_mpeg_file(Tag
 TAGLIB_C_EXPORT TagLib_Mpeg_File *taglib_mpeg_file(TagLib_File *file);
 
 /*!
- * bool TagLib::MPEG:File::save(int tags, bool stripOthers, int id3v2Version);
+ * bool TagLib::MPEG::File::save(int tags, StripTags strip, ID3v2::Version version, DuplicateTags duplicate);
  */
-TAGLIB_C_EXPORT BOOL taglib_mpeg_file_save3(TagLib_Mpeg_File *file, int tags, BOOL stripOthers, int id3v2Version);
+TAGLIB_C_EXPORT BOOL taglib_mpeg_file_save3(TagLib_Mpeg_File *file, int tags, BOOL stripOthers, int id3v2Version, BOOL duplicateTags);
 
 /*!
- * bool TagLib::MPEG:File::strip(int tags);
+ * bool TagLib::MPEG::File::strip(int tags, bool freeMemory);
  */
-TAGLIB_C_EXPORT BOOL taglib_mpeg_file_strip(TagLib_Mpeg_File *file, int tags);
+TAGLIB_C_EXPORT BOOL taglib_mpeg_file_strip(TagLib_Mpeg_File *file, int tags, BOOL freeMemory);
 
 /*******************************************************************************
  * Special convenience ID3v2 functions
@@ -309,6 +351,275 @@ TAGLIB_C_EXPORT void taglib_id3v2_set_default_text_enc
  */
 
 TAGLIB_C_EXPORT void taglib_id3v2_set_default_text_encoding(TagLib_ID3v2_Encoding encoding);
+
+/******************************************************************************
+ * Properties API
+ ******************************************************************************/
+
+/*!
+ * Sets the property \a prop with \a value.  Use \a value = NULL to remove
+ * the property, otherwise it will be replaced.
+ */
+TAGLIB_C_EXPORT void taglib_property_set(TagLib_File *file, const char *prop, const char *value);
+
+/*!
+ * Appends \a value to the property \a prop (sets it if non-existing).
+ * Use \a value = NULL to remove all values associated with the property.
+ */
+TAGLIB_C_EXPORT void taglib_property_set_append(TagLib_File *file, const char *prop, const char *value);
+
+/*!
+ * Get the keys of the property map.
+ *
+ * \return NULL terminated array of C-strings (char *), only NULL if empty.
+ * It must be freed by the client using taglib_property_free().
+ */
+TAGLIB_C_EXPORT char** taglib_property_keys(const TagLib_File *file);
+
+/*!
+ * Get value(s) of property \a prop.
+ *
+ * \return NULL terminated array of C-strings (char *), only NULL if empty.
+ * It must be freed by the client using taglib_property_free().
+ */
+TAGLIB_C_EXPORT char** taglib_property_get(const TagLib_File *file, const char *prop);
+
+/*!
+ * Frees the NULL terminated array \a props and the C-strings it contains.
+ */
+TAGLIB_C_EXPORT void taglib_property_free(char **props);
+
+/******************************************************************************
+ * Complex Properties API
+ ******************************************************************************/
+
+/*!
+ * Types which can be stored in a TagLib_Variant.
+ *
+ * \related TagLib::Variant::Type
+ * These correspond to TagLib::Variant::Type, but ByteVectorList, VariantList,
+ * VariantMap are not supported and will be returned as their string
+ * representation.
+ */
+typedef enum {
+  TagLib_Variant_Void,
+  TagLib_Variant_Bool,
+  TagLib_Variant_Int,
+  TagLib_Variant_UInt,
+  TagLib_Variant_LongLong,
+  TagLib_Variant_ULongLong,
+  TagLib_Variant_Double,
+  TagLib_Variant_String,
+  TagLib_Variant_StringList,
+  TagLib_Variant_ByteVector
+} TagLib_Variant_Type;
+
+/*!
+ * Discriminated union used in complex property attributes.
+ *
+ * \e type must be set according to the \e value union used.
+ * \e size is only required for TagLib_Variant_ByteVector and must contain
+ * the number of bytes.
+ *
+ * \related TagLib::Variant.
+ */
+typedef struct {
+  TagLib_Variant_Type type;
+  unsigned int size;
+  union {
+    char *stringValue;
+    char *byteVectorValue;
+    char **stringListValue;
+    BOOL boolValue;
+    int intValue;
+    unsigned int uIntValue;
+    long long longLongValue;
+    unsigned long long uLongLongValue;
+    double doubleValue;
+  } value;
+} TagLib_Variant;
+
+/*!
+ * Attribute of a complex property.
+ * Complex properties consist of a NULL-terminated array of pointers to
+ * this structure with \e key and \e value.
+ */
+typedef struct {
+  char *key;
+  TagLib_Variant value;
+} TagLib_Complex_Property_Attribute;
+
+/*!
+ * Picture data extracted from a complex property by the convenience function
+ * taglib_picture_from_complex_property().
+ */
+typedef struct {
+  char *mimeType;
+  char *description;
+  char *pictureType;
+  char *data;
+  unsigned int size;
+} TagLib_Complex_Property_Picture_Data;
+
+/*!
+ * Declare complex property attributes to set a picture.
+ * Can be used to define a variable \a var which can be used with
+ * taglib_complex_property_set() and a "PICTURE" key to set an
+ * embedded picture with the picture data \a dat of size \a siz
+ * and description \a desc, mime type \a mime and picture type
+ * \a typ (size is unsigned int, the other input parameters char *).
+ */
+#define TAGLIB_COMPLEX_PROPERTY_PICTURE(var, dat, siz, desc, mime, typ)   \
+const TagLib_Complex_Property_Attribute            \
+var##Attrs[] = {                                   \
+  {                                                \
+    (char *)"data",                                \
+    {                                              \
+      TagLib_Variant_ByteVector,                   \
+      (siz),                                       \
+      {                                            \
+        (char *)(dat)                              \
+      }                                            \
+    }                                              \
+  },                                               \
+  {                                                \
+    (char *)"mimeType",                            \
+    {                                              \
+      TagLib_Variant_String,                       \
+      0U,                                          \
+      {                                            \
+        (char *)(mime)                             \
+      }                                            \
+    }                                              \
+  },                                               \
+  {                                                \
+    (char *)"description",                         \
+    {                                              \
+      TagLib_Variant_String,                       \
+      0U,                                          \
+      {                                            \
+        (char *)(desc)                             \
+      }                                            \
+    }                                              \
+  },                                               \
+  {                                                \
+    (char *)"pictureType",                         \
+    {                                              \
+      TagLib_Variant_String,                       \
+      0U,                                          \
+      {                                            \
+        (char *)(typ)                              \
+      }                                            \
+    }                                              \
+  }                                                \
+};                                                 \
+const TagLib_Complex_Property_Attribute *var[] = { \
+  &var##Attrs[0], &var##Attrs[1], &var##Attrs[2],  \
+  &var##Attrs[3], NULL                             \
+}
+
+/*!
+ * Sets the complex property \a key with \a value.  Use \a value = NULL to
+ * remove the property, otherwise it will be replaced with the NULL
+ * terminated array of attributes in \a value.
+ *
+ * A picture can be set with the TAGLIB_COMPLEX_PROPERTY_PICTURE macro:
+ *
+ * \code {.c}
+ * TagLib_File *file = taglib_file_new("myfile.mp3");
+ * FILE *fh = fopen("mypicture.jpg", "rb");
+ * if(fh) {
+ *   fseek(fh, 0L, SEEK_END);
+ *   long size = ftell(fh);
+ *   fseek(fh, 0L, SEEK_SET);
+ *   char *data = (char *)malloc(size);
+ *   fread(data, size, 1, fh);
+ *   TAGLIB_COMPLEX_PROPERTY_PICTURE(props, data, size, "Written by TagLib",
+ *                                   "image/jpeg", "Front Cover");
+ *   taglib_complex_property_set(file, "PICTURE", props);
+ *   taglib_file_save(file);
+ *   free(data);
+ *   fclose(fh);
+ * }
+ * \endcode
+ */
+TAGLIB_C_EXPORT BOOL taglib_complex_property_set(
+  TagLib_File *file, const char *key,
+  const TagLib_Complex_Property_Attribute **value);
+
+/*!
+ * Appends \a value to the complex property \a key (sets it if non-existing).
+ * Use \a value = NULL to remove all values associated with the \a key.
+ */
+TAGLIB_C_EXPORT BOOL taglib_complex_property_set_append(
+  TagLib_File *file, const char *key,
+  const TagLib_Complex_Property_Attribute **value);
+
+/*!
+ * Get the keys of the complex properties.
+ *
+ * \return NULL terminated array of C-strings (char *), only NULL if empty.
+ * It must be freed by the client using taglib_complex_property_free_keys().
+ */
+TAGLIB_C_EXPORT char** taglib_complex_property_keys(const TagLib_File *file);
+
+/*!
+ * Get value(s) of complex property \a key.
+ *
+ * \return NULL terminated array of property values, which are themselves an
+ * array of property attributes, only NULL if empty.
+ * It must be freed by the client using taglib_complex_property_free().
+ */
+TAGLIB_C_EXPORT TagLib_Complex_Property_Attribute*** taglib_complex_property_get(
+  const TagLib_File *file, const char *key);
+
+/*!
+ * Extract the complex property values of a picture.
+ *
+ * This function can be used to get the data from a "PICTURE" complex property
+ * without having to traverse the whole variant map. A picture can be
+ * retrieved like this:
+ *
+ * \code {.c}
+ * TagLib_File *file = taglib_file_new("myfile.mp3");
+ * TagLib_Complex_Property_Attribute*** properties =
+ *   taglib_complex_property_get(file, "PICTURE");
+ * TagLib_Complex_Property_Picture_Data picture;
+ * taglib_picture_from_complex_property(properties, &picture);
+ * // Do something with picture.mimeType, picture.description,
+ * // picture.pictureType, picture.data, picture.size, e.g. extract it.
+ * FILE *fh = fopen("mypicture.jpg", "wb");
+ * if(fh) {
+ *   fwrite(picture.data, picture.size, 1, fh);
+ *   fclose(fh);
+ * }
+ * taglib_complex_property_free(properties);
+ * \endcode
+ *
+ * Note that the data in \a picture contains pointers to data in \a properties,
+ * i.e. it only lives as long as the properties, until they are freed with
+ * taglib_complex_property_free().
+ * If you want to access multiple pictures or additional properties of FLAC
+ * pictures ("width", "height", "numColors", "colorDepth" int values), you
+ * have to traverse the \a properties yourself.
+ */
+TAGLIB_C_EXPORT void taglib_picture_from_complex_property(
+  TagLib_Complex_Property_Attribute*** properties,
+  TagLib_Complex_Property_Picture_Data *picture);
+
+/*!
+ * Frees the NULL terminated array \a keys (as returned by
+ * taglib_complex_property_keys()) and the C-strings it contains.
+ */
+TAGLIB_C_EXPORT void taglib_complex_property_free_keys(char **keys);
+
+/*!
+ * Frees the NULL terminated array \a props of property attribute arrays
+ * (as returned by taglib_complex_property_get()) and the data such as
+ * C-strings and byte vectors contained in these attributes.
+ */
+TAGLIB_C_EXPORT void taglib_complex_property_free(
+  TagLib_Complex_Property_Attribute ***props);
 
 #ifdef __cplusplus
 }
