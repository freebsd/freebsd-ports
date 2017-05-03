--- app/src/processing/app/Base.java.orig	2017-03-16 17:38:01 UTC
+++ app/src/processing/app/Base.java
@@ -460,7 +460,7 @@ public class Base {
       new Thread(new NewBoardListener(this)).start();
 
       // Check for updates
-      if (PreferencesData.getBoolean("update.check")) {
+      if (false) {
         new UpdateCheck(this);
 
         contributionsSelfCheck = new ContributionsSelfCheck(this, new UpdatableBoardsLibsFakeURLsHandler(this), contributionInstaller, libraryInstaller);
@@ -1055,12 +1055,7 @@ public class Base {
     if (importMenu == null)
       return;
     importMenu.removeAll();
-
-    JMenuItem menu = new JMenuItem(tr("Manage Libraries..."));
-    menu.addActionListener(e -> openLibraryManager("", ""));
-    importMenu.add(menu);
-    importMenu.addSeparator();
-
+	
     JMenuItem addLibraryMenuItem = new JMenuItem(tr("Add .ZIP Library..."));
     addLibraryMenuItem.addActionListener(new ActionListener() {
       public void actionPerformed(ActionEvent e) {
@@ -1388,31 +1383,12 @@ public class Base {
     boardMenu.putClientProperty("removeOnWindowDeactivation", true);
     MenuScroller.setScrollerFor(boardMenu);
 
-    boardMenu.add(new JMenuItem(new AbstractAction(tr("Boards Manager...")) {
-      public void actionPerformed(ActionEvent actionevent) {
-        String filterText = "";
-        String dropdownItem = "";
-        if (actionevent instanceof Event) {
-          filterText = ((Event) actionevent).getPayload().get("filterText").toString();
-          dropdownItem = ((Event) actionevent).getPayload().get("dropdownItem").toString();
-        }
-        try {
-          openBoardsManager(filterText, dropdownItem);
-        } catch (Exception e) {
-          //TODO show error
-          e.printStackTrace();
-        }
-      }
-    }));
     boardsCustomMenus.add(boardMenu);
 
     // If there are no platforms installed we are done
     if (BaseNoGui.packages.size() == 0)
       return;
 
-    // Separate "Install boards..." command from installed boards
-    boardMenu.add(new JSeparator());
-
     // Generate custom menus for all platforms
     Set<String> customMenusTitles = new HashSet<>();
     for (TargetPackage targetPackage : BaseNoGui.packages.values()) {
