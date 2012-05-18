--- edit.php.orig	2011-05-30 13:41:59.411768002 +0300
+++ edit.php	2011-05-30 12:59:05.851768002 +0300
@@ -51,9 +51,15 @@
 }
 
 if (isset($_POST['save_as'])) {
+	if (zone_templ_name_exists($_POST['templ_name'])) {
+		error(ERR_ZONE_TEMPL_EXIST);
+	} elseif ($_POST['templ_name'] == '') {
+		error(ERR_ZONE_TEMPL_IS_EMPTY);
+	} else {
+		success(SUC_ZONE_TEMPL_ADD);
         $records = get_records_from_domain_id($zone_id);
-        add_zone_templ_save_as($_POST['templ_name'], $_POST['templ_descr'], $_SESSION['userid'], $records);
-
+        add_zone_templ_save_as($_POST['templ_name'], $_POST['templ_descr'], $_SESSION['userid'], $records, get_zone_name_from_id($zone_id));
+	}
 }
 
 /*
