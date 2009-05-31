--- contrib/admin.php.orig	2009-01-30 12:21:32.000000000 +0000
+++ contrib/admin.php	2009-05-27 03:13:57.000000000 +0000
@@ -85,6 +85,15 @@
 */
 $auto_update_ptr = 0;
 
+/*
+**  This can automatically insert the defaults w/o updating the serial
+**  number automatically.  Sometimes you want to change entries but not
+**  have the nameserver reload and start serving out new data.
+**  -bek@monsterous.com
+*/
+
+$auto_defaults = 1;
+
 
 /*
 **  If this option is nonzero, this script will not complain if the
@@ -2052,7 +2061,7 @@
   global $soa_use_active, $soa_use_recursive, $soa_use_xfer, $soa_use_update_acl, $soa_use_also_notify;
   global $rr_table_name, $soa_active_types, $soa_recursive_types;
   global $default_refresh, $default_retry, $default_expire, $default_minimum_ttl, $default_ttl;
-  global $default_ns, $default_mbox;
+  global $default_ns, $default_mbox, $auto_defaults;
   global $soa_bgcolor, $zonenotify;
 
   $delete_confirm = 0;
@@ -2112,6 +2121,18 @@
     } else
       $soa = $values = $_POST;
     $new_soa = 1;
+
+       if ($auto_defaults == 1) {
+                        $soa['serial'] = date("Ymd01", time());
+                        $soa['refresh'] = $default_refresh;
+                        $soa['retry'] = $default_retry;
+                        $soa['expire'] = $default_expire;
+                        $soa['minimum'] = $default_minimum_ttl;
+                        $soa['ttl'] = $default_ttl;
+                        $soa['ns'] = trim($default_ns);
+                        $soa['mbox'] = trim($default_mbox);
+                        $values = $soa;
+                        }
   }
 
   /* Set 'values' vars to avoid 'undefined' errors */
@@ -2166,8 +2187,9 @@
 	<TR title="The serial number for this zone.">
 		<TD class="soaFields"><INPUT class=mono type=text name="serial" value="<?php echo ent($values['serial'])?>" size=20>
 		<TD>&nbsp;
-		<TD nowrap><TT>; <B>Serial</B> (next is <?php echo next_serial(isset($soa['serial']) ? $soa['serial'] : '');?>)</TT>
-		<TD>&nbsp;
+		<TD nowrap><TT>; <B>Serial</B> (next is <?=next_serial(isset($soa['serial']) ? $soa['serial'] : '');?>)</TT>
+		<TD><input name="updateserial" class=formButton style="border-color: #FFFF99; color: #FFFF99;" type="button" value="Update Serial"onclick="javascript:document.soaform.serial.value
+			=<?=next_serial(isset($soa['serial']) ? $soa['serial'] : '');?>">&nbsp;
 
 	<TR title="The number of seconds slave nameservers will wait before updating their zone data for this zone.">
 		<TD class=soaFields><INPUT class=mono type=text name="refresh" value="<?php echo ent($values['refresh'])?>" size=10>
