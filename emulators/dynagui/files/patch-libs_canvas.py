--- libs/canvas.py.orig	2007-09-24 21:33:03 UTC
+++ libs/canvas.py
@@ -25,19 +25,19 @@ import gtk
 import time
 from gtk import gdk
 import dynamips_lib
-from libs.lab import lab, Connection
-from libs.util import setup_ghost
-from libs.gui_c3600 import GuiC3600
-from libs.gui_c7200 import GuiC7200
-from libs.gui_router import GuiRouter
-from libs.gui_frsw import GuiFRSwitch
-from libs.gui_atmsw import GuiATMSwitch
-from libs.gui_ethsw import GuiEthSwitch
-from libs.C3600_properties_dialog import C3600PropertiesDialog
-from libs.C7200_properties_dialog import C7200PropertiesDialog
-from libs.frsw_properties_dialog import FRSwitchPropertiesDialog
-from libs.atmsw_properties_dialog import ATMSwitchPropertiesDialog
-from libs.ethsw_properties_dialog import EthSwitchPropertiesDialog
+from dynagui_libs.lab import lab, Connection
+from dynagui_libs.util import setup_ghost
+from dynagui_libs.gui_c3600 import GuiC3600
+from dynagui_libs.gui_c7200 import GuiC7200
+from dynagui_libs.gui_router import GuiRouter
+from dynagui_libs.gui_frsw import GuiFRSwitch
+from dynagui_libs.gui_atmsw import GuiATMSwitch
+from dynagui_libs.gui_ethsw import GuiEthSwitch
+from dynagui_libs.C3600_properties_dialog import C3600PropertiesDialog
+from dynagui_libs.C7200_properties_dialog import C7200PropertiesDialog
+from dynagui_libs.frsw_properties_dialog import FRSwitchPropertiesDialog
+from dynagui_libs.atmsw_properties_dialog import ATMSwitchPropertiesDialog
+from dynagui_libs.ethsw_properties_dialog import EthSwitchPropertiesDialog
 
 term = 'xterm'          # linux terminal
 win_telnet = "telnet "  # windows terminal
