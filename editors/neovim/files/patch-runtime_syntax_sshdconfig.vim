blacklistd has been renamed to blocklistd, so UseBlocklist
is the preferred alias for UseBlacklist.

See https://github.com/freebsd/freebsd-src/commit/e426c743

--- runtime/syntax/sshdconfig.vim.orig	2018-07-26 22:51:00 UTC
+++ runtime/syntax/sshdconfig.vim
@@ -221,6 +221,8 @@ syn keyword sshdconfigKeyword Subsystem
 syn keyword sshdconfigKeyword SyslogFacility
 syn keyword sshdconfigKeyword TCPKeepAlive
 syn keyword sshdconfigKeyword TrustedUserCAKeys
+syn keyword sshdconfigKeyword UseBlacklist
+syn keyword sshdconfigKeyword UseBlocklist
 syn keyword sshdconfigKeyword UseDNS
 syn keyword sshdconfigKeyword UseLogin
 syn keyword sshdconfigKeyword UsePAM
