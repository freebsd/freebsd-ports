
$FreeBSD$

--- Slim/Utils/Accessor.pm.orig
+++ Slim/Utils/Accessor.pm
@@ -98,9 +98,15 @@
 		if ($type eq 'rw') {
 			
 			if ( hasXS() ) {
-				Class::XSAccessor::Array::_generate_method(
-					$class,	$field,	$n, 0, 0, 'accessor',
-				);
+				if ($Class::XSAccessor::Array::VERSION ge '1.05') {
+					Class::XSAccessor::Array::_generate_method(
+						$class,	$field,	$n, {}, 'accessor',
+					);
+				} else {
+					Class::XSAccessor::Array::_generate_method(
+						$class,	$field,	$n, 0, 0, 'accessor',
+					);
+				}
 			}
 			else {
 				$accessor = sub {
@@ -112,9 +118,15 @@
 		} elsif ($type eq 'ro') {
 			
 			if ( hasXS() ) {
-				Class::XSAccessor::Array::_generate_method(
-					$class,	$field,	$n, 0, 0, 'getter',
-				);
+				if ($Class::XSAccessor::Array::VERSION ge '1.05') {
+					Class::XSAccessor::Array::_generate_method(
+						$class,	$field,	$n, {}, 'getter',
+					);
+				} else {
+					Class::XSAccessor::Array::_generate_method(
+						$class,	$field,	$n, 0, 0, 'getter',
+					);
+				}
 			}
 			else {
 				$accessor = sub {
