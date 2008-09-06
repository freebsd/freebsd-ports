--- plugins/org.eclipse.pde.api.tools.ui/src/org/eclipse/pde/api/tools/ui/internal/wizards/ApiProfileWizardPage.java.orig	2008-08-02 10:08:15.000000000 -0400
+++ plugins/org.eclipse.pde.api.tools.ui/src/org/eclipse/pde/api/tools/ui/internal/wizards/ApiProfileWizardPage.java	2008-08-02 10:08:23.000000000 -0400
@@ -309,7 +309,7 @@
 		}
 		Collections.sort(items, new Comparator() {
 			public int compare(Object o1, Object o2) {
-				return ((String)o1).compareTo(o2);
+				return ((String)o1).compareTo((String)o2);
 			}
 		});		
 				
