--- setup2/source/compiler/decltor.cxx.orig	Sun Jul 21 00:25:00 2002
+++ setup2/source/compiler/decltor.cxx	Sun Jul 21 00:24:06 2002
@@ -304,6 +304,7 @@
 			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_SOLSG ||
 			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_SOLIG ||
 			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_LINUX ||
+			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_FREEBSD ||
 			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_HP ||
 			m_xCompiler->GetOsType() == com::sun::star::setup::OSType_UNIX_SCO;
 }
--- setup2/source/compiler/fields.cxx.orig	Sun Jul 21 00:25:42 2002
+++ setup2/source/compiler/fields.cxx	Sun Jul 21 00:25:45 2002
@@ -105,6 +105,7 @@
 char const VALUE_YES_IF_HPUX_HP9000[]	= "YES_IF_HPUX_HP9000";
 char const VALUE_YES_IF_AIX_RS6000[]	= "YES_IF_AIX_RS6000";
 char const VALUE_YES_IF_LINUX_X86[]		= "YES_IF_LINUX_X86";
+char const VALUE_YES_IF_FREEBSD_X86[]		= "YES_IF_FREEBSD_X86";
 char const VALUE_KEEP_OLD_VERSION[]     = "KEEP_OLD_VERSION";
 char const VALUE_NETWORK[]              = "NETWORK";
 char const VALUE_NO[]               	= "NO";
