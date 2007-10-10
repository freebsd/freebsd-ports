--- work/snowxml/template.php	Tue Nov  7 19:56:05 2006
+++ template.php	Wed Oct  3 10:35:35 2007
@@ -71,7 +71,11 @@
 			</ul>
 		</div>
 		
-		<?php include('pluxml/plugins/skinswitcher_form.php'); ?>
+		<?php 
+		if(file_exists('pluxml/plugins/skinswitcher_form.php')) {
+		include('pluxml/plugins/skinswitcher_form.php');
+		}
+		?>
 		
 	</div>
 	
