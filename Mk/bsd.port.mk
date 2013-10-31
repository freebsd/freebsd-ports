#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#
#	bsd.port.mk - 940820 Jordan K. Hubbard.
#	This file is in the public domain.
#
# Please view me with 4 column tabs!

# This is the master file for the most common elements to all port
# Makefile in the ports system.  For a more general overview of its
# use and importance, see the Porter's Handbook.

# There are two different types of "maintainers" in the ports framework.
# The maintainer alias of the bsd.port.mk file is listed below in the
# FreeBSD_MAINTAINER entry.  You should consult them if you have any
# questions/suggestions regarding this file.
#
# DO NOT COMMIT CHANGES TO THIS FILE BY YOURSELF, EVEN IF YOU DID NOT GET
# A RESPONSE FROM THE MAINTAINER(S) WITHIN A REASONABLE TIMEFRAME! ALL
# UNAUTHORISED CHANGES WILL BE UNCONDITIONALLY REVERTED!

FreeBSD_MAINTAINER=	portmgr@FreeBSD.org

# For each port, the MAINTAINER variable is what you should consult for
# contact information on the person(s) to contact if you have questions/
# suggestions about that specific port.  By default (if no MAINTAINER
# is listed), a port is maintained by the subscribers of the ports@FreeBSD.org
# mailing list, and any correspondence should be directed there.
#
# MAINTAINER	- The e-mail address of the contact person for this port.
#				  Default: ports@FreeBSD.org
#
# These are meta-variables that are automatically set to the system
# you are running on.  These are provided in case you need to take
# different actions for different values.
#
# ARCH			- The architecture of the target machine, such as would be
#				  returned by "uname -p".
# OPSYS			- Portability clause.  This is the operating system the
#				  makefile is being used on.  Automatically set to
#				  "FreeBSD," "NetBSD," or "OpenBSD" as appropriate.
# OSREL			- The release version (numeric) of the operating system.
# OSVERSION		- The value of __FreeBSD_version.
#
# This is the beginning of the list of all variables that need to be
# defined in a port, listed in order that they should be included
# to fit in with existing conventions.  (Exception: MAINTAINER actually
# should appear after EXTRACT_ONLY and before MASTER_SITE_BACKUP).
#
# These variables are used to identify your port.
#
# PORTNAME		- Name of software.  Mandatory.
# PORTVERSION	- Version of software.  Mandatory when no DISTVERSION is given.
# PORTREVISION	- Version of port.  Optional.  Commonly used to indicate
#				  that an update has happened that affects the port
#				  framework itself, but not the distributed software
#				  (e.g., local patches or Makefile changes).
# PORTEPOCH		- Optional.  In certain odd cases, the PORTREVISION logic
#				  can be fooled by ports that appear to go backwards
#				  numerically (e.g. if port-0.3 is newer than port-1998).
#				  In this case, incrementing PORTEPOCH forces the revision.
#				  Default: 0 (no effect).
# PKGNAME		- Always defined as
#				  ${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.
#				  Do not define this in your Makefile.
# PKGNAMEPREFIX	- Prefix to specify that port is language-specific, etc.
#				  Optional.
# PKGNAMESUFFIX	- Suffix to specify compilation options.  Optional.
# PKGVERSION		- Always defined as
#				  ${PORTVERSION}.
#				  Do not define this in your Makefile.
# UNIQUENAME	- A name for your port that is globally unique.  By default,
#				  this is set to ${LATEST_LINK} when LATEST_LINK is set,
#				  and to ${PKGNAMEPREFIX}${PORTNAME} otherwise.
# DISTVERSION	- Vendor version of the distribution.
#				  Default: ${PORTVERSION}
# DISTNAME		- Name of port or distribution used in generating
#				  WRKSRC and DISTFILES below.
#				  Default:
#				  ${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
# CATEGORIES	- A list of descriptive categories into which this port falls.
#				  Mandatory.
#
# These variable describe how to fetch files required for building the port.
#
# DISTFILES		- Name(s) of archive file(s) containing distribution.
#				  Set this to an empty string if the port doesn't require it.
#				  Default: ${DISTNAME}${EXTRACT_SUFX}
# EXTRACT_SUFX	- Suffix for archive names
#				  You never have to set both DISTFILES and EXTRACT_SUFX.
#				  Default: .tar.bz2 if USE_BZIP2 is set, .lzh if USE_LHA is set,
#				  .zip if USE_ZIP is set, .tar.xz if USE_XZ is set, .run if
#				  USE_MAKESELF is set, .tar.gz otherwise).
# MASTER_SITES	- Primary location(s) for distribution files if not found
#				  locally.  See bsd.sites.mk for common choices for
#				  MASTER_SITES.
# MASTER_SITE_SUBDIR
#				- Subdirectory of MASTER_SITES. Will sometimes need to be
#				  set to ${PORTNAME} for (e.g.) MASTER_SITE_SOURCEFORGE.
#				  Only guaranteed to work for choices of ${MASTER_SITES}
#				  defined in bsd.sites.mk.
#				  Default: not set.
# PATCHFILES	- Name(s) of additional files that contain distribution
#				  patches. Make will look for them at PATCH_SITES (see below).
#				  They will automatically be uncompressed before patching if
#				  the names end with ".gz", ".bz2" or ".Z".
#				  For each file you can optionally specify a strip
#				  flag of patch(1) after a colon if it has a different
#				  base directory, e.g. "file1 file2:-p1 file3".
#				  You can also use a :group at the end for matching up to
#				  dist file groups. See Porters Handbook for more information.
#				  Syntax: PATCHFILES= patch[:-pX][:group]
#				  Default: not set.
# PATCH_SITES	- Primary location(s) for distribution patch files
#				  if not found locally.
# DIST_SUBDIR	- Suffix to ${DISTDIR}.  If set, all ${DISTFILES} and
#				  ${PATCHFILES} will be put in this subdirectory of
#				  ${DISTDIR} (see below).  Also they will be fetched in this
#				  subdirectory from FreeBSD mirror sites.
# ALLFILES		- All of ${DISTFILES} and ${PATCHFILES}.
# IGNOREFILES	- If set, don't perform checksum checks on these files.
# NOFETCHFILES	- If set, don't download these files from the ${MASTER_SITES}
#				  or ${MASTER_SITE_BACKUP} (but do from
#				  ${MASTER_SITE_OVERRIDE})
# EXTRACT_ONLY	- If set, a subset of ${DISTFILES} you want to
#				  actually extract.
# ALWAYS_KEEP_DISTFILES
#				- If set, the package building cluster will save the distfiles
#				  along with the packages. This may be required to comply with
#				  some licenses, e.g. GPL in some cases.
#				  Default: not set.
#
# (NOTE: by convention, the MAINTAINER entry (see above) should go here.)
#
# These variables are typically set in /etc/make.conf to indicate
# the user's preferred location to fetch files from.  You should
# rarely need to set these.
#
# MASTER_SITE_BACKUP
#				- Backup location(s) for distribution files and patch
#				  files if not found locally and ${MASTER_SITES}/${PATCH_SITES}
#				  Default:
#				  ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
# MASTER_SITE_OVERRIDE
#				- If set, override the MASTER_SITES setting with this
#				  value.
# MASTER_SITE_FREEBSD
#				- If set, only use ${MASTER_SITE_BACKUP} for
#				  MASTER_SITES.
# CD_MOUNTPTS	- List of CDROM mountpoints to look for distfiles under.
#				  This variable supercedes CD_MOUNTPT, which is
#				  obsolete.
#
# Set these if your port should not be built under certain circumstances.
# These are string variables; you should set them to the reason why
# they are necessary.
#
# RESTRICTED	- Prevent the distribution of distfiles and packages to
#				  the FTP sites or on CDROM (e.g. forbidden by license
#				  considerations).
# NO_CDROM		- Packages and distfiles may not go on CDROM (e.g. must
#				  not be re-sold) but can go on FTP sites.
# NO_PACKAGE	- Port should not be packaged for ftp sites or CDROMs,
#				  but distfiles can be put on ftp sites and CDROMs.
# FORBIDDEN		- Package build should not be attempted because of
#				  security vulnerabilities.
# IGNORE		- Package build should be skipped entirely (e.g.
#				  because of serious unfixable problems in the build,
#				  because it cannot be manually fetched, etc).  Error
#				  logs will not appear on pointyhat, so this should be
#				  used sparingly.
# BROKEN		- Port is believed to be broken.  Package builds can
# 				  still be attempted using TRYBROKEN to test this
#				  assumption.
# BROKEN_${ARCH}  Port is believed to be broken on ${ARCH}. Package builds
#				  can still be attempted using TRYBROKEN to test this
#				  assumption.
# DEPRECATED	- Port is deprecated to install. Advisory only.
# EXPIRATION_DATE
#				- If DEPRECATED is set, determines a date when
#				  the port is planed to remove. The date format is
#				  ISO 8601 (YYYY-MM-DD).
#
# DISABLE_VULNERABILITIES
#				- If set, do not check if the port is listed in the
#				  vulnerabilities database.
#
# In addition to RESTRICTED or NO_CDROM, if only a subset of distfiles
# or patchfiles have redistribution restrictions, set the following
# to the list of such files.
#
# RESTRICTED_FILES
#				- List of files that cannot be redistributed.
#				  Default: "${DISTFILES} ${PATCHFILES}" if RESTRICTED
#				  or NO_CDROM is set, empty otherwise.
#
# These variables are booleans, so you don't need to set them to the reason.
#
# IS_INTERACTIVE
#				- Set this if your port needs to interact with the user
#				  during any step in a package build.  User can then decide
#				  to skip this port by setting ${BATCH}, or compiling only
#				  the interactive ports by setting ${INTERACTIVE}.
#				  Default: not set.
# USE_SUBMAKE	- Set this if you want that each of the port's main 7 targets
#				  (extract, patch, configure, build, stage, install and
#				  package) to be executed in a separate make(1) process.
#				  Useful when one of the stages needs to influence make(1)
#				  variables of the later stages using ${WRKDIR}/Makefile.inc
#				  generated on the fly.
#				  Default: not set.
#
# Set these if your port only makes sense to certain architectures.
# They are lists containing names for them (e.g., "alpha i386").
# (Defaults: not set.)
#
# ONLY_FOR_ARCHS
#				- Only build ports if ${ARCH} matches one of these.
# NOT_FOR_ARCHS	- Only build ports if ${ARCH} doesn't match one of these.
# ONLY_FOR_ARCHS_REASON
# ONLY_FOR_ARCHS_REASON_${ARCH}
#				- Reason why it's only for ${ONLY_FOR_ARCHS}s
# NOT_FOR_ARCHS_REASON
# NOT_FOR_ARCHS_REASON_${ARCH}
#				- Reason why it's not for ${NOT_FOR_ARCHS}s
# IA32_BINARY_PORT
#				- Set this instead of ONLY_FOR_ARCHS if the given port
#				  fetches and installs compiled i386 binaries.
#
# Dependency checking.  Use these if your port requires another port
# not in the list below.  (Default: empty.)
#
# EXTRACT_DEPENDS
#				- A list of "path:dir[:target]" tuples of other ports this
#				  package depends on in the "extract" stage.  "path" is
#				  the name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the existence
#				  (if it is a full pathname) or search for it in your
#				  $PATH (if it is an executable) and go into "dir" to do
#				  a "make all install" if it's not found.  If the third
#				  field ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.  The first field also supports a
#				  package name with a version range, in the form package>=1.2
#				  if a particular version is desired.
# PATCH_DEPENDS	- A list of "path:dir[:target]" tuples of other ports this
#				  package depends on in the "patch" stage.  "path" is the
#				  name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the existence
#				  (if it is a full pathname) or search for it in your
#				  $PATH (if it is an executable) and go into "dir" to do
#				  a "make all install" if it's not found.  If the third
#				  field ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.  The first field also supports a
#				  package name with a version range, in the form package>=1.2
#				  if a particular version is desired.
# FETCH_DEPENDS	- A list of "path:dir[:target]" tuples of other ports this
#				  package depends in the "fetch" stage.  "path" is the
#				  name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the
#				  existence (if it is a full pathname) or search for
#				  it in your $PATH (if it is an executable) and go
#				  into "dir" to do a "make all install" if it's not
#				  found.  If the third field ("target") exists, it will
#				  be used instead of ${DEPENDS_TARGET}.  The first field
#				  also supports a package name with a version range, in
#				  the form package>=1.2 if a particular version is desired.
# BUILD_DEPENDS	- A list of "path:dir[:target]" tuples of other ports this
#				  package depends to build (between the "extract" and
#				  "build" stages, inclusive).  The test done to
#				  determine the existence of the dependency is the
#				  same as FETCH_DEPENDS.  If the third field ("target")
#				  exists, it will be used instead of ${DEPENDS_TARGET}.
# RUN_DEPENDS	- A list of "path:dir[:target]" tuples of other ports this
#				  package depends to run.  The test done to determine
#				  the existence of the dependency is the same as
#				  FETCH_DEPENDS.  This will be checked during the
#				  "install" stage and the name of the dependency will
#				  be put into the package as well.  If the third field
#				  ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.  The first field also supports a
#				  package name with a version range, in the form package>=1.2
#				  if a particular version is desired.
# LIB_DEPENDS	- A list of "lib:dir[:target]" tuples of other ports this
#				  package depends on.  "lib" is the name of a shared library.
#				  make will use "ldconfig -r" to search for the library.
#				  lib can contain extended regular expressions.
# DEPENDS_TARGET
#				- The default target to execute when a port is calling a
#				  dependency.
#				  Default: install
#
# These variables control options about how a port gets built and/or
# are shorthand notations for common sets of dependencies.
# Use these if your port uses some of the common software packages. By
# convention these should be set to 'yes', although they only need to be
# defined. Defaults: not set, unless explicitly indicated below.
#
# Note: the distinction between the USE_* and WANT_* variables, and the
# WITH_* and WITHOUT_* variables, are that the former are restricted to
# usage inside the ports framework, and the latter are reserved for user-
# settable options.  (Setting USE_* in /etc/make.conf is always wrong).
#
# WITH_DEBUG            - If set, debugging flags are added to CFLAGS and the
#                         binaries don't get stripped by INSTALL_PROGRAM or
#                         INSTALL_LIB. Besides, individual ports might
#                         add their specific to produce binaries for debugging
#                         purposes. You can override the debug flags that are
#                         passed to the compiler by setting DEBUG_FLAGS. It is
#                         set to "-g" at default.
#
# WITH_SSP_PORTS
# 				- If set, SSP_FLAGS (defaults to -fstack-protector)
#				  is added to CFLAGS and the necessary flags
#				  are added to LDFLAGS. Note that SSP_UNSAFE
#				  can be used in Makefiles by port maintainers
#				  if a port breaks with it (it should be
#				  extremely rare).
#
# USE_BZIP2		- If set, this port tarballs use bzip2, not gzip, for
#				  compression.
# USE_LHA		- If set, this port distfile uses lha for compression
# USE_XZ		- If set, this port tarballs use xz (or lzma)
#				  for compression
# USE_ZIP		- If set, this port distfile uses zip, not tar w/[bg]zip
#				  for compression.
# USE_MAKESELF		- If set, this port distfile uses makeself, not tar w/[bg]zip
#				  for compression.
# USE_DOS2UNIX	- If set to "YES", remove the ^M from all files
#				  under ${WRKSRC}. If set to a string, remove in all
#				  files under ${WRKSRC} with one of these names the ^Ms.
# DOS2UNIX_REGEX
#				- Limit the ^M removal to files which name matches
#				  the regular expression.
# USE_GCC		- If set, this port requires this version of gcc, either in
#				  the system or installed from a port.
# USE_CSTD		- Override the default C language standard (gnu89, gnu99)
# USE_CXXSTD	  Override the default C++ language standard
# USE_BINUTILS	- Use binutils suite from port instead of the version in base.
##
# USE_GHOSTSCRIPT
#				- If set, this port needs ghostscript to both
#				  build and run.  If a number is specified,
#				  the specified version will be used.
#				  The valid value is '7', '8', or '9' in that case.
# USE_GHOSTSCRIPT_BUILD
#				- If set, this port needs ghostscript to build.
# USE_GHOSTSCRIPT_RUN
#				- If set, this port needs ghostscript to run.
# GHOSTSCRIPT_PORT
#				- The port that provides postscript functionality.
#				  Some installations may wish to override the default
#				  to specify a version without X11 and/or localized
#				  versions for their nationality.
#				  Default: print/ghostscript9
# WITH_GHOSTSCRIPT_VER
#				- If set, the specified version of ghostscript will be
#				  used.  The valid value is "7", "8", or "9".  Note that
#				  this is for users, not for port maintainers.  This
#				  should not be used in Makefile.
##
# USE_DISPLAY	- If set, this ports requires a (virtual) X11 environment
#				  setup. If the environment variable DISPLAY Is not set,
#				  then an extra build dependency on Xvfb is added. Further,
#				  if PACKAGE_BUILDING is not set, then CONFIGURE_ENV and
#				  MAKE_ENV are extended with a DISPLAY variable.
#
# USE_GL		- A list of Mesa or GL related dependencies needed by the port.
#				  Supported components are: egl, glesv2, glut, glu, glw, and gl.
#				  If set to "yes", this is equivalent to "glu". Note that
#				  glew and glut depend on glu, glw and glu depend on gl.
##
# USE_SDL		- If set, this port uses the sdl libraries.
#				  See bsd.sdl.mk for more information.
##
# USE_OPENAL	- If set, this port relies on the OpenAL package.
#				  Legal values are: al, soft, si, alut.
#				  If set to an unknown value, the port is marked broken.
# WANT_OPENAL	- User-specific OpenAL wishes.
#				  Legal values are: soft, si. The default is soft.
##
# USE_OPENSSL	- If set, this port relies on the OpenSSL package.
##
# USE_OPENLDAP	- If set, this port uses the OpenLDAP libraries.
#				  Implies: WANT_OPENLDAP_VER?=24
# WANT_OPENLDAP_VER
#				- Legal values are: 23, 24
#				  If set to an unknown value, the port is marked BROKEN.
# WANT_OPENLDAP_SASL
#				- If set, the system should use OpenLDAP libraries
#				  with SASL support.
##
# USE_FAM		- If set, this port uses the File Alteration Monitor.
#
# WANT_FAM_SYSTEM
#				- Legal values are: gamin (default),fam
#				  If set to an unknown value, the port is marked IGNORE.
##
# USE_AUTOTOOLS	- If set, this port uses various GNU autotools
#				  (libtool, autoconf, autoheader, automake et al.)
#				  See bsd.autotools.mk for more details.
##
# USE_SCONS		- If set, this port uses the Python-based SCons build system
#				  See bsd.scons.mk for more details.
##
# USE_EFL		- If set, this port use EFL libraries.
#				  Implies inclusion of bsd.efl.mk.  (Also see
#				  that file for more information on USE_EFL_*).
# USE_FPC		- If set, this port relies on the Free Pascal language.
# 				  Implies inclusion of bsd.fpc.mk.  (Also see
#				  that file for more information on WANT_FPC_*).
# USE_JAVA		- If set, this port relies on the Java language.
#				  Implies inclusion of bsd.java.mk.  (Also see
#				  that file for more information on USE_JAVA_*).
# USE_OCAML		- If set, this port relies on the OCaml language.
#				  Implies inclusion of bsd.ocaml.mk.  (Also see
#				  that file for more information on USE_OCAML*).
# USE_PYTHON	- If set, this port relies on the Python language.
#				  Implies inclusion of bsd.python.mk. (Also see
#				  that file for more information on USE_PYTHON_*
#				  and USE_PYDISTUTILS).
# USE_R_MOD	- If set, this port uses the Comprehensive R Archive Network.
#		  See bsd.cran.mk for more details.
# USE_RUBY		- If set, this port relies on the Ruby language.
#				  Implies inclusion of bsd.ruby.mk.  (Also see
#				  that file for more information on USE_RUBY_*).
# USE_GNUSTEP	- If set, this port relies on the GNUstep system.
#				  Implies the inclusion of bsd.gnustep.mk.
#				  (Also see that file for more information on
#				  USE_GNUSTEP_*).
##
# USE_GECKO		- If set, this port uses the Gecko/Mozilla product.
#				  See bsd.gecko.mk for more details.
##
# USE_GNOME		- A list of the Gnome dependencies the port has (e.g.,
#				  glib12, gtk12).  Implies that the port needs Gnome.
#				  Implies inclusion of bsd.gnome.mk.  See bsd.gnome.mk
#				  or http://www.FreeBSD.org/gnome/docs/porting.html
#				  for more details.
##
# USE_LUA		- If set, this port uses the Lua library and related
#				  components. See bsd.lua.mk for more details.
##
# USE_WX		- If set, this port uses the WxWidgets library and related
#				  components. See bsd.wx.mk for more details.
##
# USE_KDE4		- A list of the KDE4 dependencies the port has (e.g.,
#				  kdelibs, kdebase).  Implies that the port needs KDE.
#				  Implies inclusion of bsd.kde4.mk.  See bsd.kde4.mk
#				  for more details.
#
# USE_QT4		- A list of the QT4 dependencies the port has (e.g,
#				  corelib, webkit).  Implies that the port needs Qt.
#				  Implies the inclusion of bsd.qt.mk.  See bsd.qt.mk
#				  for more details.
#
# USE_LINUX		- Set to yes to say the port needs the default linux base port.
#				  Set to value <X>, if the port needs emulators/linux_base-<X>.
#				  Implies appropriate settings for STRIP and STRIP_CMD.
# USE_LINUX_PREFIX
#				- controls the action of PREFIX (see above). Only use this
#				  if the port is a linux infrastructure port (e.g. contains libs
#				  or a sound server which supports the FreeBSD native one),
#				  use the default or the X11 prefix if it's a leaf port
#				  (e.g. a game or program).
#				  Implies NO_MTREE=yes, and, if USE_LDCONFIG is defined:
#				    - USE_LINUX=yes
#				    - appropriate invocation of the Linux ldconfig
# USE_LINUX_RPM	- Set to yes to pull in variables and targets useful to Linux
#				  RPM ports.
#				  Implies inclusion of bsd.linux-rpm.mk.
#
# LINUX_OSRELEASE	- Contains the value of compat.linux.osrelease sysctl.
#				  Will be used to distinguish which linux
#				  infrastructure ports should be used.
#				  Valid values: 2.6.16.
# AUTOMATIC_PLIST
#				- Set to yes to enable automatic packing list generation.
#				  Currently has no effect unless USE_LINUX_RPM is set.
#
# OVERRIDE_LINUX_BASE_PORT
#				- This specifies the default linux base to use, for valid
#				  values have a look at the description of USE_LINUX. This is
#				  an user-only variable. Don't use it in any port, it's meant
#				  to be used in make.conf.
#
# LINUX_BASE_PORT
#				- This is a read-only variable, it gets set to a value which is
#				  usable in *_DEPENDS (e.g. BUILD_DEPENDS=${LINUX_BASE_PORT}).
#				  It honors USE_LINUX=foo and OVERRIDE_LINUX_BASE_PORT.
##
# USE_XORG			- Set to a list of X.org module dependencies.
#				  Implies inclusion of bsd.xorg.mk.
##
# USE_TEX			- A list of the TeX dependencies the port has.
#
##
# USE_RC_SUBR	- If set, the ports startup/shutdown script uses the common
#				  routines found in /etc/rc.subr.
#				  If this is set to a list of files, these files will be
#				  automatically added to ${SUB_FILES}, some %%VAR%%'s will
#				  automatically be expanded, they will be installed in
#				  ${PREFIX}/etc/rc.d and added to the packing list.
# USE_RCORDER	- List of rc.d startup scripts to be called early in the boot
#				  process. This acts exactly like USE_RC_SUBR except that
#				  scripts are installed in /etc/rc.d.
#				  Because local rc.d scripts are included in the base rcorder
#				  this option is not needed unless the port installs in the base.
##
# USE_APACHE	- If set, this port relies on an apache webserver.
#
# Conflict checking.  Use if your port cannot be installed at the same time as
# another package.
#
# CONFLICTS		- A list of package name patterns that the port conflicts
#				  with, separated by blanks.  The names may include shell
#				  pattern meta-characters "*", "?", "[", "]", and "!".
#				  Example: apache*-1.2* apache*-1.3.[012345] apache-*+ssl_*
#
# CONFLICTS_BUILD
#				- Check conflict prior to the build.
#
# CONFLICTS_INSTALL
#				- Check conflict prior to the installation stage.
#
# Various directory definitions and variables to control them.
# You rarely need to redefine any of these except WRKSRC and NO_WRKSUBDIR.
#
# LOCALBASE		- Where non-X11 ports install things.
#				  Default: /usr/local
# LINUXBASE		- Where Linux ports install things.
#				  Default: /compat/linux
# PREFIX		- Where *this* port installs its files.
#				  Default: ${LINUXBASE} if USE_LINUX_PREFIX is set,
#				  otherwise ${LOCALBASE}
#
# IGNORE_PATH_CHECKS
#				- There are some sanity checks against PREFIX.
#				  You can disable these checks with defining
#				  this variable, but this is not recommended!
#				  Only do this if you really know what you are
#				  doing.  These sanity checks are the following:
#				    - PREFIX has to be an absolute path.
#				    - PREFIX can't have a trailing slash.
#
# MASTERDIR		- Where the port finds patches, package files, etc.  Define
#				  this is you have two or more ports that share most of the
#				  files.
#				  Default: ${.CURDIR}
# PORTSDIR		- The root of the ports tree.
#				  Default: /usr/ports
# DISTDIR		- Where to search for and store copies of original sources
#				  Default: ${PORTSDIR}/distfiles
# PACKAGES		- A top level directory where all packages go (rather than
#				  going locally to each port).
#				  Default: ${PORTSDIR}/packages
# WRKDIRPREFIX	- The place to root the temporary working directory
#				  hierarchy.
#				  Default: none
# WRKDIR		- A temporary working directory that gets *clobbered* on clean
#				  Default: ${WRKDIRPREFIX}${.CURDIR}/work
# WRKSRC		- A subdirectory of ${WRKDIR} where the distribution actually
#				  unpacks to.
#				  Default: ${WRKDIR}/${DISTNAME} unless NO_WRKSUBDIR is set,
#				  in which case simply ${WRKDIR}
# WRKSRC_SUBDIR	- A subdirectory of ${WRKSRC} where the distribution actually
#				  builds in.
#				  Default: not set
# NO_WRKSUBDIR	- Assume port unpacks directly into ${WRKDIR}.
# PATCHDIR		- A directory containing any additional patches you made
#				  to port this software to FreeBSD.
#				  Default: ${MASTERDIR}/files
# SCRIPTDIR		- A directory containing any auxiliary scripts
#				  Default: ${MASTERDIR}/scripts
# FILESDIR		- A directory containing any miscellaneous additional files.
#				  Default: ${MASTERDIR}/files
# PKGDIR		- A directory containing any package creation files.
#				  Default: ${MASTERDIR}
# SRC_BASE		- The root of the src tree.  (Some ports require this to get
#				  kernel sources).  Default: /usr/src
# UID_FILES		- A list of files containing information about registered UIDs.
# 				  Note that files have decreasing priority.
# GID_FILES		- A list of files containing information about registered GIDs.
# 				  Note that files have decreasing priority.
#
# Variables that serve as convenient "aliases" for your *-install targets.
# Use these like: "${INSTALL_PROGRAM} ${WRKSRC}/prog ${PREFIX}/bin".
#
# INSTALL_PROGRAM
#				- A command to install binary executables.  (By
#				  default, also strips them, unless ${STRIP} is
#				  overridden to be the empty string).
# INSTALL_KLD	- As INSTALL_PROGRAM, but without the STRIP.
# INSTALL_LIB	- As INSTALL_DATA, but also strips the file.
# INSTALL_SCRIPT
#				- A command to install executable scripts.
# INSTALL_DATA	- A command to install sharable data.
# INSTALL_MAN	- A command to install manpages.  May or not compress,
#				  depending on the value of MANCOMPRESSED (see below).
#
# Boolean to control whether manpages are installed.
#
# NO_INSTALL_MANPAGES
#				- If set, this port doesn't want to install any manpages.
#				  Default: not set, i.e. manpages are installed by default.
#
# Set the following to specify all manpages that your port installs.
# These manpages will be automatically listed in ${PLIST}.  Depending
# on the setting of NO_MANCOMPRESS, the make rules will compress the
# manpages for you.
#
# MAN<sect>		- A list of manpages, categorized by section.  For
#				  example, if your port has "man/man1/foo.1" and
#				  "man/mann/bar.n", set "MAN1=foo.1" and "MANN=bar.n".
#				  The available sections chars are "123456789LN".
# MAN<sect>_<lang>
#				- If your port does not install all man pages for all
#				  languages in MANLANG, language specific pages for
#				  a language can be specified with this. For example,
#				  if the port installs foo.1 in English, Japanese, and
#				  German, bar.1 in English only, and baz.3 in German
#				  only, set
#					MANLANG=	"" de ja
#					MAN1=		foo.1
#					MAN1_EN=	bar.1
#					MAN3_DE=	baz.3
# MLINKS		- A list of <source, target> tuples for creating links
#				  for manpages.  For example, "MLINKS= a.1 b.1 c.3 d.3"
#				  will do an "ln -sf a.1 b.1" and "ln -sf c.3 d.3" in
#				  appropriate directories.  (Use this even if the port
#				  installs its own manpage links so they will show up
#				  correctly in ${PLIST}.)
# MANPREFIX		- The directory prefix for ${MAN<sect>} and ${MLINKS}.
#				  Default: ${PREFIX}
# MAN<sect>PREFIX
#				- If manual pages of some sections install in different
#				  locations than others, use these.
#				  Default: ${MANPREFIX}
# MANCOMPRESSED	- This variable can take values "yes", "no" or
#				  "maybe".  "yes" means manpages are installed
#				  compressed; "no" means they are not; "maybe" means
#				  it changes depending on the value of NO_MANCOMPRESS.
#				  Default: "yes" if USES=imake is set and NO_INSTALL_MANPAGES
#				  is not set, and "no" otherwise.
#
# Set the following to specify all .info files your port installs.
#
# INFO			- A list of .info files (omitting the trailing ".info");
#				  only one entry per document! These files are listed in
#				  the path relative to ${INFO_PATH}.
# INFO_PATH		- Path, where all .info files will be installed by your
#				  port, relative to ${PREFIX}
#				  Default: "share/info" if ${PREFIX} is equal to /usr
#				  and "info" otherwise.
#
# Set the following to specify all documentation your port installs into
# ${DOCSDIR}
#
# PORTDOCS		- A list of files and directories relative to DOCSDIR.
#				  Shell glob patterns can be used, directories include
#				  the entire subtree of contained files and directories.
#				  Should not be set when no documentation files are
#				  installed.
#				  Useful for dynamically generated documentation.
#
# Set the following to specify all documentation your port installs into
# ${EXAMPLESDIR}
#
# PORTEXAMPLES		- A list of files and directories relative to EXAMPLESDIR.
#				  Shell glob patterns can be used, directories include
#				  the entire subtree of contained files and directories.
#				  Should not be set when no examples files are
#				  installed.
#				  Useful for dynamically generated examples.
#
# Set the following to specify all files and directories your port installs into
# ${DATADIR}
#
# PORTDATA		- A list of files and directories relative to DATADIR.
#				  Shell glob patterns can be used, directories include
#				  the entire subtree of contained files and directories.
#				  Should not be set when no data files are
#				  installed.
#				  Useful for dynamically generated data files.
#
# Default targets and their behaviors:
#
# fetch			- Retrieves missing ${DISTFILES} and ${PATCHFILES} for this
#				  port.
# fetch-list	- Show list of commands to retrieve missing ${DISTFILES} and
#				  ${PATCHFILES} for this port.
# fetch-recursive
#				- Retrieves missing ${DISTFILES} and ${PATCHFILES} for this
#				  port and dependencies.
# fetch-recursive-list
#				- Show list of commands to retrieve missing ${DISTFILES} and
#				  ${PATCHFILES} for this port and dependencies.
# fetch-required
#				- Retrieves missing ${DISTFILES} and ${PATCHFILES} for this
#				  port and dependencies.
# fetch-required-list
#				- Show list of commands to retrieve missing ${DISTFILES} and
#				  ${PATCHFILES} for this port and dependencies.
# fetch-url-list
#				- Show list of URLS to retrieve missing ${DISTFILES} and
#				  ${PATCHFILES} for this port.
# fetch-urlall-list
#				- Show list of URLS to retrieve ${DISTFILES} and
#				  ${PATCHFILES} for this port.
#
# all-depends-list
#				- Show all directories which are dependencies
#				  for this port.
# build-depends-list
#				- Show all directories which are build-dependencies
#				  for this port.
# package-depends-list
#				- Show all directories which are package-dependencies
#				  for this port. This is based upon the dependency
#				  tree as recorded in the Makefiles of the ports
#				  collection, not as recorded in the currently
#				  installed ports.
# actual-package-depends
#				- Like package-depends-list but with the difference
#				  that the dependencies of the currently installed
#				  ports are used instead of the dependencies as
#				  recorded in the ports collection.
# run-depends-list
#				- Show all directories which are run-dependencies
#				  for this port.
#
# extract		- Unpacks ${DISTFILES} into ${WRKDIR}.
# patch			- Apply any provided patches to the source.
# configure		- Runs either GNU configure, one or more local configure
#				  scripts or nothing, depending on what's available.
# build			- Actually compile the sources.
# install		- Install the results of a build.
# reinstall		- Install the results of a build, ignoring "already installed"
#				  flag.
# deinstall		- Remove the installation.
# deinstall-all	- Remove all installations with the same PKGORIGIN.
# package		- Create a package from an _installed_ port.
# package-recursive
#				- Create a package for a port and _all_ of its dependencies.
# describe		- Try to generate a one-line description for each port for
#				  use in INDEX files and the like.
# checkpatch	- Do a "patch -C" instead of a "patch".  Note that it may
#				  give incorrect results if multiple patches deal with
#				  the same file.
# checksum		- Use distinfo to ensure that your distfiles are valid.
# checksum-recursive
#				- Run checksum in this port and all dependencies.
# makesum		- Generate distinfo (only do this for your own ports!).
# clean			- Remove ${WRKDIR} and other temporary files used for building.
# clean-depends	- Do a "make clean" for all dependencies.
# config		- Configure options for this port (using ${DIALOG}).
#				  Automatically run prior to extract, patch, configure, build,
#				  install, and package.
# config-recursive
#				- Configure options for this port for a port and all its
#				  dependencies.
# showconfig	- Display options config for this port.
# showconfig-recursive
#				- Display options config for this port and all its
#				  dependencies.
# rmconfig		- Remove the options config for this port.
# rmconfig-recursive
#				- Remove the options config for this port and all its
#				  dependencies.
#
# Default sequence for "all" is:
#
#		check-sanity fetch checksum extract patch configure build
#
# Please read the comments in the targets section below; you
# should be able to use the pre-* or post-* targets/scripts
# (which are available for every stage except checksum) or
# override the do-* targets to do pretty much anything you want.
#
# NEVER override the "regular" targets unless you want to open
# a major can of worms.
#
# Set these variables if your port doesn't need some of the steps.
# Note that there are no NO_PATCH or NO_CONFIGURE variables because
# those steps are empty by default.  NO_EXTRACT is not allowed anymore
# since we need to at least create ${WRKDIR}.  Also, NO_CHECKSUM is a user
# variable and is not to be set in a port's Makefile.  See above for NO_PACKAGE.
#
# NO_BUILD		- Use a dummy (do-nothing) build target.
# NO_INSTALL	- Use a dummy (do-nothing) install target.
#
# Here are some variables used in various stages.
#
# For options see bsd.options.mk
#
# For fetch:
#
# FETCH_BINARY	- Path to ftp/http fetch command if not in $PATH.
#				  Default: "/usr/bin/fetch"
# FETCH_ARGS	- Arguments to ftp/http fetch command.
#				  Default: "-AFpr"
# FETCH_CMD		- ftp/http fetch command.
#				  Default: ${FETCH_BINARY} ${FETCH_ARGS}
# FETCH_BEFORE_ARGS
#				- Arguments to ${FETCH_CMD} before filename.
#				  Default: none
# FETCH_AFTER_ARGS
#				- Arguments to ${FETCH_CMD} following filename.
#				  Default: none
# FETCH_ENV		- Environment to pass to ${FETCH_CMD}.
#				  Default: none
# FETCH_REGET	- Times to retry fetching of files on checksum errors.
#				  Default: 1
# CLEAN_FETCH_ENV		
#				- Disable package dependency in fetch target for mass
#				  fetching.  User settable.
#
# For extract:
#
# EXTRACT_CMD	- Command for extracting archive: "bzip2" if USE_BZIP2
#				  is set, "unzip" if USE_ZIP is set, "unmakeself" if
#				  USE_MAKESELF if set, "gzip" otherwise.
# EXTRACT_BEFORE_ARGS
#				- Arguments to ${EXTRACT_CMD} before filename.
#				  Default: "-dc"
# EXTRACT_AFTER_ARGS
#				- Arguments to ${EXTRACT_CMD} following filename.
#				  default: "| tar -xf -"
# EXTRACT_PRESERVE_OWNERSHIP
#				- Normally, when run as "root", the extract stage will
#				  change the owner and group of all files under ${WRKDIR}
#				  to 0:0.  Set this variable if you want to turn off this
#				  feature.
# For patch:
#
# EXTRA_PATCHES	- Define this variable if you have patches not in
#				  ${PATCHDIR}.  This usually happens when you need to
#				  do some pre-processing before some distribution
#				  patches can be applied.  In that case, fetch them as
#				  extra distfiles, put the processed results in
#				  ${WRKDIR}, then point EXTRA_PATCHES to them.
#				  The patches specified by this variable will be
#				  applied after the normal distribution patches but
#				  before those in ${PATCHDIR}.
# PATCH_WRKSRC	- Directory to apply patches in.
#				  Default: ${WRKSRC}
#
# For configure:
#
# HAS_CONFIGURE	- If set, this port has its own configure script.  The
#				  configure stage will not do anything if this is not set.
# GNU_CONFIGURE	- If set, you are using GNU configure (optional).  Implies
#				  HAS_CONFIGURE.
# CONFIGURE_WRKSRC
#				- Directory to run configure in.
#				  Default: ${WRKSRC}
# CONFIGURE_SCRIPT
#				- Name of configure script, relative to ${CONFIGURE_WRKSRC}.
#				  Default: "Makefile.PL" if PERL_CONFIGURE is set,
#				  "configure" otherwise.
# CONFIGURE_TARGET
#				- The name of target to call when GNU_CONFIGURE is
#				  defined.
#				  Default: ${ARCH}-portbld-freebsd${OSREL}
# GNU_CONFIGURE_PREFIX
#				- The directory passed as prefix to the configure script if
#				  GNU_CONFIGURE is set.
#				  Default: ${PREFIX}
# CONFIGURE_ARGS
#				- Pass these args to configure if ${HAS_CONFIGURE} is set.
#				  Default: "--prefix=${GNU_CONFIGURE_PREFIX} --infodir=${PREFIX}/${INFO_PATH}
#				  --mandir=${MANPREFIX}/man --build=${CONFIGURE_TARGET}" if
#				  GNU_CONFIGURE is set, "CC=${CC} CFLAGS=${CFLAGS}
#				  PREFIX=${PREFIX} INSTALLPRIVLIB=${PREFIX}/lib
#				  INSTALLARCHLIB=${PREFIX}/lib" if PERL_CONFIGURE is set,
#				  empty otherwise.
# CONFIGURE_ENV	- Pass these env (shell-like) to configure if
#				  ${HAS_CONFIGURE} is set.
# CONFIGURE_LOG	- The name of configure log file. It will be printed to
#				  the screen if configure fails.
#				  Default: config.log
# CONFIGURE_FAIL_MESSAGE
#				- A message displayed to users when configure
#				  fails (note: this assumes the do-configure
#				  target has not been overwritten).  This message
#				  will be passed through /usr/bin/fmt before
#				  being shown to the user.
#
# WITHOUT_FBSD10_FIX		  Disable FreeBSD 10.0 autotools workaround.
#
# For build and install:
#
# MAKEFILE		- Name of the makefile.
#				  Default: Makefile
# ALL_TARGET	- Default target for sub-make in build stage.
#				  Default: all
# BUILD_WRKSRC	- Directory to do build in (default: ${WRKSRC}).
# MAKE_ENV		- Additional environment vars passed to sub-make in build
#				  and install stages.
#				  Default: see below
# MAKE_ARGS		- Any extra arguments to sub-make in build and install stages.
#				  Default: none
##
# MAKE_JOBS_UNSAFE
#				- Disallow multiple jobs even when user set a global override.
#				  To be used with known bad ports.
# DISABLE_MAKE_JOBS
#				- Set to disable the multiple jobs feature.  User settable.
# MAKE_JOBS_NUMBER
#				- Override the number of make jobs to be used.  User settable.
# MAKE_JOBS_NUMBER_LIMIT
#				- Set a limit for maximum number of make jobs allowed to be
#				  used.
## cacche
#
# WITH_CCACHE_BUILD
# 				- Enable CCACHE support (devel/ccache).  User settable.
# CCACHE_DIR
# 				- Which directory to use for ccache (default: $HOME/.ccache)
# NO_CCACHE
#				- Disable CCACHE support for example for certain ports if
#				  CCACHE is enabled.  User settable.
#
# For install:
#
# INSTALL_TARGET
#				- Default target for sub-make in install stage.
#				  Default: install
# INSTALL_WRKSRC
#				- Directory to install from
#				  Default: ${WRKSRC}
# NO_MTREE		- If set, will not invoke mtree from bsd.port.mk from
#				  the "install" target.
# MTREE_FILE	- The name of the mtree file.
#				  Default: ${PORTSDIR}/Templates/BSD.local.dist or
#				  /etc/mtree/BSD.usr.dist if ${PREFIX} == "/usr".
# PLIST_DIRS	- Directories to be added to packing list
# PLIST_DIRSTRY	- Directories to be added to packing list and try to remove them.
# PLIST_FILES	- Files and symbolic links to be added to packing list
#
# PLIST			- Name of the `packing list' file.
#				  Change this to ${WRKDIR}/PLIST or something if you
#				  need to write to it.  (It is not a good idea for a port
#				  to write to any file outside ${WRKDIR} during a normal
#				  build.)
#				  Default: ${PKGDIR}/pkg-plist
# TMPPLIST		- Name of the `packing list' file after processing
#				  Default: ${WRKDIR}/.PLIST.mktmp
# PLIST_SUB		- List of "variable=value" pair for substitution in ${PLIST}
#				  Default: see below
#
# SUB_FILES		- Files that should be passed through sed and redirected to
#				  ${WRKDIR}.
#				- For each file specified in SUB_FILES, there must be a
#				  corresponding file in ${FILESDIR} whose suffix is ".in". For
#				  instance, if the Makefile specifies "SUB_FILES= pkg-message"
#				  then there must be a file called pkg-message.in in
#				  ${FILESDIR}.
#				- The substitution process is the same as PLIST_FILES, as
#				  described below except that any line beginning with @comment
#				  is deleted.
# SUB_LIST		- List of "variable=value" pair for substitution in ${SUB_FILES}
#				  Some pairs are added by default: eg. PREFIX=${PREFIX}
#
# USE_LDCONFIG  - If set to "yes", this adds ${PREFIX}/lib to the list of
#				  directories to be searched for shared libraries.
#				  Otherwise, this is a list of directories to be added to that
#				  list. The directory names are written to
#				  ${PREFIX}/libdata/ldconfig/${UNIQUENAME} which is then
#				  used by the ldconfig startup script.
#				  This mechanism replaces ldconfig scripts installed by some
#				  ports, often under such names as 000.${UNQUENAME}.sh.
#				  If USE_LINUX_PREFIX is defined, the Linux version of
#				  ldconfig will be used instead of the native FreeBSD
#				  version, and the directory list given will be ignored.
# USE_LDCONFIG32
# 				- Same as USE_LDCONFIG but the target file is
# 				  ${PREFIX}/libdata/ldconfig32/${UNIQUENAME} instead.
# 				  Note: that should only be used on 64-bit architectures.
# NO_LDCONFIG_MTREE
#				- Denotes whether the libdata/ldconfig directory is part of
#				  the mtree on a given OSVERSION system.  If it is not, we
#				  create the directory, pull in the ldconfig_compat port,
#				  and clean up on de-installation.  NOTE: this variable is
#				  internal to bsd.port.mk and must not be set in your Makefile.
#
# DOCSDIR		- Name of the directory to install the packages docs in.
#				  Default: ${PREFIX}/share/doc/${PORTNAME}
# DOCSDIR_REL	- The DOCSDIR relative to ${PREFIX}
# EXAMPLESDIR	- Name of the directory to install the packages examples in.
#				  Default: ${PREFIX}/share/examples/${PORTNAME}
# EXAMPLESDIR_REL
#				- The EXAMPLESDIR relative to ${PREFIX}
# DATADIR		- Name of the directory to install the packages shared data in.
#				  Default: ${PREFIX}/share/${PORTNAME}
# DATADIR_REL	- The DATADIR relative to ${PREFIX}
#
# WWWDIR		- Name of the directory to install the packages www data in.
#				  Default: ${PREFIX}/www/${PORTNAME}
# WWWDIR_REL	- The WWWDIR relative to ${PREFIX}
#
# USERS			- List of users to create at install time. Each login must
# 				  have a corresponding entry in ${UID_FILES}.
# GROUPS		- List of groups to create at install time. Each group must
# 				  have a corresponding entry in ${GID_FILES}.
#
# DESKTOPDIR	- Name of the directory to install ${DESKTOP_ENTRIES} in.
#				  Default: ${PREFIX}/share/applications
# DESKTOP_ENTRIES
#				- List of desktop entry files to generate and install in
#				  ${DESKTOPDIR}. The format is
#				  "Name" "Comment" "Icon" "Exec" "Categories" StartupNotify
#				  Rules:
#					* Only add desktop entries for applications which do not
#					  require a terminal (ie. X applications).
#					* If the upstream distribution already installs .desktop
#					  files, you do not need to use this.
#					* If you require a more elaborate .desktop file than this
#					  variable permits, write it yourself and install it
#					  in ${DESKTOPDIR}.
#				  Notes:
#					* Comment, Icon and StartupNotify may be empty
#					  strings (""). Categories may be an empty string in some
#					  cases (see below). The other fields are mandatory.
#					* If Comment is an empty string, port ${COMMENT} will be
#					  used.
#					* If set, Icon must be either absolute path (usually
#					  ${PREFIX}/share/pixmaps/${PORTNAME}.png) or icon name
#					  without extension if installed icons follow Icon Theme
#					  Specification.
#					* If Categories is an empty string, bsd.port.mk will try
#					  to deduce a default value using the CATEGORIES variable.
#					  If the deduction fails, you will have to set Categories
#					  manually. You should check the generated value using
#					  "make desktop-categories", and override it if necessary.
#					* Exec will also be used to name the .desktop file.
#					* StartupNotify may be true, false or empty (see Desktop
#					  Entry Specification for details).
#					* The files will be automatically added to ${PLIST}.
#				  Example:
#					"X Window Information" \
#					"Get information about X windows" \
#					"${PREFIX}/share/pixmaps/wininfo.png" \
#					"${PREFIX}/bin/wininfo" \
#					"System;" \
#					""
#				  See http://standards.freedesktop.org/desktop-entry-spec/desktop-entry-spec-latest.html
#				  for an explanation of the fields. If you need to create more
#				  than one file, just chain them into a single variable.
#
# Note that the install target will automatically add manpages (see
# above) and also substitute special sequences of characters (delimited
# by "%%") as defined in PLIST_SUB to generate ${TMPPLIST}.  For
# instance, "OSREL=${OSREL}" in PLIST_SUB causes all occurrences of
# "%%OSREL%%" in ${PLIST} to be substituted by the value of OSREL.
# ${TMPPLIST} is generated before the do-install stage.  If you are
# generating the packing list on-the-fly, make sure it's generated before
# do-install is called!
#
# For package:
#
# NO_LATEST_LINK
#				- Do not install the "Latest" link for package.  Define this
#				  if this port is a beta version of another stable port
#				  which is also in the tree.
# LATEST_LINK	- Install the "Latest" link for the package as ___.  Define
#				  this if the "Latest" link name will be incorrectly determined.
#
# This is used in all stages:
#
# SCRIPTS_ENV	- Additional environment vars passed to scripts in
#				  ${SCRIPTDIR} executed by bsd.port.mk.
#				  Default: see below
#
# Finally, variables to change if you want a special behavior.  These
# are for debugging purposes.  Don't set them in your Makefile.
#
# ECHO_MSG		- Used to print all the '===>' style prompts - override this
#				  to turn them off.
#				  Default: ${ECHO_CMD}
# PATCH_DEBUG	- If set, print out more information about the patches as
#				  it attempts to apply them.
# PKG_DBDIR		- Where package installation is recorded; this directory
#				  must not contain anything else.
#				  Default: /var/db/pkg
# PORT_DBDIR	- Where port configuration options are recorded.
#				  Default: /var/db/ports
# NO_PKG_REGISTER
#				- Don't register a port installation as a package.
# FORCE_PKG_REGISTER
#				- If set, it will overwrite any existing package
#				  registration information in ${PKG_DBDIR}/${PKGNAME}.
# NO_DEPENDS	- Don't verify build of dependencies.
# CHECKSUM_ALGORITHMS
#				- Different checksum algorithms to check for verifying the
#				  integrity of the distfiles. The absence of the algorithm
#				  in distinfo doesn't make it fail.
#				  Default: sha256
# NO_CHECKSUM	- Don't verify the checksum.  Typically used when
#				  when you noticed the distfile you just fetched has
#				  a different checksum and you intend to verify if
#				  the port still works with it.
# USE_PACKAGE_DEPENDS
#				- Try to install dependencies from existing packages instead
#				  of building the port from scratch. Fallback on source
#				  if an existing package is not present.
# USE_PACKAGE_DEPENDS_ONLY
#				- Like USE_PACKAGE_DEPENDS, but do not fallback on source.
# INSTALL_AS_USER
#				- Define this to install as the current user, intended
#				  for systems where you have no root access.
# DISABLE_SIZE	- Do not check the size of a distfile even if the SIZE field
#				  has been specified in distinfo.  This is useful
#				  when using an alternate FETCH_CMD.
#
# End of the list of all variables that need to be defined in a port.
# Most port authors should not need to understand anything after this point.
#

# These need to be absolute since we don't know how deep in the ports
# tree we are and thus can't go relative.  They can, of course, be overridden
# by individual Makefiles or local system make configuration.
PORTSDIR?=		/usr/ports
LOCALBASE?=		/usr/local
LINUXBASE?=		/compat/linux
DISTDIR?=		${PORTSDIR}/distfiles
_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
INDEXDIR?=		${PORTSDIR}
SRC_BASE?=		/usr/src
USESDIR?=		${PORTSDIR}/Mk/Uses
SCRIPTSDIR?=	${PORTSDIR}/Mk/Scripts
LIB_DIRS?=		/lib /usr/lib ${LOCALBASE}/lib

.if defined(FORCE_STAGE)
.undef NO_STAGE
.endif

# make sure bmake treats -V as expected 
.MAKE.EXPAND_VARIABLES= yes
# tell bmake we use the old :L :U modifiers
.MAKE.FreeBSD_UL= yes

.include "${PORTSDIR}/Mk/bsd.commands.mk"

#
# DESTDIR section to start a chrooted process if invoked with DESTDIR set
#

.if defined(DESTDIR) && !empty(DESTDIR) && !defined(CHROOTED) && \
	!defined(BEFOREPORTMK) && !defined(INOPTIONSMK)

.include "${PORTSDIR}/Mk/bsd.destdir.mk"

.else

# Look for ${PATCH_WRKSRC}/.../*.orig files, and (re-)create
# ${FILEDIR}/patch-* files from them.

.if !target(makepatch)
makepatch:
	@${MKDIR} ${FILESDIR}
	@(cd ${PATCH_WRKSRC}; \
		for i in `find . -type f -name '*.orig'`; do \
			ORG=$$i; \
			NEW=$${i%.orig}; \
			OUT=${FILESDIR}`${ECHO} $${NEW} | \
				${SED} -e 's|/|__|g' \
					-e 's|^\.__|/patch-|'`; \
			${ECHO} ${DIFF} -ud $${ORG} $${NEW} '>' $${OUT}; \
			${DIFF} -ud $${ORG} $${NEW} > $${OUT} || ${TRUE}; \
		done \
	)
.endif


# Start of options section
.if defined(INOPTIONSMK) || ( !defined(USEOPTIONSMK) && !defined(AFTERPORTMK) )


# Get the default maintainer
MAINTAINER?=	ports@FreeBSD.org

# Get the architecture
.if !defined(ARCH)
ARCH!=	${UNAME} -p
.endif

# Get the operating system type
.if !defined(OPSYS)
OPSYS!=	${UNAME} -s
.endif

# Get the operating system revision
.if !defined(OSREL)
OSREL!=	${UNAME} -r | ${SED} -e 's/[-(].*//'
.endif

# Get __FreeBSD_version
.if !defined(OSVERSION)
.if exists(/usr/include/sys/param.h)
OSVERSION!=	${AWK} '/^\#define[[:blank:]]__FreeBSD_version/ {print $$3}' < /usr/include/sys/param.h
.elif exists(${SRC_BASE}/sys/sys/param.h)
OSVERSION!=	${AWK} '/^\#define[[:blank:]]__FreeBSD_version/ {print $$3}' < ${SRC_BASE}/sys/sys/param.h
.else
OSVERSION!=	${SYSCTL} -n kern.osreldate
.endif
.endif

.if ${OSVERSION} >= 1000017
.if !defined(WITHOUT_PKGNG)
WITH_PKGNG?=	yes
.else
.undef	WITH_PKGNG
.endif
.endif

# Only define tools here (for transition period with between pkg tools)
.include "${PORTSDIR}/Mk/bsd.commands.mk"

MASTERDIR?=	${.CURDIR}

.if ${MASTERDIR} != ${.CURDIR}
SLAVE_PORT?=	yes
MASTER_PORT?=${MASTERDIR:C/[^\/]+\/\.\.\///:C/[^\/]+\/\.\.\///:C/^.*\/([^\/]+\/[^\/]+)$/\\1/}
.else
SLAVE_PORT?=	no
MASTER_PORT?=
.endif

# If they exist, include Makefile.inc, then architecture/operating
# system specific Makefiles, then local Makefile.local.

.if ${MASTERDIR} != ${.CURDIR} && exists(${.CURDIR}/../Makefile.inc)
.include "${.CURDIR}/../Makefile.inc"
USE_SUBMAKE=	yes
.endif

.if exists(${MASTERDIR}/../Makefile.inc)
.include "${MASTERDIR}/../Makefile.inc"
USE_SUBMAKE=	yes
.endif

.if exists(${MASTERDIR}/Makefile.${ARCH}-${OPSYS})
.include "${MASTERDIR}/Makefile.${ARCH}-${OPSYS}"
USE_SUBMAKE=	yes
.elif exists(${MASTERDIR}/Makefile.${OPSYS})
.include "${MASTERDIR}/Makefile.${OPSYS}"
USE_SUBMAKE=	yes
.elif exists(${MASTERDIR}/Makefile.${ARCH})
.include "${MASTERDIR}/Makefile.${ARCH}"
USE_SUBMAKE=	yes
.endif

.if exists(${MASTERDIR}/Makefile.local)
.include "${MASTERDIR}/Makefile.local"
USE_SUBMAKE=	yes
.endif

.for _CATEGORY in ${CATEGORIES}
PKGCATEGORY?=	${_CATEGORY}
.endfor
_PORTDIRNAME=	${.CURDIR:T}
PORTDIRNAME?=	${_PORTDIRNAME}
PKGORIGIN?=		${PKGCATEGORY}/${PORTDIRNAME}

# where 'make config' records user configuration options
PORT_DBDIR?=	/var/db/ports

UID_FILES?=	${PORTSDIR}/UIDs
GID_FILES?=	${PORTSDIR}/GIDs
UID_OFFSET?=	0
GID_OFFSET?=	0

# predefined accounts from src/etc/master.passwd
# alpha numeric sort order
USERS_BLACKLIST=	_dhcp _pflogd auditdistd bin bind daemon games hast kmem mailnull man news nobody operator pop proxy root smmsp sshd toor tty uucp www

LDCONFIG_DIR=	libdata/ldconfig
LDCONFIG32_DIR=	libdata/ldconfig32

.if defined(LATEST_LINK)
UNIQUENAME?=	${LATEST_LINK}
.else
UNIQUENAME?=	${PKGNAMEPREFIX}${PORTNAME}
.endif

.endif

DOS2UNIX_REGEX?=	.*

# At least KDE needs TMPDIR for the package building,
# so we're setting it to the known default value.
.if defined(PACKAGE_BUILDING)
TMPDIR?=	/tmp
.endif # defined(PACKAGE_BUILDING)

# Respect TMPDIR passed via make.conf or similar and pass it down
# to configure and make.
.if defined(TMPDIR)
MAKE_ENV+=	TMPDIR="${TMPDIR}"
CONFIGURE_ENV+=	TMPDIR="${TMPDIR}"
.endif # defined(TMPDIR)

# Reset value from bsd.own.mk.
.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
STRIP=	#none
.endif

.include "${PORTSDIR}/Mk/bsd.options.mk"

# Start of pre-makefile section.
.if !defined(AFTERPORTMK) && !defined(INOPTIONSMK)

.include "${PORTSDIR}/Mk/bsd.sanity.mk"

_PREMKINCLUDED=	yes

.if defined(PORTVERSION)
.if ${PORTVERSION:M*[-_,]*}x != x
IGNORE=			PORTVERSION ${PORTVERSION} may not contain '-' '_' or ','
.endif
DISTVERSION?=	${PORTVERSION:S/:/::/g}
.elif defined(DISTVERSION)
PORTVERSION=	${DISTVERSION:L:C/([a-z])[a-z]+/\1/g:C/([0-9])([a-z])/\1.\2/g:C/:(.)/\1/g:C/[^a-z0-9+]+/./g}
.endif

PORTREVISION?=	0
.if ${PORTREVISION} != 0
_SUF1=	_${PORTREVISION}
.endif

PORTEPOCH?=		0
.if ${PORTEPOCH} != 0
_SUF2=	,${PORTEPOCH}
.endif

PKGVERSION=	${PORTVERSION:C/[-_,]/./g}${_SUF1}${_SUF2}
PKGNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PKGVERSION}
DISTNAME?=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

INDEXFILE?=		INDEX-${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}

DOCSDIR?=		${PREFIX}/share/doc/${PORTNAME}
EXAMPLESDIR?=		${PREFIX}/share/examples/${PORTNAME}
DATADIR?=		${PREFIX}/share/${PORTNAME}
WWWDIR?=		${PREFIX}/www/${PORTNAME}
ETCDIR?=		${PREFIX}/etc/${PORTNAME}

.if defined(USE_LINUX_RPM)
.include "${PORTSDIR}/Mk/bsd.linux-rpm.mk"
.endif

.if defined(USE_LINUX_APPS)
.include "${PORTSDIR}/Mk/bsd.linux-apps.mk"
.endif

.if defined(USE_XORG) || defined(XORG_CAT)
.include "${PORTSDIR}/Mk/bsd.xorg.mk"
.endif

.if defined(USE_BZIP2)
EXTRACT_SUFX?=			.tar.bz2
.elif defined(USE_LHA)
EXTRACT_SUFX?=			.lzh
.elif defined(USE_ZIP)
EXTRACT_SUFX?=			.zip
.elif defined(USE_XZ)
EXTRACT_SUFX?=			.tar.xz
.elif defined(USE_MAKESELF)
EXTRACT_SUFX?=			.run
.else
EXTRACT_SUFX?=			.tar.gz
.endif
PACKAGES?=		${PORTSDIR}/packages
TEMPLATES?=		${PORTSDIR}/Templates

PATCHDIR?=		${MASTERDIR}/files
FILESDIR?=		${MASTERDIR}/files
SCRIPTDIR?=		${MASTERDIR}/scripts
PKGDIR?=		${MASTERDIR}

.if defined(USE_LINUX_PREFIX)
PREFIX?=		${LINUXBASE}
NO_MTREE=		yes
.else
PREFIX?=		${LOCALBASE}
.endif

.if defined(USE_LINUX_PREFIX)
LDCONFIG_CMD?=			${LINUXBASE}/sbin/ldconfig -r ${LINUXBASE}
.endif

PKGCOMPATDIR?=		${LOCALBASE}/lib/compat/pkg

.if defined(USE_LOCAL_MK)
.include "${PORTSDIR}/Mk/bsd.local.mk"
.endif

.if defined(USE_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if defined(USE_EMACS)
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
.endif

.if defined(USE_GNUSTEP)
.include "${PORTSDIR}/Mk/bsd.gnustep.mk"
.endif

.if defined(USE_PHP)
.include "${PORTSDIR}/Mk/bsd.php.mk"
.endif

.if defined(USE_PYTHON) || defined(USE_PYTHON_BUILD) || defined(USE_PYTHON_RUN)
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(USE_EFL) || defined(WANT_EFL) || defined(USE_EFL_ESMART)
.include "${PORTSDIR}/Mk/bsd.efl.mk"
.endif

.if defined(USE_FPC) || defined(WANT_FPC_BASE) || defined(WANT_FPC_ALL)
.include "${PORTSDIR}/Mk/bsd.fpc.mk"
.endif

.if defined(USE_JAVA)
.include "${PORTSDIR}/Mk/bsd.java.mk"
.endif

.if defined(USE_R_MOD)
.include "${PORTSDIR}/Mk/bsd.cran.mk"
.endif

.if defined(USE_RUBY) || defined(USE_LIBRUBY)
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.endif

.if defined(USE_OCAML)
.include "${PORTSDIR}/Mk/bsd.ocaml.mk"
.endif

.if defined(USE_TCL) || defined(USE_TCL_BUILD) || defined(USE_TCL_RUN) || defined(USE_TCL_WRAPPER) || defined(USE_TK) || defined(USE_TK_BUILD) || defined(USE_TK_RUN) || defined(USE_TK_WRAPPER)
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_BUILD) || defined(USE_APACHE_RUN)
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.endif

.if defined(USE_QT4)
.include "${PORTSDIR}/Mk/bsd.qt.mk"
.endif

.if defined(USE_TEX)
.include "${PORTSDIR}/Mk/bsd.tex.mk"
.endif

.if defined(USE_DRUPAL)
.include "${PORTSDIR}/Mk/bsd.drupal.mk"
.endif

.if defined(WANT_GECKO) || defined(USE_GECKO) || defined(USE_FIREFOX) || defined(USE_FIREFOX_BUILD) || defined(USE_SEAMONKEY) || defined(USE_SEAMONKEY_BUILD) || defined(USE_THUNDERBIRD) || defined(USE_THUNDERBIRD_BUILD)
.include "${PORTSDIR}/Mk/bsd.gecko.mk"
.endif

.if defined(WANT_GNOME) || defined(USE_GNOME) || defined(INSTALLS_ICONS)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.endif

.if defined(WANT_LUA) || defined(USE_LUA) || defined(USE_LUA_NOT)
.include "${PORTSDIR}/Mk/bsd.lua.mk"
.endif

.if defined(WANT_WX) || defined(USE_WX) || defined(USE_WX_NOT)
.include "${PORTSDIR}/Mk/bsd.wx.mk"
.endif

.if defined(WANT_GSTREAMER) || defined(USE_GSTREAMER) || defined(USE_GSTREAMER1)
.include "${PORTSDIR}/Mk/bsd.gstreamer.mk"
.endif

.if defined(USE_SDL) || defined(WANT_SDL)
.include "${PORTSDIR}/Mk/bsd.sdl.mk"
.endif

.if defined(USE_XFCE)
.include "${PORTSDIR}/Mk/bsd.xfce.mk"
.endif

.if defined(USE_KDE4) || defined(KDE4_BUILDENV)
.include "${PORTSDIR}/Mk/bsd.kde4.mk"
.endif

.include "${PORTSDIR}/Mk/bsd.pbi.mk"

.if defined(USE_GMAKE)
USES+=	gmake
.endif

.if !defined(UID)
UID!=	${ID} -u
.endif

# Loading features
.for f in ${USES}
_f=${f:C/\:.*//g}
.if ${_f} != ${f}
${_f}_ARGS:=	${f:C/^[^\:]*\://g}
.endif
.include "${USESDIR}/${_f}.mk"
.endfor

# You can force skipping these test by defining IGNORE_PATH_CHECKS
.if !defined(IGNORE_PATH_CHECKS)
.if ! ${PREFIX:M/*}
.BEGIN:
	@${ECHO_MSG} "PREFIX must be defined as an absolute path so that when 'make'"
	@${ECHO_MSG} "is invoked in the work area PREFIX points to the right place."
	@${FALSE}
.endif
.endif

# Location of mounted CDROM(s) to search for files
CD_MOUNTPTS?=	/cdrom ${CD_MOUNTPT}

# Owner and group of the WWW user
WWWOWN?=	www
WWWGRP?=	www

.endif
# End of pre-makefile section.

# Start of post-makefile section.
.if !defined(BEFOREPORTMK) && !defined(INOPTIONSMK)

.if defined(_POSTMKINCLUDED)
check-makefile::
	@${ECHO_MSG} "${PKGNAME}: Makefile error: you cannot include bsd.port[.post].mk twice"
	@${FALSE}
.endif

_POSTMKINCLUDED=	yes

WRKDIR?=		${WRKDIRPREFIX}${.CURDIR}/work
.if !defined(IGNORE_MASTER_SITE_GITHUB) && defined(USE_GITHUB)
WRKSRC?=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
.endif
.if defined(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}
.else
WRKSRC?=		${WRKDIR}/${DISTNAME}
.endif
.if defined(WRKSRC_SUBDIR)
WRKSRC:=		${WRKSRC}/${WRKSRC_SUBDIR}
.endif

PATCH_WRKSRC?=	${WRKSRC}
CONFIGURE_WRKSRC?=	${WRKSRC}
BUILD_WRKSRC?=	${WRKSRC}
INSTALL_WRKSRC?=${WRKSRC}

PLIST_SUB+=	OSREL=${OSREL} PREFIX=%D LOCALBASE=${LOCALBASE} 
SUB_LIST+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		DATADIR=${DATADIR} DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR} \
		WWWDIR=${WWWDIR} ETCDIR=${ETCDIR}

PLIST_REINPLACE+=	dirrmtry stopdaemon rmtry
PLIST_REINPLACE_DIRRMTRY=s!^@dirrmtry \(.*\)!@unexec rmdir "%D/\1" 2>/dev/null || true!
PLIST_REINPLACE_RMTRY=s!^@rmtry \(.*\)!@unexec rm -f %D/\1 2>/dev/null || true!
PLIST_REINPLACE_STOPDAEMON=s!^@stopdaemon \(.*\)!@unexec %D/etc/rc.d/\1 forcestop 2>/dev/null || true!

# kludge to strip trailing whitespace from CFLAGS;
# sub-configure will not # survive double space
CFLAGS:=	${CFLAGS:C/ $//}

.if defined(WITHOUT_CPU_CFLAGS)
.if defined(_CPUCFLAGS)
.if !empty(_CPUCFLAGS)
CFLAGS:=	${CFLAGS:C/${_CPUCFLAGS}//}
.endif
.endif
.endif

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
STRIP_CMD=	${TRUE}
DEBUG_FLAGS?=	-g
CFLAGS:=		${CFLAGS:N-O*:N-fno-strict*} ${DEBUG_FLAGS}
.endif

.if defined(WITH_SSP) || defined(WITH_SSP_PORTS)
.include "${PORTSDIR}/Mk/bsd.ssp.mk"
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=		PORTDOCS="@comment "
.else
PLIST_SUB+=		PORTDOCS=""
.endif

.if defined(NOPORTEXAMPLES)
PLIST_SUB+=	        PORTEXAMPLES="@comment "
.else
PLIST_SUB+=	        PORTEXAMPLES=""
.endif

.if defined(NOPORTDATA)
PLIST_SUB+=	        PORTDATA="@comment "
.else
PLIST_SUB+=	        PORTDATA=""
.endif

CONFIGURE_SHELL?=	${SH}
MAKE_SHELL?=	${SH}

CONFIGURE_ENV+=	SHELL=${SH} CONFIG_SHELL=${SH}
MAKE_ENV+=		SHELL=${SH} NO_LINT=YES

.if defined(MANCOMPRESSED)
.if ${MANCOMPRESSED} != yes && ${MANCOMPRESSED} != no && \
	${MANCOMPRESSED} != maybe
check-makevars::
	@${ECHO_MSG} "${PKGNAME}: Makefile error: value of MANCOMPRESSED (is \"${MANCOMPRESSED}\") can only be \"yes\", \"no\" or \"maybe\"".
	@${FALSE}
.endif
.endif

MANCOMPRESSED?=	no

.if defined(PATCHFILES)
.if ${PATCHFILES:M*.zip}x != x
PATCH_DEPENDS+=		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
.endif
.endif

# Check the compatibility layer for amd64/ia64

.if ${ARCH} == "amd64" || ${ARCH} =="ia64"
.if exists(/usr/lib32)
HAVE_COMPAT_IA32_LIBS?=  YES
.endif
.if !defined(HAVE_COMPAT_IA32_KERN)
HAVE_COMPAT_IA32_KERN!= if ${SYSCTL} -n compat.ia32.maxvmem >/dev/null 2>&1; then echo YES; fi; echo
.if empty(HAVE_COMPAT_IA32_KERN)
.undef HAVE_COMPAT_IA32_KERN
.endif
.endif
.endif

.if defined(IA32_BINARY_PORT) && ${ARCH} != "i386"
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
.if !defined(HAVE_COMPAT_IA32_KERN)
IGNORE=		requires a kernel with compiled-in IA32 compatibility
.elif !defined(HAVE_COMPAT_IA32_LIBS)
IGNORE=		requires 32-bit libraries installed under /usr/lib32
.endif
_LDCONFIG_FLAGS=-32
LIB32DIR=	lib32
.else
IGNORE=		requires i386 (or compatible) platform to run
.endif
.else
LIB32DIR=	lib
.endif
PLIST_SUB+=	LIB32DIR=${LIB32DIR}

PKGNG_ORIGIN?=	ports-mgmt/pkg
.if defined(WITH_PKGNG)
.if ${WITH_PKGNG} == devel
PKGNG_ORIGIN=		ports-mgmt/pkg-devel
.endif
.if !defined(PKG_DEPENDS)
.if !defined(CLEAN_FETCH_ENV)
PKG_DEPENDS+=		${LOCALBASE}/sbin/pkg:${PORTSDIR}/${PKGNG_ORIGIN}
.endif
.endif
.endif

.if defined(USE_LHA)
EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha
.endif
.if defined(USE_ZIP)
EXTRACT_DEPENDS+=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
.endif
.if defined(USE_XZ) && ( (${OSVERSION} >= 900000 && ${OSVERSION} < 900012) || ${OSVERSION} < 800505 )
EXTRACT_DEPENDS+=	${LOCALBASE}/bin/xz:${PORTSDIR}/archivers/xz
.endif
.if defined(USE_MAKESELF)
EXTRACT_DEPENDS+=	unmakeself:${PORTSDIR}/archivers/unmakeself
.endif

.if defined(USE_GCC) || defined(USE_FORTRAN)
.include "${PORTSDIR}/Mk/bsd.gcc.mk"
.endif

.if defined(USE_BINUTILS) && !defined(DISABLE_BINUTILS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
BINUTILS?=	ADDR2LINE AR AS CPPFILT GPROF LD NM OBJCOPY OBJDUMP RANLIB \
	READELF SIZE STRINGS
BINUTILS_NO_MAKE_ENV?=
. for b in ${BINUTILS}
${b}=	${LOCALBASE}/bin/${b:C/PP/++/:L}
.  if defined(GNU_CONFIGURE) || defined(BINUTILS_CONFIGURE)
CONFIGURE_ENV+=	${b}="${${b}}"
.  endif
.  if ${BINUTILS_NO_MAKE_ENV:M${b}} == ""
MAKE_ENV+=	${b}="${${b}}"
.  endif
. endfor
.endif

.if defined(USE_OPENLDAP) || defined(WANT_OPENLDAP_VER)
.include "${PORTSDIR}/Mk/bsd.ldap.mk"
.endif

.if defined(USE_OPENAL)
_OPENAL_ALL=	al si soft alut
_OPENAL_LIBS=	si soft
# Default choice.
_DEFAULT_OPENAL=	soft

_OPENAL_SOFT=	openal.1:${PORTSDIR}/audio/openal-soft
_OPENAL_SI=	openal.0:${PORTSDIR}/audio/openal
_OPENAL_ALUT=	alut.1:${PORTSDIR}/audio/freealut

.if exists(${LOCALBASE}/lib/libopenal.a)
_HAVE_OPENAL=	si
.elif exists(${LOCALBASE}/bin/openal-info)
_HAVE_OPENAL=	soft
.endif

.if ${USE_OPENAL} == "yes"
# Be friendly.
USE_OPENAL=	${_DEFAULT_OPENAL}
.endif

__USED_OPENAL=
_USE_OPENAL=
.for component in ${USE_OPENAL}
.if ${__USED_OPENAL:M${component}} == ""
__USED_OPENAL+=	${component}

.if ${_OPENAL_ALL:M${component}} == ""
BROKEN=	OPENAL mismatch: unknown component ${component}
.elif ${_OPENAL_ALL:M${component}} == "al"

# Check if the user wish matches the found OpenAL system.
.if defined(WANT_OPENAL) && defined(_HAVE_OPENAL) && ${_HAVE_OPENAL} != ${WANT_OPENAL}
BROKEN=	OPENAL mismatch: ${_HAVE_OPENAL} is installed, but ${WANT_OPENAL} desired
.endif # WANT_OPENAL

.if defined(_HAVE_OPENAL)
_OPENAL_SYSTEM=	${_HAVE_OPENAL}
.elif defined(WANT_OPENAL)
_OPENAL_SYSTEM=	${WANT_OPENAL}
.else
_OPENAL_SYSTEM=	${_DEFAULT_OPENAL}
.endif # _HAVE_OPENAL

_USE_OPENAL+= ${_OPENAL_${_OPENAL_SYSTEM:U}}

.else # ${_OPENAL_ALL:M${component}} == ""

.if ${_OPENAL_LIBS:M${component}} == ${component}
# Check for the system implementation to use.
.if defined(WANT_OPENAL) && ${WANT_OPENAL} != ${component}
BROKEN=	OPENAL mismatch: wants to use ${component}, while you wish to use ${WANT_OPENAL}
.endif
.if defined(_OPENAL_SYSTEM)
BROKEN=	OPENAL mismatch: cannot use ${component} and al together.
.endif
.if defined(_HAVE_OPENAL) && ${_HAVE_OPENAL} != ${component}
BROKEN=	OPENAL mismatch: wants to use ${component}, but ${_HAVE_OPENAL} is installed
.endif

_OPENAL_SYSTEM=	${component}

.endif # ${_OPENAL_LIBS:M${component}} == ${component}

_USE_OPENAL+=	${_OPENAL_${component:U}}

.endif # ${_OPENAL_ALL:M${component}} == ""

.endif # ${__USED_OPENAL:M${component} == ""
.endfor # component in ${USE_OPENAL}

.for dep in ${_USE_OPENAL}
LIB_DEPENDS+=	${dep}
.endfor

.endif # USE_OPENAL

.if defined(USE_FAM)
DEFAULT_FAM_SYSTEM=	gamin
# Currently supported FAM systems
FAM_SYSTEM_FAM=		fam.0:${PORTSDIR}/devel/fam
FAM_SYSTEM_GAMIN=	fam.0:${PORTSDIR}/devel/gamin

.if exists(${LOCALBASE}/libexec/gam_server)
_HAVE_FAM_SYSTEM=	gamin
.elif exists(${LOCALBASE}/bin/fam)
_HAVE_FAM_SYSTEM=	fam
.endif

.if defined(WANT_FAM_SYSTEM)
.if defined(WITH_FAM_SYSTEM) && ${WITH_FAM_SYSTEM}!=${WANT_FAM_SYSTEM}
IGNORE=		wants to use ${WANT_FAM_SYSTEM} as its FAM system, while you wish to use ${WITH_FAM_SYSTEM}
.endif
FAM_SYSTEM=	${WANT_FAM_SYSTEM}
.elif defined(WITH_FAM_SYSTEM)
FAM_SYSTEM=	${WITH_FAM_SYSTEM}
.else
.if defined(_HAVE_FAM_SYSTEM)
FAM_SYSTEM=	${_HAVE_FAM_SYSTEM}
.else
FAM_SYSTEM=	${DEFAULT_FAM_SYSTEM}
.endif
.endif # WANT_FAM_SYSTEM

.if defined(_HAVE_FAM_SYSTEM)
.if ${_HAVE_FAM_SYSTEM}!= ${FAM_SYSTEM}
BROKEN=		FAM system mismatch: ${_HAVE_FAM_SYSTEM} is installed, while desired FAM system is ${FAM_SYSTEM}
.endif
.endif

.if defined(FAM_SYSTEM_${FAM_SYSTEM:U})
LIB_DEPENDS+=	${FAM_SYSTEM_${FAM_SYSTEM:U}}
.else
IGNORE=		cannot be built with unknown FAM system: ${FAM_SYSTEM}
.endif
.endif # USE_FAM

.if defined(USE_RC_SUBR) && ${USE_RC_SUBR:U} != "YES"
SUB_FILES+=	${USE_RC_SUBR}
.endif

.if defined(USE_RCORDER)
SUB_FILES+=	${USE_RCORDER}
.endif

.if defined(USE_LDCONFIG) && ${USE_LDCONFIG:L} == "yes"
USE_LDCONFIG=	${PREFIX}/lib
.endif
.if defined(USE_LDCONFIG32) && ${USE_LDCONFIG32:L} == "yes"
IGNORE=			has USE_LDCONFIG32 set to yes, which is not correct
.endif

.if defined(USE_LINUX_PREFIX) && defined(USE_LDCONFIG)
# we need ${LINUXBASE}/sbin/ldconfig
USE_LINUX?=	yes
.endif

.if defined(USE_LINUX)

.  if !defined(LINUX_OSRELEASE)
LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`
.  endif

# install(1) also does a brandelf on strip, so don't strip with FreeBSD tools.
STRIP=
.	if exists(${LINUXBASE}/usr/bin/strip)
STRIP_CMD=	${LINUXBASE}/usr/bin/strip
.	else
STRIP_CMD=	${TRUE}
.	endif

# Allow the user to specify another linux_base version.
.	if defined(OVERRIDE_LINUX_BASE_PORT)
.		if ${USE_LINUX:L} == yes
USE_LINUX=	${OVERRIDE_LINUX_BASE_PORT}
.		endif
.	endif

# NOTE: when you update the default linux_base version (case "yes"),
# don't forget to update the Handbook!

.	if exists(${PORTSDIR}/emulators/linux_base-${USE_LINUX})
LINUX_BASE_PORT=	${LINUXBASE}/bin/sh:${PORTSDIR}/emulators/linux_base-${USE_LINUX}
.	else
.		if ${USE_LINUX:L} == "yes"
LINUX_BASE_PORT=	${LINUXBASE}/etc/fedora-release:${PORTSDIR}/emulators/linux_base-f10
.		else
IGNORE=		cannot be built: there is no emulators/linux_base-${USE_LINUX}, perhaps wrong use of USE_LINUX or OVERRIDE_LINUX_BASE_PORT
.		endif
.	endif

RUN_DEPENDS+=	${LINUX_BASE_PORT}
.endif

.if defined(USE_DISPLAY) && !defined(DISPLAY)
BUILD_DEPENDS+=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
	${LOCALBASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
	${LOCALBASE}/lib/X11/fonts/misc/fonts.alias:${PORTSDIR}/x11-fonts/font-alias \
	${LOCALBASE}/share/X11/xkb/rules/base:${PORTSDIR}/x11/xkeyboard-config \
	xkbcomp:${PORTSDIR}/x11/xkbcomp
.if !defined(PACKAGE_BUILDING)
CONFIGURE_ENV+=	DISPLAY="localhost:1001"
MAKE_ENV+=		DISPLAY="localhost:1001"
.endif
.endif

PKG_IGNORE_DEPENDS?=		'this_port_does_not_exist'

_GL_glesv2_LIB_DEPENDS=		libGLESv2.so:${PORTSDIR}/grahpics/libglesv2
_GL_egl_LIB_DEPENDS=		libEGL.so:${PORTSDIR}/graphics/libEGL
_GL_gl_LIB_DEPENDS=		libGL.so:${PORTSDIR}/graphics/libGL
_GL_gl_USE_XORG=		glproto dri2proto
_GL_glew_LIB_DEPENDS=		libGLEW.so:${PORTSDIR}/graphics/glew
_GL_glu_LIB_DEPENDS=		libGLU.so:${PORTSDIR}/graphics/libGLU
_GL_glu_USE_XORG=		glproto dri2proto
_GL_glw_LIB_DEPENDS=		libGLw.so:${PORTSDIR}/graphics/libGLw
_GL_glut_LIB_DEPENDS=		libglut.so:${PORTSDIR}/graphics/freeglut

.if defined(USE_GL)
. if ${USE_GL:L} == "yes"
USE_GL=		glu
. endif
. for _component in ${USE_GL}
.  if !defined(_GL_${_component}_LIB_DEPENDS) && \
		!defined(_GL_${_component}_RUN_DEPENDS)
IGNORE=		uses unknown GL component
.  else
USE_XORG+=	${_GL_${_component}_USE_XORG}
BUILD_DEPENDS+=	${_GL_${_component}_BUILD_DEPENDS}
LIB_DEPENDS+=	${_GL_${_component}_LIB_DEPENDS}
RUN_DEPENDS+=	${_GL_${_component}_RUN_DEPENDS}
.  endif
. endfor
.endif

.if !defined(NO_STAGE)
.include "${PORTSDIR}/Mk/bsd.stage.mk"
.endif

.if defined(WITH_PKGNG)
.include "${PORTSDIR}/Mk/bsd.pkgng.mk"
.endif

.if defined(USE_LOCAL_MK)
.include "${PORTSDIR}/Mk/bsd.local.mk"
.endif

.if defined(USE_XORG) || defined(XORG_CAT)
.include "${PORTSDIR}/Mk/bsd.xorg.mk"
.endif

.if defined(USE_MYSQL) || defined(WANT_MYSQL_VER) || \
	defined(USE_PGSQL) || defined(WANT_PGSQL_VER) || \
	defined(USE_BDB) || defined(USE_SQLITE) || defined(USE_FIREBIRD)
.include "${PORTSDIR}/Mk/bsd.database.mk"
.endif

.if defined(WANT_GSTREAMER) || defined(USE_GSTREAMER) || defined(USE_GSTREAMER1)
.include "${PORTSDIR}/Mk/bsd.gstreamer.mk"
.endif

.if defined(USE_EFL) || defined(WANT_EFL) || defined(USE_EFL_ESMART)
.include "${PORTSDIR}/Mk/bsd.efl.mk"
.endif

.if defined(USE_JAVA)
.include "${PORTSDIR}/Mk/bsd.java.mk"
.endif

.if defined(USE_LINUX_RPM)
.include "${PORTSDIR}/Mk/bsd.linux-rpm.mk"
.endif

.if defined(USE_LINUX_APPS)
.include "${PORTSDIR}/Mk/bsd.linux-apps.mk"
.endif

.if defined(USE_QT4)
.include "${PORTSDIR}/Mk/bsd.qt.mk"
.endif

.if defined(USE_SCONS)
.include "${PORTSDIR}/Mk/bsd.scons.mk"
.endif

.if defined(USE_SDL) || defined(WANT_SDL)
.include "${PORTSDIR}/Mk/bsd.sdl.mk"
.endif

.if defined(USE_PHP)
.include "${PORTSDIR}/Mk/bsd.php.mk"
.endif

.if defined(USE_PYTHON)
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(USE_TCL) || defined(USE_TCL_BUILD) || defined(USE_TK) || defined(USE_TK_BUILD)
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.endif

.if defined(USE_LUA) || defined(USE_LUA_NOT)
.include "${PORTSDIR}/Mk/bsd.lua.mk"
.endif

.if defined(USE_WX) || defined(USE_WX_NOT)
.include "${PORTSDIR}/Mk/bsd.wx.mk"
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_BUILD) || defined(USE_APACHE_RUN)
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.endif

.if defined(USE_AUTOTOOLS)
.include "${PORTSDIR}/Mk/bsd.autotools.mk"
.endif

.if defined(USE_FPC) || defined(WANT_FPC_BASE) || defined(WANT_FPC_ALL)
.include "${PORTSDIR}/Mk/bsd.fpc.mk"
.endif

.if defined(WANT_GECKO) || defined(USE_GECKO)
.include "${PORTSDIR}/Mk/bsd.gecko.mk"
.endif

.if defined(WANT_GNOME) || defined(USE_GNOME)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.endif

.if defined(USE_XFCE)
.include "${PORTSDIR}/Mk/bsd.xfce.mk"
.endif

.if defined(USE_KDE4)
.include "${PORTSDIR}/Mk/bsd.kde4.mk"
.endif

.if exists(${PORTSDIR}/Makefile.inc)
.include "${PORTSDIR}/Makefile.inc"
USE_SUBMAKE=	yes
.endif

# Loading features
.for f in ${_USES_POST}
_f=${f:C/\:.*//g}
.if ${_f} != ${f}
${_f}_ARGS:=	${f:C/^[^\:]*\://g}
.endif
.include "${USESDIR}/${_f}.mk"
.endfor

.if defined(USE_XORG)
# Add explicit X options to avoid problems with false positives in configure
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
.endif
.endif

# Set the default for the installation of Postscript(TM)-
# compatible functionality.
.if !defined(USE_GHOSTSCRIPT)
.	if defined(USE_GHOSTSCRIPT_BUILD)
_USE_GHOSTSCRIPT=	${USE_GHOSTSCRIPT_BUILD}
.	elif defined(USE_GHOSTSCRIPT_RUN)
_USE_GHOSTSCRIPT=	${USE_GHOSTSCRIPT_RUN}
.	endif
.else
_USE_GHOSTSCRIPT=	${USE_GHOSTSCRIPT}
.endif

.if defined(WITH_GHOSTSCRIPT_VER) && !empty(WITH_GHOSTSCRIPT_VER:M[789])
_USE_GHOSTSCRIPT_DEFAULT_VER=	${WITH_GHOSTSCRIPT_VER}
.else
_USE_GHOSTSCRIPT_DEFAULT_VER=	9
.endif

.if defined(_USE_GHOSTSCRIPT)
.	if !defined(WITHOUT_X11)
_USE_GHOSTSCRIPT_PKGNAME_SUFFIX=
.	else
_USE_GHOSTSCRIPT_PKGNAME_SUFFIX=-nox11
.	endif
.	if !empty(_USE_GHOSTSCRIPT:M[789])
_USE_GHOSTSCRIPT_VER=${_USE_GHOSTSCRIPT:M[789]}
.	else
_USE_GHOSTSCRIPT_VER=${_USE_GHOSTSCRIPT_DEFAULT_VER}
.	endif
.else
_USE_GHOSTSCRIPT_VER=${_USE_GHOSTSCRIPT_DEFAULT_VER}
.endif

# Sanity check
.if defined(_USE_GHOSTSCRIPT) && defined(WITH_GHOSTSCRIPT_VER)
.	if empty(WITH_GHOSTSCRIPT_VER:M[789])
.		error You set an invalid value "${WITH_GHOSTSCRIPT_VER}" in WITH_GHOSTSCRIPT_VER.  Abort.
.	elif ${_USE_GHOSTSCRIPT_VER} != ${WITH_GHOSTSCRIPT_VER}
.		error You set WITH_GHOSTSCRIPT_VER as ${WITH_GHOSTSCRIPT_VER} but ${PKGNAME} requires print/ghostscript${_USE_GHOSTSCRIPT_VER}.  Abort.
.	endif
.endif

GHOSTSCRIPT_PORT?=	print/ghostscript${_USE_GHOSTSCRIPT_VER}${_USE_GHOSTSCRIPT_PKGNAME_SUFFIX}

# Set up the ghostscript dependencies.
.if defined(USE_GHOSTSCRIPT) || defined(USE_GHOSTSCRIPT_BUILD)
BUILD_DEPENDS+=	gs:${PORTSDIR}/${GHOSTSCRIPT_PORT}
.endif
.if defined(USE_GHOSTSCRIPT) || defined(USE_GHOSTSCRIPT_RUN)
RUN_DEPENDS+=	gs:${PORTSDIR}/${GHOSTSCRIPT_PORT}
.endif

# Macro for doing in-place file editing using regexps
REINPLACE_ARGS?=	-i.bak
REINPLACE_CMD?=	${SED} ${REINPLACE_ARGS}

# Names of cookies used to skip already completed stages
EXTRACT_COOKIE?=	${WRKDIR}/.extract_done.${PORTNAME}.${PREFIX:S/\//_/g}
CONFIGURE_COOKIE?=	${WRKDIR}/.configure_done.${PORTNAME}.${PREFIX:S/\//_/g}
INSTALL_COOKIE?=	${WRKDIR}/.install_done.${PORTNAME}.${PREFIX:S/\//_/g}
BUILD_COOKIE?=		${WRKDIR}/.build_done.${PORTNAME}.${PREFIX:S/\//_/g}
PATCH_COOKIE?=		${WRKDIR}/.patch_done.${PORTNAME}.${PREFIX:S/\//_/g}
PACKAGE_COOKIE?=	${WRKDIR}/.package_done.${PORTNAME}.${PREFIX:S/\//_/g}
STAGE_COOKIE?=		${WRKDIR}/.stage_done.${PORTNAME}.${PREFIX:S/\//_/g}

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

# Use this as the first operand to always build dependency.
NONEXISTENT?=	/nonexistent

CHECKSUM_ALGORITHMS?= sha256

DISTINFO_FILE?=		${MASTERDIR}/distinfo

MAKE_FLAGS?=	-f
MAKEFILE?=		Makefile
MAKE_CMD?=		/usr/bin/make
MAKE_ENV+=		PREFIX=${PREFIX} \
			LOCALBASE=${LOCALBASE} \
			LIBDIR="${LIBDIR}" \
			CC="${CC}" CFLAGS="${CFLAGS}" \
			CPP="${CPP}" CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
			MANPREFIX="${MANPREFIX}"

# Add -fno-strict-aliasing to CFLAGS with optimization level -O2 or higher.
# gcc 4.x enable strict aliasing optimization with -O2 which is known to break
# a lot of ports.
.if !defined(WITHOUT_NO_STRICT_ALIASING)
.if ${CC} != "icc"
.if !empty(CFLAGS:M-O[23s]) && empty(CFLAGS:M-fno-strict-aliasing)
CFLAGS+=       -fno-strict-aliasing
.endif
.endif
.endif

.if defined(USE_CSTD)
CFLAGS:=	${CFLAGS:N-std=*} -std=${USE_CSTD}
.endif

.if defined(USE_CXXSTD)
CXXFLAGS:=	${CXXFLAGS:N-std=*} -std=${USE_CXXSTD}
.endif

# Multiple make jobs support
.if defined(DISABLE_MAKE_JOBS) || defined(MAKE_JOBS_UNSAFE)
_MAKE_JOBS=		#
MAKE_JOBS_NUMBER=	1
.else
.if defined(MAKE_JOBS_NUMBER)
_MAKE_JOBS_NUMBER:=	${MAKE_JOBS_NUMBER}
.else
_MAKE_JOBS_NUMBER!=	${SYSCTL} -n kern.smp.cpus
.endif
.if defined(MAKE_JOBS_NUMBER_LIMIT) && ( ${MAKE_JOBS_NUMBER_LIMIT} < ${_MAKE_JOBS_NUMBER} )
MAKE_JOBS_NUMBER=	${MAKE_JOBS_NUMBER_LIMIT}
.else
MAKE_JOBS_NUMBER=	${_MAKE_JOBS_NUMBER}
.endif
_MAKE_JOBS?=		-j${MAKE_JOBS_NUMBER}
BUILD_FAIL_MESSAGE+=	Try to set MAKE_JOBS_UNSAFE=yes and rebuild before reporting the failure to the maintainer.
.endif

# ccache support
# Support NO_CCACHE for common setups, require WITH_CCACHE_BUILD, and
# don't use if ccache already set in CC
.if !defined(NO_CCACHE) && defined(WITH_CCACHE_BUILD) && !${CC:M*ccache*} && \
  !defined(NO_BUILD) && !defined(NOCCACHE)
# Avoid depends loops between pkg and ccache
.	if !${.CURDIR:M*/devel/ccache} && !${.CURDIR:M*/ports-mgmt/pkg}
BUILD_DEPENDS+=		${LOCALBASE}/bin/ccache:${PORTSDIR}/devel/ccache
.	endif

_CCACHE_PATH=	${LOCALBASE}/libexec/ccache

# Prepend the ccache dir into the PATH and setup ccache env
PATH:=	${_CCACHE_PATH}:${PATH}
.if !${MAKE_ENV:MPATH=*} && !${CONFIGURE_ENV:MPATH=*}
MAKE_ENV+=			PATH=${PATH}
CONFIGURE_ENV+=		PATH=${PATH}
.endif

.	if defined(CCACHE_DIR)
MAKE_ENV+=		CCACHE_DIR="${CCACHE_DIR}"
CONFIGURE_ENV+=	CCACHE_DIR="${CCACHE_DIR}"
.	endif
.endif

PTHREAD_CFLAGS?=
PTHREAD_LIBS?=		-pthread

FETCH_ENV?=		SSL_NO_VERIFY_PEER=1 SSL_NO_VERIFY_HOSTNAME=1
FETCH_BINARY?=	/usr/bin/fetch
FETCH_ARGS?=	-AFpr
FETCH_REGET?=	1
.if !defined(DISABLE_SIZE)
FETCH_BEFORE_ARGS+=	$${CKSIZE:+-S $$CKSIZE}
.endif
FETCH_CMD?=		${FETCH_BINARY} ${FETCH_ARGS}

.if defined(RANDOMIZE_MASTER_SITES)
.if exists(/usr/games/random)
RANDOM_CMD?=	/usr/games/random
RANDOM_ARGS?=	"-w -f -"
_RANDOMIZE_SITES=	" |${RANDOM_CMD} ${RANDOM_ARGS}"
.endif
.endif

TOUCH?=			/usr/bin/touch
TOUCH_FLAGS?=	-f

DISTORIG?=	.bak.orig
PATCH?=			/usr/bin/patch
PATCH_STRIP?=	-p0
PATCH_DIST_STRIP?=	-p0
.if defined(PATCH_DEBUG)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS?=	-d ${PATCH_WRKSRC} -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	--suffix ${DISTORIG} -d ${PATCH_WRKSRC} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS?=	-d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	--suffix ${DISTORIG} -d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
PATCH_DIST_ARGS+=	--batch
.endif

# Prevent breakage with VERSION_CONTROL=numbered
PATCH_ARGS+=	-V simple

.if defined(PATCH_CHECK_ONLY)
PATCH_ARGS+=	-C
PATCH_DIST_ARGS+=	-C
.endif

.if ${PATCH} == "/usr/bin/patch"
PATCH_ARGS+=	--suffix .orig
PATCH_DIST_ARGS+=	--suffix .orig
.endif

TAR?=	/usr/bin/tar

# EXTRACT_SUFX is defined in .pre.mk section
.if defined(USE_LHA)
EXTRACT_CMD?=		${LHA_CMD}
EXTRACT_BEFORE_ARGS?=	xfqw=${WRKDIR}
EXTRACT_AFTER_ARGS?=
.elif defined(USE_ZIP)
EXTRACT_CMD?=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS?=	-qo
EXTRACT_AFTER_ARGS?=	-d ${WRKDIR}
.elif defined(USE_MAKESELF)
EXTRACT_CMD?=		${UNMAKESELF_CMD}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=
.else
EXTRACT_CMD?=	${TAR}
EXTRACT_BEFORE_ARGS?=	-xf
.if defined(EXTRACT_PRESERVE_OWNERSHIP)
EXTRACT_AFTER_ARGS?=
.else
EXTRACT_AFTER_ARGS?=	--no-same-owner --no-same-permissions
.endif
.endif

# Figure out where the local mtree file is
.if !defined(MTREE_FILE) && !defined(NO_MTREE)
.if ${PREFIX} == /usr
MTREE_FILE=	/etc/mtree/BSD.usr.dist
.else
MTREE_FILE=	${PORTSDIR}/Templates/BSD.local.dist
.endif
MTREE_FILE_DEFAULT=yes
.endif
MTREE_CMD?=	/usr/sbin/mtree
MTREE_ARGS?=	-U ${MTREE_FOLLOWS_SYMLINKS} -f ${MTREE_FILE} -d -e -p

READLINK_CMD?=	/usr/bin/readlink

# Determine whether or not we can use rootly owner/group functions.
.if ${UID} == 0
_BINOWNGRP=	-o ${BINOWN} -g ${BINGRP}
_SHROWNGRP=	-o ${SHAREOWN} -g ${SHAREGRP}
_MANOWNGRP=	-o ${MANOWN} -g ${MANGRP}
.else
_BINOWNGRP=
_SHROWNGRP=
_MANOWNGRP=
.endif

# A few aliases for *-install targets
INSTALL_PROGRAM= \
	${INSTALL} ${COPY} ${STRIP} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_KLD= \
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_LIB= \
	${INSTALL} ${COPY} ${STRIP} ${_SHROWNGRP} -m ${SHAREMODE} 
INSTALL_SCRIPT= \
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_DATA= \
	${INSTALL} ${COPY} ${_SHROWNGRP} -m ${SHAREMODE}
INSTALL_MAN= \
	${INSTALL} ${COPY} ${_MANOWNGRP} -m ${MANMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			BSD_INSTALL_LIB="${INSTALL_LIB}" \
			BSD_INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			BSD_INSTALL_DATA="${INSTALL_DATA}" \
			BSD_INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=	${INSTALL_MACROS}
SCRIPTS_ENV+=	${INSTALL_MACROS}

# Macro for copying entire directory tree with correct permissions
.if ${UID} == 0
COPYTREE_BIN=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${CHOWN} -Rh ${BINOWN}:${BINGRP} $$1 && \
					${FIND} -d $$0 $$2 -type d -exec chmod 755 $$1/{} \; && \
					${FIND} -d $$0 $$2 -type f -exec chmod ${BINMODE} $$1/{} \;' --
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${CHOWN} -Rh ${SHAREOWN}:${SHAREGRP} $$1 && \
					${FIND} -d $$0 $$2 -type d -exec chmod 755 $$1/{} \; && \
					${FIND} -d $$0 $$2 -type f -exec chmod ${SHAREMODE} $$1/{} \;' --
.else
COPYTREE_BIN=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${FIND} -d $$0 $$2 -type d -exec chmod 755 $$1/{} \; && \
					${FIND} -d $$0 $$2 -type f -exec chmod ${BINMODE} $$1/{} \;' --
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${FIND} -d $$0 $$2 -type d -exec chmod 755 $$1/{} \; && \
					${FIND} -d $$0 $$2 -type f -exec chmod ${SHAREMODE} $$1/{} \;' --
.endif

# The user can override the NO_PACKAGE by specifying this from
# the make command line
.if defined(FORCE_PACKAGE)
.undef NO_PACKAGE
.endif

DESCR?=			${PKGDIR}/pkg-descr
PLIST?=			${PKGDIR}/pkg-plist
PKGHELP?=		${PKGDIR}/pkg-help
PKGINSTALL?=	${PKGDIR}/pkg-install
PKGDEINSTALL?=	${PKGDIR}/pkg-deinstall
PKGREQ?=		${PKGDIR}/pkg-req
PKGMESSAGE?=	${PKGDIR}/pkg-message

TMPPLIST?=	${WRKDIR}/.PLIST.mktmp
TMPPLIST_SORT?=	${WRKDIR}/.PLIST.mktmp.sorted
TMPGUCMD?=	${WRKDIR}/.PLIST.gucmd

.if !defined(PKG_ARGS)
PKG_ARGS=		-v -c -${COMMENT:Q} -d ${DESCR} -f ${TMPPLIST} -p ${PREFIX} -P "`cd ${.CURDIR} && ${MAKE} actual-package-depends | ${GREP} -v -E ${PKG_IGNORE_DEPENDS} | ${SORT} -u -t : -k 2`" ${EXTRA_PKG_ARGS} $${_LATE_PKG_ARGS}
.if !defined(NO_MTREE)
PKG_ARGS+=		-m ${MTREE_FILE}
.endif
.if defined(PKGORIGIN)
PKG_ARGS+=		-o ${PKGORIGIN}
.endif
.if defined(CONFLICTS) && !defined(DISABLE_CONFLICTS)
PKG_ARGS+=		-C "${CONFLICTS}"
.endif
.if defined(CONFLICTS_INSTALL) && !defined(DISABLE_CONFLICTS)
PKG_ARGS+=		-C "${CONFLICTS_INSTALL}"
.endif
.endif
.if defined(PKG_NOCOMPRESS)
PKG_SUFX?=		.tar
.else
.if defined(WITH_PKGNG)
PKG_SUFX?=		.txz
.else
PKG_SUFX?=		.tbz
.endif
.endif
# where pkg_add records its dirty deeds.
PKG_DBDIR?=		/var/db/pkg

ALL_TARGET?=		all
INSTALL_TARGET?=	install
INSTALL_TARGET+=	${LATE_INSTALL_ARGS}

# Integrate with the license auditing framework
.if !defined (DISABLE_LICENSES)
.include "${PORTSDIR}/Mk/bsd.licenses.mk"
.endif

# Popular master sites
.include "${PORTSDIR}/Mk/bsd.sites.mk"

# Empty declaration to avoid "variable MASTER_SITES recursive" error
MASTER_SITES?=
PATCH_SITES?=
_MASTER_SITES_DEFAULT?=
_PATCH_SITES_DEFAULT?=

# Feed internal _{MASTER,PATCH}_SITES_n where n is a group designation
# as per grouping rules (:something)
# Organize _{MASTER,PATCH}_SITES_{DEFAULT,[^/:]+} according to grouping
# rules (:something)
.for _S in ${MASTER_SITES}
_S_TEMP=	${_S:S/^${_S:C@/?:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
_G_TEMP=	${_group}
.			if ${_G_TEMP} == all || ${_G_TEMP} == ALL || ${_G_TEMP} == default
check-makevars::
				@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
				@${ECHO_MSG} "used in group definitions. Please fix your MASTER_SITES"
				@${FALSE}
.			endif
_MASTER_SITES_${_group}+=	${_S:C@^(.*/):[^/:]+$@\1@}
.		endfor
.	else
_MASTER_SITES_DEFAULT+=	${_S:C@^(.*/):[^/:]+$@\1@}
.	endif
.endfor
.for _S in ${PATCH_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
_G_TEMP=	${_group}
.			if ${_G_TEMP} == all || ${_G_TEMP} == ALL || ${_G_TEMP} == default
check-makevars::
				@${ECHO_MSG} "The words all, ALL and default are reserved and cannot be"
				@${ECHO_MSG} "used in group definitions. Please fix your PATCH_SITES"
				@${FALSE}
.			endif
_PATCH_SITES_${_group}+=	${_S:C@^(.*/):[^/:]+$@\1@}
.		endfor
.	else
_PATCH_SITES_DEFAULT+=	${_S:C@^(.*/):[^/:]+$@\1@}
.	endif
.endfor

# Feed internal _{MASTER,PATCH}_SITE_SUBDIR_n where n is a group designation
# as per grouping rules (:something)
# Organize _{MASTER,PATCH}_SITE_SUBDIR_{DEFAULT,[^/:]+} according to grouping
# rules (:something)
.for _S in ${MASTER_SITE_SUBDIR}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
_G_TEMP=	${_group}
.			if ${_G_TEMP} == all || ${_G_TEMP} == ALL || ${_G_TEMP} == default
check-makevars::
				@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
				@${ECHO_MSG} "used in group definitions. Please fix your MASTER_SITE_SUBDIR"
				@${FALSE}
.			endif
.			if defined(_MASTER_SITES_${_group})
_MASTER_SITE_SUBDIR_${_group}+= ${_S:C@^(.*)/:[^/:]+$@\1@}
.			endif
.		endfor
.	else
.		if defined(_MASTER_SITES_DEFAULT)
_MASTER_SITE_SUBDIR_DEFAULT+=	${_S:C@^(.*)/:[^/:]+$@\1@}
.		endif
.	endif
.endfor
.for _S in ${PATCH_SITE_SUBDIR}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
_G_TEMP=	${_group}
.			if ${_G_TEMP} == all || ${_G_TEMP} == ALL || ${_G_TEMP} == default
check-makevars::
				@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
				@${ECHO_MSG} "used in group definitions. Please fix your PATCH_SITE_SUBDIR"
				@${FALSE}
.			endif
.			if defined(_PATCH_SITES_${_group})
_PATCH_SITE_SUBDIR_${_group}+= ${_S:C@^(.*)/:[^/:]+$@\1@}
.			endif
.		endfor
.	else
.		if defined(_PATCH_SITES_DEFAULT)
_PATCH_SITE_SUBDIR_DEFAULT+=	${_S:C@^(.*)/:[^/:]+$@\1@}
.		endif
.	endif
.endfor

# Substitute subdirectory names
# XXX simpler/faster solution but not the best space wise, suggestions please
.for _S in ${MASTER_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
.			if !defined(_MASTER_SITE_SUBDIR_${_group})
MASTER_SITES_TMP=	${_MASTER_SITES_${_group}:S^%SUBDIR%/^^}
.			else
_S_TEMP_TEMP=		${_MASTER_SITES_${_group}:M*%SUBDIR%/*}
.				if empty(_S_TEMP_TEMP)
MASTER_SITES_TMP=	${_MASTER_SITES_${_group}}
.				else
MASTER_SITES_TMP=
.					for site in ${_MASTER_SITES_${_group}}
_S_TEMP_TEMP=	${site:M*%SUBDIR%/*}
.						if empty(_S_TEMP_TEMP)
MASTER_SITES_TMP+=	${site}
.						else
.							for dir in ${_MASTER_SITE_SUBDIR_${_group}}
MASTER_SITES_TMP+=	${site:S^%SUBDIR%^\${dir}^}
.							endfor
.						endif
.					endfor
.				endif
.			endif
_MASTER_SITES_${_group}:=	${MASTER_SITES_TMP}
.		endfor
.	endif
.endfor
.if defined(_MASTER_SITE_SUBDIR_DEFAULT)
_S_TEMP=	${_MASTER_SITES_DEFAULT:M*%SUBDIR%/*}
.	if empty(_S_TEMP)
MASTER_SITES_TMP=	${_MASTER_SITES_DEFAULT}
.	else
MASTER_SITES_TMP=
.		for site in ${_MASTER_SITES_DEFAULT}
_S_TEMP_TEMP=		${site:M*%SUBDIR%/*}
.			if empty(_S_TEMP_TEMP)
MASTER_SITES_TMP+=	${site}
.			else
.				for dir in ${_MASTER_SITE_SUBDIR_DEFAULT}
MASTER_SITES_TMP+=	${site:S^%SUBDIR%^\${dir}^}
.				endfor
.			endif
.		endfor
.	endif
.else
MASTER_SITES_TMP=	${_MASTER_SITES_DEFAULT:S^%SUBDIR%/^^}
.endif
_MASTER_SITES_DEFAULT:=	${MASTER_SITES_TMP}
MASTER_SITES_TMP=
.for _S in ${PATCH_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
.			if !defined(_PATCH_SITE_SUBDIR_${_group})
PATCH_SITES_TMP=	${_PATCH_SITES_${_group}:S^%SUBDIR%/^^}
.			else
_S_TEMP_TEMP=		${_PATCH_SITES_${_group}:M*%SUBDIR%/*}
.				if empty(_S_TEMP_TEMP)
PATCH_SITES_TMP=	${_PATCH_SITES_${_group}}
.				else
PATCH_SITES_TMP=
.					for site in ${_PATCH_SITES_${_group}}
_S_TEMP_TEMP=	${site:M*%SUBDIR%/*}
.						if empty(_S_TEMP_TEMP)
PATCH_SITES_TMP+=	${site}
.						else
.							for dir in ${_PATCH_SITE_SUBDIR_${_group}}
PATCH_SITES_TMP+=	${site:S^%SUBDIR%^\${dir}^}
.							endfor
.						endif
.					endfor
.				endif
.			endif
_PATCH_SITES_${_group}:=	${PATCH_SITES_TMP}
.		endfor
.	endif
.endfor
.if defined(_PATCH_SITE_SUBDIR_DEFAULT)
_S_TEMP=	${_PATCH_SITES_DEFAULT:M*%SUBDIR%/*}
.	if empty(_S_TEMP)
PATCH_SITES_TMP=	${_PATCH_SITES_DEFAULT}
.	else
PATCH_SITES_TMP=
.		for site in ${_PATCH_SITES_DEFAULT}
_S_TEMP_TEMP=		${site:M*%SUBDIR%/*}
.			if empty(_S_TEMP_TEMP)
PATCH_SITES_TMP+=	${site}
.			else
.				for dir in ${_PATCH_SITE_SUBDIR_DEFAULT}
PATCH_SITES_TMP+=	${site:S^%SUBDIR%^\${dir}^}
.				endfor
.			endif
.		endfor
.	endif
.else
PATCH_SITES_TMP=	${_PATCH_SITES_DEFAULT:S^%SUBDIR%/^^}
.endif
_PATCH_SITES_DEFAULT:=	${PATCH_SITES_TMP}
PATCH_SITES_TMP=

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP:S^\${DIST_SUBDIR}/^^}

# If the user has MASTER_SITE_FREEBSD set, go to the FreeBSD repository
# for everything, but don't search it twice by appending it to the end.
.if defined(MASTER_SITE_FREEBSD)
_MASTER_SITE_OVERRIDE:=	${MASTER_SITE_BACKUP}
_MASTER_SITE_BACKUP:=	# empty
.else
_MASTER_SITE_OVERRIDE=	${MASTER_SITE_OVERRIDE}
_MASTER_SITE_BACKUP=	${MASTER_SITE_BACKUP}
.endif

# Search CDROM first if mounted, symlink instead of copy if
# FETCH_SYMLINK_DISTFILES is set
.for MOUNTPT in ${CD_MOUNTPTS}
.if exists(${MOUNTPT}/ports/distfiles)
_MASTER_SITE_OVERRIDE:=	file:${MOUNTPT}/ports/distfiles/${DIST_SUBDIR}/ ${_MASTER_SITE_OVERRIDE}
.if defined(FETCH_SYMLINK_DISTFILES)
FETCH_BEFORE_ARGS+=	-l
.endif
.endif
.endfor

NOFETCHFILES?=

# Organize DISTFILES, PATCHFILES, _MASTER_SITES_ALL, _PATCH_SITES_ALL
# according to grouping rules (:something)
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
_MASTER_SITES_ALL=	${_MASTER_SITES_DEFAULT}
_PATCH_SITES_ALL=	${_PATCH_SITES_DEFAULT}
_G_TEMP=	DEFAULT
.for _D in ${DISTFILES}
_D_TEMP=	${_D:S/^${_D:C/:[^:]+$//}//}
.	if !empty(_D_TEMP)
.		for _group in ${_D_TEMP:S/^://:S/,/ /g}
.			if !defined(_MASTER_SITES_${_group})
_G_TEMP_TEMP=	${_G_TEMP:M/${_group}/}
.				if empty(_G_TEMP_TEMP)
_G_TEMP+=	${_group}
_MASTER_SITES_ALL+=	${_MASTER_SITES_${_group}}
.				endif
.			endif
.		endfor
_DISTFILES+=	${_D:C/:[^:]+$//}
.	else
_DISTFILES+=	${_D}
.	endif
.endfor
_G_TEMP=	DEFAULT
.for _P in ${PATCHFILES}
_P_TEMP=	${_P:C/:[^-:][^:]*$//}
_P_groups=	${_P:S/^${_P:C/:[^:]+$//}//:S/^://}
_P_file=	${_P_TEMP:C/:-[^:]+$//}
_P_strip=	${_P_TEMP:S/^${_P_TEMP:C/:-[^:]*$//}//:S/^://}
.	if !empty(_P_groups)
.		for _group in ${_P_groups:S/,/ /g}
.			if !defined(_PATCH_SITES_${_group})
_G_TEMP_TEMP=	${_G_TEMP:M/${_group}/}
.				if empty(_G_TEMP_TEMP)
_G_TEMP+=	${_group}
_PATCH_SITES_ALL+=	${_PATCH_SITES_${_group}}
.				endif
.			endif
.		endfor
.	endif
_PATCHFILES:=	${_PATCHFILES} ${_P_file}
.	if !empty(_P_strip)
_PATCH_DIST_STRIP_CASES:=	${_PATCH_DIST_STRIP_CASES} ("${_P_file}") printf %s "${_P_strip}" ;;
.	endif
.endfor
_P_groups=
_P_file=
_P_strip=
_G_TEMP=
_G_TEMP_TEMP=
ALLFILES?=	${_DISTFILES} ${_PATCHFILES}

#
# Sort the master site list according to the patterns in MASTER_SORT
#
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+=	${MASTER_SORT:S|.|\\.|g:S|^|://[^/]*|:S|$|/|}

MASTER_SORT_AWK=	BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S|\\|\\\\|g}"; }
.for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+=	/${srt:S|/|\\/|g}/ { good["${srt:S|\\|\\\\|g}"] = good["${srt:S|\\|\\\\|g}"] " " $$0 ; next; }
.endfor
MASTER_SORT_AWK+=	{ rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }

SORTED_MASTER_SITES_DEFAULT_CMD=	cd ${.CURDIR} && ${MAKE} master-sites-DEFAULT
SORTED_PATCH_SITES_DEFAULT_CMD=		cd ${.CURDIR} && ${MAKE} patch-sites-DEFAULT
SORTED_MASTER_SITES_ALL_CMD=	cd ${.CURDIR} && ${MAKE} master-sites-ALL
SORTED_PATCH_SITES_ALL_CMD=	cd ${.CURDIR} && ${MAKE} patch-sites-ALL

# has similar effect to old targets, i.e., access only {MASTER,PATCH}_SITES, not working with the new _n variables
master-sites-DEFAULT:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_MASTER_SITES_DEFAULT}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}
patch-sites-DEFAULT:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_PATCH_SITES_DEFAULT}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}

#
# Sort the master site list according to the patterns in MASTER_SORT
# according to grouping rules (:something)
#
# for use in the fetch targets
.for _S in ${MASTER_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/^://:S/,/ /g}
.			if !target(master-sites-${_group})
SORTED_MASTER_SITES_${_group}_CMD=	cd ${.CURDIR} && ${MAKE} master-sites-${_group}
master-sites-${_group}:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_MASTER_SITES_${_group}}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}
.			endif
.		endfor
.	endif
.endfor
.for _S in ${PATCH_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/^://:S/,/ /g}
.			if !target(patch-sites-${_group})
SORTED_PATCH_SITES_${_group}_CMD=	cd ${.CURDIR} && ${MAKE} patch-sites-${_group}
patch-sites-${_group}:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_PATCH_SITES_${_group}}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}
.			endif
.		endfor
.	endif
.endfor

#
# Hackery to enable simple fetch targets with several dynamic MASTER_SITES
#
_MASTER_SITES_ENV=	_MASTER_SITES_DEFAULT="${_MASTER_SITES_DEFAULT}"
.for _F in ${DISTFILES}
_F_TEMP=	${_F:S/^${_F:C/:[^:]+$//}//:S/^://}
.	if !empty(_F_TEMP)
.		for _group in ${_F_TEMP:S/,/ /g}
.			if defined(_MASTER_SITES_${_group})
_MASTER_SITES_ENV+=	_MASTER_SITES_${_group}="${_MASTER_SITES_${_group}}"
.			endif
.		endfor
.	endif
.endfor
_PATCH_SITES_ENV=	_PATCH_SITES_DEFAULT="${_PATCH_SITES_DEFAULT}"
.for _F in ${PATCHFILES}
_F_TEMP=	${_F:S/^${_F:C/:[^-:][^:]*$//}//:S/^://}
.	if !empty(_F_TEMP)
.		for _group in ${_F_TEMP:S/,/ /g}
.			if defined(_PATCH_SITES_${_group})
_PATCH_SITES_ENV+=	_PATCH_SITES_${_group}="${_PATCH_SITES_${_group}}"
.			endif
.		endfor
.	endif
.endfor

master-sites-ALL:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_MASTER_SITES_ALL}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}
patch-sites-ALL:
	@${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} '${_PATCH_SITES_ALL}' | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}

# synonyms, mnemonics
master-sites-all: master-sites-ALL
patch-sites-all: patch-sites-ALL
master-sites-default: master-sites-DEFAULT
patch-sites-default: patch-sites-DEFAULT

# compatibility with old behavior
master-sites: master-sites-DEFAULT
patch-sites: patch-sites-DEFAULT

.if defined(IGNOREFILES)
.if !defined(CKSUMFILES)
.  for _f in ${ALLFILES}
.    if ! ${IGNOREFILES:M${_f}}
CKSUMFILES+=	${_f}
.   endif
.  endfor
.  undef _f
.endif
.else
CKSUMFILES=		${ALLFILES}
.endif

# List of all files, with ${DIST_SUBDIR} in front.  Used for checksum.
.if defined(DIST_SUBDIR)
.if defined(CKSUMFILES) && ${CKSUMFILES}!=""
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
.endif
.if defined(IGNOREFILES) && ${IGNOREFILES}!=""
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
.endif
.else
_CKSUMFILES?=	${CKSUMFILES}
_IGNOREFILES?=	${IGNOREFILES}
.endif

# This is what is actually going to be extracted, and is overridable
#  by user.
EXTRACT_ONLY?=	${_DISTFILES}

.if !target(maintainer)
maintainer:
	@${ECHO_CMD} "${MAINTAINER}"
.endif

.if !target(check-makefile)
check-makefile::
	@${DO_NADA}
.endif

.if !defined(CATEGORIES)
check-categories:
	@${ECHO_MSG} "${PKGNAME}: Makefile error: CATEGORIES is mandatory."
	@${FALSE}
.else

VALID_CATEGORIES+= accessibility afterstep arabic archivers astro audio \
	benchmarks biology cad chinese comms converters databases \
	deskutils devel docs dns editors elisp emulators enlightenment finance french ftp \
	games geography german gnome gnustep graphics hamradio haskell hebrew hungarian \
	ipv6 irc japanese java kde kld korean lang linux lisp \
	mail math mbone misc multimedia net net-im net-mgmt net-p2p news \
	palm parallel pear perl5 plan9 polish portuguese ports-mgmt \
	print python ruby rubygems russian \
	scheme science security shells spanish sysutils \
	tcl textproc tk \
	ukrainian vietnamese windowmaker www \
	x11 x11-clocks x11-drivers x11-fm x11-fonts x11-servers x11-themes \
	x11-toolkits x11-wm xfce zope

check-categories:
.for cat in ${CATEGORIES}
.	if empty(VALID_CATEGORIES:M${cat})
		@${ECHO_MSG} "${PKGNAME}: Makefile error: category ${cat} not in list of valid categories."; \
		${FALSE};
.	endif
.endfor
.endif

.if !target(check-makevars)
check-makevars::
	@${DO_NADA}
.endif

.if !target(check-depends)
check-depends:
	@${DO_NADA}
.endif

PKGREPOSITORYSUBDIR?=	All
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
.if exists(${PACKAGES})
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}
.else
PKGFILE?=		${.CURDIR}/${PKGNAME}${PKG_SUFX}
.endif

# The "latest version" link -- ${PKGNAME} minus everthing after the last '-'
PKGLATESTREPOSITORY?=	${PACKAGES}/Latest
PKGBASE?=			${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
LATEST_LINK?=		${PKGBASE}
PKGLATESTFILE=		${PKGLATESTREPOSITORY}/${LATEST_LINK}${PKG_SUFX}

CONFIGURE_SCRIPT?=	configure
CONFIGURE_TARGET?=	${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_TARGET:=	${CONFIGURE_TARGET:S/--build=//}
CONFIGURE_LOG?=		config.log

# A default message to print if do-configure fails.
CONFIGURE_FAIL_MESSAGE?=	"Please report the problem to ${MAINTAINER} [maintainer] and attach the \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\" including the output of the failure of your make command. Also, it might be a good idea to provide an overview of all packages installed on your system (e.g. a ${PKG_INFO} -Ea)."

.if defined(GNU_CONFIGURE)
# Maximum command line length
.if !defined(CONFIGURE_MAX_CMD_LEN)
CONFIGURE_MAX_CMD_LEN!=	${SYSCTL} -n kern.argmax
.endif
GNU_CONFIGURE_PREFIX?=	${PREFIX}
CONFIG_SITE?=		${PORTSDIR}/Templates/config.site
CONFIGURE_ARGS+=	--prefix=${GNU_CONFIGURE_PREFIX} $${_LATE_CONFIGURE_ARGS}
CONFIGURE_ENV+=		CONFIG_SITE=${CONFIG_SITE} lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
HAS_CONFIGURE=		yes

SET_LATE_CONFIGURE_ARGS= \
     _LATE_CONFIGURE_ARGS="" ; \
	if [ ! -z "`./${CONFIGURE_SCRIPT} --help 2>&1 | ${GREP} -- '--mandir'`" ]; then \
	    _LATE_CONFIGURE_ARGS="$${_LATE_CONFIGURE_ARGS} --mandir=${MANPREFIX}/man" ; \
	fi ; \
	if [ ! -z "`./${CONFIGURE_SCRIPT} --help 2>&1 | ${GREP} -- '--infodir'`" ]; then \
	    _LATE_CONFIGURE_ARGS="$${_LATE_CONFIGURE_ARGS} --infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR}" ; \
	fi ; \
	if [ -z "`./${CONFIGURE_SCRIPT} --version 2>&1 | ${EGREP} -i '(autoconf.*2\.13|Unrecognized option)'`" ]; then \
		_LATE_CONFIGURE_ARGS="$${_LATE_CONFIGURE_ARGS} --build=${CONFIGURE_TARGET}" ; \
	else \
		_LATE_CONFIGURE_ARGS="$${_LATE_CONFIGURE_ARGS} ${CONFIGURE_TARGET}" ; \
	fi ;
.endif

# Passed to most of script invocations
SCRIPTS_ENV+=	CURDIR=${MASTERDIR} DISTDIR=${DISTDIR} \
		  WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} \
		  SCRIPTDIR=${SCRIPTDIR} FILESDIR=${FILESDIR} \
		  PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

.if defined(BATCH)
SCRIPTS_ENV+=	BATCH=yes
.endif

.if ${PREFIX} == /usr
MANPREFIX?=	/usr/share
.else
MANPREFIX?=	${PREFIX}
.endif

MANDIRS+=	${MANPREFIX}/man
.for sect in 1 2 3 4 5 6 7 8 9
MAN${sect}PREFIX?=	${MANPREFIX}
.endfor
MANLPREFIX?=	${MANPREFIX}
MANNPREFIX?=	${MANPREFIX}

MANLANG?=	""	# english only by default

.if !defined(NO_MANCOMPRESS)
MANEXT=	.gz
.endif

.if (defined(MLINKS) || defined(_MLINKS_PREPEND)) && !defined(_MLINKS)

.if defined(.PARSEDIR)
_MLINKS=	 ${_MLINKS_PREPEND} \
		 ${MANLANG:S,^,man/,:S,/"",,:@m@${MLINKS:@p@${MAN${p:E:C/(.).*/\1/g}PREFIX}/$m/man${p:E:C/(.).*/\1/g}/$p${MANEXT}@}@}
.else
__pmlinks!=	${ECHO_CMD} '${MLINKS:S/	/ /}' | ${AWK} \
 '{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ($$i ~ /^-$$/ && i != 1 && i % 2 != 0) \
			{ $$i = $$(i-2); printf " " $$i " "; } \
		else if ($$i ~ /^[^ ]+\.[1-9ln][^. ]*$$/ || $$i ~ /^\//) \
			printf " " $$i " "; \
		else \
			{ print "broken"; exit; } \
	} \
  }' | ${SED} -e 's \([^/ ][^ ]*\.\(.\)[^. ]*\) $${MAN\2PREFIX}/$$$$$$$${__lang}/man\2/\1${MANEXT}g' -e 's/ //g' -e 's/MANlPREFIX/MANLPREFIX/g' -e 's/MANnPREFIX/MANNPREFIX/g'
.if ${__pmlinks:Mbroken} == "broken"
check-makevars::
	@${ECHO_MSG} "${PKGNAME}: Makefile error: unable to parse MLINKS."
	@${FALSE}
.endif
_MLINKS=	${_MLINKS_PREPEND}

.for lang in ${MANLANG:S%^%man/%:S%^man/""$%man%}
.for ___pmlinks in ${__pmlinks}
.for __lang in ${lang}
_MLINKS+=	${___pmlinks:S// /g}
.endfor
.endfor
.endfor
.endif
.endif
_COUNT=0
.for ___tpmlinks in ${_MLINKS}
.if ${_COUNT} == "1"
_TMLINKS+=	${___tpmlinks}
_COUNT=0
.else
_COUNT=1
.endif
.endfor

.for manlang in ${MANLANG:S%^%man/%:S%^man/""$%man%}

.for sect in 1 2 3 4 5 6 7 8 9 L N
# MAN${sect} is for man pages installed for all languages in MANLANG for a given
# section.
.if defined(MAN${sect})
_MANPAGES+=	${MAN${sect}:S%^%${MAN${sect}PREFIX}/${manlang}/man${sect:L}/%}
.endif

# Language specific MAN${sect} variables are for man pages installed in that
# language, but not necessarily all languages in MANLANG.
.if defined(MAN${sect}_${manlang:S%^man/%%:U})
_MANPAGES+=	${MAN${sect}_${manlang:S%^man/%%:U}:S%^%${MAN${sect}PREFIX}/${manlang}/man${sect:L}/%}
.endif

.endfor

.endfor

# Special case for English, since it is defined with "" in MANLANG rather than
# a language name and does not have man pages installed in a lang subdirectory 
# of MAN${sect}PREFIX.
.for sect in 1 2 3 4 5 6 7 8 9 L N
.if defined(MAN${sect}_EN)
_MANPAGES+=	${MAN${sect}_EN:S%^%${MAN${sect}PREFIX}/man/man${sect:L}/%}
.endif
.endfor

.if !defined(_TMLINKS)
_TMLINKS=
.endif

.if defined(_MANPAGES)

.if defined(NO_MANCOMPRESS)
__MANPAGES:=	${_MANPAGES:S%^${PREFIX}/%%}
.else
__MANPAGES:=	${_MANPAGES:S%^${PREFIX}/%%:S%$%.gz%}
.endif

.if ${MANCOMPRESSED} == "yes"
_MANPAGES:=	${_MANPAGES:S%$%.gz%}
.endif

.endif

.if ${PREFIX} == /usr
INFO_PATH?=	share/info
.else
INFO_PATH?=	info
.endif

.if defined(INFO)
. for D in ${INFO:H}
RD:=	${D}
.  if ${RD} != "."
.   if !defined(INFO_SUBDIR)
INFO_SUBDIR:=	${RD}
.   elif ${INFO_SUBDIR} != ${RD}
BROKEN=		only one subdirectory in INFO is allowed
.   endif
.  endif
.undef RD
. endfor
.endif

DOCSDIR_REL?=	${DOCSDIR:S,^${PREFIX}/,,}
EXAMPLESDIR_REL?=	${EXAMPLESDIR:S,^${PREFIX}/,,}
DATADIR_REL?=	${DATADIR:S,^${PREFIX}/,,}
WWWDIR_REL?=	${WWWDIR:S,^${PREFIX}/,,}
ETCDIR_REL?=	${ETCDIR:S,^${PREFIX}/,,}

PLIST_SUB+=	DOCSDIR="${DOCSDIR_REL}" \
		EXAMPLESDIR="${EXAMPLESDIR_REL}" \
		DATADIR="${DATADIR_REL}" \
		WWWDIR="${WWWDIR_REL}" \
		ETCDIR="${ETCDIR_REL}"

DESKTOPDIR?=		${PREFIX}/share/applications
_DESKTOPDIR_REL=	${DESKTOPDIR:S,^${PREFIX}/,,}/

.if ${_DESKTOPDIR_REL} == ${DESKTOPDIR}/
# DESKTOPDIR is not beneath PREFIX
_DESKTOPDIR_REL=
.endif

.MAIN: all

################################################################
# Many ways to disable a port.
#
# If we're in BATCH mode and the port is interactive, or we're
# in interactive mode and the port is non-interactive, skip all
# the important targets.  The reason we have two modes is that
# one might want to leave a build in BATCH mode running
# overnight, then come back in the morning and do _only_ the
# interactive ones that required your intervention.
#
# Ignore ports that can't be resold if building for a CDROM.
#
# Don't build a port if it's restricted and we don't want to get
# into that.
#
# Don't build a port if it's broken, unless we're running a parallel
# build (in case it's fixed).
#
# Don't build a port if it's forbidden for whatever reason.
#
# Don't build a port if the system is too old.
################################################################

# Check the machine architectures
.if defined(ONLY_FOR_ARCHS)
.for __ARCH in ${ONLY_FOR_ARCHS}
.if ${ARCH:M${__ARCH}} != ""
__ARCH_OK?=		1
.endif
.endfor
.else
__ARCH_OK?=		1
.endif

.if defined(NOT_FOR_ARCHS)
.for __NARCH in ${NOT_FOR_ARCHS}
.if ${ARCH:M${__NARCH}} != ""
.undef __ARCH_OK
.endif
.endfor
.endif

.if !defined(__ARCH_OK)
.if defined(ONLY_FOR_ARCHS)
IGNORE=		is only for ${ONLY_FOR_ARCHS},
.else # defined(NOT_FOR_ARCHS)
IGNORE=		does not run on ${NOT_FOR_ARCHS},
.endif
IGNORE+=	while you are running ${ARCH}

.if defined(ONLY_FOR_ARCHS_REASON_${ARCH})
IGNORE+=	(reason: ${ONLY_FOR_ARCHS_REASON_${ARCH}})
.elif defined(ONLY_FOR_ARCHS_REASON)
IGNORE+=	(reason: ${ONLY_FOR_ARCHS_REASON})
.endif

.if defined(NOT_FOR_ARCHS_REASON_${ARCH})
IGNORE+=	(reason: ${NOT_FOR_ARCHS_REASON_${ARCH}})
.elif defined(NOT_FOR_ARCHS_REASON)
IGNORE+=	(reason: ${NOT_FOR_ARCHS_REASON})
.endif

.endif

# Check the user interaction and legal issues
.if !defined(NO_IGNORE)
.if (defined(IS_INTERACTIVE) && defined(BATCH))
IGNORE=		is an interactive port
.elif (!defined(IS_INTERACTIVE) && defined(INTERACTIVE))
IGNORE=		is not an interactive port
.elif (defined(NO_CDROM) && defined(FOR_CDROM))
IGNORE=		may not be placed on a CDROM: ${NO_CDROM}
.elif (defined(RESTRICTED) && defined(NO_RESTRICTED))
IGNORE=		is restricted: ${RESTRICTED}
.elif defined(BROKEN)
.if !defined(TRYBROKEN)
IGNORE=		is marked as broken: ${BROKEN}
.endif
.elif defined(BROKEN_${ARCH})
.if !defined(TRYBROKEN)
IGNORE=		is marked as broken on ${ARCH}: ${BROKEN_${ARCH}}
.endif
.elif defined(FORBIDDEN)
IGNORE=		is forbidden: ${FORBIDDEN}
.endif

.if (defined(MANUAL_PACKAGE_BUILD) && defined(PACKAGE_BUILDING))
IGNORE=		has to be built manually: ${MANUAL_PACKAGE_BUILD}
clean:
	@${IGNORECMD}
.endif

.if defined(IGNORE)
.if defined(IGNORE_SILENT)
IGNORECMD=	${DO_NADA}
.else
IGNORECMD=	${ECHO_MSG} "===>  ${PKGNAME} "${IGNORE:Q}.;exit 1
.endif

.if !defined(NO_STAGE)
_TARGETS=	check-sanity fetch checksum extract patch configure all build stage restage install reinstall package
.else
_TARGETS=	check-sanity fetch checksum extract patch configure all build install reinstall package
.endif
.for target in ${_TARGETS}
.if !target(${target})
${target}:
	@${IGNORECMD}
.if defined(INSTALLS_DEPENDS)
	@${FALSE}
.endif
.endif
.endfor

.endif

.endif

.if defined(IGNORE) || defined(NO_PACKAGE)
ignorelist: package-name
.else
ignorelist:
	@${DO_NADA}
.endif

.if defined(IGNORE) || defined(NO_PACKAGE)
ignorelist-verbose:
.if defined(IGNORE)
	@${ECHO_CMD} "${PKGNAME}|IGNORE: "${IGNORE:Q}
.else
	@${ECHO_CMD} "${PKGNAME}|NO_PACKAGE: "${NO_PACKAGE:Q}
.endif
.else
ignorelist-verbose:
	@${DO_NADA}
.endif

################################################################
# Clean directories for ftp or CDROM.
################################################################

.if !defined(LICENSE)

.if defined(RESTRICTED)
clean-restricted:	delete-distfiles delete-package
clean-restricted-list: delete-distfiles-list delete-package-list
RESTRICTED_FILES?=	${_DISTFILES} ${_PATCHFILES}
.else
clean-restricted:
clean-restricted-list:
.endif

.if defined(NO_CDROM)
clean-for-cdrom:	delete-distfiles delete-package
clean-for-cdrom-list:	delete-distfiles-list delete-package-list
RESTRICTED_FILES?=	${_DISTFILES} ${_PATCHFILES}
.else
clean-for-cdrom:
clean-for-cdrom-list:
.endif

.endif # !defined(LICENSE)

.if defined(ALL_HOOK)
all:
	@cd ${.CURDIR} && ${SETENV} CURDIR=${.CURDIR} DISTNAME=${DISTNAME} \
	  DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} \
	  PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	  FILESDIR=${FILESDIR} PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} \
	  BUILD_DEPENDS="${BUILD_DEPENDS}" RUN_DEPENDS="${RUN_DEPENDS}" \
	  CONFLICTS="${CONFLICTS}" \
	${ALL_HOOK}
.endif

.if !target(all)
all: build
.endif

.if !defined(DEPENDS_TARGET)
.if defined(DEPENDS_PRECLEAN)
DEPENDS_TARGET=	clean
DEPENDS_ARGS=	NOCLEANDEPENDS=yes
.endif
.if make(reinstall)
DEPENDS_TARGET+=	reinstall
.else
DEPENDS_TARGET+=	install
.endif
.if defined(DEPENDS_CLEAN)
DEPENDS_TARGET+=	clean
DEPENDS_ARGS+=	NOCLEANDEPENDS=yes
.endif
.endif

################################################################
#
# Do preliminary work to detect if we need to run the config
# target or not.
#
################################################################
.if ((!defined(OPTIONS_DEFINE) && !defined(OPTIONS_SINGLE) && !defined(OPTIONS_MULTI)) \
	&& !defined(OPTIONS_GROUP) && !defined(OPTIONS_RADIO) \
	|| defined(CONFIG_DONE_${UNIQUENAME:U}) || \
	defined(PACKAGE_BUILDING) || defined(BATCH))
_OPTIONS_OK=yes
.endif

################################################################
# The following are used to create easy dummy targets for
# disabling some bit of default target behavior you don't want.
# They still check to see if the target exists, and if so don't
# do anything, since you might want to set this globally for a
# group of ports in a Makefile.inc, but still be able to
# override from an individual Makefile.
################################################################

# Disable checksum
.if defined(NO_CHECKSUM) && !target(checksum)
checksum: fetch
	@${DO_NADA}
.endif

# Disable build
.if defined(NO_BUILD) && !target(build)
build: configure
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.endif

# Disable install
.if defined(NO_INSTALL) && !target(do-install)
do-install:
	@${DO_NADA}
.endif

# Disable package
.if defined(NO_PACKAGE) && !target(package)
package:
.if defined(IGNORE_SILENT)
	@${DO_NADA}
.else
	@${ECHO_MSG} "===>  ${PKGNAME} may not be packaged: "${NO_PACKAGE:Q}.
.endif
.endif

# Disable describe
.if defined(NO_DESCRIBE) && !target(describe)
describe:
	@${DO_NADA}
.endif

################################################################
# More standard targets start here.
#
# These are the body of the build/install framework.  If you are
# not happy with the default actions, and you can't solve it by
# adding pre-* or post-* targets/scripts, override these.
################################################################

# Pre-everything

pre-everything::
	@${DO_NADA}

buildanyway-message:
.if defined(TRYBROKEN) && defined(BROKEN)
	@${ECHO_MSG} "Trying build of ${PKGNAME} even though it is marked BROKEN."
.else
	@${DO_NADA}
.endif

options-message:
.if defined(GNOME_OPTION_MSG) && (!defined(PACKAGE_BUILDING) || !defined(BATCH))
	@for m in ${GNOME_OPTION_MSG}; do \
		${ECHO_MSG} $$m; \
	done
.else
	@${DO_NADA}
.endif
.if defined(_OPTIONS_READ)
	@${ECHO_MSG} "===>  Found saved configuration for ${_OPTIONS_READ}"
.endif


# Warn user about deprecated packages.  Advisory only.

.if !target(check-deprecated)
check-deprecated:
.if defined(DEPRECATED)
	@${ECHO_MSG} "===>   NOTICE:"
	@${ECHO_MSG}
	@${ECHO_MSG} "This port is deprecated; you may wish to reconsider installing it:"
	@${ECHO_MSG}
	@${ECHO_MSG} ${DEPRECATED:Q}.
	@${ECHO_MSG}
.if defined(EXPIRATION_DATE)
	@${ECHO_MSG} "It is scheduled to be removed on or after ${EXPIRATION_DATE}."
	@${ECHO_MSG}
.endif
.endif
.endif

# Check if the port is listed in the vulnerability database

.if defined(WITH_PKGNG)
AUDITFILE?=		${PKG_DBDIR}/auditfile
_EXTRACT_AUDITFILE=	${CAT} "${AUDITFILE}"
.else
AUDITFILE?=		/var/db/portaudit/auditfile.tbz
_EXTRACT_AUDITFILE=	${TAR} -jxOf "${AUDITFILE}" auditfile
.endif

check-vulnerable:
.if !defined(DISABLE_VULNERABILITIES) && !defined(PACKAGE_BUILDING)
	@if [ -f "${AUDITFILE}" ]; then \
		if [ -n "${WITH_PKGNG}" ]; then \
			if [ -x "${PKG_BIN}" ]; then \
				vlist=`${PKG_BIN} audit "${PKGNAME}"`; \
			elif [ "${PORTNAME}" = "pkg" ]; then \
				vlist=""; \
			else \
				${ECHO_MSG} "===> Unable to check vuln database as pkg(8) is missing"; \
				exit 1; \
			fi; \
		elif [ -x "${LOCALBASE}/sbin/portaudit" ]; then \
			vlist=`${LOCALBASE}/sbin/portaudit -X 14 "${PKGNAME}" \
				2>&1 | grep -vE '^[0-9]+ problem\(s\) found.' \
				|| true`; \
		else \
			${ECHO_MSG} "===>  portaudit database exists, however, portaudit is not installed!"; \
		fi; \
		if [ -n "$$vlist" ]; then \
			${ECHO_MSG} "===>  ${PKGNAME} has known vulnerabilities:"; \
			${ECHO_MSG} "$$vlist"; \
			${ECHO_MSG} "=> Please update your ports tree and try again."; \
			exit 1; \
		fi; \
	fi
.endif

# set alg to any of SIZE, SHA256 (or any other checksum algorithm):
DISTINFO_DATA?=	if [ \( -n "${DISABLE_SIZE}" -a -n "${NO_CHECKSUM}" \) -o ! -f "${DISTINFO_FILE}" ]; then exit; fi; \
	DIR=${DIST_SUBDIR}; ${AWK} -v alg=$$alg -v file=$${DIR:+$$DIR/}$${file}	\
		'$$1 == alg && $$2 == "(" file ")" {print $$4}' ${DISTINFO_FILE}

# Fetch

.if !target(do-fetch)
do-fetch:
	@${MKDIR} ${_DISTDIR}
	@cd ${_DISTDIR};\
	${_MASTER_SITES_ENV} ; \
	for _file in ${DISTFILES}; do \
		file=$${_file%%:*}; \
		if [ $$_file = $$file ]; then	\
			select='';	\
		else	\
			select=`${ECHO_CMD} $${_file##*:} | ${SED} -e 's/,/ /g'` ;	\
		fi;	\
		force_fetch=false; \
		filebasename=$${file##*/}; \
		for afile in ${FORCE_FETCH}; do \
			afile=$${afile##*/}; \
			if [ "x$$afile" = "x$$filebasename" ]; then \
				force_fetch=true; \
			fi; \
		done; \
		if [ ! -f $$file -a ! -f $$filebasename -o "$$force_fetch" = "true" ]; then \
			if [ -L $$file -o -L $$filebasename ]; then \
				${ECHO_MSG} "=> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} "=> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} "=> Please correct this problem and try again."; \
				exit 1; \
			fi; \
			if [ -f ${DISTINFO_FILE} -a "x${NO_CHECKSUM}" = "x" ]; then \
				_sha256sum=`alg=SHA256; ${DISTINFO_DATA}`; \
				if [ -z "$$_sha256sum" ]; then \
					${ECHO_MSG} "=> $${DIR:+$$DIR/}$$file is not in ${DISTINFO_FILE}."; \
					${ECHO_MSG} "=> Either ${DISTINFO_FILE} is out of date, or"; \
					${ECHO_MSG} "=> $${DIR:+$$DIR/}$$file is spelled incorrectly."; \
					exit 1; \
				fi; \
			fi; \
			${ECHO_MSG} "=> $$file doesn't seem to exist in ${_DISTDIR}."; \
			if [ ! -w ${DISTDIR} ]; then \
			   ${ECHO_MSG} "=> ${DISTDIR} is not writable by you; cannot fetch."; \
			   exit 1; \
			fi; \
			if [ ! -z "$$select" ] ; then \
				__MASTER_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_MASTER_SITES_$${group}} ] ; then \
						eval ___MASTER_SITES_TMP="\$${_MASTER_SITES_$${group}}" ; \
						__MASTER_SITES_TMP="$${__MASTER_SITES_TMP} $${___MASTER_SITES_TMP}" ; \
					fi; \
				done; \
				___MASTER_SITES_TMP= ; \
				SORTED_MASTER_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__MASTER_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_MASTER_SITES_CMD_TMP="${SORTED_MASTER_SITES_DEFAULT_CMD}" ; \
			fi; \
			sites_remaining=0; \
			sites="`eval $$SORTED_MASTER_SITES_CMD_TMP ${_RANDOMIZE_SITES}`"; \
			for site in $${sites}; do \
				sites_remaining=$$(($${sites_remaining} + 1)); \
			done; \
			for site in $${sites}; do \
				sites_remaining=$$(($${sites_remaining} - 1)); \
			    ${ECHO_MSG} "=> Attempting to fetch $${site}$${file}"; \
				CKSIZE=`alg=SIZE; ${DISTINFO_DATA}`; \
				case $${file} in \
				*/*)	${MKDIR} $${file%/*}; \
						args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} ${FETCH_AFTER_ARGS}; then \
					actual_size=`stat -f %z "$${file}"`; \
					if [ -n "${DISABLE_SIZE}" ] || [ -z "$${CKSIZE}" ] || [ $${actual_size} -eq $${CKSIZE} ]; then \
						continue 2; \
					else \
						${ECHO_MSG} "=> Fetched file size mismatch (expected $${CKSIZE}, actual $${actual_size})"; \
						if [ $${sites_remaining} -gt 1 ]; then \
							${ECHO_MSG} "=> Trying next site"; \
							${RM} -f $${file}; \
						fi; \
					fi; \
				fi; \
			done; \
			${ECHO_MSG} "=> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} "=> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
	    fi; \
	 done
.if defined(PATCHFILES)
	@cd ${_DISTDIR};\
	${_PATCH_SITES_ENV} ; \
	for _file in ${PATCHFILES}; do \
		file=`${ECHO_CMD} $$_file | ${SED} -E -e 's/:[^-:][^:]*$$//'` ; \
		select=`${ECHO_CMD} $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		file=`${ECHO_CMD} $$file | ${SED} -E -e 's/:-[^:]+$$//'` ; \
		force_fetch=false; \
		filebasename=$${file##*/}; \
		for afile in ${FORCE_FETCH}; do \
			afile=$${afile##*/}; \
			if [ "x$$afile" = "x$$filebasename" ]; then \
				force_fetch=true; \
			fi; \
		done; \
		if [ ! -f $$file -a ! -f $$filebasename -o "$$force_fetch" = "true" ]; then \
			if [ -L $$file -o -L $${file##*/} ]; then \
				${ECHO_MSG} "=> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} "=> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} "=> Please correct this problem and try again."; \
				exit 1; \
			fi; \
			${ECHO_MSG} "=> $$file doesn't seem to exist in ${_DISTDIR}."; \
			if [ ! -z "$$select" ] ; then \
				__PATCH_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_PATCH_SITES_$${group}} ] ; then \
						eval ___PATCH_SITES_TMP="\$${_PATCH_SITES_$${group}}" ; \
						__PATCH_SITES_TMP="$${__PATCH_SITES_TMP} $${___PATCH_SITES_TMP}" ; \
					fi; \
				done; \
				___PATCH_SITES_TMP= ; \
				SORTED_PATCH_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__PATCH_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_PATCH_SITES_CMD_TMP="${SORTED_PATCH_SITES_DEFAULT_CMD}" ; \
			fi; \
			sites_remaining=0; \
			sites="`eval $$SORTED_PATCH_SITES_CMD_TMP`"; \
			for site in $${sites}; do \
				sites_remaining=$$(($${sites_remaining} + 1)); \
			done; \
			for site in $${sites}; do \
				sites_remaining=$$(($${sites_remaining} - 1)); \
			    ${ECHO_MSG} "=> Attempting to fetch $${site}$${file}"; \
				CKSIZE=`alg=SIZE; ${DISTINFO_DATA}`; \
				case $${file} in \
				*/*)	${MKDIR} $${file%/*}; \
						args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} ${FETCH_AFTER_ARGS}; then \
					actual_size=`stat -f %z "$${file}"`; \
					if [ -n "${DISABLE_SIZE}" ] || [ -z "$${CKSIZE}" ] || [ $${actual_size} -eq $${CKSIZE} ]; then \
						continue 2; \
					else \
						${ECHO_MSG} "=> Fetched file size mismatch (expected $${CKSIZE}, actual $${actual_size})"; \
						if [ $${sites_remaining} -gt 1 ]; then \
							${ECHO_MSG} "=> Trying next site"; \
							${RM} -f $${file}; \
						fi; \
					fi; \
				fi; \
			done; \
			${ECHO_MSG} "=> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} "=> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
		fi; \
	 done
.endif
.endif

# Extract

.if !target(do-extract)
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi; \
	done
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ ${UID} = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif
.endif

# Patch

.if !target(patch-dos2unix)
patch-dos2unix:
.if defined(USE_DOS2UNIX)
.if ${USE_DOS2UNIX:U}=="YES"
	@${ECHO_MSG} "===>   Converting DOS text files to UNIX text files"
	@${FIND} -E ${WRKSRC} -type f -iregex '${DOS2UNIX_REGEX}' -print0 | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -e 's/$$//'
.else
.if ${USE_DOS2UNIX:M*/*}
.for f in ${USE_DOS2UNIX}
	@${ECHO_MSG} "===>   Converting DOS text file to UNIX text file: ${f}"
	@${REINPLACE_CMD} -i '' -e 's/$$//' ${WRKSRC}/${f}
.endfor
.else
.for f in ${USE_DOS2UNIX}
	@${FIND} ${WRKSRC} -type f -name '${f}' -print0 | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -e 's/$$//'
.endfor
.endif
.endif
.else
	@${DO_NADA}
.endif
.endif

.if !target(do-patch)
do-patch:
.if defined(PATCHFILES)
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
	patch_dist_strip () { \
		case "$$1" in \
		${_PATCH_DIST_STRIP_CASES} \
		esac; \
	}; \
	for i in ${_PATCHFILES}; do \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch $$i" ; \
		fi ; \
		case $$i in \
		*.Z|*.gz) ${GZCAT} $$i ;; \
		*.bz2) ${BZCAT} $$i ;; \
		*.xz) ${XZCAT} $$i ;; \
		*) ${CAT} $$i ;; \
		esac | ${PATCH} ${PATCH_DIST_ARGS} `patch_dist_strip $$i` ; \
	done )
.endif
.if defined(EXTRA_PATCHES)
	@set -e ; \
	for i in ${EXTRA_PATCHES}; do \
		${ECHO_MSG} "===>  Applying extra patch $$i" ; \
		case $$i in \
		*.Z|*.gz) ${GZCAT} $$i ;; \
		*.bz2) ${BZCAT} $$i ;; \
		*.xz) ${XZCAT} $$i ;; \
		*) ${CAT} $$i ;; \
		esac | ${PATCH} ${PATCH_ARGS} ; \
	done
.endif
	@set -e ;\
	if [ -d ${PATCHDIR} ]; then \
		if [ "`${ECHO_CMD} ${PATCHDIR}/patch-*`" != "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "===>  Applying ${OPSYS} patches for ${PKGNAME}" ; \
			PATCHES_APPLIED="" ; \
			for i in ${PATCHDIR}/patch-*; do \
				case $$i in \
					*.orig|*.rej|*~|*,v) \
						${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
						;; \
					*) \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
						fi; \
						if ${PATCH} ${PATCH_ARGS} < $$i ; then \
							PATCHES_APPLIED="$$PATCHES_APPLIED $$i" ; \
						else \
							${ECHO_MSG} `${ECHO_CMD} "=> Patch $$i failed to apply cleanly." | ${SED} "s|${PATCHDIR}/||"` ; \
							if [ x"$$PATCHES_APPLIED" != x"" ]; then \
								${ECHO_MSG} `${ECHO_CMD} "=> Patch(es) $$PATCHES_APPLIED applied cleanly." | ${SED} "s|${PATCHDIR}/||g"` ; \
							fi; \
							${FALSE} ; \
						fi; \
						;; \
				esac; \
			done; \
		fi; \
	fi
.endif

.if !target(run-autotools-fixup)
run-autotools-fixup:
# Work around an issue where FreeBSD 10.0 is detected as FreeBSD 1.x.
.if ${OSVERSION} >= 1000000 && !defined(WITHOUT_FBSD10_FIX)
	-@for f in `${FIND} ${WRKDIR} -type f \( -name config.libpath -o \
		-name config.rpath -o -name configure -o -name libtool.m4 -o \
		-name ltconfig -o -name libtool -o -name aclocal.m4 -o \
		-name acinclude.m4 \)` ; do \
			${SED} -i.fbsd10bak \
				-e 's|freebsd1\*)|freebsd1.\*)|g' \
				-e 's|freebsd\[12\]\*)|freebsd[12].*)|g' \
				-e 's|freebsd\[123\]\*)|freebsd[123].*)|g' \
				-e 's|freebsd\[\[12\]\]\*)|freebsd[[12]].*)|g' \
				-e 's|freebsd\[\[123\]\]\*)|freebsd[[123]].*)|g' \
					$${f} ; \
			${TOUCH} ${TOUCH_FLAGS} -mr $${f}.fbsd10bak $${f} ; \
			${RM} -f $${f}.fbsd10bak ; \
			${ECHO_MSG} "===>   FreeBSD 10 autotools fix applied to $${f}"; \
		done
.endif
.endif

.if !target(configure-autotools)
configure-autotools:
	@${DO_NADA}
.endif

.if !target(run-autotools)
run-autotools:
	@${DO_NADA}
.endif

# Configure

.if !target(do-configure)
do-configure:
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		  ${SCRIPTDIR}/configure; \
	fi
.if defined(GNU_CONFIGURE)
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
	    ${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done
.endif
.if defined(HAS_CONFIGURE)
	@(cd ${CONFIGURE_WRKSRC} && \
	    ${SET_LATE_CONFIGURE_ARGS} \
		if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    LDFLAGS="${LDFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)
.endif
.endif

# Build

.if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly."; \
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT} 75 79 ; \
			fi; \
		${FALSE}; \
		fi)
.endif

# Check conflicts

.if !target(check-conflicts)
check-conflicts: check-build-conflicts check-install-conflicts
.endif

.if !target(check-build-conflicts)
check-build-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_BUILD) ) && !defined(DISABLE_CONFLICTS) && !defined(DEFER_CONFLICTS_CHECK)
	@found=`${PKG_INFO} -I ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`; \
	conflicts_with=; \
	for entry in $${found}; do \
		if ${PKG_INFO} -e $${entry} ; then \
			prfx=`${PKG_INFO} -q -p "$${entry}" 2> /dev/null | ${SED} -ne '1s/^@cwd //p'`; \
			orgn=`${PKG_INFO} -q -o "$${entry}" 2> /dev/null`; \
			if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
				conflicts_with="$${conflicts_with} $${entry}"; \
			fi; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They will not build together."; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.endif
.endif

.if !target(identify-install-conflicts)
identify-install-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_INSTALL) ) && !defined(DISABLE_CONFLICTS)
	@found=`${PKG_INFO} -I ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`; \
	conflicts_with=; \
	for entry in $${found}; do \
		if ${PKG_INFO} -e $${entry} ; then \
			prfx=`${PKG_INFO} -q -p "$${entry}" 2> /dev/null | ${SED} -ne '1s/^@cwd //p'`; \
			orgn=`${PKG_INFO} -q -o "$${entry}" 2> /dev/null`; \
			if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
				conflicts_with="$${conflicts_with} $${entry}"; \
			fi; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      You may want to stop build with Ctrl + C."; \
		sleep 10; \
	fi
.endif
.endif

.if !target(check-install-conflicts)
check-install-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_INSTALL) || ( defined(CONFLICTS_BUILD) && defined(DEFER_CONFLICTS_CHECK) ) ) && !defined(DISABLE_CONFLICTS) 
.if defined(DEFER_CONFLICTS_CHECK)
	@found=`${PKG_INFO} -I ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`; \
	conflicts_with=; \
	for entry in $${found}; do \
		if ${PKG_INFO} -e $${entry} ; then \
			prfx=`${PKG_INFO} -q -p "$${entry}" 2> /dev/null | ${SED} -ne '1s/^@cwd //p'`; \
			orgn=`${PKG_INFO} -q -o "$${entry}" 2> /dev/null`; \
			if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
				conflicts_with="$${conflicts_with} $${entry}"; \
			fi; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.else
	@found=`${PKG_INFO} -I ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`; \
	conflicts_with=; \
	for entry in $${found}; do \
		if ${PKG_INFO} -e $${entry} ; then \
			prfx=`${PKG_INFO} -q -p "$${entry}" 2> /dev/null | ${SED} -ne '1s/^@cwd //p'`; \
			orgn=`${PKG_INFO} -q -o "$${entry}" 2> /dev/null`; \
			if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
				conflicts_with="$${conflicts_with} $${entry}"; \
			fi; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.endif # defined(DEFER_CONFLICTS_CHECK)
.endif
.endif

# Install

.if !target(do-install)
do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

# Package

.if !target(do-package)
do-package: ${TMPPLIST}
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} "=> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi
.if defined(NO_STAGE)
	@if ${PKG_CMD} -b ${PKGNAME} ${PKGFILE}; then \
		if [ -d ${PACKAGES} ]; then \
			cd ${.CURDIR} && eval ${MAKE} package-links; \
		fi; \
	else \
		cd ${.CURDIR} && eval ${MAKE} delete-package; \
		exit 1; \
	fi
.else
	@_LATE_PKG_ARGS=""; \
	if [ -f ${PKGINSTALL} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -i ${PKGINSTALL}"; \
	fi; \
	if [ -f ${PKGDEINSTALL} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -k ${PKGDEINSTALL}"; \
	fi; \
	if [ -f ${PKGREQ} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -r ${PKGREQ}"; \
	fi; \
	if [ -f ${PKGMESSAGE} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -D ${PKGMESSAGE}"; \
	fi; \
	if ${PKG_CMD} -S ${STAGEDIR} ${PKG_ARGS} ${WRKDIR}/${PKGNAME}${PKG_SUFX}; then \
		if [ -d ${PACKAGES} -a -w ${PACKAGES} ]; then \
			${LN} -f ${WRKDIR}/${PKGNAME}${PKG_SUFX} ${PKGFILE} 2>/dev/null || \
			    ${CP} -af ${WRKDIR}/${PKGNAME}${PKG_SUFX} ${PKGFILE}; \
			cd ${.CURDIR} && eval ${MAKE} package-links; \
		fi; \
	else \
		cd ${.CURDIR} && eval ${MAKE} delete-package; \
		exit 1; \
	fi
.endif
.endif

# Some support rules for do-package

.if !target(package-links)
package-links: delete-package-links
	@for cat in ${CATEGORIES}; do \
		if [ ! -d ${PACKAGES}/$$cat ]; then \
			if ! ${MKDIR} ${PACKAGES}/$$cat; then \
				${ECHO_MSG} "=> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1; \
			fi; \
		fi; \
		${LN} -sf `${ECHO_CMD} $$cat | ${SED} -e 'sa[^/]*a..ag'`/${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done
.if !defined(NO_LATEST_LINK)
	@if [ ! -d ${PKGLATESTREPOSITORY} ]; then \
		if ! ${MKDIR} ${PKGLATESTREPOSITORY}; then \
			${ECHO_MSG} "=> Can't create directory ${PKGLATESTREPOSITORY}."; \
			exit 1; \
		fi; \
	fi
	@${LN} -s ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PKGLATESTFILE}
.endif
.endif

.if !target(delete-package-links)
delete-package-links:
	@for cat in ${CATEGORIES}; do \
		${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
	done
.if !defined(NO_LATEST_LINK)
	@${RM} -f ${PKGLATESTFILE}
.endif
.endif

.if !target(delete-package)
delete-package: delete-package-links
.	if defined(NO_STAGE)
	@${RM} -f ${PKGFILE}
.	else
# When staging, the package may only be in the workdir if not root
	@${RM} -f ${PKGFILE} ${WRKDIR}/${PKGNAME}${PKG_SUFX} 2>/dev/null || :
.	endif
.endif

.if !target(delete-package-links-list)
delete-package-links-list:
	@for cat in ${CATEGORIES}; do \
		${ECHO_CMD} ${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
	done
.if !defined(NO_LATEST_LINK)
	@${ECHO_CMD} ${RM} -f ${PKGLATESTFILE}
.endif
.endif

.if !target(delete-package-list)
delete-package-list: delete-package-links-list
	@${ECHO_CMD} "[ -f ${PKGFILE} ] && (${ECHO_CMD} deleting ${PKGFILE}; ${RM} -f ${PKGFILE})"
.endif

# Only used if !defined(NO_STAGE)
.if !target(install-package)
install-package:
.if defined(FORCE_PKG_REGISTER)
	@${PKG_ADD} -f ${WRKDIR}/${PKGNAME}${PKG_SUFX}
.else
	@${PKG_ADD} ${WRKDIR}/${PKGNAME}${PKG_SUFX}
.endif
.endif


# Utility targets follow

.if !target(check-already-installed)
check-already-installed: ${TMPPLIST_SORT}
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
		@${ECHO_MSG} "===>  Checking if ${PKGORIGIN} already installed"; \
		${MKDIR} ${PKG_DBDIR}; \
		already_installed=`${PKG_INFO} -q -O ${PKGORIGIN}`; \
		if [ -n "$${already_installed}" ]; then \
				for p in $${already_installed}; do \
						prfx=`${PKG_INFO} -q -p $${p} 2> /dev/null | ${SED} -ne '1s|^@cwd ||p'`; \
						if [ "x${PREFIX}" = "x$${prfx}" ]; then \
								df=`${PKG_INFO} -q -f $${p} 2> /dev/null | ${GREP} -v "^@" | ${SORT} -u | ${COMM} -12 - ${TMPPLIST_SORT}`; \
								if [ -n "$${df}" ]; then \
										found_package=$${p}; \
										break; \
								fi; \
						fi; \
				done; \
		fi; \
		if [ -d ${PKG_DBDIR}/${PKGNAME} -o -n "$${found_package}" ]; then \
				if [ -d ${PKG_DBDIR}/${PKGNAME} ]; then \
					${ECHO_CMD} "===>   ${PKGNAME} is already installed"; \
				else \
					${ECHO_CMD} "===>   An older version of ${PKGORIGIN} is already installed ($${found_package})"; \
				fi; \
				${ECHO_MSG} "      You may wish to \`\`make deinstall'' and install this port again"; \
				${ECHO_MSG} "      by \`\`make reinstall'' to upgrade it properly."; \
				${ECHO_MSG} "      If you really wish to overwrite the old port of ${PKGORIGIN}"; \
				${ECHO_MSG} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
				${ECHO_MSG} "      in your environment or the \"make install\" command line."; \
				exit 1; \
		fi
.else
	@${DO_NADA}
.endif
.endif

.if !target(check-umask)
check-umask:
	@if [ `${SH} -c umask` != 0022 ]; then \
		${ECHO_MSG} "===>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "      If this is not desired, set it to an appropriate value"; \
		${ECHO_MSG} "      and install this port again by \`\`make reinstall''."; \
	fi
.endif

.if !target(install-mtree)
install-mtree:
	@${MKDIR} ${PREFIX}
	@if [ ${UID} != 0 ]; then \
		if [ -w ${PREFIX}/ ]; then \
			${ECHO_MSG} "Warning: not superuser, you may get some errors during installation."; \
		else \
			${ECHO_MSG} "Error: ${PREFIX}/ not writable."; \
			${FALSE}; \
		fi; \
	fi
.if !defined(NO_MTREE)
	@if [ ${UID} = 0 ]; then \
		if [ ! -f ${MTREE_FILE} ]; then \
			${ECHO_MSG} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			${ECHO_MSG} "Copy it from a suitable location (e.g., ${SRC_BASE}/etc/mtree) and try again."; \
			exit 1; \
		else \
			${MTREE_CMD} ${MTREE_ARGS} ${PREFIX}/ >/dev/null; \
			if [ ${PREFIX} = ${LOCALBASE} -a "${MTREE_FILE_DEFAULT}" = "yes" ]; then \
				cd ${PREFIX}/share/nls; \
				for link in POSIX en_US.US-ASCII; \
				do \
					if [ x"`${READLINK_CMD} $${link}`" != x"C" ]; \
					then \
						${LN} -shf C $${link}; \
					fi; \
				done; \
			fi; \
		fi; \
	else \
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "You may want to become root and try again to ensure correct permissions."; \
	fi
.endif
.endif

.if !target(install-ldconfig-file)
install-ldconfig-file:
.if defined(USE_LDCONFIG) || defined(USE_LDCONFIG32)
.if defined(USE_LDCONFIG)
.if defined(USE_LINUX_PREFIX)
.if defined(NO_STAGE)
	@${ECHO_MSG} "===>   Running linux ldconfig"
	${LDCONFIG_CMD}
.endif
.else
.if defined(NO_STAGE)
.if !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>   Running ldconfig"
	${LDCONFIG} -m ${USE_LDCONFIG}
.else
	@${ECHO_MSG} "===>   Running ldconfig (errors are ignored)"
	-${LDCONFIG} -m ${USE_LDCONFIG}
.endif
.endif
.if ${USE_LDCONFIG} != "${PREFIX}/lib" && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>   Installing ldconfig configuration file"
.if defined(NO_LDCONFIG_MTREE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LDCONFIG_DIR}
.endif
	@${ECHO_CMD} ${USE_LDCONFIG} | ${TR} ' ' '\n' \
		> ${STAGEDIR}${PREFIX}/${LDCONFIG_DIR}/${UNIQUENAME}
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@${ECHO_CMD} ${LDCONFIG_DIR}/${UNIQUENAME} >> ${TMPPLIST}
.if defined(NO_LDCONFIG_MTREE)
	@${ECHO_CMD} "@unexec rmdir ${LDCONFIG_DIR} >/dev/null 2>&1 || true" >> ${TMPPLIST}
.endif
.endif
.endif
.endif
.if defined(USE_LDCONFIG32)
.if defined(NO_STAGE)
.if !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>   Running ldconfig"
	${LDCONFIG} -32 -m ${USE_LDCONFIG32}
.else
	@${ECHO_MSG} "===>   Running ldconfig (errors are ignored)"
	-${LDCONFIG} -32 -m ${USE_LDCONFIG32}
.endif
.endif
.if !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>   Installing 32-bit ldconfig configuration file"
.if defined(NO_LDCONFIG_MTREE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LDCONFIG_32DIR}
.endif
	@${ECHO_CMD} ${USE_LDCONFIG32} | ${TR} ' ' '\n' \
		> ${STAGEDIR}${PREFIX}/${LDCONFIG32_DIR}/${UNIQUENAME}
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@${ECHO_CMD} ${LDCONFIG32_DIR}/${UNIQUENAME} >> ${TMPPLIST}
.if defined(NO_LDCONFIG_MTREE)
	@${ECHO_CMD} "@unexec rmdir ${LDCONFIG32_DIR} >/dev/null 2>&1" >> ${TMPPLIST}
.endif
.endif
.endif
.if defined(INSTALLS_SHLIB)
	@${ECHO_MSG} "INSTALLS_SHLIB is deprecated. Use USE_LDCONFIG instead."
.endif
.endif
.endif

.if !target(create-users-groups)
.if defined(GROUPS) || defined(USERS)
.if defined(WITH_PKGNG)
_UG_OUTPUT=	${WRKDIR}/users-groups.sh
PKGPREINSTALL+=	${_UG_OUTPUT}
.else
_UG_OUTPUT=	/dev/null
.endif
.endif
create-users-groups:
.if defined(GROUPS) || defined(USERS)
.if defined(GROUPS)
.for _file in ${GID_FILES}
.if !exists(${_file})
	@${ECHO_CMD} "** ${_file} doesn't exist. Exiting."; exit 1
.endif
.endfor
.if defined(WITH_PKGNG)
		@${RM} -f ${_UG_OUTPUT} || ${TRUE}
.endif
	@${ECHO_MSG} "===> Creating users and/or groups."
.if defined(WITH_PKGNG)
	@${ECHO_CMD} "echo \"===> Creating users and/or groups.\"" >> ${_UG_OUTPUT}
.else
	@${ECHO_CMD} "@exec echo \"===> Creating users and/or groups.\"" >> ${TMPPLIST}
.endif
.for _group in ${GROUPS}
# _bgpd:*:130:
	@if ! ${GREP} -h ^${_group}: ${GID_FILES} >/dev/null 2>&1; then \
		${ECHO_CMD} "** Cannot find any information about group \`${_group}' in ${GID_FILES}."; \
		exit 1; \
	fi
	@IFS=":"; ${GREP} -h ^${_group}: ${GID_FILES} | head -n 1 | while read group foo gid members; do \
		gid=$$(($$gid+${GID_OFFSET})); \
		if [ "${NO_STAGE}" = "yes" ]; then \
		if ! ${PW} groupshow $$group >/dev/null 2>&1; then \
			${ECHO_MSG} "Creating group \`$$group' with gid \`$$gid'."; \
			${PW} groupadd $$group -g $$gid; \
		else \
			${ECHO_MSG} "Using existing group \`$$group'."; \
		fi; \
		fi ; \
		if [ -z "${WITH_PKGNG}" ]; then \
				${ECHO_CMD} "@exec if ! ${PW} groupshow $$group >/dev/null 2>&1; then \
					echo \"Creating group '$$group' with gid '$$gid'.\"; \
					${PW} groupadd $$group -g $$gid; else echo \"Using existing group '$$group'.\"; fi" >> ${TMPPLIST}; \
		else \
				${ECHO_CMD} -e "if ! ${PW} groupshow $$group >/dev/null 2>&1; then \n \
					echo \"Creating group '$$group' with gid '$$gid'.\" \n \
					${PW} groupadd $$group -g $$gid; else echo \"Using existing group '$$group'.\"\nfi" >> ${_UG_OUTPUT}; \
		fi ; \
	done
.endfor
.endif
.if defined(USERS)
.for _file in ${UID_FILES}
.if !exists(${_file})
	@${ECHO_CMD} "** ${_file} doesn't exist. Exiting."; exit 1
.endif
.endfor
.for _user in ${USERS}
# _bgpd:*:130:130:BGP Daemon:/var/empty:/sbin/nologin
	@if ! ${GREP} -h ^${_user}: ${UID_FILES} >/dev/null 2>&1; then \
		${ECHO_CMD} "** Cannot find any information about user \`${_user}' in ${UID_FILES}."; \
		exit 1; \
	fi
	@IFS=":"; ${GREP} -h ^${_user}: ${UID_FILES} | head -n 1 | while read login passwd uid gid class change expire gecos homedir shell; do \
		uid=$$(($$uid+${UID_OFFSET})); \
		gid=$$(($$gid+${GID_OFFSET})); \
		class="$${class:+-L }$$class"; \
		homedir=$$(echo $$homedir | sed "s|^/usr/local|${PREFIX}|"); \
		if [ "${NO_STAGE}" = "yes" ]; then \
		if ! ${PW} usershow $$login >/dev/null 2>&1; then \
			${ECHO_MSG}  "Creating user \`$$login' with uid \`$$uid'."; \
			eval ${PW} useradd $$login -u $$uid -g $$gid $$class -c \"$$gecos\" -d $$homedir -s $$shell; \
			case $$homedir in /nonexistent|/var/empty) ;; *) ${INSTALL} -d -g $$gid -o $$uid $$homedir;; esac; \
		else \
			${ECHO_MSG} "Using existing user \`$$login'."; \
		fi; \
		fi; \
		if [ -z "${WITH_PKGNG}" ]; then \
			${ECHO_CMD} "@exec if ! ${PW} usershow $$login >/dev/null 2>&1; then \
				echo \"Creating user '$$login' with uid '$$uid'.\"; \
				${PW} useradd $$login -u $$uid -g $$gid $$class -c \"$$gecos\" -d $$homedir -s $$shell; \
				else echo \"Using existing user '$$login'.\"; fi" >> ${TMPPLIST}; \
		else \
			${ECHO_CMD} -e "if ! ${PW} usershow $$login >/dev/null 2>&1; then \n \
				echo \"Creating user '$$login' with uid '$$uid'.\" \n \
				${PW} useradd $$login -u $$uid -g $$gid $$class -c \"$$gecos\" -d $$homedir -s $$shell \n \
				else \necho \"Using existing user '$$login'.\" \nfi" >> ${_UG_OUTPUT}; \
		fi ; \
		case $$homedir in /nonexistent|/var/empty) ;; *) ${ECHO_CMD} "@exec ${INSTALL} -d -g $$gid -o $$uid $$homedir" >> ${TMPPLIST};; esac; \
	done
.endfor
.if defined(GROUPS)
.for _group in ${GROUPS}
# mail:*:6:postfix,clamav
	@IFS=":"; ${GREP} -h ^${_group}: ${GID_FILES} | head -n 1 | while read group foo gid members; do \
		gid=$$(($$gid+${GID_OFFSET})); \
		IFS=","; for _login in $$members; do \
			for _user in ${USERS}; do \
				if [ "x$${_user}" = "x$${_login}" ]; then \
					if ! ${PW} groupshow ${_group} | ${GREP} -qw $${_login}; then \
						${ECHO_MSG} "Adding user \`$${_login}' to group \`${_group}'."; \
						${PW} groupmod ${_group} -m $${_login}; \
					fi; \
					if [ -z "${WITH_PKGNG}" ]; then \
							${ECHO_CMD} "@exec if ! ${PW} groupshow ${_group} | ${GREP} -qw $${_login}; then \
								echo \"Adding user '$${_login}' to group '${_group}'.\"; \
								${PW} groupmod ${_group} -m $${_login}; fi" >> ${TMPPLIST}; \
					else \
							${ECHO_CMD} "if ! ${PW} groupshow ${_group} | ${GREP} -qw $${_login}; then \n \
								echo \"Adding user '$${_login}' to group '${_group}'.\" \n \
								${PW} groupmod ${_group} -m $${_login} \nfi" >> ${_UG_OUTPUT}; \
					fi ; \
				fi; \
			done; \
		done; \
	done
.endfor
.endif
.if defined(USERS)
.for _user in ${USERS}
	@if [ ! ${USERS_BLACKLIST:M${_user}} ]; then \
		${ECHO_CMD} "@unexec if ${PW} usershow ${_user} >/dev/null 2>&1; then \
		echo \"==> You should manually remove the \\\"${_user}\\\" user. \"; fi" >> ${TMPPLIST}; \
	fi
.endfor
.endif
.endif
.else
	@${DO_NADA}
.endif
.endif

# PR ports/152498
# XXX Make sure the commands to create group(s) 
# and user(s) are the first in pkg-plist
.if !target(fix-plist-sequence)
fix-plist-sequence: ${TMPPLIST}
.if !defined(WITH_PKGNG) && (defined(GROUPS) || defined(USERS))
	@${ECHO_CMD} "===> Correct pkg-plist sequence to create group(s) and user(s)"
	@${EGREP} -e '^@exec echo.*Creating users and' -e '^@exec.*${PW}' -e '^@exec ${INSTALL} -d -g' ${TMPPLIST} > ${TMPGUCMD}
	@${EGREP} -v -e '^@exec echo.*Creating users and' -e '^@exec.*${PW}' -e '^@exec ${INSTALL} -d -g' ${TMPPLIST} >> ${TMPGUCMD}
	@${MV} -f ${TMPGUCMD} ${TMPPLIST}
.endif
.endif

.if !defined(DISABLE_SECURITY_CHECK)
.if !target(security-check)
security-check:
# Scan PLIST for:
#   1.  setugid files
#   2.  accept()/recvfrom() which indicates network listening capability
#   3.  insecure functions (gets/mktemp/tempnam/[XXX])
#   4.  startup scripts, in conjunction with 2.
#   5.  world-writable files/dirs
#
	-@${RM} -f ${WRKDIR}/.PLIST.setuid ${WRKDIR}/.PLIST.writable ${WRKDIR}/.PLIST.objdump; \
	${AWK} -v prefix='${PREFIX}' ' \
		match($$0, /^@cwd /) { prefix = substr($$0, RSTART + RLENGTH); if (prefix == "/") prefix=""; next; } \
		/^@/ { next; } \
		/^\// { print; next; } \
		{ print prefix "/" $$0; } \
	' ${TMPPLIST} > ${WRKDIR}/.PLIST.flattened; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune ! -type l -type f \( -perm -4000 -o -perm -2000 \) \( -perm -0010 -o -perm -0001 \) 2> /dev/null > ${WRKDIR}/.PLIST.setuid; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune -perm -0002 \! -type l 2> /dev/null > ${WRKDIR}/.PLIST.writable; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune ! -type l -type f -print0 2> /dev/null \
	| ${XARGS} -0 -n 1 ${OBJDUMP} -R 2> /dev/null > ${WRKDIR}/.PLIST.objdump; \
	if \
		! ${AWK} -v audit="$${PORTS_AUDIT}" -f ${PORTSDIR}/Tools/scripts/security-check.awk \
		  ${WRKDIR}/.PLIST.flattened ${WRKDIR}/.PLIST.objdump ${WRKDIR}/.PLIST.setuid ${WRKDIR}/.PLIST.writable; \
	then \
		www_site=$$(cd ${.CURDIR} && ${MAKE} www-site); \
	    if [ ! -z "$${www_site}" ]; then \
			${ECHO_MSG}; \
			${ECHO_MSG} "      For more information, and contact details about the security"; \
			${ECHO_MSG} "      status of this software, see the following webpage: "; \
			${ECHO_MSG} "$${www_site}"; \
		fi; \
	fi
.endif
.else # i.e. defined(DISABLE_SECURITY_CHECK)
security-check:
	@${ECHO_MSG} "      WARNING: Security check has been disabled."
.endif # !defined(DISABLE_SECURITY_CHECK)

################################################################
# Skeleton targets start here
#
# You shouldn't have to change these.  Either add the pre-* or
# post-* targets/scripts or redefine the do-* targets.  These
# targets don't do anything other than checking for cookies and
# call the necessary targets/scripts.
################################################################

# Please note that the order of the following targets is important, and
# should not be modified.

.if defined(CHROOTED)
_CHROOT_SEQ=	post-chroot
.else
_CHROOT_SEQ=
.endif
_SANITY_SEQ=	${_CHROOT_SEQ} pre-everything check-makefile \
				check-categories check-makevars check-desktop-entries \
				check-depends identify-install-conflicts check-deprecated \
				check-vulnerable check-license check-config buildanyway-message \
				options-message

_PKG_DEP=		check-sanity
_PKG_SEQ=		pkg-depends
_FETCH_DEP=		pkg
_FETCH_SEQ=		fetch-depends pre-fetch pre-fetch-script \
				do-fetch fetch-specials post-fetch post-fetch-script
_EXTRACT_DEP=	fetch
_EXTRACT_SEQ=	check-build-conflicts extract-message checksum extract-depends \
				pre-extract pre-extract-script do-extract \
				post-extract post-extract-script
_PATCH_DEP=		extract
_PATCH_SEQ=		ask-license patch-message patch-depends patch-dos2unix pre-patch \
				pre-patch-script do-patch post-patch post-patch-script
_CONFIGURE_DEP=	patch
_CONFIGURE_SEQ=	build-depends lib-depends configure-message run-autotools-fixup \
				configure-autotools pre-configure pre-configure-script \
				run-autotools do-configure post-configure post-configure-script
_BUILD_DEP=		configure
_BUILD_SEQ=		build-message pre-build pre-build-script do-build \
				post-build post-build-script
.if !defined(NO_STAGE)

_STAGE_DEP=		build
_STAGE_SEQ=		stage-message stage-dir run-depends lib-depends apply-slist pre-install generate-plist \
				pre-su-install
.if defined(NEED_ROOT)
_STAGE_SUSEQ=	create-users-groups do-install post-install post-install-script post-stage compress-man \
				install-rc-script install-ldconfig-file install-license \
				install-desktop-entries add-plist-info add-plist-docs add-plist-examples \
				add-plist-data add-plist-post fix-plist-sequence
.if defined(DEVELOPER)
_STAGE_SUSEQ+=	stage-qa
.endif
.else
_STAGE_SEQ+=	create-users-groups do-install post-install post-install-script post-stage compress-man \
				install-rc-script install-ldconfig-file install-license \
				install-desktop-entries add-plist-info add-plist-docs add-plist-examples \
				add-plist-data add-plist-post fix-plist-sequence
.if defined(DEVELOPER)
_STAGE_SEQ+=	stage-qa
.endif
.endif
.if defined(WITH_PKGNG)
_INSTALL_DEP=	stage
_INSTALL_SEQ=	install-message run-depends lib-depends check-already-installed
_INSTALL_SUSEQ=	fake-pkg security-check

_PACKAGE_DEP=	stage
_PACKAGE_SEQ=	package-message pre-package pre-package-script do-package post-package-script

.else # pkg_install

_PACKAGE_DEP=	stage
_PACKAGE_SEQ=	package-message pre-package pre-package-script do-package post-package-script

_INSTALL_DEP=	package
_INSTALL_SEQ=	install-message run-depends lib-depends check-already-installed
_INSTALL_SUSEQ=	install-package security-check
.endif

.else # NO_STAGE

_INSTALL_DEP=	build
_INSTALL_SEQ=	install-message check-install-conflicts run-depends lib-depends apply-slist pre-install \
				pre-install-script generate-plist check-already-installed
_INSTALL_SUSEQ= check-umask install-mtree pre-su-install \
				pre-su-install-script create-users-groups do-install \
				install-desktop-entries install-license install-rc-script \
				post-install post-install-script add-plist-buildinfo \
				add-plist-info add-plist-docs add-plist-examples \
				add-plist-data add-plist-post fix-plist-sequence \
				compress-man install-ldconfig-file fake-pkg security-check
_PACKAGE_DEP=	install
_PACKAGE_SEQ=	package-message pre-package pre-package-script \
				do-package post-package-script
.endif

.if !target(post-chroot)
post-chroot:
	@${DO_NADA}
.endif

.if !target(check-sanity)
check-sanity: ${_SANITY_SEQ}
.endif

# XXX MCL might need to move in loop below?
.if !target(fetch)
fetch: ${_FETCH_DEP} ${_FETCH_SEQ}
.endif

.if !target(pkg)
pkg: ${_PKG_DEP} ${_PKG_SEQ}
.endif

# Main logic. The loop generates 7 main targets and using cookies
# ensures that those already completed are skipped.

.for target in extract patch configure build stage install package

.if !target(${target}) && defined(_OPTIONS_OK)
${target}: ${${target:U}_COOKIE}
.elif !target(${target})
${target}: config-conditional
	@cd ${.CURDIR} && ${MAKE} CONFIG_DONE_${UNIQUENAME:U}=1 ${${target:U}_COOKIE}
.elif target(${target}) && defined(IGNORE)
.endif

.if !exists(${${target:U}_COOKIE})

.if ${UID} != 0 && defined(_${target:U}_SUSEQ) && !defined(INSTALL_AS_USER)
.if defined(USE_SUBMAKE)
${${target:U}_COOKIE}: ${_${target:U}_DEP}
	@cd ${.CURDIR} && ${MAKE} ${_${target:U}_SEQ}
.else
${${target:U}_COOKIE}: ${_${target:U}_DEP} ${_${target:U}_SEQ}
.endif
	@${ECHO_MSG} "===>  Switching to root credentials for '${target}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${_${target:U}_SUSEQ}"
	@${ECHO_MSG} "===>  Returning to user credentials"
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.elif defined(USE_SUBMAKE)
${${target:U}_COOKIE}: ${_${target:U}_DEP}
	@cd ${.CURDIR} && \
		${MAKE} ${_${target:U}_SEQ} ${_${target:U}_SUSEQ}
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.else
${${target:U}_COOKIE}: ${_${target:U}_DEP} ${_${target:U}_SEQ} ${_${target:U}_SUSEQ}
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.endif

.else
${${target:U}_COOKIE}::
	@if [ -e ${.TARGET} ]; then \
		${DO_NADA}; \
	else \
		cd ${.CURDIR} && ${MAKE} ${.TARGET}; \
	fi
.endif

.endfor

# Enforce order for -jN builds

.ORDER: ${_SANITY_SEQ}
.ORDER: ${_PKG_DEP} ${_PKG_SEQ}
.ORDER: ${_FETCH_DEP} ${_FETCH_SEQ}
.ORDER: ${_EXTRACT_DEP} ${_EXTRACT_SEQ}
.ORDER: ${_PATCH_DEP} ${_PATCH_SEQ}
.ORDER: ${_CONFIGURE_DEP} ${_CONFIGURE_SEQ}
.ORDER: ${_BUILD_DEP} ${_BUILD_SEQ}
.if !defined(NO_STAGE)
.ORDER: ${_STAGE_DEP} ${_STAGE_SEQ}
.endif
.ORDER: ${_INSTALL_DEP} ${_INSTALL_SEQ}
.ORDER: ${_PACKAGE_DEP} ${_PACKAGE_SEQ}

extract-message:
	@${ECHO_MSG} "===>  Extracting for ${PKGNAME}"
patch-message:
	@${ECHO_MSG} "===>  Patching for ${PKGNAME}"
configure-message:
	@${ECHO_MSG} "===>  Configuring for ${PKGNAME}"
build-message:
	@${ECHO_MSG} "===>  Building for ${PKGNAME}"
stage-message:
	@${ECHO_MSG} "===>  Staging for ${PKGNAME}"
install-message:
	@${ECHO_MSG} "===>  Installing for ${PKGNAME}"
package-message:
	@${ECHO_MSG} "===>  Building package for ${PKGNAME}"

# Empty pre-* and post-* targets

.for stage in pre post
.for name in pkg check-sanity fetch extract patch configure build stage install package

.if !target(${stage}-${name})
${stage}-${name}:
	@${DO_NADA}
.endif

.if !target(${stage}-${name}-script)
${stage}-${name}-script:
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/-script$//} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/-script$//}; \
	fi
.endif

.endfor
.endfor

# Special cases for su
.if !target(pre-su-install)
pre-su-install:
	@${DO_NADA}
.endif

.if !target(pre-su-install-script)
pre-su-install-script:
	@${DO_NADA}
.endif


.if !target(pretty-print-www-site)
pretty-print-www-site:
	@www_site=$$(cd ${.CURDIR} && ${MAKE} www-site); \
	if [ -n "$${www_site}" ]; then \
		${ECHO_MSG} -n " and/or visit the "; \
		${ECHO_MSG} -n "<a href=\"$${www_site}\">web site</a>"; \
		${ECHO_MSG} " for further information"; \
	fi
.endif

################################################################
# Some more targets supplied for users' convenience
################################################################

# Checkpatch
#
# Special target to verify patches

.if !target(checkpatch)
checkpatch:
	@cd ${.CURDIR} && ${MAKE} PATCH_CHECK_ONLY=yes ${_PATCH_DEP} ${_PATCH_SEQ}
.endif

# Reinstall
#
# Special target to re-run install

.if !target(reinstall)
reinstall:
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
	@cd ${.CURDIR} && DEPENDS_TARGET="${DEPENDS_TARGET}" ${MAKE} -DFORCE_PKG_REGISTER install
.endif

.if !target(restage)
restage:
	@${RM} -rf ${STAGEDIR} ${STAGE_COOKIE} ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
	@cd ${.CURDIR} && ${MAKE} stage
.endif

# Deinstall
#
# Special target to remove installation

.if !target(deinstall)
deinstall:
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@${ECHO_MSG} "===>  Deinstalling for ${PKGORIGIN}"
	@found_names=`${PKG_INFO} -q -O ${PKGORIGIN}`; \
	for p in $${found_names}; do \
			check_name=`${ECHO_CMD} $${p} | ${SED} -e 's/-[^-]*$$//'`; \
			if [ "$${check_name}" = "${PKGBASE}" ]; then \
					prfx=`${PKG_INFO} -q -p $${p} 2> /dev/null | ${SED} -ne '1s|^@cwd ||p'`; \
					if [ "x${PREFIX}" = "x$${prfx}" ]; then \
							${ECHO_MSG} "===>   Deinstalling $${p}"; \
							${PKG_DELETE} -f $${p}; \
					else \
							${ECHO_MSG} "===>   $${p} has a different PREFIX: $${prfx}, skipping"; \
					fi; \
			fi; \
	done; \
	if [ -z "$${found_names}" ]; then \
		${ECHO_MSG} "===>   ${PKGBASE} not installed, skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif
.endif

# Deinstall-all
#
# Special target to remove installation of all ports of the same origin

.if !target(deinstall-all)
deinstall-all:
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@${ECHO_MSG} "===>  Deinstalling for ${PKGORIGIN}"
	@deinstall_names=`${PKG_INFO} -q -O ${PKGORIGIN}`; \
	for oldpkgorigin in $$(${GREP} "|${PKGORIGIN}|" ${PORTSDIR}/MOVED | ${CUT} -f 1 -d '|' | ${SORT} -u); do \
		deinstall_names="$${deinstall_names} $$(${PKG_INFO} -q -O $${oldpkgorigin})"; \
	done; \
	if [ -n "$${deinstall_names}" ]; then \
		for d in $${deinstall_names}; do \
			${ECHO_MSG} "===>   Deinstalling $${d}"; \
			${PKG_DELETE} -f $${d}; \
		done; \
	else \
		${ECHO_MSG} "===>   ${PKGORIGIN} not installed, skipping"; \
	fi; \
	${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif
.endif

# Cleaning up

.if !target(do-clean)
do-clean:
.if !defined(NO_STAGE) && defined(NEED_ROOT) && ${UID} != 0 && !defined(INSTALL_AS_USER) && exists(${STAGE_COOKIE})
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
.endif
.endif

.if !target(clean)
clean:
.if !defined(NOCLEANDEPENDS)
	@cd ${.CURDIR} && ${MAKE} limited-clean-depends
.endif
	@${ECHO_MSG} "===>  Cleaning for ${PKGNAME}"
.if target(pre-clean)
	@cd ${.CURDIR} && ${MAKE} pre-clean
.endif
	@cd ${.CURDIR} && ${MAKE} do-clean
.if target(post-clean)
	@cd ${.CURDIR} && ${MAKE} post-clean
.endif
.endif

.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.if !target(distclean)
distclean: pre-distclean clean
	@cd ${.CURDIR} && ${MAKE} delete-distfiles RESTRICTED_FILES="${_DISTFILES} ${_PATCHFILES}"
.endif

.if !target(delete-distfiles)
delete-distfiles:
	@${ECHO_MSG} "===>  Deleting distfiles for ${PKGNAME}"
	@(if [ "X${RESTRICTED_FILES}" != "X" -a -d ${_DISTDIR} ]; then \
		cd ${_DISTDIR}; \
		for file in ${RESTRICTED_FILES}; do \
			${RM} -f $${file}; \
			dir=$${file%/*}; \
			if [ "$${dir}" != "$${file}" ]; then \
				${RMDIR} -p $${dir} >/dev/null 2>&1 || :; \
			fi; \
		done; \
	fi)
.if defined(DIST_SUBDIR)
	-@${RMDIR} ${_DISTDIR} >/dev/null 2>&1 || ${TRUE}
.endif
.endif

.if !target(delete-distfiles-list)
delete-distfiles-list:
	@${ECHO_CMD} "# ${PKGNAME}"
	@if [ "X${RESTRICTED_FILES}" != "X" ]; then \
		for file in ${RESTRICTED_FILES}; do \
			${ECHO_CMD} "[ -f ${_DISTDIR}/$$file ] && (${ECHO_CMD} deleting ${_DISTDIR}/$$file; ${RM} -f ${_DISTDIR}/$$file)"; \
			dir=$${file%/*}; \
			if [ "$${dir}" != "$${file}" ]; then \
				${ECHO_CMD} "(cd ${_DISTDIR} && ${RMDIR} -p $${dir} 2>/dev/null)"; \
			fi; \
		done; \
	fi
.if defined(DIST_SUBDIR)
	@${ECHO_CMD} "${RMDIR} ${_DISTDIR} 2>/dev/null || ${TRUE}"
.endif
.endif

# Prints out a list of files to fetch (useful to do a batch fetch)

.if !target(fetch-list)
fetch-list:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 ${_MASTER_SITES_ENV} ; \
	 for _file in ${DISTFILES}; do \
		file=`${ECHO_CMD} $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
		select=`${ECHO_CMD} $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -f $$file -a ! -f $${file##*/} ]; then \
			if [ ! -z "$$select" ] ; then \
				__MASTER_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_MASTER_SITES_$${group}} ] ; then \
						eval ___MASTER_SITES_TMP=\$${_MASTER_SITES_$${group}} ; \
						__MASTER_SITES_TMP="$${__MASTER_SITES_TMP} $${___MASTER_SITES_TMP}" ; \
					fi; \
				done; \
				___MASTER_SITES_TMP= ; \
				SORTED_MASTER_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__MASTER_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_MASTER_SITES_CMD_TMP="${SORTED_MASTER_SITES_DEFAULT_CMD}" ; \
			fi; \
			for site in `eval $$SORTED_MASTER_SITES_CMD_TMP ${_RANDOMIZE_SITES}`; do \
				if [ ! -z "`${ECHO_CMD} ${NOFETCHFILES} | ${GREP} -w $${file}`" ]; then \
					if [ -z "`${ECHO_CMD} ${MASTER_SITE_OVERRIDE} | ${GREP} -w $${site}`" ]; then \
						continue; \
					fi; \
				fi; \
				DIR=${DIST_SUBDIR};\
				CKSIZE=`alg=SIZE; ${DISTINFO_DATA}`; \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO_CMD} -n ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO_CMD} "${ECHO_CMD} $${file} not fetched" ; \
		fi; \
	done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	 ${_PATCH_SITES_ENV} ; \
	 for _file in ${PATCHFILES}; do \
		file=`${ECHO_CMD} $$_file | ${SED} -E -e 's/:[^-:][^:]*$$//'` ; \
		select=`${ECHO_CMD} $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		file=`${ECHO_CMD} $$file | ${SED} -E -e 's/:-[^:]+$$//'` ; \
		if [ ! -f $$file -a ! -f $${file##*/} ]; then \
			if [ ! -z "$$select" ] ; then \
				__PATCH_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_PATCH_SITES_$${group}} ] ; then \
						eval ___PATCH_SITES_TMP=\$${_PATCH_SITES_$${group}} ; \
						__PATCH_SITES_TMP="$${__PATCH_SITES_TMP} $${___PATCH_SITES_TMP}" ; \
				fi; \
				done; \
				___PATCH_SITES_TMP= ; \
				SORTED_PATCH_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__PATCH_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_PATCH_SITES_CMD_TMP="${SORTED_PATCH_SITES_DEFAULT_CMD}" ; \
			fi; \
			for site in `eval $$SORTED_PATCH_SITES_CMD_TMP ${_RANDOMIZE_SITES}`; do \
				CKSIZE=`alg=SIZE; ${DISTINFO_DATA}`; \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO_CMD} -n ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO_CMD} "${ECHO_CMD} $${file} not fetched" ; \
		fi; \
	 done)
.endif
.endif

.if !target(fetch-url-list-int)
fetch-url-list-int:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	${_MASTER_SITES_ENV}; \
	for _file in ${DISTFILES}; do \
		file=`${ECHO_CMD} $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
			fileptn=`${ECHO_CMD} $$file | ${SED} 's|/|\\\\/|g;s/\./\\\\./g;s/\+/\\\\+/g;s/\?/\\\\?/g'` ; \
		select=`${ECHO_CMD} $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -z "${LISTALL}" -o ! -f $$file -a ! -f $${file##*/} ]; then \
			if [ ! -z "$$select" ] ; then \
				__MASTER_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_MASTER_SITES_$${group}} ] ; then \
						eval ___MASTER_SITES_TMP=\$${_MASTER_SITES_$${group}} ; \
						__MASTER_SITES_TMP="$${__MASTER_SITES_TMP} $${___MASTER_SITES_TMP}" ; \
					fi \
				done; \
				___MASTER_SITES_TMP= ; \
				SORTED_MASTER_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__MASTER_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_MASTER_SITES_CMD_TMP="${SORTED_MASTER_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_MASTER_SITES_CMD_TMP ${_RANDOMIZE_SITES}`; do \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO_CMD} $${args} ; \
			done; \
		fi \
	done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	${_PATCH_SITES_ENV} ; \
	for _file in ${PATCHFILES}; do \
		file=`${ECHO_CMD} $$_file | ${SED} -E -e 's/:[^-:][^:]*$$//'` ; \
		select=`${ECHO_CMD} $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		file=`${ECHO_CMD} $$file | ${SED} -E -e 's/:-[^:]+$$//'` ; \
		fileptn=`${ECHO_CMD} $$file | ${SED} 's|/|\\\\/|g;s/\./\\\\./g;s/\+/\\\\+/g;s/\?/\\\\?/g'` ; \
		if [ ! -z "${LISTALL}" -o ! -f $$file -a ! -f $${file##*/} ]; then \
			if [ ! -z "$$select" ] ; then \
				__PATCH_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_PATCH_SITES_$${group}} ] ; then \
						eval ___PATCH_SITES_TMP=\$${_PATCH_SITES_$${group}} ; \
						__PATCH_SITES_TMP="$${__PATCH_SITES_TMP} $${___PATCH_SITES_TMP}" ; \
					fi \
				done; \
				___PATCH_SITES_TMP= ; \
				SORTED_PATCH_SITES_CMD_TMP="${ECHO_CMD} ${_MASTER_SITE_OVERRIDE} `${ECHO_CMD} $${__PATCH_SITES_TMP} | ${AWK} '${MASTER_SORT_AWK:S|\\|\\\\|g}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_PATCH_SITES_CMD_TMP="${SORTED_PATCH_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_PATCH_SITES_CMD_TMP ${_RANDOMIZE_SITES}`; do \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO_CMD} $${args} ; \
			done; \
		fi \
	 done)
.endif
.endif

.if !target(fetch-urlall-list)
fetch-urlall-list:
	@cd ${.CURDIR} && LISTALL=yes ${MAKE} fetch-url-list-int
.endif

.if !target(fetch-url-list)
fetch-url-list:
	@cd ${.CURDIR} && ${MAKE} fetch-url-list-int
.endif

# Generates patches.

update-patches:
	@toedit=`PATCH_WRKSRC=${PATCH_WRKSRC} \
		PATCHDIR=${PATCHDIR} \
		PATCH_LIST=${PATCHDIR}/patch-* \
		DIFF_ARGS=${DIFF_ARGS} \
		DISTORIG=${DISTORIG} \
		${SH} ${PORTSDIR}/Tools/scripts/update-patches`; \
	case $$toedit in "");; \
	*) ${ECHO_CMD} -n 'edit patches: '; read i; \
	cd ${PATCHDIR} && $${VISUAL:-$${EDIT:-/usr/bin/vi}} $$toedit;; esac

# Checksumming utilities

check-checksum-algorithms:
	@ \
	${checksum_init} \
	\
	for alg in ${CHECKSUM_ALGORITHMS:U}; do \
		eval alg_executable=\$$$$alg; \
		if [ -z "$$alg_executable" ]; then \
			${ECHO_MSG} "Checksum algorithm $$alg: Couldn't find the executable."; \
			${ECHO_MSG} "Set $$alg=/path/to/$$alg in /etc/make.conf and try again."; \
			exit 1; \
		fi; \
	done; \

checksum_init=\
	SHA256=${SHA256};

.if !target(makesum)
makesum: check-checksum-algorithms
	@cd ${.CURDIR} && ${MAKE} fetch NO_CHECKSUM=yes \
		DISABLE_SIZE=yes
	@if [ -f ${DISTINFO_FILE} ]; then ${CAT} /dev/null > ${DISTINFO_FILE}; fi
	@( \
		cd ${DISTDIR}; \
		\
		${checksum_init} \
		\
		for file in ${_CKSUMFILES}; do \
			for alg in ${CHECKSUM_ALGORITHMS:U}; do \
				eval alg_executable=\$$$$alg; \
				\
				if [ $$alg_executable != "NO" ]; then \
					$$alg_executable $$file >> ${DISTINFO_FILE}; \
				fi; \
			done; \
			${ECHO_CMD} "SIZE ($$file) = `${STAT} -f \"%z\" $$file`" >> ${DISTINFO_FILE}; \
		done \
	)
	@for file in ${_IGNOREFILES}; do \
		for alg in ${CHECKSUM_ALGORITHMS:U}; do \
			${ECHO_CMD} "$$alg ($$file) = IGNORE" >> ${DISTINFO_FILE}; \
		done; \
	done
.endif

.if !target(checksum)
checksum: fetch check-checksum-algorithms
	@set -e ; \
	${checksum_init} \
	if [ -f ${DISTINFO_FILE} ]; then \
		cd ${DISTDIR}; OK="";\
		for file in ${_CKSUMFILES}; do \
			ignored="true"; \
			_file=$${file#${DIST_SUBDIR}/*};	\
			for alg in ${CHECKSUM_ALGORITHMS:U}; do \
				ignore="false"; \
				eval alg_executable=\$$$$alg; \
				\
				if [ $$alg_executable != "NO" ]; then \
					MKSUM=`$$alg_executable < $$file`; \
					CKSUM=`file=$$_file; ${DISTINFO_DATA}`; \
				else \
					ignore="true"; \
				fi; \
				\
				if [ $$ignore = "false" -a -z "$$CKSUM" ]; then \
					${ECHO_MSG} "=> No $$alg checksum recorded for $$file."; \
					ignore="true"; \
				fi; \
				\
				if [ "$$CKSUM" = "IGNORE" ]; then \
					${ECHO_MSG} "=> $$alg Checksum for $$file is set to IGNORE in distinfo file even though"; \
					${ECHO_MSG} "   the file is not in the "'$$'"{IGNOREFILES} list."; \
					ignore="true"; \
					OK=${FALSE}; \
				fi; \
				\
				if [ $$ignore = "false" ]; then \
					match="false"; \
					for chksum in $$CKSUM; do \
						if [ "$$chksum" = "$$MKSUM" ]; then \
							match="true"; \
							break; \
						fi; \
					done; \
					if [ $$match = "true" ]; then \
						${ECHO_MSG} "=> $$alg Checksum OK for $$file."; \
						ignored="false"; \
					else \
						${ECHO_MSG} "=> $$alg Checksum mismatch for $$file."; \
						refetchlist="$$refetchlist$$file "; \
						OK="$${OK:-retry}"; \
						[ "$${OK}" = "retry" -a ${FETCH_REGET} -gt 0 ] && ${RM} -f $${file}; \
						ignored="false"; \
					fi; \
				fi; \
			done; \
			\
			if [ $$ignored = "true" ]; then \
				${ECHO_MSG} "=> No suitable checksum found for $$file."; \
				OK="${FALSE}"; \
			fi; \
			\
		done; \
		\
		for file in ${_IGNOREFILES}; do \
			_file=$${file#${DIST_SUBDIR}/*};	\
			ignored="true"; \
			alreadymatched="false"; \
			for alg in ${CHECKSUM_ALGORITHMS:U}; do \
				ignore="false"; \
				eval alg_executable=\$$$$alg; \
				\
				if [ $$alg_executable != "NO" ]; then \
					CKSUM=`file=$$_file; ${DISTINFO_DATA}`; \
				else \
					ignore="true"; \
				fi; \
				\
				if [ $$ignore = "false" ]; then \
					if [ -z "$$CKSUM" ]; then \
						${ECHO_MSG} "=> No $$alg checksum for $$file recorded (expected IGNORE)"; \
						OK="$$alreadymatched"; \
					elif [ $$CKSUM != "IGNORE" ]; then \
						${ECHO_MSG} "=> $$alg Checksum for $$file is not set to IGNORE in distinfo file even though"; \
						${ECHO_MSG} "   the file is in the "'$$'"{IGNOREFILES} list."; \
						OK="false"; \
					else \
						ignored="false"; \
						alreadymatched="true"; \
					fi; \
				fi; \
			done; \
			\
			if ( [ $$ignored = "true" ]) ; then \
				${ECHO_MSG} "=> No suitable checksum found for $$file."; \
				OK="false"; \
			fi; \
			\
		done; \
		\
		if [ "$${OK:=true}" = "retry" ] && [ ${FETCH_REGET} -gt 0 ]; then \
			${ECHO_MSG} "===>  Refetch for ${FETCH_REGET} more times files: $$refetchlist"; \
			if ( cd ${.CURDIR} && \
			    ${MAKE} ${.MAKEFLAGS} FORCE_FETCH="$$refetchlist" FETCH_REGET="`${EXPR} ${FETCH_REGET} - 1`" fetch); then \
				  if ( cd ${.CURDIR} && \
			        ${MAKE} ${.MAKEFLAGS} FETCH_REGET="`${EXPR} ${FETCH_REGET} - 1`" checksum ); then \
				      OK="true"; \
				  fi; \
			fi; \
		fi; \
		\
		if [ "$$OK" != "true" -a ${FETCH_REGET} -eq 0 ]; then \
			${ECHO_MSG} "===>  Giving up on fetching files: $$refetchlist"; \
			${ECHO_MSG} "Make sure the Makefile and distinfo file (${DISTINFO_FILE})"; \
			${ECHO_MSG} "are up to date.  If you are absolutely sure you want to override this"; \
			${ECHO_MSG} "check, type \"make NO_CHECKSUM=yes [other args]\"."; \
			exit 1; \
		fi; \
		if [ "$$OK" != "true" ]; then \
			exit 1; \
		fi; \
	elif [ -n "${_CKSUMFILES:M*}" ]; then \
		${ECHO_MSG} "=> No checksum file (${DISTINFO_FILE})."; \
	fi
.endif

################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

# Nobody should want to override this unless PKGNAME is simply bogus.

.if !target(package-name)
package-name:
	@${ECHO_CMD} ${PKGNAME}
.endif

# Build a package but don't check the package cookie

.if !target(repackage)
repackage: pre-repackage package

pre-repackage:
	@${RM} -f ${PACKAGE_COOKIE}
.endif

# Build a package but don't check the cookie for installation, also don't
# install package cookie

.if !target(package-noinstall)
package-noinstall:
	@${MKDIR} ${WRKDIR}
	@cd ${.CURDIR} && ${MAKE} pre-package \
		pre-package-script do-package post-package-script
	@${RM} -f ${TMPPLIST}
	-@${RMDIR} ${WRKDIR}
.endif

################################################################
# Dependency checking
################################################################

.if !target(depends)
depends: pkg-depends extract-depends patch-depends lib-depends fetch-depends build-depends run-depends

.if defined(ALWAYS_BUILD_DEPENDS)
_DEPEND_ALWAYS=	1
.else
_DEPEND_ALWAYS=	0
.endif

_INSTALL_DEPENDS=	\
		if [ -n "${USE_PACKAGE_DEPENDS}" -o -n "${USE_PACKAGE_DEPENDS_ONLY}" ]; then \
			subpkgfile=`(cd $$dir; ${MAKE} $$depends_args -V PKGFILE)`; \
			subpkgname=$${subpkgfile%-*} ; \
			subpkgname=$${subpkgname\#\#*/} ; \
			if [ -r "$${subpkgfile}" -a "$$target" = "${DEPENDS_TARGET}" ]; then \
				${ECHO_MSG} "===>   Installing existing package $${subpkgfile}"; \
				if [ -n "${WITH_PKGNG}" -a $${subpkgname} = "pkg" ]; then \
					[ -d ${WRKDIR} ] || ${MKDIR} ${WRKDIR} ; \
					${TAR} xf $${subpkgfile} -C ${WRKDIR} -s ",/.*/,,g" "*/pkg-static" ; \
					${WRKDIR}/pkg-static add $${subpkgfile}; \
					${RM} -f ${WRKDIR}/pkg-static; \
				else \
					${PKG_ADD} $${subpkgfile}; \
				fi; \
			elif [ -n "${USE_PACKAGE_DEPENDS_ONLY}" -a "$${target}" = "${DEPENDS_TARGET}" ]; then \
				${ECHO_MSG} "===>   ${PKGNAME} depends on package: $${subpkgfile} - not found"; \
				${ECHO_MSG} "===>   USE_PACKAGE_DEPENDS_ONLY set - not building missing dependency from source"; \
				exit 1; \
			else \
			  (cd $$dir; ${MAKE} -DINSTALLS_DEPENDS $$target $$depends_args) ; \
			fi; \
		else \
			(cd $$dir; ${MAKE} -DINSTALLS_DEPENDS $$target $$depends_args) ; \
		fi; \
		${ECHO_MSG} "===>   Returning to build of ${PKGNAME}";

.for deptype in PKG EXTRACT PATCH FETCH BUILD RUN
${deptype:L}-depends:
.if defined(${deptype}_DEPENDS)
.if !defined(NO_DEPENDS)
	@set -e ; for i in `${ECHO_CMD} "${${deptype}_DEPENDS}"`; do \
		prog=$${i%%:*}; \
		if [ -z "$$prog" ]; then \
			${ECHO_MSG} "Error: there is an empty port dependency in ${deptype}_DEPENDS."; \
			break; \
		fi; \
		dir=`${ECHO_CMD} $$i | ${SED} -e 's/[^:]*://'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=$${dir##*:}; \
			dir=$${dir%%:*}; \
			if [ X${DEPENDS_PRECLEAN} != "X" ]; then \
				target="clean $$target"; \
				depends_args="$$depends_args NOCLEANDEPENDS=yes"; \
			fi; \
			if [ X${DEPENDS_CLEAN} != "X" ]; then \
				target="$$target clean"; \
				depends_args="$$depends_args NOCLEANDEPENDS=yes"; \
			fi; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		if ${EXPR} "$$prog" : \\/ >/dev/null; then \
			if [ -e "$$prog" ]; then \
				if [ "$$prog" = "${NONEXISTENT}" ]; then \
					${ECHO_MSG} "Error: ${NONEXISTENT} exists.  Please remove it, and restart the build."; \
					${FALSE}; \
				else \
					${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - found"; \
					if [ ${_DEPEND_ALWAYS} = 1 ]; then \
						${ECHO_MSG} "       (but building it anyway)"; \
						notfound=1; \
					else \
						notfound=0; \
					fi; \
				fi; \
			else \
				${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - not found"; \
				notfound=1; \
			fi; \
		else \
			case $${prog} in \
				*\>*|*\<*|*=*)	pkg=yes;; \
				*)		pkg="";; \
			esac; \
			if [ "$$pkg" != "" ]; then \
				if ${PKG_INFO} "$$prog" > /dev/null 2>&1 ; then \
					${ECHO_MSG} "===>   ${PKGNAME} depends on package: $$prog - found"; \
					if [ ${_DEPEND_ALWAYS} = 1 ]; then \
						${ECHO_MSG} "       (but building it anyway)"; \
						notfound=1; \
					else \
						notfound=0; \
					fi; \
				else \
					${ECHO_MSG} "===>   ${PKGNAME} depends on package: $$prog - not found"; \
					notfound=1; \
				fi; \
				if [ $$notfound != 0 ]; then \
					inverse_dep=`${ECHO_CMD} $$prog | ${SED} \
						-e 's/<=/=gt=/; s/</=ge=/; s/>=/=lt=/; s/>/=le=/' \
						-e 's/=gt=/>/; s/=ge=/>=/; s/=lt=/</; s/=le=/<=/'`; \
					pkg_info=`${PKG_INFO} -E "$$inverse_dep" || ${TRUE}`; \
					if [ "$$pkg_info" != "" ]; then \
						${ECHO_MSG} "===>   Found $$pkg_info, but you need to upgrade to $$prog."; \
						exit 1; \
					fi; \
				fi; \
			elif ${WHICH} "$$prog" > /dev/null 2>&1 ; then \
				${ECHO_MSG} "===>   ${PKGNAME} depends on executable: $$prog - found"; \
				if [ ${_DEPEND_ALWAYS} = 1 ]; then \
					${ECHO_MSG} "       (but building it anyway)"; \
					notfound=1; \
				else \
					notfound=0; \
				fi; \
			else \
				${ECHO_MSG} "===>   ${PKGNAME} depends on executable: $$prog - not found"; \
				notfound=1; \
			fi; \
		fi; \
		if [ $$notfound != 0 ]; then \
			${ECHO_MSG} "===>    Verifying $$target for $$prog in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} "     => No directory for $$prog.  Skipping.."; \
			else \
				${_INSTALL_DEPENDS} \
			fi; \
		fi; \
	done
.endif
.else
	@${DO_NADA}
.endif
.endfor

lib-depends:
.if defined(LIB_DEPENDS) && !defined(NO_DEPENDS)
	@set -e ; \
	for i in ${LIB_DEPENDS:M*.so*\:*}; do \
		lib=$${i%%:*} ; \
		dir=$${i#*:}  ; \
		target="${DEPENDS_TARGET}"; \
		depends_args="${DEPENDS_ARGS}"; \
		${ECHO_MSG}  -n "===>   ${PKGNAME} depends on shared library: $${lib}" ; \
		found=0 ; \
		dirs="${LIB_DIRS} `${CAT} ${LOCALBASE}/libdata/ldconfig/* 2>/dev/null || : `" ; \
		for libdir in $$dirs; do \
			test -f $${libdir}/$${lib} || continue; \
			if [ -x /usr/bin/file ]; then \
				_LIB_FILE=`realpath $${libdir}/$${lib}`; \
				[ `file -b -L --mime-type $${_LIB_FILE}` = "application/x-sharedlib" ] || continue ; \
			fi ; \
			found=1 ; \
			${ECHO_MSG} " - found"; \
		done ; \
		if [ $${found} -eq 0 ]; then \
			${ECHO_MSG} " - not found"; \
			${ECHO_MSG} "===>    Verifying for $$lib in $$dir"; \
			if [ ! -d "$$dir" ] ; then \
				${ECHO_MSG} "    => No directory for $$lib.  Skipping.."; \
			else \
				${_INSTALL_DEPENDS} \
			fi ; \
		fi ; \
	done
	@set -e ; for i in ${LIB_DEPENDS:N*.so*\:*}; do \
		lib=$${i%%:*}; \
		pattern="`${ECHO_CMD} $$lib | ${SED} -E -e 's/\./\\\\./g' -e 's/(\\\\)?\+/\\\\+/g'`"\
		dir=$${i#*:}; \
		target=$${i##*:}; \
		if ${TEST} $$dir = $$target; then \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		else \
			dir=$${dir%%:*}; \
		fi; \
		${ECHO_MSG} -n "===>   ${PKGNAME} depends on shared library: $$lib"; \
		if ${LDCONFIG} ${_LDCONFIG_FLAGS} -r | ${GREP} -vwF -e "${PKGCOMPATDIR}" | ${GREP} -qwE -e "-l$$pattern"; then \
			${ECHO_MSG} " - found"; \
			if [ ${_DEPEND_ALWAYS} = 1 ]; then \
				${ECHO_MSG} "       (but building it anyway)"; \
				notfound=1; \
			else \
				notfound=0; \
			fi; \
		else \
			${ECHO_MSG} " - not found"; \
			notfound=1; \
		fi; \
		if [ $$notfound != 0 ]; then \
			${ECHO_MSG} "===>    Verifying $$target for $$lib in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} "     => No directory for $$lib.  Skipping.."; \
			else \
				${_INSTALL_DEPENDS} \
				if ! ${LDCONFIG} ${_LDCONFIG_FLAGS} -r | ${GREP} -vwF -e "${PKGCOMPATDIR}" | ${GREP} -qwE -e "-l$$pattern"; then \
					${ECHO_MSG} "Error: shared library \"$$lib\" does not exist"; \
					${FALSE}; \
				fi; \
			fi; \
		fi; \
	done
.endif

.endif

# Dependency lists: both build and runtime, recursive.  Print out directory names.

_UNIFIED_DEPENDS=${PKG_DEPENDS} ${EXTRACT_DEPENDS} ${PATCH_DEPENDS} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS} ${RUN_DEPENDS}
_DEPEND_DIRS=	${_UNIFIED_DEPENDS:C,^[^:]*:([^:]*).*$,\1,}
_DEPEND_SPECIALS=	${_UNIFIED_DEPENDS:M*\:*\:*:C,^[^:]*:([^:]*):.*$,\1,}

all-depends-list:
	@${ALL-DEPENDS-LIST}

ALL-DEPENDS-LIST= \
	L="${_DEPEND_DIRS}";						\
	checked="";							\
	while [ -n "$$L" ]; do						\
		l="";							\
		for d in $$L; do					\
			case $$checked in				\
			$$d\ *|*\ $$d\ *|*\ $$d)			\
				continue;;				\
			esac;						\
			checked="$$checked $$d";			\
			if [ ! -d $$d ]; then				\
				${ECHO_MSG} "${PKGNAME}: \"$$d\" non-existent -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			${ECHO_CMD} $$d;				\
			if ! children=$$(cd $$d && ${MAKE} -V _DEPEND_DIRS); then\
				${ECHO_MSG} "${PKGNAME}: \"$$d\" erroneous -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			for child in $$children; do			\
				case "$$checked $$l" in			\
				$$child\ *|*\ $$child\ *|*\ $$child)	\
					continue;;			\
				esac;					\
				l="$$l $$child";			\
			done;						\
		done;							\
		L=$$l;							\
	done

CLEAN-DEPENDS-FULL= \
	L="${_DEPEND_DIRS}";						\
	checked="";							\
	while [ -n "$$L" ]; do						\
		l="";							\
		for d in $$L; do					\
			case $$checked in				\
			$$d\ *|*\ $$d\ *|*\ $$d)			\
				continue;;				\
			esac;						\
			checked="$$checked $$d";			\
			if [ ! -d $$d ]; then				\
				${ECHO_MSG} "${PKGNAME}: \"$$d\" non-existent -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			if ! children=$$(cd $$d && ${MAKE} -V WRKDIR -V _DEPEND_DIRS); then \
				${ECHO_MSG} "${PKGNAME}: \"$$d\" erroneous -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			state=0;					\
			for child in $$children; do			\
				case $$state in				\
				0)					\
					if [ -d $$child ]; then 	\
						${ECHO_CMD} $$d;	\
					fi;				\
					state=1;;			\
				1)					\
					case "$$checked $$l" in		\
					$$child\ *|*\ $$child\ *|*\ $$child) \
						continue;;		\
					esac;				\
					l="$$l $$child";;		\
				esac;					\
			done;						\
		done;							\
		L=$$l;							\
	done

CLEAN-DEPENDS-LIMITED= \
	L="${_DEPEND_DIRS}";						\
	checked="";							\
	while [ -n "$$L" ]; do						\
		l="";							\
		for d in $$L; do					\
			case $$checked in				\
			$$d\ *|*\ $$d\ *|*\ $$d)			\
				continue;;				\
			esac;						\
			checked="$$checked $$d";			\
			if [ ! -d $$d ]; then				\
				${ECHO_MSG} "${PKGNAME}: \"$$d\" non-existent -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			if ! children=$$(cd $$d && ${MAKE} -V WRKDIR -V _DEPEND_DIRS); then \
				${ECHO_MSG} "${PKGNAME}: \"$$d\" erroneous -- dependency list incomplete" >&2; \
				continue;				\
			fi;						\
			state=0;					\
			for child in $$children; do			\
				case $$state in				\
				0)					\
					if [ ! -d $$child ]; then 	\
						break;		\
					fi;				\
					state=1;			\
					${ECHO_CMD} $$d;;		\
				1)					\
					case "$$checked $$l" in		\
					$$child\ *|*\ $$child\ *|*\ $$child) \
						continue;;		\
					esac;				\
					l="$$l $$child";;		\
				esac;					\
			done;						\
		done;							\
		L=$$l;							\
	done

.if !target(clean-depends)
clean-depends:
	@for dir in $$(${CLEAN-DEPENDS-FULL}); do \
		(cd $$dir; ${MAKE} NOCLEANDEPENDS=yes clean); \
	done
.endif

.if !target(limited-clean-depends)
limited-clean-depends:
	@for dir in $$(${CLEAN-DEPENDS-LIMITED}); do \
		(cd $$dir; ${MAKE} NOCLEANDEPENDS=yes clean); \
	done
.endif

.if !target(deinstall-depends)
deinstall-depends:
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} deinstall); \
	done
.endif

.if !target(fetch-specials)
fetch-specials:
	@${ECHO_MSG} "===> Fetching all distfiles required by ${PKGNAME} for building"
	@for dir in ${_DEPEND_SPECIALS}; do \
		(cd $$dir; ${MAKE} fetch); \
	done
.endif

.if !target(fetch-recursive)
fetch-recursive:
	@${ECHO_MSG} "===> Fetching all distfiles for ${PKGNAME} and dependencies"
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} fetch); \
	done
.endif

.if !target(fetch-recursive-list)
fetch-recursive-list:
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} fetch-list); \
	done
.endif

# Used by fetch-required and fetch-required list, this script looks
# at each of the dependencies. If 3 items are specified in the tuple,
# such as foo:${PORTSDIR}/graphics/foo:extract, the first item (foo)
# is examined. Only if it begins with a / and does not exist on the
# file-system will ``make targ'' proceed.
# For more usual (dual-item) dependency tuples, the ``make targ''
# proceeds, if the exact package, which the directory WOULD'VE installed,
# is not yet installed.
# This is the exact behaviour of the old code, and it may need
# revisiting. For example, the entire first case seems dubious, and in
# the second case we, probably, should be satisfied with _any_ (earlier)
# package, with the same origin as that of the dir.
#
#	-mi
FETCH_LIST?=	for i in $$deps; do \
		prog=$${i%%:*}; dir=$${i\#*:}; \
		case $$dir in	\
		*:*) if [ $$prog != $${prog\#/} -o ! -e $$prog ]; then	\
				dir=$${dir%%:*};	\
			else	\
				continue;	\
			fi;;	\
		*) if [ -d ${PKG_DBDIR}/$$(cd $$dir; ${MAKE} -V PKGNAME) ]; then \
				continue;	\
			fi;;	\
		esac;	\
		echo cd $$dir; cd $$dir; ${MAKE} $$targ; \
	done

.if !target(fetch-required)
fetch-required: fetch
.if defined(NO_DEPENDS)
	@${ECHO_MSG} "===> NO_DEPENDS is set, not fetching any other distfiles for ${PKGNAME}"
.else
	@${ECHO_MSG} "===> Fetching all required distfiles for ${PKGNAME} and dependencies"
.for deptype in PKG EXTRACT PATCH FETCH BUILD RUN
.if defined(${deptype}_DEPENDS)
	@targ=fetch; deps="${${deptype}_DEPENDS}"; ${FETCH_LIST}
.endif
.endfor
.endif

.endif

.if !target(fetch-required-list)
fetch-required-list: fetch-list
.if !defined(NO_DEPENDS)
.for deptype in PKG EXTRACT PATCH FETCH BUILD RUN
.if defined(${deptype}_DEPENDS)
	@targ=fetch-list; deps="${${deptype}_DEPENDS}"; ${FETCH_LIST}
.endif
.endfor
.endif
.endif

.if !target(checksum-recursive)
checksum-recursive:
	@${ECHO_MSG} "===> Fetching and checking checksums for ${PKGNAME} and dependencies"
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} checksum); \
	done
.endif

# Dependency lists: build and runtime.  Print out directory names.

build-depends-list:
.if defined(PKG_DEPENDS) || defined(EXTRACT_DEPENDS) || defined(PATCH_DEPENDS) || defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || defined(LIB_DEPENDS)
	@${BUILD-DEPENDS-LIST}
.endif

BUILD-DEPENDS-LIST= \
	for dir in $$(${ECHO_CMD} "${PKG_DEPENDS} ${EXTRACT_DEPENDS} ${PATCH_DEPENDS} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS}" | ${SED} -E -e 's,([^: ]*):([^: ]*)(:[^ ]*)?,\2,g' -e 'y/ /\n/'| ${SORT} -u); do \
		if [ -d $$dir ]; then \
			${ECHO_CMD} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | ${SORT} -u

run-depends-list:
.if defined(LIB_DEPENDS) || defined(RUN_DEPENDS)
	@${RUN-DEPENDS-LIST}
.endif

RUN-DEPENDS-LIST= \
	for dir in $$(${ECHO_CMD} "${_LIB_RUN_DEPENDS:C,.*:([^:]*).*,\1,}" | ${SED} -e 'y/ /\n/' | ${SORT} -u); do \
		if [ -d $$dir ]; then \
			${ECHO_CMD} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | ${SORT} -u

# Package (recursive runtime) dependency list.  Print out both directory names
# and package names.

package-depends-list:
.if defined(CHILD_DEPENDS) || defined(LIB_DEPENDS) || defined(RUN_DEPENDS)
	@${PACKAGE-DEPENDS-LIST}
.endif

_LIB_RUN_DEPENDS=	${LIB_DEPENDS} ${RUN_DEPENDS}
PACKAGE-DEPENDS-LIST?= \
	if [ "${CHILD_DEPENDS}" ]; then \
		installed=$$(${PKG_INFO} -qO ${PKGORIGIN} 2>/dev/null || \
			${TRUE}); \
		if [ "$$installed" ]; then \
			break; \
		fi; \
		if [ -z "$$installed" ]; then \
			installed="${PKGNAME}"; \
		fi; \
		for pkgname in $$installed; do \
			${ECHO_CMD} "$$pkgname ${.CURDIR} ${PKGORIGIN}"; \
		done; \
	fi; \
	checked="${PARENT_CHECKED}"; \
	for dir in ${_LIB_RUN_DEPENDS:C,[^:]*:([^:]*):?.*,\1,}; do \
		dir=$$(${REALPATH} $$dir); \
		if [ -d $$dir ]; then \
			case $$checked in	\
			$$dir|$$dir\ *|*\ $$dir|*\ $$dir\ *) continue;;	\
			esac;	\
			childout=$$(cd $$dir; ${MAKE} CHILD_DEPENDS=yes PARENT_CHECKED="$$checked" package-depends-list); \
			set -- $$childout; \
			childdir=""; \
			while [ $$\# != 0 ]; do \
				childdir="$$childdir $$2"; \
				${ECHO_CMD} "$$1 $$2 $$3"; \
				shift 3; \
			done; \
			checked="$$dir $$childdir $$checked"; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done

ACTUAL-PACKAGE-DEPENDS?= \
	if [ "${_LIB_RUN_DEPENDS}" != "  " ]; then \
		origins=$$(for pkgname in ${PKG_DBDIR}/*; do \
			if [ -e $$pkgname/+CONTENTS ]; then \
				${ECHO_CMD} $${pkgname\#\#*/}; \
				${SED} -n -e "s/@comment ORIGIN://p" $$pkgname/+CONTENTS; \
			fi; \
		done); \
		for dir in ${_LIB_RUN_DEPENDS:C,[^:]*:([^:]*):?.*,\1,}; do \
			tmp=$${dir\#${PORTSDIR}/}; \
			if [ "$$tmp" = "$$dir" ]; then \
				tmp=$${dir%/*}; \
				dir=$${tmp\#\#*/}/$${dir\#\#*/}; \
			else \
				dir=$$tmp; \
			fi; \
			set -- $$origins; \
			while [ $$\# -gt 1 ]; do \
				if [ ! -d "${PORTSDIR}/$$2" ]; then \
					shift; \
					continue; \
				fi; \
				if [ "$$dir" = "$$2" ]; then \
					${ECHO_CMD} $$1:$$dir; \
					if [ -e ${PKG_DBDIR}/$$1/+CONTENTS -a -z "${EXPLICIT_PACKAGE_DEPENDS}" ]; then \
						packagelist="$$packagelist ${PKG_DBDIR}/$$1/+CONTENTS"; \
					fi; \
					break; \
				fi; \
				shift 2; \
			done; \
		done; \
		[ -z "$$packagelist" ] || ${AWK} -F '( |:)' 'BEGIN { pkgname="broken_contents" } /@pkgdep / { pkgname=$$2 } /@comment DEPORIGIN:/ { printf "%s:%s\n", pkgname, $$3; pkgname="broken_contents" }' $$packagelist; \
	fi

# Print out package names.

package-depends:
	@${PACKAGE-DEPENDS-LIST} | ${AWK} '{print $$1":"$$3}'

actual-package-depends:
	@${ACTUAL-PACKAGE-DEPENDS}

# Build packages for port and dependencies

package-recursive: package
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} package-noinstall); \
	done

# Show missing dependencies
missing:
	@_origins=$$(${PKG_INFO} -aoq); \
	for dir in $$(${ALL-DEPENDS-LIST}); do \
		_origin=$${dir##${PORTSDIR}/}; \
		if ! $$(${ECHO_CMD} $${_origins} | ${GREP} -q $${_origin}); then \
			${ECHO_CMD} $${_origin}; \
		fi; \
	done

################################################################
# Everything after here are internal targets and really
# shouldn't be touched by anybody but the release engineers.
################################################################

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|port-path|installation-prefix|comment| \
#  description-file|maintainer|categories|extract-depends| \
#  patch-depends|fetch-depends|build-depends|run-depends|www site
#
# If this ever changes, portmgr should contact the portsnap maintainer
# first to avoid gratuitous breakage.

. if !target(describe)
_EXTRACT_DEPENDS=${EXTRACT_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u}
_PATCH_DEPENDS=${PATCH_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u}
_FETCH_DEPENDS=${FETCH_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u}
_LIB_DEPENDS=${LIB_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u}
_BUILD_DEPENDS=${BUILD_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u} ${_LIB_DEPENDS}
_RUN_DEPENDS=${RUN_DEPENDS:C/^[^ :]+:([^ :]+)(:[^ :]+)?/\1/:O:u} ${_LIB_DEPENDS}
. if exists(${DESCR})
_DESCR=${DESCR}
. else
_DESCR=/dev/null
. endif

.  if defined(BUILDING_INDEX) && defined(INDEX_PORTS)
INDEX_OUT=${INDEX_TMPDIR}/${INDEXFILE}.desc.aggr
.  else
INDEX_OUT=/dev/stdout
.  endif

describe:
	@(${ECHO_CMD} -n "${PKGNAME}|${.CURDIR}|${PREFIX}|"; \
	${ECHO_CMD} -n ${COMMENT:Q}; \
	${ECHO_CMD} -n "|${_DESCR}|${MAINTAINER}|${CATEGORIES}|${_EXTRACT_DEPENDS}|${_PATCH_DEPENDS}|${_FETCH_DEPENDS}|${_BUILD_DEPENDS:O:u}|${_RUN_DEPENDS:O:u}|"; \
	while read one two discard; do \
		case "$$one" in \
		WWW:)   case "$$two" in \
			https://*|http://*|ftp://*) ${ECHO_CMD} -n "$$two" ;; \
			*) ${ECHO_CMD} -n "http://$$two" ;; \
			esac; \
			break; \
			;; \
		esac; \
	done < ${DESCR}; ${ECHO_CMD}) >>${INDEX_OUT}
. endif

www-site:
.if exists(${DESCR})
	@${AWK} '$$1 ~ /^WWW:/ {print $$2}' ${DESCR} | ${HEAD} -1
.else
	@${ECHO_CMD}
.endif

.if !target(readmes)
readmes:	readme
.endif

.if !target(readme)
readme:
	@${RM} -f ${.CURDIR}/README.html
	@cd ${.CURDIR} && ${MAKE} ${.CURDIR}/README.html
.endif

${.CURDIR}/README.html:
	@${ECHO_MSG} "===>   Creating README.html for ${PKGNAME}"
	@${SED} -e 's|%%PORT%%|'$$(${ECHO_CMD} ${.CURDIR} | \
							  ${SED} -e 's|.*/\([^/]*/[^/]*\)$$|\1|')'|g' \
			-e 's|%%PKG%%|${PKGNAME}|g' \
			-e 's|%%COMMENT%%|'"$$(${ECHO_CMD} ${COMMENT:Q})"'|' \
			-e '/%%COMMENT%%/d' \
			-e 's|%%DESCR%%|'"$$(${ECHO_CMD} ${DESCR} | \
								 ${SED} -e 's|${.CURDIR}/||')"'|' \
			-e 's|%%EMAIL%%|'"$$(${ECHO_CMD} "${MAINTAINER}" | \
								 ${SED} -e 's/([^)]*)//;s/.*<//;s/>.*//')"'|g' \
			-e 's|%%MAINTAINER%%|${MAINTAINER}|g' \
			-e 's|%%WEBSITE%%|'"$$(cd ${.CURDIR} && eval ${MAKE} pretty-print-www-site)"'|' \
			-e 's|%%BUILD_DEPENDS%%|'"$$(cd ${.CURDIR} && eval ${MAKE} pretty-print-build-depends-list)"'|' \
			-e 's|%%RUN_DEPENDS%%|'"$$(cd ${.CURDIR} && eval ${MAKE} pretty-print-run-depends-list)"'|' \
			-e 's|%%TOP%%|'"$$(${ECHO_CMD} ${CATEGORIES} | \
							   ${SED} -e 's| .*||' -e 's|[^/]*|..|g')"'/..|' \
		${TEMPLATES}/README.port >> ${.TARGET}

# The following two targets require an up-to-date INDEX in ${PORTSDIR}

_PRETTY_PRINT_DEPENDS_LIST=\
	if [ ! -r ${INDEXDIR}/${INDEXFILE} ] ; then \
		${ECHO_MSG} "${.TARGET} requires an INDEX file (${INDEXFILE}). Please run make index or make fetchindex."; \
	else \
		target=${.TARGET:C/pretty-print-(.*)-depends-list/\1/} ; \
		if [ "$$target" = "build" ] ; then fldnum=8 ; else fldnum=9 ; fi; \
		${ECHO_MSG} -n 'This port requires package(s) "' ; \
		${ECHO_MSG} -n `${AWK} -F\| "\\$$1 ~ /^${PKGNAME}/ {print \\$$$${fldnum};}" ${INDEXDIR}/${INDEXFILE}` ; \
		${ECHO_MSG} "\" to $$target."; \
	fi;


.if !target(pretty-print-build-depends-list)
pretty-print-build-depends-list:
.if defined(PKG_DEPENDS) || defined(EXTRACT_DEPENDS) || defined(PATCH_DEPENDS) || \
	defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || defined(LIB_DEPENDS)
	@${_PRETTY_PRINT_DEPENDS_LIST}
.endif
.endif

.if !target(pretty-print-run-depends-list)
pretty-print-run-depends-list:
.if defined(RUN_DEPENDS) || defined(LIB_DEPENDS)
	@${_PRETTY_PRINT_DEPENDS_LIST}
.endif
.endif

_SUB_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}
.if !target(apply-slist)
apply-slist:
.if defined(SUB_FILES)
.for file in ${SUB_FILES}
.if !exists(${FILESDIR}/${file}.in)
	@${ECHO_MSG} "** Missing ${FILESDIR}/${file}.in for ${PKGNAME}."; exit 1
.else
	@${SED} ${_SUB_LIST_TEMP} -e '/^@comment /d' ${FILESDIR}/${file}.in > ${WRKDIR}/${file}
.endif
.endfor
.for i in pkg-message pkg-install pkg-deinstall pkg-req
.if ${SUB_FILES:M${i}*}!=""
${i:S/-//:U}=	${WRKDIR}/${SUB_FILES:M${i}*}
.endif
.endfor
.endif
.endif

# Generate packing list.  Also tests to make sure all required package
# files exist.

.if !target(generate-plist)
generate-plist:
	@${ECHO_MSG} "===>   Generating temporary packing list"
	@${MKDIR} `${DIRNAME} ${TMPPLIST}`
	@if [ ! -f ${DESCR} ]; then ${ECHO_MSG} "** Missing pkg-descr for ${PKGNAME}."; exit 1; fi
.if defined(NO_STAGE) || defined(NEED_ROOT)
	@>${TMPPLIST}
.else
	@${ECHO_CMD} -e "@owner root\n@group wheel" >${TMPPLIST}
.endif
	@for file in ${PLIST_FILES}; do \
		${ECHO_CMD} $${file} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} >> ${TMPPLIST}; \
	done
.if defined(NO_STAGE)
	@for man in ${__MANPAGES}; do \
		${ECHO_CMD} $${man} >> ${TMPPLIST}; \
	done
.for _PREFIX in ${PREFIX}
.if ${_TMLINKS:M${_PREFIX}*}x != x
	@for i in ${_TMLINKS:M${_PREFIX}*:S|^${_PREFIX}/||}; do \
		${ECHO_CMD} "$$i" >> ${TMPPLIST}; \
	done
.endif
.if ${_TMLINKS:N${_PREFIX}*}x != x
	@${ECHO_CMD} @cwd / >> ${TMPPLIST}
	@for i in ${_TMLINKS:N${_PREFIX}*:S|^/||}; do \
		${ECHO_CMD} "$$i" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} '@cwd ${PREFIX}' >> ${TMPPLIST}
.endif
.endfor
.endif
	@if [ -f ${PLIST} ]; then \
		${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${PLIST} >> ${TMPPLIST}; \
	fi
 
.for dir in ${PLIST_DIRS}
	@${ECHO_CMD} ${dir} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} -e 's,^,@dirrm ,' >> ${TMPPLIST}
.endfor
.for dir in ${PLIST_DIRSTRY}
	@${ECHO_CMD} ${dir} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} -e 's,^,@dirrmtry ,' >> ${TMPPLIST}
.endfor

.for reinplace in ${PLIST_REINPLACE}
.if defined(PLIST_REINPLACE_${reinplace:U})
	@${SED} -i "" -e '${PLIST_REINPLACE_${reinplace:U}}' ${TMPPLIST}
.endif
.endfor

.if defined(USE_LINUX_PREFIX)
.if defined(USE_LDCONFIG)
	@${ECHO_CMD} "@exec ${LDCONFIG_CMD}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG_CMD}" >> ${TMPPLIST}
.endif
.else
.if defined(USE_LDCONFIG)
.if !defined(INSTALL_AS_USER)
	@${ECHO_CMD} "@exec ${LDCONFIG} -m ${USE_LDCONFIG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -R" >> ${TMPPLIST}
.else
	@${ECHO_CMD} "@exec ${LDCONFIG} -m ${USE_LDCONFIG} || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -R || ${TRUE}" >> ${TMPPLIST}
.endif
.endif
.if defined(USE_LDCONFIG32)
.if !defined(INSTALL_AS_USER)
	@${ECHO_CMD} "@exec ${LDCONFIG} -32 -m ${USE_LDCONFIG32}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -32 -R" >> ${TMPPLIST}
.else
	@${ECHO_CMD} "@exec ${LDCONFIG} -32 -m ${USE_LDCONFIG32} || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -32 -R || ${TRUE}" >> ${TMPPLIST}
.endif
.endif
.endif
.if !defined(WITH_PKGNG)
	@cd ${.CURDIR} && { ${MAKE} pretty-print-config | fold -sw 120 | ${SED} -e 's/^/@comment OPTIONS:/'; } >> ${TMPPLIST}
.endif
.endif

${TMPPLIST}:
	@cd ${.CURDIR} && ${MAKE} generate-plist

${TMPPLIST_SORT}: ${TMPPLIST}
	@${SORT} -u ${TMPPLIST} >${TMPPLIST_SORT}

.if !target(add-plist-docs)
add-plist-docs:
.if defined(PORTDOCS) && !defined(NOPORTDOCS)
	@if ${EGREP} -qe '^@cw?d' ${TMPPLIST} && \
		[ "`${SED} -En -e '/^@cw?d[ 	]*/s,,,p' ${TMPPLIST} | ${TAIL} -n 1`" != "${PREFIX}" ]; then \
		${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}; \
	fi
.for x in ${PORTDOCS}
	@if ${ECHO_CMD} "${x}"| ${AWK} '$$1 ~ /(\*|\||\[|\]|\?|\{|\}|\$$)/ { exit 1};'; then \
		if [ ! -e ${STAGEDIR}${DOCSDIR}/${x} ]; then \
		${ECHO_CMD} ${DOCSDIR_REL}/${x} >> ${TMPPLIST}; \
	fi;fi
.endfor
	@${FIND} -P ${PORTDOCS:S/^/${STAGEDIR}${DOCSDIR}\//} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PORTDOCS:S/^/${STAGEDIR}${DOCSDIR}\//} -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DOCSDIR_REL}" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif
.endif

.if !target(add-plist-examples)
add-plist-examples:
.if defined(PORTEXAMPLES) && !defined(NOPORTEXAMPLES)
	@if ${EGREP} -qe '^@cw?d' ${TMPPLIST} && \
		[ "`${SED} -En -e '/^@cw?d[ 	]*/s,,,p' ${TMPPLIST} | ${TAIL} -n 1`" != "${PREFIX}" ]; then \
		${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}; \
	fi
.for x in ${PORTEXAMPLES}
	@if ${ECHO_CMD} "${x}"| ${AWK} '$$1 ~ /(\*|\||\[|\]|\?|\{|\}|\$$)/ { exit 1};'; then \
		if [ ! -e ${STAGEDIR}${EXAMPLESDIR}/${x} ]; then \
		${ECHO_CMD} ${EXAMPLESDIR}/${x} | \
			${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}; \
	fi;fi
.endfor
	@${FIND} -P ${PORTEXAMPLES:S/^/${STAGEDIR}${EXAMPLESDIR}\//} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PORTEXAMPLES:S/^/${STAGEDIR}${EXAMPLESDIR}\//} -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${EXAMPLESDIR_REL}" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif
.endif

.if !target(add-plist-data)
add-plist-data:
.if defined(PORTDATA) && !defined(NOPORTDATA)
	@if ${EGREP} -qe '^@cw?d' ${TMPPLIST} && \
		[ "`${SED} -En -e '/^@cw?d[ 	]*/s,,,p' ${TMPPLIST} | ${TAIL} -n 1`" != "${PREFIX}" ]; then \
		${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}; \
	fi
.for x in ${PORTDATA}
	@if ${ECHO_CMD} "${x}"| ${AWK} '$$1 ~ /(\*|\||\[|\]|\?|\{|\}|\$$)/ { exit 1};'; then \
		if [ ! -e ${STAGEDIR}${DATADIR}/${x} ]; then \
		${ECHO_CMD} ${DATADIR}/${x} | \
			${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}; \
	fi;fi
.endfor
	@${FIND} -P ${PORTDATA:S/^/${STAGEDIR}${DATADIR}\//} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PORTDATA:S/^/${STAGEDIR}${DATADIR}\//} -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR_REL}" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif
.endif

.if !target(add-plist-buildinfo)
add-plist-buildinfo:
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "@comment Build details:  ${BUILDHOST}|${JAIL}|${BUILD}|${PORTSTREE}|${BUILDDATE}" >> ${TMPPLIST}
.endif
.endif

.if !target(add-plist-info)
add-plist-info:
# Process GNU INFO files at package install/deinstall time
.if defined(INFO)
.for i in ${INFO}
	install-info --quiet ${PREFIX}/${INFO_PATH}/$i.info ${PREFIX}/${INFO_PATH}/dir
.if !defined(WITH_PKGNG)
	@${ECHO_CMD} "@unexec install-info --quiet --delete %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ \`info -d %D/${INFO_PATH}  --output - 2>/dev/null | grep -c '^*'\` -eq 1 ] && rm -f %D/${INFO_PATH}/dir || :"\
		>> ${TMPPLIST}
	@${LS} ${PREFIX}/${INFO_PATH}/$i.info* | ${SED} -e s:${PREFIX}/::g >> ${TMPPLIST}
	@${ECHO_CMD} "@exec install-info --quiet %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
.else
	@${LS} ${PREFIX}/${INFO_PATH}/$i.info* | ${SED} -e s:${PREFIX}/:@info\ :g >> ${TMPPLIST}
.endif
.endfor
.if defined(INFO_SUBDIR)
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${INFO_PATH}/${INFO_SUBDIR} 2> /dev/null || true" >> ${TMPPLIST}
.endif
.if (${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec if [ -f %D/${INFO_PATH}/dir ]; then if sed -e '1,/Menu:/d' %D/${INFO_PATH}/dir | grep -q '^[*] '; then true; else rm %D/${INFO_PATH}/dir; fi; fi" >> ${TMPPLIST}
.if (${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE})
	@${ECHO_CMD} "@unexec rmdir %D/${INFO_PATH} 2>/dev/null || true" >> ${TMPPLIST}
.endif
.endif
.endif
.endif

# If we're installing into a non-standard PREFIX, we need to remove that directory at
# deinstall-time
.if !target(add-plist-post)
add-plist-post:
.if (${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec rmdir %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif
.endif

.if !target(install-rc-script)
install-rc-script:
.if defined(USE_RCORDER) || defined(USE_RC_SUBR) && ${USE_RC_SUBR:U} != "YES"
.if defined(USE_RCORDER)
	@${ECHO_MSG} "===> Staging early rc.d startup script(s)"
	@${ECHO_CMD} "@cwd /" >> ${TMPPLIST}
	@for i in ${USE_RCORDER}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$${i} ${STAGEDIR}/etc/rc.d/$${i%.sh}; \
		${ECHO_CMD} "etc/rc.d/$${i%.sh}" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
.endif
.if defined(USE_RC_SUBR) && ${USE_RC_SUBR:U} != "YES"
	@${ECHO_MSG} "===> Staging rc.d startup script(s)"
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@for i in ${USE_RC_SUBR}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$${i} ${STAGEDIR}${PREFIX}/etc/rc.d/$${i%.sh}; \
		${ECHO_CMD} "etc/rc.d/$${i%.sh}" >> ${TMPPLIST}; \
	done
.endif
.else
	@${DO_NADA}
.endif
.endif

# Compress (or uncompress) and symlink manpages.
.if !target(compress-man)
compress-man:
.if defined(_MANPAGES) || defined(_MLINKS)
.if ${MANCOMPRESSED} == yes && defined(NO_MANCOMPRESS)
	@${ECHO_MSG} "===>   Uncompressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GUNZIP_CMD} $${_manpages} ) || ${TRUE}
.elif ${MANCOMPRESSED} == no && !defined(NO_MANCOMPRESS)
	@${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GZIP_CMD} $${_manpages} ) || ${TRUE}
.endif
.if defined(_MLINKS)
	@set -- ${_MLINKS}; \
	while :; do \
		[ $$# -eq 0 ] && break || ${TRUE}; \
		${RM} -f $${2%.gz}; ${RM} -f $$2.gz; \
		${LN} -fs `${ECHO_CMD} $$1 $$2 | ${AWK} '{ \
					z=split($$1, a, /\//); x=split($$2, b, /\//); \
					while (a[i] == b[i]) i++; \
					for (q=i; q<x; q++) printf "../"; \
					for (; i<z; i++) printf a[i] "/"; printf a[z]; }'` $$2; \
		shift; shift; \
	done
.endif
.else
	@${DO_NADA}
.endif
.endif

# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed port is recognized correctly in
# accordance to the @pkgdep directive in the packing lists

.if !target(fake-pkg)
fake-pkg:
.if !defined(NO_PKG_REGISTER)
	@if [ ! -d ${PKG_DBDIR} ]; then ${RM} -f ${PKG_DBDIR}; ${MKDIR} ${PKG_DBDIR}; fi
	@${RM} -f /tmp/${PKGNAME}-required-by
.if defined(FORCE_PKG_REGISTER)
	@if [ -e ${PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY ]; then \
		${CP} ${PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY /tmp/${PKGNAME}-required-by; \
	fi
	@${RM} -rf ${PKG_DBDIR}/${PKGNAME}
.endif
	@if [ ! -d ${PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO_MSG} "===>   Registering installation for ${PKGNAME}"; \
		${MKDIR} ${PKG_DBDIR}/${PKGNAME}; \
		${PKG_CMD} ${PKG_ARGS} -O ${PKGFILE} > ${PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		${CP} ${DESCR} ${PKG_DBDIR}/${PKGNAME}/+DESC; \
		${ECHO_CMD} ${COMMENT:Q} > ${PKG_DBDIR}/${PKGNAME}/+COMMENT; \
		if [ -f ${PKGINSTALL} ]; then \
			${CP} ${PKGINSTALL} ${PKG_DBDIR}/${PKGNAME}/+INSTALL; \
		fi; \
		if [ -f ${PKGDEINSTALL} ]; then \
			${CP} ${PKGDEINSTALL} ${PKG_DBDIR}/${PKGNAME}/+DEINSTALL; \
		fi; \
		if [ -f ${PKGREQ} ]; then \
			${CP} ${PKGREQ} ${PKG_DBDIR}/${PKGNAME}/+REQUIRE; \
		fi; \
		if [ -f ${PKGMESSAGE} ]; then \
			${CP} ${PKGMESSAGE} ${PKG_DBDIR}/${PKGNAME}/+DISPLAY; \
			${ECHO_CMD} "@display +DISPLAY" >> ${PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		fi; \
		for dep in `${PKG_INFO} -qf ${PKGNAME} | ${AWK} '/^@pkgdep / {print $$2}' | ${SORT} -u`; do \
			if [ -d ${PKG_DBDIR}/$$dep -a -z `${ECHO_CMD} $$dep | ${GREP} -E ${PKG_IGNORE_DEPENDS}` ]; then \
				if ! ${GREP} ^${PKGNAME}$$ ${PKG_DBDIR}/$$dep/+REQUIRED_BY \
					>/dev/null 2>&1; then \
					${ECHO_CMD} ${PKGNAME} >> ${PKG_DBDIR}/$$dep/+REQUIRED_BY; \
				fi; \
			fi; \
		done; \
	fi
.if !defined(NO_MTREE)
	@if [ -f ${MTREE_FILE} ]; then \
		${CP} ${MTREE_FILE} ${PKG_DBDIR}/${PKGNAME}/+MTREE_DIRS; \
	fi
.endif
	@if [ -e /tmp/${PKGNAME}-required-by ]; then \
		${CAT} /tmp/${PKGNAME}-required-by >> ${PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY; \
		${RM} -f /tmp/${PKGNAME}-required-by; \
	fi
.else
	@${DO_NADA}
.endif
.endif

# Depend is generally meaningless for arbitrary ports, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `make depend all install' as a matter of course.
#
.if !target(depend)
depend:
.endif

# Same goes for tags
.if !target(tags)
tags:
.endif

.if !defined(NOPRECIOUSMAKEVARS)
# These won't change, so we can pass them through the environment
.MAKEFLAGS: \
	ARCH="${ARCH:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OPSYS="${OPSYS:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSREL="${OSREL:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSVERSION="${OSVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	SYSTEMVERSION="${SYSTEMVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}"
.endif

.if !target(pre-check-config)
pre-check-config:
.for single in ${OPTIONS_SINGLE}
.  for opt in ${OPTIONS_SINGLE_${single}}
.    if empty(ALL_OPTIONS:M${single}) || !empty(PORT_OPTIONS:M${single})
.      if !empty(PORT_OPTIONS:M${opt})
.        if defined(OPTFOUND)
OPTIONS_WRONG_SINGLE+=	${single}
.        else
OPTFOUND=	true
.        endif
.      endif
.    else
# if conditional and if the condition is unchecked, remove opt from the list of
# set options
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
OPTNOCHECK=	true
.    endif
.  endfor
.  if !defined(OPTFOUND) && !defined(OPTNOCHECK)
OPTIONS_WRONG_SINGLE+=	${single}
.  endif
.  undef OPTFOUND
.  undef OPTNOCHECK
.endfor
.undef single

.for radio in ${OPTIONS_RADIO}
.  for opt in ${OPTIONS_RADIO_${radio}}
.    if !empty(PORT_OPTIONS:M${opt})
.      if defined(OPTFOUND)
OPTIONS_WRONG_RADIO+=	${radio}
.      else
OPTFOUND=	true
.      endif
.    endif
.  endfor
.  undef OPTFOUND
.endfor

.for multi in ${OPTIONS_MULTI}
.  for opt in ${OPTIONS_MULTI_${multi}}
.    if empty(ALL_OPTIONS:M${multi}) || !empty(PORT_OPTIONS:M${multi})
.      if !empty(PORT_OPTIONS:M${opt})
OPTFOUND=	true
.      endif
.    else
# if conditional and if the condition is unchecked, remove opt from the list of
# set options
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
OPTNOCHECK=	true
.    endif
.  endfor
.  if !defined(OPTFOUND) && !defined(OPTNOCHECK)
OPTIONS_WRONG_MULTI+=	${multi}
.  endif
.  undef OPTFOUND
.  undef OPTNOCHECK
.endfor
.undef multi
.undef opt
.endif #pre-check-config

.if !target(_check-config)
_check-config: pre-check-config
.for multi in ${OPTIONS_WRONG_MULTI}
	@${ECHO_MSG} "====> You must check at least one option in the ${multi} multi"
.endfor
.for single in ${OPTIONS_WRONG_SINGLE}
	@${ECHO_MSG} "====> You must select one and only one option from the ${single} single"
.endfor
.for radio in ${OPTIONS_WRONG_RADIO}
	@${ECHO_MSG} "====> You cannot select multiple options from the ${radio} radio"
.endfor
.if !empty(OPTIONS_WRONG_MULTI) || !empty(OPTIONS_WRONG_SINGLE) || !empty(OPTIONS_WRONG_RADIO)
_CHECK_CONFIG_ERROR=	true
.endif
.endif # _check-config

.if !target(check-config)
check-config: _check-config
.if !empty(_CHECK_CONFIG_ERROR)
	@exit 1
.endif
.endif # check-config

.if !target(sanity-config)
sanity-config: _check-config
.if !empty(_CHECK_CONFIG_ERROR)
	@echo -n "Config is invalid. Re-edit? [Y/n] "; \
	read answer; \
	case $$answer in \
	[Nn]|[Nn][Oo]) \
		exit 0; \
	esac; \
	cd ${.CURDIR} && ${MAKE} config
.endif
.endif # sanity-config

.if !target(pre-config)
pre-config:
D4P_ENV=	PKGNAME="${PKGNAME}" \
		PORT_OPTIONS="${PORT_OPTIONS}" \
		ALL_OPTIONS="${ALL_OPTIONS}" \
		OPTIONS_MULTI="${OPTIONS_MULTI}" \
		OPTIONS_SINGLE="${OPTIONS_SINGLE}" \
		OPTIONS_RADIO="${OPTIONS_RADIO}" \
		OPTIONS_GROUP="${OPTIONS_GROUP}" \
		NEW_OPTIONS="${NEW_OPTIONS}" \
		DIALOG4PORTS="${DIALOG4PORTS}" \
		PREFIX="${PREFIX}" \
		LOCALBASE="${LOCALBASE}" \
		PORTSDIR="${PORTSDIR}" \
		MAKE="${MAKE}" \
		D4PHEIGHT="${D4PHEIGHT}" \
		D4PWIDTH="${D4PWIDTH}" \
		D4PFULLSCREEN="${D4PFULLSCREEN}"
.if exists(${PKGHELP})
D4P_ENV+=	PKGHELP="${PKGHELP}"
.endif
.for opt in ${ALL_OPTIONS}
D4P_ENV+=	 ${opt}_DESC=""${${opt}_DESC:Q}""
.endfor
.for otype in MULTI GROUP SINGLE RADIO
.  for m in ${OPTIONS_${otype}}
D4P_ENV+=	OPTIONS_${otype}_${m}="${OPTIONS_${otype}_${m}}" \
		${m}_DESC=""${${m}_DESC:Q}""
.    for opt in ${OPTIONS_${otype}_${m}}
D4P_ENV+=	 ${opt}_DESC=""${${opt}_DESC:Q}""
.    endfor
.  endfor
.endfor
.undef m
.undef otype
.undef opt
.endif # pre-config

.if !target(do-config)
do-config:
.if empty(ALL_OPTIONS) && empty(OPTIONS_SINGLE) && empty(OPTIONS_MULTI) && empty(OPTIONS_RADIO) && empty(OPTIONS_GROUP)
	@${ECHO_MSG} "===> No options to configure"
.else
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@optionsdir=${OPTIONS_FILE}; optionsdir=$${optionsdir%/*}; \
	oldoptionsdir=${OPTIONSFILE}; oldoptionsdir=$${oldoptionsdir%/*}; \
	${ECHO_MSG} "===>  Switching to root credentials to create $${optionsdir}"; \
	(${SU_CMD} "${SH} -c \"if [ -d $${oldoptionsdir} -a ! -d $${optionsdir} ]; then ${MV} $${oldoptionsdir} $${optionsdir}; elif [ -d $${oldoptionsdir} -a -d $${optionsdir} ]; then ${RM} -rf $${oldoptionsdir} ; fi ; ${MKDIR} $${optionsdir} 2> /dev/null\"") || \
		(${ECHO_MSG} "===> Cannot create $${optionsdir}, check permissions"; exit 1); \
	${ECHO_MSG} "===>  Returning to user credentials"
.else
	@optionsdir=${OPTIONS_FILE}; optionsdir=$${optionsdir%/*}; \
	oldoptionsdir=${OPTIONSFILE}; oldoptionsdir=$${oldoptionsdir%/*}; \
	if [ -d $${oldoptionsdir} -a ! -d $${optionsdir} ]; then \
		${MV} $${oldoptionsdir} $${optionsdir}; \
	elif [ -d $${oldoptionsdir} -a -d $${optionsdir} ]; then \
		${RM} -rf $${oldoptionsdir} ; \
	fi ; \
	${MKDIR} $${optionsdir} 2> /dev/null || \
	(${ECHO_MSG} "===> Cannot create $${optionsdir}, check permissions"; exit 1)
.endif
	@TMPOPTIONSFILE=$$(mktemp -t portoptions); \
	trap "${RM} -f $${TMPOPTIONSFILE}; exit 1" 1 2 3 5 10 13 15; \
	${SETENV} ${D4P_ENV} ${SH} ${SCRIPTSDIR}/dialog4ports.sh $${TMPOPTIONSFILE} || { \
		${RM} -f $${TMPOPTIONSFILE}; \
		${ECHO_MSG} "===> Options unchanged"; \
		exit 0; \
	}; \
	${ECHO_CMD}; \
	if [ ! -e $${TMPOPTIONSFILE} ]; then \
		${ECHO_MSG} "===> No user-specified options to save for ${PKGNAME}"; \
		exit 0; \
	fi; \
	SELOPTIONS=$$(${CAT} $${TMPOPTIONSFILE}); \
	${RM} -f $${TMPOPTIONSFILE}; \
	TMPOPTIONSFILE=$$(mktemp -t portoptions); \
	trap "${RM} -f $${TMPOPTIONSFILE}; exit 1" 1 2 3 5 10 13 15; \
	${ECHO_CMD} "# This file is auto-generated by 'make config'." > $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "# Options for ${PKGNAME}" >> $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "_OPTIONS_READ=${PKGNAME}" >> $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "_FILE_COMPLETE_OPTIONS_LIST=${COMPLETE_OPTIONS_LIST}" >> $${TMPOPTIONSFILE}; \
	for i in ${COMPLETE_OPTIONS_LIST}; do \
		if ${ECHO_CMD} $${SELOPTIONS} | ${GREP} -qw $${i}; then \
			${ECHO_CMD} "OPTIONS_FILE_SET+=$${i}" >> $${TMPOPTIONSFILE}; \
		else \
			${ECHO_CMD} "OPTIONS_FILE_UNSET+=$${i}" >> $${TMPOPTIONSFILE}; \
		fi; \
	done; \
	if [ ${UID} != 0 -a "x${INSTALL_AS_USER}" = "x" ]; then \
		${ECHO_MSG} "===>  Switching to root credentials to write ${OPTIONS_FILE}"; \
		${SU_CMD} "${CAT} $${TMPOPTIONSFILE} > ${OPTIONS_FILE}"; \
		${ECHO_MSG} "===>  Returning to user credentials"; \
	else \
		${CAT} $${TMPOPTIONSFILE} > ${OPTIONS_FILE}; \
	fi; \
	${RM} -f $${TMPOPTIONSFILE}
	@cd ${.CURDIR} && ${MAKE} sanity-config
.endif
.endif # do-config

.if !target(config)
.if !defined(NO_DIALOG)
config: pre-config do-config
.else
config:
	@${ECHO_MSG} "===> Skipping 'config' as NO_DIALOG is defined"
.endif
.endif # config

.if !target(config-recursive)
config-recursive:
	@${ECHO_MSG} "===> Setting user-specified options for ${PKGNAME} and dependencies";
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} config-conditional); \
	done
.endif # config-recursive

.if !target(config-conditional)
config-conditional:
.if !empty(NEW_OPTIONS)
	@cd ${.CURDIR} && ${MAKE} config;
.endif
.endif # config-conditional

.if !target(showconfig)
.include "${PORTSDIR}/Mk/bsd.options.desc.mk"
MULTI_EOL=	: you have to choose at least one of them
SINGLE_EOL=	: you have to select exactly one of them
RADIO_EOL=	: you can only select none or one of them
showconfig:
.if !empty(COMPLETE_OPTIONS_LIST)
	@${ECHO_MSG} "===> The following configuration options are available for ${PKGNAME}":
.for opt in ${ALL_OPTIONS}
	@[ -z "${PORT_OPTIONS:M${opt}}" ] || match="on" ; ${ECHO_MSG} -n "     ${opt}=$${match:-off}"
.  if !empty(${opt}_DESC)
	@${ECHO_MSG} -n ": "${${opt}_DESC:Q}
.  endif
	@${ECHO_MSG} ""
.endfor

#multi and conditional multis
.for otype in MULTI GROUP SINGLE RADIO
.  for m in ${OPTIONS_${otype}}
.    if empty(${m}_DESC)
		@${ECHO_MSG} "====> Options available for the ${otype:L} ${m}${${otype}_EOL}"
.    else
		@${ECHO_MSG} "====> ${${m}_DESC}${${otype}_EOL}"
.    endif
.    for opt in ${OPTIONS_${otype}_${m}}
	@[ -z "${PORT_OPTIONS:M${opt}}" ] || match="on" ; ${ECHO_MSG} -n "     ${opt}=$${match:-off}"
.      if !empty(${opt}_DESC)
	@${ECHO_MSG} -n ": "${${opt}_DESC:Q}
.      endif
	@${ECHO_MSG} ""
.    endfor
.  endfor
.endfor

.undef otype
.undef m
.undef opt
	@${ECHO_MSG} "===> Use 'make config' to modify these settings"
.endif
.endif # showconfig

.if !target(showconfig-recursive)
showconfig-recursive:
	@${ECHO_MSG} "===> The following configuration options are available for ${PKGNAME} and dependencies";
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} showconfig); \
	done
.endif # showconfig-recursive

.if !target(rmconfig)
rmconfig:
.if exists(${OPTIONSFILE})
	-@${ECHO_MSG} "===> Removing user-configured options for ${PKGNAME}"; \
	optionsdir=${OPTIONSFILE}; optionsdir=$${optionsdir%/*}; \
	if [ ${UID} != 0 -a "x${INSTALL_AS_USER}" = "x" ]; then \
		${ECHO_MSG} "===> Switching to root credentials to remove ${OPTIONSFILE} and $${optionsdir}"; \
		${SU_CMD} "${RM} -f ${OPTIONSFILE} ; \
			${RMDIR} $${optionsdir}"; \
		${ECHO_MSG} "===> Returning to user credentials"; \
	else \
		${RM} -f ${OPTIONSFILE}; \
		${RMDIR} $${optionsdir} 2>/dev/null || return 0; \
	fi
.endif
.if exists(${OPTIONS_FILE})
	-@${ECHO_MSG} "===> Removing user-configured options for ${PKGNAME}"; \
	optionsdir=${OPTIONS_FILE}; optionsdir=$${optionsdir%/*}; \
	if [ ${UID} != 0 -a "x${INSTALL_AS_USER}" = "x" ]; then \
		${ECHO_MSG} "===> Switching to root credentials to remove ${OPTIONS_FILE} and $${optionsdir}"; \
		${SU_CMD} "${RM} -f ${OPTIONS_FILE} ; \
			${RMDIR} $${optionsdir}"; \
		${ECHO_MSG} "===> Returning to user credentials"; \
	else \
		${RM} -f ${OPTIONS_FILE}; \
		${RMDIR} $${optionsdir} 2>/dev/null || return 0; \
	fi
.else
	@${ECHO_MSG} "===> No user-specified options configured for ${PKGNAME}"
.endif
.endif # rmconfig

.if !target(rmconfig-recursive)
rmconfig-recursive:
	@${ECHO_MSG} "===> Removing user-specified options for ${PKGNAME} and dependencies";
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} rmconfig); \
	done
.endif # rmconfig-recursive

.if !target(pretty-print-config)
MULTI_START=	[
MULTI_END=	]
GROUP_START=	[
GROUP_END=	]
SINGLE_START=	(
SINGLE_END=	)
RADIO_START=	(
RADIO_END=	)
pretty-print-config:
.for opt in ${ALL_OPTIONS}
	@[ -z "${PORT_OPTIONS:M${opt}}" ] || match="+" ; ${ECHO_MSG} -n "$${match:--}${opt} "
.endfor
.for otype in MULTI GROUP SINGLE RADIO
.  for m in ${OPTIONS_${otype}}
	@${ECHO_MSG} -n "${m}${${otype}_START} "
.    for opt in ${OPTIONS_${otype}_${m}}
		@[ -z "${PORT_OPTIONS:M${opt}}" ] || match="+" ; ${ECHO_MSG} -n "$${match:--}${opt} "
.    endfor
	@${ECHO_MSG} -n "${${otype}_END} "
.  endfor
.endfor
.undef otype
.undef m
.undef opt
	@${ECHO_MSG} ""
.endif # pretty-print-config

desktop-categories:
	@categories=""; \
	for native_category in ${CATEGORIES}; do \
		c=""; \
		case $$native_category in \
			accessibility)	c="Utility Accessibility"		;; \
			archivers)		c="Utility Archiving"			;; \
			astro)			c="Education Science Astronomy"	;; \
			audio)			c="AudioVideo Audio"			;; \
			benchmarks)		c="System"						;; \
			biology)		c="Education Science Biology"	;; \
			cad)			c="Graphics Engineering"		;; \
			comms)			c="Utility"						;; \
			converters)		c="Utility"						;; \
			databases)		c="Office Database"				;; \
			deskutils)		c="Utility"						;; \
			devel)			c="Development"					;; \
			dns)			c="Network"						;; \
			elisp)			c="Development"					;; \
			editors)		c="Utility"						;; \
			emulators)		c="System Emulator"				;; \
			finance)		c="Office Finance"				;; \
			ftp)			c="Network FileTransfer"		;; \
			games)			c="Game"						;; \
			geography)		c="Education Science Geography"	;; \
			gnome)			c="GNOME GTK"					;; \
			graphics)		c="Graphics"					;; \
			hamradio)		c="HamRadio"					;; \
			haskell)		c="Development"					;; \
			irc)			c="Network IRCClient"			;; \
			java)			c="Development Java"			;; \
			kde)			c="KDE Qt"						;; \
			lang)			c="Development"					;; \
			lisp)			c="Development"					;; \
			mail)			c="Office Email"				;; \
			math)			c="Education Science Math"		;; \
			mbone)			c="Network AudioVideo"			;; \
			multimedia)		c="AudioVideo"					;; \
			net)			c="Network"						;; \
			net-im)			c="Network InstantMessaging"	;; \
			net-mgmt)		c="Network"						;; \
			net-p2p)		c="Network P2P"					;; \
			news)			c="Network News"				;; \
			palm)			c="Office PDA"					;; \
			parallel)		c="ParallelComputing"			;; \
			pear)			c="Development WebDevelopment"	;; \
			perl5)			c="Development"					;; \
			python)			c="Development"					;; \
			ruby)			c="Development"					;; \
			rubygems)		c="Development"					;; \
			scheme)			c="Development"					;; \
			science)		c="Science Education"			;; \
			security)		c="System Security"				;; \
			shells)			c="System Shell"				;; \
			sysutils)		c="System"						;; \
			tcl*|tk*)		c="Development"					;; \
			textproc)		c="Utility TextTools"			;; \
			www)			c="Network"						;; \
			x11-clocks)		c="Utility Clock"				;; \
			x11-fm)			c="System FileManager"			;; \
			xfce)			c="GTK XFCE"					;; \
			zope)			c="Development WebDevelopment"	;; \
		esac; \
		if [ -n "$$c" ]; then \
			categories="$$categories $$c"; \
		fi; \
	done; \
	if [ -n "$$categories" ]; then \
		for c in $$categories; do ${ECHO_MSG} "$$c"; done \
			| ${SORT} -u | ${TR} '\n' ';'; \
		${ECHO_MSG}; \
	fi

# http://standards.freedesktop.org/menu-spec/menu-spec-latest.html
DESKTOP_CATEGORIES_MAIN=	AudioVideo Audio Video Development Education \
	Game Graphics Network Office Science Settings System Utility
DESKTOP_CATEGORIES_ADDITIONAL=	Building Debugger IDE GUIDesigner Profiling \
	RevisionControl Translation Calendar ContactManagement Database \
	Dictionary Chart Email Finance FlowChart PDA ProjectManagement \
	Presentation Spreadsheet WordProcessor 2DGraphics VectorGraphics \
	RasterGraphics 3DGraphics Scanning OCR Photography Publishing Viewer \
	TextTools DesktopSettings HardwareSettings Printing PackageManager \
	Dialup InstantMessaging Chat IRCClient Feed FileTransfer HamRadio News \
	P2P RemoteAccess Telephony TelephonyTools VideoConference WebBrowser \
	WebDevelopment Midi Mixer Sequencer Tuner TV AudioVideoEditing Player \
	Recorder DiscBurning ActionGame AdventureGame ArcadeGame BoardGame \
	BlocksGame CardGame KidsGame LogicGame RolePlaying Shooter Simulation \
	SportsGame StrategyGame Art Construction Music Languages \
	ArtificialIntelligence Astronomy Biology Chemistry ComputerScience \
	DataVisualization Economy Electricity Geography Geology Geoscience \
	History Humanities ImageProcessing Literature Maps Math \
	NumericalAnalysis MedicalSoftware Physics Robotics Spirituality Sports \
	ParallelComputing Amusement Archiving Compression Electronics Emulator \
	Engineering FileTools FileManager TerminalEmulator Filesystem Monitor \
	Security Accessibility Calculator Clock TextEditor Documentation Adult \
	Core KDE GNOME XFCE GTK Qt Motif Java ConsoleOnly
DESKTOP_CATEGORIES_RESERVED=	Screensaver TrayIcon Applet Shell

VALID_DESKTOP_CATEGORIES+=	${DESKTOP_CATEGORIES_MAIN} \
	${DESKTOP_CATEGORIES_ADDITIONAL} \
	${DESKTOP_CATEGORIES_RESERVED}

check-desktop-entries:
.if defined(DESKTOP_ENTRIES)
	@set -- ${DESKTOP_ENTRIES} XXX; \
	if [ `${EXPR} \( $$# - 1 \) % 6` -ne 0 ]; then \
		${ECHO_MSG} "${PKGNAME}: Makefile error: the DESKTOP_ENTRIES list must contain one or more groups of 6 elements"; \
		exit 1; \
	fi; \
	num=1; \
	while [ $$# -gt 6 ]; do \
		entry="#$$num"; \
		if [ -n "$$4" ]; then \
			entry="$$entry ($$4)"; \
		elif [ -n "$$1" ]; then \
			entry="$$entry ($$1)"; \
		fi; \
		if [ -z "$$1" ]; then \
			${ECHO_MSG} "${PKGNAME}: Makefile error: in desktop entry $$entry: field 1 (Name) is empty"; \
			exit 1; \
		fi; \
		if ${ECHO_CMD} "$$3" | ${GREP} -iq '.\(png\|svg\|xpm\)$$'; then \
			if ! ${ECHO_CMD} "$$3" | ${GREP} -iq '^/'; then \
				${ECHO_MSG} "${PKGNAME}: Makefile warning: in desktop entry $$entry: field 3 (Icon) should be either absolute path or icon name without extension if installed icons follow Icon Theme Specification"; \
			fi; \
		fi; \
		if [ -z "$$4" ]; then \
			${ECHO_MSG} "${PKGNAME}: Makefile error: in desktop entry $$entry: field 4 (Exec) is empty"; \
			exit 1; \
		fi; \
		if [ -n "$$5" ]; then \
			for c in `${ECHO_CMD} "$$5" | ${TR} ';' ' '`; do \
				if ! ${ECHO_CMD} ${VALID_DESKTOP_CATEGORIES} | ${GREP} -wq $$c; then \
					${ECHO_CMD} "${PKGNAME}: Makefile warning: in desktop entry $$entry: category $$c is not a valid desktop category"; \
				fi; \
			done; \
			if ! ${ECHO_CMD} "$$5" | ${GREP} -q "`${ECHO_CMD} ${DESKTOP_CATEGORIES_MAIN} | ${SED} -E 's,[[:blank:]]+,\\\|,g'`"; then \
				${ECHO_CMD} "${PKGNAME}: Makefile warning: in desktop entry $$entry: field 5 (Categories) must contain at least one main desktop category (make -VDESKTOP_CATEGORIES_MAIN)"; \
			fi; \
			if ! ${ECHO_CMD} "$$5" | ${GREP} -q ';$$'; then \
				${ECHO_MSG} "${PKGNAME}: Makefile error: in desktop entry $$entry: field 5 (Categories) does not end with a semicolon"; \
				exit 1; \
			fi; \
		else \
			if [ -z "`cd ${.CURDIR} && ${MAKE} desktop-categories`" ]; then \
				${ECHO_MSG} "${PKGNAME}: Makefile error: in desktop entry $$entry: field 5 (Categories) is empty and could not be deduced from the CATEGORIES variable"; \
				exit 1; \
			fi; \
		fi; \
		if [ "x$$6" != "xtrue" ] && [ "x$$6" != "xfalse" ] && [ "x$$6" != "x" ]; then \
			${ECHO_MSG} "${PKGNAME}: Makefile error: in desktop entry $$entry: field 6 (StartupNotify) is not \"true\", \"false\" or \"\"(empty)"; \
			exit 1; \
		fi; \
		shift 6; \
		num=`${EXPR} $$num + 1`; \
	done
.else
	@${DO_NADA}
.endif

.if !target(install-desktop-entries)
install-desktop-entries:
.if defined(DESKTOP_ENTRIES)
	@set -- ${DESKTOP_ENTRIES} XXX; \
	if [ -z "${_DESKTOPDIR_REL}" ]; then \
		${ECHO_CMD} "@cwd ${DESKTOPDIR}" >> ${TMPPLIST}; \
	fi; \
	while [ $$# -gt 6 ]; do \
		filename="`${ECHO_CMD} "$$4" | ${SED} -e 's,^/,,g;s,[/ ],_,g;s,[^_[:alnum:]],,g'`.desktop"; \
		pathname="${STAGEDIR}${DESKTOPDIR}/$$filename"; \
		categories="$$5"; \
		if [ -z "$$categories" ]; then \
			categories="`cd ${.CURDIR} && ${MAKE} desktop-categories`"; \
		fi; \
		${ECHO_CMD} "${_DESKTOPDIR_REL}$$filename" >> ${TMPPLIST}; \
		${ECHO_CMD} "[Desktop Entry]" > $$pathname; \
		${ECHO_CMD} "Type=Application" >> $$pathname; \
		${ECHO_CMD} "Version=1.0" >> $$pathname; \
		${ECHO_CMD} "Name=$$1" >> $$pathname; \
		comment="$$2"; \
		if [ -z "$$2" ]; then \
			comment="`cd ${.CURDIR} && ${MAKE} -VCOMMENT`"; \
		fi; \
		${ECHO_CMD} "GenericName=$$comment" >> $$pathname; \
		${ECHO_CMD} "Comment=$$comment" >> $$pathname; \
		if [ -n "$$3" ]; then \
			${ECHO_CMD} "Icon=$$3" >> $$pathname; \
		fi; \
		${ECHO_CMD} "Exec=$$4" >> $$pathname; \
		${ECHO_CMD} "Categories=$$categories" >> $$pathname; \
		if [ -n "$$6" ]; then \
			${ECHO_CMD} "StartupNotify=$$6" >> $$pathname; \
		fi; \
		shift 6; \
	done; \
	if [ -z "${_DESKTOPDIR_REL}" ]; then \
		${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}; \
	fi
.else
	@${DO_NADA}
.endif
.endif

.if !target(check-license)
check-license:
	@${DO_NADA}
.endif

.if !target(ask-license)
ask-license:
	@${DO_NADA}
.endif

.if !target(install-license)
install-license:
	@${DO_NADA}
.endif

.if defined(WARNING)
WARNING_WAIT?=	10
show-warnings:
	@${ECHO_MSG} "/!\\ WARNING /!\\"
.for m in ${WARNING}
	@${ECHO_MSG} "${m}"
.endfor
	@${ECHO_MSG}
	@sleep ${WARNING_WAIT}

check-makefile:: show-warnings
.endif

.if defined(DEVELOPER)
.if defined(DEV_WARNING)
DEV_WARNING_WAIT?=	10
show-dev-warnings:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile warnings, please consider fixing /!\\"
	@${ECHO_MSG}
.for m in ${DEV_WARNING}
	@${ECHO_MSG} "${m}"
.endfor
	@${ECHO_MSG}
	@sleep ${DEV_WARNING_WAIT}
check-makefile:: show-dev-warnings
.endif

.if defined(DEV_ERROR)
show-dev-errors:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile errors /!\\"
	@${ECHO_MSG}
.for m in ${DEV_ERROR}
	@${ECHO_MSG} "${m}"
.endfor
	@${ECHO_MSG}
	@${FALSE}
check-makefile:: show-dev-errors
.endif
.endif #DVELOPER
.endif
# End of post-makefile section.

.endif
# End of the DESTDIR if statement
