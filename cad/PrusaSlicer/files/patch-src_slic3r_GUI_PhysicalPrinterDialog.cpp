--- src/slic3r/GUI/PhysicalPrinterDialog.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/PhysicalPrinterDialog.cpp
@@ -467,7 +467,7 @@ void PhysicalPrinterDialog::build_printhost_settings(C
     // Always fill in the "printhost_port" combo box from the config and select it.
     {
         Choice* choice = dynamic_cast<Choice*>(m_optgroup->get_field("printhost_port"));
-        choice->set_values({ m_config->opt_string("printhost_port") });
+        choice->set_values((const std::vector<std::string>){ m_config->opt_string("printhost_port") });
         choice->set_selection();
     }
 
