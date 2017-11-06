--- dynagui.py.orig	2007-12-13 21:04:43 UTC
+++ dynagui.py
@@ -27,17 +27,17 @@ import sys
 import pygtk; pygtk.require('2.0')
 import gtk
 import gobject
-from libs.canvas import MyCanvas
-from libs import lab_io
-from libs.lab import lab
-from libs.gui_router import GuiRouter
-from libs.dynamips_properties_dialog import DynamipsPropertiesDialog
-from libs.C3600_properties_dialog import C3600PropertiesDialog
-from libs.C7200_properties_dialog import C7200PropertiesDialog
-from libs.frsw_properties_dialog import FRSwitchPropertiesDialog
-from libs.atmsw_properties_dialog import ATMSwitchPropertiesDialog
-from libs.ethsw_properties_dialog import EthSwitchPropertiesDialog
-from libs.util import RouterSelectionDialog
+from dynagui_libs.canvas import MyCanvas
+from dynagui_libs import lab_io
+from dynagui_libs.lab import lab
+from dynagui_libs.gui_router import GuiRouter
+from dynagui_libs.dynamips_properties_dialog import DynamipsPropertiesDialog
+from dynagui_libs.C3600_properties_dialog import C3600PropertiesDialog
+from dynagui_libs.C7200_properties_dialog import C7200PropertiesDialog
+from dynagui_libs.frsw_properties_dialog import FRSwitchPropertiesDialog
+from dynagui_libs.atmsw_properties_dialog import ATMSwitchPropertiesDialog
+from dynagui_libs.ethsw_properties_dialog import EthSwitchPropertiesDialog
+from dynagui_libs.util import RouterSelectionDialog
 
 
 ui_popup = \
@@ -509,7 +509,7 @@ class DynaguiFrame(gtk.Window):
         if len(lab.devices)>0:
             text = 'Select routers from which to extract configuration'
             rcd = RouterSelectionDialog(lab.devices, text, show_path=True)
-            from libs.nvram_io import read_conf_b64gz
+            from dynagui_libs.nvram_io import read_conf_b64gz
             for d in rcd.selected_devices:
                 cgz64 = d.config_gz64
                 conf = read_conf_b64gz(cgz64)
