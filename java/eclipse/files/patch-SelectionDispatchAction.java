
$FreeBSD$

--- plugins/org.eclipse.jdt.ui/ui/org/eclipse/jdt/ui/actions/SelectionDispatchAction.java.orig	Mon Jul 14 20:30:10 2003
+++ plugins/org.eclipse.jdt.ui/ui/org/eclipse/jdt/ui/actions/SelectionDispatchAction.java	Mon Jul 14 20:30:27 2003
@@ -123,7 +123,7 @@
 	 * Executes this actions with the given structured selection. This default implementation
 	 * calls <code>run(ISelection selection)</code>.
 	 */
-	protected void run(IStructuredSelection selection) {
+	public void run(IStructuredSelection selection) {
 		run((ISelection)selection);
 	}
 	
@@ -141,7 +141,7 @@
 	 * Executes this actions with the given text selection. This default implementation
 	 * calls <code>run(ISelection selection)</code>.
 	 */
-	protected void run(ITextSelection selection) {
+	public void run(ITextSelection selection) {
 		run((ISelection)selection);
 	}
 	
@@ -159,7 +159,7 @@
 	 * Executes this actions with the given selection. This default implementation
 	 * does nothing.
 	 */
-	protected void run(ISelection selection) {
+	public void run(ISelection selection) {
 	}
 
 	/* (non-Javadoc)
