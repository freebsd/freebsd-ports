
$FreeBSD$

--- src/libFLAC++/metadata.cpp.orig
+++ src/libFLAC++/metadata.cpp
@@ -33,6 +33,7 @@
 #include "FLAC/assert.h"
 #include <stdlib.h> // for malloc(), free()
 #include <string.h> // for memcpy() etc.
+#include "share/alloc.h"
 
 #ifdef _MSC_VER
 // warning C4800: 'int' : forcing to bool 'true' or 'false' (performance warning)
@@ -568,7 +569,7 @@
 
 			clear_entry();
 
-			if(0 == (entry_.entry = (FLAC__byte*)malloc(field_length+1))) {
+			if(0 == (entry_.entry = (FLAC__byte*)safe_malloc_add_2op_(field_length, /*+*/1))) {
 				is_valid_ = false;
 			}
 			else {
@@ -617,7 +618,7 @@
 
 			clear_field_value();
 
-			if(0 == (field_value_ = (char *)malloc(field_value_length+1))) {
+			if(0 == (field_value_ = (char *)safe_malloc_add_2op_(field_value_length, /*+*/1))) {
 				is_valid_ = false;
 			}
 			else {
@@ -707,7 +708,7 @@
 		{
 			clear_entry();
 
-			if(0 == (entry_.entry = (FLAC__byte*)malloc(field_name_length_ + 1 + field_value_length_ + 1))) {
+			if(0 == (entry_.entry = (FLAC__byte*)safe_malloc_add_4op_(field_name_length_, /*+*/1, /*+*/field_value_length_, /*+*/1))) {
 				is_valid_ = false;
 			}
 			else {
@@ -733,7 +734,7 @@
 				p = (const char *)entry_.entry + entry_.length;
 
 			field_name_length_ = p - (const char *)entry_.entry;
-			if(0 == (field_name_ = (char *)malloc(field_name_length_ + 1))) { // +1 for the trailing \0
+			if(0 == (field_name_ = (char *)safe_malloc_add_2op_(field_name_length_, /*+*/1))) { // +1 for the trailing \0
 				is_valid_ = false;
 				return;
 			}
@@ -742,14 +743,14 @@
 
 			if(entry_.length - field_name_length_ == 0) {
 				field_value_length_ = 0;
-				if(0 == (field_value_ = (char *)malloc(0))) {
+				if(0 == (field_value_ = (char *)safe_malloc_(0))) {
 					is_valid_ = false;
 					return;
 				}
 			}
 			else {
 				field_value_length_ = entry_.length - field_name_length_ - 1;
-				if(0 == (field_value_ = (char *)malloc(field_value_length_ + 1))) { // +1 for the trailing \0
+				if(0 == (field_value_ = (char *)safe_malloc_add_2op_(field_value_length_, /*+*/1))) { // +1 for the trailing \0
 					is_valid_ = false;
 					return;
 				}
