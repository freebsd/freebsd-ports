Index: aclocal.m4
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/aclocal.m4,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- aclocal.m4	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ aclocal.m4	2 Jan 2010 11:58:36 -0000	1.2
@@ -1,7 +1,7 @@
-# aclocal.m4 generated automatically by aclocal 1.6.3 -*- Autoconf -*-
+# generated automatically by aclocal 1.10.1 -*- Autoconf -*-
 
-# Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002
-# Free Software Foundation, Inc.
+# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
+# 2005, 2006, 2007, 2008  Free Software Foundation, Inc.
 # This file is free software; the Free Software Foundation
 # gives unlimited permission to copy and/or distribute it,
 # with or without modifications, as long as this notice is preserved.
@@ -12,102 +12,187 @@
 # PARTICULAR PURPOSE.
 
 # libtool.m4 - Configure libtool for the host system. -*-Autoconf-*-
+#
+#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
+#                 2006, 2007, 2008 Free Software Foundation, Inc.
+#   Written by Gordon Matzigkeit, 1996
+#
+# This file is free software; the Free Software Foundation gives
+# unlimited permission to copy and/or distribute it, with or without
+# modifications, as long as this notice is preserved.
+
+m4_define([_LT_COPYING], [dnl
+#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
+#                 2006, 2007, 2008 Free Software Foundation, Inc.
+#   Written by Gordon Matzigkeit, 1996
+#
+#   This file is part of GNU Libtool.
+#
+# GNU Libtool is free software; you can redistribute it and/or
+# modify it under the terms of the GNU General Public License as
+# published by the Free Software Foundation; either version 2 of
+# the License, or (at your option) any later version.
+#
+# As a special exception to the GNU General Public License,
+# if you distribute this file as part of a program or library that
+# is built using GNU Libtool, you may include this file under the
+# same distribution terms that you use for the rest of that program.
+#
+# GNU Libtool is distributed in the hope that it will be useful,
+# but WITHOUT ANY WARRANTY; without even the implied warranty of
+# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+# GNU General Public License for more details.
+#
+# You should have received a copy of the GNU General Public License
+# along with GNU Libtool; see the file COPYING.  If not, a copy
+# can be downloaded from http://www.gnu.org/licenses/gpl.html, or
+# obtained by writing to the Free Software Foundation, Inc.,
+# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
+])
 
-# serial 47 AC_PROG_LIBTOOL
-
+# serial 56 LT_INIT
 
-# AC_PROVIDE_IFELSE(MACRO-NAME, IF-PROVIDED, IF-NOT-PROVIDED)
-# -----------------------------------------------------------
-# If this macro is not defined by Autoconf, define it here.
-m4_ifdef([AC_PROVIDE_IFELSE],
-         [],
-         [m4_define([AC_PROVIDE_IFELSE],
-	         [m4_ifdef([AC_PROVIDE_$1],
-		           [$2], [$3])])])
 
+# LT_PREREQ(VERSION)
+# ------------------
+# Complain and exit if this libtool version is less that VERSION.
+m4_defun([LT_PREREQ],
+[m4_if(m4_version_compare(m4_defn([LT_PACKAGE_VERSION]), [$1]), -1,
+       [m4_default([$3],
+		   [m4_fatal([Libtool version $1 or higher is required],
+		             63)])],
+       [$2])])
+
+
+# _LT_CHECK_BUILDDIR
+# ------------------
+# Complain if the absolute build directory name contains unusual characters
+m4_defun([_LT_CHECK_BUILDDIR],
+[case `pwd` in
+  *\ * | *\	*)
+    AC_MSG_WARN([Libtool does not cope well with whitespace in `pwd`]) ;;
+esac
+])
 
-# AC_PROG_LIBTOOL
-# ---------------
-AC_DEFUN([AC_PROG_LIBTOOL],
-[AC_REQUIRE([_AC_PROG_LIBTOOL])dnl
-dnl If AC_PROG_CXX has already been expanded, run AC_LIBTOOL_CXX
-dnl immediately, otherwise, hook it in at the end of AC_PROG_CXX.
-  AC_PROVIDE_IFELSE([AC_PROG_CXX],
-    [AC_LIBTOOL_CXX],
-    [define([AC_PROG_CXX], defn([AC_PROG_CXX])[AC_LIBTOOL_CXX
-  ])])
-dnl And a similar setup for Fortran 77 support
-  AC_PROVIDE_IFELSE([AC_PROG_F77],
-    [AC_LIBTOOL_F77],
-    [define([AC_PROG_F77], defn([AC_PROG_F77])[AC_LIBTOOL_F77
-])])
-
-dnl Quote A][M_PROG_GCJ so that aclocal doesn't bring it in needlessly.
-dnl If either AC_PROG_GCJ or A][M_PROG_GCJ have already been expanded, run
-dnl AC_LIBTOOL_GCJ immediately, otherwise, hook it in at the end of both.
-  AC_PROVIDE_IFELSE([AC_PROG_GCJ],
-    [AC_LIBTOOL_GCJ],
-    [AC_PROVIDE_IFELSE([A][M_PROG_GCJ],
-      [AC_LIBTOOL_GCJ],
-      [AC_PROVIDE_IFELSE([LT_AC_PROG_GCJ],
-	[AC_LIBTOOL_GCJ],
-      [ifdef([AC_PROG_GCJ],
-	     [define([AC_PROG_GCJ], defn([AC_PROG_GCJ])[AC_LIBTOOL_GCJ])])
-       ifdef([A][M_PROG_GCJ],
-	     [define([A][M_PROG_GCJ], defn([A][M_PROG_GCJ])[AC_LIBTOOL_GCJ])])
-       ifdef([LT_AC_PROG_GCJ],
-	     [define([LT_AC_PROG_GCJ],
-		defn([LT_AC_PROG_GCJ])[AC_LIBTOOL_GCJ])])])])
-])])# AC_PROG_LIBTOOL
 
+# LT_INIT([OPTIONS])
+# ------------------
+AC_DEFUN([LT_INIT],
+[AC_PREREQ([2.58])dnl We use AC_INCLUDES_DEFAULT
+AC_BEFORE([$0], [LT_LANG])dnl
+AC_BEFORE([$0], [LT_OUTPUT])dnl
+AC_BEFORE([$0], [LTDL_INIT])dnl
+m4_require([_LT_CHECK_BUILDDIR])dnl
+
+dnl Autoconf doesn't catch unexpanded LT_ macros by default:
+m4_pattern_forbid([^_?LT_[A-Z_]+$])dnl
+m4_pattern_allow([^(_LT_EOF|LT_DLGLOBAL|LT_DLLAZY_OR_NOW|LT_MULTI_MODULE)$])dnl
+dnl aclocal doesn't pull ltoptions.m4, ltsugar.m4, or ltversion.m4
+dnl unless we require an AC_DEFUNed macro:
+AC_REQUIRE([LTOPTIONS_VERSION])dnl
+AC_REQUIRE([LTSUGAR_VERSION])dnl
+AC_REQUIRE([LTVERSION_VERSION])dnl
+AC_REQUIRE([LTOBSOLETE_VERSION])dnl
+m4_require([_LT_PROG_LTMAIN])dnl
 
-# _AC_PROG_LIBTOOL
-# ----------------
-AC_DEFUN([_AC_PROG_LIBTOOL],
-[AC_REQUIRE([AC_LIBTOOL_SETUP])dnl
-AC_BEFORE([$0],[AC_LIBTOOL_CXX])dnl
-AC_BEFORE([$0],[AC_LIBTOOL_F77])dnl
-AC_BEFORE([$0],[AC_LIBTOOL_GCJ])dnl
+dnl Parse OPTIONS
+_LT_SET_OPTIONS([$0], [$1])
 
 # This can be used to rebuild libtool when needed
-LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+LIBTOOL_DEPS="$ltmain"
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
 AC_SUBST(LIBTOOL)dnl
 
-# Prevent multiple expansion
-define([AC_PROG_LIBTOOL], [])
-])# _AC_PROG_LIBTOOL
+_LT_SETUP
 
+# Only expand once:
+m4_define([LT_INIT])
+])# LT_INIT
 
-# AC_LIBTOOL_SETUP
-# ----------------
-AC_DEFUN([AC_LIBTOOL_SETUP],
-[AC_PREREQ(2.50)dnl
-AC_REQUIRE([AC_ENABLE_SHARED])dnl
-AC_REQUIRE([AC_ENABLE_STATIC])dnl
-AC_REQUIRE([AC_ENABLE_FAST_INSTALL])dnl
-AC_REQUIRE([AC_CANONICAL_HOST])dnl
+# Old names:
+AU_ALIAS([AC_PROG_LIBTOOL], [LT_INIT])
+AU_ALIAS([AM_PROG_LIBTOOL], [LT_INIT])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_PROG_LIBTOOL], [])
+dnl AC_DEFUN([AM_PROG_LIBTOOL], [])
+
+
+# _LT_CC_BASENAME(CC)
+# -------------------
+# Calculate cc_basename.  Skip known compiler wrappers and cross-prefix.
+m4_defun([_LT_CC_BASENAME],
+[for cc_temp in $1""; do
+  case $cc_temp in
+    compile | *[[\\/]]compile | ccache | *[[\\/]]ccache ) ;;
+    distcc | *[[\\/]]distcc | purify | *[[\\/]]purify ) ;;
+    \-*) ;;
+    *) break;;
+  esac
+done
+cc_basename=`$ECHO "X$cc_temp" | $Xsed -e 's%.*/%%' -e "s%^$host_alias-%%"`
+])
+
+
+# _LT_FILEUTILS_DEFAULTS
+# ----------------------
+# It is okay to use these file commands and assume they have been set
+# sensibly after `m4_require([_LT_FILEUTILS_DEFAULTS])'.
+m4_defun([_LT_FILEUTILS_DEFAULTS],
+[: ${CP="cp -f"}
+: ${MV="mv -f"}
+: ${RM="rm -f"}
+])# _LT_FILEUTILS_DEFAULTS
+
+
+# _LT_SETUP
+# ---------
+m4_defun([_LT_SETUP],
+[AC_REQUIRE([AC_CANONICAL_HOST])dnl
 AC_REQUIRE([AC_CANONICAL_BUILD])dnl
+_LT_DECL([], [host_alias], [0], [The host system])dnl
+_LT_DECL([], [host], [0])dnl
+_LT_DECL([], [host_os], [0])dnl
+dnl
+_LT_DECL([], [build_alias], [0], [The build system])dnl
+_LT_DECL([], [build], [0])dnl
+_LT_DECL([], [build_os], [0])dnl
+dnl
 AC_REQUIRE([AC_PROG_CC])dnl
-AC_REQUIRE([AC_PROG_LD])dnl
-AC_REQUIRE([AC_PROG_LD_RELOAD_FLAG])dnl
-AC_REQUIRE([AC_PROG_NM])dnl
-
+AC_REQUIRE([LT_PATH_LD])dnl
+AC_REQUIRE([LT_PATH_NM])dnl
+dnl
 AC_REQUIRE([AC_PROG_LN_S])dnl
-AC_REQUIRE([AC_DEPLIBS_CHECK_METHOD])dnl
-# Autoconf 2.13's AC_OBJEXT and AC_EXEEXT macros only works for C compilers!
-AC_REQUIRE([AC_OBJEXT])dnl
-AC_REQUIRE([AC_EXEEXT])dnl
+test -z "$LN_S" && LN_S="ln -s"
+_LT_DECL([], [LN_S], [1], [Whether we need soft or hard links])dnl
+dnl
+AC_REQUIRE([LT_CMD_MAX_LEN])dnl
+_LT_DECL([objext], [ac_objext], [0], [Object file suffix (normally "o")])dnl
+_LT_DECL([], [exeext], [0], [Executable file suffix (normally "")])dnl
 dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_CHECK_SHELL_FEATURES])dnl
+m4_require([_LT_CMD_RELOAD])dnl
+m4_require([_LT_CHECK_MAGIC_METHOD])dnl
+m4_require([_LT_CMD_OLD_ARCHIVE])dnl
+m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl
+
+_LT_CONFIG_LIBTOOL_INIT([
+# See if we are running on zsh, and set the options which allow our
+# commands through without removal of \ escapes INIT.
+if test -n "\${ZSH_VERSION+set}" ; then
+   setopt NO_GLOB_SUBST
+fi
+])
+if test -n "${ZSH_VERSION+set}" ; then
+   setopt NO_GLOB_SUBST
+fi
 
-AC_LIBTOOL_SYS_MAX_CMD_LEN
-AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE
-AC_LIBTOOL_OBJDIR
+_LT_CHECK_OBJDIR
 
-AC_REQUIRE([_LT_AC_SYS_COMPILER])dnl
-_LT_AC_PROG_ECHO_BACKSLASH
+m4_require([_LT_TAG_COMPILER])dnl
+_LT_PROG_ECHO_BACKSLASH
 
 case $host_os in
 aix3*)
@@ -123,174 +208,879 @@ esac
 
 # Sed substitution that helps us do robust quoting.  It backslashifies
 # metacharacters that are still active within double-quoted strings.
-Xsed='sed -e s/^X//'
-[sed_quote_subst='s/\([\\"\\`$\\\\]\)/\\\1/g']
+sed_quote_subst='s/\([["`$\\]]\)/\\\1/g'
 
 # Same as above, but do not quote variable references.
-[double_quote_subst='s/\([\\"\\`\\\\]\)/\\\1/g']
+double_quote_subst='s/\([["`\\]]\)/\\\1/g'
 
 # Sed substitution to delay expansion of an escaped shell variable in a
 # double_quote_subst'ed string.
 delay_variable_subst='s/\\\\\\\\\\\$/\\\\\\$/g'
 
+# Sed substitution to delay expansion of an escaped single quote.
+delay_single_quote_subst='s/'\''/'\'\\\\\\\'\''/g'
+
 # Sed substitution to avoid accidental globbing in evaled expressions
 no_glob_subst='s/\*/\\\*/g'
 
-# Constants:
-rm="rm -f"
-
 # Global variables:
-default_ofile=libtool
+ofile=libtool
 can_build_shared=yes
 
-# All known linkers require a `.a' archive for static linking (except M$VC,
+# All known linkers require a `.a' archive for static linking (except MSVC,
 # which needs '.lib').
 libext=a
-ltmain="$ac_aux_dir/ltmain.sh"
-ofile="$default_ofile"
-with_gnu_ld="$lt_cv_prog_gnu_ld"
 
-AC_CHECK_TOOL(AR, ar, false)
-AC_CHECK_TOOL(RANLIB, ranlib, :)
-AC_CHECK_TOOL(STRIP, strip, :)
+with_gnu_ld="$lt_cv_prog_gnu_ld"
 
 old_CC="$CC"
 old_CFLAGS="$CFLAGS"
 
 # Set sane defaults for various variables
-test -z "$AR" && AR=ar
-test -z "$AR_FLAGS" && AR_FLAGS=cru
-test -z "$AS" && AS=as
 test -z "$CC" && CC=cc
 test -z "$LTCC" && LTCC=$CC
-test -z "$DLLTOOL" && DLLTOOL=dlltool
+test -z "$LTCFLAGS" && LTCFLAGS=$CFLAGS
 test -z "$LD" && LD=ld
-test -z "$LN_S" && LN_S="ln -s"
-test -z "$MAGIC_CMD" && MAGIC_CMD=file
-test -z "$NM" && NM=nm
-test -z "$SED" && SED=sed
-test -z "$OBJDUMP" && OBJDUMP=objdump
-test -z "$RANLIB" && RANLIB=:
-test -z "$STRIP" && STRIP=:
 test -z "$ac_objext" && ac_objext=o
 
-# Determine commands to create old-style static archives.
-old_archive_cmds='$AR $AR_FLAGS $oldlib$oldobjs$old_deplibs'
-old_postinstall_cmds='chmod 644 $oldlib'
-old_postuninstall_cmds=
-
-if test -n "$RANLIB"; then
-  case $host_os in
-  openbsd*)
-    old_postinstall_cmds="\$RANLIB -t \$oldlib~$old_postinstall_cmds"
-    ;;
-  *)
-    old_postinstall_cmds="\$RANLIB \$oldlib~$old_postinstall_cmds"
-    ;;
-  esac
-  old_archive_cmds="$old_archive_cmds~\$RANLIB \$oldlib"
-fi
+_LT_CC_BASENAME([$compiler])
 
 # Only perform the check for file, if the check method requires it
+test -z "$MAGIC_CMD" && MAGIC_CMD=file
 case $deplibs_check_method in
 file_magic*)
   if test "$file_magic_cmd" = '$MAGIC_CMD'; then
-    AC_PATH_MAGIC
+    _LT_PATH_MAGIC
   fi
   ;;
 esac
 
-AC_PROVIDE_IFELSE([AC_LIBTOOL_DLOPEN], enable_dlopen=yes, enable_dlopen=no)
-AC_PROVIDE_IFELSE([AC_LIBTOOL_WIN32_DLL],
-enable_win32_dll=yes, enable_win32_dll=no)
-
-AC_ARG_ENABLE([libtool-lock],
-    [AC_HELP_STRING([--disable-libtool-lock],
-	[avoid locking (might break parallel builds)])])
-test "x$enable_libtool_lock" != xno && enable_libtool_lock=yes
+# Use C for the default configuration in the libtool script
+LT_SUPPORTED_TAG([CC])
+_LT_LANG_C_CONFIG
+_LT_LANG_DEFAULT_CONFIG
+_LT_CONFIG_COMMANDS
+])# _LT_SETUP
+
+
+# _LT_PROG_LTMAIN
+# ---------------
+# Note that this code is called both from `configure', and `config.status'
+# now that we use AC_CONFIG_COMMANDS to generate libtool.  Notably,
+# `config.status' has no value for ac_aux_dir unless we are using Automake,
+# so we pass a copy along to make sure it has a sensible value anyway.
+m4_defun([_LT_PROG_LTMAIN],
+[m4_ifdef([AC_REQUIRE_AUX_FILE], [AC_REQUIRE_AUX_FILE([ltmain.sh])])dnl
+_LT_CONFIG_LIBTOOL_INIT([ac_aux_dir='$ac_aux_dir'])
+ltmain="$ac_aux_dir/ltmain.sh"
+])# _LT_PROG_LTMAIN
+
+
+
+# So that we can recreate a full libtool script including additional
+# tags, we accumulate the chunks of code to send to AC_CONFIG_COMMANDS
+# in macros and then make a single call at the end using the `libtool'
+# label.
+
+
+# _LT_CONFIG_LIBTOOL_INIT([INIT-COMMANDS])
+# ----------------------------------------
+# Register INIT-COMMANDS to be passed to AC_CONFIG_COMMANDS later.
+m4_define([_LT_CONFIG_LIBTOOL_INIT],
+[m4_ifval([$1],
+          [m4_append([_LT_OUTPUT_LIBTOOL_INIT],
+                     [$1
+])])])
+
+# Initialize.
+m4_define([_LT_OUTPUT_LIBTOOL_INIT])
+
+
+# _LT_CONFIG_LIBTOOL([COMMANDS])
+# ------------------------------
+# Register COMMANDS to be passed to AC_CONFIG_COMMANDS later.
+m4_define([_LT_CONFIG_LIBTOOL],
+[m4_ifval([$1],
+          [m4_append([_LT_OUTPUT_LIBTOOL_COMMANDS],
+                     [$1
+])])])
+
+# Initialize.
+m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS])
+
+
+# _LT_CONFIG_SAVE_COMMANDS([COMMANDS], [INIT_COMMANDS])
+# -----------------------------------------------------
+m4_defun([_LT_CONFIG_SAVE_COMMANDS],
+[_LT_CONFIG_LIBTOOL([$1])
+_LT_CONFIG_LIBTOOL_INIT([$2])
+])
+
+
+# _LT_FORMAT_COMMENT([COMMENT])
+# -----------------------------
+# Add leading comment marks to the start of each line, and a trailing
+# full-stop to the whole comment if one is not present already.
+m4_define([_LT_FORMAT_COMMENT],
+[m4_ifval([$1], [
+m4_bpatsubst([m4_bpatsubst([$1], [^ *], [# ])],
+              [['`$\]], [\\\&])]m4_bmatch([$1], [[!?.]$], [], [.])
+)])
+
+
 
-AC_ARG_WITH([pic],
-    [AC_HELP_STRING([--with-pic],
-	[try to use only PIC/non-PIC objects @<:@default=use both@:>@])],
-    [pic_mode="$withval"],
-    [pic_mode=default])
-test -z "$pic_mode" && pic_mode=default
 
-# Use C for the default configuration in the libtool script
-tagname=
-AC_LIBTOOL_LANG_C_CONFIG
-_LT_AC_TAGCONFIG
-])# AC_LIBTOOL_SETUP
+
+# _LT_DECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION], [IS-TAGGED?])
+# -------------------------------------------------------------------
+# CONFIGNAME is the name given to the value in the libtool script.
+# VARNAME is the (base) name used in the configure script.
+# VALUE may be 0, 1 or 2 for a computed quote escaped value based on
+# VARNAME.  Any other value will be used directly.
+m4_define([_LT_DECL],
+[lt_if_append_uniq([lt_decl_varnames], [$2], [, ],
+    [lt_dict_add_subkey([lt_decl_dict], [$2], [libtool_name],
+	[m4_ifval([$1], [$1], [$2])])
+    lt_dict_add_subkey([lt_decl_dict], [$2], [value], [$3])
+    m4_ifval([$4],
+	[lt_dict_add_subkey([lt_decl_dict], [$2], [description], [$4])])
+    lt_dict_add_subkey([lt_decl_dict], [$2],
+	[tagged?], [m4_ifval([$5], [yes], [no])])])
+])
+
+
+# _LT_TAGDECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION])
+# --------------------------------------------------------
+m4_define([_LT_TAGDECL], [_LT_DECL([$1], [$2], [$3], [$4], [yes])])
+
+
+# lt_decl_tag_varnames([SEPARATOR], [VARNAME1...])
+# ------------------------------------------------
+m4_define([lt_decl_tag_varnames],
+[_lt_decl_filter([tagged?], [yes], $@)])
+
+
+# _lt_decl_filter(SUBKEY, VALUE, [SEPARATOR], [VARNAME1..])
+# ---------------------------------------------------------
+m4_define([_lt_decl_filter],
+[m4_case([$#],
+  [0], [m4_fatal([$0: too few arguments: $#])],
+  [1], [m4_fatal([$0: too few arguments: $#: $1])],
+  [2], [lt_dict_filter([lt_decl_dict], [$1], [$2], [], lt_decl_varnames)],
+  [3], [lt_dict_filter([lt_decl_dict], [$1], [$2], [$3], lt_decl_varnames)],
+  [lt_dict_filter([lt_decl_dict], $@)])[]dnl
+])
+
+
+# lt_decl_quote_varnames([SEPARATOR], [VARNAME1...])
+# --------------------------------------------------
+m4_define([lt_decl_quote_varnames],
+[_lt_decl_filter([value], [1], $@)])
+
+
+# lt_decl_dquote_varnames([SEPARATOR], [VARNAME1...])
+# ---------------------------------------------------
+m4_define([lt_decl_dquote_varnames],
+[_lt_decl_filter([value], [2], $@)])
+
+
+# lt_decl_varnames_tagged([SEPARATOR], [VARNAME1...])
+# ---------------------------------------------------
+m4_define([lt_decl_varnames_tagged],
+[m4_assert([$# <= 2])dnl
+_$0(m4_quote(m4_default([$1], [[, ]])),
+    m4_ifval([$2], [[$2]], [m4_dquote(lt_decl_tag_varnames)]),
+    m4_split(m4_normalize(m4_quote(_LT_TAGS)), [ ]))])
+m4_define([_lt_decl_varnames_tagged],
+[m4_ifval([$3], [lt_combine([$1], [$2], [_], $3)])])
+
+
+# lt_decl_all_varnames([SEPARATOR], [VARNAME1...])
+# ------------------------------------------------
+m4_define([lt_decl_all_varnames],
+[_$0(m4_quote(m4_default([$1], [[, ]])),
+     m4_if([$2], [],
+	   m4_quote(lt_decl_varnames),
+	m4_quote(m4_shift($@))))[]dnl
+])
+m4_define([_lt_decl_all_varnames],
+[lt_join($@, lt_decl_varnames_tagged([$1],
+			lt_decl_tag_varnames([[, ]], m4_shift($@))))dnl
+])
+
+
+# _LT_CONFIG_STATUS_DECLARE([VARNAME])
+# ------------------------------------
+# Quote a variable value, and forward it to `config.status' so that its
+# declaration there will have the same value as in `configure'.  VARNAME
+# must have a single quote delimited value for this to work.
+m4_define([_LT_CONFIG_STATUS_DECLARE],
+[$1='`$ECHO "X$][$1" | $Xsed -e "$delay_single_quote_subst"`'])
+
+
+# _LT_CONFIG_STATUS_DECLARATIONS
+# ------------------------------
+# We delimit libtool config variables with single quotes, so when
+# we write them to config.status, we have to be sure to quote all
+# embedded single quotes properly.  In configure, this macro expands
+# each variable declared with _LT_DECL (and _LT_TAGDECL) into:
+#
+#    <var>='`$ECHO "X$<var>" | $Xsed -e "$delay_single_quote_subst"`'
+m4_defun([_LT_CONFIG_STATUS_DECLARATIONS],
+[m4_foreach([_lt_var], m4_quote(lt_decl_all_varnames),
+    [m4_n([_LT_CONFIG_STATUS_DECLARE(_lt_var)])])])
+
+
+# _LT_LIBTOOL_TAGS
+# ----------------
+# Output comment and list of tags supported by the script
+m4_defun([_LT_LIBTOOL_TAGS],
+[_LT_FORMAT_COMMENT([The names of the tagged configurations supported by this script])dnl
+available_tags="_LT_TAGS"dnl
+])
+
+
+# _LT_LIBTOOL_DECLARE(VARNAME, [TAG])
+# -----------------------------------
+# Extract the dictionary values for VARNAME (optionally with TAG) and
+# expand to a commented shell variable setting:
+#
+#    # Some comment about what VAR is for.
+#    visible_name=$lt_internal_name
+m4_define([_LT_LIBTOOL_DECLARE],
+[_LT_FORMAT_COMMENT(m4_quote(lt_dict_fetch([lt_decl_dict], [$1],
+					   [description])))[]dnl
+m4_pushdef([_libtool_name],
+    m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [libtool_name])))[]dnl
+m4_case(m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [value])),
+    [0], [_libtool_name=[$]$1],
+    [1], [_libtool_name=$lt_[]$1],
+    [2], [_libtool_name=$lt_[]$1],
+    [_libtool_name=lt_dict_fetch([lt_decl_dict], [$1], [value])])[]dnl
+m4_ifval([$2], [_$2])[]m4_popdef([_libtool_name])[]dnl
+])
 
 
-# _LT_AC_SYS_COMPILER
+# _LT_LIBTOOL_CONFIG_VARS
+# -----------------------
+# Produce commented declarations of non-tagged libtool config variables
+# suitable for insertion in the LIBTOOL CONFIG section of the `libtool'
+# script.  Tagged libtool config variables (even for the LIBTOOL CONFIG
+# section) are produced by _LT_LIBTOOL_TAG_VARS.
+m4_defun([_LT_LIBTOOL_CONFIG_VARS],
+[m4_foreach([_lt_var],
+    m4_quote(_lt_decl_filter([tagged?], [no], [], lt_decl_varnames)),
+    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var)])])])
+
+
+# _LT_LIBTOOL_TAG_VARS(TAG)
+# -------------------------
+m4_define([_LT_LIBTOOL_TAG_VARS],
+[m4_foreach([_lt_var], m4_quote(lt_decl_tag_varnames),
+    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var, [$1])])])])
+
+
+# _LT_TAGVAR(VARNAME, [TAGNAME])
+# ------------------------------
+m4_define([_LT_TAGVAR], [m4_ifval([$2], [$1_$2], [$1])])
+
+
+# _LT_CONFIG_COMMANDS
 # -------------------
-AC_DEFUN([_LT_AC_SYS_COMPILER],
+# Send accumulated output to $CONFIG_STATUS.  Thanks to the lists of
+# variables for single and double quote escaping we saved from calls
+# to _LT_DECL, we can put quote escaped variables declarations
+# into `config.status', and then the shell code to quote escape them in
+# for loops in `config.status'.  Finally, any additional code accumulated
+# from calls to _LT_CONFIG_LIBTOOL_INIT is expanded.
+m4_defun([_LT_CONFIG_COMMANDS],
+[AC_PROVIDE_IFELSE([LT_OUTPUT],
+	dnl If the libtool generation code has been placed in $CONFIG_LT,
+	dnl instead of duplicating it all over again into config.status,
+	dnl then we will have config.status run $CONFIG_LT later, so it
+	dnl needs to know what name is stored there:
+        [AC_CONFIG_COMMANDS([libtool],
+            [$SHELL $CONFIG_LT || AS_EXIT(1)], [CONFIG_LT='$CONFIG_LT'])],
+    dnl If the libtool generation code is destined for config.status,
+    dnl expand the accumulated commands and init code now:
+    [AC_CONFIG_COMMANDS([libtool],
+        [_LT_OUTPUT_LIBTOOL_COMMANDS], [_LT_OUTPUT_LIBTOOL_COMMANDS_INIT])])
+])#_LT_CONFIG_COMMANDS
+
+
+# Initialize.
+m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS_INIT],
+[
+
+# The HP-UX ksh and POSIX shell print the target directory to stdout
+# if CDPATH is set.
+(unset CDPATH) >/dev/null 2>&1 && unset CDPATH
+
+sed_quote_subst='$sed_quote_subst'
+double_quote_subst='$double_quote_subst'
+delay_variable_subst='$delay_variable_subst'
+_LT_CONFIG_STATUS_DECLARATIONS
+LTCC='$LTCC'
+LTCFLAGS='$LTCFLAGS'
+compiler='$compiler_DEFAULT'
+
+# Quote evaled strings.
+for var in lt_decl_all_varnames([[ \
+]], lt_decl_quote_varnames); do
+    case \`eval \\\\\$ECHO "X\\\\\$\$var"\` in
+    *[[\\\\\\\`\\"\\\$]]*)
+      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"X\\\$\$var\\" | \\\$Xsed -e \\"\\\$sed_quote_subst\\"\\\`\\\\\\""
+      ;;
+    *)
+      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
+      ;;
+    esac
+done
+
+# Double-quote double-evaled strings.
+for var in lt_decl_all_varnames([[ \
+]], lt_decl_dquote_varnames); do
+    case \`eval \\\\\$ECHO "X\\\\\$\$var"\` in
+    *[[\\\\\\\`\\"\\\$]]*)
+      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"X\\\$\$var\\" | \\\$Xsed -e \\"\\\$double_quote_subst\\" -e \\"\\\$sed_quote_subst\\" -e \\"\\\$delay_variable_subst\\"\\\`\\\\\\""
+      ;;
+    *)
+      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
+      ;;
+    esac
+done
+
+# Fix-up fallback echo if it was mangled by the above quoting rules.
+case \$lt_ECHO in
+*'\\\[$]0 --fallback-echo"')dnl "
+  lt_ECHO=\`\$ECHO "X\$lt_ECHO" | \$Xsed -e 's/\\\\\\\\\\\\\\\[$]0 --fallback-echo"\[$]/\[$]0 --fallback-echo"/'\`
+  ;;
+esac
+
+_LT_OUTPUT_LIBTOOL_INIT
+])
+
+
+# LT_OUTPUT
+# ---------
+# This macro allows early generation of the libtool script (before
+# AC_OUTPUT is called), incase it is used in configure for compilation
+# tests.
+AC_DEFUN([LT_OUTPUT],
+[: ${CONFIG_LT=./config.lt}
+AC_MSG_NOTICE([creating $CONFIG_LT])
+cat >"$CONFIG_LT" <<_LTEOF
+#! $SHELL
+# Generated by $as_me.
+# Run this file to recreate a libtool stub with the current configuration.
+
+lt_cl_silent=false
+SHELL=\${CONFIG_SHELL-$SHELL}
+_LTEOF
+
+cat >>"$CONFIG_LT" <<\_LTEOF
+AS_SHELL_SANITIZE
+_AS_PREPARE
+
+exec AS_MESSAGE_FD>&1
+exec AS_MESSAGE_LOG_FD>>config.log
+{
+  echo
+  AS_BOX([Running $as_me.])
+} >&AS_MESSAGE_LOG_FD
+
+lt_cl_help="\
+\`$as_me' creates a local libtool stub from the current configuration,
+for use in further configure time tests before the real libtool is
+generated.
+
+Usage: $[0] [[OPTIONS]]
+
+  -h, --help      print this help, then exit
+  -V, --version   print version number, then exit
+  -q, --quiet     do not print progress messages
+  -d, --debug     don't remove temporary files
+
+Report bugs to <bug-libtool@gnu.org>."
+
+lt_cl_version="\
+m4_ifset([AC_PACKAGE_NAME], [AC_PACKAGE_NAME ])config.lt[]dnl
+m4_ifset([AC_PACKAGE_VERSION], [ AC_PACKAGE_VERSION])
+configured by $[0], generated by m4_PACKAGE_STRING.
+
+Copyright (C) 2008 Free Software Foundation, Inc.
+This config.lt script is free software; the Free Software Foundation
+gives unlimited permision to copy, distribute and modify it."
+
+while test $[#] != 0
+do
+  case $[1] in
+    --version | --v* | -V )
+      echo "$lt_cl_version"; exit 0 ;;
+    --help | --h* | -h )
+      echo "$lt_cl_help"; exit 0 ;;
+    --debug | --d* | -d )
+      debug=: ;;
+    --quiet | --q* | --silent | --s* | -q )
+      lt_cl_silent=: ;;
+
+    -*) AC_MSG_ERROR([unrecognized option: $[1]
+Try \`$[0] --help' for more information.]) ;;
+
+    *) AC_MSG_ERROR([unrecognized argument: $[1]
+Try \`$[0] --help' for more information.]) ;;
+  esac
+  shift
+done
+
+if $lt_cl_silent; then
+  exec AS_MESSAGE_FD>/dev/null
+fi
+_LTEOF
+
+cat >>"$CONFIG_LT" <<_LTEOF
+_LT_OUTPUT_LIBTOOL_COMMANDS_INIT
+_LTEOF
+
+cat >>"$CONFIG_LT" <<\_LTEOF
+AC_MSG_NOTICE([creating $ofile])
+_LT_OUTPUT_LIBTOOL_COMMANDS
+AS_EXIT(0)
+_LTEOF
+chmod +x "$CONFIG_LT"
+
+# configure is writing to config.log, but config.lt does its own redirection,
+# appending to config.log, which fails on DOS, as config.log is still kept
+# open by configure.  Here we exec the FD to /dev/null, effectively closing
+# config.log, so it can be properly (re)opened and appended to by config.lt.
+if test "$no_create" != yes; then
+  lt_cl_success=:
+  test "$silent" = yes &&
+    lt_config_lt_args="$lt_config_lt_args --quiet"
+  exec AS_MESSAGE_LOG_FD>/dev/null
+  $SHELL "$CONFIG_LT" $lt_config_lt_args || lt_cl_success=false
+  exec AS_MESSAGE_LOG_FD>>config.log
+  $lt_cl_success || AS_EXIT(1)
+fi
+])# LT_OUTPUT
+
+
+# _LT_CONFIG(TAG)
+# ---------------
+# If TAG is the built-in tag, create an initial libtool script with a
+# default configuration from the untagged config vars.  Otherwise add code
+# to config.status for appending the configuration named by TAG from the
+# matching tagged config vars.
+m4_defun([_LT_CONFIG],
+[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+_LT_CONFIG_SAVE_COMMANDS([
+  m4_define([_LT_TAG], m4_if([$1], [], [C], [$1]))dnl
+  m4_if(_LT_TAG, [C], [
+    # See if we are running on zsh, and set the options which allow our
+    # commands through without removal of \ escapes.
+    if test -n "${ZSH_VERSION+set}" ; then
+      setopt NO_GLOB_SUBST
+    fi
+
+    cfgfile="${ofile}T"
+    trap "$RM \"$cfgfile\"; exit 1" 1 2 15
+    $RM "$cfgfile"
+
+    cat <<_LT_EOF >> "$cfgfile"
+#! $SHELL
+
+# `$ECHO "$ofile" | sed 's%^.*/%%'` - Provide generalized library-building support services.
+# Generated automatically by $as_me ($PACKAGE$TIMESTAMP) $VERSION
+# Libtool was configured on host `(hostname || uname -n) 2>/dev/null | sed 1q`:
+# NOTE: Changes made to this file will be lost: look at ltmain.sh.
+#
+_LT_COPYING
+_LT_LIBTOOL_TAGS
+
+# ### BEGIN LIBTOOL CONFIG
+_LT_LIBTOOL_CONFIG_VARS
+_LT_LIBTOOL_TAG_VARS
+# ### END LIBTOOL CONFIG
+
+_LT_EOF
+
+  case $host_os in
+  aix3*)
+    cat <<\_LT_EOF >> "$cfgfile"
+# AIX sometimes has problems with the GCC collect2 program.  For some
+# reason, if we set the COLLECT_NAMES environment variable, the problems
+# vanish in a puff of smoke.
+if test "X${COLLECT_NAMES+set}" != Xset; then
+  COLLECT_NAMES=
+  export COLLECT_NAMES
+fi
+_LT_EOF
+    ;;
+  esac
+
+  _LT_PROG_LTMAIN
+
+  # We use sed instead of cat because bash on DJGPP gets confused if
+  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
+  # text mode, it properly converts lines to CR/LF.  This bash problem
+  # is reportedly fixed, but why not run on old versions too?
+  sed '/^# Generated shell functions inserted here/q' "$ltmain" >> "$cfgfile" \
+    || (rm -f "$cfgfile"; exit 1)
+
+  _LT_PROG_XSI_SHELLFNS
+
+  sed -n '/^# Generated shell functions inserted here/,$p' "$ltmain" >> "$cfgfile" \
+    || (rm -f "$cfgfile"; exit 1)
+
+  mv -f "$cfgfile" "$ofile" ||
+    (rm -f "$ofile" && cp "$cfgfile" "$ofile" && rm -f "$cfgfile")
+  chmod +x "$ofile"
+],
+[cat <<_LT_EOF >> "$ofile"
+
+dnl Unfortunately we have to use $1 here, since _LT_TAG is not expanded
+dnl in a comment (ie after a #).
+# ### BEGIN LIBTOOL TAG CONFIG: $1
+_LT_LIBTOOL_TAG_VARS(_LT_TAG)
+# ### END LIBTOOL TAG CONFIG: $1
+_LT_EOF
+])dnl /m4_if
+],
+[m4_if([$1], [], [
+    PACKAGE='$PACKAGE'
+    VERSION='$VERSION'
+    TIMESTAMP='$TIMESTAMP'
+    RM='$RM'
+    ofile='$ofile'], [])
+])dnl /_LT_CONFIG_SAVE_COMMANDS
+])# _LT_CONFIG
+
+
+# LT_SUPPORTED_TAG(TAG)
+# ---------------------
+# Trace this macro to discover what tags are supported by the libtool
+# --tag option, using:
+#    autoconf --trace 'LT_SUPPORTED_TAG:$1'
+AC_DEFUN([LT_SUPPORTED_TAG], [])
+
+
+# C support is built-in for now
+m4_define([_LT_LANG_C_enabled], [])
+m4_define([_LT_TAGS], [])
+
+
+# LT_LANG(LANG)
+# -------------
+# Enable libtool support for the given language if not already enabled.
+AC_DEFUN([LT_LANG],
+[AC_BEFORE([$0], [LT_OUTPUT])dnl
+m4_case([$1],
+  [C],			[_LT_LANG(C)],
+  [C++],		[_LT_LANG(CXX)],
+  [Java],		[_LT_LANG(GCJ)],
+  [Fortran 77],		[_LT_LANG(F77)],
+  [Fortran],		[_LT_LANG(FC)],
+  [Windows Resource],	[_LT_LANG(RC)],
+  [m4_ifdef([_LT_LANG_]$1[_CONFIG],
+    [_LT_LANG($1)],
+    [m4_fatal([$0: unsupported language: "$1"])])])dnl
+])# LT_LANG
+
+
+# _LT_LANG(LANGNAME)
+# ------------------
+m4_defun([_LT_LANG],
+[m4_ifdef([_LT_LANG_]$1[_enabled], [],
+  [LT_SUPPORTED_TAG([$1])dnl
+  m4_append([_LT_TAGS], [$1 ])dnl
+  m4_define([_LT_LANG_]$1[_enabled], [])dnl
+  _LT_LANG_$1_CONFIG($1)])dnl
+])# _LT_LANG
+
+
+# _LT_LANG_DEFAULT_CONFIG
+# -----------------------
+m4_defun([_LT_LANG_DEFAULT_CONFIG],
+[AC_PROVIDE_IFELSE([AC_PROG_CXX],
+  [LT_LANG(CXX)],
+  [m4_define([AC_PROG_CXX], defn([AC_PROG_CXX])[LT_LANG(CXX)])])
+
+AC_PROVIDE_IFELSE([AC_PROG_F77],
+  [LT_LANG(F77)],
+  [m4_define([AC_PROG_F77], defn([AC_PROG_F77])[LT_LANG(F77)])])
+
+AC_PROVIDE_IFELSE([AC_PROG_FC],
+  [LT_LANG(FC)],
+  [m4_define([AC_PROG_FC], defn([AC_PROG_FC])[LT_LANG(FC)])])
+
+dnl The call to [A][M_PROG_GCJ] is quoted like that to stop aclocal
+dnl pulling things in needlessly.
+AC_PROVIDE_IFELSE([AC_PROG_GCJ],
+  [LT_LANG(GCJ)],
+  [AC_PROVIDE_IFELSE([A][M_PROG_GCJ],
+    [LT_LANG(GCJ)],
+    [AC_PROVIDE_IFELSE([LT_PROG_GCJ],
+      [LT_LANG(GCJ)],
+      [m4_ifdef([AC_PROG_GCJ],
+	[m4_define([AC_PROG_GCJ], defn([AC_PROG_GCJ])[LT_LANG(GCJ)])])
+       m4_ifdef([A][M_PROG_GCJ],
+	[m4_define([A][M_PROG_GCJ], defn([A][M_PROG_GCJ])[LT_LANG(GCJ)])])
+       m4_ifdef([LT_PROG_GCJ],
+	[m4_define([LT_PROG_GCJ], defn([LT_PROG_GCJ])[LT_LANG(GCJ)])])])])])
+
+AC_PROVIDE_IFELSE([LT_PROG_RC],
+  [LT_LANG(RC)],
+  [m4_define([LT_PROG_RC], defn([LT_PROG_RC])[LT_LANG(RC)])])
+])# _LT_LANG_DEFAULT_CONFIG
+
+# Obsolete macros:
+AU_DEFUN([AC_LIBTOOL_CXX], [LT_LANG(C++)])
+AU_DEFUN([AC_LIBTOOL_F77], [LT_LANG(Fortran 77)])
+AU_DEFUN([AC_LIBTOOL_FC], [LT_LANG(Fortran)])
+AU_DEFUN([AC_LIBTOOL_GCJ], [LT_LANG(Java)])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_CXX], [])
+dnl AC_DEFUN([AC_LIBTOOL_F77], [])
+dnl AC_DEFUN([AC_LIBTOOL_FC], [])
+dnl AC_DEFUN([AC_LIBTOOL_GCJ], [])
+
+
+# _LT_TAG_COMPILER
+# ----------------
+m4_defun([_LT_TAG_COMPILER],
 [AC_REQUIRE([AC_PROG_CC])dnl
 
+_LT_DECL([LTCC], [CC], [1], [A C compiler])dnl
+_LT_DECL([LTCFLAGS], [CFLAGS], [1], [LTCC compiler flags])dnl
+_LT_TAGDECL([CC], [compiler], [1], [A language specific compiler])dnl
+_LT_TAGDECL([with_gcc], [GCC], [0], [Is the compiler the GNU compiler?])dnl
+
 # If no C compiler was specified, use CC.
 LTCC=${LTCC-"$CC"}
 
+# If no C compiler flags were specified, use CFLAGS.
+LTCFLAGS=${LTCFLAGS-"$CFLAGS"}
+
 # Allow CC to be a program name with arguments.
 compiler=$CC
-])# _LT_AC_SYS_COMPILER
+])# _LT_TAG_COMPILER
+
+
+# _LT_COMPILER_BOILERPLATE
+# ------------------------
+# Check for compiler boilerplate output or warnings with
+# the simple compiler test code.
+m4_defun([_LT_COMPILER_BOILERPLATE],
+[m4_require([_LT_DECL_SED])dnl
+ac_outfile=conftest.$ac_objext
+echo "$lt_simple_compile_test_code" >conftest.$ac_ext
+eval "$ac_compile" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
+_lt_compiler_boilerplate=`cat conftest.err`
+$RM conftest*
+])# _LT_COMPILER_BOILERPLATE
 
 
-# _LT_AC_SYS_LIBPATH_AIX
+# _LT_LINKER_BOILERPLATE
 # ----------------------
+# Check for linker boilerplate output or warnings with
+# the simple link test code.
+m4_defun([_LT_LINKER_BOILERPLATE],
+[m4_require([_LT_DECL_SED])dnl
+ac_outfile=conftest.$ac_objext
+echo "$lt_simple_link_test_code" >conftest.$ac_ext
+eval "$ac_link" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
+_lt_linker_boilerplate=`cat conftest.err`
+$RM -r conftest*
+])# _LT_LINKER_BOILERPLATE
+
+# _LT_REQUIRED_DARWIN_CHECKS
+# -------------------------
+m4_defun_once([_LT_REQUIRED_DARWIN_CHECKS],[
+  case $host_os in
+    rhapsody* | darwin*)
+    AC_CHECK_TOOL([DSYMUTIL], [dsymutil], [:])
+    AC_CHECK_TOOL([NMEDIT], [nmedit], [:])
+    AC_CHECK_TOOL([LIPO], [lipo], [:])
+    AC_CHECK_TOOL([OTOOL], [otool], [:])
+    AC_CHECK_TOOL([OTOOL64], [otool64], [:])
+    _LT_DECL([], [DSYMUTIL], [1],
+      [Tool to manipulate archived DWARF debug symbol files on Mac OS X])
+    _LT_DECL([], [NMEDIT], [1],
+      [Tool to change global to local symbols on Mac OS X])
+    _LT_DECL([], [LIPO], [1],
+      [Tool to manipulate fat objects and archives on Mac OS X])
+    _LT_DECL([], [OTOOL], [1],
+      [ldd/readelf like tool for Mach-O binaries on Mac OS X])
+    _LT_DECL([], [OTOOL64], [1],
+      [ldd/readelf like tool for 64 bit Mach-O binaries on Mac OS X 10.4])
+
+    AC_CACHE_CHECK([for -single_module linker flag],[lt_cv_apple_cc_single_mod],
+      [lt_cv_apple_cc_single_mod=no
+      if test -z "${LT_MULTI_MODULE}"; then
+	# By default we will add the -single_module flag. You can override
+	# by either setting the environment variable LT_MULTI_MODULE
+	# non-empty at configure time, or by adding -multi_module to the
+	# link flags.
+	rm -rf libconftest.dylib*
+	echo "int foo(void){return 1;}" > conftest.c
+	echo "$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
+-dynamiclib -Wl,-single_module conftest.c" >&AS_MESSAGE_LOG_FD
+	$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
+	  -dynamiclib -Wl,-single_module conftest.c 2>conftest.err
+        _lt_result=$?
+	if test -f libconftest.dylib && test ! -s conftest.err && test $_lt_result = 0; then
+	  lt_cv_apple_cc_single_mod=yes
+	else
+	  cat conftest.err >&AS_MESSAGE_LOG_FD
+	fi
+	rm -rf libconftest.dylib*
+	rm -f conftest.*
+      fi])
+    AC_CACHE_CHECK([for -exported_symbols_list linker flag],
+      [lt_cv_ld_exported_symbols_list],
+      [lt_cv_ld_exported_symbols_list=no
+      save_LDFLAGS=$LDFLAGS
+      echo "_main" > conftest.sym
+      LDFLAGS="$LDFLAGS -Wl,-exported_symbols_list,conftest.sym"
+      AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
+	[lt_cv_ld_exported_symbols_list=yes],
+	[lt_cv_ld_exported_symbols_list=no])
+	LDFLAGS="$save_LDFLAGS"
+    ])
+    case $host_os in
+    rhapsody* | darwin1.[[012]])
+      _lt_dar_allow_undefined='${wl}-undefined ${wl}suppress' ;;
+    darwin1.*)
+      _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
+    darwin*) # darwin 5.x on
+      # if running on 10.5 or later, the deployment target defaults
+      # to the OS version, if on x86, and 10.4, the deployment
+      # target defaults to 10.4. Don't you love it?
+      case ${MACOSX_DEPLOYMENT_TARGET-10.0},$host in
+	10.0,*86*-darwin8*|10.0,*-darwin[[91]]*)
+	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
+	10.[[012]]*)
+	  _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
+	10.*)
+	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
+      esac
+    ;;
+  esac
+    if test "$lt_cv_apple_cc_single_mod" = "yes"; then
+      _lt_dar_single_mod='$single_module'
+    fi
+    if test "$lt_cv_ld_exported_symbols_list" = "yes"; then
+      _lt_dar_export_syms=' ${wl}-exported_symbols_list,$output_objdir/${libname}-symbols.expsym'
+    else
+      _lt_dar_export_syms='~$NMEDIT -s $output_objdir/${libname}-symbols.expsym ${lib}'
+    fi
+    if test "$DSYMUTIL" != ":"; then
+      _lt_dsymutil='~$DSYMUTIL $lib || :'
+    else
+      _lt_dsymutil=
+    fi
+    ;;
+  esac
+])
+
+
+# _LT_DARWIN_LINKER_FEATURES
+# --------------------------
+# Checks for linker and compiler features on darwin
+m4_defun([_LT_DARWIN_LINKER_FEATURES],
+[
+  m4_require([_LT_REQUIRED_DARWIN_CHECKS])
+  _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+  _LT_TAGVAR(hardcode_direct, $1)=no
+  _LT_TAGVAR(hardcode_automatic, $1)=yes
+  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
+  _LT_TAGVAR(whole_archive_flag_spec, $1)=''
+  _LT_TAGVAR(link_all_deplibs, $1)=yes
+  _LT_TAGVAR(allow_undefined_flag, $1)="$_lt_dar_allow_undefined"
+  case $cc_basename in
+     ifort*) _lt_dar_can_shared=yes ;;
+     *) _lt_dar_can_shared=$GCC ;;
+  esac
+  if test "$_lt_dar_can_shared" = "yes"; then
+    output_verbose_link_cmd=echo
+    _LT_TAGVAR(archive_cmds, $1)="\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring $_lt_dar_single_mod${_lt_dsymutil}"
+    _LT_TAGVAR(module_cmds, $1)="\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dsymutil}"
+    _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring ${_lt_dar_single_mod}${_lt_dar_export_syms}${_lt_dsymutil}"
+    _LT_TAGVAR(module_expsym_cmds, $1)="sed -e 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dar_export_syms}${_lt_dsymutil}"
+    m4_if([$1], [CXX],
+[   if test "$lt_cv_apple_cc_single_mod" != "yes"; then
+      _LT_TAGVAR(archive_cmds, $1)="\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dsymutil}"
+      _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dar_export_syms}${_lt_dsymutil}"
+    fi
+],[])
+  else
+  _LT_TAGVAR(ld_shlibs, $1)=no
+  fi
+])
+
+# _LT_SYS_MODULE_PATH_AIX
+# -----------------------
 # Links a minimal program and checks the executable
 # for the system default hardcoded library path. In most cases,
 # this is /usr/lib:/lib, but when the MPI compilers are used
 # the location of the communication and MPI libs are included too.
 # If we don't find anything, use the default library path according
 # to the aix ld manual.
-AC_DEFUN([_LT_AC_SYS_LIBPATH_AIX],
-[AC_LINK_IFELSE(AC_LANG_PROGRAM,[
-aix_libpath=`dump -H conftest$ac_exeext 2>/dev/null | $SED -n -e '/Import File Strings/,/^$/ { /^0/ { s/^0  *\(.*\)$/\1/; p; }
-}'`
+m4_defun([_LT_SYS_MODULE_PATH_AIX],
+[m4_require([_LT_DECL_SED])dnl
+AC_LINK_IFELSE(AC_LANG_PROGRAM,[
+lt_aix_libpath_sed='
+    /Import File Strings/,/^$/ {
+	/^0/ {
+	    s/^0  *\(.*\)$/\1/
+	    p
+	}
+    }'
+aix_libpath=`dump -H conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
 # Check for a 64-bit object if we didn't find anything.
-if test -z "$aix_libpath"; then aix_libpath=`dump -HX64 conftest$ac_exeext 2>/dev/null | $SED -n -e '/Import File Strings/,/^$/ { /^0/ { s/^0  *\(.*\)$/\1/; p; }
-}'`; fi],[])
+if test -z "$aix_libpath"; then
+  aix_libpath=`dump -HX64 conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
+fi],[])
 if test -z "$aix_libpath"; then aix_libpath="/usr/lib:/lib"; fi
-])# _LT_AC_SYS_LIBPATH_AIX
+])# _LT_SYS_MODULE_PATH_AIX
 
 
-# _LT_AC_SHELL_INIT(ARG)
-# ----------------------
-AC_DEFUN([_LT_AC_SHELL_INIT],
+# _LT_SHELL_INIT(ARG)
+# -------------------
+m4_define([_LT_SHELL_INIT],
 [ifdef([AC_DIVERSION_NOTICE],
 	     [AC_DIVERT_PUSH(AC_DIVERSION_NOTICE)],
 	 [AC_DIVERT_PUSH(NOTICE)])
 $1
 AC_DIVERT_POP
-])# _LT_AC_SHELL_INIT
+])# _LT_SHELL_INIT
 
 
-# _LT_AC_PROG_ECHO_BACKSLASH
-# --------------------------
+# _LT_PROG_ECHO_BACKSLASH
+# -----------------------
 # Add some code to the start of the generated configure script which
 # will find an echo command which doesn't interpret backslashes.
-AC_DEFUN([_LT_AC_PROG_ECHO_BACKSLASH],
-[_LT_AC_SHELL_INIT([
+m4_defun([_LT_PROG_ECHO_BACKSLASH],
+[_LT_SHELL_INIT([
 # Check that we are running under the correct shell.
 SHELL=${CONFIG_SHELL-/bin/sh}
 
-case X$ECHO in
+case X$lt_ECHO in
 X*--fallback-echo)
   # Remove one level of quotation (which was required for Make).
-  ECHO=`echo "$ECHO" | sed 's,\\\\\[$]\\[$]0,'[$]0','`
+  ECHO=`echo "$lt_ECHO" | sed 's,\\\\\[$]\\[$]0,'[$]0','`
   ;;
 esac
 
-echo=${ECHO-echo}
+ECHO=${lt_ECHO-echo}
 if test "X[$]1" = X--no-reexec; then
   # Discard the --no-reexec flag, and continue.
   shift
 elif test "X[$]1" = X--fallback-echo; then
   # Avoid inline document here, it may be left over
   :
-elif test "X`($echo '\t') 2>/dev/null`" = 'X\t' ; then
-  # Yippee, $echo works!
+elif test "X`{ $ECHO '\t'; } 2>/dev/null`" = 'X\t' ; then
+  # Yippee, $ECHO works!
   :
 else
   # Restart under the correct shell.
@@ -300,134 +1090,137 @@ fi
 if test "X[$]1" = X--fallback-echo; then
   # used as fallback echo
   shift
-  cat <<EOF
+  cat <<_LT_EOF
 [$]*
-EOF
+_LT_EOF
   exit 0
 fi
 
 # The HP-UX ksh and POSIX shell print the target directory to stdout
 # if CDPATH is set.
-if test "X${CDPATH+set}" = Xset; then CDPATH=:; export CDPATH; fi
-
-if test -z "$ECHO"; then
-if test "X${echo_test_string+set}" != Xset; then
-# find a string as large as possible, as long as the shell can cope with it
-  for cmd in 'sed 50q "[$]0"' 'sed 20q "[$]0"' 'sed 10q "[$]0"' 'sed 2q "[$]0"' 'echo test'; do
-    # expected sizes: less than 2Kb, 1Kb, 512 bytes, 16 bytes, ...
-    if (echo_test_string="`eval $cmd`") 2>/dev/null &&
-       echo_test_string="`eval $cmd`" &&
-       (test "X$echo_test_string" = "X$echo_test_string") 2>/dev/null
-    then
-      break
-    fi
-  done
-fi
+(unset CDPATH) >/dev/null 2>&1 && unset CDPATH
 
-if test "X`($echo '\t') 2>/dev/null`" = 'X\t' &&
-   echo_testing_string=`($echo "$echo_test_string") 2>/dev/null` &&
-   test "X$echo_testing_string" = "X$echo_test_string"; then
-  :
-else
-  # The Solaris, AIX, and Digital Unix default echo programs unquote
-  # backslashes.  This makes it impossible to quote backslashes using
-  #   echo "$something" | sed 's/\\/\\\\/g'
-  #
-  # So, first we look for a working echo in the user's PATH.
+if test -z "$lt_ECHO"; then
+  if test "X${echo_test_string+set}" != Xset; then
+    # find a string as large as possible, as long as the shell can cope with it
+    for cmd in 'sed 50q "[$]0"' 'sed 20q "[$]0"' 'sed 10q "[$]0"' 'sed 2q "[$]0"' 'echo test'; do
+      # expected sizes: less than 2Kb, 1Kb, 512 bytes, 16 bytes, ...
+      if { echo_test_string=`eval $cmd`; } 2>/dev/null &&
+	 { test "X$echo_test_string" = "X$echo_test_string"; } 2>/dev/null
+      then
+        break
+      fi
+    done
+  fi
 
-  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
-  for dir in $PATH /usr/ucb; do
+  if test "X`{ $ECHO '\t'; } 2>/dev/null`" = 'X\t' &&
+     echo_testing_string=`{ $ECHO "$echo_test_string"; } 2>/dev/null` &&
+     test "X$echo_testing_string" = "X$echo_test_string"; then
+    :
+  else
+    # The Solaris, AIX, and Digital Unix default echo programs unquote
+    # backslashes.  This makes it impossible to quote backslashes using
+    #   echo "$something" | sed 's/\\/\\\\/g'
+    #
+    # So, first we look for a working echo in the user's PATH.
+
+    lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
+    for dir in $PATH /usr/ucb; do
+      IFS="$lt_save_ifs"
+      if (test -f $dir/echo || test -f $dir/echo$ac_exeext) &&
+         test "X`($dir/echo '\t') 2>/dev/null`" = 'X\t' &&
+         echo_testing_string=`($dir/echo "$echo_test_string") 2>/dev/null` &&
+         test "X$echo_testing_string" = "X$echo_test_string"; then
+        ECHO="$dir/echo"
+        break
+      fi
+    done
     IFS="$lt_save_ifs"
-    if (test -f $dir/echo || test -f $dir/echo$ac_exeext) &&
-       test "X`($dir/echo '\t') 2>/dev/null`" = 'X\t' &&
-       echo_testing_string=`($dir/echo "$echo_test_string") 2>/dev/null` &&
-       test "X$echo_testing_string" = "X$echo_test_string"; then
-      echo="$dir/echo"
-      break
-    fi
-  done
-  IFS="$lt_save_ifs"
 
-  if test "X$echo" = Xecho; then
-    # We didn't find a better echo, so look for alternatives.
-    if test "X`(print -r '\t') 2>/dev/null`" = 'X\t' &&
-       echo_testing_string=`(print -r "$echo_test_string") 2>/dev/null` &&
-       test "X$echo_testing_string" = "X$echo_test_string"; then
-      # This shell has a builtin print -r that does the trick.
-      echo='print -r'
-    elif (test -f /bin/ksh || test -f /bin/ksh$ac_exeext) &&
-	 test "X$CONFIG_SHELL" != X/bin/ksh; then
-      # If we have ksh, try running configure again with it.
-      ORIGINAL_CONFIG_SHELL=${CONFIG_SHELL-/bin/sh}
-      export ORIGINAL_CONFIG_SHELL
-      CONFIG_SHELL=/bin/ksh
-      export CONFIG_SHELL
-      exec $CONFIG_SHELL "[$]0" --no-reexec ${1+"[$]@"}
-    else
-      # Try using printf.
-      echo='printf %s\n'
-      if test "X`($echo '\t') 2>/dev/null`" = 'X\t' &&
-	 echo_testing_string=`($echo "$echo_test_string") 2>/dev/null` &&
-	 test "X$echo_testing_string" = "X$echo_test_string"; then
-	# Cool, printf works
-	:
-      elif echo_testing_string=`($ORIGINAL_CONFIG_SHELL "[$]0" --fallback-echo '\t') 2>/dev/null` &&
-	   test "X$echo_testing_string" = 'X\t' &&
-	   echo_testing_string=`($ORIGINAL_CONFIG_SHELL "[$]0" --fallback-echo "$echo_test_string") 2>/dev/null` &&
-	   test "X$echo_testing_string" = "X$echo_test_string"; then
-	CONFIG_SHELL=$ORIGINAL_CONFIG_SHELL
-	export CONFIG_SHELL
-	SHELL="$CONFIG_SHELL"
-	export SHELL
-	echo="$CONFIG_SHELL [$]0 --fallback-echo"
-      elif echo_testing_string=`($CONFIG_SHELL "[$]0" --fallback-echo '\t') 2>/dev/null` &&
-	   test "X$echo_testing_string" = 'X\t' &&
-	   echo_testing_string=`($CONFIG_SHELL "[$]0" --fallback-echo "$echo_test_string") 2>/dev/null` &&
-	   test "X$echo_testing_string" = "X$echo_test_string"; then
-	echo="$CONFIG_SHELL [$]0 --fallback-echo"
+    if test "X$ECHO" = Xecho; then
+      # We didn't find a better echo, so look for alternatives.
+      if test "X`{ print -r '\t'; } 2>/dev/null`" = 'X\t' &&
+         echo_testing_string=`{ print -r "$echo_test_string"; } 2>/dev/null` &&
+         test "X$echo_testing_string" = "X$echo_test_string"; then
+        # This shell has a builtin print -r that does the trick.
+        ECHO='print -r'
+      elif { test -f /bin/ksh || test -f /bin/ksh$ac_exeext; } &&
+	   test "X$CONFIG_SHELL" != X/bin/ksh; then
+        # If we have ksh, try running configure again with it.
+        ORIGINAL_CONFIG_SHELL=${CONFIG_SHELL-/bin/sh}
+        export ORIGINAL_CONFIG_SHELL
+        CONFIG_SHELL=/bin/ksh
+        export CONFIG_SHELL
+        exec $CONFIG_SHELL "[$]0" --no-reexec ${1+"[$]@"}
       else
-	# maybe with a smaller string...
-	prev=:
+        # Try using printf.
+        ECHO='printf %s\n'
+        if test "X`{ $ECHO '\t'; } 2>/dev/null`" = 'X\t' &&
+	   echo_testing_string=`{ $ECHO "$echo_test_string"; } 2>/dev/null` &&
+	   test "X$echo_testing_string" = "X$echo_test_string"; then
+	  # Cool, printf works
+	  :
+        elif echo_testing_string=`($ORIGINAL_CONFIG_SHELL "[$]0" --fallback-echo '\t') 2>/dev/null` &&
+	     test "X$echo_testing_string" = 'X\t' &&
+	     echo_testing_string=`($ORIGINAL_CONFIG_SHELL "[$]0" --fallback-echo "$echo_test_string") 2>/dev/null` &&
+	     test "X$echo_testing_string" = "X$echo_test_string"; then
+	  CONFIG_SHELL=$ORIGINAL_CONFIG_SHELL
+	  export CONFIG_SHELL
+	  SHELL="$CONFIG_SHELL"
+	  export SHELL
+	  ECHO="$CONFIG_SHELL [$]0 --fallback-echo"
+        elif echo_testing_string=`($CONFIG_SHELL "[$]0" --fallback-echo '\t') 2>/dev/null` &&
+	     test "X$echo_testing_string" = 'X\t' &&
+	     echo_testing_string=`($CONFIG_SHELL "[$]0" --fallback-echo "$echo_test_string") 2>/dev/null` &&
+	     test "X$echo_testing_string" = "X$echo_test_string"; then
+	  ECHO="$CONFIG_SHELL [$]0 --fallback-echo"
+        else
+	  # maybe with a smaller string...
+	  prev=:
 
-	for cmd in 'echo test' 'sed 2q "[$]0"' 'sed 10q "[$]0"' 'sed 20q "[$]0"' 'sed 50q "[$]0"'; do
-	  if (test "X$echo_test_string" = "X`eval $cmd`") 2>/dev/null
-	  then
-	    break
-	  fi
-	  prev="$cmd"
-	done
+	  for cmd in 'echo test' 'sed 2q "[$]0"' 'sed 10q "[$]0"' 'sed 20q "[$]0"' 'sed 50q "[$]0"'; do
+	    if { test "X$echo_test_string" = "X`eval $cmd`"; } 2>/dev/null
+	    then
+	      break
+	    fi
+	    prev="$cmd"
+	  done
 
-	if test "$prev" != 'sed 50q "[$]0"'; then
-	  echo_test_string=`eval $prev`
-	  export echo_test_string
-	  exec ${ORIGINAL_CONFIG_SHELL-${CONFIG_SHELL-/bin/sh}} "[$]0" ${1+"[$]@"}
-	else
-	  # Oops.  We lost completely, so just stick with echo.
-	  echo=echo
-	fi
+	  if test "$prev" != 'sed 50q "[$]0"'; then
+	    echo_test_string=`eval $prev`
+	    export echo_test_string
+	    exec ${ORIGINAL_CONFIG_SHELL-${CONFIG_SHELL-/bin/sh}} "[$]0" ${1+"[$]@"}
+	  else
+	    # Oops.  We lost completely, so just stick with echo.
+	    ECHO=echo
+	  fi
+        fi
       fi
     fi
   fi
 fi
-fi
 
 # Copy echo and quote the copy suitably for passing to libtool from
 # the Makefile, instead of quoting the original, which is used later.
-ECHO=$echo
-if test "X$ECHO" = "X$CONFIG_SHELL [$]0 --fallback-echo"; then
-   ECHO="$CONFIG_SHELL \\\$\[$]0 --fallback-echo"
+lt_ECHO=$ECHO
+if test "X$lt_ECHO" = "X$CONFIG_SHELL [$]0 --fallback-echo"; then
+   lt_ECHO="$CONFIG_SHELL \\\$\[$]0 --fallback-echo"
 fi
 
-AC_SUBST(ECHO)
-])])# _LT_AC_PROG_ECHO_BACKSLASH
+AC_SUBST(lt_ECHO)
+])
+_LT_DECL([], [SHELL], [1], [Shell to use when invoking shell scripts])
+_LT_DECL([], [ECHO], [1],
+    [An echo program that does not interpret backslashes])
+])# _LT_PROG_ECHO_BACKSLASH
 
 
-# _LT_AC_LOCK
-# -----------
-AC_DEFUN([_LT_AC_LOCK],
+# _LT_ENABLE_LOCK
+# ---------------
+m4_defun([_LT_ENABLE_LOCK],
 [AC_ARG_ENABLE([libtool-lock],
-    [AC_HELP_STRING([--disable-libtool-lock],
-	[avoid locking (might break parallel builds)])])
+  [AS_HELP_STRING([--disable-libtool-lock],
+    [avoid locking (might break parallel builds)])])
 test "x$enable_libtool_lock" != xno && enable_libtool_lock=yes
 
 # Some flags need to be propagated to the compiler or linker for good
@@ -438,12 +1231,12 @@ ia64-*-hpux*)
   echo 'int i;' > conftest.$ac_ext
   if AC_TRY_EVAL(ac_compile); then
     case `/usr/bin/file conftest.$ac_objext` in
-    *ELF-32*)
-      HPUX_IA64_MODE="32"
-      ;;
-    *ELF-64*)
-      HPUX_IA64_MODE="64"
-      ;;
+      *ELF-32*)
+	HPUX_IA64_MODE="32"
+	;;
+      *ELF-64*)
+	HPUX_IA64_MODE="64"
+	;;
     esac
   fi
   rm -rf conftest*
@@ -452,72 +1245,79 @@ ia64-*-hpux*)
   # Find out which ABI we are using.
   echo '[#]line __oline__ "configure"' > conftest.$ac_ext
   if AC_TRY_EVAL(ac_compile); then
-   if test "$lt_cv_prog_gnu_ld" = yes; then
-    case `/usr/bin/file conftest.$ac_objext` in
-    *32-bit*)
-      LD="${LD-ld} -melf32bsmip"
-      ;;
-    *N32*)
-      LD="${LD-ld} -melf32bmipn32"
-      ;;
-    *64-bit*)
-      LD="${LD-ld} -melf64bmip"
-      ;;
-    esac
-   else
-    case `/usr/bin/file conftest.$ac_objext` in
-    *32-bit*)
-      LD="${LD-ld} -32"
-      ;;
-    *N32*)
-      LD="${LD-ld} -n32"
-      ;;
-    *64-bit*)
-      LD="${LD-ld} -64"
-      ;;
-    esac
-   fi
+    if test "$lt_cv_prog_gnu_ld" = yes; then
+      case `/usr/bin/file conftest.$ac_objext` in
+	*32-bit*)
+	  LD="${LD-ld} -melf32bsmip"
+	  ;;
+	*N32*)
+	  LD="${LD-ld} -melf32bmipn32"
+	  ;;
+	*64-bit*)
+	  LD="${LD-ld} -melf64bmip"
+	;;
+      esac
+    else
+      case `/usr/bin/file conftest.$ac_objext` in
+	*32-bit*)
+	  LD="${LD-ld} -32"
+	  ;;
+	*N32*)
+	  LD="${LD-ld} -n32"
+	  ;;
+	*64-bit*)
+	  LD="${LD-ld} -64"
+	  ;;
+      esac
+    fi
   fi
   rm -rf conftest*
   ;;
 
-x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*|s390*-*linux*|sparc*-*linux*)
+x86_64-*kfreebsd*-gnu|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
+s390*-*linux*|s390*-*tpf*|sparc*-*linux*)
   # Find out which ABI we are using.
   echo 'int i;' > conftest.$ac_ext
   if AC_TRY_EVAL(ac_compile); then
-    case "`/usr/bin/file conftest.o`" in
-    *32-bit*)
-      case $host in
-        x86_64-*linux*)
-          LD="${LD-ld} -m elf_i386"
-          ;;
-        ppc64-*linux*)
-          LD="${LD-ld} -m elf32ppclinux"
-          ;;
-        s390x-*linux*)
-          LD="${LD-ld} -m elf_s390"
-          ;;
-        sparc64-*linux*)
-          LD="${LD-ld} -m elf32_sparc"
-          ;;
-      esac
-      ;;
-    *64-bit*)
-      case $host in
-        x86_64-*linux*)
-          LD="${LD-ld} -m elf_x86_64"
-          ;;
-        ppc*-*linux*|powerpc*-*linux*)
-          LD="${LD-ld} -m elf64ppc"
-          ;;
-        s390*-*linux*)
-          LD="${LD-ld} -m elf64_s390"
-          ;;
-        sparc*-*linux*)
-          LD="${LD-ld} -m elf64_sparc"
-          ;;
-      esac
-      ;;
+    case `/usr/bin/file conftest.o` in
+      *32-bit*)
+	case $host in
+	  x86_64-*kfreebsd*-gnu)
+	    LD="${LD-ld} -m elf_i386_fbsd"
+	    ;;
+	  x86_64-*linux*)
+	    LD="${LD-ld} -m elf_i386"
+	    ;;
+	  ppc64-*linux*|powerpc64-*linux*)
+	    LD="${LD-ld} -m elf32ppclinux"
+	    ;;
+	  s390x-*linux*)
+	    LD="${LD-ld} -m elf_s390"
+	    ;;
+	  sparc64-*linux*)
+	    LD="${LD-ld} -m elf32_sparc"
+	    ;;
+	esac
+	;;
+      *64-bit*)
+	case $host in
+	  x86_64-*kfreebsd*-gnu)
+	    LD="${LD-ld} -m elf_x86_64_fbsd"
+	    ;;
+	  x86_64-*linux*)
+	    LD="${LD-ld} -m elf_x86_64"
+	    ;;
+	  ppc*-*linux*|powerpc*-*linux*)
+	    LD="${LD-ld} -m elf64ppc"
+	    ;;
+	  s390*-*linux*|s390*-*tpf*)
+	    LD="${LD-ld} -m elf64_s390"
+	    ;;
+	  sparc*-*linux*)
+	    LD="${LD-ld} -m elf64_sparc"
+	    ;;
+	esac
+	;;
     esac
   fi
   rm -rf conftest*
@@ -529,36 +1329,90 @@ x86_64-*linux*|ppc*-*linux*|powerpc*-*li
   CFLAGS="$CFLAGS -belf"
   AC_CACHE_CHECK([whether the C compiler needs -belf], lt_cv_cc_needs_belf,
     [AC_LANG_PUSH(C)
-     AC_TRY_LINK([],[],[lt_cv_cc_needs_belf=yes],[lt_cv_cc_needs_belf=no])
+     AC_LINK_IFELSE([AC_LANG_PROGRAM([[]],[[]])],[lt_cv_cc_needs_belf=yes],[lt_cv_cc_needs_belf=no])
      AC_LANG_POP])
   if test x"$lt_cv_cc_needs_belf" != x"yes"; then
     # this is probably gcc 2.8.0, egcs 1.0 or newer; no need for -belf
     CFLAGS="$SAVE_CFLAGS"
   fi
   ;;
-AC_PROVIDE_IFELSE([AC_LIBTOOL_WIN32_DLL],
-[*-*-cygwin* | *-*-mingw* | *-*-pw32*)
-  AC_CHECK_TOOL(DLLTOOL, dlltool, false)
-  AC_CHECK_TOOL(AS, as, false)
-  AC_CHECK_TOOL(OBJDUMP, objdump, false)
+sparc*-*solaris*)
+  # Find out which ABI we are using.
+  echo 'int i;' > conftest.$ac_ext
+  if AC_TRY_EVAL(ac_compile); then
+    case `/usr/bin/file conftest.o` in
+    *64-bit*)
+      case $lt_cv_prog_gnu_ld in
+      yes*) LD="${LD-ld} -m elf64_sparc" ;;
+      *)
+	if ${LD-ld} -64 -r -o conftest2.o conftest.o >/dev/null 2>&1; then
+	  LD="${LD-ld} -64"
+	fi
+	;;
+      esac
+      ;;
+    esac
+  fi
+  rm -rf conftest*
   ;;
-  ])
 esac
 
 need_locks="$enable_libtool_lock"
+])# _LT_ENABLE_LOCK
+
+
+# _LT_CMD_OLD_ARCHIVE
+# -------------------
+m4_defun([_LT_CMD_OLD_ARCHIVE],
+[AC_CHECK_TOOL(AR, ar, false)
+test -z "$AR" && AR=ar
+test -z "$AR_FLAGS" && AR_FLAGS=cru
+_LT_DECL([], [AR], [1], [The archiver])
+_LT_DECL([], [AR_FLAGS], [1])
+
+AC_CHECK_TOOL(STRIP, strip, :)
+test -z "$STRIP" && STRIP=:
+_LT_DECL([], [STRIP], [1], [A symbol stripping program])
+
+AC_CHECK_TOOL(RANLIB, ranlib, :)
+test -z "$RANLIB" && RANLIB=:
+_LT_DECL([], [RANLIB], [1],
+    [Commands used to install an old-style archive])
+
+# Determine commands to create old-style static archives.
+old_archive_cmds='$AR $AR_FLAGS $oldlib$oldobjs'
+old_postinstall_cmds='chmod 644 $oldlib'
+old_postuninstall_cmds=
 
-])# _LT_AC_LOCK
+if test -n "$RANLIB"; then
+  case $host_os in
+  openbsd*)
+    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB -t \$oldlib"
+    ;;
+  *)
+    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB \$oldlib"
+    ;;
+  esac
+  old_archive_cmds="$old_archive_cmds~\$RANLIB \$oldlib"
+fi
+_LT_DECL([], [old_postinstall_cmds], [2])
+_LT_DECL([], [old_postuninstall_cmds], [2])
+_LT_TAGDECL([], [old_archive_cmds], [2],
+    [Commands used to build an old-style archive])
+])# _LT_CMD_OLD_ARCHIVE
 
 
-# AC_LIBTOOL_COMPILER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
+# _LT_COMPILER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
 #		[OUTPUT-FILE], [ACTION-SUCCESS], [ACTION-FAILURE])
 # ----------------------------------------------------------------
 # Check whether the given compiler option works
-AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION],
-[AC_CACHE_CHECK([$1], [$2],
+AC_DEFUN([_LT_COMPILER_OPTION],
+[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_DECL_SED])dnl
+AC_CACHE_CHECK([$1], [$2],
   [$2=no
-  ifelse([$4], , [ac_outfile=conftest.$ac_objext], [ac_outfile=$4])
-   printf "$lt_simple_compile_test_code" > conftest.$ac_ext
+   m4_if([$4], , [ac_outfile=conftest.$ac_objext], [ac_outfile=$4])
+   echo "$lt_simple_compile_test_code" > conftest.$ac_ext
    lt_compiler_flag="$3"
    # Insert the option either (1) after the last *FLAGS variable, or
    # (2) before a word containing "conftest.", or (3) at the end.
@@ -566,7 +1420,7 @@ AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION],
    # with a dollar sign (not a hyphen), so the echo should work correctly.
    # The option is referenced via a variable to avoid confusing sed.
    lt_compile=`echo "$ac_compile" | $SED \
-   -e 's:.*FLAGS}? :&$lt_compiler_flag :; t' \
+   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
    -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
    -e 's:$: $lt_compiler_flag:'`
    (eval echo "\"\$as_me:__oline__: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
@@ -576,62 +1430,82 @@ AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION],
    echo "$as_me:__oline__: \$? = $ac_status" >&AS_MESSAGE_LOG_FD
    if (exit $ac_status) && test -s "$ac_outfile"; then
      # The compiler can only warn and ignore the option if not recognized
-     # So say no if there are warnings
-     if test ! -s conftest.err; then
+     # So say no if there are warnings other than the usual output.
+     $ECHO "X$_lt_compiler_boilerplate" | $Xsed -e '/^$/d' >conftest.exp
+     $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
+     if test ! -s conftest.er2 || diff conftest.exp conftest.er2 >/dev/null; then
        $2=yes
      fi
    fi
-   $rm conftest*
+   $RM conftest*
 ])
 
 if test x"[$]$2" = xyes; then
-    ifelse([$5], , :, [$5])
+    m4_if([$5], , :, [$5])
 else
-    ifelse([$6], , :, [$6])
+    m4_if([$6], , :, [$6])
 fi
-])# AC_LIBTOOL_COMPILER_OPTION
-
+])# _LT_COMPILER_OPTION
 
-# AC_LIBTOOL_LINKER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
-#                          [ACTION-SUCCESS], [ACTION-FAILURE])
-# ------------------------------------------------------------
-# Check whether the given compiler option works
-AC_DEFUN([AC_LIBTOOL_LINKER_OPTION],
-[AC_CACHE_CHECK([$1], [$2],
+# Old name:
+AU_ALIAS([AC_LIBTOOL_COMPILER_OPTION], [_LT_COMPILER_OPTION])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION], [])
+
+
+# _LT_LINKER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
+#                  [ACTION-SUCCESS], [ACTION-FAILURE])
+# ----------------------------------------------------
+# Check whether the given linker option works
+AC_DEFUN([_LT_LINKER_OPTION],
+[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_DECL_SED])dnl
+AC_CACHE_CHECK([$1], [$2],
   [$2=no
    save_LDFLAGS="$LDFLAGS"
    LDFLAGS="$LDFLAGS $3"
-   printf "$lt_simple_link_test_code" > conftest.$ac_ext
+   echo "$lt_simple_link_test_code" > conftest.$ac_ext
    if (eval $ac_link 2>conftest.err) && test -s conftest$ac_exeext; then
-     # The compiler can only warn and ignore the option if not recognized
+     # The linker can only warn and ignore the option if not recognized
      # So say no if there are warnings
      if test -s conftest.err; then
        # Append any errors to the config.log.
        cat conftest.err 1>&AS_MESSAGE_LOG_FD
+       $ECHO "X$_lt_linker_boilerplate" | $Xsed -e '/^$/d' > conftest.exp
+       $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
+       if diff conftest.exp conftest.er2 >/dev/null; then
+         $2=yes
+       fi
      else
        $2=yes
      fi
    fi
-   $rm conftest*
+   $RM -r conftest*
    LDFLAGS="$save_LDFLAGS"
 ])
 
 if test x"[$]$2" = xyes; then
-    ifelse([$4], , :, [$4])
+    m4_if([$4], , :, [$4])
 else
-    ifelse([$5], , :, [$5])
+    m4_if([$5], , :, [$5])
 fi
-])# AC_LIBTOOL_LINKER_OPTION
+])# _LT_LINKER_OPTION
 
+# Old name:
+AU_ALIAS([AC_LIBTOOL_LINKER_OPTION], [_LT_LINKER_OPTION])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_LINKER_OPTION], [])
 
-# AC_LIBTOOL_SYS_MAX_CMD_LEN
-# --------------------------
-AC_DEFUN([AC_LIBTOOL_SYS_MAX_CMD_LEN],
-[# find the maximum length of command line arguments
+
+# LT_CMD_MAX_LEN
+#---------------
+AC_DEFUN([LT_CMD_MAX_LEN],
+[AC_REQUIRE([AC_CANONICAL_HOST])dnl
+# find the maximum length of command line arguments
 AC_MSG_CHECKING([the maximum length of command line arguments])
 AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [dnl
   i=0
-  testring="ABCD"
+  teststring="ABCD"
 
   case $build_os in
   msdosdjgpp*)
@@ -649,7 +1523,7 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [d
     lt_cv_sys_max_cmd_len=-1;
     ;;
 
-  cygwin* | mingw*)
+  cygwin* | mingw* | cegcc*)
     # On Win9x/ME, this test blows up -- it succeeds, but takes
     # about 5 minutes as the teststring grows exponentially.
     # Worse, since 9x/ME are not pre-emptively multitasking,
@@ -660,24 +1534,85 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [d
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
- *)
-    # If test is not a shell built-in, we'll probably end up computing a
-    # maximum length that is only half of the actual maximum length, but
-    # we can't tell.
-    while (test "X"`$CONFIG_SHELL [$]0 --fallback-echo "X$testring" 2>/dev/null` \
-	       = "XX$testring") >/dev/null 2>&1 &&
-	    new_result=`expr "X$testring" : ".*" 2>&1` &&
-	    lt_cv_sys_max_cmd_len=$new_result &&
-	    test $i != 17 # 1/2 MB should be enough
-    do
-      i=`expr $i + 1`
-      testring=$testring$testring
-    done
-    testring=
-    # Add a significant safety factor because C++ compilers can tack on massive
-    # amounts of additional arguments before passing them to the linker.
-    # It appears as though 1/2 is a usable value.
-    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 2`
+  amigaos*)
+    # On AmigaOS with pdksh, this test takes hours, literally.
+    # So we just punt and use a minimum line length of 8192.
+    lt_cv_sys_max_cmd_len=8192;
+    ;;
+
+  netbsd* | freebsd* | openbsd* | darwin* | dragonfly*)
+    # This has been around since 386BSD, at least.  Likely further.
+    if test -x /sbin/sysctl; then
+      lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
+    elif test -x /usr/sbin/sysctl; then
+      lt_cv_sys_max_cmd_len=`/usr/sbin/sysctl -n kern.argmax`
+    else
+      lt_cv_sys_max_cmd_len=65536	# usable default for all BSDs
+    fi
+    # And add a safety zone
+    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
+    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
+    ;;
+
+  interix*)
+    # We know the value 262144 and hardcode it with a safety zone (like BSD)
+    lt_cv_sys_max_cmd_len=196608
+    ;;
+
+  osf*)
+    # Dr. Hans Ekkehard Plesser reports seeing a kernel panic running configure
+    # due to this test when exec_disable_arg_limit is 1 on Tru64. It is not
+    # nice to cause kernel panics so lets avoid the loop below.
+    # First set a reasonable default.
+    lt_cv_sys_max_cmd_len=16384
+    #
+    if test -x /sbin/sysconfig; then
+      case `/sbin/sysconfig -q proc exec_disable_arg_limit` in
+        *1*) lt_cv_sys_max_cmd_len=-1 ;;
+      esac
+    fi
+    ;;
+  sco3.2v5*)
+    lt_cv_sys_max_cmd_len=102400
+    ;;
+  sysv5* | sco5v6* | sysv4.2uw2*)
+    kargmax=`grep ARG_MAX /etc/conf/cf.d/stune 2>/dev/null`
+    if test -n "$kargmax"; then
+      lt_cv_sys_max_cmd_len=`echo $kargmax | sed 's/.*[[	 ]]//'`
+    else
+      lt_cv_sys_max_cmd_len=32768
+    fi
+    ;;
+  *)
+    lt_cv_sys_max_cmd_len=`(getconf ARG_MAX) 2> /dev/null`
+    if test -n "$lt_cv_sys_max_cmd_len"; then
+      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
+      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
+    else
+      # Make teststring a little bigger before we do anything with it.
+      # a 1K string should be a reasonable start.
+      for i in 1 2 3 4 5 6 7 8 ; do
+        teststring=$teststring$teststring
+      done
+      SHELL=${SHELL-${CONFIG_SHELL-/bin/sh}}
+      # If test is not a shell built-in, we'll probably end up computing a
+      # maximum length that is only half of the actual maximum length, but
+      # we can't tell.
+      while { test "X"`$SHELL [$]0 --fallback-echo "X$teststring$teststring" 2>/dev/null` \
+	         = "XX$teststring$teststring"; } >/dev/null 2>&1 &&
+	      test $i != 17 # 1/2 MB should be enough
+      do
+        i=`expr $i + 1`
+        teststring=$teststring$teststring
+      done
+      # Only check the string length outside the loop.
+      lt_cv_sys_max_cmd_len=`expr "X$teststring" : ".*" 2>&1`
+      teststring=
+      # Add a significant safety factor because C++ compilers can tack on
+      # massive amounts of additional arguments before passing them to the
+      # linker.  It appears as though 1/2 is a usable value.
+      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 2`
+    fi
     ;;
   esac
 ])
@@ -686,27 +1621,35 @@ if test -n $lt_cv_sys_max_cmd_len ; then
 else
   AC_MSG_RESULT(none)
 fi
-])# AC_LIBTOOL_SYS_MAX_CMD_LEN
+max_cmd_len=$lt_cv_sys_max_cmd_len
+_LT_DECL([], [max_cmd_len], [0],
+    [What is the maximum length of a command?])
+])# LT_CMD_MAX_LEN
 
+# Old name:
+AU_ALIAS([AC_LIBTOOL_SYS_MAX_CMD_LEN], [LT_CMD_MAX_LEN])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_SYS_MAX_CMD_LEN], [])
 
-# _LT_AC_CHECK_DLFCN
-# --------------------
-AC_DEFUN([_LT_AC_CHECK_DLFCN],
-[AC_CHECK_HEADERS(dlfcn.h)dnl
-])# _LT_AC_CHECK_DLFCN
+
+# _LT_HEADER_DLFCN
+# ----------------
+m4_defun([_LT_HEADER_DLFCN],
+[AC_CHECK_HEADERS([dlfcn.h], [], [], [AC_INCLUDES_DEFAULT])dnl
+])# _LT_HEADER_DLFCN
 
 
-# _LT_AC_TRY_DLOPEN_SELF (ACTION-IF-TRUE, ACTION-IF-TRUE-W-USCORE,
-#                           ACTION-IF-FALSE, ACTION-IF-CROSS-COMPILING)
-# ------------------------------------------------------------------
-AC_DEFUN([_LT_AC_TRY_DLOPEN_SELF],
-[AC_REQUIRE([_LT_AC_CHECK_DLFCN])dnl
+# _LT_TRY_DLOPEN_SELF (ACTION-IF-TRUE, ACTION-IF-TRUE-W-USCORE,
+#                      ACTION-IF-FALSE, ACTION-IF-CROSS-COMPILING)
+# ----------------------------------------------------------------
+m4_defun([_LT_TRY_DLOPEN_SELF],
+[m4_require([_LT_HEADER_DLFCN])dnl
 if test "$cross_compiling" = yes; then :
   [$4]
 else
   lt_dlunknown=0; lt_dlno_uscore=1; lt_dlneed_uscore=2
   lt_status=$lt_dlunknown
-  cat > conftest.$ac_ext <<EOF
+  cat > conftest.$ac_ext <<_LT_EOF
 [#line __oline__ "configure"
 #include "confdefs.h"
 
@@ -748,10 +1691,6 @@ else
 #  endif
 #endif
 
-#ifdef __cplusplus
-extern "C" void exit (int);
-#endif
-
 void fnord() { int i=42;}
 int main ()
 {
@@ -764,17 +1703,19 @@ int main ()
       else if (dlsym( self,"_fnord")) status = $lt_dlneed_uscore;
       /* dlclose (self); */
     }
+  else
+    puts (dlerror ());
 
-    exit (status);
+  return status;
 }]
-EOF
+_LT_EOF
   if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext} 2>/dev/null; then
-    (./conftest; exit; ) 2>/dev/null
+    (./conftest; exit; ) >&AS_MESSAGE_LOG_FD 2>/dev/null
     lt_status=$?
     case x$lt_status in
       x$lt_dlno_uscore) $1 ;;
       x$lt_dlneed_uscore) $2 ;;
-      x$lt_unknown|x*) $3 ;;
+      x$lt_dlunknown|x*) $3 ;;
     esac
   else :
     # compilation failed
@@ -782,13 +1723,13 @@ EOF
   fi
 fi
 rm -fr conftest*
-])# _LT_AC_TRY_DLOPEN_SELF
+])# _LT_TRY_DLOPEN_SELF
 
 
-# AC_LIBTOOL_DLOPEN_SELF
-# -------------------
-AC_DEFUN([AC_LIBTOOL_DLOPEN_SELF],
-[AC_REQUIRE([_LT_AC_CHECK_DLFCN])dnl
+# LT_SYS_DLOPEN_SELF
+# ------------------
+AC_DEFUN([LT_SYS_DLOPEN_SELF],
+[m4_require([_LT_HEADER_DLFCN])dnl
 if test "x$enable_dlopen" != xyes; then
   enable_dlopen=unknown
   enable_dlopen_self=unknown
@@ -804,15 +1745,15 @@ else
     lt_cv_dlopen_self=yes
     ;;
 
-  mingw* | pw32*)
+  mingw* | pw32* | cegcc*)
     lt_cv_dlopen="LoadLibrary"
     lt_cv_dlopen_libs=
-   ;;
+    ;;
 
   cygwin*)
     lt_cv_dlopen="dlopen"
     lt_cv_dlopen_libs=
-   ;;
+    ;;
 
   darwin*)
   # if libdl is installed we need to link against it
@@ -822,13 +1763,13 @@ else
     lt_cv_dlopen_libs=
     lt_cv_dlopen_self=yes
     ])
-   ;;
-    
+    ;;
+
   *)
     AC_CHECK_FUNC([shl_load],
 	  [lt_cv_dlopen="shl_load"],
       [AC_CHECK_LIB([dld], [shl_load],
-	    [lt_cv_dlopen="shl_load" lt_cv_dlopen_libs="-dld"],
+	    [lt_cv_dlopen="shl_load" lt_cv_dlopen_libs="-ldld"],
 	[AC_CHECK_FUNC([dlopen],
 	      [lt_cv_dlopen="dlopen"],
 	  [AC_CHECK_LIB([dl], [dlopen],
@@ -836,7 +1777,7 @@ else
 	    [AC_CHECK_LIB([svld], [dlopen],
 		  [lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-lsvld"],
 	      [AC_CHECK_LIB([dld], [dld_link],
-		    [lt_cv_dlopen="dld_link" lt_cv_dlopen_libs="-dld"])
+		    [lt_cv_dlopen="dld_link" lt_cv_dlopen_libs="-ldld"])
 	      ])
 	    ])
 	  ])
@@ -857,23 +1798,23 @@ else
     test "x$ac_cv_header_dlfcn_h" = xyes && CPPFLAGS="$CPPFLAGS -DHAVE_DLFCN_H"
 
     save_LDFLAGS="$LDFLAGS"
-    eval LDFLAGS=\"\$LDFLAGS $export_dynamic_flag_spec\"
+    wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $export_dynamic_flag_spec\"
 
     save_LIBS="$LIBS"
     LIBS="$lt_cv_dlopen_libs $LIBS"
 
     AC_CACHE_CHECK([whether a program can dlopen itself],
 	  lt_cv_dlopen_self, [dnl
-	  _LT_AC_TRY_DLOPEN_SELF(
+	  _LT_TRY_DLOPEN_SELF(
 	    lt_cv_dlopen_self=yes, lt_cv_dlopen_self=yes,
 	    lt_cv_dlopen_self=no, lt_cv_dlopen_self=cross)
     ])
 
     if test "x$lt_cv_dlopen_self" = xyes; then
-      LDFLAGS="$LDFLAGS $link_static_flag"
+      wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $lt_prog_compiler_static\"
       AC_CACHE_CHECK([whether a statically linked program can dlopen itself],
-    	  lt_cv_dlopen_self_static, [dnl
-	  _LT_AC_TRY_DLOPEN_SELF(
+	  lt_cv_dlopen_self_static, [dnl
+	  _LT_TRY_DLOPEN_SELF(
 	    lt_cv_dlopen_self_static=yes, lt_cv_dlopen_self_static=yes,
 	    lt_cv_dlopen_self_static=no,  lt_cv_dlopen_self_static=cross)
       ])
@@ -895,29 +1836,36 @@ else
   *) enable_dlopen_self_static=unknown ;;
   esac
 fi
-])# AC_LIBTOOL_DLOPEN_SELF
+_LT_DECL([dlopen_support], [enable_dlopen], [0],
+	 [Whether dlopen is supported])
+_LT_DECL([dlopen_self], [enable_dlopen_self], [0],
+	 [Whether dlopen of programs is supported])
+_LT_DECL([dlopen_self_static], [enable_dlopen_self_static], [0],
+	 [Whether dlopen of statically linked programs is supported])
+])# LT_SYS_DLOPEN_SELF
+
+# Old name:
+AU_ALIAS([AC_LIBTOOL_DLOPEN_SELF], [LT_SYS_DLOPEN_SELF])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_DLOPEN_SELF], [])
 
 
-# AC_LIBTOOL_PROG_CC_C_O([TAGNAME])
-# ---------------------------------
-# Check to see if options -c and -o are simultaneously supported by compiler
-AC_DEFUN([AC_LIBTOOL_PROG_CC_C_O],
-[AC_REQUIRE([_LT_AC_SYS_COMPILER])dnl
+# _LT_COMPILER_C_O([TAGNAME])
+# ---------------------------
+# Check to see if options -c and -o are simultaneously supported by compiler.
+# This macro does not hard code the compiler like AC_PROG_CC_C_O.
+m4_defun([_LT_COMPILER_C_O],
+[m4_require([_LT_DECL_SED])dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_TAG_COMPILER])dnl
 AC_CACHE_CHECK([if $compiler supports -c -o file.$ac_objext],
-  [_LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)],
-  [_LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)=no
-   $rm -r conftest 2>/dev/null
+  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)],
+  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=no
+   $RM -r conftest 2>/dev/null
    mkdir conftest
    cd conftest
    mkdir out
-   printf "$lt_simple_compile_test_code" > conftest.$ac_ext
-
-   # According to Tom Tromey, Ian Lance Taylor reported there are C compilers
-   # that will create temporary files in the current directory regardless of
-   # the output directory.  Thus, making CWD read-only will cause this test
-   # to fail, enabling locking or at least warning the user not to do parallel
-   # builds.
-   chmod -w .
+   echo "$lt_simple_compile_test_code" > conftest.$ac_ext
 
    lt_compiler_flag="-o out/conftest2.$ac_objext"
    # Insert the option either (1) after the last *FLAGS variable, or
@@ -925,7 +1873,7 @@ AC_CACHE_CHECK([if $compiler supports -c
    # Note that $ac_compile itself does not contain backslashes and begins
    # with a dollar sign (not a hyphen), so the echo should work correctly.
    lt_compile=`echo "$ac_compile" | $SED \
-   -e 's:.*FLAGS}? :&$lt_compiler_flag :; t' \
+   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
    -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
    -e 's:$: $lt_compiler_flag:'`
    (eval echo "\"\$as_me:__oline__: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
@@ -937,32 +1885,41 @@ AC_CACHE_CHECK([if $compiler supports -c
    then
      # The compiler can only warn and ignore the option if not recognized
      # So say no if there are warnings
-     if test ! -s out/conftest.err; then
-       _LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
+     $ECHO "X$_lt_compiler_boilerplate" | $Xsed -e '/^$/d' > out/conftest.exp
+     $SED '/^$/d; /^ *+/d' out/conftest.err >out/conftest.er2
+     if test ! -s out/conftest.er2 || diff out/conftest.exp out/conftest.er2 >/dev/null; then
+       _LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
      fi
    fi
-   chmod u+w .
-   $rm conftest* out/*
-   rmdir out
+   chmod u+w . 2>&AS_MESSAGE_LOG_FD
+   $RM conftest*
+   # SGI C++ compiler will create directory out/ii_files/ for
+   # template instantiation
+   test -d out/ii_files && $RM out/ii_files/* && rmdir out/ii_files
+   $RM out/* && rmdir out
    cd ..
-   rmdir conftest
-   $rm conftest*
+   $RM -r conftest
+   $RM conftest*
 ])
-])# AC_LIBTOOL_PROG_CC_C_O
+_LT_TAGDECL([compiler_c_o], [lt_cv_prog_compiler_c_o], [1],
+	[Does compiler simultaneously support -c and -o options?])
+])# _LT_COMPILER_C_O
 
 
-# AC_LIBTOOL_SYS_HARD_LINK_LOCKS([TAGNAME])
-# -----------------------------------------
+# _LT_COMPILER_FILE_LOCKS([TAGNAME])
+# ----------------------------------
 # Check to see if we can do hard links to lock some files if needed
-AC_DEFUN([AC_LIBTOOL_SYS_HARD_LINK_LOCKS],
-[AC_REQUIRE([_LT_AC_LOCK])dnl
+m4_defun([_LT_COMPILER_FILE_LOCKS],
+[m4_require([_LT_ENABLE_LOCK])dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+_LT_COMPILER_C_O([$1])
 
 hard_links="nottested"
-if test "$_LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)" = no && test "$need_locks" != no; then
+if test "$_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)" = no && test "$need_locks" != no; then
   # do not overwrite the value of need_locks provided by the user
   AC_MSG_CHECKING([if we can lock with hard links])
   hard_links=yes
-  $rm conftest*
+  $RM conftest*
   ln conftest.a conftest.b 2>/dev/null && hard_links=no
   touch conftest.a
   ln conftest.a conftest.b 2>&5 || hard_links=no
@@ -975,12 +1932,13 @@ if test "$_LT_AC_TAGVAR(lt_cv_prog_compi
 else
   need_locks=no
 fi
-])# AC_LIBTOOL_SYS_HARD_LINK_LOCKS
+_LT_DECL([], [need_locks], [1], [Must we lock files when doing compilation?])
+])# _LT_COMPILER_FILE_LOCKS
 
 
-# AC_LIBTOOL_OBJDIR
-# -----------------
-AC_DEFUN([AC_LIBTOOL_OBJDIR],
+# _LT_CHECK_OBJDIR
+# ----------------
+m4_defun([_LT_CHECK_OBJDIR],
 [AC_CACHE_CHECK([for objdir], [lt_cv_objdir],
 [rm -f .libs 2>/dev/null
 mkdir .libs 2>/dev/null
@@ -992,40 +1950,46 @@ else
 fi
 rmdir .libs 2>/dev/null])
 objdir=$lt_cv_objdir
-])# AC_LIBTOOL_OBJDIR
+_LT_DECL([], [objdir], [0],
+         [The name of the directory that contains temporary libtool files])dnl
+m4_pattern_allow([LT_OBJDIR])dnl
+AC_DEFINE_UNQUOTED(LT_OBJDIR, "$lt_cv_objdir/",
+  [Define to the sub-directory in which libtool stores uninstalled libraries.])
+])# _LT_CHECK_OBJDIR
 
 
-# AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH([TAGNAME])
-# ----------------------------------------------
+# _LT_LINKER_HARDCODE_LIBPATH([TAGNAME])
+# --------------------------------------
 # Check hardcoding attributes.
-AC_DEFUN([AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH],
+m4_defun([_LT_LINKER_HARDCODE_LIBPATH],
 [AC_MSG_CHECKING([how to hardcode library paths into programs])
-_LT_AC_TAGVAR(hardcode_action, $1)=
-if test -n "$_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)" || \
-   test -n "$_LT_AC_TAGVAR(runpath_var $1)" || \
-   test "X$_LT_AC_TAGVAR(hardcode_automatic, $1)"="Xyes" ; then
+_LT_TAGVAR(hardcode_action, $1)=
+if test -n "$_LT_TAGVAR(hardcode_libdir_flag_spec, $1)" ||
+   test -n "$_LT_TAGVAR(runpath_var, $1)" ||
+   test "X$_LT_TAGVAR(hardcode_automatic, $1)" = "Xyes" ; then
 
-  # We can hardcode non-existant directories.
-  if test "$_LT_AC_TAGVAR(hardcode_direct, $1)" != no &&
+  # We can hardcode non-existent directories.
+  if test "$_LT_TAGVAR(hardcode_direct, $1)" != no &&
      # If the only mechanism to avoid hardcoding is shlibpath_var, we
      # have to relink, otherwise we might link with an installed library
      # when we should be linking with a yet-to-be-installed one
-     ## test "$_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)" != no &&
-     test "$_LT_AC_TAGVAR(hardcode_minus_L, $1)" != no; then
+     ## test "$_LT_TAGVAR(hardcode_shlibpath_var, $1)" != no &&
+     test "$_LT_TAGVAR(hardcode_minus_L, $1)" != no; then
     # Linking always hardcodes the temporary library directory.
-    _LT_AC_TAGVAR(hardcode_action, $1)=relink
+    _LT_TAGVAR(hardcode_action, $1)=relink
   else
     # We can link without hardcoding, and we can hardcode nonexisting dirs.
-    _LT_AC_TAGVAR(hardcode_action, $1)=immediate
+    _LT_TAGVAR(hardcode_action, $1)=immediate
   fi
 else
   # We cannot hardcode anything, or else we can only hardcode existing
   # directories.
-  _LT_AC_TAGVAR(hardcode_action, $1)=unsupported
+  _LT_TAGVAR(hardcode_action, $1)=unsupported
 fi
-AC_MSG_RESULT([$_LT_AC_TAGVAR(hardcode_action, $1)])
+AC_MSG_RESULT([$_LT_TAGVAR(hardcode_action, $1)])
 
-if test "$_LT_AC_TAGVAR(hardcode_action, $1)" = relink; then
+if test "$_LT_TAGVAR(hardcode_action, $1)" = relink ||
+   test "$_LT_TAGVAR(inherit_rpath, $1)" = yes; then
   # Fast installation is not supported
   enable_fast_install=no
 elif test "$shlibpath_overrides_runpath" = yes ||
@@ -1033,47 +1997,111 @@ elif test "$shlibpath_overrides_runpath"
   # Fast installation is not necessary
   enable_fast_install=needless
 fi
-])# AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH
+_LT_TAGDECL([], [hardcode_action], [0],
+    [How to hardcode a shared library path into an executable])
+])# _LT_LINKER_HARDCODE_LIBPATH
 
 
-# AC_LIBTOOL_SYS_LIB_STRIP
-# ------------------------
-AC_DEFUN([AC_LIBTOOL_SYS_LIB_STRIP],
-[striplib=
+# _LT_CMD_STRIPLIB
+# ----------------
+m4_defun([_LT_CMD_STRIPLIB],
+[m4_require([_LT_DECL_EGREP])
+striplib=
 old_striplib=
 AC_MSG_CHECKING([whether stripping libraries is possible])
-if test -n "$STRIP" && $STRIP -V 2>&1 | grep "GNU strip" >/dev/null; then
+if test -n "$STRIP" && $STRIP -V 2>&1 | $GREP "GNU strip" >/dev/null; then
   test -z "$old_striplib" && old_striplib="$STRIP --strip-debug"
   test -z "$striplib" && striplib="$STRIP --strip-unneeded"
   AC_MSG_RESULT([yes])
 else
 # FIXME - insert some real tests, host_os isn't really good enough
   case $host_os in
-   darwin*)
-       if test -n "$STRIP" ; then
-         striplib="$STRIP -x"
-         AC_MSG_RESULT([yes])
-       else
-  AC_MSG_RESULT([no])
-fi
-       ;;
-   *)
-  AC_MSG_RESULT([no])
+  darwin*)
+    if test -n "$STRIP" ; then
+      striplib="$STRIP -x"
+      old_striplib="$STRIP -S"
+      AC_MSG_RESULT([yes])
+    else
+      AC_MSG_RESULT([no])
+    fi
+    ;;
+  *)
+    AC_MSG_RESULT([no])
     ;;
-  esac  
+  esac
 fi
-])# AC_LIBTOOL_SYS_LIB_STRIP
+_LT_DECL([], [old_striplib], [1], [Commands to strip libraries])
+_LT_DECL([], [striplib], [1])
+])# _LT_CMD_STRIPLIB
 
 
-# AC_LIBTOOL_SYS_DYNAMIC_LINKER
+# _LT_SYS_DYNAMIC_LINKER([TAG])
 # -----------------------------
 # PORTME Fill in your ld.so characteristics
-AC_DEFUN([AC_LIBTOOL_SYS_DYNAMIC_LINKER],
-[AC_MSG_CHECKING([dynamic linker characteristics])
+m4_defun([_LT_SYS_DYNAMIC_LINKER],
+[AC_REQUIRE([AC_CANONICAL_HOST])dnl
+m4_require([_LT_DECL_EGREP])dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_DECL_OBJDUMP])dnl
+m4_require([_LT_DECL_SED])dnl
+AC_MSG_CHECKING([dynamic linker characteristics])
+m4_if([$1],
+	[], [
+if test "$GCC" = yes; then
+  case $host_os in
+    darwin*) lt_awk_arg="/^libraries:/,/LR/" ;;
+    *) lt_awk_arg="/^libraries:/" ;;
+  esac
+  lt_search_path_spec=`$CC -print-search-dirs | awk $lt_awk_arg | $SED -e "s/^libraries://" -e "s,=/,/,g"`
+  if $ECHO "$lt_search_path_spec" | $GREP ';' >/dev/null ; then
+    # if the path contains ";" then we assume it to be the separator
+    # otherwise default to the standard path separator (i.e. ":") - it is
+    # assumed that no part of a normal pathname contains ";" but that should
+    # okay in the real world where ";" in dirpaths is itself problematic.
+    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED -e 's/;/ /g'`
+  else
+    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED  -e "s/$PATH_SEPARATOR/ /g"`
+  fi
+  # Ok, now we have the path, separated by spaces, we can step through it
+  # and add multilib dir if necessary.
+  lt_tmp_lt_search_path_spec=
+  lt_multi_os_dir=`$CC $CPPFLAGS $CFLAGS $LDFLAGS -print-multi-os-directory 2>/dev/null`
+  for lt_sys_path in $lt_search_path_spec; do
+    if test -d "$lt_sys_path/$lt_multi_os_dir"; then
+      lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path/$lt_multi_os_dir"
+    else
+      test -d "$lt_sys_path" && \
+	lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path"
+    fi
+  done
+  lt_search_path_spec=`$ECHO $lt_tmp_lt_search_path_spec | awk '
+BEGIN {RS=" "; FS="/|\n";} {
+  lt_foo="";
+  lt_count=0;
+  for (lt_i = NF; lt_i > 0; lt_i--) {
+    if ($lt_i != "" && $lt_i != ".") {
+      if ($lt_i == "..") {
+        lt_count++;
+      } else {
+        if (lt_count == 0) {
+          lt_foo="/" $lt_i lt_foo;
+        } else {
+          lt_count--;
+        }
+      }
+    }
+  }
+  if (lt_foo != "") { lt_freq[[lt_foo]]++; }
+  if (lt_freq[[lt_foo]] == 1) { print lt_foo; }
+}'`
+  sys_lib_search_path_spec=`$ECHO $lt_search_path_spec`
+else
+  sys_lib_search_path_spec="/lib /usr/lib /usr/local/lib"
+fi])
 library_names_spec=
 libname_spec='lib$name'
 soname_spec=
-shrext=".so"
+shrext_cmds=".so"
 postinstall_cmds=
 postuninstall_cmds=
 finish_cmds=
@@ -1083,20 +2111,6 @@ shlibpath_overrides_runpath=unknown
 version_type=none
 dynamic_linker="$host_os ld.so"
 sys_lib_dlsearch_path_spec="/lib /usr/lib"
-if test "$GCC" = yes; then
-  sys_lib_search_path_spec=`$CC -print-search-dirs | grep "^libraries:" | $SED -e "s/^libraries://" -e "s,=/,/,g"`
-  if echo "$sys_lib_search_path_spec" | grep ';' >/dev/null ; then
-    # if the path contains ";" then we assume it to be the separator
-    # otherwise default to the standard path separator (i.e. ":") - it is
-    # assumed that no part of a normal pathname contains ";" but that should
-    # okay in the real world where ";" in dirpaths is itself problematic.
-    sys_lib_search_path_spec=`echo "$sys_lib_search_path_spec" | $SED -e 's/;/ /g'`
-  else
-    sys_lib_search_path_spec=`echo "$sys_lib_search_path_spec" | $SED  -e "s/$PATH_SEPARATOR/ /g"`
-  fi
-else
-  sys_lib_search_path_spec="/lib /usr/lib /usr/local/lib"
-fi
 need_lib_prefix=unknown
 hardcode_into_libs=no
 
@@ -1114,7 +2128,7 @@ aix3*)
   soname_spec='${libname}${release}${shared_ext}$major'
   ;;
 
-aix4* | aix5*)
+aix[[4-9]]*)
   version_type=linux
   need_lib_prefix=no
   need_version=no
@@ -1133,7 +2147,7 @@ aix4* | aix5*)
       aix4 | aix4.[[01]] | aix4.[[01]].*)
       if { echo '#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 97)'
 	   echo ' yes '
-	   echo '#endif'; } | ${CC} -E - | grep yes > /dev/null; then
+	   echo '#endif'; } | ${CC} -E - | $GREP yes > /dev/null; then
 	:
       else
 	can_build_shared=no
@@ -1159,9 +2173,18 @@ aix4* | aix5*)
   ;;
 
 amigaos*)
-  library_names_spec='$libname.ixlibrary $libname.a'
-  # Create ${libname}_ixlibrary.a entries in /sys/libs.
-  finish_eval='for lib in `ls $libdir/*.ixlibrary 2>/dev/null`; do libname=`$echo "X$lib" | $Xsed -e '\''s%^.*/\([[^/]]*\)\.ixlibrary$%\1%'\''`; test $rm /sys/libs/${libname}_ixlibrary.a; $show "(cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a)"; (cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a) || exit 1; done'
+  case $host_cpu in
+  powerpc)
+    # Since July 2007 AmigaOS4 officially supports .so libraries.
+    # When compiling the executable, add -use-dynld -Lsobjs: to the compileline.
+    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+    ;;
+  m68k)
+    library_names_spec='$libname.ixlibrary $libname.a'
+    # Create ${libname}_ixlibrary.a entries in /sys/libs.
+    finish_eval='for lib in `ls $libdir/*.ixlibrary 2>/dev/null`; do libname=`$ECHO "X$lib" | $Xsed -e '\''s%^.*/\([[^/]]*\)\.ixlibrary$%\1%'\''`; test $RM /sys/libs/${libname}_ixlibrary.a; $show "cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a"; cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a || exit 1; done'
+    ;;
+  esac
   ;;
 
 beos*)
@@ -1170,7 +2193,7 @@ beos*)
   shlibpath_var=LIBRARY_PATH
   ;;
 
-bsdi4*)
+bsdi[[45]]*)
   version_type=linux
   need_version=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
@@ -1184,51 +2207,55 @@ bsdi4*)
   # libtool to hard-code these into programs
   ;;
 
-cygwin* | mingw* | pw32*)
+cygwin* | mingw* | pw32* | cegcc*)
   version_type=windows
-  shrext=".dll"
+  shrext_cmds=".dll"
   need_version=no
   need_lib_prefix=no
 
   case $GCC,$host_os in
-  yes,cygwin* | yes,mingw* | yes,pw32*)
+  yes,cygwin* | yes,mingw* | yes,pw32* | yes,cegcc*)
     library_names_spec='$libname.dll.a'
     # DLL is installed to $(libdir)/../bin by postinstall_cmds
     postinstall_cmds='base_file=`basename \${file}`~
-      dlpath=`$SHELL 2>&1 -c '\''. $dir/'\''\${base_file}'\''i;echo \$dlname'\''`~
+      dlpath=`$SHELL 2>&1 -c '\''. $dir/'\''\${base_file}'\''i; echo \$dlname'\''`~
       dldir=$destdir/`dirname \$dlpath`~
       test -d \$dldir || mkdir -p \$dldir~
-      $install_prog $dir/$dlname \$dldir/$dlname'
+      $install_prog $dir/$dlname \$dldir/$dlname~
+      chmod a+x \$dldir/$dlname~
+      if test -n '\''$stripme'\'' && test -n '\''$striplib'\''; then
+        eval '\''$striplib \$dldir/$dlname'\'' || exit \$?;
+      fi'
     postuninstall_cmds='dldll=`$SHELL 2>&1 -c '\''. $file; echo \$dlname'\''`~
       dlpath=$dir/\$dldll~
-       $rm \$dlpath'
+       $RM \$dlpath'
     shlibpath_overrides_runpath=yes
 
     case $host_os in
     cygwin*)
       # Cygwin DLLs use 'cyg' prefix rather than 'lib'
       soname_spec='`echo ${libname} | sed -e 's/^lib/cyg/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
-      sys_lib_search_path_spec="/lib /lib/w32api /usr/lib /usr/local/lib"
+      sys_lib_search_path_spec="/usr/lib /lib/w32api /lib /usr/local/lib"
       ;;
-    mingw*)
+    mingw* | cegcc*)
       # MinGW DLLs use traditional 'lib' prefix
       soname_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
-      sys_lib_search_path_spec=`$CC -print-search-dirs | grep "^libraries:" | $SED -e "s/^libraries://" -e "s,=/,/,g"`
-      if echo "$sys_lib_search_path_spec" | [grep ';[c-zC-Z]:/' >/dev/null]; then
+      sys_lib_search_path_spec=`$CC -print-search-dirs | $GREP "^libraries:" | $SED -e "s/^libraries://" -e "s,=/,/,g"`
+      if $ECHO "$sys_lib_search_path_spec" | [$GREP ';[c-zC-Z]:/' >/dev/null]; then
         # It is most probably a Windows format PATH printed by
         # mingw gcc, but we are running on Cygwin. Gcc prints its search
         # path with ; separators, and with drive letters. We can handle the
         # drive letters (cygwin fileutils understands them), so leave them,
         # especially as we might pass files found there to a mingw objdump,
         # which wouldn't understand a cygwinified path. Ahh.
-        sys_lib_search_path_spec=`echo "$sys_lib_search_path_spec" | $SED -e 's/;/ /g'`
+        sys_lib_search_path_spec=`$ECHO "$sys_lib_search_path_spec" | $SED -e 's/;/ /g'`
       else
-        sys_lib_search_path_spec=`echo "$sys_lib_search_path_spec" | $SED  -e "s/$PATH_SEPARATOR/ /g"`
+        sys_lib_search_path_spec=`$ECHO "$sys_lib_search_path_spec" | $SED  -e "s/$PATH_SEPARATOR/ /g"`
       fi
       ;;
     pw32*)
       # pw32 DLLs use 'pw' prefix rather than 'lib'
-      library_names_spec='`echo ${libname} | sed -e 's/^lib/pw/'``echo ${release} | $SED -e 's/[.]/-/g'`${versuffix}${shared_ext}'
+      library_names_spec='`echo ${libname} | sed -e 's/^lib/pw/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
       ;;
     esac
     ;;
@@ -1247,18 +2274,13 @@ darwin* | rhapsody*)
   version_type=darwin
   need_lib_prefix=no
   need_version=no
-  # FIXME: Relying on posixy $() will cause problems for
-  #        cross-compilation, but unfortunately the echo tests do not
-  #        yet detect zsh echo's removal of \ escapes.
-  library_names_spec='${libname}${release}${versuffix}$shared_ext ${libname}${release}${major}$shared_ext ${libname}$shared_ext'
+  library_names_spec='${libname}${release}${major}$shared_ext ${libname}$shared_ext'
   soname_spec='${libname}${release}${major}$shared_ext'
   shlibpath_overrides_runpath=yes
   shlibpath_var=DYLD_LIBRARY_PATH
-  shrext='$(test .$module = .yes && echo .so || echo .dylib)'
-  # Apple's gcc prints 'gcc -print-search-dirs' doesn't operate the same.
-  if $CC -v 2>&1 | grep 'Apple' >/dev/null ; then 
-  sys_lib_search_path_spec=`$CC -print-search-dirs | tr "\n" "$PATH_SEPARATOR" | sed -e 's/libraries:/@libraries:/' | tr "@" "\n" | grep "^libraries:" | sed -e "s/^libraries://" -e "s,=/,/,g" -e "s,$PATH_SEPARATOR, ,g" -e "s,.*,& /lib /usr/lib /usr/local/lib,g"`
-  fi
+  shrext_cmds='`test .$module = .yes && echo .so || echo .dylib`'
+m4_if([$1], [],[
+  sys_lib_search_path_spec="$sys_lib_search_path_spec /usr/local/lib"])
   sys_lib_dlsearch_path_spec='/usr/local/lib /lib /usr/lib'
   ;;
 
@@ -1275,8 +2297,17 @@ freebsd1*)
   dynamic_linker=no
   ;;
 
-freebsd*)
-  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
+freebsd* | dragonfly*)
+  # DragonFly does not have aout.  When/if they implement a new
+  # versioning mechanism, adjust this.
+  if test -x /usr/bin/objformat; then
+    objformat=`/usr/bin/objformat`
+  else
+    case $host_os in
+    freebsd[[123]]*) objformat=aout ;;
+    *) objformat=elf ;;
+    esac
+  fi
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
@@ -1294,14 +2325,19 @@ freebsd*)
   freebsd2*)
     shlibpath_overrides_runpath=yes
     ;;
-  freebsd3.[01]* | freebsdelf3.[01]*)
+  freebsd3.[[01]]* | freebsdelf3.[[01]]*)
     shlibpath_overrides_runpath=yes
     hardcode_into_libs=yes
     ;;
-  *) # from 3.2 on
+  freebsd3.[[2-9]]* | freebsdelf3.[[2-9]]* | \
+  freebsd4.[[0-5]] | freebsdelf4.[[0-5]] | freebsd4.1.1 | freebsdelf4.1.1)
     shlibpath_overrides_runpath=no
     hardcode_into_libs=yes
     ;;
+  *) # from 4.6 on, and DragonFly
+    shlibpath_overrides_runpath=yes
+    hardcode_into_libs=yes
+    ;;
   esac
   ;;
 
@@ -1321,9 +2357,9 @@ hpux9* | hpux10* | hpux11*)
   version_type=sunos
   need_lib_prefix=no
   need_version=no
-  case "$host_cpu" in
+  case $host_cpu in
   ia64*)
-    shrext='.so'
+    shrext_cmds='.so'
     hardcode_into_libs=yes
     dynamic_linker="$host_os dld.so"
     shlibpath_var=LD_LIBRARY_PATH
@@ -1337,19 +2373,19 @@ hpux9* | hpux10* | hpux11*)
     fi
     sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
     ;;
-   hppa*64*)
-     shrext='.sl'
-     hardcode_into_libs=yes
-     dynamic_linker="$host_os dld.sl"
-     shlibpath_var=LD_LIBRARY_PATH # How should we handle SHLIB_PATH
-     shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
-     library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
-     soname_spec='${libname}${release}${shared_ext}$major'
-     sys_lib_search_path_spec="/usr/lib/pa20_64 /usr/ccs/lib/pa20_64"
-     sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
-     ;;
-   *)
-    shrext='.sl'
+  hppa*64*)
+    shrext_cmds='.sl'
+    hardcode_into_libs=yes
+    dynamic_linker="$host_os dld.sl"
+    shlibpath_var=LD_LIBRARY_PATH # How should we handle SHLIB_PATH
+    shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
+    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+    soname_spec='${libname}${release}${shared_ext}$major'
+    sys_lib_search_path_spec="/usr/lib/pa20_64 /usr/ccs/lib/pa20_64"
+    sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
+    ;;
+  *)
+    shrext_cmds='.sl'
     dynamic_linker="$host_os dld.sl"
     shlibpath_var=SHLIB_PATH
     shlibpath_overrides_runpath=no # +s is required to enable SHLIB_PATH
@@ -1361,6 +2397,18 @@ hpux9* | hpux10* | hpux11*)
   postinstall_cmds='chmod 555 $lib'
   ;;
 
+interix[[3-9]]*)
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='Interix 3.x ld.so.1 (PE, like ELF)'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $host_os in
     nonstopux*) version_type=nonstopux ;;
@@ -1404,7 +2452,7 @@ linux*oldld* | linux*aout* | linux*coff*
   ;;
 
 # This must be Linux ELF.
-linux*)
+linux* | k*bsd*-gnu)
   version_type=linux
   need_lib_prefix=no
   need_version=no
@@ -1413,11 +2461,28 @@ linux*)
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -n $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   shlibpath_overrides_runpath=no
+  # Some binutils ld are patched to set DT_RUNPATH
+  save_LDFLAGS=$LDFLAGS
+  save_libdir=$libdir
+  eval "libdir=/foo; wl=\"$_LT_TAGVAR(lt_prog_compiler_wl, $1)\"; \
+       LDFLAGS=\"\$LDFLAGS $_LT_TAGVAR(hardcode_libdir_flag_spec, $1)\""
+  AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
+    [AS_IF([ ($OBJDUMP -p conftest$ac_exeext) 2>/dev/null | grep "RUNPATH.*$libdir" >/dev/null],
+       [shlibpath_overrides_runpath=yes])])
+  LDFLAGS=$save_LDFLAGS
+  libdir=$save_libdir
+
   # This implies no fast_install, which is unacceptable.
   # Some rework will be needed to allow for fast_install
   # before this can be enabled.
   hardcode_into_libs=yes
 
+  # Append ld.so.conf contents to the search path
+  if test -f /etc/ld.so.conf; then
+    lt_ld_extra=`awk '/^include / { system(sprintf("cd /etc; cat %s 2>/dev/null", \[$]2)); skip = 1; } { if (!skip) print \[$]0; skip = 0; }' < /etc/ld.so.conf | $SED -e 's/#.*//;/^[	 ]*hwcap[	 ]/d;s/[:,	]/ /g;s/=[^=]*$//;s/=[^= ]* / /g;/^$/d' | tr '\n' ' '`
+    sys_lib_dlsearch_path_spec="/lib /usr/lib $lt_ld_extra"
+  fi
+
   # We used to test for /lib/ld.so.1 and disable shared libraries on
   # powerpc, because MkLinux only supported shared libraries with the
   # GNU dynamic linker.  Since this was broken with cross compilers,
@@ -1431,12 +2496,12 @@ netbsd*)
   version_type=sunos
   need_lib_prefix=no
   need_version=no
-  if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
+  if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
     library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
     finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
     dynamic_linker='NetBSD (a.out) ld.so'
   else
-    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${release}${shared_ext} ${libname}${shared_ext}'
+    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
     soname_spec='${libname}${release}${shared_ext}$major'
     dynamic_linker='NetBSD ld.elf_so'
   fi
@@ -1452,24 +2517,31 @@ newsos6)
   shlibpath_overrides_runpath=yes
   ;;
 
-nto-qnx)
-  version_type=linux
+*nto* | *qnx*)
+  version_type=qnx
   need_lib_prefix=no
   need_version=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
   shlibpath_var=LD_LIBRARY_PATH
-  shlibpath_overrides_runpath=yes
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  dynamic_linker='ldqnx.so'
   ;;
 
 openbsd*)
   version_type=sunos
+  sys_lib_dlsearch_path_spec="/usr/lib"
   need_lib_prefix=no
-  need_version=no
+  # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
+  case $host_os in
+    openbsd3.3 | openbsd3.3.*)	need_version=yes ;;
+    *)				need_version=no  ;;
+  esac
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
-  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
+  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
     case $host_os in
       openbsd2.[[89]] | openbsd2.[[89]].*)
 	shlibpath_overrides_runpath=no
@@ -1485,7 +2557,7 @@ openbsd*)
 
 os2*)
   libname_spec='$name'
-  shrext=".dll"
+  shrext_cmds=".dll"
   need_lib_prefix=no
   library_names_spec='$libname${shared_ext} $libname.a'
   dynamic_linker='OS/2 ld.exe'
@@ -1503,11 +2575,8 @@ osf3* | osf4* | osf5*)
   sys_lib_dlsearch_path_spec="$sys_lib_search_path_spec"
   ;;
 
-sco3.2v5*)
-  version_type=osf
-  soname_spec='${libname}${release}${shared_ext}$major'
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
-  shlibpath_var=LD_LIBRARY_PATH
+rdos*)
+  dynamic_linker=no
   ;;
 
 solaris*)
@@ -1535,7 +2604,7 @@ sunos4*)
   need_version=yes
   ;;
 
-sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
+sysv4 | sysv4.3*)
   version_type=linux
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
@@ -1544,7 +2613,6 @@ sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
     sni)
       shlibpath_overrides_runpath=no
       need_lib_prefix=no
-      export_dynamic_flag_spec='${wl}-Blargedynsym'
       runpath_var=LD_RUN_PATH
       ;;
     siemens)
@@ -1568,6 +2636,39 @@ sysv4*MP*)
   fi
   ;;
 
+sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
+  version_type=freebsd-elf
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=yes
+  hardcode_into_libs=yes
+  if test "$with_gnu_ld" = yes; then
+    sys_lib_search_path_spec='/usr/local/lib /usr/gnu/lib /usr/ccs/lib /usr/lib /lib'
+  else
+    sys_lib_search_path_spec='/usr/ccs/lib /usr/lib'
+    case $host_os in
+      sco3.2v5*)
+        sys_lib_search_path_spec="$sys_lib_search_path_spec /lib"
+	;;
+    esac
+  fi
+  sys_lib_dlsearch_path_spec='/usr/lib'
+  ;;
+
+tpf*)
+  # TPF is a cross-target only.  Preferred cross-host = GNU/Linux.
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  ;;
+
 uts4*)
   version_type=linux
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
@@ -1581,271 +2682,59 @@ uts4*)
 esac
 AC_MSG_RESULT([$dynamic_linker])
 test "$dynamic_linker" = no && can_build_shared=no
-])# AC_LIBTOOL_SYS_DYNAMIC_LINKER
-
-
-# _LT_AC_TAGCONFIG
-# ----------------
-AC_DEFUN([_LT_AC_TAGCONFIG],
-[AC_ARG_WITH([tags],
-    [AC_HELP_STRING([--with-tags@<:@=TAGS@:>@],
-        [include additional configurations @<:@automatic@:>@])],
-    [tagnames="$withval"])
-
-if test -f "$ltmain" && test -n "$tagnames"; then
-  if test ! -f "${ofile}"; then
-    AC_MSG_WARN([output file `$ofile' does not exist])
-  fi
-
-  if test -z "$LTCC"; then
-    eval "`$SHELL ${ofile} --config | grep '^LTCC='`"
-    if test -z "$LTCC"; then
-      AC_MSG_WARN([output file `$ofile' does not look like a libtool script])
-    else
-      AC_MSG_WARN([using `LTCC=$LTCC', extracted from `$ofile'])
-    fi
-  fi
-
-  # Extract list of available tagged configurations in $ofile.
-  # Note that this assumes the entire list is on one line.
-  available_tags=`grep "^available_tags=" "${ofile}" | $SED -e 's/available_tags=\(.*$\)/\1/' -e 's/\"//g'`
-
-  lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
-  for tagname in $tagnames; do
-    IFS="$lt_save_ifs"
-    # Check whether tagname contains only valid characters
-    case `$echo "X$tagname" | $Xsed -e 's:[[-_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,/]]::g'` in
-    "") ;;
-    *)  AC_MSG_ERROR([invalid tag name: $tagname])
-	;;
-    esac
-
-    if grep "^# ### BEGIN LIBTOOL TAG CONFIG: $tagname$" < "${ofile}" > /dev/null
-    then
-      AC_MSG_ERROR([tag name \"$tagname\" already exists])
-    fi
-
-    # Update the list of available tags.
-    if test -n "$tagname"; then
-      echo appending configuration tag \"$tagname\" to $ofile
-
-      case $tagname in
-      CXX)
-	if test -n "$CXX" && test "X$CXX" != "Xno"; then
-	  AC_LIBTOOL_LANG_CXX_CONFIG
-	else
-	  tagname=""
-	fi
-	;;
-
-      F77)
-	if test -n "$F77" && test "X$F77" != "Xno"; then
-	  AC_LIBTOOL_LANG_F77_CONFIG
-	else
-	  tagname=""
-	fi
-	;;
 
-      GCJ)
-	if test -n "$GCJ" && test "X$GCJ" != "Xno"; then
-	  AC_LIBTOOL_LANG_GCJ_CONFIG
-	else
-	  tagname=""
-	fi
-	;;
-
-      RC)
-	AC_LIBTOOL_LANG_RC_CONFIG
-	;;
-
-      *)
-	AC_MSG_ERROR([Unsupported tag name: $tagname])
-	;;
-      esac
-
-      # Append the new tag name to the list of available tags.
-      if test -n "$tagname" ; then
-      available_tags="$available_tags $tagname"
-    fi
-    fi
-  done
-  IFS="$lt_save_ifs"
-
-  # Now substitute the updated list of available tags.
-  if eval "sed -e 's/^available_tags=.*\$/available_tags=\"$available_tags\"/' \"$ofile\" > \"${ofile}T\""; then
-    mv "${ofile}T" "$ofile"
-    chmod +x "$ofile"
-  else
-    rm -f "${ofile}T"
-    AC_MSG_ERROR([unable to update list of available tagged configurations.])
-  fi
+variables_saved_for_relink="PATH $shlibpath_var $runpath_var"
+if test "$GCC" = yes; then
+  variables_saved_for_relink="$variables_saved_for_relink GCC_EXEC_PREFIX COMPILER_PATH LIBRARY_PATH"
 fi
-])# _LT_AC_TAGCONFIG
-
-
-# AC_LIBTOOL_DLOPEN
-# -----------------
-# enable checks for dlopen support
-AC_DEFUN([AC_LIBTOOL_DLOPEN],
- [AC_BEFORE([$0],[AC_LIBTOOL_SETUP])
-])# AC_LIBTOOL_DLOPEN
-
-
-# AC_LIBTOOL_WIN32_DLL
-# --------------------
-# declare package support for building win32 dll's
-AC_DEFUN([AC_LIBTOOL_WIN32_DLL],
-[AC_BEFORE([$0], [AC_LIBTOOL_SETUP])
-])# AC_LIBTOOL_WIN32_DLL
-
-
-# AC_ENABLE_SHARED([DEFAULT])
-# ---------------------------
-# implement the --enable-shared flag
-# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
-AC_DEFUN([AC_ENABLE_SHARED],
-[define([AC_ENABLE_SHARED_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE([shared],
-    [AC_HELP_STRING([--enable-shared@<:@=PKGS@:>@],
-	[build shared libraries @<:@default=]AC_ENABLE_SHARED_DEFAULT[@:>@])],
-    [p=${PACKAGE-default}
-    case $enableval in
-    yes) enable_shared=yes ;;
-    no) enable_shared=no ;;
-    *)
-      enable_shared=no
-      # Look at the argument we got.  We use all the common list separators.
-      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
-      for pkg in $enableval; do
-	IFS="$lt_save_ifs"
-	if test "X$pkg" = "X$p"; then
-	  enable_shared=yes
-	fi
-      done
-      IFS="$lt_save_ifs"
-      ;;
-    esac],
-    [enable_shared=]AC_ENABLE_SHARED_DEFAULT)
-])# AC_ENABLE_SHARED
-
-
-# AC_DISABLE_SHARED
-# -----------------
-#- set the default shared flag to --disable-shared
-AC_DEFUN([AC_DISABLE_SHARED],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_SHARED(no)
-])# AC_DISABLE_SHARED
-
-
-# AC_ENABLE_STATIC([DEFAULT])
-# ---------------------------
-# implement the --enable-static flag
-# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
-AC_DEFUN([AC_ENABLE_STATIC],
-[define([AC_ENABLE_STATIC_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE([static],
-    [AC_HELP_STRING([--enable-static@<:@=PKGS@:>@],
-	[build static libraries @<:@default=]AC_ENABLE_STATIC_DEFAULT[@:>@])],
-    [p=${PACKAGE-default}
-    case $enableval in
-    yes) enable_static=yes ;;
-    no) enable_static=no ;;
-    *)
-     enable_static=no
-      # Look at the argument we got.  We use all the common list separators.
-      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
-      for pkg in $enableval; do
-	IFS="$lt_save_ifs"
-	if test "X$pkg" = "X$p"; then
-	  enable_static=yes
-	fi
-      done
-      IFS="$lt_save_ifs"
-      ;;
-    esac],
-    [enable_static=]AC_ENABLE_STATIC_DEFAULT)
-])# AC_ENABLE_STATIC
-
-
-# AC_DISABLE_STATIC
-# -----------------
-# set the default static flag to --disable-static
-AC_DEFUN([AC_DISABLE_STATIC],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_STATIC(no)
-])# AC_DISABLE_STATIC
-
-
-# AC_ENABLE_FAST_INSTALL([DEFAULT])
-# ---------------------------------
-# implement the --enable-fast-install flag
-# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
-AC_DEFUN([AC_ENABLE_FAST_INSTALL],
-[define([AC_ENABLE_FAST_INSTALL_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE([fast-install],
-    [AC_HELP_STRING([--enable-fast-install@<:@=PKGS@:>@],
-    [optimize for fast installation @<:@default=]AC_ENABLE_FAST_INSTALL_DEFAULT[@:>@])],
-    [p=${PACKAGE-default}
-    case $enableval in
-    yes) enable_fast_install=yes ;;
-    no) enable_fast_install=no ;;
-    *)
-      enable_fast_install=no
-      # Look at the argument we got.  We use all the common list separators.
-      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
-      for pkg in $enableval; do
-	IFS="$lt_save_ifs"
-	if test "X$pkg" = "X$p"; then
-	  enable_fast_install=yes
-	fi
-      done
-      IFS="$lt_save_ifs"
-      ;;
-    esac],
-    [enable_fast_install=]AC_ENABLE_FAST_INSTALL_DEFAULT)
-])# AC_ENABLE_FAST_INSTALL
 
+if test "${lt_cv_sys_lib_search_path_spec+set}" = set; then
+  sys_lib_search_path_spec="$lt_cv_sys_lib_search_path_spec"
+fi
+if test "${lt_cv_sys_lib_dlsearch_path_spec+set}" = set; then
+  sys_lib_dlsearch_path_spec="$lt_cv_sys_lib_dlsearch_path_spec"
+fi
 
-# AC_DISABLE_FAST_INSTALL
-# -----------------------
-# set the default to --disable-fast-install
-AC_DEFUN([AC_DISABLE_FAST_INSTALL],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_FAST_INSTALL(no)
-])# AC_DISABLE_FAST_INSTALL
+_LT_DECL([], [variables_saved_for_relink], [1],
+    [Variables whose values should be saved in libtool wrapper scripts and
+    restored at link time])
+_LT_DECL([], [need_lib_prefix], [0],
+    [Do we need the "lib" prefix for modules?])
+_LT_DECL([], [need_version], [0], [Do we need a version for libraries?])
+_LT_DECL([], [version_type], [0], [Library versioning type])
+_LT_DECL([], [runpath_var], [0],  [Shared library runtime path variable])
+_LT_DECL([], [shlibpath_var], [0],[Shared library path variable])
+_LT_DECL([], [shlibpath_overrides_runpath], [0],
+    [Is shlibpath searched before the hard-coded library search path?])
+_LT_DECL([], [libname_spec], [1], [Format of library name prefix])
+_LT_DECL([], [library_names_spec], [1],
+    [[List of archive names.  First name is the real one, the rest are links.
+    The last name is the one that the linker finds with -lNAME]])
+_LT_DECL([], [soname_spec], [1],
+    [[The coded name of the library, if different from the real name]])
+_LT_DECL([], [postinstall_cmds], [2],
+    [Command to use after installation of a shared archive])
+_LT_DECL([], [postuninstall_cmds], [2],
+    [Command to use after uninstallation of a shared archive])
+_LT_DECL([], [finish_cmds], [2],
+    [Commands used to finish a libtool library installation in a directory])
+_LT_DECL([], [finish_eval], [1],
+    [[As "finish_cmds", except a single script fragment to be evaled but
+    not shown]])
+_LT_DECL([], [hardcode_into_libs], [0],
+    [Whether we should hardcode library paths into libraries])
+_LT_DECL([], [sys_lib_search_path_spec], [2],
+    [Compile-time system search path for libraries])
+_LT_DECL([], [sys_lib_dlsearch_path_spec], [2],
+    [Run-time system search path for libraries])
+])# _LT_SYS_DYNAMIC_LINKER
 
 
-# AC_LIBTOOL_PICMODE([MODE])
+# _LT_PATH_TOOL_PREFIX(TOOL)
 # --------------------------
-# implement the --with-pic flag
-# MODE is either `yes' or `no'.  If omitted, it defaults to `both'.
-AC_DEFUN([AC_LIBTOOL_PICMODE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-pic_mode=ifelse($#,1,$1,default)
-])# AC_LIBTOOL_PICMODE
-
-
-# AC_PROG_EGREP
-# -------------
-# This is predefined starting with Autoconf 2.54, so this conditional
-# definition can be removed once we require Autoconf 2.54 or later.
-m4_ifndef([AC_PROG_EGREP], [AC_DEFUN([AC_PROG_EGREP],
-[AC_CACHE_CHECK([for egrep], [ac_cv_prog_egrep],
-   [if echo a | (grep -E '(a|b)') >/dev/null 2>&1
-    then ac_cv_prog_egrep='grep -E'
-    else ac_cv_prog_egrep='egrep'
-    fi])
- EGREP=$ac_cv_prog_egrep
- AC_SUBST([EGREP])
-])])
-
-
-# AC_PATH_TOOL_PREFIX
-# -------------------
-# find a file program which can recognise shared library
-AC_DEFUN([AC_PATH_TOOL_PREFIX],
-[AC_REQUIRE([AC_PROG_EGREP])dnl
+# find a file program which can recognize shared library
+AC_DEFUN([_LT_PATH_TOOL_PREFIX],
+[m4_require([_LT_DECL_EGREP])dnl
 AC_MSG_CHECKING([for $1])
 AC_CACHE_VAL(lt_cv_path_MAGIC_CMD,
 [case $MAGIC_CMD in
@@ -1858,7 +2747,7 @@ AC_CACHE_VAL(lt_cv_path_MAGIC_CMD,
 dnl $ac_dummy forces splitting on constant user-supplied paths.
 dnl POSIX.2 word splitting is done only on the output of word expansions,
 dnl not every word.  This closes a longstanding sh security hole.
-  ac_dummy="ifelse([$2], , $PATH, [$2])"
+  ac_dummy="m4_if([$2], , $PATH, [$2])"
   for ac_dir in $ac_dummy; do
     IFS="$lt_save_ifs"
     test -z "$ac_dir" && ac_dir=.
@@ -1867,13 +2756,13 @@ dnl not every word.  This closes a longs
       if test -n "$file_magic_test_file"; then
 	case $deplibs_check_method in
 	"file_magic "*)
-	  file_magic_regex="`expr \"$deplibs_check_method\" : \"file_magic \(.*\)\"`"
+	  file_magic_regex=`expr "$deplibs_check_method" : "file_magic \(.*\)"`
 	  MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
 	  if eval $file_magic_cmd \$file_magic_test_file 2> /dev/null |
 	    $EGREP "$file_magic_regex" > /dev/null; then
 	    :
 	  else
-	    cat <<EOF 1>&2
+	    cat <<_LT_EOF 1>&2
 
 *** Warning: the command libtool uses to detect shared libraries,
 *** $file_magic_cmd, produces output that libtool cannot recognize.
@@ -1884,7 +2773,7 @@ dnl not every word.  This closes a longs
 *** may want to report the problem to your system manager and/or to
 *** bug-libtool@gnu.org
 
-EOF
+_LT_EOF
 	  fi ;;
 	esac
       fi
@@ -1901,37 +2790,47 @@ if test -n "$MAGIC_CMD"; then
 else
   AC_MSG_RESULT(no)
 fi
-])# AC_PATH_TOOL_PREFIX
+_LT_DECL([], [MAGIC_CMD], [0],
+	 [Used to examine libraries when file_magic_cmd begins with "file"])dnl
+])# _LT_PATH_TOOL_PREFIX
 
+# Old name:
+AU_ALIAS([AC_PATH_TOOL_PREFIX], [_LT_PATH_TOOL_PREFIX])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_PATH_TOOL_PREFIX], [])
 
-# AC_PATH_MAGIC
-# -------------
-# find a file program which can recognise a shared library
-AC_DEFUN([AC_PATH_MAGIC],
-[AC_PATH_TOOL_PREFIX(${ac_tool_prefix}file, /usr/bin$PATH_SEPARATOR$PATH)
+
+# _LT_PATH_MAGIC
+# --------------
+# find a file program which can recognize a shared library
+m4_defun([_LT_PATH_MAGIC],
+[_LT_PATH_TOOL_PREFIX(${ac_tool_prefix}file, /usr/bin$PATH_SEPARATOR$PATH)
 if test -z "$lt_cv_path_MAGIC_CMD"; then
   if test -n "$ac_tool_prefix"; then
-    AC_PATH_TOOL_PREFIX(file, /usr/bin$PATH_SEPARATOR$PATH)
+    _LT_PATH_TOOL_PREFIX(file, /usr/bin$PATH_SEPARATOR$PATH)
   else
     MAGIC_CMD=:
   fi
 fi
-])# AC_PATH_MAGIC
+])# _LT_PATH_MAGIC
 
 
-# AC_PROG_LD
+# LT_PATH_LD
 # ----------
-# find the path to the GNU or non-GNU linker
-AC_DEFUN([AC_PROG_LD],
-[AC_ARG_WITH([gnu-ld],
-    [AC_HELP_STRING([--with-gnu-ld],
-	[assume the C compiler uses GNU ld @<:@default=no@:>@])],
-    [test "$withval" = no || with_gnu_ld=yes],
-    [with_gnu_ld=no])
-AC_REQUIRE([LT_AC_PROG_SED])dnl
-AC_REQUIRE([AC_PROG_CC])dnl
+# find the pathname to the GNU or non-GNU linker
+AC_DEFUN([LT_PATH_LD],
+[AC_REQUIRE([AC_PROG_CC])dnl
 AC_REQUIRE([AC_CANONICAL_HOST])dnl
 AC_REQUIRE([AC_CANONICAL_BUILD])dnl
+m4_require([_LT_DECL_SED])dnl
+m4_require([_LT_DECL_EGREP])dnl
+
+AC_ARG_WITH([gnu-ld],
+    [AS_HELP_STRING([--with-gnu-ld],
+	[assume the C compiler uses GNU ld @<:@default=no@:>@])],
+    [test "$withval" = no || with_gnu_ld=yes],
+    [with_gnu_ld=no])dnl
+
 ac_prog=ld
 if test "$GCC" = yes; then
   # Check if gcc -print-prog-name=ld gives a path.
@@ -1947,10 +2846,10 @@ if test "$GCC" = yes; then
     # Accept absolute paths.
     [[\\/]]* | ?:[[\\/]]*)
       re_direlt='/[[^/]][[^/]]*/\.\./'
-      # Canonicalize the path of ld
-      ac_prog=`echo $ac_prog| $SED 's%\\\\%/%g'`
-      while echo $ac_prog | grep "$re_direlt" > /dev/null 2>&1; do
-	ac_prog=`echo $ac_prog| $SED "s%$re_direlt%/%"`
+      # Canonicalize the pathname of ld
+      ac_prog=`$ECHO "$ac_prog"| $SED 's%\\\\%/%g'`
+      while $ECHO "$ac_prog" | $GREP "$re_direlt" > /dev/null 2>&1; do
+	ac_prog=`$ECHO $ac_prog| $SED "s%$re_direlt%/%"`
       done
       test -z "$LD" && LD="$ac_prog"
       ;;
@@ -1977,7 +2876,7 @@ AC_CACHE_VAL(lt_cv_path_LD,
     if test -f "$ac_dir/$ac_prog" || test -f "$ac_dir/$ac_prog$ac_exeext"; then
       lt_cv_path_LD="$ac_dir/$ac_prog"
       # Check to see if the program is GNU ld.  I'd rather use --version,
-      # but apparently some GNU ld's only accept -v.
+      # but apparently some variants of GNU ld only accept -v.
       # Break only if it was the GNU/non-GNU ld that we prefer.
       case `"$lt_cv_path_LD" -v 2>&1 </dev/null` in
       *GNU* | *'with BFD'*)
@@ -2000,17 +2899,26 @@ else
   AC_MSG_RESULT(no)
 fi
 test -z "$LD" && AC_MSG_ERROR([no acceptable ld found in \$PATH])
-AC_PROG_LD_GNU
-])# AC_PROG_LD
+_LT_PATH_LD_GNU
+AC_SUBST([LD])
 
+_LT_TAGDECL([], [LD], [1], [The linker used to build libraries])
+])# LT_PATH_LD
 
-# AC_PROG_LD_GNU
-# --------------
-AC_DEFUN([AC_PROG_LD_GNU],
-[AC_REQUIRE([AC_PROG_EGREP])dnl
-AC_CACHE_CHECK([if the linker ($LD) is GNU ld], lt_cv_prog_gnu_ld,
-[# I'd rather use --version here, but apparently some GNU ld's only accept -v.
-case `"$LD" -v 2>&1 </dev/null` in
+# Old names:
+AU_ALIAS([AM_PROG_LD], [LT_PATH_LD])
+AU_ALIAS([AC_PROG_LD], [LT_PATH_LD])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AM_PROG_LD], [])
+dnl AC_DEFUN([AC_PROG_LD], [])
+
+
+# _LT_PATH_LD_GNU
+#- --------------
+m4_defun([_LT_PATH_LD_GNU],
+[AC_CACHE_CHECK([if the linker ($LD) is GNU ld], lt_cv_prog_gnu_ld,
+[# I'd rather use --version here, but apparently some GNU lds only accept -v.
+case `$LD -v 2>&1 </dev/null` in
 *GNU* | *'with BFD'*)
   lt_cv_prog_gnu_ld=yes
   ;;
@@ -2019,14 +2927,14 @@ case `"$LD" -v 2>&1 </dev/null` in
   ;;
 esac])
 with_gnu_ld=$lt_cv_prog_gnu_ld
-])# AC_PROG_LD_GNU
+])# _LT_PATH_LD_GNU
 
 
-# AC_PROG_LD_RELOAD_FLAG
-# ----------------------
+# _LT_CMD_RELOAD
+# --------------
 # find reload flag for linker
 #   -- PORTME Some linkers may need a different reload flag.
-AC_DEFUN([AC_PROG_LD_RELOAD_FLAG],
+m4_defun([_LT_CMD_RELOAD],
 [AC_CACHE_CHECK([for $LD option to reload object files],
   lt_cv_ld_reload_flag,
   [lt_cv_ld_reload_flag='-r'])
@@ -2036,15 +2944,28 @@ case $reload_flag in
 *) reload_flag=" $reload_flag" ;;
 esac
 reload_cmds='$LD$reload_flag -o $output$reload_objs'
-])# AC_PROG_LD_RELOAD_FLAG
+case $host_os in
+  darwin*)
+    if test "$GCC" = yes; then
+      reload_cmds='$LTCC $LTCFLAGS -nostdlib ${wl}-r -o $output$reload_objs'
+    else
+      reload_cmds='$LD$reload_flag -o $output$reload_objs'
+    fi
+    ;;
+esac
+_LT_DECL([], [reload_flag], [1], [How to create reloadable object files])dnl
+_LT_DECL([], [reload_cmds], [2])dnl
+])# _LT_CMD_RELOAD
 
 
-# AC_DEPLIBS_CHECK_METHOD
-# -----------------------
+# _LT_CHECK_MAGIC_METHOD
+# ----------------------
 # how to check for library dependencies
 #  -- PORTME fill in with the dynamic library characteristics
-AC_DEFUN([AC_DEPLIBS_CHECK_METHOD],
-[AC_CACHE_CHECK([how to recognise dependent libraries],
+m4_defun([_LT_CHECK_MAGIC_METHOD],
+[m4_require([_LT_DECL_EGREP])
+m4_require([_LT_DECL_OBJDUMP])
+AC_CACHE_CHECK([how to recognize dependent libraries],
 lt_cv_deplibs_check_method,
 [lt_cv_file_magic_cmd='$MAGIC_CMD'
 lt_cv_file_magic_test_file=
@@ -2061,7 +2982,7 @@ lt_cv_deplibs_check_method='unknown'
 # whether `pass_all' will *always* work, you probably want this one.
 
 case $host_os in
-aix4* | aix5*)
+aix[[4-9]]*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
@@ -2069,40 +2990,48 @@ beos*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-bsdi4*)
+bsdi[[45]]*)
   lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib)'
   lt_cv_file_magic_cmd='/usr/bin/file -L'
   lt_cv_file_magic_test_file=/shlib/libc.so
   ;;
 
-cygwin* | mingw* | pw32*)
-  # win32_libid is a shell function defined in ltmain.sh
+cygwin*)
+  # func_win32_libid is a shell function defined in ltmain.sh
   lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
-  lt_cv_file_magic_cmd='win32_libid'
+  lt_cv_file_magic_cmd='func_win32_libid'
+  ;;
+
+mingw* | pw32*)
+  # Base MSYS/MinGW do not provide the 'file' command needed by
+  # func_win32_libid shell function, so use a weaker test based on 'objdump',
+  # unless we find 'file', for example because we are cross-compiling.
+  if ( file / ) >/dev/null 2>&1; then
+    lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
+    lt_cv_file_magic_cmd='func_win32_libid'
+  else
+    lt_cv_deplibs_check_method='file_magic file format pei*-i386(.*architecture: i386)?'
+    lt_cv_file_magic_cmd='$OBJDUMP -f'
+  fi
+  ;;
+
+cegcc)
+  # use the weaker test based on 'objdump'. See mingw*.
+  lt_cv_deplibs_check_method='file_magic file format pe-arm-.*little(.*architecture: arm)?'
+  lt_cv_file_magic_cmd='$OBJDUMP -f'
   ;;
 
 darwin* | rhapsody*)
-  # this will be overwritten by pass_all, but leave it in just in case
-  lt_cv_deplibs_check_method='file_magic Mach-O dynamically linked shared library'
-  lt_cv_file_magic_cmd='/usr/bin/file -L'
-  case "$host_os" in
-  rhapsody* | darwin1.[[012]])
-    lt_cv_file_magic_test_file=`/System/Library/Frameworks/System.framework/System`
-    ;;
-  *) # Darwin 1.3 on
-    lt_cv_file_magic_test_file='/usr/lib/libSystem.dylib'
-    ;;
-  esac
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-freebsd*)
-  if echo __ELF__ | $CC -E - | grep __ELF__ > /dev/null; then
+freebsd* | dragonfly*)
+  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
     case $host_cpu in
     i*86 )
       # Not sure whether the presence of OpenBSD here was a mistake.
       # Let's accept both of them until this is cleared up.
-      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD)/i[[3-9]]86 (compact )?demand paged shared library'
+      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD|DragonFly)/i[[3-9]]86 (compact )?demand paged shared library'
       lt_cv_file_magic_cmd=/usr/bin/file
       lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
       ;;
@@ -2118,7 +3047,7 @@ gnu*)
 
 hpux10.20* | hpux11*)
   lt_cv_file_magic_cmd=/usr/bin/file
-  case "$host_cpu" in
+  case $host_cpu in
   ia64*)
     lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|ELF-[[0-9]][[0-9]]) shared object file - IA64'
     lt_cv_file_magic_test_file=/usr/lib/hpux32/libc.so
@@ -2134,41 +3063,28 @@ hpux10.20* | hpux11*)
   esac
   ;;
 
+interix[[3-9]]*)
+  # PIC code is broken on Interix 3.x, that's why |\.a not |_pic\.a here
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
+  ;;
+
 irix5* | irix6* | nonstopux*)
-  case $host_os in
-  irix5* | nonstopux*)
-    # this will be overridden with pass_all, but let us keep it just in case
-    lt_cv_deplibs_check_method="file_magic ELF 32-bit MSB dynamic lib MIPS - version 1"
-    ;;
-  *)
-    case $LD in
-    *-32|*"-32 ") libmagic=32-bit;;
-    *-n32|*"-n32 ") libmagic=N32;;
-    *-64|*"-64 ") libmagic=64-bit;;
-    *) libmagic=never-match;;
-    esac
-    # this will be overridden with pass_all, but let us keep it just in case
-    lt_cv_deplibs_check_method="file_magic ELF ${libmagic} MSB mips-[[1234]] dynamic lib MIPS - version 1"
-    ;;
+  case $LD in
+  *-32|*"-32 ") libmagic=32-bit;;
+  *-n32|*"-n32 ") libmagic=N32;;
+  *-64|*"-64 ") libmagic=64-bit;;
+  *) libmagic=never-match;;
   esac
-  lt_cv_file_magic_test_file=`echo /lib${libsuff}/libc.so*`
   lt_cv_deplibs_check_method=pass_all
   ;;
 
 # This must be Linux ELF.
-linux*)
-  case $host_cpu in
-  alpha* | hppa* | i*86 | ia64* | m68* | mips | mipsel | powerpc* | sparc* | s390* | sh*)
-    lt_cv_deplibs_check_method=pass_all ;;
-  *)
-    # glibc up to 2.1.1 does not perform some relocations on ARM
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB (shared object|dynamic lib )' ;;
-  esac
-  lt_cv_file_magic_test_file=`echo /lib/libc.so* /lib/libc-*.so`
+linux* | k*bsd*-gnu)
+  lt_cv_deplibs_check_method=pass_all
   ;;
 
 netbsd*)
-  if echo __ELF__ | $CC -E - | grep __ELF__ > /dev/null; then
+  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
     lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
   else
     lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
@@ -2181,37 +3097,35 @@ newos6*)
   lt_cv_file_magic_test_file=/usr/lib/libnls.so
   ;;
 
-nto-qnx)
-  lt_cv_deplibs_check_method=unknown
+*nto* | *qnx*)
+  lt_cv_deplibs_check_method=pass_all
   ;;
 
 openbsd*)
-  lt_cv_file_magic_cmd=/usr/bin/file
-  lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
-  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB shared object'
+  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
+    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|\.so|_pic\.a)$'
   else
-    lt_cv_deplibs_check_method='file_magic OpenBSD.* shared library'
+    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
   fi
   ;;
 
 osf3* | osf4* | osf5*)
-  # this will be overridden with pass_all, but let us keep it just in case
-  lt_cv_deplibs_check_method='file_magic COFF format alpha shared library'
-  lt_cv_file_magic_test_file=/shlib/libc.so
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-sco3.2v5*)
+rdos*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
 solaris*)
   lt_cv_deplibs_check_method=pass_all
-  lt_cv_file_magic_test_file=/lib/libc.so
   ;;
 
-sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
+sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
+  lt_cv_deplibs_check_method=pass_all
+  ;;
+
+sysv4 | sysv4.3*)
   case $host_vendor in
   motorola)
     lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib) M[[0-9]][[0-9]]* Version [[0-9]]'
@@ -2232,10 +3146,13 @@ sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
   siemens)
     lt_cv_deplibs_check_method=pass_all
     ;;
+  pc)
+    lt_cv_deplibs_check_method=pass_all
+    ;;
   esac
   ;;
 
-sysv5OpenUNIX8* | sysv5UnixWare7* | sysv5uw[[78]]* | unixware7* | sysv4*uw2*)
+tpf*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 esac
@@ -2243,58 +3160,106 @@ esac
 file_magic_cmd=$lt_cv_file_magic_cmd
 deplibs_check_method=$lt_cv_deplibs_check_method
 test -z "$deplibs_check_method" && deplibs_check_method=unknown
-])# AC_DEPLIBS_CHECK_METHOD
+
+_LT_DECL([], [deplibs_check_method], [1],
+    [Method to check whether dependent libraries are shared objects])
+_LT_DECL([], [file_magic_cmd], [1],
+    [Command to use when deplibs_check_method == "file_magic"])
+])# _LT_CHECK_MAGIC_METHOD
 
 
-# AC_PROG_NM
+# LT_PATH_NM
 # ----------
-# find the path to a BSD-compatible name lister
-AC_DEFUN([AC_PROG_NM],
-[AC_CACHE_CHECK([for BSD-compatible nm], lt_cv_path_NM,
+# find the pathname to a BSD- or MS-compatible name lister
+AC_DEFUN([LT_PATH_NM],
+[AC_REQUIRE([AC_PROG_CC])dnl
+AC_CACHE_CHECK([for BSD- or MS-compatible name lister (nm)], lt_cv_path_NM,
 [if test -n "$NM"; then
   # Let the user override the test.
   lt_cv_path_NM="$NM"
 else
-  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
-  for ac_dir in $PATH /usr/ccs/bin /usr/ucb /bin; do
-    IFS="$lt_save_ifs"
-    test -z "$ac_dir" && ac_dir=.
-    tmp_nm="$ac_dir/${ac_tool_prefix}nm"
-    if test -f "$tmp_nm" || test -f "$tmp_nm$ac_exeext" ; then
-      # Check to see if the nm accepts a BSD-compat flag.
-      # Adding the `sed 1q' prevents false positives on HP-UX, which says:
-      #   nm: unknown option "B" ignored
-      # Tru64's nm complains that /dev/null is an invalid object file
-      case `"$tmp_nm" -B /dev/null 2>&1 | sed '1q'` in
-      */dev/null* | *'Invalid file or object type'*)
-	lt_cv_path_NM="$tmp_nm -B"
-	break
-        ;;
-      *)
-	case `"$tmp_nm" -p /dev/null 2>&1 | sed '1q'` in
-	*/dev/null*)
-	  lt_cv_path_NM="$tmp_nm -p"
+  lt_nm_to_check="${ac_tool_prefix}nm"
+  if test -n "$ac_tool_prefix" && test "$build" = "$host"; then
+    lt_nm_to_check="$lt_nm_to_check nm"
+  fi
+  for lt_tmp_nm in $lt_nm_to_check; do
+    lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
+    for ac_dir in $PATH /usr/ccs/bin/elf /usr/ccs/bin /usr/ucb /bin; do
+      IFS="$lt_save_ifs"
+      test -z "$ac_dir" && ac_dir=.
+      tmp_nm="$ac_dir/$lt_tmp_nm"
+      if test -f "$tmp_nm" || test -f "$tmp_nm$ac_exeext" ; then
+	# Check to see if the nm accepts a BSD-compat flag.
+	# Adding the `sed 1q' prevents false positives on HP-UX, which says:
+	#   nm: unknown option "B" ignored
+	# Tru64's nm complains that /dev/null is an invalid object file
+	case `"$tmp_nm" -B /dev/null 2>&1 | sed '1q'` in
+	*/dev/null* | *'Invalid file or object type'*)
+	  lt_cv_path_NM="$tmp_nm -B"
 	  break
 	  ;;
 	*)
-	  lt_cv_path_NM=${lt_cv_path_NM="$tmp_nm"} # keep the first match, but
-	  continue # so that we can try to find one that supports BSD flags
+	  case `"$tmp_nm" -p /dev/null 2>&1 | sed '1q'` in
+	  */dev/null*)
+	    lt_cv_path_NM="$tmp_nm -p"
+	    break
+	    ;;
+	  *)
+	    lt_cv_path_NM=${lt_cv_path_NM="$tmp_nm"} # keep the first match, but
+	    continue # so that we can try to find one that supports BSD flags
+	    ;;
+	  esac
 	  ;;
 	esac
-      esac
-    fi
+      fi
+    done
+    IFS="$lt_save_ifs"
   done
-  IFS="$lt_save_ifs"
-  test -z "$lt_cv_path_NM" && lt_cv_path_NM=nm
+  : ${lt_cv_path_NM=no}
 fi])
-NM="$lt_cv_path_NM"
-])# AC_PROG_NM
+if test "$lt_cv_path_NM" != "no"; then
+  NM="$lt_cv_path_NM"
+else
+  # Didn't find any BSD compatible name lister, look for dumpbin.
+  AC_CHECK_TOOLS(DUMPBIN, ["dumpbin -symbols" "link -dump -symbols"], :)
+  AC_SUBST([DUMPBIN])
+  if test "$DUMPBIN" != ":"; then
+    NM="$DUMPBIN"
+  fi
+fi
+test -z "$NM" && NM=nm
+AC_SUBST([NM])
+_LT_DECL([], [NM], [1], [A BSD- or MS-compatible name lister])dnl
+
+AC_CACHE_CHECK([the name lister ($NM) interface], [lt_cv_nm_interface],
+  [lt_cv_nm_interface="BSD nm"
+  echo "int some_variable = 0;" > conftest.$ac_ext
+  (eval echo "\"\$as_me:__oline__: $ac_compile\"" >&AS_MESSAGE_LOG_FD)
+  (eval "$ac_compile" 2>conftest.err)
+  cat conftest.err >&AS_MESSAGE_LOG_FD
+  (eval echo "\"\$as_me:__oline__: $NM \\\"conftest.$ac_objext\\\"\"" >&AS_MESSAGE_LOG_FD)
+  (eval "$NM \"conftest.$ac_objext\"" 2>conftest.err > conftest.out)
+  cat conftest.err >&AS_MESSAGE_LOG_FD
+  (eval echo "\"\$as_me:__oline__: output\"" >&AS_MESSAGE_LOG_FD)
+  cat conftest.out >&AS_MESSAGE_LOG_FD
+  if $GREP 'External.*some_variable' conftest.out > /dev/null; then
+    lt_cv_nm_interface="MS dumpbin"
+  fi
+  rm -f conftest*])
+])# LT_PATH_NM
 
+# Old names:
+AU_ALIAS([AM_PROG_NM], [LT_PATH_NM])
+AU_ALIAS([AC_PROG_NM], [LT_PATH_NM])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AM_PROG_NM], [])
+dnl AC_DEFUN([AC_PROG_NM], [])
 
-# AC_CHECK_LIBM
-# -------------
+
+# LT_LIB_M
+# --------
 # check for math library
-AC_DEFUN([AC_CHECK_LIBM],
+AC_DEFUN([LT_LIB_M],
 [AC_REQUIRE([AC_CANONICAL_HOST])dnl
 LIBM=
 case $host in
@@ -2309,3537 +3274,4686 @@ case $host in
   AC_CHECK_LIB(m, cos, LIBM="-lm")
   ;;
 esac
-])# AC_CHECK_LIBM
+AC_SUBST([LIBM])
+])# LT_LIB_M
 
+# Old name:
+AU_ALIAS([AC_CHECK_LIBM], [LT_LIB_M])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_CHECK_LIBM], [])
 
-# AC_LIBLTDL_CONVENIENCE([DIRECTORY])
-# -----------------------------------
-# sets LIBLTDL to the link flags for the libltdl convenience library and
-# LTDLINCL to the include flags for the libltdl header and adds
-# --enable-ltdl-convenience to the configure arguments.  Note that LIBLTDL
-# and LTDLINCL are not AC_SUBSTed, nor is AC_CONFIG_SUBDIRS called.  If
-# DIRECTORY is not provided, it is assumed to be `libltdl'.  LIBLTDL will
-# be prefixed with '${top_builddir}/' and LTDLINCL will be prefixed with
-# '${top_srcdir}/' (note the single quotes!).  If your package is not
-# flat and you're not using automake, define top_builddir and
-# top_srcdir appropriately in the Makefiles.
-AC_DEFUN([AC_LIBLTDL_CONVENIENCE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-  case $enable_ltdl_convenience in
-  no) AC_MSG_ERROR([this package needs a convenience libltdl]) ;;
-  "") enable_ltdl_convenience=yes
-      ac_configure_args="$ac_configure_args --enable-ltdl-convenience" ;;
-  esac
-  LIBLTDL='${top_builddir}/'ifelse($#,1,[$1],['libltdl'])/libltdlc.la
-  LTDLINCL='-I${top_srcdir}/'ifelse($#,1,[$1],['libltdl'])
-  # For backwards non-gettext consistent compatibility...
-  INCLTDL="$LTDLINCL"
-])# AC_LIBLTDL_CONVENIENCE
 
+# _LT_COMPILER_NO_RTTI([TAGNAME])
+# -------------------------------
+m4_defun([_LT_COMPILER_NO_RTTI],
+[m4_require([_LT_TAG_COMPILER])dnl
 
-# AC_LIBLTDL_INSTALLABLE([DIRECTORY])
-# -----------------------------------
-# sets LIBLTDL to the link flags for the libltdl installable library and
-# LTDLINCL to the include flags for the libltdl header and adds
-# --enable-ltdl-install to the configure arguments.  Note that LIBLTDL
-# and LTDLINCL are not AC_SUBSTed, nor is AC_CONFIG_SUBDIRS called.  If
-# DIRECTORY is not provided and an installed libltdl is not found, it is
-# assumed to be `libltdl'.  LIBLTDL will be prefixed with '${top_builddir}/'
-# and LTDLINCL will be prefixed with '${top_srcdir}/' (note the single
-# quotes!).  If your package is not flat and you're not using automake,
-# define top_builddir and top_srcdir appropriately in the Makefiles.
-# In the future, this macro may have to be called after AC_PROG_LIBTOOL.
-AC_DEFUN([AC_LIBLTDL_INSTALLABLE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-  AC_CHECK_LIB(ltdl, lt_dlinit,
-  [test x"$enable_ltdl_install" != xyes && enable_ltdl_install=no],
-  [if test x"$enable_ltdl_install" = xno; then
-     AC_MSG_WARN([libltdl not installed, but installation disabled])
-   else
-     enable_ltdl_install=yes
-   fi
-  ])
-  if test x"$enable_ltdl_install" = x"yes"; then
-    ac_configure_args="$ac_configure_args --enable-ltdl-install"
-    LIBLTDL='${top_builddir}/'ifelse($#,1,[$1],['libltdl'])/libltdl.la
-    LTDLINCL='-I${top_srcdir}/'ifelse($#,1,[$1],['libltdl'])
-  else
-    ac_configure_args="$ac_configure_args --enable-ltdl-install=no"
-    LIBLTDL="-lltdl"
-    LTDLINCL=
-  fi
-  # For backwards non-gettext consistent compatibility...
-  INCLTDL="$LTDLINCL"
-])# AC_LIBLTDL_INSTALLABLE
+_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
 
+if test "$GCC" = yes; then
+  _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
 
-# AC_LIBTOOL_CXX
-# --------------
-# enable support for C++ libraries
-AC_DEFUN([AC_LIBTOOL_CXX],
-[AC_REQUIRE([_LT_AC_LANG_CXX])
-])# AC_LIBTOOL_CXX
+  _LT_COMPILER_OPTION([if $compiler supports -fno-rtti -fno-exceptions],
+    lt_cv_prog_compiler_rtti_exceptions,
+    [-fno-rtti -fno-exceptions], [],
+    [_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)="$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) -fno-rtti -fno-exceptions"])
+fi
+_LT_TAGDECL([no_builtin_flag], [lt_prog_compiler_no_builtin_flag], [1],
+	[Compiler flag to turn off builtin functions])
+])# _LT_COMPILER_NO_RTTI
 
 
-# _LT_AC_LANG_CXX
-# ---------------
-AC_DEFUN([_LT_AC_LANG_CXX],
-[AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([AC_PROG_CXXCPP])
-_LT_AC_SHELL_INIT([tagnames=`echo "$tagnames,CXX" | sed 's/^,//'`])
-])# _LT_AC_LANG_CXX
-
-
-# AC_LIBTOOL_F77
-# --------------
-# enable support for Fortran 77 libraries
-AC_DEFUN([AC_LIBTOOL_F77],
-[AC_REQUIRE([_LT_AC_LANG_F77])
-])# AC_LIBTOOL_F77
-
-
-# _LT_AC_LANG_F77
-# ---------------
-AC_DEFUN([_LT_AC_LANG_F77],
-[AC_REQUIRE([AC_PROG_F77])
-_LT_AC_SHELL_INIT([tagnames=`echo "$tagnames,F77" | sed 's/^,//'`])
-])# _LT_AC_LANG_F77
-
-
-# AC_LIBTOOL_GCJ
-# --------------
-# enable support for GCJ libraries
-AC_DEFUN([AC_LIBTOOL_GCJ],
-[AC_REQUIRE([_LT_AC_LANG_GCJ])
-])# AC_LIBTOOL_GCJ
-
-
-# _LT_AC_LANG_GCJ
-# ---------------
-AC_DEFUN([_LT_AC_LANG_GCJ],
-[AC_PROVIDE_IFELSE([AC_PROG_GCJ],[],
-  [AC_PROVIDE_IFELSE([A][M_PROG_GCJ],[],
-    [AC_PROVIDE_IFELSE([LT_AC_PROG_GCJ],[],
-      [ifdef([AC_PROG_GCJ],[AC_REQUIRE([AC_PROG_GCJ])],
-	 [ifdef([A][M_PROG_GCJ],[AC_REQUIRE([A][M_PROG_GCJ])],
-	   [AC_REQUIRE([A][C_PROG_GCJ_OR_A][M_PROG_GCJ])])])])])])
-_LT_AC_SHELL_INIT([tagnames=`echo "$tagnames,GCJ" | sed 's/^,//'`])
-])# _LT_AC_LANG_GCJ
-
-
-# AC_LIBTOOL_RC
-# --------------
-# enable support for Windows resource files
-AC_DEFUN([AC_LIBTOOL_RC],
-[AC_REQUIRE([LT_AC_PROG_RC])
-_LT_AC_SHELL_INIT([tagnames=`echo "$tagnames,RC" | sed 's/^,//'`])
-])# AC_LIBTOOL_RC
-
-
-# AC_LIBTOOL_LANG_C_CONFIG
-# ------------------------
-# Ensure that the configuration vars for the C compiler are
-# suitably defined.  Those variables are subsequently used by
-# AC_LIBTOOL_CONFIG to write the compiler configuration to `libtool'.
-AC_DEFUN([AC_LIBTOOL_LANG_C_CONFIG], [_LT_AC_LANG_C_CONFIG])
-AC_DEFUN([_LT_AC_LANG_C_CONFIG],
-[lt_save_CC="$CC"
-AC_LANG_PUSH(C)
-
-# Source file extension for C test sources.
-ac_ext=c
-
-# Object file extension for compiled C test sources.
-objext=o
-_LT_AC_TAGVAR(objext, $1)=$objext
-
-# Code to be used in simple compile tests
-lt_simple_compile_test_code="int some_variable = 0;\n"
-
-# Code to be used in simple link tests
-lt_simple_link_test_code='int main(){return(0);}\n'
-
-_LT_AC_SYS_COMPILER
-
-#
-# Check for any special shared library compilation flags.
-#
-_LT_AC_TAGVAR(lt_prog_cc_shlib, $1)=
-if test "$GCC" = no; then
-  case $host_os in
-  sco3.2v5*)
-    _LT_AC_TAGVAR(lt_prog_cc_shlib, $1)='-belf'
-    ;;
-  esac
-fi
-if test -n "$_LT_AC_TAGVAR(lt_prog_cc_shlib, $1)"; then
-  AC_MSG_WARN([`$CC' requires `$_LT_AC_TAGVAR(lt_prog_cc_shlib, $1)' to build shared libraries])
-  if echo "$old_CC $old_CFLAGS " | grep "[[ 	]]$]_LT_AC_TAGVAR(lt_prog_cc_shlib, $1)[[[ 	]]" >/dev/null; then :
-  else
-    AC_MSG_WARN([add `$_LT_AC_TAGVAR(lt_prog_cc_shlib, $1)' to the CC or CFLAGS env variable and reconfigure])
-    _LT_AC_TAGVAR(lt_cv_prog_cc_can_build_shared, $1)=no
-  fi
-fi
+# _LT_CMD_GLOBAL_SYMBOLS
+# ----------------------
+m4_defun([_LT_CMD_GLOBAL_SYMBOLS],
+[AC_REQUIRE([AC_CANONICAL_HOST])dnl
+AC_REQUIRE([AC_PROG_CC])dnl
+AC_REQUIRE([LT_PATH_NM])dnl
+AC_REQUIRE([LT_PATH_LD])dnl
+m4_require([_LT_DECL_SED])dnl
+m4_require([_LT_DECL_EGREP])dnl
+m4_require([_LT_TAG_COMPILER])dnl
 
+# Check for command to grab the raw symbol name followed by C symbol from nm.
+AC_MSG_CHECKING([command to parse $NM output from $compiler object])
+AC_CACHE_VAL([lt_cv_sys_global_symbol_pipe],
+[
+# These are sane defaults that work on at least a few old systems.
+# [They come from Ultrix.  What could be older than Ultrix?!! ;)]
 
-#
-# Check to make sure the static flag actually works.
-#
-AC_LIBTOOL_LINKER_OPTION([if $compiler static flag $_LT_AC_TAGVAR(lt_prog_compiler_static, $1) works],
-  _LT_AC_TAGVAR(lt_prog_compiler_static_works, $1),
-  $_LT_AC_TAGVAR(lt_prog_compiler_static, $1),
-  [],
-  [_LT_AC_TAGVAR(lt_prog_compiler_static, $1)=])
+# Character class describing NM global symbol codes.
+symcode='[[BCDEGRST]]'
 
+# Regexp to match symbols that can be accessed directly from C.
+sympat='\([[_A-Za-z]][[_A-Za-z0-9]]*\)'
 
-AC_LIBTOOL_PROG_COMPILER_NO_RTTI($1)
-AC_LIBTOOL_PROG_COMPILER_PIC($1)
-AC_LIBTOOL_PROG_CC_C_O($1)
-AC_LIBTOOL_SYS_HARD_LINK_LOCKS($1)
-AC_LIBTOOL_PROG_LD_SHLIBS($1)
-AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH($1)
-AC_LIBTOOL_SYS_LIB_STRIP
-AC_LIBTOOL_SYS_DYNAMIC_LINKER($1)
-AC_LIBTOOL_DLOPEN_SELF($1)
-
-# Report which librarie types wil actually be built
-AC_MSG_CHECKING([if libtool supports shared libraries])
-AC_MSG_RESULT([$can_build_shared])
-
-AC_MSG_CHECKING([whether to build shared libraries])
-test "$can_build_shared" = "no" && enable_shared=no
-
-# On AIX, shared libraries and static libraries use the same namespace, and
-# are all built from PIC.
-case "$host_os" in
-aix3*)
-  test "$enable_shared" = yes && enable_static=no
-  if test -n "$RANLIB"; then
-    archive_cmds="$archive_cmds~\$RANLIB \$lib"
-    postinstall_cmds='$RANLIB $lib'
-  fi
+# Define system-specific variables.
+case $host_os in
+aix*)
+  symcode='[[BCDT]]'
   ;;
-
-aix4*)
-  if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
-    test "$enable_shared" = yes && enable_static=no
+cygwin* | mingw* | pw32* | cegcc*)
+  symcode='[[ABCDGISTW]]'
+  ;;
+hpux*)
+  if test "$host_cpu" = ia64; then
+    symcode='[[ABCDEGRST]]'
   fi
   ;;
-  darwin* | rhapsody*)
-  if $CC -v 2>&1 | grep 'Apple' >/dev/null ; then 
-    _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-    case "$host_os" in
-    rhapsody* | darwin1.[[012]])
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)='-undefined suppress'
-      ;;
-    *) # Darwin 1.3 on
-      test -z ${LD_TWOLEVEL_NAMESPACE} && _LT_AC_TAGVAR(allow_undefined_flag, $1)='-flat_namespace -undefined suppress'
-      ;;
-    esac
-    # FIXME: Relying on posixy $() will cause problems for
-    #        cross-compilation, but unfortunately the echo tests do not
-    #        yet detect zsh echo's removal of \ escapes.  Also zsh mangles
-    #	       `"' quotes if we put them in here... so don't!
-		output_verbose_link_cmd='echo'
-    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -dynamiclib $allow_undefined_flag -o $lib $libobjs $deplibs$compiler_flags -install_name $rpath/$soname $verstring'
-    _LT_AC_TAGVAR(module_cmds, $1)='$CC -bundle $allow_undefined_flag -o $lib $libobjs $deplibs$compiler_flags'
-    # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-		  _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -dynamiclib $allow_undefined_flag  -o $lib $libobjs $deplibs$compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-		  _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -bundle $allow_undefined_flag  -o $lib $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-    _LT_AC_TAGVAR(hardcode_direct, $1)=no
-    _LT_AC_TAGVAR(hardcode_automatic, $1)=yes
-    _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
-    _LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-all_load $convenience'
-    _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-    fi
-    ;;  
+irix* | nonstopux*)
+  symcode='[[BCDEGRST]]'
+  ;;
+osf*)
+  symcode='[[BCDEGQRST]]'
+  ;;
+solaris*)
+  symcode='[[BDRT]]'
+  ;;
+sco3.2v5*)
+  symcode='[[DT]]'
+  ;;
+sysv4.2uw2*)
+  symcode='[[DT]]'
+  ;;
+sysv5* | sco5v6* | unixware* | OpenUNIX*)
+  symcode='[[ABDT]]'
+  ;;
+sysv4)
+  symcode='[[DFNSTU]]'
+  ;;
 esac
-AC_MSG_RESULT([$enable_shared])
-
-AC_MSG_CHECKING([whether to build static libraries])
-# Make sure either enable_shared or enable_static is yes.
-test "$enable_shared" = yes || enable_static=yes
-AC_MSG_RESULT([$enable_static])
-
-AC_LIBTOOL_CONFIG($1)
-
-AC_LANG_POP
-CC="$lt_save_CC"
-])# AC_LIBTOOL_LANG_C_CONFIG
 
+# If we're using GNU nm, then use its standard symbol codes.
+case `$NM -V 2>&1` in
+*GNU* | *'with BFD'*)
+  symcode='[[ABCDGIRSTW]]' ;;
+esac
 
-# AC_LIBTOOL_LANG_CXX_CONFIG
-# --------------------------
-# Ensure that the configuration vars for the C compiler are
-# suitably defined.  Those variables are subsequently used by
-# AC_LIBTOOL_CONFIG to write the compiler configuration to `libtool'.
-AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG], [_LT_AC_LANG_CXX_CONFIG(CXX)])
-AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
-[AC_LANG_PUSH(C++)
-AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([AC_PROG_CXXCPP])
-
-_LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-_LT_AC_TAGVAR(allow_undefined_flag, $1)=
-_LT_AC_TAGVAR(always_export_symbols, $1)=no
-_LT_AC_TAGVAR(archive_expsym_cmds, $1)=
-_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=
-_LT_AC_TAGVAR(hardcode_direct, $1)=no
-_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
-_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
-_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
-_LT_AC_TAGVAR(hardcode_minus_L, $1)=no
-_LT_AC_TAGVAR(hardcode_automatic, $1)=no
-_LT_AC_TAGVAR(module_cmds, $1)=
-_LT_AC_TAGVAR(module_expsym_cmds, $1)=
-_LT_AC_TAGVAR(link_all_deplibs, $1)=unknown
-_LT_AC_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
-_LT_AC_TAGVAR(no_undefined_flag, $1)=
-_LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
-_LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+# Transform an extracted symbol line into a proper C declaration.
+# Some systems (esp. on ia64) link data and code symbols differently,
+# so use this general approach.
+lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^T .* \(.*\)$/extern int \1();/p' -e 's/^$symcode* .* \(.*\)$/extern char \1;/p'"
 
-# Dependencies to place before and after the object being linked:
-_LT_AC_TAGVAR(predep_objects, $1)=
-_LT_AC_TAGVAR(postdep_objects, $1)=
-_LT_AC_TAGVAR(predeps, $1)=
-_LT_AC_TAGVAR(postdeps, $1)=
-_LT_AC_TAGVAR(compiler_lib_search_path, $1)=
+# Transform an extracted symbol line into symbol name and symbol address
+lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p'"
+lt_cv_sys_global_symbol_to_c_name_address_lib_prefix="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \(lib[[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"lib\2\", (void *) \&\2},/p'"
 
-# Source file extension for C++ test sources.
-ac_ext=cc
+# Handle CRLF in mingw tool chain
+opt_cr=
+case $build_os in
+mingw*)
+  opt_cr=`$ECHO 'x\{0,1\}' | tr x '\015'` # option cr in regexp
+  ;;
+esac
 
-# Object file extension for compiled C++ test sources.
-objext=o
-_LT_AC_TAGVAR(objext, $1)=$objext
+# Try without a prefix underscore, then with it.
+for ac_symprfx in "" "_"; do
 
-# Code to be used in simple compile tests
-lt_simple_compile_test_code="int some_variable = 0;\n"
+  # Transform symcode, sympat, and symprfx into a raw symbol and a C symbol.
+  symxfrm="\\1 $ac_symprfx\\2 \\2"
 
-# Code to be used in simple link tests
-lt_simple_link_test_code='int main(int, char *[]) { return(0); }\n'
+  # Write the raw and C identifiers.
+  if test "$lt_cv_nm_interface" = "MS dumpbin"; then
+    # Fake it for dumpbin and say T for any non-static function
+    # and D for any global variable.
+    # Also find C++ and __fastcall symbols from MSVC++,
+    # which start with @ or ?.
+    lt_cv_sys_global_symbol_pipe="$AWK ['"\
+"     {last_section=section; section=\$ 3};"\
+"     /Section length .*#relocs.*(pick any)/{hide[last_section]=1};"\
+"     \$ 0!~/External *\|/{next};"\
+"     / 0+ UNDEF /{next}; / UNDEF \([^|]\)*()/{next};"\
+"     {if(hide[section]) next};"\
+"     {f=0}; \$ 0~/\(\).*\|/{f=1}; {printf f ? \"T \" : \"D \"};"\
+"     {split(\$ 0, a, /\||\r/); split(a[2], s)};"\
+"     s[1]~/^[@?]/{print s[1], s[1]; next};"\
+"     s[1]~prfx {split(s[1],t,\"@\"); print t[1], substr(t[1],length(prfx))}"\
+"     ' prfx=^$ac_symprfx]"
+  else
+    lt_cv_sys_global_symbol_pipe="sed -n -e 's/^.*[[	 ]]\($symcode$symcode*\)[[	 ]][[	 ]]*$ac_symprfx$sympat$opt_cr$/$symxfrm/p'"
+  fi
 
-# ltmain only uses $CC for tagged configurations so make sure $CC is set.
-_LT_AC_SYS_COMPILER
+  # Check to see that the pipe works correctly.
+  pipe_works=no
 
-# Allow CC to be a program name with arguments.
-lt_save_CC=$CC
-lt_save_LD=$LD
-lt_save_GCC=$GCC
-GCC=$GXX
-lt_save_with_gnu_ld=$with_gnu_ld
-lt_save_path_LD=$lt_cv_path_LD
-if test -n "${lt_cv_prog_gnu_ldcxx+set}"; then
-  lt_cv_prog_gnu_ld=$lt_cv_prog_gnu_ldcxx
-else
-  unset lt_cv_prog_gnu_ld
-fi
-if test -n "${lt_cv_path_LDCXX+set}"; then
-  lt_cv_path_LD=$lt_cv_path_LDCXX
-else
-  unset lt_cv_path_LD
-fi
-test -z "${LDCXX+set}" || LD=$LDCXX
-CC=${CXX-"c++"}
-compiler=$CC
-_LT_AC_TAGVAR(compiler, $1)=$CC
-cc_basename=`$echo X"$compiler" | $Xsed -e 's%^.*/%%'`
+  rm -f conftest*
+  cat > conftest.$ac_ext <<_LT_EOF
+#ifdef __cplusplus
+extern "C" {
+#endif
+char nm_test_var;
+void nm_test_func(void);
+void nm_test_func(void){}
+#ifdef __cplusplus
+}
+#endif
+int main(){nm_test_var='a';nm_test_func();return(0);}
+_LT_EOF
 
-# We don't want -fno-exception wen compiling C++ code, so set the
-# no_builtin_flag separately
-if test "$GXX" = yes; then
-  _LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
-else
-  _LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
-fi
+  if AC_TRY_EVAL(ac_compile); then
+    # Now try to grab the symbols.
+    nlist=conftest.nm
+    if AC_TRY_EVAL(NM conftest.$ac_objext \| $lt_cv_sys_global_symbol_pipe \> $nlist) && test -s "$nlist"; then
+      # Try sorting and uniquifying the output.
+      if sort "$nlist" | uniq > "$nlist"T; then
+	mv -f "$nlist"T "$nlist"
+      else
+	rm -f "$nlist"T
+      fi
 
-if test "$GXX" = yes; then
-  # Set up default GNU C++ configuration
+      # Make sure that we snagged all the symbols we need.
+      if $GREP ' nm_test_var$' "$nlist" >/dev/null; then
+	if $GREP ' nm_test_func$' "$nlist" >/dev/null; then
+	  cat <<_LT_EOF > conftest.$ac_ext
+#ifdef __cplusplus
+extern "C" {
+#endif
 
-  AC_PROG_LD
+_LT_EOF
+	  # Now generate the symbol file.
+	  eval "$lt_cv_sys_global_symbol_to_cdecl"' < "$nlist" | $GREP -v main >> conftest.$ac_ext'
 
-  # Check if GNU C++ uses GNU ld as the underlying linker, since the
-  # archiving commands below assume that GNU ld is being used.
-  if test "$with_gnu_ld" = yes; then
-    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
-    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+	  cat <<_LT_EOF >> conftest.$ac_ext
 
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
-    _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+/* The mapping between symbol names and symbols.  */
+const struct {
+  const char *name;
+  void       *address;
+}
+lt__PROGRAM__LTX_preloaded_symbols[[]] =
+{
+  { "@PROGRAM@", (void *) 0 },
+_LT_EOF
+	  $SED "s/^$symcode$symcode* \(.*\) \(.*\)$/  {\"\2\", (void *) \&\2},/" < "$nlist" | $GREP -v main >> conftest.$ac_ext
+	  cat <<\_LT_EOF >> conftest.$ac_ext
+  {0, (void *) 0}
+};
 
-    # If archive_cmds runs LD, not CC, wlarc should be empty
-    # XXX I think wlarc can be eliminated in ltcf-cxx, but I need to
-    #     investigate it a little bit more. (MM)
-    wlarc='${wl}'
+/* This works around a problem in FreeBSD linker */
+#ifdef FREEBSD_WORKAROUND
+static const void *lt_preloaded_setup() {
+  return lt__PROGRAM__LTX_preloaded_symbols;
+}
+#endif
 
-    # ancient GNU ld didn't support --whole-archive et. al.
-    if eval "`$CC -print-prog-name=ld` --help 2>&1" | \
-	grep 'no-whole-archive' > /dev/null; then
-      _LT_AC_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+#ifdef __cplusplus
+}
+#endif
+_LT_EOF
+	  # Now try linking the two files.
+	  mv conftest.$ac_objext conftstm.$ac_objext
+	  lt_save_LIBS="$LIBS"
+	  lt_save_CFLAGS="$CFLAGS"
+	  LIBS="conftstm.$ac_objext"
+	  CFLAGS="$CFLAGS$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)"
+	  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext}; then
+	    pipe_works=yes
+	  fi
+	  LIBS="$lt_save_LIBS"
+	  CFLAGS="$lt_save_CFLAGS"
+	else
+	  echo "cannot find nm_test_func in $nlist" >&AS_MESSAGE_LOG_FD
+	fi
+      else
+	echo "cannot find nm_test_var in $nlist" >&AS_MESSAGE_LOG_FD
+      fi
     else
-      _LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
+      echo "cannot run $lt_cv_sys_global_symbol_pipe" >&AS_MESSAGE_LOG_FD
     fi
   else
-    with_gnu_ld=no
-    wlarc=
-
-    # A generic and very simple default shared library creation
-    # command for GNU C++ for the case where it uses the native
-    # linker, instead of GNU ld.  If possible, this setting should
-    # overridden to take advantage of the native linker features on
-    # the platform it is being used on.
-    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
+    echo "$progname: failed program was:" >&AS_MESSAGE_LOG_FD
+    cat conftest.$ac_ext >&5
   fi
+  rm -rf conftest* conftst*
 
-  # Commands to make compiler produce verbose output that lists
-  # what "hidden" libraries, object files and flags are used when
-  # linking a shared library.
-  output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "\-L"'
-
+  # Do not use the global_symbol_pipe unless it works.
+  if test "$pipe_works" = yes; then
+    break
+  else
+    lt_cv_sys_global_symbol_pipe=
+  fi
+done
+])
+if test -z "$lt_cv_sys_global_symbol_pipe"; then
+  lt_cv_sys_global_symbol_to_cdecl=
+fi
+if test -z "$lt_cv_sys_global_symbol_pipe$lt_cv_sys_global_symbol_to_cdecl"; then
+  AC_MSG_RESULT(failed)
 else
-  GXX=no
-  with_gnu_ld=no
-  wlarc=
+  AC_MSG_RESULT(ok)
 fi
 
-# PORTME: fill in a description of your system's C++ link characteristics
-AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
-_LT_AC_TAGVAR(ld_shlibs, $1)=yes
-case $host_os in
-  aix3*)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  aix4* | aix5*)
-    if test "$host_cpu" = ia64; then
-      # On IA64, the linker does run time linking by default, so we don't
-      # have to do anything special.
-      aix_use_runtimelinking=no
-      exp_sym_flag='-Bexport'
-      no_entry_flag=""
-    else
-      aix_use_runtimelinking=no
+_LT_DECL([global_symbol_pipe], [lt_cv_sys_global_symbol_pipe], [1],
+    [Take the output of nm and produce a listing of raw symbols and C names])
+_LT_DECL([global_symbol_to_cdecl], [lt_cv_sys_global_symbol_to_cdecl], [1],
+    [Transform the output of nm in a proper C declaration])
+_LT_DECL([global_symbol_to_c_name_address],
+    [lt_cv_sys_global_symbol_to_c_name_address], [1],
+    [Transform the output of nm in a C name address pair])
+_LT_DECL([global_symbol_to_c_name_address_lib_prefix],
+    [lt_cv_sys_global_symbol_to_c_name_address_lib_prefix], [1],
+    [Transform the output of nm in a C name address pair when lib prefix is needed])
+]) # _LT_CMD_GLOBAL_SYMBOLS
 
-      # Test if we are trying to use run time linking or normal
-      # AIX style linking. If -brtl is somewhere in LDFLAGS, we
-      # need to do runtime linking.
-      case $host_os in aix4.[[23]]|aix4.[[23]].*|aix5*)
-	for ld_flag in $LDFLAGS; do
-	  case $ld_flag in
-	  *-brtl*)
-	    aix_use_runtimelinking=yes
-	    break
-	    ;;
-	  esac
-	done
-      esac
 
-      exp_sym_flag='-bexport'
-      no_entry_flag='-bnoentry'
-    fi
+# _LT_COMPILER_PIC([TAGNAME])
+# ---------------------------
+m4_defun([_LT_COMPILER_PIC],
+[m4_require([_LT_TAG_COMPILER])dnl
+_LT_TAGVAR(lt_prog_compiler_wl, $1)=
+_LT_TAGVAR(lt_prog_compiler_pic, $1)=
+_LT_TAGVAR(lt_prog_compiler_static, $1)=
 
-    # When large executables or shared objects are built, AIX ld can
-    # have problems creating the table of contents.  If linking a library
-    # or program results in "error TOC overflow" add -mminimal-toc to
-    # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
-    # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.
-
-    _LT_AC_TAGVAR(archive_cmds, $1)=''
-    _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-    _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=':'
-    _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+AC_MSG_CHECKING([for $compiler option to produce PIC])
+m4_if([$1], [CXX], [
+  # C++ specific cases for pic, static, wl, etc.
+  if test "$GXX" = yes; then
+    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
 
-    if test "$GXX" = yes; then
-      case $host_os in aix4.[012]|aix4.[012].*)
-      # We only want to do this on AIX 4.2 and lower, the check
-      # below for broken collect2 doesn't work under 4.3+
-	collect2name=`${CC} -print-prog-name=collect2`
-	if test -f "$collect2name" && \
-	   strings "$collect2name" | grep resolve_lib_name >/dev/null
-	then
-	  # We have reworked collect2
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-	else
-	  # We have old collect2
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=unsupported
-	  # It fails to find uninstalled libraries when the uninstalled
-	  # path is not listed in the libpath.  Setting hardcode_minus_L
-	  # to unsupported forces relinking
-	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
-	fi
-      esac
-      shared_flag='-shared'
-    else
-      # not using gcc
+    case $host_os in
+    aix*)
+      # All AIX code is PIC.
       if test "$host_cpu" = ia64; then
-	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
-	# chokes on -Wl,-G. The following line is correct:
-	shared_flag='-G'
-      else
-	if test "$aix_use_runtimelinking" = yes; then
-	  shared_flag='${wl}-G'
-	else
-	  shared_flag='${wl}-bM:SRE'
-	fi
+	# AIX 5 now supports IA64 processor
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
       fi
-    fi
+      ;;
 
-    # It seems that -bexpall does not export symbols beginning with
-    # underscore (_), so it is better to generate a list of symbols to export.
-    _LT_AC_TAGVAR(always_export_symbols, $1)=yes
-    if test "$aix_use_runtimelinking" = yes; then
-      # Warning - without using the other runtime loading flags (-brtl),
-      # -berok will link without error, but may produce a broken library.
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)='-berok'
-      # Determine the default libpath from the value encoded in an empty executable.
-      _LT_AC_SYS_LIBPATH_AIX
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+    amigaos*)
+      case $host_cpu in
+      powerpc)
+            # see comment about AmigaOS4 .so support
+            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+        ;;
+      m68k)
+            # FIXME: we need at least 68020 code to build shared libraries, but
+            # adding the `-m68020' flag to GCC prevents building anything better,
+            # like `-m68040'.
+            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
+        ;;
+      esac
+      ;;
 
-      _LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then echo "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols $shared_flag"
-     else
-      if test "$host_cpu" = ia64; then
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols"
-      else
-	# Determine the default libpath from the value encoded in an empty executable.
-	_LT_AC_SYS_LIBPATH_AIX
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
-	# Warning - without using the other run time loading flags,
-	# -berok will link without error, but may produce a broken library.
-	_LT_AC_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
-	# -bexpall does not export symbols beginning with underscore (_)
-	_LT_AC_TAGVAR(always_export_symbols, $1)=yes
-	# Exported symbols can be pulled into shared objects from archives
-	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)=' '
-	_LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
-	# This is similar to how AIX traditionally builds it's shared libraries.
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}-bE:$export_symbols ${wl}-bnoentry${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
-      fi
-    fi
-    ;;
-  chorus*)
-    case $cc_basename in
-      *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-    esac
-    ;;
-
-  cygwin* | mingw* | pw32*)
-    # _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
-    # as there is no search path for DLLs.
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-    _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-    _LT_AC_TAGVAR(always_export_symbols, $1)=no
-    _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
-
-    if $LD --help 2>&1 | grep 'auto-import' > /dev/null; then
-      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000 ${wl}--out-implib,$lib'
-      # If the export-symbols file already is a .def file (1st line
-      # is EXPORTS), use it as is; otherwise, prepend...
-      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
-	cp $export_symbols $output_objdir/$soname.def;
-      else
-	echo EXPORTS > $output_objdir/$soname.def;
-	cat $export_symbols >> $output_objdir/$soname.def;
-      fi~
-      $CC -shared -nostdlib $output_objdir/$soname.def $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000 ${wl}--out-implib,$lib'
-    else
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    fi
-  ;;
-
-  darwin* | rhapsody*)
-   if $CC -v 2>&1 | grep 'Apple' >/dev/null ; then 
-    _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-    case "$host_os" in
-    rhapsody* | darwin1.[[012]])
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)='-undefined suppress'
+    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
+      # PIC is the default for these OSes.
       ;;
-    *) # Darwin 1.3 on
-      test -z ${LD_TWOLEVEL_NAMESPACE} && _LT_AC_TAGVAR(allow_undefined_flag, $1)='-flat_namespace -undefined suppress'
+    mingw* | cygwin* | os2* | pw32* | cegcc*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      # Although the cygwin gcc ignores -fPIC, still need this for old-style
+      # (--disable-auto-import) libraries
+      m4_if([$1], [GCJ], [],
+	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
       ;;
-    esac
-    	lt_int_apple_cc_single_mod=no
-    	output_verbose_link_cmd='echo'
-    	if $CC -dumpspecs 2>&1 | grep 'single_module' >/dev/null ; then
-    	  lt_int_apple_cc_single_mod=yes
-    	fi
-    	if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
-    	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
-    	else
-        _LT_AC_TAGVAR(archive_cmds, $1)='$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
-      fi
-      _LT_AC_TAGVAR(module_cmds, $1)='$CC -bundle ${wl}-bind_at_load $allow_undefined_flag -o $lib $libobjs $deplibs$compiler_flags'
-
-    # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-      if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
-        _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-      else
-        _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-      fi
-        _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -bundle $allow_undefined_flag  -o $lib $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-    _LT_AC_TAGVAR(hardcode_direct, $1)=no
-    _LT_AC_TAGVAR(hardcode_automatic, $1)=yes
-    _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
-    _LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-all_load $convenience'
-    _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-   fi 
-    ;;
-
-  dgux*)
-    case $cc_basename in
-      ec++)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-      ghcx)
-	# Green Hills C++ Compiler
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-      *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-    esac
-    ;;
-  freebsd[12]*)
-    # C++ shared libraries reported to be fairly broken before switch to ELF
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  freebsd-elf*)
-    _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-    ;;
-  freebsd*)
-    # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
-    # conventions
-    _LT_AC_TAGVAR(ld_shlibs, $1)=yes
-    ;;
-  gnu*)
-    ;;
-  hpux9*)
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-    _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-    _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
-    _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-    _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
-				# but as the default
-				# location of the library.
-
-    case $cc_basename in
-    CC)
-      # FIXME: insert proper C++ library support
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
+    darwin* | rhapsody*)
+      # PIC is the default on this platform
+      # Common symbols not allowed in MH_DYLIB files
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
       ;;
-    aCC)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$CC -b ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
-      # Commands to make compiler produce verbose output that lists
-      # what "hidden" libraries, object files and flags are used when
-      # linking a shared library.
-      #
-      # There doesn't appear to be a way to prevent this compiler from
-      # explicitly linking system object files so we need to strip them
-      # from the output so that they don't get included in the library
-      # dependencies.
-      output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | egrep "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
+    *djgpp*)
+      # DJGPP does not support shared libraries at all
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
       ;;
-    *)
-      if test "$GXX" = yes; then
-        _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$CC -shared -nostdlib -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
-      else
-        # FIXME: insert proper C++ library support
-        _LT_AC_TAGVAR(ld_shlibs, $1)=no
+    interix[[3-9]]*)
+      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
+      # Instead, we relocate shared libraries at runtime.
+      ;;
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
       fi
       ;;
-    esac
-    ;;
-  hpux10*|hpux11*)
-    if test $with_gnu_ld = no; then
-      case "$host_cpu" in
+    hpux*)
+      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
+      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
+      # sets the default TLS model and affects inlining.
+      case $host_cpu in
       hppa*64*)
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='+b $libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-        ;;
-      ia64*)
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-        ;;
+	;;
       *)
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-	_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
-        ;;
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	;;
       esac
-    fi
-    case "$host_cpu" in
-    hppa*64*)
-      _LT_AC_TAGVAR(hardcode_direct, $1)=no
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
-    ia64*)
-      _LT_AC_TAGVAR(hardcode_direct, $1)=no
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
-					      # but as the default
-					      # location of the library.
+      ;;
+    *qnx* | *nto*)
+      # QNX uses GNU C++, but need to define -shared option too, otherwise
+      # it will coredump.
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
       ;;
     *)
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
-					      # but as the default
-					      # location of the library.
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
       ;;
     esac
-
-    case $cc_basename in
-      CC)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+  else
+    case $host_os in
+      aix[[4-9]]*)
+	# All AIX code is PIC.
+	if test "$host_cpu" = ia64; then
+	  # AIX 5 now supports IA64 processor
+	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	else
+	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
+	fi
 	;;
-      aCC)
-	case "$host_cpu" in
-	hppa*64*|ia64*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname -o $lib $linker_flags $libobjs $deplibs'
-	  ;;
-	*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+      chorus*)
+	case $cc_basename in
+	cxch68*)
+	  # Green Hills C++ Compiler
+	  # _LT_TAGVAR(lt_prog_compiler_static, $1)="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
 	  ;;
 	esac
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | grep "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
 	;;
-      *)
-	if test "$GXX" = yes; then
-	  if test $with_gnu_ld = no; then
-	    case "$host_cpu" in
-	    ia64*|hppa*64*)
-	      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname -o $lib $linker_flags $libobjs $deplibs'
+      dgux*)
+	case $cc_basename in
+	  ec++*)
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    ;;
+	  ghcx*)
+	    # Green Hills C++ Compiler
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      freebsd* | dragonfly*)
+	# FreeBSD uses GNU C++
+	;;
+      hpux9* | hpux10* | hpux11*)
+	case $cc_basename in
+	  CC*)
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
+	    if test "$host_cpu" != ia64; then
+	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
+	    fi
+	    ;;
+	  aCC*)
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
+	    case $host_cpu in
+	    hppa*64*|ia64*)
+	      # +Z the default
 	      ;;
 	    *)
-	      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
 	      ;;
 	    esac
-	  fi
-	else
-	  # FIXME: insert proper C++ library support
-	  _LT_AC_TAGVAR(ld_shlibs, $1)=no
-	fi
-	;;
-    esac
-    ;;
-  irix5* | irix6*)
-    case $cc_basename in
-      CC)
-	# SGI C++
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -all -multigot $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
-
-	# Archives containing C++ object files must be created using
-	# "CC -ar", where "CC" is the IRIX C++ compiler.  This is
-	# necessary to make sure instantiated templates are included
-	# in the archive.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC -ar -WR,-u -o $oldlib $oldobjs'
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-      *)
-	if test "$GXX" = yes; then
-	  if test "$with_gnu_ld" = no; then
-	    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${objdir}/so_locations -o $lib'
-	  else
-	    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` -o $lib'
-	  fi
-	fi
-	_LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+      interix*)
+	# This is c89, which is MS Visual C++ (no shared libs)
+	# Anyone wants to do a port?
 	;;
-    esac
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-    _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-    ;;
-  linux*)
-    case $cc_basename in
-      KCC)
-	# Kuck and Associates, Inc. (KAI) C++ Compiler
-
-	# KCC will only create a shared library if the output file
-	# ends with ".so" (or ".sl" for HP-UX), so rename the library
-	# to its proper name (with version) after linking.
-	_LT_AC_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib ${wl}-retain-symbols-file,$export_symbols; mv \$templib $lib'
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`$CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1 | grep "ld"`; rm -f libconftest$shared_ext; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath,$libdir'
-	_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
-
-	# Archives containing C++ object files must be created using
-	# "CC -Bstatic", where "CC" is the KAI C++ compiler.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs'
-	;;
-      icpc)
-	# Intel C++
-	with_gnu_ld=yes
-	_LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
-	_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
-	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
-	;;
-      cxx)
-	# Compaq C++
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname  -o $lib ${wl}-retain-symbols-file $wl$export_symbols'
-
-	runpath_var=LD_RUN_PATH
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "ld"`; templist=`echo $templist | $SED "s/\(^.*ld.*\)\( .*ld .*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
+      irix5* | irix6* | nonstopux*)
+	case $cc_basename in
+	  CC*)
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    # CC pic flag -KPIC is the default.
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-    esac
-    ;;
-  lynxos*)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  m88k*)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  mvs*)
-    case $cc_basename in
-      cxx)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      linux* | k*bsd*-gnu)
+	case $cc_basename in
+	  KCC*)
+	    # KAI C++ Compiler
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	    ;;
+	  ecpc* )
+	    # old Intel C++ for x86_64 which still supported -KPIC.
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
+	    ;;
+	  icpc* )
+	    # Intel C++, used to be incompatible with GCC.
+	    # ICC 10 doesn't accept -KPIC any more.
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
+	    ;;
+	  pgCC* | pgcpp*)
+	    # Portland Group C++ compiler
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    ;;
+	  cxx*)
+	    # Compaq C++
+	    # Make sure the PIC flag is empty.  It appears that all Alpha
+	    # Linux and Compaq Tru64 Unix objects are PIC.
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    ;;
+	  xlc* | xlC*)
+	    # IBM XL 8.0 on PPC
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
+	    ;;
+	  *)
+	    case `$CC -V 2>&1 | sed 5q` in
+	    *Sun\ C*)
+	      # Sun C++ 5.9
+	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
+	      ;;
+	    esac
+	    ;;
+	esac
 	;;
-      *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      lynxos*)
 	;;
-    esac
-    ;;
-  netbsd*)
-    if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
-      wlarc=
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-    fi
-    # Workaround some broken pre-1.5 toolchains
-    output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
-    ;;
-  osf3*)
-    case $cc_basename in
-      KCC)
-	# Kuck and Associates, Inc. (KAI) C++ Compiler
-
-	# KCC will only create a shared library if the output file
-	# ends with ".so" (or ".sl" for HP-UX), so rename the library
-	# to its proper name (with version) after linking.
-	_LT_AC_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	# Archives containing C++ object files must be created using
-	# "CC -Bstatic", where "CC" is the KAI C++ compiler.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs'
-
-	;;
-      RCC)
-	# Rational C++ 2.4.1
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-      cxx)
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $soname `test -n "$verstring" && echo ${wl}-set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "ld" | grep -v "ld:"`; templist=`echo $templist | $SED "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
+      m88k*)
 	;;
-      *)
-	if test "$GXX" = yes && test "$with_gnu_ld" = no; then
-	  _LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${objdir}/so_locations -o $lib'
-
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	  # Commands to make compiler produce verbose output that lists
-	  # what "hidden" libraries, object files and flags are used when
-	  # linking a shared library.
-	  output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "\-L"'
-
-	else
-	  # FIXME: insert proper C++ library support
-	  _LT_AC_TAGVAR(ld_shlibs, $1)=no
-	fi
+      mvs*)
+	case $cc_basename in
+	  cxx*)
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-W c,exportall'
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-    esac
-    ;;
-  osf4* | osf5*)
-    case $cc_basename in
-      KCC)
-	# Kuck and Associates, Inc. (KAI) C++ Compiler
-
-	# KCC will only create a shared library if the output file
-	# ends with ".so" (or ".sl" for HP-UX), so rename the library
-	# to its proper name (with version) after linking.
-	_LT_AC_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	# Archives containing C++ object files must be created using
-	# the KAI C++ compiler.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC -o $oldlib $oldobjs'
-	;;
-      RCC)
-	# Rational C++ 2.4.1
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-      cxx)
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done~
-	  echo "-hidden">> $lib.exp~
-	  $CC -shared$allow_undefined_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname -Wl,-input -Wl,$lib.exp  `test -n "$verstring" && echo -set_version	$verstring` -update_registry $objdir/so_locations -o $lib~
-	  $rm $lib.exp'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
-	_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "ld" | grep -v "ld:"`; templist=`echo $templist | $SED "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
+      netbsd*)
 	;;
-      *)
-	if test "$GXX" = yes && test "$with_gnu_ld" = no; then
-	  _LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
-	 _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${objdir}/so_locations -o $lib'
-
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-
-	  # Commands to make compiler produce verbose output that lists
-	  # what "hidden" libraries, object files and flags are used when
-	  # linking a shared library.
-	  output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep "\-L"'
-
-	else
-	  # FIXME: insert proper C++ library support
-	  _LT_AC_TAGVAR(ld_shlibs, $1)=no
-	fi
+      *qnx* | *nto*)
+        # QNX uses GNU C++, but need to define -shared option too, otherwise
+        # it will coredump.
+        _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
+        ;;
+      osf3* | osf4* | osf5*)
+	case $cc_basename in
+	  KCC*)
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
+	    ;;
+	  RCC*)
+	    # Rational C++ 2.4.1
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  cxx*)
+	    # Digital/Compaq C++
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    # Make sure the PIC flag is empty.  It appears that all Alpha
+	    # Linux and Compaq Tru64 Unix objects are PIC.
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-    esac
-    ;;
-  psos*)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  sco*)
-    _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-    case $cc_basename in
-      CC)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      psos*)
 	;;
-      *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      solaris*)
+	case $cc_basename in
+	  CC*)
+	    # Sun C++ 4.2, 5.x and Centerline C++
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
+	    ;;
+	  gcx*)
+	    # Green Hills C++ Compiler
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-    esac
-    ;;
-  sunos4*)
-    case $cc_basename in
-      CC)
-	# Sun C++ 4.x
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	;;
-      lcc)
-	# Lucid
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      sunos4*)
+	case $cc_basename in
+	  CC*)
+	    # Sun C++ 4.x
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    ;;
+	  lcc*)
+	    # Lucid
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  *)
+	    ;;
+	esac
 	;;
-      *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
+	case $cc_basename in
+	  CC*)
+	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    ;;
+	esac
 	;;
-    esac
-    ;;
-  solaris*)
-    case $cc_basename in
-      CC)
-	# Sun C++ 4.2, 5.x and Centerline C++
-	_LT_AC_TAGVAR(no_undefined_flag, $1)=' -zdefs'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -nolib -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-	$CC -G${allow_undefined_flag} -nolib ${wl}-M ${wl}$lib.exp -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$rm $lib.exp'
-
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-	_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-	case $host_os in
-	  solaris2.[0-5] | solaris2.[0-5].*) ;;
+      tandem*)
+	case $cc_basename in
+	  NCC*)
+	    # NonStop-UX NCC 3.20
+	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    ;;
 	  *)
-	    # The C++ compiler is used as linker so we must use $wl
-	    # flag to pass the commands to the underlying system
-	    # linker.
-	    # Supported since Solaris 2.6 (maybe 2.5.1?)
-	    _LT_AC_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
 	    ;;
 	esac
-	_LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-
-	# Commands to make compiler produce verbose output that lists
-	# what "hidden" libraries, object files and flags are used when
-	# linking a shared library.
-	#
-	# There doesn't appear to be a way to prevent this compiler from
-	# explicitly linking system object files so we need to strip them
-	# from the output so that they don't get included in the library
-	# dependencies.
-	output_verbose_link_cmd='templist=`$CC -G $CFLAGS -v conftest.$objext 2>&1 | grep "\-[[LR]]"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
-
-	# Archives containing C++ object files must be created using
-	# "CC -xar", where "CC" is the Sun C++ compiler.  This is
-	# necessary to make sure instantiated templates are included
-	# in the archive.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
-	;;
-      gcx)
-	# Green Hills C++ Compiler
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
-
-	# The C++ compiler must be used to create the archive.
-	_LT_AC_TAGVAR(old_archive_cmds, $1)='$CC $LDFLAGS -archive -o $oldlib $oldobjs'
-	;;
-      *)
-	# GNU C++ compiler with Solaris linker
-	if test "$GXX" = yes && test "$with_gnu_ld" = no; then
-	  _LT_AC_TAGVAR(no_undefined_flag, $1)=' ${wl}-z ${wl}defs'
-	  if $CC --version | grep -v '^2\.7' > /dev/null; then
-	    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
-	    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-		$CC -shared -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$rm $lib.exp'
-
-	    # Commands to make compiler produce verbose output that lists
-	    # what "hidden" libraries, object files and flags are used when
-	    # linking a shared library.
-	    output_verbose_link_cmd="$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep \"\-L\""
-	  else
-	    # g++ 2.7 appears to require `-G' NOT `-shared' on this
-	    # platform.
-	    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -G -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
-	    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-		$CC -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$rm $lib.exp'
-
-	    # Commands to make compiler produce verbose output that lists
-	    # what "hidden" libraries, object files and flags are used when
-	    # linking a shared library.
-	    output_verbose_link_cmd="$CC -G $CFLAGS -v conftest.$objext 2>&1 | grep \"\-L\""
-	  fi
-
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $wl$libdir'
-	fi
 	;;
-    esac
-    ;;
-  sysv5OpenUNIX8* | sysv5UnixWare7* | sysv5uw[[78]]* | unixware7*)
-    _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-    ;;
-  tandem*)
-    case $cc_basename in
-      NCC)
-	# NonStop-UX NCC 3.20
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      vxworks*)
 	;;
       *)
-	# FIXME: insert proper C++ library support
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+	_LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
 	;;
     esac
-    ;;
-  vxworks*)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-  *)
-    # FIXME: insert proper C++ library support
-    _LT_AC_TAGVAR(ld_shlibs, $1)=no
-    ;;
-esac
-AC_MSG_RESULT([$_LT_AC_TAGVAR(ld_shlibs, $1)])
-test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
+  fi
+],
+[
+  if test "$GCC" = yes; then
+    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
 
-_LT_AC_TAGVAR(GCC, $1)="$GXX"
-_LT_AC_TAGVAR(LD, $1)="$LD"
+    case $host_os in
+      aix*)
+      # All AIX code is PIC.
+      if test "$host_cpu" = ia64; then
+	# AIX 5 now supports IA64 processor
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      fi
+      ;;
 
-AC_LIBTOOL_POSTDEP_PREDEP($1)
-AC_LIBTOOL_PROG_COMPILER_PIC($1)
-AC_LIBTOOL_PROG_CC_C_O($1)
-AC_LIBTOOL_SYS_HARD_LINK_LOCKS($1)
-AC_LIBTOOL_PROG_LD_SHLIBS($1)
-AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH($1)
-AC_LIBTOOL_SYS_LIB_STRIP
-AC_LIBTOOL_SYS_DYNAMIC_LINKER($1)
-AC_LIBTOOL_DLOPEN_SELF($1)
+    amigaos*)
+      case $host_cpu in
+      powerpc)
+            # see comment about AmigaOS4 .so support
+            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+        ;;
+      m68k)
+            # FIXME: we need at least 68020 code to build shared libraries, but
+            # adding the `-m68020' flag to GCC prevents building anything better,
+            # like `-m68040'.
+            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
+        ;;
+      esac
+      ;;
 
-AC_LIBTOOL_CONFIG($1)
+    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
+      # PIC is the default for these OSes.
+      ;;
 
-AC_LANG_POP
-CC=$lt_save_CC
-LDCXX=$LD
-LD=$lt_save_LD
-GCC=$lt_save_GCC
-with_gnu_ldcxx=$with_gnu_ld
-with_gnu_ld=$lt_save_with_gnu_ld
-lt_cv_path_LDCXX=$lt_cv_path_LD
-lt_cv_path_LD=$lt_save_path_LD
-lt_cv_prog_gnu_ldcxx=$lt_cv_prog_gnu_ld
-lt_cv_prog_gnu_ld=$lt_save_with_gnu_ld
-])# AC_LIBTOOL_LANG_CXX_CONFIG
+    mingw* | cygwin* | pw32* | os2* | cegcc*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      # Although the cygwin gcc ignores -fPIC, still need this for old-style
+      # (--disable-auto-import) libraries
+      m4_if([$1], [GCJ], [],
+	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
+      ;;
 
-# AC_LIBTOOL_POSTDEP_PREDEP([TAGNAME])
-# ------------------------
-# Figure out "hidden" library dependencies from verbose
-# compiler output when linking a shared library.
-# Parse the compiler output and extract the necessary
-# objects, libraries and library flags.
-AC_DEFUN([AC_LIBTOOL_POSTDEP_PREDEP],[
-dnl we can't use the lt_simple_compile_test_code here,
-dnl because it contains code intended for an executable,
-dnl not a library.  It's possible we should let each
-dnl tag define a new lt_????_link_test_code variable,
-dnl but it's only used here...
-ifelse([$1],[],[cat > conftest.$ac_ext <<EOF
-int a;
-void foo (void) { a = 0; }
-EOF
-],[$1],[CXX],[cat > conftest.$ac_ext <<EOF
-class Foo
-{
-public:
-  Foo (void) { a = 0; }
-private:
-  int a;
-};
-EOF
-],[$1],[F77],[cat > conftest.$ac_ext <<EOF
-      subroutine foo
-      implicit none
-      integer*4 a
-      a=0
-      return
-      end
-EOF
-],[$1],[GCJ],[cat > conftest.$ac_ext <<EOF
-public class foo {
-  private int a;
-  public void bar (void) {
-    a = 0;
-  }
-};
-EOF
-])
-dnl Parse the compiler output and extract the necessary
-dnl objects, libraries and library flags.
-if AC_TRY_EVAL(ac_compile); then
-  # Parse the compiler output and extract the necessary
-  # objects, libraries and library flags.
-
-  # Sentinel used to keep track of whether or not we are before
-  # the conftest object file.
-  pre_test_object_deps_done=no
+    darwin* | rhapsody*)
+      # PIC is the default on this platform
+      # Common symbols not allowed in MH_DYLIB files
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      ;;
 
-  # The `*' in the case matches for architectures that use `case' in
-  # $output_verbose_cmd can trigger glob expansion during the loop
-  # eval without this substitution.
-  output_verbose_link_cmd="`$echo \"X$output_verbose_link_cmd\" | $Xsed -e \"$no_glob_subst\"`"
+    hpux*)
+      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
+      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
+      # sets the default TLS model and affects inlining.
+      case $host_cpu in
+      hppa*64*)
+	# +Z the default
+	;;
+      *)
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	;;
+      esac
+      ;;
 
-  for p in `eval $output_verbose_link_cmd`; do
-    case $p in
+    interix[[3-9]]*)
+      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
+      # Instead, we relocate shared libraries at runtime.
+      ;;
 
-    -L* | -R* | -l*)
-       # Some compilers place space between "-{L,R}" and the path.
-       # Remove the space.
-       if test $p = "-L" \
-	  || test $p = "-R"; then
-	 prev=$p
-	 continue
-       else
-	 prev=
-       fi
+    msdosdjgpp*)
+      # Just because we use GCC doesn't mean we suddenly get shared libraries
+      # on systems that don't support them.
+      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      enable_shared=no
+      ;;
 
-       if test "$pre_test_object_deps_done" = no; then
-	 case $p in
-	 -L* | -R*)
-	   # Internal compiler library paths should come after those
-	   # provided the user.  The postdeps already come after the
-	   # user supplied libs so there is no need to process them.
-	   if test -z "$_LT_AC_TAGVAR(compiler_lib_search_path, $1)"; then
-	     _LT_AC_TAGVAR(compiler_lib_search_path, $1)="${prev}${p}"
-	   else
-	     _LT_AC_TAGVAR(compiler_lib_search_path, $1)="${_LT_AC_TAGVAR(compiler_lib_search_path, $1)} ${prev}${p}"
-	   fi
-	   ;;
-	 # The "-l" case would never come before the object being
-	 # linked, so don't bother handling this case.
-	 esac
-       else
-	 if test -z "$_LT_AC_TAGVAR(postdeps, $1)"; then
-	   _LT_AC_TAGVAR(postdeps, $1)="${prev}${p}"
-	 else
-	   _LT_AC_TAGVAR(postdeps, $1)="${_LT_AC_TAGVAR(postdeps, $1)} ${prev}${p}"
-	 fi
-       fi
-       ;;
+    *nto* | *qnx*)
+      # QNX uses GNU C++, but need to define -shared option too, otherwise
+      # it will coredump.
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
+      ;;
 
-    *.$objext)
-       # This assumes that the test object file only shows up
-       # once in the compiler output.
-       if test "$p" = "conftest.$objext"; then
-	 pre_test_object_deps_done=yes
-	 continue
-       fi
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
+      fi
+      ;;
 
-       if test "$pre_test_object_deps_done" = no; then
-	 if test -z "$_LT_AC_TAGVAR(predep_objects, $1)"; then
-	   _LT_AC_TAGVAR(predep_objects, $1)="$p"
-	 else
-	   _LT_AC_TAGVAR(predep_objects, $1)="$_LT_AC_TAGVAR(predep_objects, $1) $p"
-	 fi
-       else
-	 if test -z "$_LT_AC_TAGVAR(postdep_objects, $1)"; then
-	   _LT_AC_TAGVAR(postdep_objects, $1)="$p"
-	 else
-	   _LT_AC_TAGVAR(postdep_objects, $1)="$_LT_AC_TAGVAR(postdep_objects, $1) $p"
-	 fi
-       fi
-       ;;
+    *)
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+      ;;
+    esac
+  else
+    # PORTME Check for flag to pass linker flags through the system compiler.
+    case $host_os in
+    aix*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      if test "$host_cpu" = ia64; then
+	# AIX 5 now supports IA64 processor
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      else
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
+      fi
+      ;;
 
-    *) ;; # Ignore the rest.
+    mingw* | cygwin* | pw32* | os2* | cegcc*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      m4_if([$1], [GCJ], [],
+	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
+      ;;
 
-    esac
-  done
+    hpux9* | hpux10* | hpux11*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
+      # not for PA HP-UX.
+      case $host_cpu in
+      hppa*64*|ia64*)
+	# +Z the default
+	;;
+      *)
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
+	;;
+      esac
+      # Is there a better lt_prog_compiler_static that works with the bundled CC?
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
+      ;;
 
-  # Clean up.
-  rm -f a.out a.exe
-else
-  echo "libtool.m4: error: problem compiling $1 test program"
-fi
+    irix5* | irix6* | nonstopux*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # PIC (with -KPIC) is the default.
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+      ;;
 
-$rm -f confest.$objext
+    linux* | k*bsd*-gnu)
+      case $cc_basename in
+      # old Intel for x86_64 which still supported -KPIC.
+      ecc*)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
+        ;;
+      # icc used to be incompatible with GCC.
+      # ICC 10 doesn't accept -KPIC any more.
+      icc* | ifort*)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
+        ;;
+      # Lahey Fortran 8.1.
+      lf95*)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='--shared'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='--static'
+	;;
+      pgcc* | pgf77* | pgf90* | pgf95*)
+        # Portland Group compilers (*not* the Pentium gcc compiler,
+	# which looks to be a dead project)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+        ;;
+      ccc*)
+        _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+        # All Alpha code is PIC.
+        _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+        ;;
+      xl*)
+	# IBM XL C 8.0/Fortran 10.1 on PPC
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
+	;;
+      *)
+	case `$CC -V 2>&1 | sed 5q` in
+	*Sun\ C*)
+	  # Sun C 5.9
+	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	  ;;
+	*Sun\ F*)
+	  # Sun Fortran 8.3 passes all unrecognized flags to the linker
+	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	  _LT_TAGVAR(lt_prog_compiler_wl, $1)=''
+	  ;;
+	esac
+	;;
+      esac
+      ;;
 
-case " $_LT_AC_TAGVAR(postdeps, $1) " in
-*" -lc "*) _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no ;;
-esac
-])# AC_LIBTOOL_POSTDEP_PREDEP
+    newsos6)
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# AC_LIBTOOL_LANG_F77_CONFIG
-# ------------------------
-# Ensure that the configuration vars for the C compiler are
-# suitably defined.  Those variables are subsequently used by
-# AC_LIBTOOL_CONFIG to write the compiler configuration to `libtool'.
-AC_DEFUN([AC_LIBTOOL_LANG_F77_CONFIG], [_LT_AC_LANG_F77_CONFIG(F77)])
-AC_DEFUN([_LT_AC_LANG_F77_CONFIG],
-[AC_REQUIRE([AC_PROG_F77])
-AC_LANG_PUSH(Fortran 77)
+    *nto* | *qnx*)
+      # QNX uses GNU C++, but need to define -shared option too, otherwise
+      # it will coredump.
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
+      ;;
 
-_LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-_LT_AC_TAGVAR(allow_undefined_flag, $1)=
-_LT_AC_TAGVAR(always_export_symbols, $1)=no
-_LT_AC_TAGVAR(archive_expsym_cmds, $1)=
-_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=
-_LT_AC_TAGVAR(hardcode_direct, $1)=no
-_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
-_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
-_LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
-_LT_AC_TAGVAR(hardcode_minus_L, $1)=no
-_LT_AC_TAGVAR(hardcode_automatic, $1)=no
-_LT_AC_TAGVAR(module_cmds, $1)=
-_LT_AC_TAGVAR(module_expsym_cmds, $1)=
-_LT_AC_TAGVAR(link_all_deplibs, $1)=unknown
-_LT_AC_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
-_LT_AC_TAGVAR(no_undefined_flag, $1)=
-_LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
-_LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+    osf3* | osf4* | osf5*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # All OSF/1 code is PIC.
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+      ;;
 
-# Source file extension for f77 test sources.
-ac_ext=f
+    rdos*)
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+      ;;
 
-# Object file extension for compiled f77 test sources.
-objext=o
-_LT_AC_TAGVAR(objext, $1)=$objext
+    solaris*)
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      case $cc_basename in
+      f77* | f90* | f95*)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld ';;
+      *)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,';;
+      esac
+      ;;
 
-# Code to be used in simple compile tests
-lt_simple_compile_test_code="      subroutine t\n      return\n      end\n"
+    sunos4*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# Code to be used in simple link tests
-lt_simple_link_test_code="      program t\n      end\n"
+    sysv4 | sysv4.2uw2* | sysv4.3*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# ltmain only uses $CC for tagged configurations so make sure $CC is set.
-_LT_AC_SYS_COMPILER
+    sysv4*MP*)
+      if test -d /usr/nec ;then
+	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-Kconform_pic'
+	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      fi
+      ;;
 
-# Allow CC to be a program name with arguments.
-lt_save_CC="$CC"
-CC=${F77-"f77"}
-compiler=$CC
-_LT_AC_TAGVAR(compiler, $1)=$CC
-cc_basename=`$echo X"$compiler" | $Xsed -e 's%^.*/%%'`
+    sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-AC_MSG_CHECKING([if libtool supports shared libraries])
-AC_MSG_RESULT([$can_build_shared])
+    unicos*)
+      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      ;;
 
-AC_MSG_CHECKING([whether to build shared libraries])
-test "$can_build_shared" = "no" && enable_shared=no
+    uts4*)
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# On AIX, shared libraries and static libraries use the same namespace, and
-# are all built from PIC.
-case "$host_os" in
-aix3*)
-  test "$enable_shared" = yes && enable_static=no
-  if test -n "$RANLIB"; then
-    archive_cmds="$archive_cmds~\$RANLIB \$lib"
-    postinstall_cmds='$RANLIB $lib'
+    *)
+      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      ;;
+    esac
   fi
-  ;;
-aix4*)
-  test "$enable_shared" = yes && enable_static=no
-  ;;
+])
+case $host_os in
+  # For platforms which do not support PIC, -DPIC is meaningless:
+  *djgpp*)
+    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+    ;;
+  *)
+    _LT_TAGVAR(lt_prog_compiler_pic, $1)="$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])"
+    ;;
 esac
-AC_MSG_RESULT([$enable_shared])
-
-AC_MSG_CHECKING([whether to build static libraries])
-# Make sure either enable_shared or enable_static is yes.
-test "$enable_shared" = yes || enable_static=yes
-AC_MSG_RESULT([$enable_static])
-
-test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
-
-_LT_AC_TAGVAR(GCC, $1)="$G77"
-_LT_AC_TAGVAR(LD, $1)="$LD"
-
-AC_LIBTOOL_PROG_COMPILER_PIC($1)
-AC_LIBTOOL_PROG_CC_C_O($1)
-AC_LIBTOOL_SYS_HARD_LINK_LOCKS($1)
-AC_LIBTOOL_PROG_LD_SHLIBS($1)
-AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH($1)
-AC_LIBTOOL_SYS_LIB_STRIP
-AC_LIBTOOL_SYS_DYNAMIC_LINKER($1)
+AC_MSG_RESULT([$_LT_TAGVAR(lt_prog_compiler_pic, $1)])
+_LT_TAGDECL([wl], [lt_prog_compiler_wl], [1],
+	[How to pass a linker flag through the compiler])
 
-AC_LIBTOOL_CONFIG($1)
+#
+# Check to make sure the PIC flag actually works.
+#
+if test -n "$_LT_TAGVAR(lt_prog_compiler_pic, $1)"; then
+  _LT_COMPILER_OPTION([if $compiler PIC flag $_LT_TAGVAR(lt_prog_compiler_pic, $1) works],
+    [_LT_TAGVAR(lt_cv_prog_compiler_pic_works, $1)],
+    [$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])], [],
+    [case $_LT_TAGVAR(lt_prog_compiler_pic, $1) in
+     "" | " "*) ;;
+     *) _LT_TAGVAR(lt_prog_compiler_pic, $1)=" $_LT_TAGVAR(lt_prog_compiler_pic, $1)" ;;
+     esac],
+    [_LT_TAGVAR(lt_prog_compiler_pic, $1)=
+     _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no])
+fi
+_LT_TAGDECL([pic_flag], [lt_prog_compiler_pic], [1],
+	[Additional compiler flags for building library objects])
 
-AC_LANG_POP
-CC="$lt_save_CC"
-])# AC_LIBTOOL_LANG_F77_CONFIG
+#
+# Check to make sure the static flag actually works.
+#
+wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1) eval lt_tmp_static_flag=\"$_LT_TAGVAR(lt_prog_compiler_static, $1)\"
+_LT_LINKER_OPTION([if $compiler static flag $lt_tmp_static_flag works],
+  _LT_TAGVAR(lt_cv_prog_compiler_static_works, $1),
+  $lt_tmp_static_flag,
+  [],
+  [_LT_TAGVAR(lt_prog_compiler_static, $1)=])
+_LT_TAGDECL([link_static_flag], [lt_prog_compiler_static], [1],
+	[Compiler flag to prevent dynamic linking])
+])# _LT_COMPILER_PIC
 
 
-# AC_LIBTOOL_LANG_GCJ_CONFIG
-# --------------------------
-# Ensure that the configuration vars for the C compiler are
-# suitably defined.  Those variables are subsequently used by
-# AC_LIBTOOL_CONFIG to write the compiler configuration to `libtool'.
-AC_DEFUN([AC_LIBTOOL_LANG_GCJ_CONFIG], [_LT_AC_LANG_GCJ_CONFIG(GCJ)])
-AC_DEFUN([_LT_AC_LANG_GCJ_CONFIG],
-[AC_LANG_SAVE
+# _LT_LINKER_SHLIBS([TAGNAME])
+# ----------------------------
+# See if the linker supports building shared libraries.
+m4_defun([_LT_LINKER_SHLIBS],
+[AC_REQUIRE([LT_PATH_LD])dnl
+AC_REQUIRE([LT_PATH_NM])dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_DECL_EGREP])dnl
+m4_require([_LT_DECL_SED])dnl
+m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl
+m4_require([_LT_TAG_COMPILER])dnl
+AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
+m4_if([$1], [CXX], [
+  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
+  case $host_os in
+  aix[[4-9]]*)
+    # If we're using GNU nm, then we don't want the "-C" option.
+    # -C means demangle to AIX nm, but means don't demangle with GNU nm
+    if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
+      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
+    else
+      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
+    fi
+    ;;
+  pw32*)
+    _LT_TAGVAR(export_symbols_cmds, $1)="$ltdll_cmds"
+  ;;
+  cygwin* | mingw* | cegcc*)
+    _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/;/^.*[[ ]]__nm__/s/^.*[[ ]]__nm__\([[^ ]]*\)[[ ]][[^ ]]*/\1 DATA/;/^I[[ ]]/d;/^[[AITW]][[ ]]/s/.* //'\'' | sort | uniq > $export_symbols'
+  ;;
+  *)
+    _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
+  ;;
+  esac
+  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
+], [
+  runpath_var=
+  _LT_TAGVAR(allow_undefined_flag, $1)=
+  _LT_TAGVAR(always_export_symbols, $1)=no
+  _LT_TAGVAR(archive_cmds, $1)=
+  _LT_TAGVAR(archive_expsym_cmds, $1)=
+  _LT_TAGVAR(compiler_needs_object, $1)=no
+  _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+  _LT_TAGVAR(export_dynamic_flag_spec, $1)=
+  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
+  _LT_TAGVAR(hardcode_automatic, $1)=no
+  _LT_TAGVAR(hardcode_direct, $1)=no
+  _LT_TAGVAR(hardcode_direct_absolute, $1)=no
+  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+  _LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
+  _LT_TAGVAR(hardcode_libdir_separator, $1)=
+  _LT_TAGVAR(hardcode_minus_L, $1)=no
+  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
+  _LT_TAGVAR(inherit_rpath, $1)=no
+  _LT_TAGVAR(link_all_deplibs, $1)=unknown
+  _LT_TAGVAR(module_cmds, $1)=
+  _LT_TAGVAR(module_expsym_cmds, $1)=
+  _LT_TAGVAR(old_archive_from_new_cmds, $1)=
+  _LT_TAGVAR(old_archive_from_expsyms_cmds, $1)=
+  _LT_TAGVAR(thread_safe_flag_spec, $1)=
+  _LT_TAGVAR(whole_archive_flag_spec, $1)=
+  # include_expsyms should be a list of space-separated symbols to be *always*
+  # included in the symbol list
+  _LT_TAGVAR(include_expsyms, $1)=
+  # exclude_expsyms can be an extended regexp of symbols to exclude
+  # it will be wrapped by ` (' and `)$', so one must not match beginning or
+  # end of line.  Example: `a|bc|.*d.*' will exclude the symbols `a' and `bc',
+  # as well as any symbol that contains `d'.
+  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
+  # Although _GLOBAL_OFFSET_TABLE_ is a valid symbol C name, most a.out
+  # platforms (ab)use it in PIC code, but their linkers get confused if
+  # the symbol is explicitly referenced.  Since portable code cannot
+  # rely on this symbol name, it's probably fine to never include it in
+  # preloaded symbol tables.
+  # Exclude shared library initialization/finalization symbols.
+dnl Note also adjust exclude_expsyms for C++ above.
+  extract_expsyms_cmds=
 
-# Source file extension for Java test sources.
-ac_ext=java
+  case $host_os in
+  cygwin* | mingw* | pw32* | cegcc*)
+    # FIXME: the MSVC++ port hasn't been tested in a loooong time
+    # When not using gcc, we currently assume that we are using
+    # Microsoft Visual C++.
+    if test "$GCC" != yes; then
+      with_gnu_ld=no
+    fi
+    ;;
+  interix*)
+    # we just hope/assume this is gcc and not c89 (= MSVC++)
+    with_gnu_ld=yes
+    ;;
+  openbsd*)
+    with_gnu_ld=no
+    ;;
+  esac
 
-# Object file extension for compiled Java test sources.
-objext=o
-_LT_AC_TAGVAR(objext, $1)=$objext
+  _LT_TAGVAR(ld_shlibs, $1)=yes
+  if test "$with_gnu_ld" = yes; then
+    # If archive_cmds runs LD, not CC, wlarc should be empty
+    wlarc='${wl}'
 
-# Code to be used in simple compile tests
-lt_simple_compile_test_code="class foo {}\n"
-
-# Code to be used in simple link tests
-lt_simple_link_test_code='public class conftest { public static void main(String[] argv) {}; }\n'
+    # Set some defaults for GNU ld with shared library support. These
+    # are reset later if shared libraries are not supported. Putting them
+    # here allows them to be overridden if necessary.
+    runpath_var=LD_RUN_PATH
+    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+    # ancient GNU ld didn't support --whole-archive et. al.
+    if $LD --help 2>&1 | $GREP 'no-whole-archive' > /dev/null; then
+      _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+    else
+      _LT_TAGVAR(whole_archive_flag_spec, $1)=
+    fi
+    supports_anon_versioning=no
+    case `$LD -v 2>&1` in
+      *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.10.*) ;; # catch versions < 2.11
+      *\ 2.11.93.0.2\ *) supports_anon_versioning=yes ;; # RH7.3 ...
+      *\ 2.11.92.0.12\ *) supports_anon_versioning=yes ;; # Mandrake 8.2 ...
+      *\ 2.11.*) ;; # other 2.11 versions
+      *) supports_anon_versioning=yes ;;
+    esac
 
-# ltmain only uses $CC for tagged configurations so make sure $CC is set.
-_LT_AC_SYS_COMPILER
+    # See if GNU ld supports shared libraries.
+    case $host_os in
+    aix[[3-9]]*)
+      # On AIX/PPC, the GNU linker is very broken
+      if test "$host_cpu" != ia64; then
+	_LT_TAGVAR(ld_shlibs, $1)=no
+	cat <<_LT_EOF 1>&2
 
-# Allow CC to be a program name with arguments.
-lt_save_CC="$CC"
-CC=${GCJ-"gcj"}
-compiler=$CC
-_LT_AC_TAGVAR(compiler, $1)=$CC
+*** Warning: the GNU linker, at least up to release 2.9.1, is reported
+*** to be unable to reliably create shared libraries on AIX.
+*** Therefore, libtool is disabling shared libraries support.  If you
+*** really care for shared libraries, you may want to modify your PATH
+*** so that a non-GNU linker is found, and then restart.
 
-# GCJ did not exist at the time GCC didn't implicitly link libc in.
-_LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
+_LT_EOF
+      fi
+      ;;
 
-AC_LIBTOOL_PROG_COMPILER_NO_RTTI($1)
-AC_LIBTOOL_PROG_COMPILER_PIC($1)
-AC_LIBTOOL_PROG_CC_C_O($1)
-AC_LIBTOOL_SYS_HARD_LINK_LOCKS($1)
-AC_LIBTOOL_PROG_LD_SHLIBS($1)
-AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH($1)
-AC_LIBTOOL_SYS_LIB_STRIP
-AC_LIBTOOL_SYS_DYNAMIC_LINKER($1)
-AC_LIBTOOL_DLOPEN_SELF($1)
+    amigaos*)
+      case $host_cpu in
+      powerpc)
+            # see comment about AmigaOS4 .so support
+            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+            _LT_TAGVAR(archive_expsym_cmds, $1)=''
+        ;;
+      m68k)
+            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
+            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+            _LT_TAGVAR(hardcode_minus_L, $1)=yes
+        ;;
+      esac
+      ;;
 
-AC_LIBTOOL_CONFIG($1)
+    beos*)
+      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
+	_LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+	# Joseph Beckenbach <jrb3@best.com> says some releases of gcc
+	# support --undefined.  This deserves some investigation.  FIXME
+	_LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      else
+	_LT_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-AC_LANG_RESTORE
-CC="$lt_save_CC"
-])# AC_LIBTOOL_LANG_GCJ_CONFIG
+    cygwin* | mingw* | pw32* | cegcc*)
+      # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
+      # as there is no search path for DLLs.
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_TAGVAR(always_export_symbols, $1)=no
+      _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
+      _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]][[ ]]/s/.*[[ ]]//'\'' | sort | uniq > $export_symbols'
 
+      if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
+        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
+	# If the export-symbols file already is a .def file (1st line
+	# is EXPORTS), use it as is; otherwise, prepend...
+	_LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
+	  cp $export_symbols $output_objdir/$soname.def;
+	else
+	  echo EXPORTS > $output_objdir/$soname.def;
+	  cat $export_symbols >> $output_objdir/$soname.def;
+	fi~
+	$CC -shared $output_objdir/$soname.def $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
+      else
+	_LT_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-# AC_LIBTOOL_LANG_RC_CONFIG
-# --------------------------
-# Ensure that the configuration vars for the Windows resource compiler are
-# suitably defined.  Those variables are subsequently used by
-# AC_LIBTOOL_CONFIG to write the compiler configuration to `libtool'.
-AC_DEFUN([AC_LIBTOOL_LANG_RC_CONFIG], [_LT_AC_LANG_RC_CONFIG(RC)])
-AC_DEFUN([_LT_AC_LANG_RC_CONFIG],
-[AC_LANG_SAVE
+    interix[[3-9]]*)
+      _LT_TAGVAR(hardcode_direct, $1)=no
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      # Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
+      # Instead, shared libraries are loaded at an image base (0x10000000 by
+      # default) and relocated if they conflict, which is a slow very memory
+      # consuming and fragmenting process.  To avoid this, we pick a random,
+      # 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
+      # time.  Moving up from 0x10000000 also allows more sbrk(2) space.
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
+      ;;
+
+    gnu* | linux* | tpf* | k*bsd*-gnu)
+      tmp_diet=no
+      if test "$host_os" = linux-dietlibc; then
+	case $cc_basename in
+	  diet\ *) tmp_diet=yes;;	# linux-dietlibc with static linking (!diet-dyn)
+	esac
+      fi
+      if $LD --help 2>&1 | $EGREP ': supported targets:.* elf' > /dev/null \
+	 && test "$tmp_diet" = no
+      then
+	tmp_addflag=
+	tmp_sharedflag='-shared'
+	case $cc_basename,$host_cpu in
+        pgcc*)				# Portland Group C compiler
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; $ECHO \"$new_convenience\"` ${wl}--no-whole-archive'
+	  tmp_addflag=' $pic_flag'
+	  ;;
+	pgf77* | pgf90* | pgf95*)	# Portland Group f77 and f90 compilers
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; $ECHO \"$new_convenience\"` ${wl}--no-whole-archive'
+	  tmp_addflag=' $pic_flag -Mnomain' ;;
+	ecc*,ia64* | icc*,ia64*)	# Intel C compiler on ia64
+	  tmp_addflag=' -i_dynamic' ;;
+	efc*,ia64* | ifort*,ia64*)	# Intel Fortran compiler on ia64
+	  tmp_addflag=' -i_dynamic -nofor_main' ;;
+	ifc* | ifort*)			# Intel Fortran compiler
+	  tmp_addflag=' -nofor_main' ;;
+	lf95*)				# Lahey Fortran 8.1
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)=
+	  tmp_sharedflag='--shared' ;;
+	xl[[cC]]*)			# IBM XL C 8.0 on PPC (deal with xlf below)
+	  tmp_sharedflag='-qmkshrobj'
+	  tmp_addflag= ;;
+	esac
+	case `$CC -V 2>&1 | sed 5q` in
+	*Sun\ C*)			# Sun C 5.9
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; $ECHO \"$new_convenience\"` ${wl}--no-whole-archive'
+	  _LT_TAGVAR(compiler_needs_object, $1)=yes
+	  tmp_sharedflag='-G' ;;
+	*Sun\ F*)			# Sun Fortran 8.3
+	  tmp_sharedflag='-G' ;;
+	esac
+	_LT_TAGVAR(archive_cmds, $1)='$CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
 
-# Source file extension for RC test sources.
-ac_ext=rc
+        if test "x$supports_anon_versioning" = xyes; then
+          _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
+	    cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
+	    echo "local: *; };" >> $output_objdir/$libname.ver~
+	    $CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
+        fi
 
-# Object file extension for compiled RC test sources.
-objext=o
-_LT_AC_TAGVAR(objext, $1)=$objext
+	case $cc_basename in
+	xlf*)
+	  # IBM XL Fortran 10.1 on PPC cannot create shared libs itself
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='--whole-archive$convenience --no-whole-archive'
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+	  _LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='-rpath $libdir'
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -shared $libobjs $deplibs $compiler_flags -soname $soname -o $lib'
+	  if test "x$supports_anon_versioning" = xyes; then
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
+	      cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
+	      echo "local: *; };" >> $output_objdir/$libname.ver~
+	      $LD -shared $libobjs $deplibs $compiler_flags -soname $soname -version-script $output_objdir/$libname.ver -o $lib'
+	  fi
+	  ;;
+	esac
+      else
+        _LT_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-# Code to be used in simple compile tests
-lt_simple_compile_test_code='sample MENU { MENUITEM "&Soup", 100, CHECKED }\n'
+    netbsd*)
+      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
+	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
+	wlarc=
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      fi
+      ;;
 
-# Code to be used in simple link tests
-lt_simple_link_test_code="$lt_simple_compile_test_code"
+    solaris*)
+      if $LD -v 2>&1 | $GREP 'BFD 2\.8' > /dev/null; then
+	_LT_TAGVAR(ld_shlibs, $1)=no
+	cat <<_LT_EOF 1>&2
 
-# ltmain only uses $CC for tagged configurations so make sure $CC is set.
-_LT_AC_SYS_COMPILER
+*** Warning: The releases 2.8.* of the GNU linker cannot reliably
+*** create shared libraries on Solaris systems.  Therefore, libtool
+*** is disabling shared libraries support.  We urge you to upgrade GNU
+*** binutils to release 2.9.1 or newer.  Another option is to modify
+*** your PATH or compiler configuration so that the native linker is
+*** used, and then restart.
 
-# Allow CC to be a program name with arguments.
-lt_save_CC="$CC"
-CC=${RC-"windres"}
-compiler=$CC
-_LT_AC_TAGVAR(compiler, $1)=$CC
-_LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
+_LT_EOF
+      elif $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      else
+	_LT_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-AC_LIBTOOL_CONFIG($1)
+    sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX*)
+      case `$LD -v 2>&1` in
+        *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.1[[0-5]].*)
+	_LT_TAGVAR(ld_shlibs, $1)=no
+	cat <<_LT_EOF 1>&2
 
-AC_LANG_RESTORE
-CC="$lt_save_CC"
-])# AC_LIBTOOL_LANG_RC_CONFIG
+*** Warning: Releases of the GNU linker prior to 2.16.91.0.3 can not
+*** reliably create shared libraries on SCO systems.  Therefore, libtool
+*** is disabling shared libraries support.  We urge you to upgrade GNU
+*** binutils to release 2.16.91.0.3 or newer.  Another option is to modify
+*** your PATH or compiler configuration so that the native linker is
+*** used, and then restart.
 
+_LT_EOF
+	;;
+	*)
+	  # For security reasons, it is highly recommended that you always
+	  # use absolute paths for naming shared libraries, and exclude the
+	  # DT_RUNPATH tag from executables and libraries.  But doing so
+	  # requires that you compile everything twice, which is a pain.
+	  if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+	  else
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	  fi
+	;;
+      esac
+      ;;
 
-# AC_LIBTOOL_CONFIG([TAGNAME])
-# ----------------------------
-# If TAGNAME is not passed, then create an initial libtool script
-# with a default configuration from the untagged config vars.  Otherwise
-# add code to config.status for appending the configuration named by
-# TAGNAME from the matching tagged config vars.
-AC_DEFUN([AC_LIBTOOL_CONFIG],
-[# The else clause should only fire when bootstrapping the
-# libtool distribution, otherwise you forgot to ship ltmain.sh
-# with your package, and you will get complaints that there are
-# no rules to generate ltmain.sh.
-if test -f "$ltmain"; then
-  # See if we are running on zsh, and set the options which allow our commands through
-  # without removal of \ escapes.
-  if test -n "${ZSH_VERSION+set}" ; then
-    setopt NO_GLOB_SUBST
-  fi  
-  # Now quote all the things that may contain metacharacters while being
-  # careful not to overquote the AC_SUBSTed values.  We take copies of the
-  # variables and quote the copies for generation of the libtool script.
-  for var in echo old_CC old_CFLAGS AR AR_FLAGS EGREP RANLIB LN_S LTCC NM SED SHELL \
-    libname_spec library_names_spec soname_spec extract_expsyms_cmds \
-    old_striplib striplib file_magic_cmd finish_cmds finish_eval \
-    deplibs_check_method reload_flag reload_cmds need_locks \
-    lt_cv_sys_global_symbol_pipe lt_cv_sys_global_symbol_to_cdecl \
-    lt_cv_sys_global_symbol_to_c_name_address \
-    sys_lib_search_path_spec sys_lib_dlsearch_path_spec \
-    old_postinstall_cmds old_postuninstall_cmds \
-    _LT_AC_TAGVAR(compiler, $1) \
-    _LT_AC_TAGVAR(CC, $1) \
-    _LT_AC_TAGVAR(LD, $1) \
-    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1) \
-    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1) \
-    _LT_AC_TAGVAR(lt_prog_compiler_static, $1) \
-    _LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) \
-    _LT_AC_TAGVAR(export_dynamic_flag_spec, $1) \
-    _LT_AC_TAGVAR(thread_safe_flag_spec, $1) \
-    _LT_AC_TAGVAR(whole_archive_flag_spec, $1) \
-    _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1) \
-    _LT_AC_TAGVAR(old_archive_cmds, $1) \
-    _LT_AC_TAGVAR(old_archive_from_new_cmds, $1) \
-    _LT_AC_TAGVAR(predep_objects, $1) \
-    _LT_AC_TAGVAR(postdep_objects, $1) \
-    _LT_AC_TAGVAR(predeps, $1) \
-    _LT_AC_TAGVAR(postdeps, $1) \
-    _LT_AC_TAGVAR(compiler_lib_search_path, $1) \
-    _LT_AC_TAGVAR(archive_cmds, $1) \
-    _LT_AC_TAGVAR(archive_expsym_cmds, $1) \
-    _LT_AC_TAGVAR(postinstall_cmds, $1) \
-    _LT_AC_TAGVAR(postuninstall_cmds, $1) \
-    _LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1) \
-    _LT_AC_TAGVAR(allow_undefined_flag, $1) \
-    _LT_AC_TAGVAR(no_undefined_flag, $1) \
-    _LT_AC_TAGVAR(export_symbols_cmds, $1) \
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1) \
-    _LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1) \
-    _LT_AC_TAGVAR(hardcode_libdir_separator, $1) \
-    _LT_AC_TAGVAR(hardcode_automatic, $1) \
-    _LT_AC_TAGVAR(module_cmds, $1) \
-    _LT_AC_TAGVAR(module_expsym_cmds, $1) \
-    _LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1) \
-    _LT_AC_TAGVAR(exclude_expsyms, $1) \
-    _LT_AC_TAGVAR(include_expsyms, $1); do
-
-    case $var in
-    _LT_AC_TAGVAR(old_archive_cmds, $1) | \
-    _LT_AC_TAGVAR(old_archive_from_new_cmds, $1) | \
-    _LT_AC_TAGVAR(archive_cmds, $1) | \
-    _LT_AC_TAGVAR(archive_expsym_cmds, $1) | \
-    _LT_AC_TAGVAR(module_cmds, $1) | \
-    _LT_AC_TAGVAR(module_expsym_cmds, $1) | \   
-    _LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1) | \
-    _LT_AC_TAGVAR(export_symbols_cmds, $1) | \
-    extract_expsyms_cmds | reload_cmds | finish_cmds | \
-    postinstall_cmds | postuninstall_cmds | \
-    old_postinstall_cmds | old_postuninstall_cmds | \
-    sys_lib_search_path_spec | sys_lib_dlsearch_path_spec)
-      # Double-quote double-evaled strings.
-      eval "lt_$var=\\\"\`\$echo \"X\$$var\" | \$Xsed -e \"\$double_quote_subst\" -e \"\$sed_quote_subst\" -e \"\$delay_variable_subst\"\`\\\""
+    sunos4*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+      wlarc=
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
+
     *)
-      eval "lt_$var=\\\"\`\$echo \"X\$$var\" | \$Xsed -e \"\$sed_quote_subst\"\`\\\""
+      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      else
+	_LT_TAGVAR(ld_shlibs, $1)=no
+      fi
       ;;
     esac
-  done
-
-  case $lt_echo in
-  *'\[$]0 --fallback-echo"')
-    lt_echo=`$echo "X$lt_echo" | $Xsed -e 's/\\\\\\\[$]0 --fallback-echo"[$]/[$]0 --fallback-echo"/'`
-    ;;
-  esac
-
-ifelse([$1], [],
-  [cfgfile="${ofile}T"
-  trap "$rm \"$cfgfile\"; exit 1" 1 2 15
-  $rm -f "$cfgfile"
-  AC_MSG_NOTICE([creating $ofile])],
-  [cfgfile="$ofile"])
-
-  cat <<__EOF__ >> "$cfgfile"
-ifelse([$1], [],
-[#! $SHELL
 
-# `$echo "$cfgfile" | sed 's%^.*/%%'` - Provide generalized library-building support services.
-# Generated automatically by $PROGRAM (GNU $PACKAGE $VERSION$TIMESTAMP)
-# NOTE: Changes made to this file will be lost: look at ltmain.sh.
-#
-# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001
-# Free Software Foundation, Inc.
-#
-# This file is part of GNU Libtool:
-# Originally by Gordon Matzigkeit <gord@gnu.ai.mit.edu>, 1996
-#
-# This program is free software; you can redistribute it and/or modify
-# it under the terms of the GNU General Public License as published by
-# the Free Software Foundation; either version 2 of the License, or
-# (at your option) any later version.
-#
-# This program is distributed in the hope that it will be useful, but
-# WITHOUT ANY WARRANTY; without even the implied warranty of
-# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-# General Public License for more details.
-#
-# You should have received a copy of the GNU General Public License
-# along with this program; if not, write to the Free Software
-# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-#
-# As a special exception to the GNU General Public License, if you
-# distribute this file as part of a program that contains a
-# configuration script generated by Autoconf, you may include it under
-# the same distribution terms that you use for the rest of that program.
-
-# A sed program that does not truncate output.
-SED=$lt_SED
+    if test "$_LT_TAGVAR(ld_shlibs, $1)" = no; then
+      runpath_var=
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)=
+      _LT_TAGVAR(whole_archive_flag_spec, $1)=
+    fi
+  else
+    # PORTME fill in a description of your system's linker (not GNU ld)
+    case $host_os in
+    aix3*)
+      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_TAGVAR(always_export_symbols, $1)=yes
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$LD -o $output_objdir/$soname $libobjs $deplibs $linker_flags -bE:$export_symbols -T512 -H512 -bM:SRE~$AR $AR_FLAGS $lib $output_objdir/$soname'
+      # Note: this linker hardcodes the directories in LIBPATH if there
+      # are no directories specified by -L.
+      _LT_TAGVAR(hardcode_minus_L, $1)=yes
+      if test "$GCC" = yes && test -z "$lt_prog_compiler_static"; then
+	# Neither direct hardcoding nor static linking is supported with a
+	# broken collect2.
+	_LT_TAGVAR(hardcode_direct, $1)=unsupported
+      fi
+      ;;
 
-# Sed that helps us avoid accidentally triggering echo(1) options like -n.
-Xsed="$SED -e s/^X//"
+    aix[[4-9]]*)
+      if test "$host_cpu" = ia64; then
+	# On IA64, the linker does run time linking by default, so we don't
+	# have to do anything special.
+	aix_use_runtimelinking=no
+	exp_sym_flag='-Bexport'
+	no_entry_flag=""
+      else
+	# If we're using GNU nm, then we don't want the "-C" option.
+	# -C means demangle to AIX nm, but means don't demangle with GNU nm
+	if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
+	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
+	else
+	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
+	fi
+	aix_use_runtimelinking=no
 
-# The HP-UX ksh and POSIX shell print the target directory to stdout
-# if CDPATH is set.
-if test "X\${CDPATH+set}" = Xset; then CDPATH=:; export CDPATH; fi
+	# Test if we are trying to use run time linking or normal
+	# AIX style linking. If -brtl is somewhere in LDFLAGS, we
+	# need to do runtime linking.
+	case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
+	  for ld_flag in $LDFLAGS; do
+	  if (test $ld_flag = "-brtl" || test $ld_flag = "-Wl,-brtl"); then
+	    aix_use_runtimelinking=yes
+	    break
+	  fi
+	  done
+	  ;;
+	esac
 
-# The names of the tagged configurations supported by this script.
-available_tags=
+	exp_sym_flag='-bexport'
+	no_entry_flag='-bnoentry'
+      fi
 
-# ### BEGIN LIBTOOL CONFIG],
-[# ### BEGIN LIBTOOL TAG CONFIG: $tagname])
+      # When large executables or shared objects are built, AIX ld can
+      # have problems creating the table of contents.  If linking a library
+      # or program results in "error TOC overflow" add -mminimal-toc to
+      # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
+      # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.
 
-# Libtool was configured on host `(hostname || uname -n) 2>/dev/null | sed 1q`:
+      _LT_TAGVAR(archive_cmds, $1)=''
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
+      _LT_TAGVAR(link_all_deplibs, $1)=yes
+      _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'
 
-# Shell to use when invoking shell scripts.
-SHELL=$lt_SHELL
+      if test "$GCC" = yes; then
+	case $host_os in aix4.[[012]]|aix4.[[012]].*)
+	# We only want to do this on AIX 4.2 and lower, the check
+	# below for broken collect2 doesn't work under 4.3+
+	  collect2name=`${CC} -print-prog-name=collect2`
+	  if test -f "$collect2name" &&
+	   strings "$collect2name" | $GREP resolve_lib_name >/dev/null
+	  then
+	  # We have reworked collect2
+	  :
+	  else
+	  # We have old collect2
+	  _LT_TAGVAR(hardcode_direct, $1)=unsupported
+	  # It fails to find uninstalled libraries when the uninstalled
+	  # path is not listed in the libpath.  Setting hardcode_minus_L
+	  # to unsupported forces relinking
+	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+	  _LT_TAGVAR(hardcode_libdir_separator, $1)=
+	  fi
+	  ;;
+	esac
+	shared_flag='-shared'
+	if test "$aix_use_runtimelinking" = yes; then
+	  shared_flag="$shared_flag "'${wl}-G'
+	fi
+      else
+	# not using gcc
+	if test "$host_cpu" = ia64; then
+	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
+	# chokes on -Wl,-G. The following line is correct:
+	  shared_flag='-G'
+	else
+	  if test "$aix_use_runtimelinking" = yes; then
+	    shared_flag='${wl}-G'
+	  else
+	    shared_flag='${wl}-bM:SRE'
+	  fi
+	fi
+      fi
 
-# Whether or not to build shared libraries.
-build_libtool_libs=$enable_shared
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
+      # It seems that -bexpall does not export symbols beginning with
+      # underscore (_), so it is better to generate a list of symbols to export.
+      _LT_TAGVAR(always_export_symbols, $1)=yes
+      if test "$aix_use_runtimelinking" = yes; then
+	# Warning - without using the other runtime loading flags (-brtl),
+	# -berok will link without error, but may produce a broken library.
+	_LT_TAGVAR(allow_undefined_flag, $1)='-berok'
+        # Determine the default libpath from the value encoded in an
+        # empty executable.
+        _LT_SYS_MODULE_PATH_AIX
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then $ECHO "X${wl}${allow_undefined_flag}" | $Xsed; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
+      else
+	if test "$host_cpu" = ia64; then
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
+	  _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
+	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
+	else
+	 # Determine the default libpath from the value encoded in an
+	 # empty executable.
+	 _LT_SYS_MODULE_PATH_AIX
+	 _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+	  # Warning - without using the other run time loading flags,
+	  # -berok will link without error, but may produce a broken library.
+	  _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
+	  _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
+	  # Exported symbols can be pulled into shared objects from archives
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
+	  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
+	  # This is similar to how AIX traditionally builds its shared libraries.
+	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
+	fi
+      fi
+      ;;
 
-# Whether or not to build static libraries.
-build_old_libs=$enable_static
+    amigaos*)
+      case $host_cpu in
+      powerpc)
+            # see comment about AmigaOS4 .so support
+            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+            _LT_TAGVAR(archive_expsym_cmds, $1)=''
+        ;;
+      m68k)
+            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
+            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+            _LT_TAGVAR(hardcode_minus_L, $1)=yes
+        ;;
+      esac
+      ;;
 
-# Whether or not to add -lc for building shared libraries.
-build_libtool_need_lc=$_LT_AC_TAGVAR(archive_cmds_need_lc, $1)
+    bsdi[[45]]*)
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)=-rdynamic
+      ;;
 
-# Whether or not to disallow shared libs when runtime libs are static
-allow_libtool_libs_with_static_runtimes=$_LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)
+    cygwin* | mingw* | pw32* | cegcc*)
+      # When not using gcc, we currently assume that we are using
+      # Microsoft Visual C++.
+      # hardcode_libdir_flag_spec is actually meaningless, as there is
+      # no search path for DLLs.
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
+      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+      # Tell ltmain to make .lib files, not .a files.
+      libext=lib
+      # Tell ltmain to make .dll files, not .so files.
+      shrext_cmds=".dll"
+      # FIXME: Setting linknames here is a bad hack.
+      _LT_TAGVAR(archive_cmds, $1)='$CC -o $lib $libobjs $compiler_flags `$ECHO "X$deplibs" | $Xsed -e '\''s/ -lc$//'\''` -link -dll~linknames='
+      # The linker will automatically build a .lib file if we build a DLL.
+      _LT_TAGVAR(old_archive_from_new_cmds, $1)='true'
+      # FIXME: Should let the user specify the lib program.
+      _LT_TAGVAR(old_archive_cmds, $1)='lib -OUT:$oldlib$oldobjs$old_deplibs'
+      _LT_TAGVAR(fix_srcfile_path, $1)='`cygpath -w "$srcfile"`'
+      _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
+      ;;
 
-# Whether or not to optimize for fast installation.
-fast_install=$enable_fast_install
+    darwin* | rhapsody*)
+      _LT_DARWIN_LINKER_FEATURES($1)
+      ;;
 
-# The host system.
-host_alias=$host_alias
-host=$host
+    dgux*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# An echo program that does not interpret backslashes.
-echo=$lt_echo
+    freebsd1*)
+      _LT_TAGVAR(ld_shlibs, $1)=no
+      ;;
 
-# The archiver.
-AR=$lt_AR
-AR_FLAGS=$lt_AR_FLAGS
+    # FreeBSD 2.2.[012] allows us to include c++rt0.o to get C++ constructor
+    # support.  Future versions do this automatically, but an explicit c++rt0.o
+    # does not break anything, and helps significantly (at the cost of a little
+    # extra space).
+    freebsd2.2*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags /usr/lib/c++rt0.o'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# A C compiler.
-LTCC=$lt_LTCC
+    # Unfortunately, older versions of FreeBSD 2 do not have this feature.
+    freebsd2*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# A language-specific compiler.
-CC=$lt_[]_LT_AC_TAGVAR(compiler, $1)
+    # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
+    freebsd* | dragonfly*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Is the compiler the GNU C compiler?
-with_gcc=$_LT_AC_TAGVAR(GCC, $1)
+    hpux9*)
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $libobjs $deplibs $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$LD -b +b $install_libdir -o $output_objdir/$soname $libobjs $deplibs $linker_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+      fi
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_TAGVAR(hardcode_direct, $1)=yes
 
-# An ERE matcher.
-EGREP=$lt_EGREP
+      # hardcode_minus_L: Not really in the search PATH,
+      # but as the default location of the library.
+      _LT_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      ;;
 
-# The linker used to build libraries.
-LD=$lt_[]_LT_AC_TAGVAR(LD, $1)
+    hpux10*)
+      if test "$GCC" = yes -a "$with_gnu_ld" = no; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'
+      fi
+      if test "$with_gnu_ld" = no; then
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+	_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='+b $libdir'
+	_LT_TAGVAR(hardcode_libdir_separator, $1)=:
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	# hardcode_minus_L: Not really in the search PATH,
+	# but as the default location of the library.
+	_LT_TAGVAR(hardcode_minus_L, $1)=yes
+      fi
+      ;;
 
-# Whether we need hard or soft links.
-LN_S=$lt_LN_S
-
-# A BSD-compatible nm program.
-NM=$lt_NM
-
-# A symbol stripping program
-STRIP=$STRIP
-
-# Used to examine libraries when file_magic_cmd begins "file"
-MAGIC_CMD=$MAGIC_CMD
-
-# Used on cygwin: DLL creation program.
-DLLTOOL="$DLLTOOL"
-
-# Used on cygwin: object dumper.
-OBJDUMP="$OBJDUMP"
-
-# Used on cygwin: assembler.
-AS="$AS"
+    hpux11*)
+      if test "$GCC" = yes -a "$with_gnu_ld" = no; then
+	case $host_cpu in
+	hppa*64*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	ia64*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	esac
+      else
+	case $host_cpu in
+	hppa*64*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	ia64*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	esac
+      fi
+      if test "$with_gnu_ld" = no; then
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+	_LT_TAGVAR(hardcode_libdir_separator, $1)=:
 
-# The name of the directory that contains temporary libtool files.
-objdir=$objdir
+	case $host_cpu in
+	hppa*64*|ia64*)
+	  _LT_TAGVAR(hardcode_direct, $1)=no
+	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	  ;;
+	*)
+	  _LT_TAGVAR(hardcode_direct, $1)=yes
+	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
 
-# How to create reloadable object files.
-reload_flag=$lt_reload_flag
-reload_cmds=$lt_reload_cmds
+	  # hardcode_minus_L: Not really in the search PATH,
+	  # but as the default location of the library.
+	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
+	  ;;
+	esac
+      fi
+      ;;
 
-# How to pass a linker flag through the compiler.
-wl=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)
+    irix5* | irix6* | nonstopux*)
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+	# Try to use the -exported_symbol ld option, if it does not
+	# work, assume that -exports_file does not work either and
+	# implicitly export all symbols.
+        save_LDFLAGS="$LDFLAGS"
+        LDFLAGS="$LDFLAGS -shared ${wl}-exported_symbol ${wl}foo ${wl}-update_registry ${wl}/dev/null"
+        AC_LINK_IFELSE(int foo(void) {},
+          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations ${wl}-exports_file ${wl}$export_symbols -o $lib'
+        )
+        LDFLAGS="$save_LDFLAGS"
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -exports_file $export_symbols -o $lib'
+      fi
+      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_TAGVAR(inherit_rpath, $1)=yes
+      _LT_TAGVAR(link_all_deplibs, $1)=yes
+      ;;
 
-# Object file suffix (normally "o").
-objext="$ac_objext"
+    netbsd*)
+      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
+	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
+      fi
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Old archive suffix (normally "a").
-libext="$libext"
+    newsos6)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Shared library suffix (normally ".so").
-shrext='$shrext'
+    *nto* | *qnx*)
+      ;;
 
-# Executable file suffix (normally "").
-exeext="$exeext"
+    openbsd*)
+      if test -f /usr/libexec/ld.so; then
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-retain-symbols-file,$export_symbols'
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	else
+	  case $host_os in
+	   openbsd[[01]].* | openbsd2.[[0-7]] | openbsd2.[[0-7]].*)
+	     _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+	     ;;
+	   *)
+	     _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	     ;;
+	  esac
+	fi
+      else
+	_LT_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-# Additional compiler flags for building library objects.
-pic_flag=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)
-pic_mode=$pic_mode
+    os2*)
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_TAGVAR(archive_cmds, $1)='$ECHO "LIBRARY $libname INITINSTANCE" > $output_objdir/$libname.def~$ECHO "DESCRIPTION \"$libname\"" >> $output_objdir/$libname.def~$ECHO DATA >> $output_objdir/$libname.def~$ECHO " SINGLE NONSHARED" >> $output_objdir/$libname.def~$ECHO EXPORTS >> $output_objdir/$libname.def~emxexp $libobjs >> $output_objdir/$libname.def~$CC -Zdll -Zcrtdll -o $lib $libobjs $deplibs $compiler_flags $output_objdir/$libname.def'
+      _LT_TAGVAR(old_archive_from_new_cmds, $1)='emximp -o $output_objdir/$libname.a $output_objdir/$libname.def'
+      ;;
 
-# What is the maximum length of a command?
-max_cmd_len=$lt_cv_sys_max_cmd_len
+    osf3*)
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+      else
+	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+      fi
+      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+      ;;
 
-# Does compiler simultaneously support -c and -o options?
-compiler_c_o=$lt_[]_LT_AC_TAGVAR(lt_cv_prog_compiler_c_o, $1)
+    osf4* | osf5*)	# as osf3* with the addition of -msym flag
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      else
+	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -msym -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done; printf "%s\\n" "-hidden">> $lib.exp~
+	$CC -shared${allow_undefined_flag} ${wl}-input ${wl}$lib.exp $compiler_flags $libobjs $deplibs -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib~$RM $lib.exp'
 
-# Must we lock files when doing compilation ?
-need_locks=$lt_need_locks
+	# Both c and cxx compiler support -rpath directly
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
+      fi
+      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+      ;;
 
-# Do we need the lib prefix for modules?
-need_lib_prefix=$need_lib_prefix
+    solaris*)
+      _LT_TAGVAR(no_undefined_flag, $1)=' -z defs'
+      if test "$GCC" = yes; then
+	wlarc='${wl}'
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-z ${wl}text ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+	  $CC -shared ${wl}-z ${wl}text ${wl}-M ${wl}$lib.exp ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
+      else
+	case `$CC -V 2>&1` in
+	*"Compilers 5.0"*)
+	  wlarc=''
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+	  $LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$RM $lib.exp'
+	  ;;
+	*)
+	  wlarc='${wl}'
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $compiler_flags'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+	  $CC -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
+	  ;;
+	esac
+      fi
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      case $host_os in
+      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
+      *)
+	# The compiler driver will combine and reorder linker options,
+	# but understands `-z linker_flag'.  GCC discards it without `$wl',
+	# but is careful enough not to reorder.
+	# Supported since Solaris 2.6 (maybe 2.5.1?)
+	if test "$GCC" = yes; then
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
+	else
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
+	fi
+	;;
+      esac
+      _LT_TAGVAR(link_all_deplibs, $1)=yes
+      ;;
 
-# Do we need a version for libraries?
-need_version=$need_version
+    sunos4*)
+      if test "x$host_vendor" = xsequent; then
+	# Use $CC to link under sequent, because it throws in some extra .o
+	# files that make .init and .fini sections work.
+	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h $soname -o $lib $libobjs $deplibs $compiler_flags'
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bstatic -o $lib $libobjs $deplibs $linker_flags'
+      fi
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Whether dlopen is supported.
-dlopen_support=$enable_dlopen
+    sysv4)
+      case $host_vendor in
+	sni)
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_TAGVAR(hardcode_direct, $1)=yes # is this really true???
+	;;
+	siemens)
+	  ## LD is ld it makes a PLAMLIB
+	  ## CC just makes a GrossModule.
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_TAGVAR(reload_cmds, $1)='$CC -r -o $output$reload_objs'
+	  _LT_TAGVAR(hardcode_direct, $1)=no
+        ;;
+	motorola)
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_TAGVAR(hardcode_direct, $1)=no #Motorola manual says yes, but my tests say they lie
+	;;
+      esac
+      runpath_var='LD_RUN_PATH'
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Whether dlopen of programs is supported.
-dlopen_self=$enable_dlopen_self
+    sysv4.3*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)='-Bexport'
+      ;;
 
-# Whether dlopen of statically linked programs is supported.
-dlopen_self_static=$enable_dlopen_self_static
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	runpath_var=LD_RUN_PATH
+	hardcode_runpath_var=yes
+	_LT_TAGVAR(ld_shlibs, $1)=yes
+      fi
+      ;;
 
-# Compiler flag to prevent dynamic linking.
-link_static_flag=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_static, $1)
+    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
+      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
+      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      runpath_var='LD_RUN_PATH'
 
-# Compiler flag to turn off builtin functions.
-no_builtin_flag=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+      fi
+      ;;
 
-# Compiler flag to allow reflexive dlopens.
-export_dynamic_flag_spec=$lt_[]_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)
+    sysv5* | sco3.2v5* | sco5v6*)
+      # Note: We can NOT use -z defs as we might desire, because we do not
+      # link with -lc, and that would cause any symbols used from libc to
+      # always be unresolved, which means just about no library would
+      # ever link correctly.  If we're not using GNU ld we use -z text
+      # though, which does catch some bad symbols but isn't as heavy-handed
+      # as -z defs.
+      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
+      _LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
+      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
+      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
+      _LT_TAGVAR(link_all_deplibs, $1)=yes
+      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
+      runpath_var='LD_RUN_PATH'
 
-# Compiler flag to generate shared objects directly from archives.
-whole_archive_flag_spec=$lt_[]_LT_AC_TAGVAR(whole_archive_flag_spec, $1)
+      if test "$GCC" = yes; then
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+      else
+	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+      fi
+      ;;
 
-# Compiler flag to generate thread-safe objects.
-thread_safe_flag_spec=$lt_[]_LT_AC_TAGVAR(thread_safe_flag_spec, $1)
+    uts4*)
+      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# Library versioning type.
-version_type=$version_type
+    *)
+      _LT_TAGVAR(ld_shlibs, $1)=no
+      ;;
+    esac
 
-# Format of library name prefix.
-libname_spec=$lt_libname_spec
+    if test x$host_vendor = xsni; then
+      case $host in
+      sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Blargedynsym'
+	;;
+      esac
+    fi
+  fi
+])
+AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
+test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
 
-# List of archive names.  First name is the real one, the rest are links.
-# The last name is the one that the linker finds with -lNAME.
-library_names_spec=$lt_library_names_spec
+_LT_TAGVAR(with_gnu_ld, $1)=$with_gnu_ld
 
-# The coded name of the library, if different from the real name.
-soname_spec=$lt_soname_spec
+_LT_DECL([], [libext], [0], [Old archive suffix (normally "a")])dnl
+_LT_DECL([], [shrext_cmds], [1], [Shared library suffix (normally ".so")])dnl
+_LT_DECL([], [extract_expsyms_cmds], [2],
+    [The commands to extract the exported symbol list from a shared archive])
 
-# Commands used to build and install an old-style archive.
-RANLIB=$lt_RANLIB
-old_archive_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_cmds, $1)
-old_postinstall_cmds=$lt_old_postinstall_cmds
-old_postuninstall_cmds=$lt_old_postuninstall_cmds
+#
+# Do we need to explicitly link libc?
+#
+case "x$_LT_TAGVAR(archive_cmds_need_lc, $1)" in
+x|xyes)
+  # Assume -lc should be added
+  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
 
-# Create an old-style archive from a shared archive.
-old_archive_from_new_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_from_new_cmds, $1)
+  if test "$enable_shared" = yes && test "$GCC" = yes; then
+    case $_LT_TAGVAR(archive_cmds, $1) in
+    *'~'*)
+      # FIXME: we may have to deal with multi-command sequences.
+      ;;
+    '$CC '*)
+      # Test whether the compiler implicitly links with -lc since on some
+      # systems, -lgcc has to come before -lc. If gcc already passes -lc
+      # to ld, don't add -lc before -lgcc.
+      AC_MSG_CHECKING([whether -lc should be explicitly linked in])
+      $RM conftest*
+      echo "$lt_simple_compile_test_code" > conftest.$ac_ext
 
-# Create a temporary old-style archive to link instead of a shared archive.
-old_archive_from_expsyms_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1)
+      if AC_TRY_EVAL(ac_compile) 2>conftest.err; then
+        soname=conftest
+        lib=conftest
+        libobjs=conftest.$ac_objext
+        deplibs=
+        wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1)
+	pic_flag=$_LT_TAGVAR(lt_prog_compiler_pic, $1)
+        compiler_flags=-v
+        linker_flags=-v
+        verstring=
+        output_objdir=.
+        libname=conftest
+        lt_save_allow_undefined_flag=$_LT_TAGVAR(allow_undefined_flag, $1)
+        _LT_TAGVAR(allow_undefined_flag, $1)=
+        if AC_TRY_EVAL(_LT_TAGVAR(archive_cmds, $1) 2\>\&1 \| $GREP \" -lc \" \>/dev/null 2\>\&1)
+        then
+	  _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+        else
+	  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
+        fi
+        _LT_TAGVAR(allow_undefined_flag, $1)=$lt_save_allow_undefined_flag
+      else
+        cat conftest.err 1>&5
+      fi
+      $RM conftest*
+      AC_MSG_RESULT([$_LT_TAGVAR(archive_cmds_need_lc, $1)])
+      ;;
+    esac
+  fi
+  ;;
+esac
 
-# Commands used to build and install a shared archive.
-archive_cmds=$lt_[]_LT_AC_TAGVAR(archive_cmds, $1)
-archive_expsym_cmds=$lt_[]_LT_AC_TAGVAR(archive_expsym_cmds, $1)
-postinstall_cmds=$lt_postinstall_cmds
-postuninstall_cmds=$lt_postuninstall_cmds
+_LT_TAGDECL([build_libtool_need_lc], [archive_cmds_need_lc], [0],
+    [Whether or not to add -lc for building shared libraries])
+_LT_TAGDECL([allow_libtool_libs_with_static_runtimes],
+    [enable_shared_with_static_runtimes], [0],
+    [Whether or not to disallow shared libs when runtime libs are static])
+_LT_TAGDECL([], [export_dynamic_flag_spec], [1],
+    [Compiler flag to allow reflexive dlopens])
+_LT_TAGDECL([], [whole_archive_flag_spec], [1],
+    [Compiler flag to generate shared objects directly from archives])
+_LT_TAGDECL([], [compiler_needs_object], [1],
+    [Whether the compiler copes with passing no objects directly])
+_LT_TAGDECL([], [old_archive_from_new_cmds], [2],
+    [Create an old-style archive from a shared archive])
+_LT_TAGDECL([], [old_archive_from_expsyms_cmds], [2],
+    [Create a temporary old-style archive to link instead of a shared archive])
+_LT_TAGDECL([], [archive_cmds], [2], [Commands used to build a shared archive])
+_LT_TAGDECL([], [archive_expsym_cmds], [2])
+_LT_TAGDECL([], [module_cmds], [2],
+    [Commands used to build a loadable module if different from building
+    a shared archive.])
+_LT_TAGDECL([], [module_expsym_cmds], [2])
+_LT_TAGDECL([], [with_gnu_ld], [1],
+    [Whether we are building with GNU ld or not])
+_LT_TAGDECL([], [allow_undefined_flag], [1],
+    [Flag that allows shared libraries with undefined symbols to be built])
+_LT_TAGDECL([], [no_undefined_flag], [1],
+    [Flag that enforces no undefined symbols])
+_LT_TAGDECL([], [hardcode_libdir_flag_spec], [1],
+    [Flag to hardcode $libdir into a binary during linking.
+    This must work even if $libdir does not exist])
+_LT_TAGDECL([], [hardcode_libdir_flag_spec_ld], [1],
+    [[If ld is used when linking, flag to hardcode $libdir into a binary
+    during linking.  This must work even if $libdir does not exist]])
+_LT_TAGDECL([], [hardcode_libdir_separator], [1],
+    [Whether we need a single "-rpath" flag with a separated argument])
+_LT_TAGDECL([], [hardcode_direct], [0],
+    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
+    DIR into the resulting binary])
+_LT_TAGDECL([], [hardcode_direct_absolute], [0],
+    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
+    DIR into the resulting binary and the resulting library dependency is
+    "absolute", i.e impossible to change by setting ${shlibpath_var} if the
+    library is relocated])
+_LT_TAGDECL([], [hardcode_minus_L], [0],
+    [Set to "yes" if using the -LDIR flag during linking hardcodes DIR
+    into the resulting binary])
+_LT_TAGDECL([], [hardcode_shlibpath_var], [0],
+    [Set to "yes" if using SHLIBPATH_VAR=DIR during linking hardcodes DIR
+    into the resulting binary])
+_LT_TAGDECL([], [hardcode_automatic], [0],
+    [Set to "yes" if building a shared library automatically hardcodes DIR
+    into the library and all subsequent libraries and executables linked
+    against it])
+_LT_TAGDECL([], [inherit_rpath], [0],
+    [Set to yes if linker adds runtime paths of dependent libraries
+    to runtime path list])
+_LT_TAGDECL([], [link_all_deplibs], [0],
+    [Whether libtool must link a program against all its dependency libraries])
+_LT_TAGDECL([], [fix_srcfile_path], [1],
+    [Fix the shell variable $srcfile for the compiler])
+_LT_TAGDECL([], [always_export_symbols], [0],
+    [Set to "yes" if exported symbols are required])
+_LT_TAGDECL([], [export_symbols_cmds], [2],
+    [The commands to list exported symbols])
+_LT_TAGDECL([], [exclude_expsyms], [1],
+    [Symbols that should not be listed in the preloaded symbols])
+_LT_TAGDECL([], [include_expsyms], [1],
+    [Symbols that must always be exported])
+_LT_TAGDECL([], [prelink_cmds], [2],
+    [Commands necessary for linking programs (against libraries) with templates])
+_LT_TAGDECL([], [file_list_spec], [1],
+    [Specify filename containing input files])
+dnl FIXME: Not yet implemented
+dnl _LT_TAGDECL([], [thread_safe_flag_spec], [1],
+dnl    [Compiler flag to generate thread safe objects])
+])# _LT_LINKER_SHLIBS
 
-# Commands used to build a loadable module (assumed same as above if empty)
-module_cmds=$lt_[]_LT_AC_TAGVAR(module_cmds, $1)
-module_expsym_cmds=$lt_[]_LT_AC_TAGVAR(module_expsym_cmds, $1)
 
-# Commands to strip libraries.
-old_striplib=$lt_old_striplib
-striplib=$lt_striplib
+# _LT_LANG_C_CONFIG([TAG])
+# ------------------------
+# Ensure that the configuration variables for a C compiler are suitably
+# defined.  These variables are subsequently used by _LT_CONFIG to write
+# the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_C_CONFIG],
+[m4_require([_LT_DECL_EGREP])dnl
+lt_save_CC="$CC"
+AC_LANG_PUSH(C)
 
-# Dependencies to place before the objects being linked to create a
-# shared library.
-predep_objects=$lt_[]_LT_AC_TAGVAR(predep_objects, $1)
+# Source file extension for C test sources.
+ac_ext=c
 
-# Dependencies to place after the objects being linked to create a
-# shared library.
-postdep_objects=$lt_[]_LT_AC_TAGVAR(postdep_objects, $1)
+# Object file extension for compiled C test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
 
-# Dependencies to place before the objects being linked to create a
-# shared library.
-predeps=$lt_[]_LT_AC_TAGVAR(predeps, $1)
+# Code to be used in simple compile tests
+lt_simple_compile_test_code="int some_variable = 0;"
 
-# Dependencies to place after the objects being linked to create a
-# shared library.
-postdeps=$lt_[]_LT_AC_TAGVAR(postdeps, $1)
+# Code to be used in simple link tests
+lt_simple_link_test_code='int main(){return(0);}'
 
-# The library search path used internally by the compiler when linking
-# a shared library.
-compiler_lib_search_path=$lt_[]_LT_AC_TAGVAR(compiler_lib_search_path, $1)
+_LT_TAG_COMPILER
+# Save the default compiler, since it gets overwritten when the other
+# tags are being tested, and _LT_TAGVAR(compiler, []) is a NOP.
+compiler_DEFAULT=$CC
+
+# save warnings/boilerplate of simple test code
+_LT_COMPILER_BOILERPLATE
+_LT_LINKER_BOILERPLATE
+
+if test -n "$compiler"; then
+  _LT_COMPILER_NO_RTTI($1)
+  _LT_COMPILER_PIC($1)
+  _LT_COMPILER_C_O($1)
+  _LT_COMPILER_FILE_LOCKS($1)
+  _LT_LINKER_SHLIBS($1)
+  _LT_SYS_DYNAMIC_LINKER($1)
+  _LT_LINKER_HARDCODE_LIBPATH($1)
+  LT_SYS_DLOPEN_SELF
+  _LT_CMD_STRIPLIB
+
+  # Report which library types will actually be built
+  AC_MSG_CHECKING([if libtool supports shared libraries])
+  AC_MSG_RESULT([$can_build_shared])
 
-# Method to check whether dependent libraries are shared objects.
-deplibs_check_method=$lt_deplibs_check_method
+  AC_MSG_CHECKING([whether to build shared libraries])
+  test "$can_build_shared" = "no" && enable_shared=no
 
-# Command to use when deplibs_check_method == file_magic.
-file_magic_cmd=$lt_file_magic_cmd
+  # On AIX, shared libraries and static libraries use the same namespace, and
+  # are all built from PIC.
+  case $host_os in
+  aix3*)
+    test "$enable_shared" = yes && enable_static=no
+    if test -n "$RANLIB"; then
+      archive_cmds="$archive_cmds~\$RANLIB \$lib"
+      postinstall_cmds='$RANLIB $lib'
+    fi
+    ;;
 
-# Flag that allows shared libraries with undefined symbols to be built.
-allow_undefined_flag=$lt_[]_LT_AC_TAGVAR(allow_undefined_flag, $1)
+  aix[[4-9]]*)
+    if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
+      test "$enable_shared" = yes && enable_static=no
+    fi
+    ;;
+  esac
+  AC_MSG_RESULT([$enable_shared])
 
-# Flag that forces no undefined symbols.
-no_undefined_flag=$lt_[]_LT_AC_TAGVAR(no_undefined_flag, $1)
+  AC_MSG_CHECKING([whether to build static libraries])
+  # Make sure either enable_shared or enable_static is yes.
+  test "$enable_shared" = yes || enable_static=yes
+  AC_MSG_RESULT([$enable_static])
 
-# Commands used to finish a libtool library installation in a directory.
-finish_cmds=$lt_finish_cmds
+  _LT_CONFIG($1)
+fi
+AC_LANG_POP
+CC="$lt_save_CC"
+])# _LT_LANG_C_CONFIG
 
-# Same as above, but a single script fragment to be evaled but not shown.
-finish_eval=$lt_finish_eval
 
-# Take the output of nm and produce a listing of raw symbols and C names.
-global_symbol_pipe=$lt_lt_cv_sys_global_symbol_pipe
+# _LT_PROG_CXX
+# ------------
+# Since AC_PROG_CXX is broken, in that it returns g++ if there is no c++
+# compiler, we have our own version here.
+m4_defun([_LT_PROG_CXX],
+[
+pushdef([AC_MSG_ERROR], [_lt_caught_CXX_error=yes])
+AC_PROG_CXX
+if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
+    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
+    (test "X$CXX" != "Xg++"))) ; then
+  AC_PROG_CXXCPP
+else
+  _lt_caught_CXX_error=yes
+fi
+popdef([AC_MSG_ERROR])
+])# _LT_PROG_CXX
 
-# Transform the output of nm in a proper C declaration
-global_symbol_to_cdecl=$lt_lt_cv_sys_global_symbol_to_cdecl
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([_LT_PROG_CXX], [])
 
-# Transform the output of nm in a C name address pair
-global_symbol_to_c_name_address=$lt_lt_cv_sys_global_symbol_to_c_name_address
 
-# This is the shared library runtime path variable.
-runpath_var=$runpath_var
+# _LT_LANG_CXX_CONFIG([TAG])
+# --------------------------
+# Ensure that the configuration variables for a C++ compiler are suitably
+# defined.  These variables are subsequently used by _LT_CONFIG to write
+# the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_CXX_CONFIG],
+[AC_REQUIRE([_LT_PROG_CXX])dnl
+m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+m4_require([_LT_DECL_EGREP])dnl
+
+AC_LANG_PUSH(C++)
+_LT_TAGVAR(archive_cmds_need_lc, $1)=no
+_LT_TAGVAR(allow_undefined_flag, $1)=
+_LT_TAGVAR(always_export_symbols, $1)=no
+_LT_TAGVAR(archive_expsym_cmds, $1)=
+_LT_TAGVAR(compiler_needs_object, $1)=no
+_LT_TAGVAR(export_dynamic_flag_spec, $1)=
+_LT_TAGVAR(hardcode_direct, $1)=no
+_LT_TAGVAR(hardcode_direct_absolute, $1)=no
+_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
+_LT_TAGVAR(hardcode_libdir_separator, $1)=
+_LT_TAGVAR(hardcode_minus_L, $1)=no
+_LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
+_LT_TAGVAR(hardcode_automatic, $1)=no
+_LT_TAGVAR(inherit_rpath, $1)=no
+_LT_TAGVAR(module_cmds, $1)=
+_LT_TAGVAR(module_expsym_cmds, $1)=
+_LT_TAGVAR(link_all_deplibs, $1)=unknown
+_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
+_LT_TAGVAR(no_undefined_flag, $1)=
+_LT_TAGVAR(whole_archive_flag_spec, $1)=
+_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
 
-# This is the shared library path variable.
-shlibpath_var=$shlibpath_var
+# Source file extension for C++ test sources.
+ac_ext=cpp
 
-# Is shlibpath searched before the hard-coded library search path?
-shlibpath_overrides_runpath=$shlibpath_overrides_runpath
+# Object file extension for compiled C++ test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
 
-# How to hardcode a shared library path into an executable.
-hardcode_action=$_LT_AC_TAGVAR(hardcode_action, $1)
+# No sense in running all these tests if we already determined that
+# the CXX compiler isn't working.  Some variables (like enable_shared)
+# are currently assumed to apply to all compilers on this platform,
+# and will be corrupted by setting them based on a non-working compiler.
+if test "$_lt_caught_CXX_error" != yes; then
+  # Code to be used in simple compile tests
+  lt_simple_compile_test_code="int some_variable = 0;"
+
+  # Code to be used in simple link tests
+  lt_simple_link_test_code='int main(int, char *[[]]) { return(0); }'
+
+  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
+  _LT_TAG_COMPILER
+
+  # save warnings/boilerplate of simple test code
+  _LT_COMPILER_BOILERPLATE
+  _LT_LINKER_BOILERPLATE
+
+  # Allow CC to be a program name with arguments.
+  lt_save_CC=$CC
+  lt_save_LD=$LD
+  lt_save_GCC=$GCC
+  GCC=$GXX
+  lt_save_with_gnu_ld=$with_gnu_ld
+  lt_save_path_LD=$lt_cv_path_LD
+  if test -n "${lt_cv_prog_gnu_ldcxx+set}"; then
+    lt_cv_prog_gnu_ld=$lt_cv_prog_gnu_ldcxx
+  else
+    $as_unset lt_cv_prog_gnu_ld
+  fi
+  if test -n "${lt_cv_path_LDCXX+set}"; then
+    lt_cv_path_LD=$lt_cv_path_LDCXX
+  else
+    $as_unset lt_cv_path_LD
+  fi
+  test -z "${LDCXX+set}" || LD=$LDCXX
+  CC=${CXX-"c++"}
+  compiler=$CC
+  _LT_TAGVAR(compiler, $1)=$CC
+  _LT_CC_BASENAME([$compiler])
+
+  if test -n "$compiler"; then
+    # We don't want -fno-exception when compiling C++ code, so set the
+    # no_builtin_flag separately
+    if test "$GXX" = yes; then
+      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
+    else
+      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
+    fi
 
-# Whether we should hardcode library paths into libraries.
-hardcode_into_libs=$hardcode_into_libs
+    if test "$GXX" = yes; then
+      # Set up default GNU C++ configuration
 
-# Flag to hardcode \$libdir into a binary during linking.
-# This must work even if \$libdir does not exist.
-hardcode_libdir_flag_spec=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)
+      LT_PATH_LD
 
-# If ld is used when linking, flag to hardcode \$libdir into
-# a binary during linking. This must work even if \$libdir does
-# not exist.
-hardcode_libdir_flag_spec_ld=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)
+      # Check if GNU C++ uses GNU ld as the underlying linker, since the
+      # archiving commands below assume that GNU ld is being used.
+      if test "$with_gnu_ld" = yes; then
+        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
+        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+
+        # If archive_cmds runs LD, not CC, wlarc should be empty
+        # XXX I think wlarc can be eliminated in ltcf-cxx, but I need to
+        #     investigate it a little bit more. (MM)
+        wlarc='${wl}'
+
+        # ancient GNU ld didn't support --whole-archive et. al.
+        if eval "`$CC -print-prog-name=ld` --help 2>&1" |
+	  $GREP 'no-whole-archive' > /dev/null; then
+          _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+        else
+          _LT_TAGVAR(whole_archive_flag_spec, $1)=
+        fi
+      else
+        with_gnu_ld=no
+        wlarc=
 
-# Whether we need a single -rpath flag with a separated argument.
-hardcode_libdir_separator=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_separator, $1)
+        # A generic and very simple default shared library creation
+        # command for GNU C++ for the case where it uses the native
+        # linker, instead of GNU ld.  If possible, this setting should
+        # overridden to take advantage of the native linker features on
+        # the platform it is being used on.
+        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
+      fi
 
-# Set to yes if using DIR/libNAME${shared_ext} during linking hardcodes DIR into the
-# resulting binary.
-hardcode_direct=$_LT_AC_TAGVAR(hardcode_direct, $1)
+      # Commands to make compiler produce verbose output that lists
+      # what "hidden" libraries, object files and flags are used when
+      # linking a shared library.
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "\-L"'
 
-# Set to yes if using the -LDIR flag during linking hardcodes DIR into the
-# resulting binary.
-hardcode_minus_L=$_LT_AC_TAGVAR(hardcode_minus_L, $1)
+    else
+      GXX=no
+      with_gnu_ld=no
+      wlarc=
+    fi
 
-# Set to yes if using SHLIBPATH_VAR=DIR during linking hardcodes DIR into
-# the resulting binary.
-hardcode_shlibpath_var=$_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)
+    # PORTME: fill in a description of your system's C++ link characteristics
+    AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
+    _LT_TAGVAR(ld_shlibs, $1)=yes
+    case $host_os in
+      aix3*)
+        # FIXME: insert proper C++ library support
+        _LT_TAGVAR(ld_shlibs, $1)=no
+        ;;
+      aix[[4-9]]*)
+        if test "$host_cpu" = ia64; then
+          # On IA64, the linker does run time linking by default, so we don't
+          # have to do anything special.
+          aix_use_runtimelinking=no
+          exp_sym_flag='-Bexport'
+          no_entry_flag=""
+        else
+          aix_use_runtimelinking=no
 
-# Set to yes if building a shared library automatically hardcodes DIR into the library
-# and all subsequent libraries and executables linked against it.
-hardcode_automatic=$_LT_AC_TAGVAR(hardcode_automatic, $1)
+          # Test if we are trying to use run time linking or normal
+          # AIX style linking. If -brtl is somewhere in LDFLAGS, we
+          # need to do runtime linking.
+          case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
+	    for ld_flag in $LDFLAGS; do
+	      case $ld_flag in
+	      *-brtl*)
+	        aix_use_runtimelinking=yes
+	        break
+	        ;;
+	      esac
+	    done
+	    ;;
+          esac
 
-# Variables whose values should be saved in libtool wrapper scripts and
-# restored at relink time.
-variables_saved_for_relink="$variables_saved_for_relink"
+          exp_sym_flag='-bexport'
+          no_entry_flag='-bnoentry'
+        fi
 
-# Whether libtool must link a program against all its dependency libraries.
-link_all_deplibs=$_LT_AC_TAGVAR(link_all_deplibs, $1)
+        # When large executables or shared objects are built, AIX ld can
+        # have problems creating the table of contents.  If linking a library
+        # or program results in "error TOC overflow" add -mminimal-toc to
+        # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
+        # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.
+
+        _LT_TAGVAR(archive_cmds, $1)=''
+        _LT_TAGVAR(hardcode_direct, $1)=yes
+        _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+        _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
+        _LT_TAGVAR(link_all_deplibs, $1)=yes
+        _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'
+
+        if test "$GXX" = yes; then
+          case $host_os in aix4.[[012]]|aix4.[[012]].*)
+          # We only want to do this on AIX 4.2 and lower, the check
+          # below for broken collect2 doesn't work under 4.3+
+	  collect2name=`${CC} -print-prog-name=collect2`
+	  if test -f "$collect2name" &&
+	     strings "$collect2name" | $GREP resolve_lib_name >/dev/null
+	  then
+	    # We have reworked collect2
+	    :
+	  else
+	    # We have old collect2
+	    _LT_TAGVAR(hardcode_direct, $1)=unsupported
+	    # It fails to find uninstalled libraries when the uninstalled
+	    # path is not listed in the libpath.  Setting hardcode_minus_L
+	    # to unsupported forces relinking
+	    _LT_TAGVAR(hardcode_minus_L, $1)=yes
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+	    _LT_TAGVAR(hardcode_libdir_separator, $1)=
+	  fi
+          esac
+          shared_flag='-shared'
+	  if test "$aix_use_runtimelinking" = yes; then
+	    shared_flag="$shared_flag "'${wl}-G'
+	  fi
+        else
+          # not using gcc
+          if test "$host_cpu" = ia64; then
+	  # VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
+	  # chokes on -Wl,-G. The following line is correct:
+	  shared_flag='-G'
+          else
+	    if test "$aix_use_runtimelinking" = yes; then
+	      shared_flag='${wl}-G'
+	    else
+	      shared_flag='${wl}-bM:SRE'
+	    fi
+          fi
+        fi
 
-# Compile-time system search path for libraries
-sys_lib_search_path_spec=$lt_sys_lib_search_path_spec
+        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
+        # It seems that -bexpall does not export symbols beginning with
+        # underscore (_), so it is better to generate a list of symbols to
+	# export.
+        _LT_TAGVAR(always_export_symbols, $1)=yes
+        if test "$aix_use_runtimelinking" = yes; then
+          # Warning - without using the other runtime loading flags (-brtl),
+          # -berok will link without error, but may produce a broken library.
+          _LT_TAGVAR(allow_undefined_flag, $1)='-berok'
+          # Determine the default libpath from the value encoded in an empty
+          # executable.
+          _LT_SYS_MODULE_PATH_AIX
+          _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
 
-# Run-time system search path for libraries
-sys_lib_dlsearch_path_spec=$lt_sys_lib_dlsearch_path_spec
+          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then $ECHO "X${wl}${allow_undefined_flag}" | $Xsed; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
+        else
+          if test "$host_cpu" = ia64; then
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
+	    _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
+	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
+          else
+	    # Determine the default libpath from the value encoded in an
+	    # empty executable.
+	    _LT_SYS_MODULE_PATH_AIX
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+	    # Warning - without using the other run time loading flags,
+	    # -berok will link without error, but may produce a broken library.
+	    _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
+	    _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
+	    # Exported symbols can be pulled into shared objects from archives
+	    _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
+	    _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
+	    # This is similar to how AIX traditionally builds its shared
+	    # libraries.
+	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
+          fi
+        fi
+        ;;
 
-# Fix the shell variable \$srcfile for the compiler.
-fix_srcfile_path="$_LT_AC_TAGVAR(fix_srcfile_path, $1)"
+      beos*)
+	if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
+	  _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+	  # Joseph Beckenbach <jrb3@best.com> says some releases of gcc
+	  # support --undefined.  This deserves some investigation.  FIXME
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	else
+	  _LT_TAGVAR(ld_shlibs, $1)=no
+	fi
+	;;
 
-# Set to yes if exported symbols are required.
-always_export_symbols=$_LT_AC_TAGVAR(always_export_symbols, $1)
+      chorus*)
+        case $cc_basename in
+          *)
+	  # FIXME: insert proper C++ library support
+	  _LT_TAGVAR(ld_shlibs, $1)=no
+	  ;;
+        esac
+        ;;
 
-# The commands to list exported symbols.
-export_symbols_cmds=$lt_[]_LT_AC_TAGVAR(export_symbols_cmds, $1)
+      cygwin* | mingw* | pw32* | cegcc*)
+        # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
+        # as there is no search path for DLLs.
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+        _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
+        _LT_TAGVAR(always_export_symbols, $1)=no
+        _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
+
+        if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
+          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
+          # If the export-symbols file already is a .def file (1st line
+          # is EXPORTS), use it as is; otherwise, prepend...
+          _LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
+	    cp $export_symbols $output_objdir/$soname.def;
+          else
+	    echo EXPORTS > $output_objdir/$soname.def;
+	    cat $export_symbols >> $output_objdir/$soname.def;
+          fi~
+          $CC -shared -nostdlib $output_objdir/$soname.def $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
+        else
+          _LT_TAGVAR(ld_shlibs, $1)=no
+        fi
+        ;;
+      darwin* | rhapsody*)
+        _LT_DARWIN_LINKER_FEATURES($1)
+	;;
 
-# The commands to extract the exported symbol list from a shared archive.
-extract_expsyms_cmds=$lt_extract_expsyms_cmds
+      dgux*)
+        case $cc_basename in
+          ec++*)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          ghcx*)
+	    # Green Hills C++ Compiler
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          *)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+        esac
+        ;;
 
-# Symbols that should not be listed in the preloaded symbols.
-exclude_expsyms=$lt_[]_LT_AC_TAGVAR(exclude_expsyms, $1)
+      freebsd[[12]]*)
+        # C++ shared libraries reported to be fairly broken before
+	# switch to ELF
+        _LT_TAGVAR(ld_shlibs, $1)=no
+        ;;
 
-# Symbols that must always be exported.
-include_expsyms=$lt_[]_LT_AC_TAGVAR(include_expsyms, $1)
+      freebsd-elf*)
+        _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+        ;;
 
-ifelse([$1],[],
-[# ### END LIBTOOL CONFIG],
-[# ### END LIBTOOL TAG CONFIG: $tagname])
+      freebsd* | dragonfly*)
+        # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
+        # conventions
+        _LT_TAGVAR(ld_shlibs, $1)=yes
+        ;;
 
-__EOF__
+      gnu*)
+        ;;
 
-ifelse([$1],[], [
-  case $host_os in
-  aix3*)
-    cat <<\EOF >> "$cfgfile"
+      hpux9*)
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+        _LT_TAGVAR(hardcode_direct, $1)=yes
+        _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
+				             # but as the default
+				             # location of the library.
+
+        case $cc_basename in
+          CC*)
+            # FIXME: insert proper C++ library support
+            _LT_TAGVAR(ld_shlibs, $1)=no
+            ;;
+          aCC*)
+            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -b ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+            # Commands to make compiler produce verbose output that lists
+            # what "hidden" libraries, object files and flags are used when
+            # linking a shared library.
+            #
+            # There doesn't appear to be a way to prevent this compiler from
+            # explicitly linking system object files so we need to strip them
+            # from the output so that they don't get included in the library
+            # dependencies.
+            output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $EGREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; $ECHO "X$list" | $Xsed'
+            ;;
+          *)
+            if test "$GXX" = yes; then
+              _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared -nostdlib -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+            else
+              # FIXME: insert proper C++ library support
+              _LT_TAGVAR(ld_shlibs, $1)=no
+            fi
+            ;;
+        esac
+        ;;
 
-# AIX sometimes has problems with the GCC collect2 program.  For some
-# reason, if we set the COLLECT_NAMES environment variable, the problems
-# vanish in a puff of smoke.
-if test "X${COLLECT_NAMES+set}" != Xset; then
-  COLLECT_NAMES=
-  export COLLECT_NAMES
-fi
-EOF
-    ;;
-  esac
+      hpux10*|hpux11*)
+        if test $with_gnu_ld = no; then
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+	  _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+
+          case $host_cpu in
+            hppa*64*|ia64*)
+              ;;
+            *)
+	      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+              ;;
+          esac
+        fi
+        case $host_cpu in
+          hppa*64*|ia64*)
+            _LT_TAGVAR(hardcode_direct, $1)=no
+            _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+            ;;
+          *)
+            _LT_TAGVAR(hardcode_direct, $1)=yes
+            _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+            _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
+					         # but as the default
+					         # location of the library.
+            ;;
+        esac
+
+        case $cc_basename in
+          CC*)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          aCC*)
+	    case $host_cpu in
+	      hppa*64*)
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	        ;;
+	      ia64*)
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	        ;;
+	      *)
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	        ;;
+	    esac
+	    # Commands to make compiler produce verbose output that lists
+	    # what "hidden" libraries, object files and flags are used when
+	    # linking a shared library.
+	    #
+	    # There doesn't appear to be a way to prevent this compiler from
+	    # explicitly linking system object files so we need to strip them
+	    # from the output so that they don't get included in the library
+	    # dependencies.
+	    output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $GREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; $ECHO "X$list" | $Xsed'
+	    ;;
+          *)
+	    if test "$GXX" = yes; then
+	      if test $with_gnu_ld = no; then
+	        case $host_cpu in
+	          hppa*64*)
+	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	            ;;
+	          ia64*)
+	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	            ;;
+	          *)
+	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	            ;;
+	        esac
+	      fi
+	    else
+	      # FIXME: insert proper C++ library support
+	      _LT_TAGVAR(ld_shlibs, $1)=no
+	    fi
+	    ;;
+        esac
+        ;;
 
-  # We use sed instead of cat because bash on DJGPP gets confused if
-  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
-  # text mode, it properly converts lines to CR/LF.  This bash problem
-  # is reportedly fixed, but why not run on old versions too?
-  sed '$q' "$ltmain" >> "$cfgfile" || (rm -f "$cfgfile"; exit 1)
+      interix[[3-9]]*)
+	_LT_TAGVAR(hardcode_direct, $1)=no
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	# Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
+	# Instead, shared libraries are loaded at an image base (0x10000000 by
+	# default) and relocated if they conflict, which is a slow very memory
+	# consuming and fragmenting process.  To avoid this, we pick a random,
+	# 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
+	# time.  Moving up from 0x10000000 also allows more sbrk(2) space.
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
+	;;
+      irix5* | irix6*)
+        case $cc_basename in
+          CC*)
+	    # SGI C++
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared -all -multigot $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+
+	    # Archives containing C++ object files must be created using
+	    # "CC -ar", where "CC" is the IRIX C++ compiler.  This is
+	    # necessary to make sure instantiated templates are included
+	    # in the archive.
+	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -ar -WR,-u -o $oldlib $oldobjs'
+	    ;;
+          *)
+	    if test "$GXX" = yes; then
+	      if test "$with_gnu_ld" = no; then
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+	      else
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` -o $lib'
+	      fi
+	    fi
+	    _LT_TAGVAR(link_all_deplibs, $1)=yes
+	    ;;
+        esac
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+        _LT_TAGVAR(inherit_rpath, $1)=yes
+        ;;
 
-  mv -f "$cfgfile" "$ofile" || \
-    (rm -f "$ofile" && cp "$cfgfile" "$ofile" && rm -f "$cfgfile")
-  chmod +x "$ofile"
-])
-else
-  # If there is no Makefile yet, we rely on a make rule to execute
-  # `config.status --recheck' to rerun these tests and create the
-  # libtool script then.
-  test -f Makefile && make "$ltmain"
-fi
-])# AC_LIBTOOL_CONFIG
+      linux* | k*bsd*-gnu)
+        case $cc_basename in
+          KCC*)
+	    # Kuck and Associates, Inc. (KAI) C++ Compiler
+
+	    # KCC will only create a shared library if the output file
+	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
+	    # to its proper name (with version) after linking.
+	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib ${wl}-retain-symbols-file,$export_symbols; mv \$templib $lib'
+	    # Commands to make compiler produce verbose output that lists
+	    # what "hidden" libraries, object files and flags are used when
+	    # linking a shared library.
+	    #
+	    # There doesn't appear to be a way to prevent this compiler from
+	    # explicitly linking system object files so we need to strip them
+	    # from the output so that they don't get included in the library
+	    # dependencies.
+	    output_verbose_link_cmd='templist=`$CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1 | $GREP "ld"`; rm -f libconftest$shared_ext; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; $ECHO "X$list" | $Xsed'
+
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+
+	    # Archives containing C++ object files must be created using
+	    # "CC -Bstatic", where "CC" is the KAI C++ compiler.
+	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs'
+	    ;;
+	  icpc* | ecpc* )
+	    # Intel C++
+	    with_gnu_ld=yes
+	    # version 8.0 and above of icpc choke on multiply defined symbols
+	    # if we add $predep_objects and $postdep_objects, however 7.1 and
+	    # earlier do not add the objects themselves.
+	    case `$CC -V 2>&1` in
+	      *"Version 7."*)
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
+		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+		;;
+	      *)  # Version 8.0 or newer
+	        tmp_idyn=
+	        case $host_cpu in
+		  ia64*) tmp_idyn=' -i_dynamic';;
+		esac
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+		;;
+	    esac
+	    _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
+	    ;;
+          pgCC* | pgcpp*)
+            # Portland Group C++ compiler
+	    case `$CC -V` in
+	    *pgCC\ [[1-5]]* | *pgcpp\ [[1-5]]*)
+	      _LT_TAGVAR(prelink_cmds, $1)='tpldir=Template.dir~
+		rm -rf $tpldir~
+		$CC --prelink_objects --instantiation_dir $tpldir $objs $libobjs $compile_deplibs~
+		compile_command="$compile_command `find $tpldir -name \*.o | $NL2SP`"'
+	      _LT_TAGVAR(old_archive_cmds, $1)='tpldir=Template.dir~
+		rm -rf $tpldir~
+		$CC --prelink_objects --instantiation_dir $tpldir $oldobjs$old_deplibs~
+		$AR $AR_FLAGS $oldlib$oldobjs$old_deplibs `find $tpldir -name \*.o | $NL2SP`~
+		$RANLIB $oldlib'
+	      _LT_TAGVAR(archive_cmds, $1)='tpldir=Template.dir~
+		rm -rf $tpldir~
+		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
+		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
+	      _LT_TAGVAR(archive_expsym_cmds, $1)='tpldir=Template.dir~
+		rm -rf $tpldir~
+		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
+		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
+	      ;;
+	    *) # Version 6 will use weak symbols
+	      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
+	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
+	      ;;
+	    esac
 
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
+	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; $ECHO \"$new_convenience\"` ${wl}--no-whole-archive'
+            ;;
+	  cxx*)
+	    # Compaq C++
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname  -o $lib ${wl}-retain-symbols-file $wl$export_symbols'
 
-# AC_LIBTOOL_PROG_COMPILER_NO_RTTI([TAGNAME])
-# -------------------------------------------
-AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_NO_RTTI],
-[AC_REQUIRE([_LT_AC_SYS_COMPILER])dnl
+	    runpath_var=LD_RUN_PATH
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
+	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:
 
-_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
+	    # Commands to make compiler produce verbose output that lists
+	    # what "hidden" libraries, object files and flags are used when
+	    # linking a shared library.
+	    #
+	    # There doesn't appear to be a way to prevent this compiler from
+	    # explicitly linking system object files so we need to strip them
+	    # from the output so that they don't get included in the library
+	    # dependencies.
+	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld"`; templist=`$ECHO "X$templist" | $Xsed -e "s/\(^.*ld.*\)\( .*ld .*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; $ECHO "X$list" | $Xsed'
+	    ;;
+	  xl*)
+	    # IBM XL 8.0 on PPC, with GNU ld
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	    if test "x$supports_anon_versioning" = xyes; then
+	      _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
+		cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
+		echo "local: *; };" >> $output_objdir/$libname.ver~
+		$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
+	    fi
+	    ;;
+	  *)
+	    case `$CC -V 2>&1 | sed 5q` in
+	    *Sun\ C*)
+	      # Sun C++ 5.9
+	      _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
+	      _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file ${wl}$export_symbols'
+	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+	      _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; $ECHO \"$new_convenience\"` ${wl}--no-whole-archive'
+	      _LT_TAGVAR(compiler_needs_object, $1)=yes
+
+	      # Not sure whether something based on
+	      # $CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1
+	      # would be better.
+	      output_verbose_link_cmd='echo'
+
+	      # Archives containing C++ object files must be created using
+	      # "CC -xar", where "CC" is the Sun C++ compiler.  This is
+	      # necessary to make sure instantiated templates are included
+	      # in the archive.
+	      _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
+	      ;;
+	    esac
+	    ;;
+	esac
+	;;
 
-if test "$GCC" = yes; then
-  _LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
+      lynxos*)
+        # FIXME: insert proper C++ library support
+	_LT_TAGVAR(ld_shlibs, $1)=no
+	;;
 
-  AC_LIBTOOL_COMPILER_OPTION([if $compiler supports -fno-rtti -fno-exceptions],
-    lt_cv_prog_compiler_rtti_exceptions,
-    [-fno-rtti -fno-exceptions], [],
-    [_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)="$_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) -fno-rtti -fno-exceptions"])
-fi
-])# AC_LIBTOOL_PROG_COMPILER_NO_RTTI
+      m88k*)
+        # FIXME: insert proper C++ library support
+        _LT_TAGVAR(ld_shlibs, $1)=no
+	;;
 
+      mvs*)
+        case $cc_basename in
+          cxx*)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+	  *)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+	esac
+	;;
 
-# AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE
-# ---------------------------------
-AC_DEFUN([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE],
-[AC_REQUIRE([AC_CANONICAL_HOST])
-AC_REQUIRE([AC_PROG_NM])
-AC_REQUIRE([AC_OBJEXT])
-# Check for command to grab the raw symbol name followed by C symbol from nm.
-AC_MSG_CHECKING([command to parse $NM output from $compiler object])
-AC_CACHE_VAL([lt_cv_sys_global_symbol_pipe],
-[
-# These are sane defaults that work on at least a few old systems.
-# [They come from Ultrix.  What could be older than Ultrix?!! ;)]
+      netbsd*)
+        if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
+	  _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
+	  wlarc=
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+	  _LT_TAGVAR(hardcode_direct, $1)=yes
+	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	fi
+	# Workaround some broken pre-1.5 toolchains
+	output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+	;;
 
-# Character class describing NM global symbol codes.
-symcode='[[BCDEGRST]]'
+      *nto* | *qnx*)
+        _LT_TAGVAR(ld_shlibs, $1)=yes
+	;;
 
-# Regexp to match symbols that can be accessed directly from C.
-sympat='\([[_A-Za-z]][[_A-Za-z0-9]]*\)'
+      openbsd2*)
+        # C++ shared libraries are fairly broken
+	_LT_TAGVAR(ld_shlibs, $1)=no
+	;;
+
+      openbsd*)
+	if test -f /usr/libexec/ld.so; then
+	  _LT_TAGVAR(hardcode_direct, $1)=yes
+	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file,$export_symbols -o $lib'
+	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	    _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+	  fi
+	  output_verbose_link_cmd=echo
+	else
+	  _LT_TAGVAR(ld_shlibs, $1)=no
+	fi
+	;;
 
-# Transform the above into a raw symbol and a C symbol.
-symxfrm='\1 \2\3 \3'
+      osf3* | osf4* | osf5*)
+        case $cc_basename in
+          KCC*)
+	    # Kuck and Associates, Inc. (KAI) C++ Compiler
+
+	    # KCC will only create a shared library if the output file
+	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
+	    # to its proper name (with version) after linking.
+	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo "$lib" | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
+
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+
+	    # Archives containing C++ object files must be created using
+	    # the KAI C++ compiler.
+	    case $host in
+	      osf3*) _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs' ;;
+	      *) _LT_TAGVAR(old_archive_cmds, $1)='$CC -o $oldlib $oldobjs' ;;
+	    esac
+	    ;;
+          RCC*)
+	    # Rational C++ 2.4.1
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          cxx*)
+	    case $host in
+	      osf3*)
+	        _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $soname `test -n "$verstring" && $ECHO "X${wl}-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+		;;
+	      *)
+	        _LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib'
+	        _LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done~
+	          echo "-hidden">> $lib.exp~
+	          $CC -shared$allow_undefined_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname ${wl}-input ${wl}$lib.exp  `test -n "$verstring" && $ECHO "X-set_version $verstring" | $Xsed` -update_registry ${output_objdir}/so_locations -o $lib~
+	          $RM $lib.exp'
+	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
+		;;
+	    esac
 
-# Transform an extracted symbol line into a proper C declaration
-lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^. .* \(.*\)$/extern int \1;/p'"
+	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:
 
-# Transform an extracted symbol line into symbol name and symbol address
-lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (lt_ptr) 0},/p' -e 's/^$symcode \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (lt_ptr) \&\2},/p'"
+	    # Commands to make compiler produce verbose output that lists
+	    # what "hidden" libraries, object files and flags are used when
+	    # linking a shared library.
+	    #
+	    # There doesn't appear to be a way to prevent this compiler from
+	    # explicitly linking system object files so we need to strip them
+	    # from the output so that they don't get included in the library
+	    # dependencies.
+	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld" | $GREP -v "ld:"`; templist=`$ECHO "X$templist" | $Xsed -e "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; $ECHO "X$list" | $Xsed'
+	    ;;
+	  *)
+	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
+	      _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	      case $host in
+	        osf3*)
+	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "X${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+		  ;;
+	        *)
+	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && $ECHO "${wl}-set_version ${wl}$verstring" | $Xsed` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+		  ;;
+	      esac
+
+	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+	      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
+
+	      # Commands to make compiler produce verbose output that lists
+	      # what "hidden" libraries, object files and flags are used when
+	      # linking a shared library.
+	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "\-L"'
+
+	    else
+	      # FIXME: insert proper C++ library support
+	      _LT_TAGVAR(ld_shlibs, $1)=no
+	    fi
+	    ;;
+        esac
+        ;;
 
-# Define system-specific variables.
-case $host_os in
-aix*)
-  symcode='[[BCDT]]'
-  ;;
-cygwin* | mingw* | pw32*)
-  symcode='[[ABCDGISTW]]'
-  ;;
-hpux*) # Its linker distinguishes data from code symbols
-  if test "$host_cpu" = ia64; then
-    symcode='[[ABCDEGRST]]'
-  fi
-  lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^T .* \(.*\)$/extern int \1();/p' -e 's/^$symcode* .* \(.*\)$/extern char \1;/p'"
-  lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (lt_ptr) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (lt_ptr) \&\2},/p'"
-  ;;
-irix* | nonstopux*)
-  symcode='[[BCDEGRST]]'
-  ;;
-osf*)
-  symcode='[[BCDEGQRST]]'
-  ;;
-solaris* | sysv5*)
-  symcode='[[BDT]]'
-  ;;
-sysv4)
-  symcode='[[DFNSTU]]'
-  ;;
-esac
+      psos*)
+        # FIXME: insert proper C++ library support
+        _LT_TAGVAR(ld_shlibs, $1)=no
+        ;;
 
-# Handle CRLF in mingw tool chain
-opt_cr=
-case $build_os in
-mingw*)
-  opt_cr=`echo 'x\{0,1\}' | tr x '\015'` # option cr in regexp
-  ;;
-esac
+      sunos4*)
+        case $cc_basename in
+          CC*)
+	    # Sun C++ 4.x
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          lcc*)
+	    # Lucid
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          *)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+        esac
+        ;;
 
-# If we're using GNU nm, then use its standard symbol codes.
-case `$NM -V 2>&1` in
-*GNU* | *'with BFD'*)
-  symcode='[[ABCDGISTW]]' ;;
-esac
+      solaris*)
+        case $cc_basename in
+          CC*)
+	    # Sun C++ 4.2, 5.x and Centerline C++
+            _LT_TAGVAR(archive_cmds_need_lc,$1)=yes
+	    _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag}  -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+	      $CC -G${allow_undefined_flag} ${wl}-M ${wl}$lib.exp -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
+
+	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+	    _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	    case $host_os in
+	      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
+	      *)
+		# The compiler driver will combine and reorder linker options,
+		# but understands `-z linker_flag'.
+	        # Supported since Solaris 2.6 (maybe 2.5.1?)
+		_LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
+	        ;;
+	    esac
+	    _LT_TAGVAR(link_all_deplibs, $1)=yes
 
-# Try without a prefix undercore, then with it.
-for ac_symprfx in "" "_"; do
+	    output_verbose_link_cmd='echo'
 
-  # Write the raw and C identifiers.
-  lt_cv_sys_global_symbol_pipe="sed -n -e 's/^.*[[ 	]]\($symcode$symcode*\)[[ 	]][[ 	]]*\($ac_symprfx\)$sympat$opt_cr$/$symxfrm/p'"
+	    # Archives containing C++ object files must be created using
+	    # "CC -xar", where "CC" is the Sun C++ compiler.  This is
+	    # necessary to make sure instantiated templates are included
+	    # in the archive.
+	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
+	    ;;
+          gcx*)
+	    # Green Hills C++ Compiler
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
 
-  # Check to see that the pipe works correctly.
-  pipe_works=no
+	    # The C++ compiler must be used to create the archive.
+	    _LT_TAGVAR(old_archive_cmds, $1)='$CC $LDFLAGS -archive -o $oldlib $oldobjs'
+	    ;;
+          *)
+	    # GNU C++ compiler with Solaris linker
+	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
+	      _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-z ${wl}defs'
+	      if $CC --version | $GREP -v '^2\.7' > /dev/null; then
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
+	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+		  $CC -shared -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
+
+	        # Commands to make compiler produce verbose output that lists
+	        # what "hidden" libraries, object files and flags are used when
+	        # linking a shared library.
+	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "\-L"'
+	      else
+	        # g++ 2.7 appears to require `-G' NOT `-shared' on this
+	        # platform.
+	        _LT_TAGVAR(archive_cmds, $1)='$CC -G -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
+	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+		  $CC -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
+
+	        # Commands to make compiler produce verbose output that lists
+	        # what "hidden" libraries, object files and flags are used when
+	        # linking a shared library.
+	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP "\-L"'
+	      fi
+
+	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $wl$libdir'
+	      case $host_os in
+		solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
+		*)
+		  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
+		  ;;
+	      esac
+	    fi
+	    ;;
+        esac
+        ;;
 
-  rm -f conftest*
-  cat > conftest.$ac_ext <<EOF
-#ifdef __cplusplus
-extern "C" {
-#endif
-char nm_test_var;
-void nm_test_func(){}
-#ifdef __cplusplus
-}
-#endif
-int main(){nm_test_var='a';nm_test_func();return(0);}
-EOF
+    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
+      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
+      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      runpath_var='LD_RUN_PATH'
 
-  if AC_TRY_EVAL(ac_compile); then
-    # Now try to grab the symbols.
-    nlist=conftest.nm
-    if AC_TRY_EVAL(NM conftest.$ac_objext \| $lt_cv_sys_global_symbol_pipe \> $nlist) && test -s "$nlist"; then
-      # Try sorting and uniquifying the output.
-      if sort "$nlist" | uniq > "$nlist"T; then
-	mv -f "$nlist"T "$nlist"
-      else
-	rm -f "$nlist"T
-      fi
+      case $cc_basename in
+        CC*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	*)
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+      esac
+      ;;
 
-      # Make sure that we snagged all the symbols we need.
-      if grep ' nm_test_var$' "$nlist" >/dev/null; then
-	if grep ' nm_test_func$' "$nlist" >/dev/null; then
-	  cat <<EOF > conftest.$ac_ext
-#ifdef __cplusplus
-extern "C" {
-#endif
+      sysv5* | sco3.2v5* | sco5v6*)
+	# Note: We can NOT use -z defs as we might desire, because we do not
+	# link with -lc, and that would cause any symbols used from libc to
+	# always be unresolved, which means just about no library would
+	# ever link correctly.  If we're not using GNU ld we use -z text
+	# though, which does catch some bad symbols but isn't as heavy-handed
+	# as -z defs.
+	_LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
+	_LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
+	_LT_TAGVAR(archive_cmds_need_lc, $1)=no
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
+	_LT_TAGVAR(hardcode_libdir_separator, $1)=':'
+	_LT_TAGVAR(link_all_deplibs, $1)=yes
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
+	runpath_var='LD_RUN_PATH'
 
-EOF
-	  # Now generate the symbol file.
-	  eval "$lt_cv_sys_global_symbol_to_cdecl"' < "$nlist" | grep -v main >> conftest.$ac_ext'
+	case $cc_basename in
+          CC*)
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	    ;;
+	  *)
+	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
+	    ;;
+	esac
+      ;;
 
-	  cat <<EOF >> conftest.$ac_ext
-#if defined (__STDC__) && __STDC__
-# define lt_ptr_t void *
-#else
-# define lt_ptr_t char *
-# define const
-#endif
+      tandem*)
+        case $cc_basename in
+          NCC*)
+	    # NonStop-UX NCC 3.20
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+          *)
+	    # FIXME: insert proper C++ library support
+	    _LT_TAGVAR(ld_shlibs, $1)=no
+	    ;;
+        esac
+        ;;
 
-/* The mapping between symbol names and symbols. */
-const struct {
-  const char *name;
-  lt_ptr_t address;
-}
-lt_preloaded_symbols[[]] =
-{
-EOF
-	  $SED "s/^$symcode$symcode* \(.*\) \(.*\)$/  {\"\2\", (lt_ptr_t) \&\2},/" < "$nlist" | grep -v main >> conftest.$ac_ext
-	  cat <<\EOF >> conftest.$ac_ext
-  {0, (lt_ptr_t) 0}
-};
+      vxworks*)
+        # FIXME: insert proper C++ library support
+        _LT_TAGVAR(ld_shlibs, $1)=no
+        ;;
 
-#ifdef __cplusplus
-}
-#endif
-EOF
-	  # Now try linking the two files.
-	  mv conftest.$ac_objext conftstm.$ac_objext
-	  lt_save_LIBS="$LIBS"
-	  lt_save_CFLAGS="$CFLAGS"
-	  LIBS="conftstm.$ac_objext"
-	  CFLAGS="$CFLAGS$_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)"
-	  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext}; then
-	    pipe_works=yes
-	  fi
-	  LIBS="$lt_save_LIBS"
-	  CFLAGS="$lt_save_CFLAGS"
-	else
-	  echo "cannot find nm_test_func in $nlist" >&AS_MESSAGE_LOG_FD
-	fi
-      else
-	echo "cannot find nm_test_var in $nlist" >&AS_MESSAGE_LOG_FD
-      fi
-    else
-      echo "cannot run $lt_cv_sys_global_symbol_pipe" >&AS_MESSAGE_LOG_FD
-    fi
-  else
-    echo "$progname: failed program was:" >&AS_MESSAGE_LOG_FD
-    cat conftest.$ac_ext >&5
-  fi
-  rm -f conftest* conftst*
+      *)
+        # FIXME: insert proper C++ library support
+        _LT_TAGVAR(ld_shlibs, $1)=no
+        ;;
+    esac
 
-  # Do not use the global_symbol_pipe unless it works.
-  if test "$pipe_works" = yes; then
-    break
-  else
-    lt_cv_sys_global_symbol_pipe=
-  fi
-done
-])
-if test -z "$lt_cv_sys_global_symbol_pipe"; then
-  lt_cv_sys_global_symbol_to_cdecl=
-fi
-if test -z "$lt_cv_sys_global_symbol_pipe$lt_cv_sys_global_symbol_to_cdecl"; then
-  AC_MSG_RESULT(failed)
-else
-  AC_MSG_RESULT(ok)
-fi
-]) # AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE
+    AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
+    test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
 
+    _LT_TAGVAR(GCC, $1)="$GXX"
+    _LT_TAGVAR(LD, $1)="$LD"
 
-# AC_LIBTOOL_PROG_COMPILER_PIC([TAGNAME])
-# ---------------------------------------
-AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_PIC],
-[_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)=
-_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-_LT_AC_TAGVAR(lt_prog_compiler_static, $1)=
+    ## CAVEAT EMPTOR:
+    ## There is no encapsulation within the following macros, do not change
+    ## the running order or otherwise move them around unless you know exactly
+    ## what you are doing...
+    _LT_SYS_HIDDEN_LIBDEPS($1)
+    _LT_COMPILER_PIC($1)
+    _LT_COMPILER_C_O($1)
+    _LT_COMPILER_FILE_LOCKS($1)
+    _LT_LINKER_SHLIBS($1)
+    _LT_SYS_DYNAMIC_LINKER($1)
+    _LT_LINKER_HARDCODE_LIBPATH($1)
+
+    _LT_CONFIG($1)
+  fi # test -n "$compiler"
+
+  CC=$lt_save_CC
+  LDCXX=$LD
+  LD=$lt_save_LD
+  GCC=$lt_save_GCC
+  with_gnu_ld=$lt_save_with_gnu_ld
+  lt_cv_path_LDCXX=$lt_cv_path_LD
+  lt_cv_path_LD=$lt_save_path_LD
+  lt_cv_prog_gnu_ldcxx=$lt_cv_prog_gnu_ld
+  lt_cv_prog_gnu_ld=$lt_save_with_gnu_ld
+fi # test "$_lt_caught_CXX_error" != yes
 
-AC_MSG_CHECKING([for $compiler option to produce PIC])
- ifelse([$1],[CXX],[
-  # C++ specific cases for pic, static, wl, etc.
-  if test "$GXX" = yes; then
-    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
+AC_LANG_POP
+])# _LT_LANG_CXX_CONFIG
 
-    case $host_os in
-    aix*)
-      # All AIX code is PIC.
-      if test "$host_cpu" = ia64; then
-	# AIX 5 now supports IA64 processor
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      fi
-      ;;
-    amigaos*)
-      # FIXME: we need at least 68020 code to build shared libraries, but
-      # adding the `-m68020' flag to GCC prevents building anything better,
-      # like `-m68040'.
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
-      ;;
-    beos* | cygwin* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
-      # PIC is the default for these OSes.
-      ;;
-    mingw* | os2* | pw32*)
-      # This hack is so that the source file can tell whether it is being
-      # built for inclusion in a dll (and should export symbols for example).
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
-      ;;
-    darwin* | rhapsody*)
-      # PIC is the default on this platform
-      # Common symbols not allowed in MH_DYLIB files
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
-      ;;
-    *djgpp*)
-      # DJGPP does not support shared libraries at all
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-      ;;
-    sysv4*MP*)
-      if test -d /usr/nec; then
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
-      fi
-      ;;
-    hpux*)
-      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
-      # not for PA HP-UX.
-      case "$host_cpu" in
-      hppa*64*|ia64*)
-	;;
-      *)
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
-	;;
-      esac
+
+# _LT_SYS_HIDDEN_LIBDEPS([TAGNAME])
+# ---------------------------------
+# Figure out "hidden" library dependencies from verbose
+# compiler output when linking a shared library.
+# Parse the compiler output and extract the necessary
+# objects, libraries and library flags.
+m4_defun([_LT_SYS_HIDDEN_LIBDEPS],
+[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
+# Dependencies to place before and after the object being linked:
+_LT_TAGVAR(predep_objects, $1)=
+_LT_TAGVAR(postdep_objects, $1)=
+_LT_TAGVAR(predeps, $1)=
+_LT_TAGVAR(postdeps, $1)=
+_LT_TAGVAR(compiler_lib_search_path, $1)=
+
+dnl we can't use the lt_simple_compile_test_code here,
+dnl because it contains code intended for an executable,
+dnl not a library.  It's possible we should let each
+dnl tag define a new lt_????_link_test_code variable,
+dnl but it's only used here...
+m4_if([$1], [], [cat > conftest.$ac_ext <<_LT_EOF
+int a;
+void foo (void) { a = 0; }
+_LT_EOF
+], [$1], [CXX], [cat > conftest.$ac_ext <<_LT_EOF
+class Foo
+{
+public:
+  Foo (void) { a = 0; }
+private:
+  int a;
+};
+_LT_EOF
+], [$1], [F77], [cat > conftest.$ac_ext <<_LT_EOF
+      subroutine foo
+      implicit none
+      integer*4 a
+      a=0
+      return
+      end
+_LT_EOF
+], [$1], [FC], [cat > conftest.$ac_ext <<_LT_EOF
+      subroutine foo
+      implicit none
+      integer a
+      a=0
+      return
+      end
+_LT_EOF
+], [$1], [GCJ], [cat > conftest.$ac_ext <<_LT_EOF
+public class foo {
+  private int a;
+  public void bar (void) {
+    a = 0;
+  }
+};
+_LT_EOF
+])
+dnl Parse the compiler output and extract the necessary
+dnl objects, libraries and library flags.
+if AC_TRY_EVAL(ac_compile); then
+  # Parse the compiler output and extract the necessary
+  # objects, libraries and library flags.
+
+  # Sentinel used to keep track of whether or not we are before
+  # the conftest object file.
+  pre_test_object_deps_done=no
+
+  for p in `eval "$output_verbose_link_cmd"`; do
+    case $p in
+
+    -L* | -R* | -l*)
+       # Some compilers place space between "-{L,R}" and the path.
+       # Remove the space.
+       if test $p = "-L" ||
+          test $p = "-R"; then
+	 prev=$p
+	 continue
+       else
+	 prev=
+       fi
+
+       if test "$pre_test_object_deps_done" = no; then
+	 case $p in
+	 -L* | -R*)
+	   # Internal compiler library paths should come after those
+	   # provided the user.  The postdeps already come after the
+	   # user supplied libs so there is no need to process them.
+	   if test -z "$_LT_TAGVAR(compiler_lib_search_path, $1)"; then
+	     _LT_TAGVAR(compiler_lib_search_path, $1)="${prev}${p}"
+	   else
+	     _LT_TAGVAR(compiler_lib_search_path, $1)="${_LT_TAGVAR(compiler_lib_search_path, $1)} ${prev}${p}"
+	   fi
+	   ;;
+	 # The "-l" case would never come before the object being
+	 # linked, so don't bother handling this case.
+	 esac
+       else
+	 if test -z "$_LT_TAGVAR(postdeps, $1)"; then
+	   _LT_TAGVAR(postdeps, $1)="${prev}${p}"
+	 else
+	   _LT_TAGVAR(postdeps, $1)="${_LT_TAGVAR(postdeps, $1)} ${prev}${p}"
+	 fi
+       fi
+       ;;
+
+    *.$objext)
+       # This assumes that the test object file only shows up
+       # once in the compiler output.
+       if test "$p" = "conftest.$objext"; then
+	 pre_test_object_deps_done=yes
+	 continue
+       fi
+
+       if test "$pre_test_object_deps_done" = no; then
+	 if test -z "$_LT_TAGVAR(predep_objects, $1)"; then
+	   _LT_TAGVAR(predep_objects, $1)="$p"
+	 else
+	   _LT_TAGVAR(predep_objects, $1)="$_LT_TAGVAR(predep_objects, $1) $p"
+	 fi
+       else
+	 if test -z "$_LT_TAGVAR(postdep_objects, $1)"; then
+	   _LT_TAGVAR(postdep_objects, $1)="$p"
+	 else
+	   _LT_TAGVAR(postdep_objects, $1)="$_LT_TAGVAR(postdep_objects, $1) $p"
+	 fi
+       fi
+       ;;
+
+    *) ;; # Ignore the rest.
+
+    esac
+  done
+
+  # Clean up.
+  rm -f a.out a.exe
+else
+  echo "libtool.m4: error: problem compiling $1 test program"
+fi
+
+$RM -f confest.$objext
+
+# PORTME: override above test on systems where it is broken
+m4_if([$1], [CXX],
+[case $host_os in
+interix[[3-9]]*)
+  # Interix 3.5 installs completely hosed .la files for C++, so rather than
+  # hack all around it, let's just trust "g++" to DTRT.
+  _LT_TAGVAR(predep_objects,$1)=
+  _LT_TAGVAR(postdep_objects,$1)=
+  _LT_TAGVAR(postdeps,$1)=
+  ;;
+
+linux*)
+  case `$CC -V 2>&1 | sed 5q` in
+  *Sun\ C*)
+    # Sun C++ 5.9
+
+    # The more standards-conforming stlport4 library is
+    # incompatible with the Cstd library. Avoid specifying
+    # it if it's in CXXFLAGS. Ignore libCrun as
+    # -library=stlport4 depends on it.
+    case " $CXX $CXXFLAGS " in
+    *" -library=stlport4 "*)
+      solaris_use_stlport4=yes
       ;;
-    *)
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+    esac
+
+    if test "$solaris_use_stlport4" != yes; then
+      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
+    fi
+    ;;
+  esac
+  ;;
+
+solaris*)
+  case $cc_basename in
+  CC*)
+    # The more standards-conforming stlport4 library is
+    # incompatible with the Cstd library. Avoid specifying
+    # it if it's in CXXFLAGS. Ignore libCrun as
+    # -library=stlport4 depends on it.
+    case " $CXX $CXXFLAGS " in
+    *" -library=stlport4 "*)
+      solaris_use_stlport4=yes
       ;;
     esac
-  else
+
+    # Adding this requires a known-good setup of shared libraries for
+    # Sun compiler versions before 5.6, else PIC objects from an old
+    # archive will be linked into the output, leading to subtle bugs.
+    if test "$solaris_use_stlport4" != yes; then
+      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
+    fi
+    ;;
+  esac
+  ;;
+esac
+])
+
+case " $_LT_TAGVAR(postdeps, $1) " in
+*" -lc "*) _LT_TAGVAR(archive_cmds_need_lc, $1)=no ;;
+esac
+ _LT_TAGVAR(compiler_lib_search_dirs, $1)=
+if test -n "${_LT_TAGVAR(compiler_lib_search_path, $1)}"; then
+ _LT_TAGVAR(compiler_lib_search_dirs, $1)=`echo " ${_LT_TAGVAR(compiler_lib_search_path, $1)}" | ${SED} -e 's! -L! !g' -e 's!^ !!'`
+fi
+_LT_TAGDECL([], [compiler_lib_search_dirs], [1],
+    [The directories searched by this compiler when creating a shared library])
+_LT_TAGDECL([], [predep_objects], [1],
+    [Dependencies to place before and after the objects being linked to
+    create a shared library])
+_LT_TAGDECL([], [postdep_objects], [1])
+_LT_TAGDECL([], [predeps], [1])
+_LT_TAGDECL([], [postdeps], [1])
+_LT_TAGDECL([], [compiler_lib_search_path], [1],
+    [The library search path used internally by the compiler when linking
+    a shared library])
+])# _LT_SYS_HIDDEN_LIBDEPS
+
+
+# _LT_PROG_F77
+# ------------
+# Since AC_PROG_F77 is broken, in that it returns the empty string
+# if there is no fortran compiler, we have our own version here.
+m4_defun([_LT_PROG_F77],
+[
+pushdef([AC_MSG_ERROR], [_lt_disable_F77=yes])
+AC_PROG_F77
+if test -z "$F77" || test "X$F77" = "Xno"; then
+  _lt_disable_F77=yes
+fi
+popdef([AC_MSG_ERROR])
+])# _LT_PROG_F77
+
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([_LT_PROG_F77], [])
+
+
+# _LT_LANG_F77_CONFIG([TAG])
+# --------------------------
+# Ensure that the configuration variables for a Fortran 77 compiler are
+# suitably defined.  These variables are subsequently used by _LT_CONFIG
+# to write the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_F77_CONFIG],
+[AC_REQUIRE([_LT_PROG_F77])dnl
+AC_LANG_PUSH(Fortran 77)
+
+_LT_TAGVAR(archive_cmds_need_lc, $1)=no
+_LT_TAGVAR(allow_undefined_flag, $1)=
+_LT_TAGVAR(always_export_symbols, $1)=no
+_LT_TAGVAR(archive_expsym_cmds, $1)=
+_LT_TAGVAR(export_dynamic_flag_spec, $1)=
+_LT_TAGVAR(hardcode_direct, $1)=no
+_LT_TAGVAR(hardcode_direct_absolute, $1)=no
+_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
+_LT_TAGVAR(hardcode_libdir_separator, $1)=
+_LT_TAGVAR(hardcode_minus_L, $1)=no
+_LT_TAGVAR(hardcode_automatic, $1)=no
+_LT_TAGVAR(inherit_rpath, $1)=no
+_LT_TAGVAR(module_cmds, $1)=
+_LT_TAGVAR(module_expsym_cmds, $1)=
+_LT_TAGVAR(link_all_deplibs, $1)=unknown
+_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
+_LT_TAGVAR(no_undefined_flag, $1)=
+_LT_TAGVAR(whole_archive_flag_spec, $1)=
+_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+
+# Source file extension for f77 test sources.
+ac_ext=f
+
+# Object file extension for compiled f77 test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
+
+# No sense in running all these tests if we already determined that
+# the F77 compiler isn't working.  Some variables (like enable_shared)
+# are currently assumed to apply to all compilers on this platform,
+# and will be corrupted by setting them based on a non-working compiler.
+if test "$_lt_disable_F77" != yes; then
+  # Code to be used in simple compile tests
+  lt_simple_compile_test_code="\
+      subroutine t
+      return
+      end
+"
+
+  # Code to be used in simple link tests
+  lt_simple_link_test_code="\
+      program t
+      end
+"
+
+  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
+  _LT_TAG_COMPILER
+
+  # save warnings/boilerplate of simple test code
+  _LT_COMPILER_BOILERPLATE
+  _LT_LINKER_BOILERPLATE
+
+  # Allow CC to be a program name with arguments.
+  lt_save_CC="$CC"
+  lt_save_GCC=$GCC
+  CC=${F77-"f77"}
+  compiler=$CC
+  _LT_TAGVAR(compiler, $1)=$CC
+  _LT_CC_BASENAME([$compiler])
+  GCC=$G77
+  if test -n "$compiler"; then
+    AC_MSG_CHECKING([if libtool supports shared libraries])
+    AC_MSG_RESULT([$can_build_shared])
+
+    AC_MSG_CHECKING([whether to build shared libraries])
+    test "$can_build_shared" = "no" && enable_shared=no
+
+    # On AIX, shared libraries and static libraries use the same namespace, and
+    # are all built from PIC.
     case $host_os in
-      aix4* | aix5*)
-	# All AIX code is PIC.
-	if test "$host_cpu" = ia64; then
-	  # AIX 5 now supports IA64 processor
-	  _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-	else
-	  _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
+      aix3*)
+        test "$enable_shared" = yes && enable_static=no
+        if test -n "$RANLIB"; then
+          archive_cmds="$archive_cmds~\$RANLIB \$lib"
+          postinstall_cmds='$RANLIB $lib'
+        fi
+        ;;
+      aix[[4-9]]*)
+	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
+	  test "$enable_shared" = yes && enable_static=no
 	fi
-	;;
-      chorus*)
-	case $cc_basename in
-	cxch68)
-	  # Green Hills C++ Compiler
-	  # _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
-	  ;;
-	esac
-	;;
-      dgux*)
-	case $cc_basename in
-	  ec++)
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-	    ;;
-	  ghcx)
-	    # Green Hills C++ Compiler
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      freebsd*)
-	# FreeBSD uses GNU C++
-	;;
-      hpux9* | hpux10* | hpux11*)
-	case $cc_basename in
-	  CC)
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
-	    if test "$host_cpu" != ia64; then
-	      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
-	    fi
-	    ;;
-	  aCC)
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
-	    case "$host_cpu" in
-	    hppa*64*|ia64*)
-	      # +Z the default
-	      ;;
-	    *)
-	      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
-	      ;;
-	    esac
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      irix5* | irix6* | nonstopux*)
-	case $cc_basename in
-	  CC)
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-	    # CC pic flag -KPIC is the default.
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      linux*)
-	case $cc_basename in
-	  KCC)
-	    # KAI C++ Compiler
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
-	    ;;
-	  icpc)
-	    # Intel C++
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
-	    ;; 
-	  cxx)
-	    # Compaq C++
-	    # Make sure the PIC flag is empty.  It appears that all Alpha
-	    # Linux and Compaq Tru64 Unix objects are PIC.
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      lynxos*)
-	;;
-      m88k*)
-	;;
-      mvs*)
-	case $cc_basename in
-	  cxx)
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-W c,exportall'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      netbsd*)
-	;;
-      osf3* | osf4* | osf5*)
-	case $cc_basename in
-	  KCC)
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
-	    ;;
-	  RCC)
-	    # Rational C++ 2.4.1
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
-	    ;;
-	  cxx)
-	    # Digital/Compaq C++
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	    # Make sure the PIC flag is empty.  It appears that all Alpha
-	    # Linux and Compaq Tru64 Unix objects are PIC.
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      psos*)
-	;;
-      sco*)
-	case $cc_basename in
-	  CC)
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      solaris*)
-	case $cc_basename in
-	  CC)
-	    # Sun C++ 4.2, 5.x and Centerline C++
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
-	    ;;
-	  gcx)
-	    # Green Hills C++ Compiler
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      sunos4*)
-	case $cc_basename in
-	  CC)
-	    # Sun C++ 4.x
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
-	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-	    ;;
-	  lcc)
-	    # Lucid
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      tandem*)
-	case $cc_basename in
-	  NCC)
-	    # NonStop-UX NCC 3.20
-	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-	    ;;
-	  *)
-	    ;;
-	esac
-	;;
-      unixware*)
-	;;
-      vxworks*)
-	;;
-      *)
-	_LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
-	;;
+        ;;
     esac
-  fi
-],
+    AC_MSG_RESULT([$enable_shared])
+
+    AC_MSG_CHECKING([whether to build static libraries])
+    # Make sure either enable_shared or enable_static is yes.
+    test "$enable_shared" = yes || enable_static=yes
+    AC_MSG_RESULT([$enable_static])
+
+    _LT_TAGVAR(GCC, $1)="$G77"
+    _LT_TAGVAR(LD, $1)="$LD"
+
+    ## CAVEAT EMPTOR:
+    ## There is no encapsulation within the following macros, do not change
+    ## the running order or otherwise move them around unless you know exactly
+    ## what you are doing...
+    _LT_COMPILER_PIC($1)
+    _LT_COMPILER_C_O($1)
+    _LT_COMPILER_FILE_LOCKS($1)
+    _LT_LINKER_SHLIBS($1)
+    _LT_SYS_DYNAMIC_LINKER($1)
+    _LT_LINKER_HARDCODE_LIBPATH($1)
+
+    _LT_CONFIG($1)
+  fi # test -n "$compiler"
+
+  GCC=$lt_save_GCC
+  CC="$lt_save_CC"
+fi # test "$_lt_disable_F77" != yes
+
+AC_LANG_POP
+])# _LT_LANG_F77_CONFIG
+
+
+# _LT_PROG_FC
+# -----------
+# Since AC_PROG_FC is broken, in that it returns the empty string
+# if there is no fortran compiler, we have our own version here.
+m4_defun([_LT_PROG_FC],
 [
-  if test "$GCC" = yes; then
-    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
+pushdef([AC_MSG_ERROR], [_lt_disable_FC=yes])
+AC_PROG_FC
+if test -z "$FC" || test "X$FC" = "Xno"; then
+  _lt_disable_FC=yes
+fi
+popdef([AC_MSG_ERROR])
+])# _LT_PROG_FC
+
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([_LT_PROG_FC], [])
+
+
+# _LT_LANG_FC_CONFIG([TAG])
+# -------------------------
+# Ensure that the configuration variables for a Fortran compiler are
+# suitably defined.  These variables are subsequently used by _LT_CONFIG
+# to write the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_FC_CONFIG],
+[AC_REQUIRE([_LT_PROG_FC])dnl
+AC_LANG_PUSH(Fortran)
+
+_LT_TAGVAR(archive_cmds_need_lc, $1)=no
+_LT_TAGVAR(allow_undefined_flag, $1)=
+_LT_TAGVAR(always_export_symbols, $1)=no
+_LT_TAGVAR(archive_expsym_cmds, $1)=
+_LT_TAGVAR(export_dynamic_flag_spec, $1)=
+_LT_TAGVAR(hardcode_direct, $1)=no
+_LT_TAGVAR(hardcode_direct_absolute, $1)=no
+_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
+_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
+_LT_TAGVAR(hardcode_libdir_separator, $1)=
+_LT_TAGVAR(hardcode_minus_L, $1)=no
+_LT_TAGVAR(hardcode_automatic, $1)=no
+_LT_TAGVAR(inherit_rpath, $1)=no
+_LT_TAGVAR(module_cmds, $1)=
+_LT_TAGVAR(module_expsym_cmds, $1)=
+_LT_TAGVAR(link_all_deplibs, $1)=unknown
+_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
+_LT_TAGVAR(no_undefined_flag, $1)=
+_LT_TAGVAR(whole_archive_flag_spec, $1)=
+_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+
+# Source file extension for fc test sources.
+ac_ext=${ac_fc_srcext-f}
+
+# Object file extension for compiled fc test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
+
+# No sense in running all these tests if we already determined that
+# the FC compiler isn't working.  Some variables (like enable_shared)
+# are currently assumed to apply to all compilers on this platform,
+# and will be corrupted by setting them based on a non-working compiler.
+if test "$_lt_disable_FC" != yes; then
+  # Code to be used in simple compile tests
+  lt_simple_compile_test_code="\
+      subroutine t
+      return
+      end
+"
 
+  # Code to be used in simple link tests
+  lt_simple_link_test_code="\
+      program t
+      end
+"
+
+  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
+  _LT_TAG_COMPILER
+
+  # save warnings/boilerplate of simple test code
+  _LT_COMPILER_BOILERPLATE
+  _LT_LINKER_BOILERPLATE
+
+  # Allow CC to be a program name with arguments.
+  lt_save_CC="$CC"
+  lt_save_GCC=$GCC
+  CC=${FC-"f95"}
+  compiler=$CC
+  GCC=$ac_cv_fc_compiler_gnu
+
+  _LT_TAGVAR(compiler, $1)=$CC
+  _LT_CC_BASENAME([$compiler])
+
+  if test -n "$compiler"; then
+    AC_MSG_CHECKING([if libtool supports shared libraries])
+    AC_MSG_RESULT([$can_build_shared])
+
+    AC_MSG_CHECKING([whether to build shared libraries])
+    test "$can_build_shared" = "no" && enable_shared=no
+
+    # On AIX, shared libraries and static libraries use the same namespace, and
+    # are all built from PIC.
     case $host_os in
-      aix*)
-      # All AIX code is PIC.
-      if test "$host_cpu" = ia64; then
-	# AIX 5 now supports IA64 processor
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      fi
-      ;;
+      aix3*)
+        test "$enable_shared" = yes && enable_static=no
+        if test -n "$RANLIB"; then
+          archive_cmds="$archive_cmds~\$RANLIB \$lib"
+          postinstall_cmds='$RANLIB $lib'
+        fi
+        ;;
+      aix[[4-9]]*)
+	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
+	  test "$enable_shared" = yes && enable_static=no
+	fi
+        ;;
+    esac
+    AC_MSG_RESULT([$enable_shared])
 
-    amigaos*)
-      # FIXME: we need at least 68020 code to build shared libraries, but
-      # adding the `-m68020' flag to GCC prevents building anything better,
-      # like `-m68040'.
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
-      ;;
+    AC_MSG_CHECKING([whether to build static libraries])
+    # Make sure either enable_shared or enable_static is yes.
+    test "$enable_shared" = yes || enable_static=yes
+    AC_MSG_RESULT([$enable_static])
+
+    _LT_TAGVAR(GCC, $1)="$ac_cv_fc_compiler_gnu"
+    _LT_TAGVAR(LD, $1)="$LD"
+
+    ## CAVEAT EMPTOR:
+    ## There is no encapsulation within the following macros, do not change
+    ## the running order or otherwise move them around unless you know exactly
+    ## what you are doing...
+    _LT_SYS_HIDDEN_LIBDEPS($1)
+    _LT_COMPILER_PIC($1)
+    _LT_COMPILER_C_O($1)
+    _LT_COMPILER_FILE_LOCKS($1)
+    _LT_LINKER_SHLIBS($1)
+    _LT_SYS_DYNAMIC_LINKER($1)
+    _LT_LINKER_HARDCODE_LIBPATH($1)
+
+    _LT_CONFIG($1)
+  fi # test -n "$compiler"
+
+  GCC=$lt_save_GCC
+  CC="$lt_save_CC"
+fi # test "$_lt_disable_FC" != yes
+
+AC_LANG_POP
+])# _LT_LANG_FC_CONFIG
+
+
+# _LT_LANG_GCJ_CONFIG([TAG])
+# --------------------------
+# Ensure that the configuration variables for the GNU Java Compiler compiler
+# are suitably defined.  These variables are subsequently used by _LT_CONFIG
+# to write the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_GCJ_CONFIG],
+[AC_REQUIRE([LT_PROG_GCJ])dnl
+AC_LANG_SAVE
+
+# Source file extension for Java test sources.
+ac_ext=java
+
+# Object file extension for compiled Java test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
+
+# Code to be used in simple compile tests
+lt_simple_compile_test_code="class foo {}"
+
+# Code to be used in simple link tests
+lt_simple_link_test_code='public class conftest { public static void main(String[[]] argv) {}; }'
+
+# ltmain only uses $CC for tagged configurations so make sure $CC is set.
+_LT_TAG_COMPILER
+
+# save warnings/boilerplate of simple test code
+_LT_COMPILER_BOILERPLATE
+_LT_LINKER_BOILERPLATE
+
+# Allow CC to be a program name with arguments.
+lt_save_CC="$CC"
+lt_save_GCC=$GCC
+GCC=yes
+CC=${GCJ-"gcj"}
+compiler=$CC
+_LT_TAGVAR(compiler, $1)=$CC
+_LT_TAGVAR(LD, $1)="$LD"
+_LT_CC_BASENAME([$compiler])
+
+# GCJ did not exist at the time GCC didn't implicitly link libc in.
+_LT_TAGVAR(archive_cmds_need_lc, $1)=no
+
+_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
+
+if test -n "$compiler"; then
+  _LT_COMPILER_NO_RTTI($1)
+  _LT_COMPILER_PIC($1)
+  _LT_COMPILER_C_O($1)
+  _LT_COMPILER_FILE_LOCKS($1)
+  _LT_LINKER_SHLIBS($1)
+  _LT_LINKER_HARDCODE_LIBPATH($1)
+
+  _LT_CONFIG($1)
+fi
+
+AC_LANG_RESTORE
+
+GCC=$lt_save_GCC
+CC="$lt_save_CC"
+])# _LT_LANG_GCJ_CONFIG
+
+
+# _LT_LANG_RC_CONFIG([TAG])
+# -------------------------
+# Ensure that the configuration variables for the Windows resource compiler
+# are suitably defined.  These variables are subsequently used by _LT_CONFIG
+# to write the compiler configuration to `libtool'.
+m4_defun([_LT_LANG_RC_CONFIG],
+[AC_REQUIRE([LT_PROG_RC])dnl
+AC_LANG_SAVE
+
+# Source file extension for RC test sources.
+ac_ext=rc
+
+# Object file extension for compiled RC test sources.
+objext=o
+_LT_TAGVAR(objext, $1)=$objext
+
+# Code to be used in simple compile tests
+lt_simple_compile_test_code='sample MENU { MENUITEM "&Soup", 100, CHECKED }'
 
-    beos* | cygwin* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
-      # PIC is the default for these OSes.
-      ;;
+# Code to be used in simple link tests
+lt_simple_link_test_code="$lt_simple_compile_test_code"
 
-    mingw* | pw32* | os2*)
-      # This hack is so that the source file can tell whether it is being
-      # built for inclusion in a dll (and should export symbols for example).
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
-      ;;
+# ltmain only uses $CC for tagged configurations so make sure $CC is set.
+_LT_TAG_COMPILER
 
-    darwin* | rhapsody*)
-      # PIC is the default on this platform
-      # Common symbols not allowed in MH_DYLIB files
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
-      ;;
+# save warnings/boilerplate of simple test code
+_LT_COMPILER_BOILERPLATE
+_LT_LINKER_BOILERPLATE
 
-    msdosdjgpp*)
-      # Just because we use GCC doesn't mean we suddenly get shared libraries
-      # on systems that don't support them.
-      _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
-      enable_shared=no
-      ;;
+# Allow CC to be a program name with arguments.
+lt_save_CC="$CC"
+lt_save_GCC=$GCC
+GCC=
+CC=${RC-"windres"}
+compiler=$CC
+_LT_TAGVAR(compiler, $1)=$CC
+_LT_CC_BASENAME([$compiler])
+_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
 
-    sysv4*MP*)
-      if test -d /usr/nec; then
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
-      fi
-      ;;
+if test -n "$compiler"; then
+  :
+  _LT_CONFIG($1)
+fi
 
-    hpux*)
-      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
-      # not for PA HP-UX.
-      case "$host_cpu" in
-      hppa*64*|ia64*)
-	# +Z the default
-	;;
-      *)
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
-	;;
-      esac
-      ;;
+GCC=$lt_save_GCC
+AC_LANG_RESTORE
+CC="$lt_save_CC"
+])# _LT_LANG_RC_CONFIG
 
-    *)
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
-      ;;
-    esac
-  else
-    # PORTME Check for flag to pass linker flags through the system compiler.
-    case $host_os in
-    aix*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      if test "$host_cpu" = ia64; then
-	# AIX 5 now supports IA64 processor
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      else
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
-      fi
-      ;;
 
-    mingw* | pw32* | os2*)
-      # This hack is so that the source file can tell whether it is being
-      # built for inclusion in a dll (and should export symbols for example).
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
-      ;;
+# LT_PROG_GCJ
+# -----------
+AC_DEFUN([LT_PROG_GCJ],
+[m4_ifdef([AC_PROG_GCJ], [AC_PROG_GCJ],
+  [m4_ifdef([A][M_PROG_GCJ], [A][M_PROG_GCJ],
+    [AC_CHECK_TOOL(GCJ, gcj,)
+      test "x${GCJFLAGS+set}" = xset || GCJFLAGS="-g -O2"
+      AC_SUBST(GCJFLAGS)])])[]dnl
+])
 
-    hpux9* | hpux10* | hpux11*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
-      # not for PA HP-UX.
-      case "$host_cpu" in
-      hppa*64*|ia64*)
-	# +Z the default
-	;;
-      *)
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
-	;;
-      esac
-      # Is there a better lt_prog_compiler_static that works with the bundled CC?
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
-      ;;
+# Old name:
+AU_ALIAS([LT_AC_PROG_GCJ], [LT_PROG_GCJ])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([LT_AC_PROG_GCJ], [])
 
-    irix5* | irix6* | nonstopux*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      # PIC (with -KPIC) is the default.
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-      ;;
 
-    newsos6)
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      ;;
+# LT_PROG_RC
+# ----------
+AC_DEFUN([LT_PROG_RC],
+[AC_CHECK_TOOL(RC, windres,)
+])
 
-    linux*)
-      case $CC in
-      icc|ecc)
-	_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
-        ;;
-      ccc)
-        _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-        # All Alpha code is PIC.
-        _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-        ;;
-      esac
-      ;;
+# Old name:
+AU_ALIAS([LT_AC_PROG_RC], [LT_PROG_RC])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([LT_AC_PROG_RC], [])
 
-    osf3* | osf4* | osf5*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      # All OSF/1 code is PIC.
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
-      ;;
 
-    sco3.2v5*)
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-Kpic'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-dn'
-      ;;
+# _LT_DECL_EGREP
+# --------------
+# If we don't have a new enough Autoconf to choose the best grep
+# available, choose the one first in the user's PATH.
+m4_defun([_LT_DECL_EGREP],
+[AC_REQUIRE([AC_PROG_EGREP])dnl
+AC_REQUIRE([AC_PROG_FGREP])dnl
+test -z "$GREP" && GREP=grep
+_LT_DECL([], [GREP], [1], [A grep program that handles long lines])
+_LT_DECL([], [EGREP], [1], [An ERE matcher])
+_LT_DECL([], [FGREP], [1], [A literal string matcher])
+dnl Non-bleeding-edge autoconf doesn't subst GREP, so do it here too
+AC_SUBST([GREP])
+])
 
-    solaris*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      ;;
 
-    sunos4*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      ;;
+# _LT_DECL_OBJDUMP
+# --------------
+# If we don't have a new enough Autoconf to choose the best objdump
+# available, choose the one first in the user's PATH.
+m4_defun([_LT_DECL_OBJDUMP],
+[AC_CHECK_TOOL(OBJDUMP, objdump, false)
+test -z "$OBJDUMP" && OBJDUMP=objdump
+_LT_DECL([], [OBJDUMP], [1], [An object symbol dumper])
+AC_SUBST([OBJDUMP])
+])
 
-    sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
-      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      ;;
 
-    sysv4*MP*)
-      if test -d /usr/nec ;then
-	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-Kconform_pic'
-	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      fi
-      ;;
+# _LT_DECL_SED
+# ------------
+# Check for a fully-functional sed program, that truncates
+# as few characters as possible.  Prefer GNU sed if found.
+m4_defun([_LT_DECL_SED],
+[AC_PROG_SED
+test -z "$SED" && SED=sed
+Xsed="$SED -e 1s/^X//"
+_LT_DECL([], [SED], [1], [A sed program that does not truncate output])
+_LT_DECL([], [Xsed], ["\$SED -e 1s/^X//"],
+    [Sed that helps us avoid accidentally triggering echo(1) options like -n])
+])# _LT_DECL_SED
 
-    uts4*)
-      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
-      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
-      ;;
+m4_ifndef([AC_PROG_SED], [
+# NOTE: This macro has been submitted for inclusion into   #
+#  GNU Autoconf as AC_PROG_SED.  When it is available in   #
+#  a released version of Autoconf we should remove this    #
+#  macro and use it instead.                               #
 
-    *)
-      _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
-      ;;
-    esac
+m4_defun([AC_PROG_SED],
+[AC_MSG_CHECKING([for a sed that does not truncate output])
+AC_CACHE_VAL(lt_cv_path_SED,
+[# Loop through the user's path and test for sed and gsed.
+# Then use that list of sed's as ones to test for truncation.
+as_save_IFS=$IFS; IFS=$PATH_SEPARATOR
+for as_dir in $PATH
+do
+  IFS=$as_save_IFS
+  test -z "$as_dir" && as_dir=.
+  for lt_ac_prog in sed gsed; do
+    for ac_exec_ext in '' $ac_executable_extensions; do
+      if $as_executable_p "$as_dir/$lt_ac_prog$ac_exec_ext"; then
+        lt_ac_sed_list="$lt_ac_sed_list $as_dir/$lt_ac_prog$ac_exec_ext"
+      fi
+    done
+  done
+done
+IFS=$as_save_IFS
+lt_ac_max=0
+lt_ac_count=0
+# Add /usr/xpg4/bin/sed as it is typically found on Solaris
+# along with /bin/sed that truncates output.
+for lt_ac_sed in $lt_ac_sed_list /usr/xpg4/bin/sed; do
+  test ! -f $lt_ac_sed && continue
+  cat /dev/null > conftest.in
+  lt_ac_count=0
+  echo $ECHO_N "0123456789$ECHO_C" >conftest.in
+  # Check for GNU sed and select it if it is found.
+  if "$lt_ac_sed" --version 2>&1 < /dev/null | grep 'GNU' > /dev/null; then
+    lt_cv_path_SED=$lt_ac_sed
+    break
   fi
+  while true; do
+    cat conftest.in conftest.in >conftest.tmp
+    mv conftest.tmp conftest.in
+    cp conftest.in conftest.nl
+    echo >>conftest.nl
+    $lt_ac_sed -e 's/a$//' < conftest.nl >conftest.out || break
+    cmp -s conftest.out conftest.nl || break
+    # 10000 chars as input seems more than enough
+    test $lt_ac_count -gt 10 && break
+    lt_ac_count=`expr $lt_ac_count + 1`
+    if test $lt_ac_count -gt $lt_ac_max; then
+      lt_ac_max=$lt_ac_count
+      lt_cv_path_SED=$lt_ac_sed
+    fi
+  done
+done
 ])
-AC_MSG_RESULT([$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)])
+SED=$lt_cv_path_SED
+AC_SUBST([SED])
+AC_MSG_RESULT([$SED])
+])#AC_PROG_SED
+])#m4_ifndef
 
-#
-# Check to make sure the PIC flag actually works.
-#
-if test -n "$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)"; then
-  AC_LIBTOOL_COMPILER_OPTION([if $compiler PIC flag $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1) works],
-    _LT_AC_TAGVAR(lt_prog_compiler_pic_works, $1),
-    [$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)ifelse([$1],[],[ -DPIC],[ifelse([$1],[CXX],[ -DPIC],[])])], [],
-    [case $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1) in
-     "" | " "*) ;;
-     *) _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=" $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)" ;;
-     esac],
-    [_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-     _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no])
+# Old name:
+AU_ALIAS([LT_AC_PROG_SED], [AC_PROG_SED])
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([LT_AC_PROG_SED], [])
+
+
+# _LT_CHECK_SHELL_FEATURES
+# ------------------------
+# Find out whether the shell is Bourne or XSI compatible,
+# or has some other useful features.
+m4_defun([_LT_CHECK_SHELL_FEATURES],
+[AC_MSG_CHECKING([whether the shell understands some XSI constructs])
+# Try some XSI features
+xsi_shell=no
+( _lt_dummy="a/b/c"
+  test "${_lt_dummy##*/},${_lt_dummy%/*},"${_lt_dummy%"$_lt_dummy"}, \
+      = c,a/b,, \
+    && eval 'test $(( 1 + 1 )) -eq 2 \
+    && test "${#_lt_dummy}" -eq 5' ) >/dev/null 2>&1 \
+  && xsi_shell=yes
+AC_MSG_RESULT([$xsi_shell])
+_LT_CONFIG_LIBTOOL_INIT([xsi_shell='$xsi_shell'])
+
+AC_MSG_CHECKING([whether the shell understands "+="])
+lt_shell_append=no
+( foo=bar; set foo baz; eval "$[1]+=\$[2]" && test "$foo" = barbaz ) \
+    >/dev/null 2>&1 \
+  && lt_shell_append=yes
+AC_MSG_RESULT([$lt_shell_append])
+_LT_CONFIG_LIBTOOL_INIT([lt_shell_append='$lt_shell_append'])
+
+if ( (MAIL=60; unset MAIL) || exit) >/dev/null 2>&1; then
+  lt_unset=unset
+else
+  lt_unset=false
 fi
-case "$host_os" in
-  # For platforms which do not support PIC, -DPIC is meaningless:
-  *djgpp*)
-    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
-    ;;
-  *)
-    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)="$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)ifelse([$1],[],[ -DPIC],[ifelse([$1],[CXX],[ -DPIC],[])])"
-    ;;
+_LT_DECL([], [lt_unset], [0], [whether the shell understands "unset"])dnl
+
+# test EBCDIC or ASCII
+case `echo X|tr X '\101'` in
+ A) # ASCII based system
+    # \n is not interpreted correctly by Solaris 8 /usr/ucb/tr
+  lt_SP2NL='tr \040 \012'
+  lt_NL2SP='tr \015\012 \040\040'
+  ;;
+ *) # EBCDIC based system
+  lt_SP2NL='tr \100 \n'
+  lt_NL2SP='tr \r\n \100\100'
+  ;;
 esac
-])
+_LT_DECL([SP2NL], [lt_SP2NL], [1], [turn spaces into newlines])dnl
+_LT_DECL([NL2SP], [lt_NL2SP], [1], [turn newlines into spaces])dnl
+])# _LT_CHECK_SHELL_FEATURES
+
+
+# _LT_PROG_XSI_SHELLFNS
+# ---------------------
+# Bourne and XSI compatible variants of some useful shell functions.
+m4_defun([_LT_PROG_XSI_SHELLFNS],
+[case $xsi_shell in
+  yes)
+    cat << \_LT_EOF >> "$cfgfile"
+
+# func_dirname file append nondir_replacement
+# Compute the dirname of FILE.  If nonempty, add APPEND to the result,
+# otherwise set result to NONDIR_REPLACEMENT.
+func_dirname ()
+{
+  case ${1} in
+    */*) func_dirname_result="${1%/*}${2}" ;;
+    *  ) func_dirname_result="${3}" ;;
+  esac
+}
 
+# func_basename file
+func_basename ()
+{
+  func_basename_result="${1##*/}"
+}
 
-# AC_LIBTOOL_PROG_LD_SHLIBS([TAGNAME])
-# ------------------------------------
-# See if the linker supports building shared libraries.
-AC_DEFUN([AC_LIBTOOL_PROG_LD_SHLIBS],
-[AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
-ifelse([$1],[CXX],[
-  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
-  case $host_os in
-  aix4* | aix5*)
-    # If we're using GNU nm, then we don't want the "-C" option.
-    # -C means demangle to AIX nm, but means don't demangle with GNU nm
-    if $NM -V 2>&1 | grep 'GNU' > /dev/null; then
-      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
-    else
-      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
-    fi
+# func_dirname_and_basename file append nondir_replacement
+# perform func_basename and func_dirname in a single function
+# call:
+#   dirname:  Compute the dirname of FILE.  If nonempty,
+#             add APPEND to the result, otherwise set result
+#             to NONDIR_REPLACEMENT.
+#             value returned in "$func_dirname_result"
+#   basename: Compute filename of FILE.
+#             value retuned in "$func_basename_result"
+# Implementation must be kept synchronized with func_dirname
+# and func_basename. For efficiency, we do not delegate to
+# those functions but instead duplicate the functionality here.
+func_dirname_and_basename ()
+{
+  case ${1} in
+    */*) func_dirname_result="${1%/*}${2}" ;;
+    *  ) func_dirname_result="${3}" ;;
+  esac
+  func_basename_result="${1##*/}"
+}
+
+# func_stripname prefix suffix name
+# strip PREFIX and SUFFIX off of NAME.
+# PREFIX and SUFFIX must not contain globbing or regex special
+# characters, hashes, percent signs, but SUFFIX may contain a leading
+# dot (in which case that matches only a dot).
+func_stripname ()
+{
+  # pdksh 5.2.14 does not do ${X%$Y} correctly if both X and Y are
+  # positional parameters, so assign one to ordinary parameter first.
+  func_stripname_result=${3}
+  func_stripname_result=${func_stripname_result#"${1}"}
+  func_stripname_result=${func_stripname_result%"${2}"}
+}
+
+# func_opt_split
+func_opt_split ()
+{
+  func_opt_split_opt=${1%%=*}
+  func_opt_split_arg=${1#*=}
+}
+
+# func_lo2o object
+func_lo2o ()
+{
+  case ${1} in
+    *.lo) func_lo2o_result=${1%.lo}.${objext} ;;
+    *)    func_lo2o_result=${1} ;;
+  esac
+}
+
+# func_xform libobj-or-source
+func_xform ()
+{
+  func_xform_result=${1%.*}.lo
+}
+
+# func_arith arithmetic-term...
+func_arith ()
+{
+  func_arith_result=$(( $[*] ))
+}
+
+# func_len string
+# STRING may not start with a hyphen.
+func_len ()
+{
+  func_len_result=${#1}
+}
+
+_LT_EOF
     ;;
-  pw32*)
-    _LT_AC_TAGVAR(export_symbols_cmds, $1)="$ltdll_cmds"
-  ;;
-  cygwin* | mingw*)
-    _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGS]] /s/.* \([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]] /s/.* //'\'' | sort | uniq > $export_symbols'
-  ;;
-  *)
-    _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
-  ;;
+  *) # Bourne compatible functions.
+    cat << \_LT_EOF >> "$cfgfile"
+
+# func_dirname file append nondir_replacement
+# Compute the dirname of FILE.  If nonempty, add APPEND to the result,
+# otherwise set result to NONDIR_REPLACEMENT.
+func_dirname ()
+{
+  # Extract subdirectory from the argument.
+  func_dirname_result=`$ECHO "X${1}" | $Xsed -e "$dirname"`
+  if test "X$func_dirname_result" = "X${1}"; then
+    func_dirname_result="${3}"
+  else
+    func_dirname_result="$func_dirname_result${2}"
+  fi
+}
+
+# func_basename file
+func_basename ()
+{
+  func_basename_result=`$ECHO "X${1}" | $Xsed -e "$basename"`
+}
+
+dnl func_dirname_and_basename
+dnl A portable version of this function is already defined in general.m4sh
+dnl so there is no need for it here.
+
+# func_stripname prefix suffix name
+# strip PREFIX and SUFFIX off of NAME.
+# PREFIX and SUFFIX must not contain globbing or regex special
+# characters, hashes, percent signs, but SUFFIX may contain a leading
+# dot (in which case that matches only a dot).
+# func_strip_suffix prefix name
+func_stripname ()
+{
+  case ${2} in
+    .*) func_stripname_result=`$ECHO "X${3}" \
+           | $Xsed -e "s%^${1}%%" -e "s%\\\\${2}\$%%"`;;
+    *)  func_stripname_result=`$ECHO "X${3}" \
+           | $Xsed -e "s%^${1}%%" -e "s%${2}\$%%"`;;
   esac
-],[
-  runpath_var=
-  _LT_AC_TAGVAR(allow_undefined_flag, $1)=
-  _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=no
-  _LT_AC_TAGVAR(archive_cmds, $1)=
-  _LT_AC_TAGVAR(archive_expsym_cmds, $1)=
-  _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)=
-  _LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1)=
-  _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=
-  _LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
-  _LT_AC_TAGVAR(thread_safe_flag_spec, $1)=
-  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
-  _LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
-  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
-  _LT_AC_TAGVAR(hardcode_direct, $1)=no
-  _LT_AC_TAGVAR(hardcode_minus_L, $1)=no
-  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
-  _LT_AC_TAGVAR(link_all_deplibs, $1)=unknown
-  _LT_AC_TAGVAR(hardcode_automatic, $1)=no
-  _LT_AC_TAGVAR(module_cmds, $1)=
-  _LT_AC_TAGVAR(module_expsym_cmds, $1)=  
-  _LT_AC_TAGVAR(always_export_symbols, $1)=no
-  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
-  # include_expsyms should be a list of space-separated symbols to be *always*
-  # included in the symbol list
-  _LT_AC_TAGVAR(include_expsyms, $1)=
-  # exclude_expsyms can be an extended regexp of symbols to exclude
-  # it will be wrapped by ` (' and `)$', so one must not match beginning or
-  # end of line.  Example: `a|bc|.*d.*' will exclude the symbols `a' and `bc',
-  # as well as any symbol that contains `d'.
-  _LT_AC_TAGVAR(exclude_expsyms, $1)="_GLOBAL_OFFSET_TABLE_"
-  # Although _GLOBAL_OFFSET_TABLE_ is a valid symbol C name, most a.out
-  # platforms (ab)use it in PIC code, but their linkers get confused if
-  # the symbol is explicitly referenced.  Since portable code cannot
-  # rely on this symbol name, it's probably fine to never include it in
-  # preloaded symbol tables.
-  extract_expsyms_cmds=
+}
+
+# sed scripts:
+my_sed_long_opt='1s/^\(-[[^=]]*\)=.*/\1/;q'
+my_sed_long_arg='1s/^-[[^=]]*=//'
+
+# func_opt_split
+func_opt_split ()
+{
+  func_opt_split_opt=`$ECHO "X${1}" | $Xsed -e "$my_sed_long_opt"`
+  func_opt_split_arg=`$ECHO "X${1}" | $Xsed -e "$my_sed_long_arg"`
+}
+
+# func_lo2o object
+func_lo2o ()
+{
+  func_lo2o_result=`$ECHO "X${1}" | $Xsed -e "$lo2o"`
+}
+
+# func_xform libobj-or-source
+func_xform ()
+{
+  func_xform_result=`$ECHO "X${1}" | $Xsed -e 's/\.[[^.]]*$/.lo/'`
+}
+
+# func_arith arithmetic-term...
+func_arith ()
+{
+  func_arith_result=`expr "$[@]"`
+}
+
+# func_len string
+# STRING may not start with a hyphen.
+func_len ()
+{
+  func_len_result=`expr "$[1]" : ".*" 2>/dev/null || echo $max_cmd_len`
+}
 
-  case $host_os in
-  cygwin* | mingw* | pw32*)
-    # FIXME: the MSVC++ port hasn't been tested in a loooong time
-    # When not using gcc, we currently assume that we are using
-    # Microsoft Visual C++.
-    if test "$GCC" != yes; then
-      with_gnu_ld=no
-    fi
+_LT_EOF
+esac
+
+case $lt_shell_append in
+  yes)
+    cat << \_LT_EOF >> "$cfgfile"
+
+# func_append var value
+# Append VALUE to the end of shell variable VAR.
+func_append ()
+{
+  eval "$[1]+=\$[2]"
+}
+_LT_EOF
     ;;
-  openbsd*)
-    with_gnu_ld=no
+  *)
+    cat << \_LT_EOF >> "$cfgfile"
+
+# func_append var value
+# Append VALUE to the end of shell variable VAR.
+func_append ()
+{
+  eval "$[1]=\$$[1]\$[2]"
+}
+
+_LT_EOF
     ;;
   esac
+])
 
-  _LT_AC_TAGVAR(ld_shlibs, $1)=yes
-  if test "$with_gnu_ld" = yes; then
-    # If archive_cmds runs LD, not CC, wlarc should be empty
-    wlarc='${wl}'
+# Helper functions for option handling.                    -*- Autoconf -*-
+#
+#   Copyright (C) 2004, 2005, 2007, 2008 Free Software Foundation, Inc.
+#   Written by Gary V. Vaughan, 2004
+#
+# This file is free software; the Free Software Foundation gives
+# unlimited permission to copy and/or distribute it, with or without
+# modifications, as long as this notice is preserved.
 
-    # See if GNU ld supports shared libraries.
-    case $host_os in
-    aix3* | aix4* | aix5*)
-      # On AIX/PPC, the GNU linker is very broken
-      if test "$host_cpu" != ia64; then
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	cat <<EOF 1>&2
+# serial 6 ltoptions.m4
 
-*** Warning: the GNU linker, at least up to release 2.9.1, is reported
-*** to be unable to reliably create shared libraries on AIX.
-*** Therefore, libtool is disabling shared libraries support.  If you
-*** really care for shared libraries, you may want to modify your PATH
-*** so that a non-GNU linker is found, and then restart.
+# This is to help aclocal find these macros, as it can't see m4_define.
+AC_DEFUN([LTOPTIONS_VERSION], [m4_if([1])])
 
-EOF
-      fi
-      ;;
 
-    amigaos*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/a2ixlibrary.data~$echo "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$echo "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$echo "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$echo "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-
-      # Samuel A. Falvo II <kc5tja@dolphin.openprojects.net> reports
-      # that the semantics of dynamic libraries on AmigaOS, at least up
-      # to version 4, is to share data among multiple programs linked
-      # with the same dynamic library.  Since this doesn't match the
-      # behavior of shared libraries on other platforms, we can't use
-      # them.
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
-      ;;
+# _LT_MANGLE_OPTION(MACRO-NAME, OPTION-NAME)
+# ------------------------------------------
+m4_define([_LT_MANGLE_OPTION],
+[[_LT_OPTION_]m4_bpatsubst($1__$2, [[^a-zA-Z0-9_]], [_])])
 
-    beos*)
-      if $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-	# Joseph Beckenbach <jrb3@best.com> says some releases of gcc
-	# support --undefined.  This deserves some investigation.  FIXME
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
-      else
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-      fi
-      ;;
 
-    cygwin* | mingw* | pw32*)
-      # _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
-      # as there is no search path for DLLs.
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-      _LT_AC_TAGVAR(always_export_symbols, $1)=no
-      _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
-      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGS]] /s/.* \([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]] /s/.* //'\'' | sort | uniq > $export_symbols'
+# _LT_SET_OPTION(MACRO-NAME, OPTION-NAME)
+# ---------------------------------------
+# Set option OPTION-NAME for macro MACRO-NAME, and if there is a
+# matching handler defined, dispatch to it.  Other OPTION-NAMEs are
+# saved as a flag.
+m4_define([_LT_SET_OPTION],
+[m4_define(_LT_MANGLE_OPTION([$1], [$2]))dnl
+m4_ifdef(_LT_MANGLE_DEFUN([$1], [$2]),
+        _LT_MANGLE_DEFUN([$1], [$2]),
+    [m4_warning([Unknown $1 option `$2'])])[]dnl
+])
 
-      if $LD --help 2>&1 | grep 'auto-import' > /dev/null; then
-        _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000 ${wl}--out-implib,$lib'
-	# If the export-symbols file already is a .def file (1st line
-	# is EXPORTS), use it as is; otherwise, prepend...
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
-	  cp $export_symbols $output_objdir/$soname.def;
-	else
-	  echo EXPORTS > $output_objdir/$soname.def;
-	  cat $export_symbols >> $output_objdir/$soname.def;
-	fi~
-	$CC -shared $output_objdir/$soname.def $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000  ${wl}--out-implib,$lib'
-      else
-	ld_shlibs=no
-      fi
-      ;;
 
-    netbsd*)
-      if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
-	wlarc=
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
-      fi
-      ;;
+# _LT_IF_OPTION(MACRO-NAME, OPTION-NAME, IF-SET, [IF-NOT-SET])
+# ------------------------------------------------------------
+# Execute IF-SET if OPTION is set, IF-NOT-SET otherwise.
+m4_define([_LT_IF_OPTION],
+[m4_ifdef(_LT_MANGLE_OPTION([$1], [$2]), [$3], [$4])])
 
-    solaris* | sysv5*)
-      if $LD -v 2>&1 | grep 'BFD 2\.8' > /dev/null; then
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-	cat <<EOF 1>&2
 
-*** Warning: The releases 2.8.* of the GNU linker cannot reliably
-*** create shared libraries on Solaris systems.  Therefore, libtool
-*** is disabling shared libraries support.  We urge you to upgrade GNU
-*** binutils to release 2.9.1 or newer.  Another option is to modify
-*** your PATH or compiler configuration so that the native linker is
-*** used, and then restart.
+# _LT_UNLESS_OPTIONS(MACRO-NAME, OPTION-LIST, IF-NOT-SET)
+# -------------------------------------------------------
+# Execute IF-NOT-SET unless all options in OPTION-LIST for MACRO-NAME
+# are set.
+m4_define([_LT_UNLESS_OPTIONS],
+[m4_foreach([_LT_Option], m4_split(m4_normalize([$2])),
+	    [m4_ifdef(_LT_MANGLE_OPTION([$1], _LT_Option),
+		      [m4_define([$0_found])])])[]dnl
+m4_ifdef([$0_found], [m4_undefine([$0_found])], [$3
+])[]dnl
+])
 
-EOF
-      elif $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
-      else
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-      fi
-      ;;
 
-    sunos4*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bshareable -o $lib $libobjs $deplibs $linker_flags'
-      wlarc=
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
+# _LT_SET_OPTIONS(MACRO-NAME, OPTION-LIST)
+# ----------------------------------------
+# OPTION-LIST is a space-separated list of Libtool options associated
+# with MACRO-NAME.  If any OPTION has a matching handler declared with
+# LT_OPTION_DEFINE, dispatch to that macro; otherwise complain about
+# the unknown option and exit.
+m4_defun([_LT_SET_OPTIONS],
+[# Set options
+m4_foreach([_LT_Option], m4_split(m4_normalize([$2])),
+    [_LT_SET_OPTION([$1], _LT_Option)])
+
+m4_if([$1],[LT_INIT],[
+  dnl
+  dnl Simply set some default values (i.e off) if boolean options were not
+  dnl specified:
+  _LT_UNLESS_OPTIONS([LT_INIT], [dlopen], [enable_dlopen=no
+  ])
+  _LT_UNLESS_OPTIONS([LT_INIT], [win32-dll], [enable_win32_dll=no
+  ])
+  dnl
+  dnl If no reference was made to various pairs of opposing options, then
+  dnl we run the default mode handler for the pair.  For example, if neither
+  dnl `shared' nor `disable-shared' was passed, we enable building of shared
+  dnl archives by default:
+  _LT_UNLESS_OPTIONS([LT_INIT], [shared disable-shared], [_LT_ENABLE_SHARED])
+  _LT_UNLESS_OPTIONS([LT_INIT], [static disable-static], [_LT_ENABLE_STATIC])
+  _LT_UNLESS_OPTIONS([LT_INIT], [pic-only no-pic], [_LT_WITH_PIC])
+  _LT_UNLESS_OPTIONS([LT_INIT], [fast-install disable-fast-install],
+  		   [_LT_ENABLE_FAST_INSTALL])
+  ])
+])# _LT_SET_OPTIONS
 
-    *)
-      if $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
-      else
-	_LT_AC_TAGVAR(ld_shlibs, $1)=no
-      fi
-      ;;
-    esac
 
-    if test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = yes; then
-      runpath_var=LD_RUN_PATH
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
-      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
-      # ancient GNU ld didn't support --whole-archive et. al.
-      if $LD --help 2>&1 | grep 'no-whole-archive' > /dev/null; then
- 	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
-      else
-  	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
-      fi
-    fi
-  else
-    # PORTME fill in a description of your system's linker (not GNU ld)
-    case $host_os in
-    aix3*)
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-      _LT_AC_TAGVAR(always_export_symbols, $1)=yes
-      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$LD -o $output_objdir/$soname $libobjs $deplibs $linker_flags -bE:$export_symbols -T512 -H512 -bM:SRE~$AR $AR_FLAGS $lib $output_objdir/$soname'
-      # Note: this linker hardcodes the directories in LIBPATH if there
-      # are no directories specified by -L.
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      if test "$GCC" = yes && test -z "$link_static_flag"; then
-	# Neither direct hardcoding nor static linking is supported with a
-	# broken collect2.
-	_LT_AC_TAGVAR(hardcode_direct, $1)=unsupported
-      fi
-      ;;
 
-    aix4* | aix5*)
-      if test "$host_cpu" = ia64; then
-	# On IA64, the linker does run time linking by default, so we don't
-	# have to do anything special.
-	aix_use_runtimelinking=no
-	exp_sym_flag='-Bexport'
-	no_entry_flag=""
-      else
-	# If we're using GNU nm, then we don't want the "-C" option.
-	# -C means demangle to AIX nm, but means don't demangle with GNU nm
-	if $NM -V 2>&1 | grep 'GNU' > /dev/null; then
-	  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
-	else
-	  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
-	fi
-	aix_use_runtimelinking=no
+# _LT_MANGLE_DEFUN(MACRO-NAME, OPTION-NAME)
+# -----------------------------------------
+m4_define([_LT_MANGLE_DEFUN],
+[[_LT_OPTION_DEFUN_]m4_bpatsubst(m4_toupper([$1__$2]), [[^A-Z0-9_]], [_])])
 
-	# Test if we are trying to use run time linking or normal
-	# AIX style linking. If -brtl is somewhere in LDFLAGS, we
-	# need to do runtime linking.
-	case $host_os in aix4.[[23]]|aix4.[[23]].*|aix5*)
-	  for ld_flag in $LDFLAGS; do
-  	  if (test $ld_flag = "-brtl" || test $ld_flag = "-Wl,-brtl"); then
-  	    aix_use_runtimelinking=yes
-  	    break
-  	  fi
-	  done
-	esac
 
-	exp_sym_flag='-bexport'
-	no_entry_flag='-bnoentry'
-      fi
+# LT_OPTION_DEFINE(MACRO-NAME, OPTION-NAME, CODE)
+# -----------------------------------------------
+m4_define([LT_OPTION_DEFINE],
+[m4_define(_LT_MANGLE_DEFUN([$1], [$2]), [$3])[]dnl
+])# LT_OPTION_DEFINE
 
-      # When large executables or shared objects are built, AIX ld can
-      # have problems creating the table of contents.  If linking a library
-      # or program results in "error TOC overflow" add -mminimal-toc to
-      # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
-      # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.
 
-      _LT_AC_TAGVAR(archive_cmds, $1)=''
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=':'
-      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+# dlopen
+# ------
+LT_OPTION_DEFINE([LT_INIT], [dlopen], [enable_dlopen=yes
+])
 
-      if test "$GCC" = yes; then
-	case $host_os in aix4.[012]|aix4.[012].*)
-	# We only want to do this on AIX 4.2 and lower, the check
-	# below for broken collect2 doesn't work under 4.3+
-	  collect2name=`${CC} -print-prog-name=collect2`
-	  if test -f "$collect2name" && \
-  	   strings "$collect2name" | grep resolve_lib_name >/dev/null
-	  then
-  	  # We have reworked collect2
-  	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-	  else
-  	  # We have old collect2
-  	  _LT_AC_TAGVAR(hardcode_direct, $1)=unsupported
-  	  # It fails to find uninstalled libraries when the uninstalled
-  	  # path is not listed in the libpath.  Setting hardcode_minus_L
-  	  # to unsupported forces relinking
-  	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-  	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-  	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
-	  fi
-	esac
-	shared_flag='-shared'
-      else
-	# not using gcc
-	if test "$host_cpu" = ia64; then
-  	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
-  	# chokes on -Wl,-G. The following line is correct:
-	  shared_flag='-G'
-	else
-  	if test "$aix_use_runtimelinking" = yes; then
-	    shared_flag='${wl}-G'
-	  else
-	    shared_flag='${wl}-bM:SRE'
-  	fi
-	fi
-      fi
+AU_DEFUN([AC_LIBTOOL_DLOPEN],
+[_LT_SET_OPTION([LT_INIT], [dlopen])
+AC_DIAGNOSE([obsolete],
+[$0: Remove this warning and the call to _LT_SET_OPTION when you
+put the `dlopen' option into LT_INIT's first parameter.])
+])
 
-      # It seems that -bexpall does not export symbols beginning with
-      # underscore (_), so it is better to generate a list of symbols to export.
-      _LT_AC_TAGVAR(always_export_symbols, $1)=yes
-      if test "$aix_use_runtimelinking" = yes; then
-	# Warning - without using the other runtime loading flags (-brtl),
-	# -berok will link without error, but may produce a broken library.
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)='-berok'
-       # Determine the default libpath from the value encoded in an empty executable.
-       _LT_AC_SYS_LIBPATH_AIX
-       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then echo "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols $shared_flag"
-       else
-	if test "$host_cpu" = ia64; then
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
-	  _LT_AC_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
-	  _LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols"
-	else
-	 # Determine the default libpath from the value encoded in an empty executable.
-	 _LT_AC_SYS_LIBPATH_AIX
-	 _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
-	  # Warning - without using the other run time loading flags,
-	  # -berok will link without error, but may produce a broken library.
-	  _LT_AC_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
-	  _LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
-	  # -bexpall does not export symbols beginning with underscore (_)
-	  _LT_AC_TAGVAR(always_export_symbols, $1)=yes
-	  # Exported symbols can be pulled into shared objects from archives
-	  _LT_AC_TAGVAR(whole_archive_flag_spec, $1)=' '
-	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
-	  # This is similar to how AIX traditionally builds it's shared libraries.
-	  _LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}-bE:$export_symbols ${wl}-bnoentry${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
-	fi
-      fi
-      ;;
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_DLOPEN], [])
 
-    amigaos*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/a2ixlibrary.data~$echo "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$echo "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$echo "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$echo "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      # see comment about different semantics on the GNU ld section
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
-      ;;
 
-    bsdi4*)
-      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=-rdynamic
-      ;;
+# win32-dll
+# ---------
+# Declare package support for building win32 dll's.
+LT_OPTION_DEFINE([LT_INIT], [win32-dll],
+[enable_win32_dll=yes
 
-    cygwin* | mingw* | pw32*)
-      # When not using gcc, we currently assume that we are using
-      # Microsoft Visual C++.
-      # hardcode_libdir_flag_spec is actually meaningless, as there is
-      # no search path for DLLs.
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-      # Tell ltmain to make .lib files, not .a files.
-      libext=lib
-      # Tell ltmain to make .dll files, not .so files.
-      shrext=".dll"
-      # FIXME: Setting linknames here is a bad hack.
-      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -o $lib $libobjs $compiler_flags `echo "$deplibs" | $SED -e '\''s/ -lc$//'\''` -link -dll~linknames='
-      # The linker will automatically build a .lib file if we build a DLL.
-      _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)='true'
-      # FIXME: Should let the user specify the lib program.
-      _LT_AC_TAGVAR(old_archive_cmds, $1)='lib /OUT:$oldlib$oldobjs$old_deplibs'
-      fix_srcfile_path='`cygpath -w "$srcfile"`'
-      _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
-      ;;
+case $host in
+*-*-cygwin* | *-*-mingw* | *-*-pw32* | *-cegcc*)
+  AC_CHECK_TOOL(AS, as, false)
+  AC_CHECK_TOOL(DLLTOOL, dlltool, false)
+  AC_CHECK_TOOL(OBJDUMP, objdump, false)
+  ;;
+esac
 
-    darwin* | rhapsody*)
-    if $CC -v 2>&1 | grep 'Apple' >/dev/null ; then 
-      _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-      case "$host_os" in
-      rhapsody* | darwin1.[[012]])
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)='-undefined suppress'
-	;;
-      *) # Darwin 1.3 on
-	test -z ${LD_TWOLEVEL_NAMESPACE} && _LT_AC_TAGVAR(allow_undefined_flag, $1)='-flat_namespace -undefined suppress'
-	;;
-      esac
-      # FIXME: Relying on posixy $() will cause problems for
-      #        cross-compilation, but unfortunately the echo tests do not
-      #        yet detect zsh echo's removal of \ escapes.  Also zsh mangles
-      #	       `"' quotes if we put them in here... so don't!
-    	lt_int_apple_cc_single_mod=no
-    	output_verbose_link_cmd='echo'
-    	if $CC -dumpspecs 2>&1 | grep 'single_module' >/dev/null ; then
-    	  lt_int_apple_cc_single_mod=yes
-    	fi
-    	if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
-    	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
-    	else
-        _LT_AC_TAGVAR(archive_cmds, $1)='$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
-      fi
-      _LT_AC_TAGVAR(module_cmds, $1)='$CC -bundle ${wl}-bind_at_load $allow_undefined_flag -o $lib $libobjs $deplibs$compiler_flags'
-      # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-        if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
-          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-        else
-          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-        fi
-          _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -bundle $allow_undefined_flag  -o $lib $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=no
-      _LT_AC_TAGVAR(hardcode_automatic, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
-      _LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-all_load $convenience'
-      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-    fi  
-      ;;
+test -z "$AS" && AS=as
+_LT_DECL([], [AS],      [0], [Assembler program])dnl
 
-    dgux*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
+test -z "$DLLTOOL" && DLLTOOL=dlltool
+_LT_DECL([], [DLLTOOL], [0], [DLL creation program])dnl
 
-    freebsd1*)
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
-      ;;
+test -z "$OBJDUMP" && OBJDUMP=objdump
+_LT_DECL([], [OBJDUMP], [0], [Object dumper program])dnl
+])# win32-dll
 
-    # FreeBSD 2.2.[012] allows us to include c++rt0.o to get C++ constructor
-    # support.  Future versions do this automatically, but an explicit c++rt0.o
-    # does not break anything, and helps significantly (at the cost of a little
-    # extra space).
-    freebsd2.2*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags /usr/lib/c++rt0.o'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
+AU_DEFUN([AC_LIBTOOL_WIN32_DLL],
+[AC_REQUIRE([AC_CANONICAL_HOST])dnl
+_LT_SET_OPTION([LT_INIT], [win32-dll])
+AC_DIAGNOSE([obsolete],
+[$0: Remove this warning and the call to _LT_SET_OPTION when you
+put the `win32-dll' option into LT_INIT's first parameter.])
+])
 
-    # Unfortunately, older versions of FreeBSD 2 do not have this feature.
-    freebsd2*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_WIN32_DLL], [])
 
-    # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
-    freebsd*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+
+# _LT_ENABLE_SHARED([DEFAULT])
+# ----------------------------
+# implement the --enable-shared flag, and supports the `shared' and
+# `disable-shared' LT_INIT options.
+# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
+m4_define([_LT_ENABLE_SHARED],
+[m4_define([_LT_ENABLE_SHARED_DEFAULT], [m4_if($1, no, no, yes)])dnl
+AC_ARG_ENABLE([shared],
+    [AS_HELP_STRING([--enable-shared@<:@=PKGS@:>@],
+	[build shared libraries @<:@default=]_LT_ENABLE_SHARED_DEFAULT[@:>@])],
+    [p=${PACKAGE-default}
+    case $enableval in
+    yes) enable_shared=yes ;;
+    no) enable_shared=no ;;
+    *)
+      enable_shared=no
+      # Look at the argument we got.  We use all the common list separators.
+      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
+      for pkg in $enableval; do
+	IFS="$lt_save_ifs"
+	if test "X$pkg" = "X$p"; then
+	  enable_shared=yes
+	fi
+      done
+      IFS="$lt_save_ifs"
       ;;
+    esac],
+    [enable_shared=]_LT_ENABLE_SHARED_DEFAULT)
 
-    hpux9*)
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$CC -shared -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $libobjs $deplibs $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$LD -b +b $install_libdir -o $output_objdir/$soname $libobjs $deplibs $linker_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+    _LT_DECL([build_libtool_libs], [enable_shared], [0],
+	[Whether or not to build shared libraries])
+])# _LT_ENABLE_SHARED
 
-      # hardcode_minus_L: Not really in the search PATH,
-      # but as the default location of the library.
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
-      ;;
+LT_OPTION_DEFINE([LT_INIT], [shared], [_LT_ENABLE_SHARED([yes])])
+LT_OPTION_DEFINE([LT_INIT], [disable-shared], [_LT_ENABLE_SHARED([no])])
 
-    hpux10* | hpux11*)
-      if test "$GCC" = yes -a "$with_gnu_ld" = no; then
-	case "$host_cpu" in
-	hppa*64*|ia64*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
-	  ;;
-	*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
-	  ;;
-	esac
-      else
-	case "$host_cpu" in
-	hppa*64*|ia64*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname -o $lib $libobjs $deplibs $linker_flags'
-	  ;;
-	*)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'
-	  ;;
-	esac
-      fi
-      if test "$with_gnu_ld" = no; then
-	case "$host_cpu" in
-	hppa*64*)
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='+b $libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
-	  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-	  ;;
-	ia64*)
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
-	  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+# Old names:
+AC_DEFUN([AC_ENABLE_SHARED],
+[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[shared])
+])
+
+AC_DEFUN([AC_DISABLE_SHARED],
+[_LT_SET_OPTION([LT_INIT], [disable-shared])
+])
 
-	  # hardcode_minus_L: Not really in the search PATH,
-	  # but as the default location of the library.
-	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-	  ;;
-	*)
-	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
-	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-	  _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+AU_DEFUN([AM_ENABLE_SHARED], [AC_ENABLE_SHARED($@)])
+AU_DEFUN([AM_DISABLE_SHARED], [AC_DISABLE_SHARED($@)])
 
-	  # hardcode_minus_L: Not really in the search PATH,
-	  # but as the default location of the library.
-	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-	  ;;
-	esac
-      fi
-      ;;
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AM_ENABLE_SHARED], [])
+dnl AC_DEFUN([AM_DISABLE_SHARED], [])
 
-    irix5* | irix6* | nonstopux*)
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared $libobjs $deplibs $linker_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='-rpath $libdir'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-      ;;
 
-    netbsd*)
-      if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
 
-    newsos6)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+# _LT_ENABLE_STATIC([DEFAULT])
+# ----------------------------
+# implement the --enable-static flag, and support the `static' and
+# `disable-static' LT_INIT options.
+# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
+m4_define([_LT_ENABLE_STATIC],
+[m4_define([_LT_ENABLE_STATIC_DEFAULT], [m4_if($1, no, no, yes)])dnl
+AC_ARG_ENABLE([static],
+    [AS_HELP_STRING([--enable-static@<:@=PKGS@:>@],
+	[build static libraries @<:@default=]_LT_ENABLE_STATIC_DEFAULT[@:>@])],
+    [p=${PACKAGE-default}
+    case $enableval in
+    yes) enable_static=yes ;;
+    no) enable_static=no ;;
+    *)
+     enable_static=no
+      # Look at the argument we got.  We use all the common list separators.
+      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
+      for pkg in $enableval; do
+	IFS="$lt_save_ifs"
+	if test "X$pkg" = "X$p"; then
+	  enable_static=yes
+	fi
+      done
+      IFS="$lt_save_ifs"
       ;;
+    esac],
+    [enable_static=]_LT_ENABLE_STATIC_DEFAULT)
 
-    openbsd*)
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
-	_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
-      else
-       case $host_os in
-	 openbsd[[01]].* | openbsd2.[[0-7]] | openbsd2.[[0-7]].*)
-	   _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
-	   _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-	   ;;
-	 *)
-	   _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
-	   _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
-	   ;;
-       esac
-      fi
-      ;;
+    _LT_DECL([build_old_libs], [enable_static], [0],
+	[Whether or not to build static libraries])
+])# _LT_ENABLE_STATIC
 
-    os2*)
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
-      _LT_AC_TAGVAR(archive_cmds, $1)='$echo "LIBRARY $libname INITINSTANCE" > $output_objdir/$libname.def~$echo "DESCRIPTION \"$libname\"" >> $output_objdir/$libname.def~$echo DATA >> $output_objdir/$libname.def~$echo " SINGLE NONSHARED" >> $output_objdir/$libname.def~$echo EXPORTS >> $output_objdir/$libname.def~emxexp $libobjs >> $output_objdir/$libname.def~$CC -Zdll -Zcrtdll -o $lib $libobjs $deplibs $compiler_flags $output_objdir/$libname.def'
-      _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)='emximp -o $output_objdir/$libname.a $output_objdir/$libname.def'
-      ;;
+LT_OPTION_DEFINE([LT_INIT], [static], [_LT_ENABLE_STATIC([yes])])
+LT_OPTION_DEFINE([LT_INIT], [disable-static], [_LT_ENABLE_STATIC([no])])
 
-    osf3*)
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
-      else
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared${allow_undefined_flag} $libobjs $deplibs $linker_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-      ;;
+# Old names:
+AC_DEFUN([AC_ENABLE_STATIC],
+[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[static])
+])
 
-    osf4* | osf5*)	# as osf3* with the addition of -msym flag
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
-      else
-	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared${allow_undefined_flag} $libobjs $deplibs $linker_flags -msym -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done; echo "-hidden">> $lib.exp~
-	$LD -shared${allow_undefined_flag} -input $lib.exp $linker_flags $libobjs $deplibs -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${objdir}/so_locations -o $lib~$rm $lib.exp'
+AC_DEFUN([AC_DISABLE_STATIC],
+[_LT_SET_OPTION([LT_INIT], [disable-static])
+])
 
-	# Both c and cxx compiler support -rpath directly
-	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
-      ;;
+AU_DEFUN([AM_ENABLE_STATIC], [AC_ENABLE_STATIC($@)])
+AU_DEFUN([AM_DISABLE_STATIC], [AC_DISABLE_STATIC($@)])
 
-    sco3.2v5*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
-      runpath_var=LD_RUN_PATH
-      hardcode_runpath_var=yes
-      ;;
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AM_ENABLE_STATIC], [])
+dnl AC_DEFUN([AM_DISABLE_STATIC], [])
 
-    solaris*)
-      _LT_AC_TAGVAR(no_undefined_flag, $1)=' -z text'
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-	  $CC -shared ${wl}-M ${wl}$lib.exp ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags~$rm $lib.exp'
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
-	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-  	$LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$rm $lib.exp'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      case $host_os in
-      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
-      *) # Supported since Solaris 2.6 (maybe 2.5.1?)
-	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract' ;;
-      esac
-      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
-      ;;
 
-    sunos4*)
-      if test "x$host_vendor" = xsequent; then
-	# Use $CC to link under sequent, because it throws in some extra .o
-	# files that make .init and .fini sections work.
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h $soname -o $lib $libobjs $deplibs $compiler_flags'
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bstatic -o $lib $libobjs $deplibs $linker_flags'
-      fi
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
 
-    sysv4)
-      case $host_vendor in
-	sni)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes # is this really true???
-	;;
-	siemens)
-	  ## LD is ld it makes a PLAMLIB
-	  ## CC just makes a GrossModule.
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
-	  _LT_AC_TAGVAR(reload_cmds, $1)='$CC -r -o $output$reload_objs'
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
-        ;;
-	motorola)
-	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-	  _LT_AC_TAGVAR(hardcode_direct, $1)=no #Motorola manual says yes, but my tests say they lie
-	;;
-      esac
-      runpath_var='LD_RUN_PATH'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+# _LT_ENABLE_FAST_INSTALL([DEFAULT])
+# ----------------------------------
+# implement the --enable-fast-install flag, and support the `fast-install'
+# and `disable-fast-install' LT_INIT options.
+# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
+m4_define([_LT_ENABLE_FAST_INSTALL],
+[m4_define([_LT_ENABLE_FAST_INSTALL_DEFAULT], [m4_if($1, no, no, yes)])dnl
+AC_ARG_ENABLE([fast-install],
+    [AS_HELP_STRING([--enable-fast-install@<:@=PKGS@:>@],
+    [optimize for fast installation @<:@default=]_LT_ENABLE_FAST_INSTALL_DEFAULT[@:>@])],
+    [p=${PACKAGE-default}
+    case $enableval in
+    yes) enable_fast_install=yes ;;
+    no) enable_fast_install=no ;;
+    *)
+      enable_fast_install=no
+      # Look at the argument we got.  We use all the common list separators.
+      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
+      for pkg in $enableval; do
+	IFS="$lt_save_ifs"
+	if test "X$pkg" = "X$p"; then
+	  enable_fast_install=yes
+	fi
+      done
+      IFS="$lt_save_ifs"
       ;;
+    esac],
+    [enable_fast_install=]_LT_ENABLE_FAST_INSTALL_DEFAULT)
 
-    sysv4.3*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='-Bexport'
-      ;;
+_LT_DECL([fast_install], [enable_fast_install], [0],
+	 [Whether or not to optimize for fast installation])dnl
+])# _LT_ENABLE_FAST_INSTALL
+
+LT_OPTION_DEFINE([LT_INIT], [fast-install], [_LT_ENABLE_FAST_INSTALL([yes])])
+LT_OPTION_DEFINE([LT_INIT], [disable-fast-install], [_LT_ENABLE_FAST_INSTALL([no])])
+
+# Old names:
+AU_DEFUN([AC_ENABLE_FAST_INSTALL],
+[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[fast-install])
+AC_DIAGNOSE([obsolete],
+[$0: Remove this warning and the call to _LT_SET_OPTION when you put
+the `fast-install' option into LT_INIT's first parameter.])
+])
 
-    sysv4*MP*)
-      if test -d /usr/nec; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-	_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-	runpath_var=LD_RUN_PATH
-	hardcode_runpath_var=yes
-	_LT_AC_TAGVAR(ld_shlibs, $1)=yes
-      fi
-      ;;
+AU_DEFUN([AC_DISABLE_FAST_INSTALL],
+[_LT_SET_OPTION([LT_INIT], [disable-fast-install])
+AC_DIAGNOSE([obsolete],
+[$0: Remove this warning and the call to _LT_SET_OPTION when you put
+the `disable-fast-install' option into LT_INIT's first parameter.])
+])
 
-    sysv4.2uw2*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
-      _LT_AC_TAGVAR(hardcode_minus_L, $1)=no
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      hardcode_runpath_var=yes
-      runpath_var=LD_RUN_PATH
-      ;;
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_ENABLE_FAST_INSTALL], [])
+dnl AC_DEFUN([AM_DISABLE_FAST_INSTALL], [])
 
-   sysv5OpenUNIX8* | sysv5UnixWare7* |  sysv5uw[[78]]* | unixware7*)
-      _LT_AC_TAGVAR(no_undefined_flag, $1)='${wl}-z ${wl}text'
-      if test "$GCC" = yes; then
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
-      else
-	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
-      fi
-      runpath_var='LD_RUN_PATH'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
 
-    sysv5*)
-      _LT_AC_TAGVAR(no_undefined_flag, $1)=' -z text'
-      # $CC -shared without GNU ld will not create a library from C++
-      # object files and a static libstdc++, better avoid it by now
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
-  		$LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$rm $lib.exp'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      runpath_var='LD_RUN_PATH'
-      ;;
+# _LT_WITH_PIC([MODE])
+# --------------------
+# implement the --with-pic flag, and support the `pic-only' and `no-pic'
+# LT_INIT options.
+# MODE is either `yes' or `no'.  If omitted, it defaults to `both'.
+m4_define([_LT_WITH_PIC],
+[AC_ARG_WITH([pic],
+    [AS_HELP_STRING([--with-pic],
+	[try to use only PIC/non-PIC objects @<:@default=use both@:>@])],
+    [pic_mode="$withval"],
+    [pic_mode=default])
 
-    uts4*)
-      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
-      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
-      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
-      ;;
+test -z "$pic_mode" && pic_mode=m4_default([$1], [default])
 
-    *)
-      _LT_AC_TAGVAR(ld_shlibs, $1)=no
-      ;;
-    esac
-  fi
+_LT_DECL([], [pic_mode], [0], [What type of objects to build])dnl
+])# _LT_WITH_PIC
+
+LT_OPTION_DEFINE([LT_INIT], [pic-only], [_LT_WITH_PIC([yes])])
+LT_OPTION_DEFINE([LT_INIT], [no-pic], [_LT_WITH_PIC([no])])
+
+# Old name:
+AU_DEFUN([AC_LIBTOOL_PICMODE],
+[_LT_SET_OPTION([LT_INIT], [pic-only])
+AC_DIAGNOSE([obsolete],
+[$0: Remove this warning and the call to _LT_SET_OPTION when you
+put the `pic-only' option into LT_INIT's first parameter.])
 ])
-AC_MSG_RESULT([$_LT_AC_TAGVAR(ld_shlibs, $1)])
-test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
 
-variables_saved_for_relink="PATH $shlibpath_var $runpath_var"
-if test "$GCC" = yes; then
-  variables_saved_for_relink="$variables_saved_for_relink GCC_EXEC_PREFIX COMPILER_PATH LIBRARY_PATH"
-fi
+dnl aclocal-1.4 backwards compatibility:
+dnl AC_DEFUN([AC_LIBTOOL_PICMODE], [])
+
 
+m4_define([_LTDL_MODE], [])
+LT_OPTION_DEFINE([LTDL_INIT], [nonrecursive],
+		 [m4_define([_LTDL_MODE], [nonrecursive])])
+LT_OPTION_DEFINE([LTDL_INIT], [recursive],
+		 [m4_define([_LTDL_MODE], [recursive])])
+LT_OPTION_DEFINE([LTDL_INIT], [subproject],
+		 [m4_define([_LTDL_MODE], [subproject])])
+
+m4_define([_LTDL_TYPE], [])
+LT_OPTION_DEFINE([LTDL_INIT], [installable],
+		 [m4_define([_LTDL_TYPE], [installable])])
+LT_OPTION_DEFINE([LTDL_INIT], [convenience],
+		 [m4_define([_LTDL_TYPE], [convenience])])
+
+# ltsugar.m4 -- libtool m4 base layer.                         -*-Autoconf-*-
 #
-# Do we need to explicitly link libc?
+# Copyright (C) 2004, 2005, 2007, 2008 Free Software Foundation, Inc.
+# Written by Gary V. Vaughan, 2004
 #
-case "x$_LT_AC_TAGVAR(archive_cmds_need_lc, $1)" in
-x|xyes)
-  # Assume -lc should be added
-  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
+# This file is free software; the Free Software Foundation gives
+# unlimited permission to copy and/or distribute it, with or without
+# modifications, as long as this notice is preserved.
 
-  if test "$enable_shared" = yes && test "$GCC" = yes; then
-    case $_LT_AC_TAGVAR(archive_cmds, $1) in
-    *'~'*)
-      # FIXME: we may have to deal with multi-command sequences.
-      ;;
-    '$CC '*)
-      # Test whether the compiler implicitly links with -lc since on some
-      # systems, -lgcc has to come before -lc. If gcc already passes -lc
-      # to ld, don't add -lc before -lgcc.
-      AC_MSG_CHECKING([whether -lc should be explicitly linked in])
-      $rm conftest*
-      printf "$lt_simple_compile_test_code" > conftest.$ac_ext
-  
-      if AC_TRY_EVAL(ac_compile) 2>conftest.err; then
-        soname=conftest
-        lib=conftest
-        libobjs=conftest.$ac_objext
-        deplibs=
-        wl=$_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)
-        compiler_flags=-v
-        linker_flags=-v
-        verstring=
-        output_objdir=.
-        libname=conftest
-        lt_save_allow_undefined_flag=$_LT_AC_TAGVAR(allow_undefined_flag, $1)
-        _LT_AC_TAGVAR(allow_undefined_flag, $1)=
-        if AC_TRY_EVAL(_LT_AC_TAGVAR(archive_cmds, $1) 2\>\&1 \| grep \" -lc \" \>/dev/null 2\>\&1)
-        then
-	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
-        else
-	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
-        fi
-        _LT_AC_TAGVAR(allow_undefined_flag, $1)=$lt_save_allow_undefined_flag
-      else
-        cat conftest.err 1>&5
-      fi
-      $rm conftest*
-      AC_MSG_RESULT([$_LT_AC_TAGVAR(archive_cmds_need_lc, $1)])
-      ;;
-    esac
-  fi
-  ;;
-esac
-])# AC_LIBTOOL_PROG_LD_SHLIBS
+# serial 6 ltsugar.m4
 
+# This is to help aclocal find these macros, as it can't see m4_define.
+AC_DEFUN([LTSUGAR_VERSION], [m4_if([0.1])])
 
-# _LT_AC_FILE_LTDLL_C
-# -------------------
-# Be careful that the start marker always follows a newline.
-AC_DEFUN([_LT_AC_FILE_LTDLL_C], [
-# /* ltdll.c starts here */
-# #define WIN32_LEAN_AND_MEAN
-# #include <windows.h>
-# #undef WIN32_LEAN_AND_MEAN
-# #include <stdio.h>
-#
-# #ifndef __CYGWIN__
-# #  ifdef __CYGWIN32__
-# #    define __CYGWIN__ __CYGWIN32__
-# #  endif
-# #endif
-#
-# #ifdef __cplusplus
-# extern "C" {
-# #endif
-# BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved);
-# #ifdef __cplusplus
-# }
-# #endif
-#
-# #ifdef __CYGWIN__
-# #include <cygwin/cygwin_dll.h>
-# DECLARE_CYGWIN_DLL( DllMain );
-# #endif
-# HINSTANCE __hDllInstance_base;
+
+# lt_join(SEP, ARG1, [ARG2...])
+# -----------------------------
+# Produce ARG1SEPARG2...SEPARGn, omitting [] arguments and their
+# associated separator.
+# Needed until we can rely on m4_join from Autoconf 2.62, since all earlier
+# versions in m4sugar had bugs.
+m4_define([lt_join],
+[m4_if([$#], [1], [],
+       [$#], [2], [[$2]],
+       [m4_if([$2], [], [], [[$2]_])$0([$1], m4_shift(m4_shift($@)))])])
+m4_define([_lt_join],
+[m4_if([$#$2], [2], [],
+       [m4_if([$2], [], [], [[$1$2]])$0([$1], m4_shift(m4_shift($@)))])])
+
+
+# lt_car(LIST)
+# lt_cdr(LIST)
+# ------------
+# Manipulate m4 lists.
+# These macros are necessary as long as will still need to support
+# Autoconf-2.59 which quotes differently.
+m4_define([lt_car], [[$1]])
+m4_define([lt_cdr],
+[m4_if([$#], 0, [m4_fatal([$0: cannot be called without arguments])],
+       [$#], 1, [],
+       [m4_dquote(m4_shift($@))])])
+m4_define([lt_unquote], $1)
+
+
+# lt_append(MACRO-NAME, STRING, [SEPARATOR])
+# ------------------------------------------
+# Redefine MACRO-NAME to hold its former content plus `SEPARATOR'`STRING'.
+# Note that neither SEPARATOR nor STRING are expanded; they are appended
+# to MACRO-NAME as is (leaving the expansion for when MACRO-NAME is invoked).
+# No SEPARATOR is output if MACRO-NAME was previously undefined (different
+# than defined and empty).
 #
-# BOOL APIENTRY
-# DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
-# {
-#   __hDllInstance_base = hInst;
-#   return TRUE;
-# }
-# /* ltdll.c ends here */
-])# _LT_AC_FILE_LTDLL_C
+# This macro is needed until we can rely on Autoconf 2.62, since earlier
+# versions of m4sugar mistakenly expanded SEPARATOR but not STRING.
+m4_define([lt_append],
+[m4_define([$1],
+	   m4_ifdef([$1], [m4_defn([$1])[$3]])[$2])])
 
 
-# _LT_AC_TAGVAR(VARNAME, [TAGNAME])
-# ---------------------------------
-AC_DEFUN([_LT_AC_TAGVAR], [ifelse([$2], [], [$1], [$1_$2])])
 
+# lt_combine(SEP, PREFIX-LIST, INFIX, SUFFIX1, [SUFFIX2...])
+# ----------------------------------------------------------
+# Produce a SEP delimited list of all paired combinations of elements of
+# PREFIX-LIST with SUFFIX1 through SUFFIXn.  Each element of the list
+# has the form PREFIXmINFIXSUFFIXn.
+# Needed until we can rely on m4_combine added in Autoconf 2.62.
+m4_define([lt_combine],
+[m4_if(m4_eval([$# > 3]), [1],
+       [m4_pushdef([_Lt_sep], [m4_define([_Lt_sep], m4_defn([lt_car]))])]]dnl
+[[m4_foreach([_Lt_prefix], [$2],
+	     [m4_foreach([_Lt_suffix],
+		]m4_dquote(m4_dquote(m4_shift(m4_shift(m4_shift($@)))))[,
+	[_Lt_sep([$1])[]m4_defn([_Lt_prefix])[$3]m4_defn([_Lt_suffix])])])])])
+
+
+# lt_if_append_uniq(MACRO-NAME, VARNAME, [SEPARATOR], [UNIQ], [NOT-UNIQ])
+# -----------------------------------------------------------------------
+# Iff MACRO-NAME does not yet contain VARNAME, then append it (delimited
+# by SEPARATOR if supplied) and expand UNIQ, else NOT-UNIQ.
+m4_define([lt_if_append_uniq],
+[m4_ifdef([$1],
+	  [m4_if(m4_index([$3]m4_defn([$1])[$3], [$3$2$3]), [-1],
+		 [lt_append([$1], [$2], [$3])$4],
+		 [$5])],
+	  [lt_append([$1], [$2], [$3])$4])])
 
-# old names
-AC_DEFUN([AM_PROG_LIBTOOL],   [AC_PROG_LIBTOOL])
-AC_DEFUN([AM_ENABLE_SHARED],  [AC_ENABLE_SHARED($@)])
-AC_DEFUN([AM_ENABLE_STATIC],  [AC_ENABLE_STATIC($@)])
-AC_DEFUN([AM_DISABLE_SHARED], [AC_DISABLE_SHARED($@)])
-AC_DEFUN([AM_DISABLE_STATIC], [AC_DISABLE_STATIC($@)])
-AC_DEFUN([AM_PROG_LD],        [AC_PROG_LD])
-AC_DEFUN([AM_PROG_NM],        [AC_PROG_NM])
 
-# This is just to silence aclocal about the macro not being used
-ifelse([AC_DISABLE_FAST_INSTALL])
+# lt_dict_add(DICT, KEY, VALUE)
+# -----------------------------
+m4_define([lt_dict_add],
+[m4_define([$1($2)], [$3])])
 
-AC_DEFUN([LT_AC_PROG_GCJ],
-[AC_CHECK_TOOL(GCJ, gcj, no)
-  test "x${GCJFLAGS+set}" = xset || GCJFLAGS="-g -O2"
-  AC_SUBST(GCJFLAGS)
-])
 
-AC_DEFUN([LT_AC_PROG_RC],
-[AC_CHECK_TOOL(RC, windres, no)
+# lt_dict_add_subkey(DICT, KEY, SUBKEY, VALUE)
+# --------------------------------------------
+m4_define([lt_dict_add_subkey],
+[m4_define([$1($2:$3)], [$4])])
+
+
+# lt_dict_fetch(DICT, KEY, [SUBKEY])
+# ----------------------------------
+m4_define([lt_dict_fetch],
+[m4_ifval([$3],
+	m4_ifdef([$1($2:$3)], [m4_defn([$1($2:$3)])]),
+    m4_ifdef([$1($2)], [m4_defn([$1($2)])]))])
+
+
+# lt_if_dict_fetch(DICT, KEY, [SUBKEY], VALUE, IF-TRUE, [IF-FALSE])
+# -----------------------------------------------------------------
+m4_define([lt_if_dict_fetch],
+[m4_if(lt_dict_fetch([$1], [$2], [$3]), [$4],
+	[$5],
+    [$6])])
+
+
+# lt_dict_filter(DICT, [SUBKEY], VALUE, [SEPARATOR], KEY, [...])
+# --------------------------------------------------------------
+m4_define([lt_dict_filter],
+[m4_if([$5], [], [],
+  [lt_join(m4_quote(m4_default([$4], [[, ]])),
+           lt_unquote(m4_split(m4_normalize(m4_foreach(_Lt_key, lt_car([m4_shiftn(4, $@)]),
+		      [lt_if_dict_fetch([$1], _Lt_key, [$2], [$3], [_Lt_key ])])))))])[]dnl
 ])
 
-# NOTE: This macro has been submitted for inclusion into   #
-#  GNU Autoconf as AC_PROG_SED.  When it is available in   #
-#  a released version of Autoconf we should remove this    #
-#  macro and use it instead.                               #
-# LT_AC_PROG_SED
-# --------------
-# Check for a fully-functional sed program, that truncates
-# as few characters as possible.  Prefer GNU sed if found.
-AC_DEFUN([LT_AC_PROG_SED],
-[AC_MSG_CHECKING([for a sed that does not truncate output])
-AC_CACHE_VAL(lt_cv_path_SED,
-[# Loop through the user's path and test for sed and gsed.
-# Then use that list of sed's as ones to test for truncation.
-as_save_IFS=$IFS; IFS=$PATH_SEPARATOR
-for as_dir in $PATH
-do
-  IFS=$as_save_IFS
-  test -z "$as_dir" && as_dir=.
-  for lt_ac_prog in sed gsed; do
-    for ac_exec_ext in '' $ac_executable_extensions; do
-      if $as_executable_p "$as_dir/$lt_ac_prog$ac_exec_ext"; then
-        lt_ac_sed_list="$lt_ac_sed_list $as_dir/$lt_ac_prog$ac_exec_ext"
-      fi
-    done
-  done
-done
-lt_ac_max=0
-lt_ac_count=0
-# Add /usr/xpg4/bin/sed as it is typically found on Solaris
-# along with /bin/sed that truncates output.
-for lt_ac_sed in $lt_ac_sed_list /usr/xpg4/bin/sed; do
-  test ! -f $lt_ac_sed && break
-  cat /dev/null > conftest.in
-  lt_ac_count=0
-  echo $ECHO_N "0123456789$ECHO_C" >conftest.in
-  # Check for GNU sed and select it if it is found.
-  if "$lt_ac_sed" --version 2>&1 < /dev/null | grep 'GNU' > /dev/null; then
-    lt_cv_path_SED=$lt_ac_sed
-    break
-  fi
-  while true; do
-    cat conftest.in conftest.in >conftest.tmp
-    mv conftest.tmp conftest.in
-    cp conftest.in conftest.nl
-    echo >>conftest.nl
-    $lt_ac_sed -e 's/a$//' < conftest.nl >conftest.out || break
-    cmp -s conftest.out conftest.nl || break
-    # 10000 chars as input seems more than enough
-    test $lt_ac_count -gt 10 && break
-    lt_ac_count=`expr $lt_ac_count + 1`
-    if test $lt_ac_count -gt $lt_ac_max; then
-      lt_ac_max=$lt_ac_count
-      lt_cv_path_SED=$lt_ac_sed
-    fi
-  done
-done
-SED=$lt_cv_path_SED
-])
-AC_MSG_RESULT([$SED])
+# ltversion.m4 -- version numbers			-*- Autoconf -*-
+#
+#   Copyright (C) 2004 Free Software Foundation, Inc.
+#   Written by Scott James Remnant, 2004
+#
+# This file is free software; the Free Software Foundation gives
+# unlimited permission to copy and/or distribute it, with or without
+# modifications, as long as this notice is preserved.
+
+# Generated from ltversion.in.
+
+# serial 3012 ltversion.m4
+# This file is part of GNU Libtool
+
+m4_define([LT_PACKAGE_VERSION], [2.2.6])
+m4_define([LT_PACKAGE_REVISION], [1.3012])
+
+AC_DEFUN([LTVERSION_VERSION],
+[macro_version='2.2.6'
+macro_revision='1.3012'
+_LT_DECL(, macro_version, 0, [Which release of libtool.m4 was used?])
+_LT_DECL(, macro_revision, 0)
 ])
 
+# lt~obsolete.m4 -- aclocal satisfying obsolete definitions.    -*-Autoconf-*-
+#
+#   Copyright (C) 2004, 2005, 2007 Free Software Foundation, Inc.
+#   Written by Scott James Remnant, 2004.
+#
+# This file is free software; the Free Software Foundation gives
+# unlimited permission to copy and/or distribute it, with or without
+# modifications, as long as this notice is preserved.
+
+# serial 4 lt~obsolete.m4
+
+# These exist entirely to fool aclocal when bootstrapping libtool.
+#
+# In the past libtool.m4 has provided macros via AC_DEFUN (or AU_DEFUN)
+# which have later been changed to m4_define as they aren't part of the
+# exported API, or moved to Autoconf or Automake where they belong.
+#
+# The trouble is, aclocal is a bit thick.  It'll see the old AC_DEFUN
+# in /usr/share/aclocal/libtool.m4 and remember it, then when it sees us
+# using a macro with the same name in our local m4/libtool.m4 it'll
+# pull the old libtool.m4 in (it doesn't see our shiny new m4_define
+# and doesn't know about Autoconf macros at all.)
+#
+# So we provide this file, which has a silly filename so it's always
+# included after everything else.  This provides aclocal with the
+# AC_DEFUNs it wants, but when m4 processes it, it doesn't do anything
+# because those macros already exist, or will be overwritten later.
+# We use AC_DEFUN over AU_DEFUN for compatibility with aclocal-1.6. 
+#
+# Anytime we withdraw an AC_DEFUN or AU_DEFUN, remember to add it here.
+# Yes, that means every name once taken will need to remain here until
+# we give up compatibility with versions before 1.7, at which point
+# we need to keep only those names which we still refer to.
+
+# This is to help aclocal find these macros, as it can't see m4_define.
+AC_DEFUN([LTOBSOLETE_VERSION], [m4_if([1])])
+
+m4_ifndef([AC_LIBTOOL_LINKER_OPTION],	[AC_DEFUN([AC_LIBTOOL_LINKER_OPTION])])
+m4_ifndef([AC_PROG_EGREP],		[AC_DEFUN([AC_PROG_EGREP])])
+m4_ifndef([_LT_AC_PROG_ECHO_BACKSLASH],	[AC_DEFUN([_LT_AC_PROG_ECHO_BACKSLASH])])
+m4_ifndef([_LT_AC_SHELL_INIT],		[AC_DEFUN([_LT_AC_SHELL_INIT])])
+m4_ifndef([_LT_AC_SYS_LIBPATH_AIX],	[AC_DEFUN([_LT_AC_SYS_LIBPATH_AIX])])
+m4_ifndef([_LT_PROG_LTMAIN],		[AC_DEFUN([_LT_PROG_LTMAIN])])
+m4_ifndef([_LT_AC_TAGVAR],		[AC_DEFUN([_LT_AC_TAGVAR])])
+m4_ifndef([AC_LTDL_ENABLE_INSTALL],	[AC_DEFUN([AC_LTDL_ENABLE_INSTALL])])
+m4_ifndef([AC_LTDL_PREOPEN],		[AC_DEFUN([AC_LTDL_PREOPEN])])
+m4_ifndef([_LT_AC_SYS_COMPILER],	[AC_DEFUN([_LT_AC_SYS_COMPILER])])
+m4_ifndef([_LT_AC_LOCK],		[AC_DEFUN([_LT_AC_LOCK])])
+m4_ifndef([AC_LIBTOOL_SYS_OLD_ARCHIVE],	[AC_DEFUN([AC_LIBTOOL_SYS_OLD_ARCHIVE])])
+m4_ifndef([_LT_AC_TRY_DLOPEN_SELF],	[AC_DEFUN([_LT_AC_TRY_DLOPEN_SELF])])
+m4_ifndef([AC_LIBTOOL_PROG_CC_C_O],	[AC_DEFUN([AC_LIBTOOL_PROG_CC_C_O])])
+m4_ifndef([AC_LIBTOOL_SYS_HARD_LINK_LOCKS], [AC_DEFUN([AC_LIBTOOL_SYS_HARD_LINK_LOCKS])])
+m4_ifndef([AC_LIBTOOL_OBJDIR],		[AC_DEFUN([AC_LIBTOOL_OBJDIR])])
+m4_ifndef([AC_LTDL_OBJDIR],		[AC_DEFUN([AC_LTDL_OBJDIR])])
+m4_ifndef([AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH], [AC_DEFUN([AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH])])
+m4_ifndef([AC_LIBTOOL_SYS_LIB_STRIP],	[AC_DEFUN([AC_LIBTOOL_SYS_LIB_STRIP])])
+m4_ifndef([AC_PATH_MAGIC],		[AC_DEFUN([AC_PATH_MAGIC])])
+m4_ifndef([AC_PROG_LD_GNU],		[AC_DEFUN([AC_PROG_LD_GNU])])
+m4_ifndef([AC_PROG_LD_RELOAD_FLAG],	[AC_DEFUN([AC_PROG_LD_RELOAD_FLAG])])
+m4_ifndef([AC_DEPLIBS_CHECK_METHOD],	[AC_DEFUN([AC_DEPLIBS_CHECK_METHOD])])
+m4_ifndef([AC_LIBTOOL_PROG_COMPILER_NO_RTTI], [AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_NO_RTTI])])
+m4_ifndef([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE], [AC_DEFUN([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE])])
+m4_ifndef([AC_LIBTOOL_PROG_COMPILER_PIC], [AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_PIC])])
+m4_ifndef([AC_LIBTOOL_PROG_LD_SHLIBS],	[AC_DEFUN([AC_LIBTOOL_PROG_LD_SHLIBS])])
+m4_ifndef([AC_LIBTOOL_POSTDEP_PREDEP],	[AC_DEFUN([AC_LIBTOOL_POSTDEP_PREDEP])])
+m4_ifndef([LT_AC_PROG_EGREP],		[AC_DEFUN([LT_AC_PROG_EGREP])])
+m4_ifndef([LT_AC_PROG_SED],		[AC_DEFUN([LT_AC_PROG_SED])])
+m4_ifndef([_LT_CC_BASENAME],		[AC_DEFUN([_LT_CC_BASENAME])])
+m4_ifndef([_LT_COMPILER_BOILERPLATE],	[AC_DEFUN([_LT_COMPILER_BOILERPLATE])])
+m4_ifndef([_LT_LINKER_BOILERPLATE],	[AC_DEFUN([_LT_LINKER_BOILERPLATE])])
+m4_ifndef([_AC_PROG_LIBTOOL],		[AC_DEFUN([_AC_PROG_LIBTOOL])])
+m4_ifndef([AC_LIBTOOL_SETUP],		[AC_DEFUN([AC_LIBTOOL_SETUP])])
+m4_ifndef([_LT_AC_CHECK_DLFCN],		[AC_DEFUN([_LT_AC_CHECK_DLFCN])])
+m4_ifndef([AC_LIBTOOL_SYS_DYNAMIC_LINKER],	[AC_DEFUN([AC_LIBTOOL_SYS_DYNAMIC_LINKER])])
+m4_ifndef([_LT_AC_TAGCONFIG],		[AC_DEFUN([_LT_AC_TAGCONFIG])])
+m4_ifndef([AC_DISABLE_FAST_INSTALL],	[AC_DEFUN([AC_DISABLE_FAST_INSTALL])])
+m4_ifndef([_LT_AC_LANG_CXX],		[AC_DEFUN([_LT_AC_LANG_CXX])])
+m4_ifndef([_LT_AC_LANG_F77],		[AC_DEFUN([_LT_AC_LANG_F77])])
+m4_ifndef([_LT_AC_LANG_GCJ],		[AC_DEFUN([_LT_AC_LANG_GCJ])])
+m4_ifndef([AC_LIBTOOL_RC],		[AC_DEFUN([AC_LIBTOOL_RC])])
+m4_ifndef([AC_LIBTOOL_LANG_C_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_C_CONFIG])])
+m4_ifndef([_LT_AC_LANG_C_CONFIG],	[AC_DEFUN([_LT_AC_LANG_C_CONFIG])])
+m4_ifndef([AC_LIBTOOL_LANG_CXX_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG])])
+m4_ifndef([_LT_AC_LANG_CXX_CONFIG],	[AC_DEFUN([_LT_AC_LANG_CXX_CONFIG])])
+m4_ifndef([AC_LIBTOOL_LANG_F77_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_F77_CONFIG])])
+m4_ifndef([_LT_AC_LANG_F77_CONFIG],	[AC_DEFUN([_LT_AC_LANG_F77_CONFIG])])
+m4_ifndef([AC_LIBTOOL_LANG_GCJ_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_GCJ_CONFIG])])
+m4_ifndef([_LT_AC_LANG_GCJ_CONFIG],	[AC_DEFUN([_LT_AC_LANG_GCJ_CONFIG])])
+m4_ifndef([AC_LIBTOOL_LANG_RC_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_RC_CONFIG])])
+m4_ifndef([_LT_AC_LANG_RC_CONFIG],	[AC_DEFUN([_LT_AC_LANG_RC_CONFIG])])
+m4_ifndef([AC_LIBTOOL_CONFIG],		[AC_DEFUN([AC_LIBTOOL_CONFIG])])
+m4_ifndef([_LT_AC_FILE_LTDLL_C],	[AC_DEFUN([_LT_AC_FILE_LTDLL_C])])
+
