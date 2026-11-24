--- packages/app-desktop/gui/MainScreen.tsx.orig	2026-11-19 16:09:35 UTC
+++ packages/app-desktop/gui/MainScreen.tsx
@@ -668,7 +668,7 @@ class MainScreenComponent extends React.Component<Prop
 						this.props.syncTargetAppMinVersion,
 					),
 				);
-			} else if (this.state.syncTargetAppMinVersionIsRelease === false && shim.isLinux()) {
+			} else if (this.state.syncTargetAppMinVersionIsRelease === false && (shim.isLinux() || shim.isFreeBSD())) {
 				const callForAction = _('Download it from GitHub Releases');
 				msg = this.renderNotificationMessage(
 					_(
