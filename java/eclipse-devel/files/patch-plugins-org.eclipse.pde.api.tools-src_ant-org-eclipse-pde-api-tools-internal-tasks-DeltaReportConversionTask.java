--- plugins/org.eclipse.pde.api.tools/src_ant/org/eclipse/pde/api/tools/internal/tasks/DeltaReportConversionTask.java.orig	2008-08-02 23:45:53.571262184 -0400
+++ plugins/org.eclipse.pde.api.tools/src_ant/org/eclipse/pde/api/tools/internal/tasks/DeltaReportConversionTask.java	2008-08-02 23:46:12.521379029 -0400
@@ -288,7 +288,7 @@
 			public int compare(Object o1, Object o2) {
 				Map.Entry entry1 = (Map.Entry) o1;
 				Map.Entry entry2 = (Map.Entry) o2;
-				return ((String) entry1.getKey()).compareTo(entry2.getKey());
+				return ((String) entry1.getKey()).compareTo((String) entry2.getKey());
 			}
 		});
 		for (Iterator iterator = allEntries.iterator(); iterator.hasNext(); ) {
