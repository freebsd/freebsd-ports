--- src/SWIG_files/wrapper/TCollection.i.orig	2026-08-06 17:42:37 UTC
+++ src/SWIG_files/wrapper/TCollection.i
@@ -141,7 +141,7 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with a string_view. 
+Initializes a AsciiString with a string_view.
 Input parameter: theStringView the string view to initialize from.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const std::string_view & theStringView);
@@ -160,7 +160,7 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with a CString (null-terminated). 
+Initializes a AsciiString with a CString (null-terminated).
 Input parameter: theMessage the C string to initialize from.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const char * const theMessage);
@@ -180,8 +180,8 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with a CString and explicit length. 
-Input parameter: theMessage the C string to initialize from 
+Initializes a AsciiString with a CString and explicit length.
+Input parameter: theMessage the C string to initialize from
 Input parameter: theLength the length of the string.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const char * const theMessage, const int theLength);
@@ -200,7 +200,7 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with a single character. 
+Initializes a AsciiString with a single character.
 Input parameter: theChar the character to initialize from.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const char theChar);
@@ -220,8 +220,8 @@ -----------
 
 Description
 -----------
-Initializes an AsciiString with specified length space allocated and filled with filler character. This is useful for buffers. 
-Input parameter: theLength the length to allocate 
+Initializes an AsciiString with specified length space allocated and filled with filler character. This is useful for buffers.
+Input parameter: theLength the length to allocate
 Input parameter: theFiller the character to fill with.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const int theLength, const char theFiller);
@@ -240,7 +240,7 @@ -----------
 
 Description
 -----------
-Initializes an AsciiString with an integer value 
+Initializes an AsciiString with an integer value
 Input parameter: theValue the integer value to convert to string.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const int theValue);
@@ -259,7 +259,7 @@ -----------
 
 Description
 -----------
-Initializes an AsciiString with a real value 
+Initializes an AsciiString with a real value
 Input parameter: theValue the real value to convert to string.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const double theValue);
@@ -278,7 +278,7 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with another AsciiString. 
+Initializes a AsciiString with another AsciiString.
 Input parameter: theString the string to copy from.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_AsciiString theString);
@@ -297,7 +297,7 @@ -----------
 
 Description
 -----------
-Move constructor 
+Move constructor
 Input parameter: theOther the string to move from.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_AsciiString & theOther);
@@ -317,8 +317,8 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with copy of another AsciiString concatenated with the message character. 
-Input parameter: theString the string to copy 
+Initializes a AsciiString with copy of another AsciiString concatenated with the message character.
+Input parameter: theString the string to copy
 Input parameter: theChar the character to append.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_AsciiString theString, const char theChar);
@@ -338,8 +338,8 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with copy of another AsciiString concatenated with the message string. 
-Input parameter: theString the string to copy 
+Initializes a AsciiString with copy of another AsciiString concatenated with the message string.
+Input parameter: theString the string to copy
 Input parameter: theMessage the C string to append.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_AsciiString theString, const char * const theMessage);
@@ -359,8 +359,8 @@ -----------
 
 Description
 -----------
-Initializes a AsciiString with copy of another AsciiString concatenated with the message string. 
-Input parameter: theString the string to copy 
+Initializes a AsciiString with copy of another AsciiString concatenated with the message string.
+Input parameter: theString the string to copy
 Input parameter: theOtherString the string to append.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_AsciiString theString, TCollection_AsciiString theOtherString);
@@ -380,8 +380,8 @@ -----------
 
 Description
 -----------
-Creation by converting an extended string to an ascii string. If replaceNonAscii is non-null character, it will be used in place of any non-ascii character found in the source string. Otherwise, creates UTF-8 unicode string. 
-Input parameter: theExtendedString the extended string to convert 
+Creation by converting an extended string to an ascii string. If replaceNonAscii is non-null character, it will be used in place of any non-ascii character found in the source string. Otherwise, creates UTF-8 unicode string.
+Input parameter: theExtendedString the extended string to convert
 Input parameter: theReplaceNonAscii replacement character for non-ASCII characters.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(TCollection_ExtendedString theExtendedString, const char theReplaceNonAscii = 0);
@@ -400,7 +400,7 @@ -----------
 
 Description
 -----------
-Initialize UTF-8 Unicode string from wide-char string considering it as Unicode string (the size of wide char is a platform-dependent - e.g. on Windows wchar_t is UTF-16). //! This constructor is unavailable if application is built with deprecated msvc option '-Zc:wchar_t-', since OCCT itself is never built with this option. 
+Initialize UTF-8 Unicode string from wide-char string considering it as Unicode string (the size of wide char is a platform-dependent - e.g. on Windows wchar_t is UTF-16). //! This constructor is unavailable if application is built with deprecated msvc option '-Zc:wchar_t-', since OCCT itself is never built with this option.
 Input parameter: theStringUtf the wide character string to convert.
 ") TCollection_AsciiString;
 		 TCollection_AsciiString(const wchar_t * theStringUtf);
@@ -419,7 +419,7 @@ -----------
 
 Description
 -----------
-Appends other character to this string. This is an unary operator. 
+Appends other character to this string. This is an unary operator.
 Input parameter: theOther the character to append.
 ") AssignCat;
 		void AssignCat(const char theOther);
@@ -438,7 +438,7 @@ -----------
 
 Description
 -----------
-Appends other integer to this string. This is an unary operator. 
+Appends other integer to this string. This is an unary operator.
 Input parameter: theOther the integer to append.
 ") AssignCat;
 		void AssignCat(const int theOther);
@@ -457,7 +457,7 @@ -----------
 
 Description
 -----------
-Appends other real number to this string. This is an unary operator. 
+Appends other real number to this string. This is an unary operator.
 Input parameter: theOther the real number to append.
 ") AssignCat;
 		void AssignCat(const double theOther);
@@ -477,8 +477,8 @@ -----------
 
 Description
 -----------
-Appends an extended string to this ASCII string. If theReplaceNonAscii is non-null character, it will be used in place of any non-ASCII character found in the source string. Otherwise, appends UTF-8 representation of the source string. 
-Input parameter: theOther the extended string to append 
+Appends an extended string to this ASCII string. If theReplaceNonAscii is non-null character, it will be used in place of any non-ASCII character found in the source string. Otherwise, appends UTF-8 representation of the source string.
+Input parameter: theOther the extended string to append
 Input parameter: theReplaceNonAscii replacement character for non-ASCII characters.
 ") AssignCat;
 		void AssignCat(TCollection_ExtendedString theOther, const char theReplaceNonAscii = 0);
@@ -497,7 +497,7 @@ -----------
 
 Description
 -----------
-Appends wide-char string converted to UTF-8 representation. 
+Appends wide-char string converted to UTF-8 representation.
 Input parameter: theStringUtf the wide character string to append.
 ") AssignCat;
 		void AssignCat(const wchar_t * theStringUtf);
@@ -517,8 +517,8 @@ -----------
 
 Description
 -----------
-Core implementation: Appends string (pointer and length) to this ASCII string. This is the primary implementation that all other AssignCat overloads redirect to. 
-Input parameter: theString pointer to the string to append 
+Core implementation: Appends string (pointer and length) to this ASCII string. This is the primary implementation that all other AssignCat overloads redirect to.
+Input parameter: theString pointer to the string to append
 Input parameter: theLength length of the string to append.
 ") AssignCat;
 		void AssignCat(const char * const theString, const int theLength);
@@ -537,7 +537,7 @@ -----------
 
 Description
 -----------
-Appends other string to this string. This is an unary operator. //! Example: ```cpp TCollection_AsciiString aString('Hello'); TCollection_AsciiString anotherString(' World'); aString += anotherString; // Result: aString == 'Hello World' ``` 
+Appends other string to this string. This is an unary operator. //! Example: ```cpp TCollection_AsciiString aString('Hello'); TCollection_AsciiString anotherString(' World'); aString += anotherString; // Result: aString == 'Hello World' ```
 Input parameter: theOther the string to append.
 ") AssignCat;
 		void AssignCat(TCollection_AsciiString theOther);
@@ -556,7 +556,7 @@ -----------
 
 Description
 -----------
-Appends C string to this ASCII string. 
+Appends C string to this ASCII string.
 Input parameter: theCString the C string to append.
 ") AssignCat;
 		void AssignCat(const char * const theCString);
@@ -575,7 +575,7 @@ -----------
 
 Description
 -----------
-Appends string view to this ASCII string. This is an unary operator. 
+Appends string view to this ASCII string. This is an unary operator.
 Input parameter: theStringView the string view to append.
 ") AssignCat;
 		void AssignCat(const std::string_view & theStringView);
@@ -608,9 +608,9 @@ -----------
 
 Description
 -----------
-Core implementation: Appends string (pointer and length) to this ASCII string and returns a new string. This is the primary implementation that all other Cat overloads redirect to. 
-Input parameter: theString pointer to the string to append 
-Input parameter: theLength length of the string to append 
+Core implementation: Appends string (pointer and length) to this ASCII string and returns a new string. This is the primary implementation that all other Cat overloads redirect to.
+Input parameter: theString pointer to the string to append
+Input parameter: theLength length of the string to append
 Return: new string with the string appended.
 ") Cat;
 		TCollection_AsciiString Cat(const char * const theString, const int theLength);
@@ -629,8 +629,8 @@ -----------
 
 Description
 -----------
-Appends other character to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + '!'; // Result: aResult == 'I say !' //! // To catenate more, you must put a String before. // 'Hello ' + 'Dolly' // THIS IS NOT ALLOWED // This rule is applicable to AssignCat (operator +=) too. ``` 
-Input parameter: theOther the character to append 
+Appends other character to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + '!'; // Result: aResult == 'I say !' //! // To catenate more, you must put a String before. // 'Hello ' + 'Dolly' // THIS IS NOT ALLOWED // This rule is applicable to AssignCat (operator +=) too. ```
+Input parameter: theOther the character to append
 Return: new string with character appended.
 ") Cat;
 		TCollection_AsciiString Cat(const char theOther);
@@ -649,8 +649,8 @@ -----------
 
 Description
 -----------
-Appends other integer to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + 15; // Result: aResult == 'I say 15' ``` 
-Input parameter: theOther the integer to append 
+Appends other integer to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + 15; // Result: aResult == 'I say 15' ```
+Input parameter: theOther the integer to append
 Return: new string with integer appended.
 ") Cat;
 		TCollection_AsciiString Cat(const int theOther);
@@ -669,8 +669,8 @@ -----------
 
 Description
 -----------
-Appends other real number to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + 15.15; // Result: aResult == 'I say 15.15' ``` 
-Input parameter: theOther the real number to append 
+Appends other real number to this string. //! Example: ```cpp TCollection_AsciiString aString('I say '); TCollection_AsciiString aResult = aString + 15.15; // Result: aResult == 'I say 15.15' ```
+Input parameter: theOther the real number to append
 Return: new string with real number appended.
 ") Cat;
 		TCollection_AsciiString Cat(const double theOther);
@@ -690,9 +690,9 @@ -----------
 
 Description
 -----------
-Appends extended string to this string. If theReplaceNonAscii is non-null character, it will be used in place of any non-ASCII character found in the source string. Otherwise, concatenates UTF-8 representation of the source string. 
-Input parameter: theOther the extended string to append 
-Input parameter: theReplaceNonAscii replacement character for non-ASCII characters 
+Appends extended string to this string. If theReplaceNonAscii is non-null character, it will be used in place of any non-ASCII character found in the source string. Otherwise, concatenates UTF-8 representation of the source string.
+Input parameter: theOther the extended string to append
+Input parameter: theReplaceNonAscii replacement character for non-ASCII characters
 Return: new string with extended string appended.
 ") Cat;
 		TCollection_AsciiString Cat(TCollection_ExtendedString theOther, const char theReplaceNonAscii = 0);
@@ -711,8 +711,8 @@ -----------
 
 Description
 -----------
-Appends wide-char string converted to UTF-8 representation. 
-Input parameter: theStringUtf the wide character string to append 
+Appends wide-char string converted to UTF-8 representation.
+Input parameter: theStringUtf the wide character string to append
 Return: new string with wide-char string appended.
 ") Cat;
 		TCollection_AsciiString Cat(const wchar_t * theStringUtf);
@@ -731,8 +731,8 @@ -----------
 
 Description
 -----------
-Appends other string to this string. //! Example: ```cpp TCollection_AsciiString aString('Hello'); TCollection_AsciiString anotherString(' World'); TCollection_AsciiString aResult = aString + anotherString; // Result: aResult == 'Hello World' ``` 
-Input parameter: theOther the string to append 
+Appends other string to this string. //! Example: ```cpp TCollection_AsciiString aString('Hello'); TCollection_AsciiString anotherString(' World'); TCollection_AsciiString aResult = aString + anotherString; // Result: aResult == 'Hello World' ```
+Input parameter: theOther the string to append
 Return: new string with other string appended.
 ") Cat;
 		TCollection_AsciiString Cat(TCollection_AsciiString theOther);
@@ -751,8 +751,8 @@ -----------
 
 Description
 -----------
-Appends C string to this ASCII string. 
-Input parameter: theCString the C string to append 
+Appends C string to this ASCII string.
+Input parameter: theCString the C string to append
 Return: new string with C string appended.
 ") Cat;
 		TCollection_AsciiString Cat(const char * const theCString);
@@ -771,8 +771,8 @@ -----------
 
 Description
 -----------
-Appends string view to this ASCII string. 
-Input parameter: theStringView the string view to append 
+Appends string view to this ASCII string.
+Input parameter: theStringView the string view to append
 Return: new string with string view appended.
 ") Cat;
 		TCollection_AsciiString Cat(const std::string_view & theStringView);
@@ -792,8 +792,8 @@ -----------
 
 Description
 -----------
-Modifies this ASCII string so that its length becomes equal to Width and the new characters are equal to Filler. New characters are added both at the beginning and at the end of this string. If Width is less than the length of this ASCII string, nothing happens. //! Example: ```cpp TCollection_AsciiString anAlphabet('abcdef'); anAlphabet.Center(9, ' '); // Result: anAlphabet == ' abcdef ' ``` 
-Input parameter: theWidth the desired width 
+Modifies this ASCII string so that its length becomes equal to Width and the new characters are equal to Filler. New characters are added both at the beginning and at the end of this string. If Width is less than the length of this ASCII string, nothing happens. //! Example: ```cpp TCollection_AsciiString anAlphabet('abcdef'); anAlphabet.Center(9, ' '); // Result: anAlphabet == ' abcdef ' ```
+Input parameter: theWidth the desired width
 Input parameter: theFiller the character to fill with.
 ") Center;
 		void Center(const int theWidth, const char theFiller);
@@ -814,9 +814,9 @@ -----------
 
 Description
 -----------
-Substitutes all the characters equal to aChar by NewChar in this AsciiString. The substitution can be case sensitive. If you don't use default case sensitive, no matter whether aChar is uppercase or not. //! Example: ```cpp TCollection_AsciiString aString('Histake'); aString.ChangeAll('H', 'M', true); // Result: aString == 'Mistake' ``` 
-Input parameter: theChar the character to replace 
-Input parameter: theNewChar the replacement character 
+Substitutes all the characters equal to aChar by NewChar in this AsciiString. The substitution can be case sensitive. If you don't use default case sensitive, no matter whether aChar is uppercase or not. //! Example: ```cpp TCollection_AsciiString aString('Histake'); aString.ChangeAll('H', 'M', true); // Result: aString == 'Mistake' ```
+Input parameter: theChar the character to replace
+Input parameter: theNewChar the replacement character
 Input parameter: theCaseSensitive flag indicating case sensitivity.
 ") ChangeAll;
 		void ChangeAll(const char theChar, const char theNewChar, const bool theCaseSensitive = true);
@@ -849,8 +849,8 @@ -----------
 
 Description
 -----------
-Core implementation: Copy string (pointer and length) to this ASCII string. This is the primary implementation that all other Copy overloads redirect to. Used as operator = 
-Input parameter: theString pointer to the string to copy from 
+Core implementation: Copy string (pointer and length) to this ASCII string. This is the primary implementation that all other Copy overloads redirect to. Used as operator =
+Input parameter: theString pointer to the string to copy from
 Input parameter: theLength length of the string to copy.
 ") Copy;
 		void Copy(const char * const theString, const int theLength);
@@ -869,7 +869,7 @@ -----------
 
 Description
 -----------
-Copy C string to this ASCII string. Used as operator = 
+Copy C string to this ASCII string. Used as operator =
 Input parameter: theCString the C string to copy from.
 ") Copy;
 		void Copy(const char * const theCString);
@@ -888,7 +888,7 @@ -----------
 
 Description
 -----------
-Copy string view to this ASCII string. Used as operator = 
+Copy string view to this ASCII string. Used as operator =
 Input parameter: theStringView the string view to copy from.
 ") Copy;
 		void Copy(const std::string_view & theStringView);
@@ -920,7 +920,7 @@ -----------
 
 Description
 -----------
-Returns a const reference to a single shared empty string instance. This method provides access to a static empty string to avoid creating temporary empty strings. Use this method instead of constructing empty strings when you need a const reference. //! Example: ```cpp const TCollection_AsciiString& anEmptyStr = TCollection_AsciiString::EmptyString(); // Use anEmptyStr instead of TCollection_AsciiString() ``` 
+Returns a const reference to a single shared empty string instance. This method provides access to a static empty string to avoid creating temporary empty strings. Use this method instead of constructing empty strings when you need a const reference. //! Example: ```cpp const TCollection_AsciiString& anEmptyStr = TCollection_AsciiString::EmptyString(); // Use anEmptyStr instead of TCollection_AsciiString() ```
 Return: const reference to static empty string.
 ") EmptyString;
 		static const TCollection_AsciiString & EmptyString();
@@ -940,9 +940,9 @@ -----------
 
 Description
 -----------
-Core implementation: Determines whether the end of this string instance matches the specified string (pointer and length). 
-Input parameter: theEndString pointer to the string to check for at the end 
-Input parameter: theEndLength length of the string to check for 
+Core implementation: Determines whether the end of this string instance matches the specified string (pointer and length).
+Input parameter: theEndString pointer to the string to check for at the end
+Input parameter: theEndLength length of the string to check for
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(const char * const theEndString, const int theEndLength);
@@ -961,8 +961,8 @@ -----------
 
 Description
 -----------
-Determines whether the end of this string instance matches the specified string. 
-Input parameter: theEndString the string to check for at the end 
+Determines whether the end of this string instance matches the specified string.
+Input parameter: theEndString the string to check for at the end
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(TCollection_AsciiString theEndString);
@@ -981,8 +981,8 @@ -----------
 
 Description
 -----------
-Determines whether the end of this string instance matches the specified string_view. 
-Input parameter: theEndString the string view to check for at the end 
+Determines whether the end of this string instance matches the specified string_view.
+Input parameter: theEndString the string view to check for at the end
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(const std::string_view & theEndString);
@@ -1004,11 +1004,11 @@ -----------
 
 Description
 -----------
-Core implementation: Returns the index of the first character of this string that is present in the given character set (pointer and length). The search begins at index FromIndex and ends at index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. 
-Input parameter: theSet pointer to the set of characters to search for 
-Input parameter: theSetLength length of the set 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Core implementation: Returns the index of the first character of this string that is present in the given character set (pointer and length). The search begins at index FromIndex and ends at index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range.
+Input parameter: theSet pointer to the set of characters to search for
+Input parameter: theSetLength length of the set
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character found in set, or 0 if not found.
 ") FirstLocationInSet;
 		int FirstLocationInSet(const char * const theSet, const int theSetLength, const int theFromIndex, const int theToIndex);
@@ -1029,10 +1029,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is present in Set. The search begins to the index FromIndex and ends to the the index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAcAa'); TCollection_AsciiString aSet('Aa'); int anIndex = aString.FirstLocationInSet(aSet, 1, 7); // Result: anIndex == 1 ``` 
-Input parameter: theSet the set of characters to search for 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns the index of the first character of this string that is present in Set. The search begins to the index FromIndex and ends to the the index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAcAa'); TCollection_AsciiString aSet('Aa'); int anIndex = aString.FirstLocationInSet(aSet, 1, 7); // Result: anIndex == 1 ```
+Input parameter: theSet the set of characters to search for
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character found in set, or 0 if not found.
 ") FirstLocationInSet;
 		int FirstLocationInSet(TCollection_AsciiString theSet, const int theFromIndex, const int theToIndex);
@@ -1053,10 +1053,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is present in string_view. 
-Input parameter: theSet the string view of characters to search for 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns the index of the first character of this string that is present in string_view.
+Input parameter: theSet the string view of characters to search for
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character found in set, or 0 if not found.
 ") FirstLocationInSet;
 		int FirstLocationInSet(const std::string_view & theSet, const int theFromIndex, const int theToIndex);
@@ -1078,11 +1078,11 @@ -----------
 
 Description
 -----------
-Core implementation: Returns the index of the first character of this string that is not present in the given character set (pointer and length). The search begins at index FromIndex and ends at index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. 
-Input parameter: theSet pointer to the set of characters to check against 
-Input parameter: theSetLength length of the set 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Core implementation: Returns the index of the first character of this string that is not present in the given character set (pointer and length). The search begins at index FromIndex and ends at index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range.
+Input parameter: theSet pointer to the set of characters to check against
+Input parameter: theSetLength length of the set
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character not in set, or 0 if not found.
 ") FirstLocationNotInSet;
 		int FirstLocationNotInSet(const char * const theSet, const int theSetLength, const int theFromIndex, const int theToIndex);
@@ -1103,10 +1103,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is not present in the set Set. The search begins to the index FromIndex and ends to the the index ToIndex in this string. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAcAa'); TCollection_AsciiString aSet('Aa'); int anIndex = aString.FirstLocationNotInSet(aSet, 1, 7); // Result: anIndex == 3 ``` 
-Input parameter: theSet the set of characters to check against 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns the index of the first character of this string that is not present in the set Set. The search begins to the index FromIndex and ends to the the index ToIndex in this string. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAcAa'); TCollection_AsciiString aSet('Aa'); int anIndex = aString.FirstLocationNotInSet(aSet, 1, 7); // Result: anIndex == 3 ```
+Input parameter: theSet the set of characters to check against
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character not in set, or 0 if not found.
 ") FirstLocationNotInSet;
 		int FirstLocationNotInSet(TCollection_AsciiString theSet, const int theFromIndex, const int theToIndex);
@@ -1127,10 +1127,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is not present in string_view. 
-Input parameter: theSet the string view of characters to check against 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns the index of the first character of this string that is not present in string_view.
+Input parameter: theSet the string view of characters to check against
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first character not in set, or 0 if not found.
 ") FirstLocationNotInSet;
 		int FirstLocationNotInSet(const std::string_view & theSet, const int theFromIndex, const int theToIndex);
@@ -1144,7 +1144,7 @@ -----------
 
 Description
 -----------
-Computes a hash code for the given ASCII string Returns the same integer value as the hash function for TCollection_ExtendedString 
+Computes a hash code for the given ASCII string Returns the same integer value as the hash function for TCollection_ExtendedString
 Return: a computed hash code.
 ") HashCode;
 		size_t HashCode();
@@ -1164,8 +1164,8 @@ -----------
 
 Description
 -----------
-Inserts a Character at position where. //! Example: ```cpp TCollection_AsciiString aString('hy not ?'); aString.Insert(1, 'W'); // Result: aString == 'Why not ?' //! TCollection_AsciiString bString('Wh'); bString.Insert(3, 'y'); // Result: bString == 'Why' ``` 
-Input parameter: theWhere the position to insert at 
+Inserts a Character at position where. //! Example: ```cpp TCollection_AsciiString aString('hy not ?'); aString.Insert(1, 'W'); // Result: aString == 'Why not ?' //! TCollection_AsciiString bString('Wh'); bString.Insert(3, 'y'); // Result: bString == 'Why' ```
+Input parameter: theWhere the position to insert at
 Input parameter: theWhat the character to insert.
 ") Insert;
 		void Insert(const int theWhere, const char theWhat);
@@ -1186,9 +1186,9 @@ -----------
 
 Description
 -----------
-Core implementation: Inserts a string (pointer and length) at position theWhere. This is the primary implementation that all other Insert overloads redirect to. 
-Input parameter: theWhere position to insert at 
-Input parameter: theString pointer to the string to insert 
+Core implementation: Inserts a string (pointer and length) at position theWhere. This is the primary implementation that all other Insert overloads redirect to.
+Input parameter: theWhere position to insert at
+Input parameter: theString pointer to the string to insert
 Input parameter: theLength length of the string to insert.
 ") Insert;
 		void Insert(const int theWhere, const char * const theString, const int theLength);
@@ -1208,8 +1208,8 @@ -----------
 
 Description
 -----------
-Inserts a AsciiString at position where. 
-Input parameter: theWhere the position to insert at 
+Inserts a AsciiString at position where.
+Input parameter: theWhere the position to insert at
 Input parameter: theWhat the ASCII string to insert.
 ") Insert;
 		void Insert(const int theWhere, TCollection_AsciiString theWhat);
@@ -1229,8 +1229,8 @@ -----------
 
 Description
 -----------
-Inserts a C string at position theWhere. 
-Input parameter: theWhere position to insert at 
+Inserts a C string at position theWhere.
+Input parameter: theWhere position to insert at
 Input parameter: theCString the C string to insert.
 ") Insert;
 		void Insert(const int theWhere, const char * const theCString);
@@ -1250,8 +1250,8 @@ -----------
 
 Description
 -----------
-Inserts a string_view at position theWhere. 
-Input parameter: theWhere position to insert at 
+Inserts a string_view at position theWhere.
+Input parameter: theWhere position to insert at
 Input parameter: theStringView the string view to insert.
 ") Insert;
 		void Insert(const int theWhere, const std::string_view & theStringView);
@@ -1272,9 +1272,9 @@ -----------
 
 Description
 -----------
-Core implementation: Inserts string (pointer and length) after a specific index in this string. This is the primary implementation that all other InsertAfter overloads redirect to. Raises an exception if index is out of bounds (less than 0 or greater than the length). 
-Input parameter: theIndex the index to insert after 
-Input parameter: theString pointer to the string to insert 
+Core implementation: Inserts string (pointer and length) after a specific index in this string. This is the primary implementation that all other InsertAfter overloads redirect to. Raises an exception if index is out of bounds (less than 0 or greater than the length).
+Input parameter: theIndex the index to insert after
+Input parameter: theString pointer to the string to insert
 Input parameter: theLength length of the string to insert.
 ") InsertAfter;
 		void InsertAfter(const int theIndex, const char * const theString, const int theLength);
@@ -1294,8 +1294,8 @@ -----------
 
 Description
 -----------
-Inserts an ASCII string after a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert after 
+Inserts an ASCII string after a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert after
 Input parameter: theOther the string to insert.
 ") InsertAfter;
 		void InsertAfter(const int theIndex, TCollection_AsciiString theOther);
@@ -1315,8 +1315,8 @@ -----------
 
 Description
 -----------
-Inserts a C string after a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert after 
+Inserts a C string after a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert after
 Input parameter: theCString the C string to insert.
 ") InsertAfter;
 		void InsertAfter(const int theIndex, const char * const theCString);
@@ -1336,8 +1336,8 @@ -----------
 
 Description
 -----------
-Inserts a string_view after a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert after 
+Inserts a string_view after a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert after
 Input parameter: theStringView the string view to insert.
 ") InsertAfter;
 		void InsertAfter(const int theIndex, const std::string_view & theStringView);
@@ -1358,9 +1358,9 @@ -----------
 
 Description
 -----------
-Core implementation: Inserts string (pointer and length) before a specific index in this string. This is the primary implementation that all other InsertBefore overloads redirect to. Raises an exception if index is out of bounds (less than 1 or greater than the length). 
-Input parameter: theIndex the index to insert before 
-Input parameter: theString pointer to the string to insert 
+Core implementation: Inserts string (pointer and length) before a specific index in this string. This is the primary implementation that all other InsertBefore overloads redirect to. Raises an exception if index is out of bounds (less than 1 or greater than the length).
+Input parameter: theIndex the index to insert before
+Input parameter: theString pointer to the string to insert
 Input parameter: theLength length of the string to insert.
 ") InsertBefore;
 		void InsertBefore(const int theIndex, const char * const theString, const int theLength);
@@ -1380,8 +1380,8 @@ -----------
 
 Description
 -----------
-Inserts an ASCII string before a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert before 
+Inserts an ASCII string before a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert before
 Input parameter: theOther the string to insert.
 ") InsertBefore;
 		void InsertBefore(const int theIndex, TCollection_AsciiString theOther);
@@ -1401,8 +1401,8 @@ -----------
 
 Description
 -----------
-Inserts a C string before a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert before 
+Inserts a C string before a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert before
 Input parameter: theCString the C string to insert.
 ") InsertBefore;
 		void InsertBefore(const int theIndex, const char * const theCString);
@@ -1422,8 +1422,8 @@ -----------
 
 Description
 -----------
-Inserts a string_view before a specific index in this string. Raises an exception if index is out of bounds. 
-Input parameter: theIndex the index to insert before 
+Inserts a string_view before a specific index in this string. Raises an exception if index is out of bounds.
+Input parameter: theIndex the index to insert before
 Input parameter: theStringView the string view to insert.
 ") InsertBefore;
 		void InsertBefore(const int theIndex, const std::string_view & theStringView);
@@ -1437,7 +1437,7 @@ -----------
 
 Description
 -----------
-Converts a AsciiString containing a numeric expression to an Integer. //! Example: ```cpp TCollection_AsciiString aString('215'); int anInt = aString.IntegerValue(); // Result: anInt == 215 ``` 
+Converts a AsciiString containing a numeric expression to an Integer. //! Example: ```cpp TCollection_AsciiString aString('215'); int anInt = aString.IntegerValue(); // Result: anInt == 215 ```
 Return: the integer value of the string.
 ") IntegerValue;
 		int IntegerValue();
@@ -1451,7 +1451,7 @@ -----------
 
 Description
 -----------
-Returns True if the AsciiString contains only ASCII characters between ' ' and '~'. This means no control character and no extended ASCII code. 
+Returns True if the AsciiString contains only ASCII characters between ' ' and '~'. This means no control character and no extended ASCII code.
 Return: true if string contains only ASCII characters.
 ") IsAscii;
 		bool IsAscii();
@@ -1470,8 +1470,8 @@ -----------
 
 Description
 -----------
-Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator != 
-Input parameter: theOther the ASCII string to compare with 
+Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator !=
+Input parameter: theOther the ASCII string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(TCollection_AsciiString theOther);
@@ -1491,9 +1491,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns true if there are differences between this ASCII string and the string (pointer and length). This is the primary implementation that string_view and CString overloads redirect to. 
-Input parameter: theString pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns true if there are differences between this ASCII string and the string (pointer and length). This is the primary implementation that string_view and CString overloads redirect to.
+Input parameter: theString pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(const char * const theString, const int theLength);
@@ -1512,8 +1512,8 @@ -----------
 
 Description
 -----------
-Returns true if there are differences between this ASCII string and C string. 
-Input parameter: theCString the C string to compare with 
+Returns true if there are differences between this ASCII string and C string.
+Input parameter: theCString the C string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(const char * const theCString);
@@ -1532,8 +1532,8 @@ -----------
 
 Description
 -----------
-Returns true if there are differences between the characters in this ASCII string and string_view. 
-Input parameter: theStringView the string view to compare with 
+Returns true if there are differences between the characters in this ASCII string and string_view.
+Input parameter: theStringView the string view to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(const std::string_view & theStringView);
@@ -1565,8 +1565,8 @@ -----------
 
 Description
 -----------
-Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==. 
-Input parameter: theOther the ASCII string to compare with 
+Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==.
+Input parameter: theOther the ASCII string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(TCollection_AsciiString theOther);
@@ -1586,9 +1586,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns true if the characters in this ASCII string are identical to the string (pointer and length). This is the primary implementation that string_view and CString overloads redirect to. 
-Input parameter: theString pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns true if the characters in this ASCII string are identical to the string (pointer and length). This is the primary implementation that string_view and CString overloads redirect to.
+Input parameter: theString pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(const char * const theString, const int theLength);
@@ -1607,8 +1607,8 @@ -----------
 
 Description
 -----------
-Returns true if the characters in this ASCII string are identical to the C string. 
-Input parameter: theCString the C string to compare with 
+Returns true if the characters in this ASCII string are identical to the C string.
+Input parameter: theCString the C string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(const char * const theCString);
@@ -1627,8 +1627,8 @@ -----------
 
 Description
 -----------
-Returns true if the characters in this ASCII string are identical to the characters in string_view. 
-Input parameter: theStringView the string view to compare with 
+Returns true if the characters in this ASCII string are identical to the characters in string_view.
+Input parameter: theStringView the string view to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(const std::string_view & theStringView);
@@ -1648,9 +1648,9 @@ -----------
 
 Description
 -----------
-Returns True when the two strings are the same. (Just for HashCode for AsciiString) 
-Input parameter: string1 first string to compare 
-Input parameter: string2 second string to compare 
+Returns True when the two strings are the same. (Just for HashCode for AsciiString)
+Input parameter: string1 first string to compare
+Input parameter: string2 second string to compare
 Return: true if strings are equal.
 ") IsEqual;
 		static bool IsEqual(TCollection_AsciiString string1, TCollection_AsciiString string2);
@@ -1670,9 +1670,9 @@ -----------
 
 Description
 -----------
-Returns True when the ASCII string and string_view are the same. (Just for HashCode for AsciiString) 
-Input parameter: theString1 first string to compare 
-Input parameter: theStringView second string view to compare 
+Returns True when the ASCII string and string_view are the same. (Just for HashCode for AsciiString)
+Input parameter: theString1 first string to compare
+Input parameter: theStringView second string view to compare
 Return: true if strings are equal.
 ") IsEqual;
 		static bool IsEqual(TCollection_AsciiString theString1, const std::string_view & theStringView);
@@ -1692,9 +1692,9 @@ -----------
 
 Description
 -----------
-Returns True when the string_view and ASCII string are the same. (Just for HashCode for AsciiString) 
-Input parameter: theStringView first string view to compare 
-Input parameter: theString2 second string to compare 
+Returns True when the string_view and ASCII string are the same. (Just for HashCode for AsciiString)
+Input parameter: theStringView first string view to compare
+Input parameter: theString2 second string to compare
 Return: true if strings are equal.
 ") IsEqual;
 		static bool IsEqual(const std::string_view & theStringView, TCollection_AsciiString theString2);
@@ -1714,9 +1714,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns True if this string is lexicographically greater than the string (pointer and length). This is the primary implementation that all other IsGreater overloads redirect to. 
-Input parameter: theString pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns True if this string is lexicographically greater than the string (pointer and length). This is the primary implementation that all other IsGreater overloads redirect to.
+Input parameter: theString pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if this string is lexicographically greater than the given string.
 ") IsGreater;
 		bool IsGreater(const char * const theString, const int theLength);
@@ -1735,8 +1735,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is 'ASCII' greater than other. 
-Input parameter: theOther the ASCII string to compare with 
+Returns True if this string is 'ASCII' greater than other.
+Input parameter: theOther the ASCII string to compare with
 Return: true if this string is lexicographically greater than other.
 ") IsGreater;
 		bool IsGreater(TCollection_AsciiString theOther);
@@ -1755,8 +1755,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically greater than C string. 
-Input parameter: theCString the C string to compare with 
+Returns True if this string is lexicographically greater than C string.
+Input parameter: theCString the C string to compare with
 Return: true if this string is lexicographically greater than C string.
 ") IsGreater;
 		bool IsGreater(const char * const theCString);
@@ -1775,8 +1775,8 @@ -----------
 
 Description
 -----------
-Returns True if this ASCII string is lexicographically greater than theStringView. 
-Input parameter: theStringView the string view to compare with 
+Returns True if this ASCII string is lexicographically greater than theStringView.
+Input parameter: theStringView the string view to compare with
 Return: true if this string is lexicographically greater than theStringView.
 ") IsGreater;
 		bool IsGreater(const std::string_view & theStringView);
@@ -1790,7 +1790,7 @@ -----------
 
 Description
 -----------
-Returns True if the AsciiString contains an integer value. Note: an integer value is considered to be a real value as well. 
+Returns True if the AsciiString contains an integer value. Note: an integer value is considered to be a real value as well.
 Return: true if string represents an integer value.
 ") IsIntegerValue;
 		bool IsIntegerValue();
@@ -1810,9 +1810,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns True if this string is lexicographically less than the string (pointer and length). This is the primary implementation that all other IsLess overloads redirect to. 
-Input parameter: theString pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns True if this string is lexicographically less than the string (pointer and length). This is the primary implementation that all other IsLess overloads redirect to.
+Input parameter: theString pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if this string is lexicographically less than the given string.
 ") IsLess;
 		bool IsLess(const char * const theString, const int theLength);
@@ -1831,8 +1831,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is 'ASCII' less than other. 
-Input parameter: theOther the ASCII string to compare with 
+Returns True if this string is 'ASCII' less than other.
+Input parameter: theOther the ASCII string to compare with
 Return: true if this string is lexicographically less than other.
 ") IsLess;
 		bool IsLess(TCollection_AsciiString theOther);
@@ -1851,8 +1851,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically less than C string. 
-Input parameter: theCString the C string to compare with 
+Returns True if this string is lexicographically less than C string.
+Input parameter: theCString the C string to compare with
 Return: true if this string is lexicographically less than C string.
 ") IsLess;
 		bool IsLess(const char * const theCString);
@@ -1871,8 +1871,8 @@ -----------
 
 Description
 -----------
-Returns True if this ASCII string is lexicographically less than theStringView. 
-Input parameter: theStringView the string view to compare with 
+Returns True if this ASCII string is lexicographically less than theStringView.
+Input parameter: theStringView the string view to compare with
 Return: true if this string is lexicographically less than theStringView.
 ") IsLess;
 		bool IsLess(const std::string_view & theStringView);
@@ -1891,8 +1891,8 @@ -----------
 
 Description
 -----------
-Returns True if the AsciiString starts with some characters that can be interpreted as integer or real value. 
-Input parameter: theToCheckFull when True, checks if entire string defines a real value;  otherwise checks if string starts with a real value Note: an integer value is considered to be a real value as well. 
+Returns True if the AsciiString starts with some characters that can be interpreted as integer or real value.
+Input parameter: theToCheckFull when True, checks if entire string defines a real value;  otherwise checks if string starts with a real value Note: an integer value is considered to be a real value as well.
 Return: true if string represents a real value.
 ") IsRealValue;
 		bool IsRealValue(bool theToCheckFull = false);
@@ -1915,12 +1915,12 @@ -----------
 
 Description
 -----------
-Core implementation: Returns True if the two strings (pointer and length) contain same characters. This is the primary implementation that all other IsSameString overloads redirect to. 
-Input parameter: theString1 pointer to first string to compare 
-Input parameter: theLength1 length of first string 
-Input parameter: theString2 pointer to second string to compare 
-Input parameter: theLength2 length of second string 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Core implementation: Returns True if the two strings (pointer and length) contain same characters. This is the primary implementation that all other IsSameString overloads redirect to.
+Input parameter: theString1 pointer to first string to compare
+Input parameter: theLength1 length of first string
+Input parameter: theString2 pointer to second string to compare
+Input parameter: theLength2 length of second string
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(const char * const theString1, const int theLength1, const char * const theString2, const int theLength2, const bool theIsCaseSensitive);
@@ -1941,10 +1941,10 @@ -----------
 
 Description
 -----------
-Returns True if the strings contain same characters. 
-Input parameter: theString1 first string to compare 
-Input parameter: theString2 second string to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the strings contain same characters.
+Input parameter: theString1 first string to compare
+Input parameter: theString2 second string to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(TCollection_AsciiString theString1, TCollection_AsciiString theString2, const bool theIsCaseSensitive);
@@ -1965,10 +1965,10 @@ -----------
 
 Description
 -----------
-Returns True if the string and C string contain same characters. 
-Input parameter: theString1 first string to compare 
-Input parameter: theCString second C string to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the string and C string contain same characters.
+Input parameter: theString1 first string to compare
+Input parameter: theCString second C string to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(TCollection_AsciiString theString1, const char * const theCString, const bool theIsCaseSensitive);
@@ -1989,10 +1989,10 @@ -----------
 
 Description
 -----------
-Returns True if the C string and string contain same characters. 
-Input parameter: theCString first C string to compare 
-Input parameter: theString2 second string to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the C string and string contain same characters.
+Input parameter: theCString first C string to compare
+Input parameter: theString2 second string to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(const char * const theCString, TCollection_AsciiString theString2, const bool theIsCaseSensitive);
@@ -2013,10 +2013,10 @@ -----------
 
 Description
 -----------
-Returns True if the string and string_view contain same characters. 
-Input parameter: theString1 first string to compare 
-Input parameter: theStringView second string view to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the string and string_view contain same characters.
+Input parameter: theString1 first string to compare
+Input parameter: theStringView second string view to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(TCollection_AsciiString theString1, const std::string_view & theStringView, const bool theIsCaseSensitive);
@@ -2037,10 +2037,10 @@ -----------
 
 Description
 -----------
-Returns True if the string_view and string contain same characters. 
-Input parameter: theStringView first string view to compare 
-Input parameter: theString2 second string to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the string_view and string contain same characters.
+Input parameter: theStringView first string view to compare
+Input parameter: theString2 second string to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(const std::string_view & theStringView, TCollection_AsciiString theString2, const bool theIsCaseSensitive);
@@ -2061,10 +2061,10 @@ -----------
 
 Description
 -----------
-Returns True if the two C strings contain same characters. 
-Input parameter: theCString1 first C string to compare 
-Input parameter: theCString2 second C string to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the two C strings contain same characters.
+Input parameter: theCString1 first C string to compare
+Input parameter: theCString2 second C string to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(const char * const theCString1, const char * const theCString2, const bool theIsCaseSensitive);
@@ -2085,10 +2085,10 @@ -----------
 
 Description
 -----------
-Returns True if the two string_views contain same characters. 
-Input parameter: theStringView1 first string view to compare 
-Input parameter: theStringView2 second string view to compare 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity 
+Returns True if the two string_views contain same characters.
+Input parameter: theStringView1 first string view to compare
+Input parameter: theStringView2 second string view to compare
+Input parameter: theIsCaseSensitive flag indicating case sensitivity
 Return: true if strings contain same characters.
 ") IsSameString;
 		static bool IsSameString(const std::string_view & theStringView1, const std::string_view & theStringView2, const bool theIsCaseSensitive);
@@ -2121,8 +2121,8 @@ -----------
 
 Description
 -----------
-left justify Length becomes equal to Width and the new characters are equal to Filler. If Width < Length nothing happens. Raises an exception if Width is less than zero. //! Example: ```cpp TCollection_AsciiString aString('abcdef'); aString.LeftJustify(9, ' '); // Result: aString == 'abcdef ' ``` 
-Input parameter: theWidth the desired width 
+left justify Length becomes equal to Width and the new characters are equal to Filler. If Width < Length nothing happens. Raises an exception if Width is less than zero. //! Example: ```cpp TCollection_AsciiString aString('abcdef'); aString.LeftJustify(9, ' '); // Result: aString == 'abcdef ' ```
+Input parameter: theWidth the desired width
 Input parameter: theFiller the character to fill with.
 ") LeftJustify;
 		void LeftJustify(const int theWidth, const char theFiller);
@@ -2136,7 +2136,7 @@ -----------
 
 Description
 -----------
-Returns number of characters in this string. This is the same functionality as 'strlen' in C. //! Example: ```cpp TCollection_AsciiString anAlphabet('abcdef'); int aLength = anAlphabet.Length(); // Result: aLength == 6 ``` - 1 is the position of the first character in this string. - The length of this string gives the position of its last character. - Positions less than or equal to zero, or greater than the length of this string are invalid in functions which identify a character of this string by its position. 
+Returns number of characters in this string. This is the same functionality as 'strlen' in C. //! Example: ```cpp TCollection_AsciiString anAlphabet('abcdef'); int aLength = anAlphabet.Length(); // Result: aLength == 6 ``` - 1 is the position of the first character in this string. - The length of this string gives the position of its last character. - Positions less than or equal to zero, or greater than the length of this string are invalid in functions which identify a character of this string by its position.
 Return: the number of characters in the string.
 ") Length;
 		int Length();
@@ -2157,10 +2157,10 @@ -----------
 
 Description
 -----------
-Returns an index in this string of the first occurrence of the string S in this string from the starting index FromIndex to the ending index ToIndex returns zero if failure Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAaAa'); TCollection_AsciiString aSearchString('Aa'); int anIndex = aString.Location(aSearchString, 1, 7); // Result: anIndex == 4 ``` 
-Input parameter: theOther the string to search for 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns an index in this string of the first occurrence of the string S in this string from the starting index FromIndex to the ending index ToIndex returns zero if failure Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAaAa'); TCollection_AsciiString aSearchString('Aa'); int anIndex = aString.Location(aSearchString, 1, 7); // Result: anIndex == 4 ```
+Input parameter: theOther the string to search for
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of first occurrence, or 0 if not found.
 ") Location;
 		int Location(TCollection_AsciiString theOther, const int theFromIndex, const int theToIndex);
@@ -2182,11 +2182,11 @@ -----------
 
 Description
 -----------
-Returns the index of the nth occurrence of the character C in this string from the starting index FromIndex to the ending index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAa'); int anIndex = aString.Location(3, 'a', 1, 5); // Result: anIndex == 5 ``` 
-Input parameter: theN the occurrence number to find 
-Input parameter: theC the character to search for 
-Input parameter: theFromIndex the starting index for search 
-Input parameter: theToIndex the ending index for search 
+Returns the index of the nth occurrence of the character C in this string from the starting index FromIndex to the ending index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. //! Example: ```cpp TCollection_AsciiString aString('aabAa'); int anIndex = aString.Location(3, 'a', 1, 5); // Result: anIndex == 5 ```
+Input parameter: theN the occurrence number to find
+Input parameter: theC the character to search for
+Input parameter: theFromIndex the starting index for search
+Input parameter: theToIndex the ending index for search
 Return: the index of the nth occurrence, or 0 if not found.
 ") Location;
 		int Location(const int theN, const char theC, const int theFromIndex, const int theToIndex);
@@ -2218,7 +2218,7 @@ -----------
 
 Description
 -----------
-Inserts the string other at the beginning of this ASCII string. //! Example: ```cpp TCollection_AsciiString anAlphabet('cde'); TCollection_AsciiString aBegin('ab'); anAlphabet.Prepend(aBegin); // Result: anAlphabet == 'abcde' ``` 
+Inserts the string other at the beginning of this ASCII string. //! Example: ```cpp TCollection_AsciiString anAlphabet('cde'); TCollection_AsciiString aBegin('ab'); anAlphabet.Prepend(aBegin); // Result: anAlphabet == 'abcde' ```
 Input parameter: theOther the string to prepend.
 ") Prepend;
 		void Prepend(TCollection_AsciiString theOther);
@@ -2236,7 +2236,7 @@ -----------
 
 Description
 -----------
-Displays this string on a stream. 
+Displays this string on a stream.
 Input parameter: theStream the output stream.
 ") Print;
 		void Print(std::ostream &OutValue);
@@ -2255,7 +2255,7 @@ -----------
 
 Description
 -----------
-Read this string from a stream. 
+Read this string from a stream.
 Input parameter: theStream the input stream.
 ") Read;
 		void Read(std::istream & theStream);
@@ -2269,7 +2269,7 @@ -----------
 
 Description
 -----------
-Converts an AsciiString containing a numeric expression to a Real. //! Example: ```cpp TCollection_AsciiString aString1('215'); double aReal1 = aString1.RealValue(); // Result: aReal1 == 215.0 //! TCollection_AsciiString aString2('3.14159267'); double aReal2 = aString2.RealValue(); // Result: aReal2 == 3.14159267 ``` 
+Converts an AsciiString containing a numeric expression to a Real. //! Example: ```cpp TCollection_AsciiString aString1('215'); double aReal1 = aString1.RealValue(); // Result: aReal1 == 215.0 //! TCollection_AsciiString aString2('3.14159267'); double aReal2 = aString2.RealValue(); // Result: aReal2 == 3.14159267 ```
 Return: the real value of the string.
 ") RealValue;
 		double RealValue();
@@ -2289,8 +2289,8 @@ -----------
 
 Description
 -----------
-Erases ahowmany characters from position where, where included. //! Example: ```cpp TCollection_AsciiString aString('Hello'); aString.Remove(2, 2); // erases 2 characters from position 2 // Result: aString == 'Hlo' ``` 
-Input parameter: theWhere the position to start erasing from 
+Erases ahowmany characters from position where, where included. //! Example: ```cpp TCollection_AsciiString aString('Hello'); aString.Remove(2, 2); // erases 2 characters from position 2 // Result: aString == 'Hlo' ```
+Input parameter: theWhere the position to start erasing from
 Input parameter: theHowMany the number of characters to erase.
 ") Remove;
 		void Remove(const int theWhere, const int theHowMany = 1);
@@ -2310,8 +2310,8 @@ -----------
 
 Description
 -----------
-Remove all the occurrences of the character C in the string. //! Example: ```cpp TCollection_AsciiString aString('HellLLo'); aString.RemoveAll('L', true); // Result: aString == 'Hello' ``` 
-Input parameter: theC the character to remove 
+Remove all the occurrences of the character C in the string. //! Example: ```cpp TCollection_AsciiString aString('HellLLo'); aString.RemoveAll('L', true); // Result: aString == 'Hello' ```
+Input parameter: theC the character to remove
 Input parameter: theCaseSensitive flag indicating case sensitivity.
 ") RemoveAll;
 		void RemoveAll(const char theC, const bool theCaseSensitive);
@@ -2330,7 +2330,7 @@ -----------
 
 Description
 -----------
-Removes every what characters from this string. 
+Removes every what characters from this string.
 Input parameter: theWhat the character to remove.
 ") RemoveAll;
 		void RemoveAll(const char theWhat);
@@ -2363,8 +2363,8 @@ -----------
 
 Description
 -----------
-Right justify. Length becomes equal to Width and the new characters are equal to Filler. if Width < Length nothing happens. Raises an exception if Width is less than zero. //! Example: ```cpp TCollection_AsciiString aString('abcdef'); aString.RightJustify(9, ' '); // Result: aString == ' abcdef' ``` 
-Input parameter: theWidth the desired width 
+Right justify. Length becomes equal to Width and the new characters are equal to Filler. if Width < Length nothing happens. Raises an exception if Width is less than zero. //! Example: ```cpp TCollection_AsciiString aString('abcdef'); aString.RightJustify(9, ' '); // Result: aString == ' abcdef' ```
+Input parameter: theWidth the desired width
 Input parameter: theFiller the character to fill with.
 ") RightJustify;
 		void RightJustify(const int theWidth, const char theFiller);
@@ -2384,9 +2384,9 @@ -----------
 
 Description
 -----------
-Core implementation: Searches a string (pointer and length) in this string from the beginning and returns position of first item matching. It returns -1 if not found. 
-Input parameter: theWhat pointer to the string to search for 
-Input parameter: theWhatLength length of the string to search for 
+Core implementation: Searches a string (pointer and length) in this string from the beginning and returns position of first item matching. It returns -1 if not found.
+Input parameter: theWhat pointer to the string to search for
+Input parameter: theWhatLength length of the string to search for
 Return: the position of first match, or -1 if not found.
 ") Search;
 		int Search(const char * const theWhat, const int theWhatLength);
@@ -2405,8 +2405,8 @@ -----------
 
 Description
 -----------
-Searches an AsciiString in this string from the beginning and returns position of first item what matching. It returns -1 if not found. 
-Input parameter: theWhat the ASCII string to search for 
+Searches an AsciiString in this string from the beginning and returns position of first item what matching. It returns -1 if not found.
+Input parameter: theWhat the ASCII string to search for
 Return: the position of first match, or -1 if not found.
 ") Search;
 		int Search(TCollection_AsciiString theWhat);
@@ -2425,8 +2425,8 @@ -----------
 
 Description
 -----------
-Searches a C string in this string from the beginning. 
-Input parameter: theCString the C string to search for 
+Searches a C string in this string from the beginning.
+Input parameter: theCString the C string to search for
 Return: the position of first match, or -1 if not found.
 ") Search;
 		int Search(const char * const theCString);
@@ -2445,8 +2445,8 @@ -----------
 
 Description
 -----------
-Searches a string_view in this string from the beginning and returns position of first item matching. It returns -1 if not found. 
-Input parameter: theWhat the string view to search for 
+Searches a string_view in this string from the beginning and returns position of first item matching. It returns -1 if not found.
+Input parameter: theWhat the string view to search for
 Return: the position of first match, or -1 if not found.
 ") Search;
 		int Search(const std::string_view & theWhat);
@@ -2466,9 +2466,9 @@ -----------
 
 Description
 -----------
-Core implementation: Searches a string (pointer and length) in this string from the end and returns position of first item matching. It returns -1 if not found. 
-Input parameter: theWhat pointer to the string to search for 
-Input parameter: theWhatLength length of the string to search for 
+Core implementation: Searches a string (pointer and length) in this string from the end and returns position of first item matching. It returns -1 if not found.
+Input parameter: theWhat pointer to the string to search for
+Input parameter: theWhatLength length of the string to search for
 Return: the position of first match from end, or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(const char * const theWhat, const int theWhatLength);
@@ -2487,8 +2487,8 @@ -----------
 
 Description
 -----------
-Searches a AsciiString in another AsciiString from the end and returns position of first item what matching. It returns -1 if not found. 
-Input parameter: theWhat the ASCII string to search for 
+Searches a AsciiString in another AsciiString from the end and returns position of first item what matching. It returns -1 if not found.
+Input parameter: theWhat the ASCII string to search for
 Return: the position of first match from end, or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(TCollection_AsciiString theWhat);
@@ -2507,8 +2507,8 @@ -----------
 
 Description
 -----------
-Searches a C string in this string from the end. 
-Input parameter: theCString the C string to search for 
+Searches a C string in this string from the end.
+Input parameter: theCString the C string to search for
 Return: the position of first match from end, or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(const char * const theCString);
@@ -2527,8 +2527,8 @@ -----------
 
 Description
 -----------
-Searches a string_view in this string from the end and returns position of first item matching. It returns -1 if not found. 
-Input parameter: theWhat the string view to search for 
+Searches a string_view in this string from the end and returns position of first item matching. It returns -1 if not found.
+Input parameter: theWhat the string view to search for
 Return: the position of first match from end, or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(const std::string_view & theWhat);
@@ -2548,8 +2548,8 @@ -----------
 
 Description
 -----------
-Replaces one character in the AsciiString at position where. If where is less than zero or greater than the length of this string an exception is raised. //! Example: ```cpp TCollection_AsciiString aString('Garbake'); aString.SetValue(6, 'g'); // Result: aString == 'Garbage' ``` 
-Input parameter: theWhere the position to replace at 
+Replaces one character in the AsciiString at position where. If where is less than zero or greater than the length of this string an exception is raised. //! Example: ```cpp TCollection_AsciiString aString('Garbake'); aString.SetValue(6, 'g'); // Result: aString == 'Garbage' ```
+Input parameter: theWhere the position to replace at
 Input parameter: theWhat the character to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char theWhat);
@@ -2570,9 +2570,9 @@ -----------
 
 Description
 -----------
-Core implementation: Replaces a part of this string with a string (pointer and length). This is the primary implementation that all other SetValue string overloads redirect to. 
-Input parameter: theWhere position to start replacement 
-Input parameter: theString pointer to the string to replace with 
+Core implementation: Replaces a part of this string with a string (pointer and length). This is the primary implementation that all other SetValue string overloads redirect to.
+Input parameter: theWhere position to start replacement
+Input parameter: theString pointer to the string to replace with
 Input parameter: theLength length of the string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char * const theString, const int theLength);
@@ -2592,8 +2592,8 @@ -----------
 
 Description
 -----------
-Replaces a part of this string by another AsciiString. 
-Input parameter: theWhere the position to start replacement 
+Replaces a part of this string by another AsciiString.
+Input parameter: theWhere the position to start replacement
 Input parameter: theWhat the ASCII string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, TCollection_AsciiString theWhat);
@@ -2613,8 +2613,8 @@ -----------
 
 Description
 -----------
-Replaces a part of this ASCII string with a C string. 
-Input parameter: theWhere position to start replacement 
+Replaces a part of this ASCII string with a C string.
+Input parameter: theWhere position to start replacement
 Input parameter: theCString the C string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char * const theCString);
@@ -2634,8 +2634,8 @@ -----------
 
 Description
 -----------
-Replaces a part of this ASCII string with a string_view. 
-Input parameter: theWhere position to start replacement 
+Replaces a part of this ASCII string with a string_view.
+Input parameter: theWhere position to start replacement
 Input parameter: theStringView the string view to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const std::string_view & theStringView);
@@ -2654,8 +2654,8 @@ -----------
 
 Description
 -----------
-Splits a AsciiString into two sub-strings. //! Example: ```cpp TCollection_AsciiString aString('abcdefg'); TCollection_AsciiString aSecondPart = aString.Split(3); // Result: aString == 'abc' and aSecondPart == 'defg' ``` 
-Input parameter: theWhere the position to split at 
+Splits a AsciiString into two sub-strings. //! Example: ```cpp TCollection_AsciiString aString('abcdefg'); TCollection_AsciiString aSecondPart = aString.Split(3); // Result: aString == 'abc' and aSecondPart == 'defg' ```
+Input parameter: theWhere the position to split at
 Return: the second part of the split string.
 ") Split;
 		TCollection_AsciiString Split(const int theWhere);
@@ -2675,9 +2675,9 @@ -----------
 
 Description
 -----------
-Core implementation: Determines whether the beginning of this string instance matches the specified string (pointer and length). 
-Input parameter: theStartString pointer to the string to check for at the beginning 
-Input parameter: theStartLength length of the string to check for 
+Core implementation: Determines whether the beginning of this string instance matches the specified string (pointer and length).
+Input parameter: theStartString pointer to the string to check for at the beginning
+Input parameter: theStartLength length of the string to check for
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(const char * const theStartString, const int theStartLength);
@@ -2696,8 +2696,8 @@ -----------
 
 Description
 -----------
-Determines whether the beginning of this string instance matches the specified string. 
-Input parameter: theStartString the string to check for at the beginning 
+Determines whether the beginning of this string instance matches the specified string.
+Input parameter: theStartString the string to check for at the beginning
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(TCollection_AsciiString theStartString);
@@ -2716,8 +2716,8 @@ -----------
 
 Description
 -----------
-Determines whether the beginning of this string matches the specified C string. 
-Input parameter: theCString the C string to check for at the beginning 
+Determines whether the beginning of this string matches the specified C string.
+Input parameter: theCString the C string to check for at the beginning
 Return: true if this string starts with theCString.
 ") StartsWith;
 		bool StartsWith(const char * const theCString);
@@ -2736,8 +2736,8 @@ -----------
 
 Description
 -----------
-Determines whether the beginning of this string instance matches the specified string_view. 
-Input parameter: theStartString the string view to check for at the beginning 
+Determines whether the beginning of this string instance matches the specified string_view.
+Input parameter: theStartString the string view to check for at the beginning
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(const std::string_view & theStartString);
@@ -2757,9 +2757,9 @@ -----------
 
 Description
 -----------
-Creation of a sub-string of this string. The sub-string starts to the index Fromindex and ends to the index ToIndex. Raises an exception if ToIndex or FromIndex is out of bounds //! Example: ```cpp TCollection_AsciiString aString('abcdefg'); TCollection_AsciiString aSubString = aString.SubString(3, 6); // Result: aSubString == 'cdef' ``` 
-Input parameter: theFromIndex the starting index 
-Input parameter: theToIndex the ending index 
+Creation of a sub-string of this string. The sub-string starts to the index Fromindex and ends to the index ToIndex. Raises an exception if ToIndex or FromIndex is out of bounds //! Example: ```cpp TCollection_AsciiString aString('abcdefg'); TCollection_AsciiString aSubString = aString.SubString(3, 6); // Result: aSubString == 'cdef' ```
+Input parameter: theFromIndex the starting index
+Input parameter: theToIndex the ending index
 Return: the substring from FromIndex to ToIndex.
 ") SubString;
 		TCollection_AsciiString SubString(const int theFromIndex, const int theToIndex);
@@ -2791,7 +2791,7 @@ -----------
 
 Description
 -----------
-Returns pointer to AsciiString (char *). This is useful for some casual manipulations. Warning: Because this 'char *' is 'const', you can't modify its contents. 
+Returns pointer to AsciiString (char *). This is useful for some casual manipulations. Warning: Because this 'char *' is 'const', you can't modify its contents.
 Return: the C string representation.
 ") ToCString;
 		const char * ToCString();
@@ -2811,8 +2811,8 @@ -----------
 
 Description
 -----------
-Extracts whichone token from this string. By default, the separators is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). separators contains all separators you need. If no token indexed by whichone is found, it returns empty AsciiString. //! Example: ```cpp TCollection_AsciiString aString('This is a message'); TCollection_AsciiString aToken1 = aString.Token(); // Result: aToken1 == 'This' //! TCollection_AsciiString aToken2 = aString.Token(' ', 4); // Result: aToken2 == 'message' //! TCollection_AsciiString aToken3 = aString.Token(' ', 2); // Result: aToken3 == 'is' //! TCollection_AsciiString aToken4 = aString.Token(' ', 9); // Result: aToken4 == '' //! TCollection_AsciiString bString('1234; test:message , value'); TCollection_AsciiString bToken1 = bString.Token('; :,', 4); // Result: bToken1 == 'value' //! TCollection_AsciiString bToken2 = bString.Token('; :,', 2); // Result: bToken2 == 'test' ``` 
-Input parameter: theSeparators the separator characters 
+Extracts whichone token from this string. By default, the separators is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). separators contains all separators you need. If no token indexed by whichone is found, it returns empty AsciiString. //! Example: ```cpp TCollection_AsciiString aString('This is a message'); TCollection_AsciiString aToken1 = aString.Token(); // Result: aToken1 == 'This' //! TCollection_AsciiString aToken2 = aString.Token(' ', 4); // Result: aToken2 == 'message' //! TCollection_AsciiString aToken3 = aString.Token(' ', 2); // Result: aToken3 == 'is' //! TCollection_AsciiString aToken4 = aString.Token(' ', 9); // Result: aToken4 == '' //! TCollection_AsciiString bString('1234; test:message , value'); TCollection_AsciiString bToken1 = bString.Token('; :,', 4); // Result: bToken1 == 'value' //! TCollection_AsciiString bToken2 = bString.Token('; :,', 2); // Result: bToken2 == 'test' ```
+Input parameter: theSeparators the separator characters
 Input parameter: theWhichOne the token number to extract.
 ") Token;
 		TCollection_AsciiString Token(const char * const theSeparators = "\t", const int theWhichOne = 1);
@@ -2831,7 +2831,7 @@ -----------
 
 Description
 -----------
-Truncates this string to ahowmany characters. //! Example: ```cpp TCollection_AsciiString aString('Hello Dolly'); aString.Trunc(3); // Result: aString == 'Hel' ``` 
+Truncates this string to ahowmany characters. //! Example: ```cpp TCollection_AsciiString aString('Hello Dolly'); aString.Trunc(3); // Result: aString == 'Hel' ```
 Input parameter: theHowMany the number of characters to keep.
 ") Trunc;
 		void Trunc(const int theHowMany);
@@ -2858,7 +2858,7 @@ -----------
 
 Description
 -----------
-Length of the string ignoring all spaces (' ') and the control character at the end. 
+Length of the string ignoring all spaces (' ') and the control character at the end.
 Return: the useful length of the string.
 ") UsefullLength;
 		int UsefullLength();
@@ -2877,8 +2877,8 @@ -----------
 
 Description
 -----------
-Returns character at position where in this string. If where is less than zero or greater than the length of this string, an exception is raised. //! Example: ```cpp TCollection_AsciiString aString('Hello'); char aChar = aString.Value(2); // Result: aChar == 'e' ``` 
-Input parameter: theWhere the position to get character from 
+Returns character at position where in this string. If where is less than zero or greater than the length of this string, an exception is raised. //! Example: ```cpp TCollection_AsciiString aString('Hello'); char aChar = aString.Value(2); // Result: aChar == 'e' ```
+Input parameter: theWhere the position to get character from
 Return: the character at the specified position.
 ") Value;
 		char Value(const int theWhere);
@@ -3249,8 +3249,8 @@ -----------
 
 Description
 -----------
-Creation by converting a CString to an extended string. If theIsMultiByte is true then the string is treated as having UTF-8 coding. If it is not a UTF-8 then theIsMultiByte is ignored and each character is copied to ExtCharacter. 
-Input parameter: theString the C string to convert 
+Creation by converting a CString to an extended string. If theIsMultiByte is true then the string is treated as having UTF-8 coding. If it is not a UTF-8 then theIsMultiByte is ignored and each character is copied to ExtCharacter.
+Input parameter: theString the C string to convert
 Input parameter: theIsMultiByte flag indicating UTF-8 coding.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const char * const theString, const bool theIsMultiByte = false);
@@ -3269,7 +3269,7 @@ -----------
 
 Description
 -----------
-Creation by converting an ExtString (char16_t*) to an extended string. 
+Creation by converting an ExtString (char16_t*) to an extended string.
 Input parameter: theString the char16_t string to copy.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const char16_t * const theString);
@@ -3288,7 +3288,7 @@ -----------
 
 Description
 -----------
-Initialize from wide-char string considering it as Unicode string (the size of wide char is a platform-dependent - e.g. on Windows wchar_t is UTF-16). //! This constructor is unavailable if application is built with deprecated msvc option '-Zc:wchar_t-', since OCCT itself is never built with this option. 
+Initialize from wide-char string considering it as Unicode string (the size of wide char is a platform-dependent - e.g. on Windows wchar_t is UTF-16). //! This constructor is unavailable if application is built with deprecated msvc option '-Zc:wchar_t-', since OCCT itself is never built with this option.
 Input parameter: theStringUtf the wide character string to convert.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const wchar_t * theStringUtf);
@@ -3307,7 +3307,7 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with a single ASCII character. 
+Initializes an ExtendedString with a single ASCII character.
 Input parameter: theChar the ASCII character to initialize from.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const char theChar);
@@ -3326,7 +3326,7 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with a single extended character. 
+Initializes an ExtendedString with a single extended character.
 Input parameter: theChar the extended character to initialize from.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const char16_t theChar);
@@ -3346,8 +3346,8 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with specified length space allocated and filled with filler character. This is useful for buffers. 
-Input parameter: theLength the length to allocate 
+Initializes an ExtendedString with specified length space allocated and filled with filler character. This is useful for buffers.
+Input parameter: theLength the length to allocate
 Input parameter: theFiller the character to fill with.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const int theLength, const char16_t theFiller);
@@ -3366,7 +3366,7 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with an integer value. 
+Initializes an ExtendedString with an integer value.
 Input parameter: theValue the integer value to convert to string.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const int theValue);
@@ -3385,7 +3385,7 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with a real value. 
+Initializes an ExtendedString with a real value.
 Input parameter: theValue the real value to convert to string.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const double theValue);
@@ -3404,7 +3404,7 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with another ExtendedString. 
+Initializes an ExtendedString with another ExtendedString.
 Input parameter: theString the string to copy from.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(TCollection_ExtendedString theString);
@@ -3423,7 +3423,7 @@ -----------
 
 Description
 -----------
-Move constructor. 
+Move constructor.
 Input parameter: theOther the string to move from.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(TCollection_ExtendedString & theOther);
@@ -3443,8 +3443,8 @@ -----------
 
 Description
 -----------
-Creation by converting an AsciiString to an extended string. The string is treated as having UTF-8 coding. If it is not a UTF-8 or multi byte then each character is copied to ExtCharacter. 
-Input parameter: theString the ASCII string to convert 
+Creation by converting an AsciiString to an extended string. The string is treated as having UTF-8 coding. If it is not a UTF-8 or multi byte then each character is copied to ExtCharacter.
+Input parameter: theString the ASCII string to convert
 Input parameter: theIsMultiByte flag indicating UTF-8 coding.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(TCollection_AsciiString theString, const bool theIsMultiByte = true);
@@ -3464,8 +3464,8 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString with a char16_t string and explicit length. 
-Input parameter: theString the char16_t string to initialize from 
+Initializes an ExtendedString with a char16_t string and explicit length.
+Input parameter: theString the char16_t string to initialize from
 Input parameter: theLength the length of the string.
 ") TCollection_ExtendedString;
 		 TCollection_ExtendedString(const char16_t * const theString, const int theLength);
@@ -3484,10 +3484,14 @@ -----------
 
 Description
 -----------
-Initializes an ExtendedString from a std::u16string_view. 
+Initializes an ExtendedString from a std::u16string_view.
 Input parameter: theStringView the string view to copy.
 ") TCollection_ExtendedString;
-		 TCollection_ExtendedString(const std::u16string_view & theStringView);
+		// occt-800: the std::u16string_view ctor is inline and calls the private,
+		// non-exported allocate(), which breaks the Windows link (LNK2019). It is
+		// also unreachable from Python (no u16string_view typemap); str is built
+		// via the char16_t*/wchar_t* ctors. Skip it.
+		// TCollection_ExtendedString(const std::u16string_view & theStringView);
 
 		/****** TCollection_ExtendedString::u16string_view ******/
 		/****** md5 signature: 2c5272a7bc3d3e18c7d49843bb69015c ******/
@@ -3498,7 +3502,7 @@ -----------
 
 Description
 -----------
-Conversion to std::u16string_view. 
+Conversion to std::u16string_view.
 Return: a non-owning view of the string data.
 ") u16string_view;
 		 u16string_view();
@@ -3517,7 +3521,7 @@ -----------
 
 Description
 -----------
-Appends the other extended string to this extended string. Note that this method is an alias of operator +=. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); TCollection_ExtendedString anotherString(u' World'); aString += anotherString; // Result: aString == u'Hello World' ``` 
+Appends the other extended string to this extended string. Note that this method is an alias of operator +=. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); TCollection_ExtendedString anotherString(u' World'); aString += anotherString; // Result: aString == u'Hello World' ```
 Input parameter: theOther the string to append.
 ") AssignCat;
 		void AssignCat(TCollection_ExtendedString theOther);
@@ -3536,7 +3540,7 @@ -----------
 
 Description
 -----------
-Appends the integer value to this extended string. 
+Appends the integer value to this extended string.
 Input parameter: theOther the integer to append.
 ") AssignCat;
 		void AssignCat(const int theOther);
@@ -3555,7 +3559,7 @@ -----------
 
 Description
 -----------
-Appends the ASCII character to this extended string. 
+Appends the ASCII character to this extended string.
 Input parameter: theChar the character to append.
 ") AssignCat;
 		void AssignCat(const char theChar);
@@ -3574,7 +3578,7 @@ -----------
 
 Description
 -----------
-Appends the real value to this extended string. 
+Appends the real value to this extended string.
 Input parameter: theOther the real value to append.
 ") AssignCat;
 		void AssignCat(const double theOther);
@@ -3593,7 +3597,7 @@ -----------
 
 Description
 -----------
-Appends the utf16 char to this extended string. 
+Appends the utf16 char to this extended string.
 Input parameter: theChar the character to append.
 ") AssignCat;
 		void AssignCat(const char16_t theChar);
@@ -3613,8 +3617,8 @@ -----------
 
 Description
 -----------
-Core implementation: Appends char16_t string (pointer and length) to this extended string. This is the primary implementation that all other AssignCat overloads redirect to. 
-Input parameter: theString pointer to the string to append 
+Core implementation: Appends char16_t string (pointer and length) to this extended string. This is the primary implementation that all other AssignCat overloads redirect to.
+Input parameter: theString pointer to the string to append
 Input parameter: theLength length of the string to append.
 ") AssignCat;
 		void AssignCat(const char16_t * const theString, const int theLength);
@@ -3633,7 +3637,7 @@ -----------
 
 Description
 -----------
-Appends the char16_t string to this extended string. 
+Appends the char16_t string to this extended string.
 Input parameter: theString the string to append.
 ") AssignCat;
 		void AssignCat(const char16_t * const theString);
@@ -3652,10 +3656,12 @@ -----------
 
 Description
 -----------
-Appends the std::u16string_view to this extended string. 
+Appends the std::u16string_view to this extended string.
 Input parameter: theStringView the string view to append.
 ") AssignCat;
-		void AssignCat(const std::u16string_view & theStringView);
+		// occt-800: inline AssignCat(u16string_view) calls the private, non-exported
+		// reallocate() (Windows LNK2019); the char16_t* overload covers it. Skip it.
+		// void AssignCat(const std::u16string_view & theStringView);
 
 		/****** TCollection_ExtendedString::Capitalize ******/
 		/****** md5 signature: dbcb7ca2711d8c69ac14d5c2510a8e32 ******/
@@ -3685,9 +3691,9 @@ -----------
 
 Description
 -----------
-Core implementation: Concatenates char16_t string (pointer and length) and returns a new string. 
-Input parameter: theOther pointer to the string to append 
-Input parameter: theLength length of the string to append 
+Core implementation: Concatenates char16_t string (pointer and length) and returns a new string.
+Input parameter: theOther pointer to the string to append
+Input parameter: theLength length of the string to append
 Return: new string with theOther appended.
 ") Cat;
 		TCollection_ExtendedString Cat(const char16_t * const theOther, const int theLength);
@@ -3706,8 +3712,8 @@ -----------
 
 Description
 -----------
-Concatenates char16_t string and returns a new string. 
-Input parameter: theOther the null-terminated string to append 
+Concatenates char16_t string and returns a new string.
+Input parameter: theOther the null-terminated string to append
 Return: new string with theOther appended.
 ") Cat;
 		TCollection_ExtendedString Cat(const char16_t * const theOther);
@@ -3726,8 +3732,8 @@ -----------
 
 Description
 -----------
-Appends the integer value to this string and returns a new string. 
-Input parameter: theOther the integer to append 
+Appends the integer value to this string and returns a new string.
+Input parameter: theOther the integer to append
 Return: new string with integer appended.
 ") Cat;
 		TCollection_ExtendedString Cat(const int theOther);
@@ -3746,8 +3752,8 @@ -----------
 
 Description
 -----------
-Appends the real value to this string and returns a new string. 
-Input parameter: theOther the real value to append 
+Appends the real value to this string and returns a new string.
+Input parameter: theOther the real value to append
 Return: new string with real value appended.
 ") Cat;
 		TCollection_ExtendedString Cat(const double theOther);
@@ -3766,7 +3772,7 @@ -----------
 
 Description
 -----------
-Appends a single ASCII character to this string and returns a new string. 
+Appends a single ASCII character to this string and returns a new string.
 Input parameter: theChar the ASCII character to append.
 ") Cat;
 		TCollection_ExtendedString Cat(const char theChar);
@@ -3785,7 +3791,7 @@ -----------
 
 Description
 -----------
-Appends a single extended (char16_t) character to this string and returns a new string. 
+Appends a single extended (char16_t) character to this string and returns a new string.
 Input parameter: theChar the extended character to append.
 ") Cat;
 		TCollection_ExtendedString Cat(const char16_t theChar);
@@ -3804,8 +3810,8 @@ -----------
 
 Description
 -----------
-Appends the other extended string to this string and returns a new string. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); TCollection_ExtendedString anotherString(u' World'); TCollection_ExtendedString aResult = aString + anotherString; // Result: aResult == u'Hello World' ``` 
-Input parameter: theOther the string to append 
+Appends the other extended string to this string and returns a new string. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); TCollection_ExtendedString anotherString(u' World'); TCollection_ExtendedString aResult = aString + anotherString; // Result: aResult == u'Hello World' ```
+Input parameter: theOther the string to append
 Return: new string with theOther appended.
 ") Cat;
 		TCollection_ExtendedString Cat(TCollection_ExtendedString theOther);
@@ -3825,8 +3831,8 @@ -----------
 
 Description
 -----------
-Modifies this string so that its length becomes equal to theWidth and the new characters are equal to theFiller. New characters are added both at the beginning and at the end of this string. If theWidth is less than the length of this string, nothing happens. 
-Input parameter: theWidth the desired width of the string 
+Modifies this string so that its length becomes equal to theWidth and the new characters are equal to theFiller. New characters are added both at the beginning and at the end of this string. If theWidth is less than the length of this string, nothing happens.
+Input parameter: theWidth the desired width of the string
 Input parameter: theFiller the character to fill with.
 ") Center;
 		void Center(const int theWidth, const char16_t theFiller);
@@ -3846,8 +3852,8 @@ -----------
 
 Description
 -----------
-Substitutes all the characters equal to theChar by theNewChar in this ExtendedString. The substitution can be case sensitive. If you don't use default case sensitive, no matter whether theChar is uppercase or not. //! Example: ```cpp TCollection_ExtendedString aString(u'Histake'); aString.ChangeAll(u'H', u'M'); // Result: aString == u'Mistake' ``` 
-Input parameter: theChar the character to replace 
+Substitutes all the characters equal to theChar by theNewChar in this ExtendedString. The substitution can be case sensitive. If you don't use default case sensitive, no matter whether theChar is uppercase or not. //! Example: ```cpp TCollection_ExtendedString aString(u'Histake'); aString.ChangeAll(u'H', u'M'); // Result: aString == u'Mistake' ```
+Input parameter: theChar the character to replace
 Input parameter: theNewChar the replacement character.
 ") ChangeAll;
 		void ChangeAll(const char16_t theChar, const char16_t theNewChar);
@@ -3880,8 +3886,8 @@ -----------
 
 Description
 -----------
-Core implementation: Copy from a char16_t pointer with explicit length. 
-Input parameter: theString pointer to the string to copy 
+Core implementation: Copy from a char16_t pointer with explicit length.
+Input parameter: theString pointer to the string to copy
 Input parameter: theLength length of the string to copy.
 ") Copy;
 		void Copy(const char16_t * const theString, const int theLength);
@@ -3900,7 +3906,7 @@ -----------
 
 Description
 -----------
-Copy from a char16_t pointer. 
+Copy from a char16_t pointer.
 Input parameter: theString the null-terminated string to copy.
 ") Copy;
 		void Copy(const char16_t * const theString);
@@ -3919,7 +3925,7 @@ -----------
 
 Description
 -----------
-Copy theFromWhere to this string. Used as operator = //! Example: ```cpp TCollection_ExtendedString aString; TCollection_ExtendedString anotherString(u'Hello World'); aString = anotherString; // operator= // Result: aString == u'Hello World' ``` 
+Copy theFromWhere to this string. Used as operator = //! Example: ```cpp TCollection_ExtendedString aString; TCollection_ExtendedString anotherString(u'Hello World'); aString = anotherString; // operator= // Result: aString == u'Hello World' ```
 Input parameter: theFromWhere the string to copy from.
 ") Copy;
 		void Copy(TCollection_ExtendedString theFromWhere);
@@ -3933,7 +3939,7 @@ -----------
 
 Description
 -----------
-Returns a const reference to a single shared empty string instance. This method provides access to a static empty string to avoid creating temporary empty strings. Use this method instead of constructing empty strings when you need a const reference. //! Example: ```cpp const TCollection_ExtendedString& anEmptyStr = TCollection_ExtendedString::EmptyString(); // Use anEmptyStr instead of TCollection_ExtendedString() ``` 
+Returns a const reference to a single shared empty string instance. This method provides access to a static empty string to avoid creating temporary empty strings. Use this method instead of constructing empty strings when you need a const reference. //! Example: ```cpp const TCollection_ExtendedString& anEmptyStr = TCollection_ExtendedString::EmptyString(); // Use anEmptyStr instead of TCollection_ExtendedString() ```
 Return: const reference to static empty string.
 ") EmptyString;
 		static const TCollection_ExtendedString & EmptyString();
@@ -3953,9 +3959,9 @@ -----------
 
 Description
 -----------
-Core implementation: Determines whether this string ends with theEndString. 
-Input parameter: theEndString pointer to the string to check for 
-Input parameter: theLength length of the string to check for 
+Core implementation: Determines whether this string ends with theEndString.
+Input parameter: theEndString pointer to the string to check for
+Input parameter: theLength length of the string to check for
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(const char16_t * const theEndString, const int theLength);
@@ -3974,8 +3980,8 @@ -----------
 
 Description
 -----------
-Determines whether this string ends with theEndString. 
-Input parameter: theEndString the null-terminated string to check for 
+Determines whether this string ends with theEndString.
+Input parameter: theEndString the null-terminated string to check for
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(const char16_t * const theEndString);
@@ -3994,8 +4000,8 @@ -----------
 
 Description
 -----------
-Determines whether the end of this string instance matches the specified string. 
-Input parameter: theEndString the string to check for at the end 
+Determines whether the end of this string instance matches the specified string.
+Input parameter: theEndString the string to check for at the end
 Return: true if this string ends with theEndString.
 ") EndsWith;
 		bool EndsWith(TCollection_ExtendedString theEndString);
@@ -4016,10 +4022,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is present in theSet. The search begins at index theFromIndex and ends at index theToIndex. Returns zero if failure. 
-Input parameter: theSet the set of characters to search for 
-Input parameter: theFromIndex the starting index for search (1-based) 
-Input parameter: theToIndex the ending index for search (1-based) 
+Returns the index of the first character of this string that is present in theSet. The search begins at index theFromIndex and ends at index theToIndex. Returns zero if failure.
+Input parameter: theSet the set of characters to search for
+Input parameter: theFromIndex the starting index for search (1-based)
+Input parameter: theToIndex the ending index for search (1-based)
 Return: the index of first character found in set, or 0 if not found.
 ") FirstLocationInSet;
 		int FirstLocationInSet(TCollection_ExtendedString theSet, const int theFromIndex, const int theToIndex);
@@ -4040,10 +4046,10 @@ -----------
 
 Description
 -----------
-Returns the index of the first character of this string that is NOT present in theSet. The search begins at index theFromIndex and ends at index theToIndex. Returns zero if failure. 
-Input parameter: theSet the set of characters to check against 
-Input parameter: theFromIndex the starting index for search (1-based) 
-Input parameter: theToIndex the ending index for search (1-based) 
+Returns the index of the first character of this string that is NOT present in theSet. The search begins at index theFromIndex and ends at index theToIndex. Returns zero if failure.
+Input parameter: theSet the set of characters to check against
+Input parameter: theFromIndex the starting index for search (1-based)
+Input parameter: theToIndex the ending index for search (1-based)
 Return: the index of first character not in set, or 0 if not found.
 ") FirstLocationNotInSet;
 		int FirstLocationNotInSet(TCollection_ExtendedString theSet, const int theFromIndex, const int theToIndex);
@@ -4057,7 +4063,7 @@ -----------
 
 Description
 -----------
-Returns a hashed value for the extended string. Note: if string is ASCII, the computed value is the same as the value computed with the HashCode function on a TCollection_AsciiString string composed with equivalent ASCII characters. 
+Returns a hashed value for the extended string. Note: if string is ASCII, the computed value is the same as the value computed with the HashCode function on a TCollection_AsciiString string composed with equivalent ASCII characters.
 Return: a computed hash code.
 ") HashCode;
 		size_t HashCode();
@@ -4077,8 +4083,8 @@ -----------
 
 Description
 -----------
-Insert a Character at position theWhere. //! Example: ```cpp TCollection_ExtendedString aString(u'hy not ?'); aString.Insert(1, u'W'); // Result: aString == u'Why not ?' ``` 
-Input parameter: theWhere the position to insert at (1-based) 
+Insert a Character at position theWhere. //! Example: ```cpp TCollection_ExtendedString aString(u'hy not ?'); aString.Insert(1, u'W'); // Result: aString == u'Why not ?' ```
+Input parameter: theWhere the position to insert at (1-based)
 Input parameter: theWhat the character to insert.
 ") Insert;
 		void Insert(const int theWhere, const char16_t theWhat);
@@ -4099,9 +4105,9 @@ -----------
 
 Description
 -----------
-Core implementation: Insert a char16_t string (pointer and length) at position theWhere. 
-Input parameter: theWhere the position to insert at (1-based) 
-Input parameter: theWhat pointer to the string to insert 
+Core implementation: Insert a char16_t string (pointer and length) at position theWhere.
+Input parameter: theWhere the position to insert at (1-based)
+Input parameter: theWhat pointer to the string to insert
 Input parameter: theLength length of the string to insert.
 ") Insert;
 		void Insert(const int theWhere, const char16_t * const theWhat, const int theLength);
@@ -4121,8 +4127,8 @@ -----------
 
 Description
 -----------
-Insert a char16_t string at position theWhere. 
-Input parameter: theWhere the position to insert at (1-based) 
+Insert a char16_t string at position theWhere.
+Input parameter: theWhere the position to insert at (1-based)
 Input parameter: theWhat the null-terminated string to insert.
 ") Insert;
 		void Insert(const int theWhere, const char16_t * const theWhat);
@@ -4142,8 +4148,8 @@ -----------
 
 Description
 -----------
-Insert an ExtendedString at position theWhere. 
-Input parameter: theWhere the position to insert at (1-based) 
+Insert an ExtendedString at position theWhere.
+Input parameter: theWhere the position to insert at (1-based)
 Input parameter: theWhat the string to insert.
 ") Insert;
 		void Insert(const int theWhere, TCollection_ExtendedString theWhat);
@@ -4157,7 +4163,7 @@ -----------
 
 Description
 -----------
-Converts this extended string containing a numeric expression to an Integer. 
+Converts this extended string containing a numeric expression to an Integer.
 Return: the integer value.
 ") IntegerValue;
 		int IntegerValue();
@@ -4171,7 +4177,7 @@ -----------
 
 Description
 -----------
-Returns True if the ExtendedString contains only 'Ascii Range' characters. 
+Returns True if the ExtendedString contains only 'Ascii Range' characters.
 Return: true if string contains only ASCII characters.
 ") IsAscii;
 		bool IsAscii();
@@ -4191,9 +4197,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns true if this string differs from theOther (pointer and length). 
-Input parameter: theOther pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns true if this string differs from theOther (pointer and length).
+Input parameter: theOther pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(const char16_t * const theOther, const int theLength);
@@ -4212,8 +4218,8 @@ -----------
 
 Description
 -----------
-Returns true if this string differs from theOther null-terminated string. Note that this method is an alias of operator !=. 
-Input parameter: theOther the char16_t string to compare with 
+Returns true if this string differs from theOther null-terminated string. Note that this method is an alias of operator !=.
+Input parameter: theOther the char16_t string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(const char16_t * const theOther);
@@ -4232,8 +4238,8 @@ -----------
 
 Description
 -----------
-Returns true if there are differences between the characters in this extended string and theOther extended string. Note that this method is an alias of operator !=. 
-Input parameter: theOther the extended string to compare with 
+Returns true if there are differences between the characters in this extended string and theOther extended string. Note that this method is an alias of operator !=.
+Input parameter: theOther the extended string to compare with
 Return: true if strings are different, false otherwise.
 ") IsDifferent;
 		bool IsDifferent(TCollection_ExtendedString theOther);
@@ -4266,9 +4272,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns true if this string equals theOther (pointer and length). 
-Input parameter: theOther pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns true if this string equals theOther (pointer and length).
+Input parameter: theOther pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(const char16_t * const theOther, const int theLength);
@@ -4287,8 +4293,8 @@ -----------
 
 Description
 -----------
-Returns true if this string equals theOther null-terminated string. Note that this method is an alias of operator ==. 
-Input parameter: theOther the char16_t string to compare with 
+Returns true if this string equals theOther null-terminated string. Note that this method is an alias of operator ==.
+Input parameter: theOther the char16_t string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(const char16_t * const theOther);
@@ -4307,8 +4313,8 @@ -----------
 
 Description
 -----------
-Returns true if the characters in this extended string are identical to the characters in theOther extended string. Note that this method is an alias of operator ==. 
-Input parameter: theOther the extended string to compare with 
+Returns true if the characters in this extended string are identical to the characters in theOther extended string. Note that this method is an alias of operator ==.
+Input parameter: theOther the extended string to compare with
 Return: true if strings are equal, false otherwise.
 ") IsEqual;
 		bool IsEqual(TCollection_ExtendedString theOther);
@@ -4328,9 +4334,9 @@ -----------
 
 Description
 -----------
-Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==. 
-Input parameter: theString1 first string to compare 
-Input parameter: theString2 second string to compare 
+Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==.
+Input parameter: theString1 first string to compare
+Input parameter: theString2 second string to compare
 Return: true if strings are equal.
 ") IsEqual;
 		static bool IsEqual(TCollection_ExtendedString theString1, TCollection_ExtendedString theString2);
@@ -4350,9 +4356,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns True if this string is lexicographically greater than theOther. 
-Input parameter: theOther pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns True if this string is lexicographically greater than theOther.
+Input parameter: theOther pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if this string is greater than theOther.
 ") IsGreater;
 		bool IsGreater(const char16_t * const theOther, const int theLength);
@@ -4371,8 +4377,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically greater than theOther. 
-Input parameter: theOther the char16_t string to compare with 
+Returns True if this string is lexicographically greater than theOther.
+Input parameter: theOther the char16_t string to compare with
 Return: true if this string is greater than theOther.
 ") IsGreater;
 		bool IsGreater(const char16_t * const theOther);
@@ -4391,8 +4397,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically greater than theOther. 
-Input parameter: theOther the extended string to compare with 
+Returns True if this string is lexicographically greater than theOther.
+Input parameter: theOther the extended string to compare with
 Return: true if this string is greater than theOther.
 ") IsGreater;
 		bool IsGreater(TCollection_ExtendedString theOther);
@@ -4406,7 +4412,7 @@ -----------
 
 Description
 -----------
-Returns True if this extended string contains an integer value. 
+Returns True if this extended string contains an integer value.
 Return: true if string represents an integer value.
 ") IsIntegerValue;
 		bool IsIntegerValue();
@@ -4426,9 +4432,9 @@ -----------
 
 Description
 -----------
-Core implementation: Returns True if this string is lexicographically less than theOther. 
-Input parameter: theOther pointer to the string to compare with 
-Input parameter: theLength length of the string to compare with 
+Core implementation: Returns True if this string is lexicographically less than theOther.
+Input parameter: theOther pointer to the string to compare with
+Input parameter: theLength length of the string to compare with
 Return: true if this string is less than theOther.
 ") IsLess;
 		bool IsLess(const char16_t * const theOther, const int theLength);
@@ -4447,8 +4453,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically less than theOther. 
-Input parameter: theOther the char16_t string to compare with 
+Returns True if this string is lexicographically less than theOther.
+Input parameter: theOther the char16_t string to compare with
 Return: true if this string is less than theOther.
 ") IsLess;
 		bool IsLess(const char16_t * const theOther);
@@ -4467,8 +4473,8 @@ -----------
 
 Description
 -----------
-Returns True if this string is lexicographically less than theOther. 
-Input parameter: theOther the extended string to compare with 
+Returns True if this string is lexicographically less than theOther.
+Input parameter: theOther the extended string to compare with
 Return: true if this string is less than theOther.
 ") IsLess;
 		bool IsLess(TCollection_ExtendedString theOther);
@@ -4487,8 +4493,8 @@ -----------
 
 Description
 -----------
-Returns True if this extended string starts with characters that can be interpreted as a real value. 
-Input parameter: theToCheckFull when True, checks if entire string defines a real value;  otherwise checks if string starts with a real value 
+Returns True if this extended string starts with characters that can be interpreted as a real value.
+Input parameter: theToCheckFull when True, checks if entire string defines a real value;  otherwise checks if string starts with a real value
 Return: true if string represents a real value.
 ") IsRealValue;
 		bool IsRealValue(bool theToCheckFull = false);
@@ -4508,9 +4514,9 @@ -----------
 
 Description
 -----------
-Returns True if the strings contain same characters. 
-Input parameter: theOther the string to compare with 
-Input parameter: theIsCaseSensitive flag indicating case sensitivity @note When case-insensitive, only ASCII characters (a-z, A-Z) are affected. 
+Returns True if the strings contain same characters.
+Input parameter: theOther the string to compare with
+Input parameter: theIsCaseSensitive flag indicating case sensitivity @note When case-insensitive, only ASCII characters (a-z, A-Z) are affected.
 Return: true if strings contain same characters.
 ") IsSameString;
 		bool IsSameString(TCollection_ExtendedString theOther, const bool theIsCaseSensitive);
@@ -4543,8 +4549,8 @@ -----------
 
 Description
 -----------
-Left justify. Length becomes equal to theWidth and the new characters are equal to theFiller. If theWidth < Length nothing happens. 
-Input parameter: theWidth the desired width of the string 
+Left justify. Length becomes equal to theWidth and the new characters are equal to theFiller. If theWidth < Length nothing happens.
+Input parameter: theWidth the desired width of the string
 Input parameter: theFiller the character to fill with.
 ") LeftJustify;
 		void LeftJustify(const int theWidth, const char16_t theFiller);
@@ -4558,7 +4564,7 @@ -----------
 
 Description
 -----------
-Returns the number of 16-bit code units (might be greater than number of Unicode symbols if string contains surrogate pairs). 
+Returns the number of 16-bit code units (might be greater than number of Unicode symbols if string contains surrogate pairs).
 Return: the number of 16-bit code units.
 ") Length;
 		int Length();
@@ -4572,7 +4578,7 @@ -----------
 
 Description
 -----------
-Returns expected CString length in UTF8 coding (like strlen, without null terminator). It can be used for memory calculation before converting to CString containing symbols in UTF8 coding. For external allocation, use: char* buf = new char[str.LengthOfCString() + 1]; 
+Returns expected CString length in UTF8 coding (like strlen, without null terminator). It can be used for memory calculation before converting to CString containing symbols in UTF8 coding. For external allocation, use: char* buf = new char[str.LengthOfCString() + 1];
 Return: expected UTF-8 string length.
 ") LengthOfCString;
 		int LengthOfCString();
@@ -4592,8 +4598,8 @@ -----------
 
 Description
 -----------
-Core implementation: Inserts char16_t string (pointer and length) at the beginning. 
-Input parameter: theOther pointer to the string to prepend 
+Core implementation: Inserts char16_t string (pointer and length) at the beginning.
+Input parameter: theOther pointer to the string to prepend
 Input parameter: theLength length of the string to prepend.
 ") Prepend;
 		void Prepend(const char16_t * const theOther, const int theLength);
@@ -4612,7 +4618,7 @@ -----------
 
 Description
 -----------
-Inserts a null-terminated char16_t string at the beginning. 
+Inserts a null-terminated char16_t string at the beginning.
 Input parameter: theOther the null-terminated string to prepend.
 ") Prepend;
 		void Prepend(const char16_t * const theOther);
@@ -4631,7 +4637,7 @@ -----------
 
 Description
 -----------
-Inserts the other extended string at the beginning of this string. 
+Inserts the other extended string at the beginning of this string.
 Input parameter: theOther the string to prepend.
 ") Prepend;
 		void Prepend(TCollection_ExtendedString theOther);
@@ -4649,7 +4655,7 @@ -----------
 
 Description
 -----------
-Displays this string on a stream. 
+Displays this string on a stream.
 Input parameter: theStream the output stream.
 ") Print;
 		void Print(std::ostream &OutValue);
@@ -4663,7 +4669,7 @@ -----------
 
 Description
 -----------
-Converts this extended string containing a numeric expression to a Real. 
+Converts this extended string containing a numeric expression to a Real.
 Return: the real value.
 ") RealValue;
 		double RealValue();
@@ -4683,8 +4689,8 @@ -----------
 
 Description
 -----------
-Erases theHowMany characters from position theWhere, theWhere included. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); aString.Remove(2, 2); // erases 2 characters from position 2 // Result: aString == u'Hlo' ``` 
-Input parameter: theWhere the position to start erasing from (1-based) 
+Erases theHowMany characters from position theWhere, theWhere included. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); aString.Remove(2, 2); // erases 2 characters from position 2 // Result: aString == u'Hlo' ```
+Input parameter: theWhere the position to start erasing from (1-based)
 Input parameter: theHowMany the number of characters to erase.
 ") Remove;
 		void Remove(const int theWhere, const int theHowMany = 1);
@@ -4703,7 +4709,7 @@ -----------
 
 Description
 -----------
-Removes every theWhat characters from this string. 
+Removes every theWhat characters from this string.
 Input parameter: theWhat the character to remove.
 ") RemoveAll;
 		void RemoveAll(const char16_t theWhat);
@@ -4736,8 +4742,8 @@ -----------
 
 Description
 -----------
-Right justify. Length becomes equal to theWidth and the new characters are equal to theFiller. If theWidth < Length nothing happens. 
-Input parameter: theWidth the desired width of the string 
+Right justify. Length becomes equal to theWidth and the new characters are equal to theFiller. If theWidth < Length nothing happens.
+Input parameter: theWidth the desired width of the string
 Input parameter: theFiller the character to fill with.
 ") RightJustify;
 		void RightJustify(const int theWidth, const char16_t theFiller);
@@ -4757,9 +4763,9 @@ -----------
 
 Description
 -----------
-Core implementation: Searches for theWhat (pointer and length) from the beginning. 
-Input parameter: theWhat pointer to the string to search for 
-Input parameter: theLength length of the string to search for 
+Core implementation: Searches for theWhat (pointer and length) from the beginning.
+Input parameter: theWhat pointer to the string to search for
+Input parameter: theLength length of the string to search for
 Return: the position of first match (1-based), or -1 if not found.
 ") Search;
 		int Search(const char16_t * const theWhat, const int theLength);
@@ -4778,8 +4784,8 @@ -----------
 
 Description
 -----------
-Searches for theWhat null-terminated string from the beginning. 
-Input parameter: theWhat the null-terminated string to search for 
+Searches for theWhat null-terminated string from the beginning.
+Input parameter: theWhat the null-terminated string to search for
 Return: the position of first match (1-based), or -1 if not found.
 ") Search;
 		int Search(const char16_t * const theWhat);
@@ -4798,8 +4804,8 @@ -----------
 
 Description
 -----------
-Searches an ExtendedString in this string from the beginning and returns position of first item theWhat matching. It returns -1 if not found. 
-Input parameter: theWhat the string to search for 
+Searches an ExtendedString in this string from the beginning and returns position of first item theWhat matching. It returns -1 if not found.
+Input parameter: theWhat the string to search for
 Return: the position of first match (1-based), or -1 if not found.
 ") Search;
 		int Search(TCollection_ExtendedString theWhat);
@@ -4819,9 +4825,9 @@ -----------
 
 Description
 -----------
-Core implementation: Searches for theWhat (pointer and length) from the end. 
-Input parameter: theWhat pointer to the string to search for 
-Input parameter: theLength length of the string to search for 
+Core implementation: Searches for theWhat (pointer and length) from the end.
+Input parameter: theWhat pointer to the string to search for
+Input parameter: theLength length of the string to search for
 Return: the position of first match from end (1-based), or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(const char16_t * const theWhat, const int theLength);
@@ -4840,8 +4846,8 @@ -----------
 
 Description
 -----------
-Searches for theWhat null-terminated string from the end. 
-Input parameter: theWhat the null-terminated string to search for 
+Searches for theWhat null-terminated string from the end.
+Input parameter: theWhat the null-terminated string to search for
 Return: the position of first match from end (1-based), or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(const char16_t * const theWhat);
@@ -4860,8 +4866,8 @@ -----------
 
 Description
 -----------
-Searches an ExtendedString in this string from the end and returns position of first item theWhat matching. It returns -1 if not found. 
-Input parameter: theWhat the string to search for 
+Searches an ExtendedString in this string from the end and returns position of first item theWhat matching. It returns -1 if not found.
+Input parameter: theWhat the string to search for
 Return: the position of first match from end (1-based), or -1 if not found.
 ") SearchFromEnd;
 		int SearchFromEnd(TCollection_ExtendedString theWhat);
@@ -4881,8 +4887,8 @@ -----------
 
 Description
 -----------
-Replaces one character in the ExtendedString at position theWhere. If theWhere is less than zero or greater than the length of this string an exception is raised. //! Example: ```cpp TCollection_ExtendedString aString(u'Garbake'); aString.SetValue(6, u'g'); // Result: aString == u'Garbage' ``` 
-Input parameter: theWhere the position to replace at (1-based) 
+Replaces one character in the ExtendedString at position theWhere. If theWhere is less than zero or greater than the length of this string an exception is raised. //! Example: ```cpp TCollection_ExtendedString aString(u'Garbake'); aString.SetValue(6, u'g'); // Result: aString == u'Garbage' ```
+Input parameter: theWhere the position to replace at (1-based)
 Input parameter: theWhat the character to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char16_t theWhat);
@@ -4903,9 +4909,9 @@ -----------
 
 Description
 -----------
-Core implementation: Replaces a part of this string by char16_t string (pointer and length). 
-Input parameter: theWhere the position to start replacement (1-based) 
-Input parameter: theWhat pointer to the string to replace with 
+Core implementation: Replaces a part of this string by char16_t string (pointer and length).
+Input parameter: theWhere the position to start replacement (1-based)
+Input parameter: theWhat pointer to the string to replace with
 Input parameter: theLength length of the string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char16_t * const theWhat, const int theLength);
@@ -4925,8 +4931,8 @@ -----------
 
 Description
 -----------
-Replaces a part of this string by a null-terminated char16_t string. 
-Input parameter: theWhere the position to start replacement (1-based) 
+Replaces a part of this string by a null-terminated char16_t string.
+Input parameter: theWhere the position to start replacement (1-based)
 Input parameter: theWhat the null-terminated string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, const char16_t * const theWhat);
@@ -4946,8 +4952,8 @@ -----------
 
 Description
 -----------
-Replaces a part of this string by another ExtendedString. 
-Input parameter: theWhere the position to start replacement (1-based) 
+Replaces a part of this string by another ExtendedString.
+Input parameter: theWhere the position to start replacement (1-based)
 Input parameter: theWhat the string to replace with.
 ") SetValue;
 		void SetValue(const int theWhere, TCollection_ExtendedString theWhat);
@@ -4966,8 +4972,8 @@ -----------
 
 Description
 -----------
-Splits this extended string into two sub-strings at position theWhere. - The second sub-string (from position theWhere + 1 of this string to the end) is returned in a new extended string. - This extended string is modified: its last characters are removed, it becomes equal to the first sub-string (from the first character to position theWhere). //! Example: ```cpp TCollection_ExtendedString aString(u'abcdefg'); TCollection_ExtendedString aSecondPart = aString.Split(3); // Result: aString == u'abc' and aSecondPart == u'defg' ``` 
-Input parameter: theWhere the position to split at (0-based) 
+Splits this extended string into two sub-strings at position theWhere. - The second sub-string (from position theWhere + 1 of this string to the end) is returned in a new extended string. - This extended string is modified: its last characters are removed, it becomes equal to the first sub-string (from the first character to position theWhere). //! Example: ```cpp TCollection_ExtendedString aString(u'abcdefg'); TCollection_ExtendedString aSecondPart = aString.Split(3); // Result: aString == u'abc' and aSecondPart == u'defg' ```
+Input parameter: theWhere the position to split at (0-based)
 Return: the second part of the split string.
 ") Split;
 		TCollection_ExtendedString Split(const int theWhere);
@@ -4987,9 +4993,9 @@ -----------
 
 Description
 -----------
-Core implementation: Determines whether this string starts with theStartString. 
-Input parameter: theStartString pointer to the string to check for 
-Input parameter: theLength length of the string to check for 
+Core implementation: Determines whether this string starts with theStartString.
+Input parameter: theStartString pointer to the string to check for
+Input parameter: theLength length of the string to check for
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(const char16_t * const theStartString, const int theLength);
@@ -5008,8 +5014,8 @@ -----------
 
 Description
 -----------
-Determines whether this string starts with theStartString. 
-Input parameter: theStartString the null-terminated string to check for 
+Determines whether this string starts with theStartString.
+Input parameter: theStartString the null-terminated string to check for
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(const char16_t * const theStartString);
@@ -5028,8 +5034,8 @@ -----------
 
 Description
 -----------
-Determines whether the beginning of this string instance matches the specified string. 
-Input parameter: theStartString the string to check for at the beginning 
+Determines whether the beginning of this string instance matches the specified string.
+Input parameter: theStartString the string to check for at the beginning
 Return: true if this string starts with theStartString.
 ") StartsWith;
 		bool StartsWith(TCollection_ExtendedString theStartString);
@@ -5049,9 +5055,9 @@ -----------
 
 Description
 -----------
-Copies characters from this string starting from index theFromIndex to the index theToIndex (inclusive). Raises an exception if theToIndex or theFromIndex is out of bounds. //! Example: ```cpp TCollection_ExtendedString aString(u'abcdefg'); TCollection_ExtendedString aSubString = aString.SubString(3, 6); // Result: aSubString == u'cdef' ``` 
-Input parameter: theFromIndex the starting index (1-based) 
-Input parameter: theToIndex the ending index (1-based, inclusive) 
+Copies characters from this string starting from index theFromIndex to the index theToIndex (inclusive). Raises an exception if theToIndex or theFromIndex is out of bounds. //! Example: ```cpp TCollection_ExtendedString aString(u'abcdefg'); TCollection_ExtendedString aSubString = aString.SubString(3, 6); // Result: aSubString == u'cdef' ```
+Input parameter: theFromIndex the starting index (1-based)
+Input parameter: theToIndex the ending index (1-based, inclusive)
 Return: the substring from theFromIndex to theToIndex.
 ") SubString;
 		TCollection_ExtendedString SubString(const int theFromIndex, const int theToIndex);
@@ -5083,7 +5089,7 @@ -----------
 
 Description
 -----------
-Returns pointer to ExtString (char16_t*). 
+Returns pointer to ExtString (char16_t*).
 Return: the char16_t string representation.
 ") ToExtString;
 		const char16_t * ToExtString();
@@ -5102,7 +5108,7 @@ -----------
 
 Description
 -----------
-Converts the internal myString to UTF8 coding and returns length of the out CString. A memory for the theCString should be allocated before call! @param[in,out] theCString pointer to the output buffer 
+Converts the internal myString to UTF8 coding and returns length of the out CString. A memory for the theCString should be allocated before call! @param[in,out] theCString pointer to the output buffer
 Return: length of the UTF-8 string.
 ") ToUTF8CString;
 		int ToUTF8CString(Standard_PCharacter & theCString);
@@ -5122,9 +5128,9 @@ -----------
 
 Description
 -----------
-Extracts theWhichOne token from this string. By default, the theSeparators is set to space and tabulation. By default, the token extracted is the first one (theWhichOne = 1). theSeparators contains all separators you need. If no token indexed by theWhichOne is found, it returns an empty ExtendedString. //! Example: ```cpp TCollection_ExtendedString aString(u'This is a message'); TCollection_ExtendedString aToken1 = aString.Token(); // Result: aToken1 == u'This' //! TCollection_ExtendedString aToken2 = aString.Token(u' ', 4); // Result: aToken2 == u'message' //! TCollection_ExtendedString aToken3 = aString.Token(u' ', 2); // Result: aToken3 == u'is' //! TCollection_ExtendedString aToken4 = aString.Token(u' ', 9); // Result: aToken4 == u'' //! TCollection_ExtendedString bString(u'1234; test:message , value'); TCollection_ExtendedString bToken1 = bString.Token(u'; :,', 4); // Result: bToken1 == u'value' ``` 
-Input parameter: theSeparators the separator characters 
-Input parameter: theWhichOne the token number to extract (1-based) 
+Extracts theWhichOne token from this string. By default, the theSeparators is set to space and tabulation. By default, the token extracted is the first one (theWhichOne = 1). theSeparators contains all separators you need. If no token indexed by theWhichOne is found, it returns an empty ExtendedString. //! Example: ```cpp TCollection_ExtendedString aString(u'This is a message'); TCollection_ExtendedString aToken1 = aString.Token(); // Result: aToken1 == u'This' //! TCollection_ExtendedString aToken2 = aString.Token(u' ', 4); // Result: aToken2 == u'message' //! TCollection_ExtendedString aToken3 = aString.Token(u' ', 2); // Result: aToken3 == u'is' //! TCollection_ExtendedString aToken4 = aString.Token(u' ', 9); // Result: aToken4 == u'' //! TCollection_ExtendedString bString(u'1234; test:message , value'); TCollection_ExtendedString bToken1 = bString.Token(u'; :,', 4); // Result: bToken1 == u'value' ```
+Input parameter: theSeparators the separator characters
+Input parameter: theWhichOne the token number to extract (1-based)
 Return: the extracted token.
 ") Token;
 		TCollection_ExtendedString Token(const char16_t * const theSeparators, const int theWhichOne = 1);
@@ -5143,7 +5149,7 @@ -----------
 
 Description
 -----------
-Truncates this string to theHowMany characters. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello Dolly'); aString.Trunc(3); // Result: aString == u'Hel' ``` 
+Truncates this string to theHowMany characters. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello Dolly'); aString.Trunc(3); // Result: aString == u'Hel' ```
 Input parameter: theHowMany the number of characters to keep.
 ") Trunc;
 		void Trunc(const int theHowMany);
@@ -5162,8 +5168,8 @@ -----------
 
 Description
 -----------
-Returns character at position theWhere in this string. If theWhere is less than zero or greater than the length of this string, an exception is raised. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); char16_t aChar = aString.Value(2); // Result: aChar == u'e' ``` 
-Input parameter: theWhere the position to get character from (1-based) 
+Returns character at position theWhere in this string. If theWhere is less than zero or greater than the length of this string, an exception is raised. //! Example: ```cpp TCollection_ExtendedString aString(u'Hello'); char16_t aChar = aString.Value(2); // Result: aChar == u'e' ```
+Input parameter: theWhere the position to get character from (1-based)
 Return: the character at the specified position.
 ") Value;
 		char16_t Value(const int theWhere);
@@ -5362,7 +5368,9 @@ def __iadd__(self, right):
 
 %extend{
     void __iadd_wrapper__(const std::u16string_view other) {
-    *self += other;
+    // occt-800: avoid operator+=(u16string_view) -> inline reallocate (Windows LNK2019);
+    // use the Standard_EXPORT AssignCat(char16_t*, int) overload instead.
+    self->AssignCat(other.data(), static_cast<int>(other.size()));
     }
 }
 %pythoncode {
