--- plugins/org.eclipse.pde.api.tools/src_ant/org/eclipse/pde/api/tools/internal/tasks/APIToolsVerificationTask.java.orig	2008-08-02 23:44:38.060798145 -0400
+++ plugins/org.eclipse.pde.api.tools/src_ant/org/eclipse/pde/api/tools/internal/tasks/APIToolsVerificationTask.java	2008-08-02 23:45:19.561053624 -0400
@@ -656,7 +656,7 @@
 			public int compare(Object o1, Object o2) {
 				Map.Entry entry1 = (Map.Entry) o1;
 				Map.Entry entry2 = (Map.Entry) o2;
-				return ((String) entry1.getKey()).compareTo(entry2.getKey());
+				return ((String) entry1.getKey()).compareTo((String) entry2.getKey());
 			}
 		});
 		Summary[] summaries = new Summary[size];
