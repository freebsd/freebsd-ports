--- internal/app/upgrade.go.orig	1979-11-30 08:00:00 UTC
+++ internal/app/upgrade.go
@@ -71,7 +71,7 @@ func detectInstallation(path, stamped, goos string) in
 		i.kind = installHomebrew
 	case strings.HasPrefix(slashed, "/nix/store/"):
 		i.kind = installNix
-	case goos != "windows" && goos != "darwin" && (strings.HasPrefix(slashed, "/usr/bin/") || strings.HasPrefix(slashed, "/bin/") || strings.HasPrefix(slashed, "/usr/sbin/")):
+	case goos != "windows" && goos != "darwin" && (strings.HasPrefix(slashed, "/usr/bin/") || strings.HasPrefix(slashed, "/bin/") || strings.HasPrefix(slashed, "/usr/sbin/") || strings.HasPrefix(slashed, "%%PREFIX%%/bin/")):
 		i.kind = installPackage
 	default:
 		i.kind = installScript
@@ -157,7 +157,7 @@ func (a *application) notifiesUpdates(args []string) (
 		}
 	}
 	i, err := a.installation()
-	return i, err == nil && i.kind != installSource
+	return i, err == nil && i.kind != installSource && i.kind != installPackage
 }
 
 // checkForUpdate asks for the latest release in the background while the command runs, when the
@@ -261,12 +261,12 @@ GITEA_CLI_DOWNLOAD_URL selects another download locati
 the install script, verifies its SHA-256 checksum and replaces its executable with it;
 GITEA_CLI_DOWNLOAD_URL selects another download location.
 
-gt installed with Homebrew, a Linux package, Nix or go install is upgraded the way it was
+gt installed with Homebrew, a package, Nix or go install is upgraded the way it was
 installed; gt upgrade names the command for that instead.
 
 After a command, gt tells at most once a day when a newer release is out, asking gitea.com
-for it. It does not check in CI or when stdout or stderr is not a terminal; set
-GITEA_CLI_NO_UPDATE_NOTIFIER to turn the check off.`,
+for it. It does not check when installed by a package, in CI or when stdout or stderr is not
+a terminal; set GITEA_CLI_NO_UPDATE_NOTIFIER to turn the check off.`,
 		Example: `$ gt upgrade
 # See whether a newer release is out
 $ gt upgrade --dry-run
