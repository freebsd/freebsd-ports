--- modules/overrides/GLib.js.orig	2011-12-15 16:10:34.000000000 +0100
+++ modules/overrides/GLib.js	2011-12-15 16:23:47.000000000 +0100
@@ -25,27 +25,27 @@ let originalVariantClass;
 const SIMPLE_TYPES = ['b', 'y', 'n', 'q', 'i', 'u', 'x', 't', 'h', 'd', 's', 'o', 'g'];
 
 function _read_single_type(signature, forceSimple) {
-    let char = signature.shift();
+    let xchar = signature.shift();
     let isSimple = false;
 
-    if (SIMPLE_TYPES.indexOf(char) == -1) {
+    if (SIMPLE_TYPES.indexOf(xchar) == -1) {
 	if (forceSimple)
 	    throw new TypeError('Invalid GVariant signature (a simple type was expected)');
     } else
 	isSimple = true;
 
-    if (char == 'm' || char == 'a')
-	return [char].concat(_read_single_type(signature, false));
-    if (char == '{') {
+    if (xchar == 'm' || xchar == 'a')
+	return [xchar].concat(_read_single_type(signature, false));
+    if (xchar == '{') {
 	let key = _read_single_type(signature, true);
 	let val = _read_single_type(signature, false);
 	let close = signature.shift();
 	if (close != '}')
 	    throw new TypeError('Invalid GVariant signature for type DICT_ENTRY (expected "}"');
-	return [char].concat(key, val, close);
+	return [xchar].concat(key, val, close);
     }
-    if (char == '(') {
-	let res = [char];
+    if (xchar == '(') {
+	let res = [xchar];
 	while (true) {
 	    if (signature.length == 0)
 		throw new TypeError('Invalid GVariant signature for type TUPLE (expected ")")');
@@ -60,10 +60,10 @@ function _read_single_type(signature, fo
     }
 
     // Valid types are simple types, arrays, maybes, tuples, dictionary entries and variants
-    if (!isSimple && char != 'v')
-	throw new TypeError('Invalid GVariant signature (' + char + ' is not a valid type)');
+    if (!isSimple && xchar != 'v')
+	throw new TypeError('Invalid GVariant signature (' + xchar + ' is not a valid type)');
 
-    return [char];
+    return [xchar];
 }
 
 
@@ -71,8 +71,8 @@ function _pack_variant(signature, value)
     if (signature.length == 0)
 	    throw new TypeError('GVariant signature cannot be empty');
 
-    let char = signature.shift();
-    switch (char) {
+    let xchar = signature.shift();
+    switch (xchar) {
     case 'b':
 	return GLib.Variant.new_boolean(value);
     case 'y':
@@ -160,7 +160,7 @@ function _pack_variant(signature, value)
 
 	return GLib.Variant.new_dict_entry(key, child);
     default:
-	throw new TypeError('Invalid GVariant signature (unexpected character ' + char + ')');
+	throw new TypeError('Invalid GVariant signature (unexpected character ' + xchar + ')');
     }
 }
 
@@ -258,4 +258,4 @@ function _init() {
     this.Variant.prototype.toString = function() {
 	return '[object variant of type "' + this.get_type_string() + '"]';
     }
-}
\ No newline at end of file
+}
