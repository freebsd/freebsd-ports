--- add_zone_master.php.orig	2011-05-30 12:33:42.399768001 +0300
+++ add_zone_master.php	2011-05-30 12:34:41.423768002 +0300
@@ -36,7 +36,10 @@
 if (isset($_POST['domain'])) {
         $temp = array();
         foreach ($_POST['domain'] as $domain) {
-          $temp[] = trim($domain);
+                if($domain != "")
+                {
+                        $temp[] = trim($domain);
+                }
         }
 	$domains = $temp;
 } else {
@@ -56,6 +59,7 @@
 (verify_permission('user_view_others')) ? $perm_view_others = "1" : $perm_view_others = "0" ; 
 
 if (isset($_POST['submit']) && $zone_master_add == "1" ) {
+        $error = false;
         foreach ($domains as $domain) {
                 if (domain_exists($domain)) {
                         error($domain . " failed - " . ERR_DOMAIN_EXISTS);
@@ -63,7 +67,6 @@
                         $error = true;
                 } elseif (add_domain($domain, $owner, $dom_type, '', $zone_template)) {
                         success("<a href=\"edit.php?id=" . get_zone_id_from_name($domain) . "\">".$domain . " - " . SUC_ZONE_ADD.'</a>');
-                        $error = false;
                 }
         }
 
@@ -139,7 +142,7 @@
 	echo "       <tr>\n";
 	echo "        <td class=\"n\">&nbsp;</td>\n";
 	echo "        <td class=\"n\">\n";
-	echo "         <input type=\"submit\" class=\"button\" name=\"submit\" value=\"" . _('Add zone') . "\">\n";
+        echo "         <input type=\"submit\" class=\"button\" name=\"submit\" value=\"" . _('Add zone') . "\" onclick=\"checkDomainFilled();return false;\">\n";
 	echo "        </td>\n";
 	echo "        <td class=\"n\">&nbsp;</td>\n";
 	echo "       </tr>\n";
