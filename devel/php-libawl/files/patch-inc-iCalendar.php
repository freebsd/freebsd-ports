--- inc/iCalendar.php.old	2011-02-28 14:10:05.863011862 +0100
+++ inc/iCalendar.php	2011-02-28 14:10:54.276562796 +0100
@@ -233,7 +233,7 @@
   function RenderParameters() {
     $rendered = "";
     foreach( $this->parameters AS $k => $v ) {
-      $escaped = preg_replace( "/([;:\"])/", '\\\\$1', $v);
+      $escaped = preg_replace( "/([;:])/", '\\\\$1', $v);
       $rendered .= sprintf( ";%s=%s", $k, $escaped );
     }
     return $rendered;
@@ -273,7 +273,7 @@
       default:
         $escaped = str_replace( '\\', '\\\\', $escaped);
         $escaped = preg_replace( '/\r?\n/', '\\n', $escaped);
-        $escaped = preg_replace( "/([,;\"])/", '\\\\$1', $escaped);
+        $escaped = preg_replace( "/([,;])/", '\\\\$1', $escaped);
     }
     $property = sprintf( "%s%s:", $this->name, $this->RenderParameters() );
     if ( (strlen($property) + strlen($escaped)) <= 72 ) {
@@ -786,7 +786,7 @@
   */
   function CloneConfidential() {
     $confidential = clone($this);
-    $keep_properties = array( 'DTSTAMP', 'DTSTART', 'RRULE', 'DURATION', 'DTEND', 'UID', 'CLASS', 'TRANSP' );
+    $keep_properties = array( 'DTSTAMP', 'DTSTART', 'RRULE', 'DURATION', 'DTEND', 'DUE', 'UID', 'CLASS', 'TRANSP', 'CREATED', 'LAST-MODIFIED' );
     $resource_components = array( 'VEVENT', 'VTODO', 'VJOURNAL' );
     $confidential->MaskComponents(array( 'VTIMEZONE', 'VEVENT', 'VTODO', 'VJOURNAL' ));
     $confidential->MaskProperties($keep_properties, $resource_components );
@@ -822,6 +822,7 @@
     foreach( $this->components AS $v ) {   $rendered .= $v->Render();  }
     $rendered .= "END:$this->type\r\n";
 
+    $rendered = preg_replace('{(?<!\r)\n}', '\r\n', $rendered);
     if ( $unrestricted ) $this->rendered = $rendered;
 
     return $rendered;
