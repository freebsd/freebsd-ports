--- rtengine/LibRaw.cmake.orig	2025-05-28 01:02:22 UTC
+++ rtengine/LibRaw.cmake
@@ -33,6 +33,27 @@ execute_process(
 # Configuration commands.
 message(STATUS "Configuring LibRaw")
 execute_process(
+	COMMAND pkg-config --cflags-only-I libjpeg
+	RESULT_VARIABLE PROCESS_RESULT
+	OUTPUT_VARIABLE JPEG_BIGI_FLAGS
+	OUTPUT_STRIP_TRAILING_WHITESPACE
+)
+if(PROCESS_RESULT AND NOT PROCESS_RESULT EQUAL 0)
+	message(FATAL_ERROR "Could not obtain libjpeg -I flags from pkg-config")
+endif()
+execute_process(
+	COMMAND pkg-config --libs-only-L libjpeg
+	RESULT_VARIABLE PROCESS_RESULT
+	OUTPUT_VARIABLE JPEG_BIGL_FLAGS
+	OUTPUT_STRIP_TRAILING_WHITESPACE
+)
+if(PROCESS_RESULT AND NOT PROCESS_RESULT EQUAL 0)
+	message(FATAL_ERROR "Could not obtain libjpeg -L flags from pkg-config")
+endif()
+message(STATUS "libjpeg flags (from pkg-config): CFLAGS=\"${JPEG_BIGI_FLAGS}\" LIBS=\"${JPEG_BIGL_FLAGS}\"")
+set(CONFIGURE_FLAGS "${CONFIGURE_FLAGS} CFLAGS=\"${CFLAGS} ${JPEG_BIGI_FLAGS}\"")
+set(CONFIGURE_FLAGS "${CONFIGURE_FLAGS} LIBS=\"${LIBS} ${JPEG_BIGL_FLAGS}\"")
+execute_process(
     COMMAND cp -p -R "${CMAKE_CURRENT_SOURCE_DIR}/libraw" .
     WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
     RESULT_VARIABLE PROCESS_RESULT
