--- lib/SQL/Translator/Parser/xSV.pm.orig	Sun May  9 21:39:20 2004
+++ lib/SQL/Translator/Parser/xSV.pm	Sun May  9 21:39:50 2004
@@ -174,9 +174,9 @@
                 $size = [ $size->[0] + $size->[1] ];
             }
 
-            my $field = $table->get_field( $field );
-            $field->size( $size );
-            $field->data_type( $data_type );
+            my $f = $table->get_field( $field );
+            $f->size( $size );
+            $f->data_type( $data_type );
         }
     }
 
