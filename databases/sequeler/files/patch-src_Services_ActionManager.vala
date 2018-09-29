Fix crash most likely caused by an outdated libgee and or vala?
Reevaluate when libgee >= 0.20 and vala >= 0.40 make it into the
tree after https://bugs.freebsd.org/229761 lands.

--- src/Services/ActionManager.vala.orig	2018-09-11 21:39:55 UTC
+++ src/Services/ActionManager.vala
@@ -32,8 +32,6 @@ public class Sequeler.Services.ActionManager : Object 
 	public const string ACTION_LOGOUT = "action_logout";
 	public const string ACTION_QUIT = "action_quit";
 
-	public static Gee.MultiMap<string, string> action_accelerators = new Gee.HashMultiMap<string, string> ();
-
 	private const ActionEntry[] action_entries = {
 		{ ACTION_NEW_WINDOW, action_new_window },
 		{ ACTION_NEW_CONNECTION, action_new_connection },
@@ -49,22 +47,16 @@ public class Sequeler.Services.ActionManager : Object 
 		);
 	}
 
-	static construct {
-		action_accelerators.set (ACTION_NEW_WINDOW, "<Control>n");
-		action_accelerators.set (ACTION_NEW_CONNECTION, "<Control><Shift>n");
-		action_accelerators.set (ACTION_RUN_QUERY, "<Control>Return");
-		action_accelerators.set (ACTION_LOGOUT, "<Control>Escape");
-		action_accelerators.set (ACTION_QUIT, "<Control>q");
-	}
-
 	construct {
 		actions = new SimpleActionGroup ();
 		actions.add_action_entries (action_entries, this);
 		window.insert_action_group ("win", actions);
 
-		foreach (var action in action_accelerators.get_keys ()) {
-			app.set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
-		}
+		app.set_accels_for_action (ACTION_PREFIX + ACTION_NEW_WINDOW, { "<Control>n" });
+		app.set_accels_for_action (ACTION_PREFIX + ACTION_NEW_CONNECTION, { "<Control><Shift>n" });
+		app.set_accels_for_action (ACTION_PREFIX + ACTION_RUN_QUERY, { "<Control>Return" });
+		app.set_accels_for_action (ACTION_PREFIX + ACTION_LOGOUT, { "<Control>Escape" });
+		app.set_accels_for_action (ACTION_PREFIX + ACTION_QUIT, { "<Control>q" });
 	}
 
 	private void action_quit () {
