--- inc/vComponent.php.old	2010-12-01 04:18:52.000000000 +0100
+++ inc/vComponent.php	2011-02-28 14:11:24.757189028 +0100
@@ -203,7 +203,7 @@
   function RenderParameters() {
     $rendered = "";
     foreach( $this->parameters AS $k => $v ) {
-      $escaped = preg_replace( "/([;:\"])/", '\\\\$1', $v);
+      $escaped = preg_replace( "/([;:])/", '\\\\$1', $v);
       $rendered .= sprintf( ";%s=%s", $k, $escaped );
     }
     return $rendered;
@@ -235,7 +235,7 @@
       default:
         $escaped = str_replace( '\\', '\\\\', $escaped);
         $escaped = preg_replace( '/\r?\n/', '\\n', $escaped);
-        $escaped = preg_replace( "/([,;\"])/", '\\\\$1', $escaped);
+        $escaped = preg_replace( "/([,;])/", '\\\\$1', $escaped);
     }
 
     $property = sprintf( "%s%s:", $this->name, $this->RenderParameters() );
@@ -800,6 +800,7 @@
     foreach( $this->components AS $v ) {   $rendered .= $v->Render();  }
     $rendered .= "END:$this->type\r\n";
 
+    $rendered = preg_replace('{(?<!\r)\n}', '\r\n', $rendered);
     if ( $unrestricted ) $this->rendered = $rendered;
 
     return $rendered;
