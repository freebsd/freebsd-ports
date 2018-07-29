error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]

--- Foundation/src/NumberFormatter.cpp.orig	2018-07-29 11:30:18 UTC
+++ Foundation/src/NumberFormatter.cpp
@@ -245,7 +245,7 @@ void NumberFormatter::appendHex(std::string& str, unsi
 void NumberFormatter::append(std::string& str, Int64 value)
 {
 	char buffer[64];
-	std::sprintf(buffer, "%"I64_FMT"d", value);
+	std::sprintf(buffer, "%" I64_FMT "d", value);
 	str.append(buffer);
 }
 
@@ -255,7 +255,7 @@ void NumberFormatter::append(std::string& str, Int64 v
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%*"I64_FMT"d", width, value);
+	std::sprintf(buffer, "%*" I64_FMT "d", width, value);
 	str.append(buffer);
 }
 
@@ -265,7 +265,7 @@ void NumberFormatter::append0(std::string& str, Int64 
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%0*"I64_FMT"d", width, value);
+	std::sprintf(buffer, "%0*" I64_FMT "d", width, value);
 	str.append(buffer);
 }
 
@@ -273,7 +273,7 @@ void NumberFormatter::append0(std::string& str, Int64 
 void NumberFormatter::appendHex(std::string& str, Int64 value)
 {
 	char buffer[64];
-	std::sprintf(buffer, "%"I64_FMT"X", value);
+	std::sprintf(buffer, "%" I64_FMT "X", value);
 	str.append(buffer);
 }
 
@@ -283,7 +283,7 @@ void NumberFormatter::appendHex(std::string& str, Int6
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
+	std::sprintf(buffer, "%0*" I64_FMT "X", width, value);
 	str.append(buffer);
 }
 
@@ -291,7 +291,7 @@ void NumberFormatter::appendHex(std::string& str, Int6
 void NumberFormatter::append(std::string& str, UInt64 value)
 {
 	char buffer[64];
-	std::sprintf(buffer, "%"I64_FMT"u", value);
+	std::sprintf(buffer, "%" I64_FMT "u", value);
 	str.append(buffer);
 }
 
@@ -301,7 +301,7 @@ void NumberFormatter::append(std::string& str, UInt64 
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%*"I64_FMT"u", width, value);
+	std::sprintf(buffer, "%*" I64_FMT "u", width, value);
 	str.append(buffer);
 }
 
@@ -311,7 +311,7 @@ void NumberFormatter::append0(std::string& str, UInt64
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%0*"I64_FMT"u", width, value);
+	std::sprintf(buffer, "%0*" I64_FMT "u", width, value);
 	str.append(buffer);
 }
 
@@ -319,7 +319,7 @@ void NumberFormatter::append0(std::string& str, UInt64
 void NumberFormatter::appendHex(std::string& str, UInt64 value)
 {
 	char buffer[64];
-	std::sprintf(buffer, "%"I64_FMT"X", value);
+	std::sprintf(buffer, "%" I64_FMT "X", value);
 	str.append(buffer);
 }
 
@@ -329,7 +329,7 @@ void NumberFormatter::appendHex(std::string& str, UInt
 	poco_assert (width > 0 && width < 64);
 
 	char buffer[64];
-	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
+	std::sprintf(buffer, "%0*" I64_FMT "X", width, value);
 	str.append(buffer);
 }
 
@@ -396,7 +396,7 @@ void NumberFormatter::append(std::string& str, const v
 	#if defined(POCO_LONG_IS_64_BIT)
 		std::sprintf(buffer, "%016lX", (UIntPtr) ptr);
 	#else
-		std::sprintf(buffer, "%016"I64_FMT"X", (UIntPtr) ptr);
+		std::sprintf(buffer, "%016" I64_FMT "X", (UIntPtr) ptr);
 	#endif
 #else
 	std::sprintf(buffer, "%08lX", (UIntPtr) ptr);
