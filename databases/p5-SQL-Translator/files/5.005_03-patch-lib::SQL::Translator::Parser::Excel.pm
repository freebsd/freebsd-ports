--- lib/SQL/Translator/Parser/Excel.pm.orig	Sun May  9 14:49:45 2004
+++ lib/SQL/Translator/Parser/Excel.pm	Sun May  9 14:50:21 2004
@@ -183,9 +183,9 @@
                     $size = [ $size->[0] + $size->[1] ];
                 }
 
-                my $field = $table->get_field( $field );
-                $field->size( $size ) if $size;
-                $field->data_type( $data_type );
+                my $f = $table->get_field( $field );
+                $f->size( $size ) if $size;
+                $f->data_type( $data_type );
             }
         }
     }
