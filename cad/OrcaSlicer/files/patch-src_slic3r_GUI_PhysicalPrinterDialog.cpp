--- src/slic3r/GUI/PhysicalPrinterDialog.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/PhysicalPrinterDialog.cpp
@@ -430,7 +430,7 @@ void PhysicalPrinterDialog::build_printhost_settings(C
     // Always fill in the "printhost_port" combo box from the config and select it.
     {
         Choice* choice = dynamic_cast<Choice*>(m_optgroup->get_field("printhost_port"));
-        choice->set_values({ m_config->opt_string("printhost_port") });
+        choice->set_values(std::vector<std::string>{ m_config->opt_string("printhost_port") });
         choice->set_selection();
     }
 
