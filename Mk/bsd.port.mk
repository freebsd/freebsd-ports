#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#
#	bsd.port.mk - 940820 Jordan K. Hubbard.
#	This file is in the public domain.
#
# Please view me with 4 column tabs!

# There are two different types of "maintainers" in the whole ports
# framework concept.  The maintainer alias of the bsd.port.mk file is
# listed below in the FreeBSD_MAINTAINER entry.  You should consult
# them if you have any questions/suggestions regarding this file.
#
# DO NOT COMMIT CHANGES TO THIS FILE BY YOURSELF, EVEN IF DID NOT GET
# A RESPONSE FROM MAINTAINER(S) WITHIN A REASONABLE TIMEFRAME! ALL
# UNAUTHORISED CHANGES WILL BE UNCONDITIONALLY REVERTED!

FreeBSD_MAINTAINER=	portmgr@FreeBSD.org

# For each port, the MAINTAINER variable is what you should consult for
# contact information on the person(s) to contact if you have questions/
# suggestions about that specific port.  By default (if no MAINTAINER
# is listed), a port is maintained by the subscribers of the ports@FreeBSD.org
# mailing list, and any correspondece should be directed there.
#
# MAINTAINER	- The e-mail address of the contact person for this port
#				  (default: ports@FreeBSD.org).
#
# These are meta-variables that are automatically set to the system
# you are running on.
# 
# ARCH			- The architecture, as returned by "uname -m".
# OPSYS			- Portability clause.  This is the operating system the
#				  makefile is being used on.  Automatically set to
#				  "FreeBSD," "NetBSD," or "OpenBSD" as appropriate.
# OSREL			- The release version (numeric) of the operating system.
# OSVERSION		- The value of __FreeBSD_version.
# PORTOBJFORMAT	- The object format ("aout" or "elf").
#
# These variables are used to identify your port.
#
# PORTNAME		- Name of software.
# PORTVERSION	- Version of software.
# PKGNAMEPREFIX	- Prefix to specify that port is language-specific, etc.
# PKGNAMESUFFIX	- Suffix to specify compilation options.
# PKGNAME		- Always defined as
#				  ${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.
#				  Do not define this in your Makefile.
# DISTNAME		- Name of port or distribution used in generating
#				  WRKSRC and DISTFILES below (default:
#				  ${PORTNAME}-${PORTVERSION}).
# CATEGORIES	- A list of descriptive categories into which this port falls.
#
# These variable describe how to fetch files required for building the port.
#
# DISTFILES		- Name(s) of archive file(s) containing distribution
#				  (default: ${DISTNAME}${EXTRACT_SUFX}).  Set this to
#				  an empty string if the port doesn't require it.
# EXTRACT_SUFX	- Suffix for archive names (default: .tar.bz2 if USE_BZIP2
#				  is set, .zip if USE_ZIP is set, .tar.gz otherwise).  
#				  You never have to set both DISTFILES and EXTRACT_SUFX.
# MASTER_SITES	- Primary location(s) for distribution files if not found
#				  locally.
# PATCHFILES	- Name(s) of additional files that contain distribution
#				  patches (default: none).  make will look for them at
#				  PATCH_SITES (see below).  They will automatically be
#				  uncompressed before patching if the names end with
#				  ".gz", ".bz2" or ".Z".
# PATCH_SITES	- Primary location(s) for distribution patch files
#				  if not found locally.
# DIST_SUBDIR	- Suffix to ${DISTDIR}.  If set, all ${DISTFILES} 
#				  and ${PATCHFILES} will be put in this subdirectory of
#				  ${DISTDIR} (see below).  Also they will be fetched in
#				  this subdirectory from FreeBSD mirror sites.
# ALLFILES		- All of ${DISTFILES} and ${PATCHFILES}.
# IGNOREFILES	- If some of the ${ALLFILES} are not checksum-able, set
#				  this variable to their names.
# EXTRACT_ONLY	- If defined, a subset of ${DISTFILES} you want to
#			  	  actually extract.
#
# These variables are typically set in /etc/make.conf to indicate
# the user's preferred location to fetch files from.
#
# MASTER_SITE_BACKUP - Backup location(s) for distribution files and patch
#				  files if not found locally and ${MASTER_SITES}/${PATCH_SITES}
#				  (default:
#				  ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/${DIST_SUBDIR}/)
# MASTER_SITE_OVERRIDE - If set, override the MASTER_SITES setting with this
#				  value.
# MASTER_SITE_FREEBSD - If set, only use ${MASTER_SITE_BACKUP} for
#				  MASTER_SITES.
# CD_MOUNTPTS -			List of CDROM mountpoints to look for distfiles under.
#						This variable supercedes CD_MOUNTPT, which is
#						obsolete.
#
# Set these if your port should not be built under certain circumstances.
# These are string variables; you should set them to the reason why
# they are necessary.
#
# RESTRICTED	- Port is restricted (e.g., contains cryptography, etc.).
# NO_CDROM		- Port may not go on CDROM.
# NO_PACKAGE	- Port should not be packaged but distfiles can be put on
#				  ftp sites and CDROMs.
# BROKEN_ELF	- Port doesn't build on ELF machines.
# BROKEN		- Port is broken.
#
# In addition to RESTRICTED or NO_CDROM, if only a subset of distfiles
# or patchfiles have redistribution restrictions, set the following
# to the list of such files.
#
# RESTRICTED_FILES - List of files that cannot be redistributed
#				  (default: "${DISTFILES} ${PATCHFILES}" if RESTRICTED
#				  or NO_CDROM is set, empty otherwise).
#
# This variable is a boolean, so you don't need to set it to the reason.
#
# IS_INTERACTIVE - Set this if your port needs to interact with the user
#				  during any step in a package build.  User can then decide
#				  to skip this port by setting ${BATCH}, or compiling only
#				  the interactive ports by setting ${INTERACTIVE}.
#
# Set these if your port only makes sense to certain archetictures.
# They are lists containing names for them (e.g., "alpha i386").
#
# ONLY_FOR_ARCHS - Only build ports if ${ARCH} matches one of these.
# NOT_FOR_ARCHS  - Only build ports if ${ARCH} doesn't match one of these.
#
# Use these if your port uses some of the common software packages. By
# convention these should be set to 'yes', although they only need to be
# defined.
#
# USE_BZIP2		- Says that the port tarballs use bzip2, not gzip, for
#				  compression.
# USE_ZIP		- Says that the port distfile uses zip, not tar w/[bg]zip
#				  for compression.
# USE_GCC295	- Says that the port requires this version of gcc, either in
#				  the system or installed from a port.
# USE_GCC30		- Says that the port requires this version of gcc, either in
#				  the system or installed from a port.
# USE_GMAKE		- Says that the port uses gmake.
# GMAKE			- Set to path of GNU make if not in $PATH (default: gmake).
# USE_AUTOMAKE		- Says that the port uses automake.  Implies
#			USE_AUTOCONF and USE_AUTOMAKE_VER?=14.
# USE_AUTOMAKE_VER	- Says that the port uses automake. Possible
#				values: 14, 15;
#				each specify a version of automake to use
#				and appropriatly set both AUTOMAKE{,_DIR}
#				and ACLOCAL{,_DIR} variables.
#				Implies USE_AUTOMAKE.  If set with
#				unknown value, defaults to 14.
# AUTOMAKE		- Set to path of GNU automake if not in $PATH (default:
#				according to USE_AUTOMAKE_VER value)
# AUTOMAKE_ARGS	- Pass these args to ${AUTOMAKE} if ${USE_AUTOMAKE_VER} is set.
# AUTOMAKE_ENV	- Pass these env (shell-like) to ${AUTOMAKE} if
#				${USE_AUTOMAKE_VER} is set.
# ACLOCAL	- Set to path of GNU automake aclocal if not in $PATH (default:
#				according to USE_AUTOMAKE_VER value)
# ACLOCAL_DIR	- Set to path of GNU automake aclocal shared directory (default:
#				according to USE_AUTOMAKE_VER value)
# AUTOMAKE_DIR	- Set to path of GNU automake shared directory (default:
#				according to USE_AUTOMAKE_VER value)
# USE_AUTOCONF_VER	- Says that the port uses autoconf. Possible
#				values: 213;
#				each specify a version of autoconf to use
#				and appropriatly set both AUTOCONF{,_DIR}
#				and ACLOCAL{,_DIR} variables.
#				Implies USE_AUTOCONF.  If set with
#				unknown value, defaults to 213.
# USE_AUTOCONF	- Says that the port uses autoconf.  Implies
#				GNU_CONFIGURE and USE_AUTOCONF_VER?=213.
# AUTOCONF	- Set to path of GNU autoconf if not in $PATH (default:
#				according to USE_AUTOCONF_VER value)
# AUTOCONF_ARGS	- Pass these args to ${AUTOCONF} if ${USE_AUTOCONF} is set.
# AUTOCONF_ENV	- Pass these env (shell-like) to ${AUTOCONF} if
#				${USE_AUTOCONF} is set.
# AUTOHEADER	- Set to path of GNU autoconf autoheader
#				if not in $PATH (default: according
#				to USE_AUTOCONF_VER value)
# AUTORECONF	- Set to path of GNU autoconf autoreconf
#				if not in $PATH (default: according
#				to USE_AUTOCONF_VER value)
# AUTOSCAN	- Set to path of GNU autoconf autoscan
#				if not in $PATH (default: according
#				to USE_AUTOCONF_VER value)
# AUTOIFNAMES	- Set to path of GNU autoconf autoifnames
#				if not in $PATH (default: according
#				to USE_AUTOCONF_VER value)
# AUTOCONF_DIR	- Set to path of GNU autoconf shared directory (default:
#				according to USE_AUTOCONF_VER value)
# USE_LIBTOOL	- Says that the port uses Libtool.  Implies GNU_CONFIGURE.
# LIBTOOL		- Set to path of libtool (default: libtool).
# LIBTOOLFILES	- Files to patch for libtool (defaults: "aclocal.m4" if
#				  USE_AUTOCONF is set, "configure" otherwise).
# LIBTOOLFLAGS	- Additional flags to pass to ltconfig
#				  (default: --disable-ltlibs)
# USE_PERL5		- Says that the port uses perl5 for building and running.
# PERL5			- Set to full path of perl5, either in the system or
#				  installed from a port.
# PERL			- Set to full path of perl5, either in the system or
#				  installed from a port, but without the version number.
#				  Use this if you need to replace "#!" lines in scripts.
# PERL_VERSION	- Full version of perl5 (see below for current value).
# PERL_VER		- Short version of perl5 (see below for current value).
# PERL_ARCH		- Directory name of architecture dependent libraries
#				  (value: ${ARCH}-freebsd).
# USE_BISON		- Says that the port uses bison for building.
# USE_IMAKE		- Says that the port uses imake.  Implies USE_X_PREFIX.
# XMKMF			- Set to path of `xmkmf' if not in $PATH (default: xmkmf -a ).
# NO_INSTALL_MANPAGES - For imake ports that don't like the install.man
#						target.
# USE_X_PREFIX	- Says that the port installs in ${X11BASE}.  Implies USE_XLIB.
# USE_XLIB		- Says that the port uses X libraries.
# USE_MOTIF		- Says that the port uses the Motif toolkit.  Implies USE_XPM.
#
# Dependency checking.  Use these if your port requires another port
# not in the list above.
#
# FETCH_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
#				  package depends in the "fetch" stage.  "path" is the
#				  name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the
#				  existence (if it is a full pathname) or search for
#				  it in your $PATH (if it is an executable) and go
#				  into "dir" to do a "make all install" if it's not
#				  found.  If the third field ("target") exists, it will
#				  be used instead of ${DEPENDS_TARGET}.
# BUILD_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
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
#				  ${DEPENDS_TARGET}.
# LIB_DEPENDS	- A list of "lib:dir[:target]" tuples of other ports this
#				  package depends on.  "lib" is the name of a shared library.
#				  make will use "ldconfig -r" to search for the
#				  library.  Note that lib can not contain regular expressions.
# DEPENDS		- A list of "dir[:target]" tuples of other ports this
#				  package depends on being made first.  Use this only for
#				  things that don't fall into the above four categories.
#				  If the second field ("target") exists, it will be used
#				  instead of ${DEPENDS_TARGET}.
# DEPENDS_TARGET - The default target to execute when a port is calling a
#				  dependency (default: "install").
#
# Various directory definitions and variables to control them.
# You rarely need to redefine any of these except WRKSRC and NO_WRKSUBDIR.
#
# X11BASE		- Where X11 ports install things (default: /usr/X11R6).
# LOCALBASE		- Where non-X11 ports install things (default: /usr/local).
# LINUXBASE		- Where Linux ports install things (default: /compat/linux).
# PREFIX		- Where *this* port installs its files (default: ${X11BASE}
#				  if USE_X_PREFIX is set, ${LINUXBASE} if USE_LINUX_PREFIX
#				  is set, otherwise ${LOCALBASE}).
# MASTERDIR		- Where the port finds patches, package files, etc.  Define
#				  this is you have two or more ports that share most of the
#				  files (default: ${.CURDIR}).
# PORTSDIR		- The root of the ports tree.  Defaults:
#					FreeBSD/OpenBSD: /usr/ports
#					NetBSD:          /usr/opt
# DISTDIR 		- Where to get gzip'd, tarballed copies of original sources
#				  (default: ${PORTSDIR}/distfiles).
# PACKAGES		- A top level directory where all packages go (rather than
#				  going locally to each port). (default: ${PORTSDIR}/packages).
# WRKDIRPREFIX	- The place to root the temporary working directory
#				  hierarchy (default: none).
# WRKDIR 		- A temporary working directory that gets *clobbered* on clean
#				  (default: ${WRKDIRPREFIX}${.CURDIR}/work).
# WRKSRC		- A subdirectory of ${WRKDIR} where the distribution actually
#				  unpacks to.  (Default: ${WRKDIR}/${DISTNAME} unless
#				  NO_WRKSUBDIR is set, in which case simply ${WRKDIR}).
# NO_WRKSUBDIR	- Assume port unpacks directly into ${WRKDIR}.
# PATCHDIR 		- A directory containing any additional patches you made
#				  to port this software to FreeBSD (default:
#				  ${MASTERDIR}/files)
# SCRIPTDIR 	- A directory containing any auxiliary scripts
#				  (default: ${MASTERDIR}/scripts)
# FILESDIR 		- A directory containing any miscellaneous additional files.
#				  (default: ${MASTERDIR}/files)
# PKGDIR 		- A direction containing any package creation files.
#				  (default: ${MASTERDIR})
#
# Variables that serve as convenient "aliases" for your *-install targets.
# Use these like: "${INSTALL_PROGRAM} ${WRKSRC}/prog ${PREFIX}/bin".
#
# INSTALL_PROGRAM - A command to install binary executables.
# INSTALL_SCRIPT - A command to install executable scripts.
# INSTALL_DATA	- A command to install sharable data.
# INSTALL_MAN	- A command to install manpages (doesn't compress).
#
# Set the following to specify all manpages that your port installs.
# These manpages will be automatically listed in ${PLIST}.  Depending
# on the setting of NOMANCOMPRESS, the make rules will compress the
# manpages for you.
#
# MAN<sect>		- A list of manpages, categorized by section.  For
#				  example, if your port has "man/man1/foo.1" and
#				  "man/mann/bar.n", set "MAN1=foo.1" and "MANN=bar.n".
#				  The available sections chars are "123456789LN".
# MLINKS		- A list of <source, target> tuples for creating links
#				  for manpages.  For example, "MLINKS= a.1 b.1 c.3 d.3"
#				  will do an "ln -sf a.1 b.1" and "ln -sf c.3 and d.3" in
#				  appropriate directories.  (Use this even if the port
#				  installs its own manpage links so they will show up
#				  correctly in ${PLIST}.)
# MANPREFIX		- The directory prefix for ${MAN<sect>} and ${MLINKS}
#				  (default: ${PREFIX}).
# MAN<sect>PREFIX - If manual pages of some sections install in different
#				  locations than others, use these (default: ${MANPREFIX}).
# MANCOMPRESSED - This variable can take values "yes", "no" or
#				  "maybe".  "yes" means manpages are installed
#				  compressed; "no" means they are not; "maybe" means
#				  it changes depending on the value of
#				  NOMANCOMPRESS.  The default is "yes" if USE_IMAKE
#				  is set and NO_INSTALL_MANPAGES is not set, and
#				  "no" otherwise.
#
# Default targets and their behaviors:
#
# fetch			- Retrieves ${DISTFILES} (and ${PATCHFILES} if defined)
#				  into ${DISTDIR} as necessary.
# fetch-list	- Show list of files that would be retrieved by fetch.
# fetch-recursive - Retrieves ${DISTFILES} (and ${PATCHFILES} if defined),
#				  for port and dependencies into ${DISTDIR} as necessary.
# fetch-recursive-list  - Show list of files that would be retrieved by
#				  fetch-recursive.
# extract		- Unpacks ${DISTFILES} into ${WRKDIR}.
# patch			- Apply any provided patches to the source.
# configure		- Runs either GNU configure, one or more local configure
#				  scripts or nothing, depending on what's available.
# build			- Actually compile the sources.
# install		- Install the results of a build.
# reinstall		- Install the results of a build, ignoring "already installed"
#				  flag.
# deinstall		- Remove the installation.
# package		- Create a package from an _installed_ port.
# describe		- Try to generate a one-line description for each port for
#				  use in INDEX files and the like.
# checkpatch	- Do a "patch -C" instead of a "patch".  Note that it may
#				  give incorrect results if multiple patches deal with
#				  the same file.
# checksum		- Use distinfo to ensure that your distfiles are valid.
# checksum-recursive - Run checksum in this port and all dependencies.
# makesum		- Generate distinfo (only do this for your own ports!).
# clean		    - Remove ${WRKDIR} and other temporary files used for building.
# clean-depends	- Do a "make clean" for all dependencies.
#
# Default sequence for "all" is:  fetch checksum extract patch configure build
#
# Please read the comments in the targets section below, you
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
# For fetch:
#
# FETCH_CMD		- Full path to ftp/http fetch command if not in $PATH
#				  (default: "/usr/bin/fetch -A").
# FETCH_BEFORE_ARGS -
#				  Arguments to ${FETCH_CMD} before filename (default: none).
# FETCH_AFTER_ARGS -
#				  Arguments to ${FETCH_CMD} following filename (default: none).
# FETCH_ENV		- Environment to pass to ${FETCH_CMD} (default: none).
#
# For extract:
#
# EXTRACT_CMD	- Command for extracting archive (default: "bzip2" if
#				  USE_BZIP2 is set, "unzip" if USE_ZIP is set, "gzip" 
#				  otherwise).
# EXTRACT_BEFORE_ARGS -
#				  Arguments to ${EXTRACT_CMD} before filename
#				  (default: "-dc").
# EXTRACT_AFTER_ARGS -
#				  Arguments to ${EXTRACT_CMD} following filename
#				  (default: "| tar -xf -").
# EXTRACT_PRESERVE_OWNERSHIP -
#				  Normally, when run as "root", the extract stage will
#				  change the owner and group of all files under ${WRKDIR}
#				  to 0:0.  Set this variable if you want to turn off this
#				  feature.
#
# For patch:
#
# EXTRA_PATCHES - Define this variable if you have patches not in
#				  ${PATCHDIR}.  This usually happens when you need to
#				  do some pre-processing before some distribution
#				  patches can be applied.  In that case, fetch them as
#				  extra distfiles, put the processed results in
#				  ${WRKDIR}, then point EXTRA_PATCHES to them.
#
#				  The patches specified by this variable will be
#				  applied after the normal distribution patches but
#				  before those in ${PATCHDIR}.
# PATCH_WRKSRC  - Directory to apply patches in (default: ${WRKSRC}).
#
# For configure:
#
# HAS_CONFIGURE	- Says that the port has its own configure script.  The
#				  configure stage will not do anything if this is not set.
# GNU_CONFIGURE	- Set if you are using GNU configure (optional).  Implies
#				  HAS_CONFIGURE.
# PERL_CONFIGURE - Configure using Perl's MakeMaker.  Implies USE_PERL5.
# CONFIGURE_WRKSRC - Directory to run configure in (default: ${WRKSRC}).
# CONFIGURE_SCRIPT - Name of configure script, relative to ${CONFIGURE_WRKSRC}
#				  (default: "Makefile.PL" if PERL_CONFIGURE is set,
#				  "configure" otherwise).
# CONFIGURE_TARGET - The name of target to call when GNU_CONFIGURE is
#				  defined (default: ${MACHINE_ARCH}--freebsd${OSREL}).
# CONFIGURE_ARGS - Pass these args to configure if ${HAS_CONFIGURE} is set
#				  (default: "--prefix=${PREFIX} ${CONFIGURE_TARGET}" if
#				  GNU_CONFIGURE is set, "CC=${CC} CCFLAGS=${CFLAGS}
#				  PREFIX=${PREFIX}" if PERL_CONFIGURE is set, empty otherwise).
# CONFIGURE_ENV - Pass these env (shell-like) to configure if
#				  ${HAS_CONFIGURE} is set.
# CONFIGURE_LOG - The name of configure log file (default: config.log).
#				  It will be printed to the screen if configure fails.
#
# For build and install:
#
# ALL_TARGET	- Default target for sub-make in build stage (default: all).
# BUILD_WRKSRC  - Directory to do build in (default: ${WRKSRC}).
# MAKE_ENV		- Additional environment vars passed to sub-make in build
#				  and install stages (default: see below).
# MAKE_ARGS		- Any extra arguments to sub-make in build and install
#				  stages (default: none).
#
# For install:
#
# INSTALL_TARGET - Default target for sub-make in install stage 
# 				  (default: install).
# INSTALL_WRKSRC - Directory to install from (default: ${WRKSRC}).
# NO_MTREE		- If set, will not invoke mtree from bsd.port.mk from
#				  the "install" target.
# MTREE_FILE	- The name of the mtree file (default: /etc/mtree/BSD.x11.dist
#				  if USE_X_PREFIX is set, /etc/mtree/BSD.local.dist
#				  otherwise.)
# PLIST			- Name of the `packing list' file (default: ${PKGDIR}/pkg-plist).
#				  Change this to ${WRKDIR}/PLIST or something if you
#				  need to write to it.  (It is not a good idea for a port
#				  to write to any file outside ${WRKDIR} during a normal
#				  build.)
# TMPPLIST		- Name of the `packing list' file after processing
#				  (default: ${WRKDIR}/.PLIST.mktmp).
# PLIST_SUB		- List of "variable=value" pair for substitution in ${PLIST}
# 				  (default: see below).
# INSTALLS_SHLIB - If set, bsd.port.mk will automatically run ldconfig commands
#				  from post-install and also add appropriate @exec/@unexec
#				  directives to directories listed in LDCONFIG_DIRS.
# LDCONFIG_DIRS - List of directories to run ldconfig if
#				  INSTALLS_SHLIB is set (default: %%PREFIX%%/lib).
#				  Note that this is passed through sed just like the
#				  rest of PLIST, so ${PLIST_SUB} substitutions also
#				  apply here.  It is recommended that you use
#				  %%PREFIX%% for ${PREFIX}, %%LOCALBASE%% for
#				  ${LOCALBASE} and %%X11BASE%% for ${X11BASE}.
# DOCSDIR		- Name of the directory to install the packages docs in
#				  (default: ${PREFIX}/share/doc/${PORTNAME}).
# EXAMPLESDIR		- Name of the directory to install the packages examples in
#				  (default: ${PREFIX}/share/examples/${PORTNAME}).
# DATADIR		- Name of the directory to install the packages shared data
#				  in (default: ${PREFIX}/share/${PORTNAME}).
# 
# Note that the install target will automatically add manpages (see
# above) and also substitute special sequences of characters (delimited
# by "%%") as defined in PLIST_SUB to generate ${TMPPLIST}.  For
# instance, "OSREL=${OSREL}" in PLIST_SUB causes all occurrences of
# "%%OSREL%%" in ${PLIST} to be substituted by the value of OSREL.
# ${TMPPLIST} is generated between the do-install and post-install
# stages.  If you are generating the packing list on-the-fly, make
# sure it's generated by the end of do-install!
#
# For package:
#
# NO_LATEST_LINK - Do not install the "Latest" link for package.  Define this
#				  if this port is a beta version of another stable port
#				  which is also in the tree.
# LATEST_LINK    - Install the "Latest" link for the package as ___.  Define
#                 this if the "Latest" link name will be incorrectly determined.
#
# This is used in all stages:
#
# SCRIPTS_ENV	- Additional environment vars passed to scripts in
#                 ${SCRIPTDIR} executed by bsd.port.mk (default: see below).
#
# Finally, variables to change if you want a special behavior.  These
# are for debugging purposes.  Don't set them in your Makefile.
#
# ECHO_MSG		- Used to print all the '===>' style prompts - override this
#				  to turn them off (default: ${ECHO}).
# PATCH_DEBUG	- If set, print out more information about the patches as
#				  it attempts to apply them.
# PKG_DBDIR		- Where package installation is recorded (default: /var/db/pkg)
# NO_PKG_REGISTER - Don't register a port installation as a package.
# FORCE_PKG_REGISTER - If set, it will overwrite any existing package
#				  registration information in ${PKG_DBDIR}/${PKGNAME}.
# NO_DEPENDS	- Don't verify build of dependencies.
# NO_CHECKSUM	- Don't verify the checksum.  Typically used when
#				  when you noticed the distfile you just fetched has
#				  a different checksum and you intend to verify if
#				  the port still works with it.

# Start of pre-makefile section.
.if !defined(AFTERPORTMK)

.if defined(_PREMKINCLUDED)
.BEGIN:
	@${ECHO} "${PKGNAME}: You cannot include bsd.port[.pre].mk twice"
	@${FALSE}
.endif

_PREMKINCLUDED=	yes

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
.if exists(/usr/bin/bzip2)
BZCAT?=		/usr/bin/bzcat
BZIP2_CMD?=	/usr/bin/bzip2
.else
BZCAT?=		${LOCALBASE}/bin/bzcat
BZIP2_CMD?=	${LOCALBASE}/bin/bzip2
.endif
CAT?=		/bin/cat
CHGRP?=		/usr/bin/chgrp
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CP?=		/bin/cp
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FILE?=		/usr/bin/file
FIND?=		/usr/bin/find
GREP?=		/usr/bin/grep
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
ID?=		/usr/bin/id
IDENT?=		/usr/bin/ident
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
MKDIR?=		/bin/mkdir -p
MV?=		/bin/mv
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
STRIP_CMD?=	/usr/bin/strip
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
TEST?=		test				# Shell builtin
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
UNAME?=		/usr/bin/uname
WHICH?=		/usr/bin/which
XARGS?=		/usr/bin/xargs

# ECHO is defined in /usr/share/mk/sys.mk, which can either be "echo",
# or "true" if the make flag -s is given.  Use ECHO_CMD where you mean
# the echo command.
ECHO_CMD?=	echo				# Shell builtin

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO}

# Get the architecture
.if !defined(ARCH)
ARCH!=	${UNAME} -m
.endif

# Kludge for pre-3.0 systems
MACHINE_ARCH?=	i386

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
.if exists(/sbin/sysctl)
OSVERSION!=	/sbin/sysctl -n kern.osreldate
.else
OSVERSION!=	/usr/sbin/sysctl -n kern.osreldate
.endif
.endif

# Get the object format.
.if !defined(PORTOBJFORMAT)
PORTOBJFORMAT!=	test -x /usr/bin/objformat && /usr/bin/objformat || echo aout
.endif

MASTERDIR?=	${.CURDIR}

# If they exist, include Makefile.inc, then architecture/operating
# system specific Makefiles, then local Makefile.local.

.if ${MASTERDIR} != ${.CURDIR} && exists(${.CURDIR}/../Makefile.inc)
.include "${.CURDIR}/../Makefile.inc"
.endif

.if exists(${MASTERDIR}/../Makefile.inc)
.include "${MASTERDIR}/../Makefile.inc"
.endif

.if exists(${MASTERDIR}/Makefile.${ARCH}-${OPSYS})
.include "${MASTERDIR}/Makefile.${ARCH}-${OPSYS}"
.elif exists(${MASTERDIR}/Makefile.${OPSYS})
.include "${MASTERDIR}/Makefile.${OPSYS}"
.elif exists(${MASTERDIR}/Makefile.${ARCH})
.include "${MASTERDIR}/Makefile.${ARCH}"
.endif

.if exists(${MASTERDIR}/Makefile.local)
.include "${MASTERDIR}/Makefile.local"
.endif

.if !defined(PORTNAME) || !defined(PORTVERSION) || defined(PKGNAME)
.BEGIN:
	@${ECHO} "${PKGNAME}: You need to define PORTNAME and PORTVERSION instead of PKGNAME."
	@${ECHO} "(This port is too old for your bsd.port.mk, please update it to match"
	@${ECHO} " your bsd.port.mk.)"
	@${FALSE}
.endif

PORTREVISION?=	0
.if ${PORTREVISION} != 0
_SUF1=	_${PORTREVISION}
.endif

PORTEPOCH?=		0
.if ${PORTEPOCH} != 0
_SUF2=	,${PORTEPOCH}
.endif

PKGNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}${_SUF1}${_SUF2}
DISTNAME?=	${PORTNAME}-${PORTVERSION}

# These need to be absolute since we don't know how deep in the ports
# tree we are and thus can't go relative.  They can, of course, be overridden
# by individual Makefiles or local system make configuration.
.if (${OPSYS} == "NetBSD")
PORTSDIR?=		/usr/opt
.else
PORTSDIR?=		/usr/ports
.endif
LOCALBASE?=		${DESTDIR}/usr/local
X11BASE?=		${DESTDIR}/usr/X11R6
LINUXBASE?=		${DESTDIR}/compat/linux
DISTDIR?=		${PORTSDIR}/distfiles
_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
.if defined(USE_BZIP2)
EXTRACT_SUFX?=			.tar.bz2
.elif defined(USE_ZIP)
EXTRACT_SUFX?=			.zip
.else
EXTRACT_SUFX?=			.tar.gz
.endif
PACKAGES?=		${PORTSDIR}/packages
TEMPLATES?=		${PORTSDIR}/Templates

.if (!defined(PATCHDIR) && exists(${MASTERDIR}/patches)) || \
	(!defined(PKGDIR) && exists(${MASTERDIR}/pkg)) || \
	(!defined(MD5_FILE) && exists(${MASTERDIR}/files/md5))
pre-everything::
	@${ECHO} "Error: your port uses an old layout.  Please update it to match this bsd.port.mk.  If you have updated your ports collection via cvsup and are still getting this error, see Q12 and Q13 in the cvsup FAQ on http://www.polstra.com for further information."
	@${FALSE}
.endif
PATCHDIR?=		${MASTERDIR}/files
FILESDIR?=		${MASTERDIR}/files
SCRIPTDIR?=		${MASTERDIR}/scripts
PKGDIR?=		${MASTERDIR}

.if defined(USE_IMAKE) && !defined(USE_X_PREFIX)
USE_X_PREFIX=	yes
.endif
.if defined(USE_X_PREFIX) && ${USE_X_PREFIX} == "no"
.undef USE_X_PREFIX
.endif
.if defined(USE_X_PREFIX)
USE_XLIB=		yes
.endif
.if defined(USE_LINUX_PREFIX)
USE_LINUX=		yes
.endif
.if defined(USE_X_PREFIX)
PREFIX?=		${X11BASE}
.elif defined(USE_LINUX_PREFIX)
PREFIX?=		${LINUXBASE}
NO_MTREE=		yes
.else
PREFIX?=		${LOCALBASE}
.endif

.if defined(USE_OPENSSL)
.if ${OSVERSION} >= 400014
.if !exists(/usr/lib/libcrypto.so)
.BEGIN:
	@${ECHO} "This port requires the OpenSSL library, which is part of"
	@${ECHO} "the FreeBSD crypto distribution but not installed on your"
	@${ECHO} "machine. Please see the \"OpenSSL\" section in the handbook"
	@${ECHO} "(at \"http://www.FreeBSD.org/handbook/openssl.html\", for instance)"
	@${ECHO} "for instructions on how to obtain and install the FreeBSD"
	@${ECHO} "OpenSSL distribution."
	@${FALSE}
.else
OPENSSLBASE=	/usr
OPENSSLDIR=		/etc/ssl
# OpenSSL in the base system may not include IDEA for patent licensing reasons.
.if defined(MAKE_IDEA) && !defined(OPENSSL_IDEA)
OPENSSL_IDEA=	${MAKE_IDEA}
.else
OPENSSL_IDEA?=	NO
.endif
.if ${OPENSSL_IDEA} == "NO"
# XXX This is a hack to work around the fact that /etc/make.conf clobbers
#     our CFLAGS. It might not be enough for all future ports.
.if defined(HAS_CONFIGURE)
CFLAGS+=		-DNO_IDEA
.else
OPENSSL_CFLAGS+=-DNO_IDEA
.endif
MAKE_ARGS+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}"
.endif
.endif
.else
LIB_DEPENDS+=	crypto.2:${PORTSDIR}/security/openssl
OPENSSLBASE?=	${LOCALBASE}
OPENSSLDIR?=	${OPENSSLBASE}/openssl
.endif
OPENSSLLIB=		${OPENSSLBASE}/lib
OPENSSLINC=		${OPENSSLBASE}/include
MAKE_ENV+=		OPENSSLLIB=${OPENSSLLIB} OPENSSLINC=${OPENSSLINC} \
				OPENSSLBASE=${OPENSSLBASE} OPENSSLDIR=${OPENSSLDIR}
### crypto
#RESTRICTED=		"Contains cryptography."
.endif

.if defined(EMACS_PORT_NAME)
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
.endif

.if defined(USE_PYTHON) || defined(PYTHON_VERSION)
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(USE_RUBY) || defined(USE_LIBRUBY)
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.endif

.if defined(USE_QT) || defined(USE_QT2) || defined(USE_QT_VER) || defined(USE_KDELIBS_VER) || defined(USE_KDEBASE_VER)
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.endif

.include "${PORTSDIR}/Mk/bsd.gnome.mk"

# defaults to 4.x for -CURRENT; and 3.3.6 for all other branches
.if ${OSVERSION} > 500025
XFREE86_VERSION?=	4
.else
XFREE86_VERSION?=	3
.endif

.endif
# End of pre-makefile section.

# Start of post-makefile section.
.if !defined(BEFOREPORTMK)

.if defined(_POSTMKINCLUDED)
.BEGIN:
	@${ECHO} "${PKGNAME}: You cannot include bsd.port[.post].mk twice"
	@${FALSE}
.endif

_POSTMKINCLUDED=	yes

WRKDIR?=		${WRKDIRPREFIX}${.CURDIR}/work
.if defined(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}
.else
WRKSRC?=		${WRKDIR}/${DISTNAME}
.endif

PATCH_WRKSRC?=	${WRKSRC}
CONFIGURE_WRKSRC?=	${WRKSRC}
BUILD_WRKSRC?=	${WRKSRC}
INSTALL_WRKSRC?=${WRKSRC}

PLIST_SUB+=	OSREL=${OSREL} PREFIX=%D LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.if defined(NOPORTDOCS)
PLIST_SUB+=	        PORTDOCS="@comment "
.else
PLIST_SUB+=	        PORTDOCS=""
.endif

CONFIGURE_ENV+=	PORTOBJFORMAT=${PORTOBJFORMAT}
SCRIPTS_ENV+=	PORTOBJFORMAT=${PORTOBJFORMAT}
MAKE_ENV+=		PORTOBJFORMAT=${PORTOBJFORMAT}
PLIST_SUB+=		PORTOBJFORMAT=${PORTOBJFORMAT}

.if defined(MANCOMPRESSED)
.if ${MANCOMPRESSED} != yes && ${MANCOMPRESSED} != no && \
	${MANCOMPRESSED} != maybe
.BEGIN:
	@${ECHO} "${PKGNAME}: Value of MANCOMPRESSED (is \"${MANCOMPRESSED}\") can only be \"yes\", \"no\" or \"maybe\"".
	@${FALSE}
.endif
.endif

.if defined(USE_IMAKE) && ${OPSYS} != OpenBSD && !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED?=	yes
.else
MANCOMPRESSED?=	no
.endif

.if defined(PATCHFILES)
.if ${PATCHFILES:M*.bz2}x != x
HAVE_BZIP2_PATCHES=	yes
.endif
.endif

.if (defined(USE_BZIP2) || defined(HAVE_BZIP2_PATCHES)) && !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=		bzip2:${PORTSDIR}/archivers/bzip2
.endif
.if defined(USE_ZIP)
BUILD_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
.endif
.if defined(USE_GMAKE)
BUILD_DEPENDS+=		gmake:${PORTSDIR}/devel/gmake
CONFIGURE_ENV+=	MAKE=${GMAKE}
.endif
.if defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)
USE_AUTOMAKE?=	yes
USE_AUTOMAKE_VER?=	14

USE_AUTOCONF=	yes
.endif
.if defined(USE_AUTOMAKE_VER)
.if ${USE_AUTOMAKE_VER} == 15
BUILD_DEPENDS+=		automake:${PORTSDIR}/devel/automake

ACLOCAL?=		aclocal
AUTOMAKE?=		automake
ACLOCAL_DIR?=		${LOCALBASE}/share/aclocal
AUTOMAKE_DIR?=		${LOCALBASE}/share/automake
.else
BUILD_DEPENDS+=		automake14:${PORTSDIR}/devel/automake14

AUTOMAKE_ARGS+=		-i
USE_AUTOCONF_VER?=	213
.endif
.endif
.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
USE_AUTOCONF?=	yes
USE_AUTOCONF_VER?=	213

GNU_CONFIGURE=	yes
.endif
.if defined(USE_AUTOCONF_VER)
BUILD_DEPENDS+=		autoconf213:${PORTSDIR}/devel/autoconf213
.endif
.if defined(USE_LIBTOOL)
GNU_CONFIGURE=	yes
BUILD_DEPENDS+=		libtool:${PORTSDIR}/devel/libtool
.if defined(USE_AUTOCONF)
LIBTOOLFILES?=		aclocal.m4
.else
LIBTOOLFILES?=		configure
.endif
LIBTOOLFLAGS?=		--disable-ltlibs
.endif
.if defined(USE_GCC295) && ${OSVERSION} < 400012
CC=				gcc295
CXX=			g++295
BUILD_DEPENDS+=	gcc295:${PORTSDIR}/lang/gcc295
MAKE_ENV+=		CC=${CC} CXX=${CXX}
.endif
.if defined(USE_GCC30) && ${OSVERSION} < 500999
CC=				gcc30
CXX=			g++30
BUILD_DEPENDS+=	gcc30:${PORTSDIR}/lang/gcc30
MAKE_ENV+=		CC=${CC} CXX=${CXX}
.endif

.if defined(USE_LINUX)
RUN_DEPENDS+=	${LINUXBASE}/etc/redhat-release:${PORTSDIR}/emulators/linux_base
.endif

.if defined(USE_MOTIF)
USE_XPM=			yes
.if !defined(NO_OPENMOTIF)
LIB_DEPENDS+=		Xm.2:${PORTSDIR}/x11-toolkits/open-motif
.endif
.endif

.if defined(USE_FREETYPE)
LIB_DEPENDS+=			ttf.4:${PORTSDIR}/print/freetype
.endif

.if ${XFREE86_VERSION} == 3
.if defined(USE_IMAKE)
BUILD_DEPENDS+=			imake:${PORTSDIR}/devel/imake
.endif
.if defined(USE_XPM)
LIB_DEPENDS+=			Xpm.4:${PORTSDIR}/graphics/xpm
.endif
.if defined(USE_DGS)
LIB_DEPENDS+=			dps.0:${PORTSDIR}/x11/dgs
.endif
.if defined(USE_MESA)
LIB_DEPENDS+=			GL.14:${PORTSDIR}/graphics/Mesa3
.endif
XAWVER=					6
PKG_IGNORE_DEPENDS?=	'^XFree86-3\.'
.else
.if defined(USE_IMAKE)
BUILD_DEPENDS+=			imake:${PORTSDIR}/devel/imake-4
.endif
.if defined(USE_XPM) || defined(USE_DGS)
USE_XLIB=				yes
.endif
.if defined(USE_MESA)
LIB_DEPENDS+=			glut.3:${PORTSDIR}/graphics/Mesa3
.endif
XAWVER=					7
PKG_IGNORE_DEPENDS?=	'this_port_does_not_exist'
.endif
PLIST_SUB+=				XAWVER=${XAWVER}

.if defined(USE_BISON)
.if ${OSVERSION} >= 400014
BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison
.endif
.endif

.if ${OSVERSION} >= 500007
PERL_VERSION?=	5.6.0
PERL_VER?=		5.6.0
PERL_ARCH?=		mach
.else
.if ${OSVERSION} >= 300000
PERL_VERSION?=	5.00503
.else
PERL_VERSION?=	5.00502
.endif
PERL_VER?=		5.005
PERL_ARCH?=		${ARCH}-freebsd
.endif
PLIST_SUB+=		PERL_VERSION=${PERL_VERSION} \
				PERL_VER=${PERL_VER} \
				PERL_ARCH=${PERL_ARCH}

.if exists(/usr/bin/perl5) && ${OSVERSION} >= 300000
# 3.0-current after perl5 import
.if !exists(/usr/bin/perl${PERL_VERSION}) && defined(USE_PERL5)
pre-everything::
	@${ECHO} "Error: you don't have the right version of perl in /usr/bin."
	@${FALSE}
.endif
PERL5=			/usr/bin/perl${PERL_VERSION}
PERL=			/usr/bin/perl
.else
PERL5=			${LOCALBASE}/bin/perl${PERL_VERSION}
PERL=			${LOCALBASE}/bin/perl
.if defined(USE_PERL5)
BUILD_DEPENDS+=	perl${PERL_VERSION}:${PORTSDIR}/lang/perl5
RUN_DEPENDS+=	perl${PERL_VERSION}:${PORTSDIR}/lang/perl5
.endif
.endif

.if defined(USE_XLIB)
.if ${XFREE86_VERSION} == 3
# Don't try to build XFree86-3 even if ALWAYS_BUILD_DEPENDS is defined --
# it's just too big....
.if !defined(ALWAYS_BUILD_DEPENDS)
LIB_DEPENDS+=	X11.6:${PORTSDIR}/x11/XFree86
.endif
.else
LIB_DEPENDS+=	X11.6:${PORTSDIR}/x11/XFree86-4-libraries
.endif
.endif

.include "${PORTSDIR}/Mk/bsd.gnome.mk"

.if exists(${PORTSDIR}/../Makefile.inc)
.include "${PORTSDIR}/../Makefile.inc"
.endif

# Don't change these!!!  These names are built into the _TARGET_USE macro,
# there is no way to refer to them cleanly from within the macro AFAIK.
EXTRACT_COOKIE?=	${WRKDIR}/.extract_done.${PKGNAME}
CONFIGURE_COOKIE?=	${WRKDIR}/.configure_done.${PKGNAME}
INSTALL_COOKIE?=	${WRKDIR}/.install_done.${PKGNAME}
BUILD_COOKIE?=		${WRKDIR}/.build_done.${PKGNAME}
PATCH_COOKIE?=		${WRKDIR}/.patch_done.${PKGNAME}
PACKAGE_COOKIE?=	${WRKDIR}/.package_done.${PKGNAME}

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

# Use this as the first operand to always build dependency.
NONEXISTENT?=	/nonexistent

# Miscellaneous overridable commands:
GMAKE?=			gmake
ACLOCAL?=		aclocal14
AUTOMAKE?=		automake14
ACLOCAL_DIR?=		${LOCALBASE}/share/automake14/aclocal
AUTOMAKE_DIR?=		${LOCALBASE}/share/automake14/automake
AUTOCONF?=		autoconf213
AUTOHEADER?=		autoheader213
AUTORECONF?=		autoreconf213
AUTOSCAN?=		autoscan213
AUTOUPDATE?=		autoupdate213
AUTOIFNAMES?=		ifnames213
AUTOCONF_DIR?=		${LOCALBASE}/share/autoconf213/autoconf
LIBTOOL?=		libtool
XMKMF?=			xmkmf -a
.if exists(/sbin/md5)
MD5?=			/sbin/md5
.elif exists(/bin/md5)
MD5?=			/bin/md5
.elif exists(/usr/bin/md5)
MD5?=			/usr/bin/md5
.else
MD5?=			md5
.endif
MD5_FILE?=		${MASTERDIR}/distinfo

MAKE_FLAGS?=	-f
MAKEFILE?=		Makefile
MAKE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} MOTIFLIB="${MOTIFLIB}" LIBDIR="${LIBDIR}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

.if ${OSVERSION} < 500016
PTHREAD_CFLAGS=	-D_THREAD_SAFE
PTHREAD_LIBS=		"-pthread"
.else
PTHREAD_CFLAGS=	""
PTHREAD_LIBS=		"-lc_r"
.endif

.if exists(/usr/bin/fetch)
# avoid -A for 2.2 -- it's not ported to that branch
.if ${OSVERSION} < 300000
FETCH_CMD?=		/usr/bin/fetch
.else
FETCH_CMD?=		/usr/bin/fetch -A
.endif
#FETCH_BEFORE_ARGS+=	$${CKSIZE:+-S $$CKSIZE}
.else
FETCH_CMD?=		/usr/bin/ftp
.endif

TOUCH?=			/usr/bin/touch
TOUCH_FLAGS?=	-f

PATCH?=			/usr/bin/patch
PATCH_STRIP?=	-p0
PATCH_DIST_STRIP?=	-p0
.if defined(PATCH_DEBUG)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS?=	-d ${PATCH_WRKSRC} -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${PATCH_WRKSRC} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS?=	-d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
PATCH_DIST_ARGS+=	--batch
.endif

.if defined(PATCH_CHECK_ONLY)
PATCH_ARGS+=	-C
PATCH_DIST_ARGS+=	-C
.endif

.if exists(/bin/tar)
TAR?=	/bin/tar
.else
TAR?=	/usr/bin/tar
.endif

# EXTRACT_SUFX is defined in .pre.mk section
.if defined(USE_ZIP)
EXTRACT_CMD?=			unzip
EXTRACT_BEFORE_ARGS?=	-q
EXTRACT_AFTER_ARGS?=	-d ${WRKDIR}
.else
EXTRACT_BEFORE_ARGS?=	-dc
EXTRACT_AFTER_ARGS?=	| ${TAR} -xf -
.if defined(USE_BZIP2)
EXTRACT_CMD?=			${BZIP2_CMD}
.else
EXTRACT_CMD?=			${GZIP_CMD}
.endif
.endif

# Figure out where the local mtree file is
.if !defined(MTREE_FILE) && !defined(NO_MTREE)
.if defined(USE_X_PREFIX)
.if ${XFREE86_VERSION} == 3
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.endif
.else
MTREE_FILE=	/etc/mtree/BSD.local.dist
.endif
.endif
MTREE_CMD?=	/usr/sbin/mtree
MTREE_ARGS?=	-U ${MTREE_FOLLOWS_SYMLINKS} -f ${MTREE_FILE} -d -e -p

# Determine whether or not we can use rootly owner/group functions.
UID!=	id -u
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
INSTALL_SCRIPT= \
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_DATA= \
	${INSTALL} ${COPY} ${_SHROWNGRP} -m ${SHAREMODE}
INSTALL_MAN= \
	${INSTALL} ${COPY} ${_MANOWNGRP} -m ${MANMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			BSD_INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			BSD_INSTALL_DATA="${INSTALL_DATA}" \
			BSD_INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=	${INSTALL_MACROS}
SCRIPTS_ENV+=	${INSTALL_MACROS}

# The user can override the NO_PACKAGE by specifying this from
# the make command line
.if defined(FORCE_PACKAGE)
.undef NO_PACKAGE
.endif

COMMENT?=		${PKGDIR}/pkg-comment
DESCR?=			${PKGDIR}/pkg-descr
PLIST?=			${PKGDIR}/pkg-plist
PKGINSTALL?=	${PKGDIR}/pkg-install
PKGDEINSTALL?=	${PKGDIR}/pkg-deinstall
PKGREQ?=		${PKGDIR}/pkg-req
PKGMESSAGE?=	${PKGDIR}/pkg-message

TMPPLIST?=	${WRKDIR}/.PLIST.mktmp

.if ${OSVERSION} >= 400000
.for _CATEGORY in ${CATEGORIES}
PKGCATEGORY?=	${_CATEGORY}
.endfor
_PORTDIRNAME!=	${BASENAME} ${.CURDIR}
PORTDIRNAME?=	${_PORTDIRNAME}
PKGORIGIN?=		${PKGCATEGORY}/${PORTDIRNAME}
.endif

PKG_CMD?=		/usr/sbin/pkg_create
PKG_DELETE?=	/usr/sbin/pkg_delete
PKG_INFO?=		/usr/sbin/pkg_info
.if !defined(PKG_ARGS)
PKG_ARGS=		-v -c ${COMMENT} -d ${DESCR} -f ${TMPPLIST} -p ${PREFIX} -P "`${MAKE} package-depends | ${GREP} -v -E ${PKG_IGNORE_DEPENDS} | sort -u`" ${EXTRA_PKG_ARGS}
.if exists(${PKGINSTALL})
PKG_ARGS+=		-i ${PKGINSTALL}
.endif
.if exists(${PKGDEINSTALL})
PKG_ARGS+=		-k ${PKGDEINSTALL}
.endif
.if exists(${PKGREQ})
PKG_ARGS+=		-r ${PKGREQ}
.endif
.if exists(${PKGMESSAGE})
PKG_ARGS+=		-D ${PKGMESSAGE}
.endif
.if !defined(NO_MTREE)
PKG_ARGS+=		-m ${MTREE_FILE}
.endif
.if defined(PKGORIGIN)
PKG_ARGS+=		-o ${PKGORIGIN}
.endif
.endif
.if defined(PKG_NOCOMPRESS)
PKG_SUFX?=		.tar
.else
PKG_SUFX?=		.tgz
.endif
# where pkg_add records its dirty deeds.
PKG_DBDIR?=		/var/db/pkg

MOTIFLIB?=	-L${X11BASE}/lib -lXm -lXp

ALL_TARGET?=		all
INSTALL_TARGET?=	install

# Popular master sites
.include "bsd.sites.mk"

# Empty declaration to avoid "variable MASTER_SITES recursive" error
MASTER_SITES?=
PATCH_SITES?=
_MASTER_SITES_DEFAULT?=

# Feed internal _{MASTER,PATCH}_SITES_n where n is a group designation
# as per grouping rules (:something)
# Organize _{MASTER,PATCH}_SITES_{DEFAULT,[^/:]+} according to grouping
# rules (:something)
.for _S in ${MASTER_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
.			if ${_group}==all || ${_group}==ALL || ${_group}==default
.			BEGIN:
				@${ECHO} "The words all, ALL and default are reserved and cannot be used"
				@${ECHO} "in group definitions."
				@${ECHO} "Please fix your MASTER_SITES"
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
.			if ${_group}==all || ${_group}==ALL || ${_group}==default
.			BEGIN:
				@${ECHO} "The words all, ALL and default are reserved and cannot be used"
				@${ECHO} "in group definitions."
				@${ECHO} "Please fix your MASTER_SITES"
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
.			if ${_group}==all || ${_group}==ALL || ${_group}==default
.			BEGIN:
				@${ECHO} "The words all, ALL and default are reserved and cannot be used"
				@${ECHO} "in group definitions."
				@${ECHO} "Please fix your MASTER_SITE_SUBDIR"
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
.			if ${_group}==all || ${_group}==ALL || ${_group}==default
.			BEGIN:
				@${ECHO} "The words all, ALL and default are reserved and cannot be used"
				@${ECHO} "in group definitions."
				@${ECHO} "Please fix your PATCH_SITE_SUBDIR"
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
MASTER_SITES_TMP=
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
.			if defined(_MASTER_SITE_SUBDIR_${_group})
.				for dir in ${_MASTER_SITE_SUBDIR_${_group}}
MASTER_SITES_TMP+=	${_MASTER_SITES_${_group}:S^%SUBDIR%^${dir}^}
.				endfor
.			else
MASTER_SITES_TMP+=	${_MASTER_SITES_${_group}:S^%SUBDIR%/^^}
.			endif
_MASTER_SITES_${_group}:=	${MASTER_SITES_TMP}
.		endfor
.	endif
.endfor
MASTER_SITES_TMP=
.if defined(_MASTER_SITE_SUBDIR_DEFAULT)
.	for dir in ${_MASTER_SITE_SUBDIR_DEFAULT}
MASTER_SITES_TMP+=	${_MASTER_SITES_DEFAULT:S^%SUBDIR%^${dir}^}
.	endfor
.else
MASTER_SITES_TMP=	${_MASTER_SITES_DEFAULT:S^%SUBDIR%/^^}
.endif
_MASTER_SITES_DEFAULT:=	${MASTER_SITES_TMP}
MASTER_SITES_TMP=
.for _S in ${PATCH_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//:S/^://}
PATCH_SITES_TMP=
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/,/ /g}
.			if defined(_PATCH_SITE_SUBDIR_${_group})
.				for dir in ${_PATCH_SITE_SUBDIR_${_group}}
PATCH_SITES_TMP+=	${_PATCH_SITES_${_group}:S^%SUBDIR%^${dir}^}
.				endfor
.			else
PATCH_SITES_TMP+=	${_PATCH_SITES_${_group}:S^%SUBDIR%/^^}
.			endif
_PATCH_SITES_${_group}:=	${PATCH_SITES_TMP}
.		endfor
.	endif
.endfor
PATCH_SITES_TMP=
.if defined(_PATCH_SITE_SUBDIR_DEFAULT)
.	for dir in ${_PATCH_SITE_SUBDIR_DEFAULT}
PATCH_SITES_TMP+=	${_PATCH_SITES_DEFAULT:S^%SUBDIR%^${dir}^}
.	endfor
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
CD_MOUNTPTS?=	/cdrom ${CD_MOUNTPT}
.for MOUNTPT in ${CD_MOUNPTS}
.if exists(${MOUNTPT}/ports/distfiles)
_MASTER_SITE_OVERRIDE:=	file:${MOUNTPT}/ports/distfiles/${DIST_SUBDIR}/ ${_MASTER_SITE_OVERRIDE}
.if defined(FETCH_SYMLINK_DISTFILES)
FETCH_BEFORE_ARGS+=	-l
.endif
.endif
.endfor

# Organize DISTFILES, PATCHFILES, _MASTER_SITES_ALL, _PATCH_SITES_ALL
# according to grouping rules (:something)
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
_MASTER_SITES_ALL=	${_MASTER_SITES_DEFAULT}
_PATCH_SITES_ALL=	${_PATCH_SITES_DEFAULT}
.for _D in ${DISTFILES}
_D_TEMP=	${_D:S/^${_D:C/:[^:]+$//}//}
.	if !empty(_D_TEMP) && defined(_MASTER_SITES_${_D_TEMP:S/^://})
#_MASTER_SITES_ALL+=	${MASTER_SITES_${_D_TEMP:S/^://}}
_MASTER_SITES_ALL+=	${_MASTER_SITES_${_D:S/^${_D:C/:[^:]+$//}://}}
#_DISTFILES+=	${_D:S/:${_D_TEMP:S/^://}$//}
_DISTFILES+=	${_D:C/:[^:]+$//}
.	else
_DISTFILES+=	${_D}
.	endif
.endfor
.for _P in ${PATCHFILES}
_P_TEMP=	${_P:S/^${_P:C/:[^:]+$//}//}
.	if !empty(_P_TEMP) && defined(_PATCH_SITES_${_P_TEMP:S/^://})
_PATCH_SITES_ALL+=	${_PATCH_SITES_${_P:S/^${_P:C/:[^:]+$//}://}}
_PATCHFILES+=	${_P:C/:[^:]+$//}
.	else
_PATCHFILES+=	${_P}
.	endif
.endfor
ALLFILES?=	${_DISTFILES} ${_PATCHFILES}

#
# Sort the master site list according to the patterns in MASTER_SORT
#
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S|.|\\.|g:S|^|//[^/]*|:S|$|/|}

MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX}"; }
.for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+= /${srt:S^/^\\/^g}/ { good["${srt}"] = good["${srt}"] " " $$0 ; next; } 
.endfor
MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }
SORTED_MASTER_SITES_DEFAULT_CMD=	cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} master-sites-DEFAULT
SORTED_PATCH_SITES_DEFAULT_CMD=		cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} patch-sites-DEFAULT
SORTED_MASTER_SITES_ALL_CMD=	cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} master-sites-ALL
SORTED_PATCH_SITES_ALL_CMD=	cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} patch-sites-ALL

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
SORTED_MASTER_SITES_${_group}_CMD=	cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} master-sites-${_group}
master-sites-${_group}:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_MASTER_SITES_${_group}}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}
.			endif
.		endfor
.	endif
.endfor
.for _S in ${PATCH_SITES}
_S_TEMP=	${_S:S/^${_S:C@/:[^/:]+$@/@}//}
.	if !empty(_S_TEMP)
.		for _group in ${_S_TEMP:S/^://:S/,/ /g}
.			if !target(patch-sites-${_group})
SORTED_PATCH_SITES_${_group}_CMD=	cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} patch-sites-${_group}
patch-sites-${_group}:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_PATCH_SITES_${_group}}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}
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
_F_TEMP=	${_F:S/^${_F:C/:[^:]+$//}//:S/^://}
.	if !empty(_F_TEMP)
.		for _group in ${_F_TEMP:S/,/ /g}
.			if defined(_PATCH_SITES_${_group})
_PATCH_SITES_ENV+=	_PATCH_SITES_${_group}="${_PATCH_SITES_${_group}}"
.			endif
.		endfor
.	endif
.endfor

master-sites-ALL:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_MASTER_SITES_ALL}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}
patch-sites-ALL:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_PATCH_SITES_ALL}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}
# has similar effect to old targets, i.e., access only {MASTER,PATCH}_SITES, not working with the new _n variables
master-sites-DEFAULT:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_MASTER_SITES_DEFAULT}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}
patch-sites-DEFAULT:
	@echo ${_MASTER_SITE_OVERRIDE} `echo '${_PATCH_SITES_DEFAULT}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}

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
CKSUMFILES!=	\
	for file in ${ALLFILES}; do \
		ignore=0; \
		for tmp in ${IGNOREFILES}; do \
			if [ "$$file" = "$$tmp" ]; then \
				ignore=1; \
			fi; \
		done; \
		if [ "$$ignore" = 0 ]; then \
			echo "$$file"; \
		fi; \
	done
.endif
.else
CKSUMFILES=		${ALLFILES}
.endif

# List of all files, with ${DIST_SUBDIR} in front.  Used for checksum.
.if defined(DIST_SUBDIR)
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
.else
_CKSUMFILES?=	${CKSUMFILES}
_IGNOREFILES?=	${IGNOREFILES}
.endif

# This is what is actually going to be extracted, and is overridable
#  by user.
EXTRACT_ONLY?=	${_DISTFILES}

# Documentation
MAINTAINER?=	ports@FreeBSD.org

.if !target(maintainer)
maintainer:
	@${ECHO} ${MAINTAINER}
.endif

.if !defined(CATEGORIES)
.BEGIN:
	@${ECHO} "${PKGNAME}: CATEGORIES is mandatory."
	@${FALSE}
.else
VALID_CATEGORIES+=	afterstep archivers astro audio benchmarks biology \
	cad chinese comms converters databases deskutils devel \
	editors elisp emulators french ftp games german gnome graphics \
	hebrew ipv6 irc japanese java kde korean lang linux \
	mail math mbone misc net news \
	offix palm perl5 picobsd plan9 print python ruby russian \
	science security shells sysutils \
	tcl76 tcl80 tcl81 tcl82 tcl83 textproc \
	tk42 tk80 tk82 tk83 tkstep80 \
	ukrainian vietnamese windowmaker www \
	x11 x11-clocks x11-fm x11-fonts x11-servers x11-toolkits x11-wm zope
check-categories:
.for cat in ${CATEGORIES}
	@if ${ECHO} ${VALID_CATEGORIES} | ${GREP} -wq ${cat}; then \
		${TRUE}; \
	else \
		${ECHO} "${PKGNAME}: category ${cat} not in list of valid categories."; \
		${FALSE}; \
	fi
.endfor
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

.if defined(PERL_CONFIGURE)
CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}"
CONFIGURE_SCRIPT?=	Makefile.PL
USE_PERL5=			yes
.undef HAS_CONFIGURE
.endif

CONFIGURE_SCRIPT?=	configure
CONFIGURE_TARGET?=	${MACHINE_ARCH}--freebsd${OSREL}
CONFIGURE_LOG?=		config.log

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--prefix=${PREFIX} ${CONFIGURE_TARGET}
HAS_CONFIGURE=		yes
.endif

# Passed to most of script invocations
SCRIPTS_ENV+=	CURDIR=${MASTERDIR} DISTDIR=${DISTDIR} \
		  WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} \
		  SCRIPTDIR=${SCRIPTDIR} FILESDIR=${FILESDIR} \
		  PORTSDIR=${PORTSDIR} DEPENDS="${DEPENDS}" \
		  PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.if defined(BATCH)
SCRIPTS_ENV+=	BATCH=yes
.endif

MANPREFIX?=	${PREFIX}

.for sect in 1 2 3 4 5 6 7 8 9
MAN${sect}PREFIX?=	${MANPREFIX}
.endfor
MANLPREFIX?=	${MANPREFIX}
MANNPREFIX?=	${MANPREFIX}

MANLANG?=	""	# english only by default

.if !defined(NOMANCOMPRESS)
MANEXT=	.gz
.endif

.if (defined(MLINKS) || defined(_MLINKS_PREPEND)) && !defined(_MLINKS)
__pmlinks!=	${ECHO} '${MLINKS:S/	/ /}' | ${AWK} \
 '{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ($$i ~ /^-$$/ && i != 1 && i % 2 != 0) \
			{ $$i = $$(i-2); printf " " $$i " "; } \
		else if ($$i ~ /^[^ ]+\.[1-9ln][^. ]*$$/ || $$i ~ /^\//) \
			printf " " $$i " "; \
		else \
			{ print "broken"; exit; } \
	} \
  }' | ${SED} -e 's \([^/ ][^ ]*\.\(.\)[^. ]*\) $${MAN\2PREFIX}/man/$$$$$$$${__lang}/man\2/\1.gzg' -e 's/ //g' -e 's/MANlPREFIX/MANLPREFIX/g' -e 's/MANnPREFIX/MANNPREFIX/g'
.if ${__pmlinks:Mbroken} == "broken"
.BEGIN:
	@${ECHO} "${PKGNAME}: Unable to parse MLINKS."
	@${FALSE}
.endif
_MLINKS=	${_MLINKS_PREPEND}
.for lang in ${MANLANG}
.for ___pmlinks in ${__pmlinks}
.for __lang in ${lang}
_MLINKS+=	${___pmlinks:S// /g}
.endfor
.endfor
.endfor
.endif

.for lang in ${MANLANG}

.for sect in 1 2 3 4 5 6 7 8 9
.if defined(MAN${sect})
_MANPAGES+=	${MAN${sect}:S%^%${MAN${sect}PREFIX}/man/${lang}/man${sect}/%}
.endif
.endfor

.if defined(MANL)
_MANPAGES+=	${MANL:S%^%${MANLPREFIX}/man/${lang}/manl/%}
.endif

.if defined(MANN)
_MANPAGES+=	${MANN:S%^%${MANNPREFIX}/man/${lang}/mann/%}
.endif

.endfor

.if defined(_MLINKS) && make(generate-plist)
_TMLINKS!=	${ECHO} ${_MLINKS} | ${AWK} '{for (i=2; i<=NF; i+=2) print $$i}'
.else
_TMLINKS=
.endif

.if defined(_MANPAGES) && defined(NOMANCOMPRESS)
__MANPAGES:=	${_MANPAGES:S^${PREFIX}/^^:S/""//:S^//^/^g}
.elif defined(_MANPAGES)
__MANPAGES:=	${_MANPAGES:S^${PREFIX}/^^:S/""//:S^//^/^g:S/$/.gz/}
.endif

.if defined(_MANPAGES) && ${MANCOMPRESSED} == "yes"
_MANPAGES:=	${_MANPAGES:S/$/.gz/}
.endif

.if ${XFREE86_VERSION} == 3
XFREE86_HTML_MAN=	no
.else
.if defined(USE_IMAKE)
XFREE86_HTML_MAN?=	yes
.else
XFREE86_HTML_MAN?=	no
.endif
.endif

# Put this for down as possible so it will catch all PLIST_SUB definitions.

.if defined(INSTALLS_SHLIB)
LDCONFIG_DIRS?=	%%PREFIX%%/lib
LDCONFIG_PLIST!=	${ECHO} ${LDCONFIG_DIRS} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}
LDCONFIG_RUNLIST!=	${ECHO} ${LDCONFIG_PLIST} | ${SED} -e "s!%D!${PREFIX}!g"
.endif

DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PORTNAME}
DATADIR?=	${PREFIX}/share/${PORTNAME}

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
# Don't build a port on an ELF machine if it's broken for ELF.
#
# Don't build a port if it's broken, unless we're running a parallel
# build (in case it's fixed).
#
# Don't build a port if it's forbidden for whatever reason.
#
# Don't build a port if the system is too old.
################################################################

.if ${OSVERSION} >= 300000
# You need an upgrade kit or make world newer than this
BSDPORTMKVERSION=	20001103
.if exists(/var/db/port.mkversion)
VERSIONFILE=	/var/db/port.mkversion
.else
VERSIONFILE=	${PKG_DBDIR}/.mkversion
.endif
.if exists(${VERSIONFILE})
.if !defined(SYSTEMVERSION)
SYSTEMVERSION!=	cat ${VERSIONFILE}
.endif
.else
SYSTEMVERSION=	0
.endif
.if ${BSDPORTMKVERSION} > ${SYSTEMVERSION}
IGNORE=	": Your system is too old to use this bsd.port.mk.  You need a fresh make world or an upgrade kit.  Please go to http://www.FreeBSD.org/ports/ or a mirror site and follow the instructions"
.endif
.endif

.if defined(ONLY_FOR_ARCHS)
.for __ARCH in ${ONLY_FOR_ARCHS}
.if ${MACHINE_ARCH:M${__ARCH}} != ""
__ARCH_OK?=     1
.endif
.endfor
.else
__ARCH_OK?=     1
.endif

.if defined(NOT_FOR_ARCHS)
.for __NARCH in ${NOT_FOR_ARCHS}
.if ${MACHINE_ARCH:M${__NARCH}} != ""
.undef __ARCH_OK
.endif
.endfor
.endif

.if !defined(__ARCH_OK)
.if defined(ONLY_FOR_ARCHS)
IGNORE=		"is only for ${ONLY_FOR_ARCHS},"
.else # defined(NOT_FOR_ARCHS)
IGNORE=		"does not run on ${NOT_FOR_ARCHS},"
.endif
IGNORE+=	"and you are running ${ARCH}"
.endif

.if !defined(NO_IGNORE)
.if (defined(IS_INTERACTIVE) && defined(BATCH))
IGNORE=	"is an interactive port"
.elif (!defined(IS_INTERACTIVE) && defined(INTERACTIVE))
IGNORE=	"is not an interactive port"
.elif (defined(NO_CDROM) && defined(FOR_CDROM))
IGNORE=	"may not be placed on a CDROM: ${NO_CDROM}"
.elif (defined(RESTRICTED) && defined(NO_RESTRICTED))
IGNORE=	"is restricted: ${RESTRICTED}"
.elif defined(NO_WRKDIR)
IGNORE=	"defines NO_WRKDIR, which is obsoleted.  If you are defining NO_WRKDIR and NO_EXTRACT, try changing it to NO_WRKSUBDIR=yes and EXTRACT_ONLY= \(the right side intentionally left empty\)"
.elif defined(NO_EXTRACT)
IGNORE=	"defines NO_EXTRACT, which is obsoleted.  Try changing it to EXTRACT_ONLY= \(the right side intentionally left empty\)"
.elif defined(NO_CONFIGURE)
IGNORE=	"defines NO_CONFIGURE, which is obsoleted"
.elif defined(NO_PATCH)
IGNORE=	"defines NO_PATCH, which is obsoleted"
.elif defined(BROKEN_ELF) && (${PORTOBJFORMAT} == "elf") && \
	  !defined(PARALLEL_PACKAGE_BUILD)
IGNORE=	"is broken for ELF: ${BROKEN_ELF}"
.elif defined(BROKEN)
.if defined(PARALLEL_PACKAGE_BUILD)
# try building even if marked BROKEN
TRYBROKEN=	yes
.else
IGNORE=	"is marked as broken: ${BROKEN}"
.endif
.elif defined(FORBIDDEN)
IGNORE=	"is forbidden: ${FORBIDDEN}"
.endif

.if (defined(MANUAL_PACKAGE_BUILD) && defined(PACKAGE_BUILDING) && !defined(PARALLEL_PACKAGE_BUILD))
IGNORE=	"has to be built manually: ${MANUAL_PACKAGE_BUILD}"
clean:
	@${IGNORECMD}
.endif

.if defined(IGNORE)
.if defined(IGNORE_SILENT)
IGNORECMD=	${DO_NADA}
.else
IGNORECMD=	${ECHO_MSG} "===>  ${PKGNAME} ${IGNORE}."
.endif
fetch:
	@${IGNORECMD}
checksum:
	@${IGNORECMD}
extract:
	@${IGNORECMD}
patch:
	@${IGNORECMD}
configure:
	@${IGNORECMD}
all:
	@${IGNORECMD}
build:
	@${IGNORECMD}
install:
	@${IGNORECMD}
reinstall:
	@${IGNORECMD}
package:
	@${IGNORECMD}
.endif

.endif

.if defined(IGNORE) || defined(NO_PACKAGE)
ignorelist: package-name
.else
ignorelist:
	@${DO_NADA}
.endif

################################################################
# Clean directories for ftp or CDROM.
################################################################

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

.if defined(ALL_HOOK)
all:
	@cd ${.CURDIR} && ${SETENV} CURDIR=${.CURDIR} DISTNAME=${DISTNAME} \
	  DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} \
	  PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	  FILESDIR=${FILESDIR} PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} \
	  DEPENDS="${DEPENDS}" BUILD_DEPENDS="${BUILD_DEPENDS}" \
	  RUN_DEPENDS="${RUN_DEPENDS}" X11BASE=${X11BASE} \
	${ALL_HOOK}
.endif

.if !target(all)
all: build
.endif

.if !defined(DEPENDS_TARGET)
.if make(reinstall)
DEPENDS_TARGET=	reinstall
.else
DEPENDS_TARGET=	install
.endif
.if defined(DEPENDS_CLEAN)
DEPENDS_TARGET+=	clean
DEPENDS_ARGS+=	NOCLEANDEPENDS=yes
.endif
.else
DEPENDS_ARGS+=	FORCE_PKG_REGISTER=yes
.endif
.if defined(DEPENDS)
# pretty much guarantees overwrite of existing installation
.MAKEFLAGS:	FORCE_PKG_REGISTER=yes
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
.if defined(NO_INSTALL) && !target(install)
install: build
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

# Disable package
.if defined(NO_PACKAGE) && !target(package)
package:
.if defined(IGNORE_SILENT)
	@${DO_NADA}
.else
	@${ECHO_MSG} "===>  ${PKGNAME} may not be packaged: ${NO_PACKAGE}."
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

# Fetch

.if !target(do-fetch)
do-fetch:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 ${_MASTER_SITES_ENV} ; \
	 for _file in ${DISTFILES}; do \
		file=`echo $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
		select=`echo $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			if [ -f ${MD5_FILE} -a "x${NO_CHECKSUM}" = "x" ]; then \
				if ! ${GREP} -q "^MD5 (.*$$file)" ${MD5_FILE}; then \
					${ECHO_MSG} ">> $$file is not in ${MD5_FILE}."; \
					${ECHO_MSG} ">> Either ${MD5_FILE} is out of date, or"; \
					${ECHO_MSG} ">> $$file is spelled incorrectly."; \
					exit 1; \
				fi; \
			fi; \
			${ECHO_MSG} ">> $$file doesn't seem to exist in ${_DISTDIR}."; \
			if [ ! -z "$$select" ] ; then \
				__MASTER_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_MASTER_SITES_$${group}} ] ; then \
						eval ___MASTER_SITES_TMP="\$${_MASTER_SITES_$${group}}" ; \
						__MASTER_SITES_TMP="$${__MASTER_SITES_TMP} $${___MASTER_SITES_TMP}" ; \
					fi \
				done; \
				___MASTER_SITES_TMP= ; \
				SORTED_MASTER_SITES_CMD_TMP="echo ${_MASTER_SITE_OVERRIDE} `echo '$${__MASTER_SITES_TMP}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_MASTER_SITES_CMD_TMP="${SORTED_MASTER_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_MASTER_SITES_CMD_TMP`; do \
			    ${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
				DIR=${DIST_SUBDIR}; \
				CKSIZE=`${GREP} "^SIZE ($${DIR:+$$DIR/}$$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
				case $${file} in \
				*/*)	${MKDIR} $${file%/*}; \
						args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} ${FETCH_AFTER_ARGS}; then \
					continue 2; \
				fi \
			done; \
			${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} ">> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
	    fi \
	 done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	 ${_PATCH_SITES_ENV} ; \
	 for _file in ${PATCHFILES}; do \
		file=`echo $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
		select=`echo $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			${ECHO_MSG} ">> $$file doesn't seem to exist in ${_DISTDIR}."; \
			if [ ! -z $$select ] ; then \
				__PATCH_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_PATCH_SITES_$${group}} ] ; then \
						eval ___PATCH_SITES_TMP="\$${_PATCH_SITES_$${group}}" ; \
						__PATCH_SITES_TMP="$${__PATCH_SITES_TMP} $${___PATCH_SITES_TMP}" ; \
					fi \
				done; \
				___PATCH_SITES_TMP= ; \
				SORTED_PATCH_SITES_CMD_TMP="echo ${_MASTER_SITE_OVERRIDE} `echo '$${__PATCH_SITES_TMP}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_PATCH_SITES_CMD_TMP="${SORTED_PATCH_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_PATCH_SITES_CMD_TMP`; do \
			    ${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
				DIR=${DIST_SUBDIR}; \
				CKSIZE=`${GREP} "^SIZE ($${DIR:+$$DIR/}$$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
				case $${file} in \
				*/*)	${MKDIR} $${file%/*}; \
						args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} ${FETCH_AFTER_ARGS}; then \
					continue 2; \
				fi \
			done; \
			${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} ">> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
	    fi \
	 done)
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
		fi \
	done
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif
.endif

# Patch

.if !target(do-patch)
do-patch:
.if defined(PATCHFILES)
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
	  for i in ${_PATCHFILES}; do \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch $$i" ; \
		fi; \
		case $$i in \
			*.Z|*.gz) \
				${GZCAT} $$i | ${PATCH} ${PATCH_DIST_ARGS}; \
				;; \
			*.bz2) \
				${BZCAT} $$i | ${PATCH} ${PATCH_DIST_ARGS}; \
				;; \
			*) \
				${PATCH} ${PATCH_DIST_ARGS} < $$i; \
				;; \
		esac; \
	  done)
.endif
.if defined(EXTRA_PATCHES)
	@for i in ${EXTRA_PATCHES}; do \
		${ECHO_MSG} "===>  Applying extra patch $$i"; \
		${PATCH} ${PATCH_ARGS} < $$i; \
	done
.endif
	@if [ -d ${PATCHDIR} ]; then \
		if [ "`echo ${PATCHDIR}/patch-*`" != "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "===>  Applying ${OPSYS} patches for ${PKGNAME}" ; \
			PATCHES_APPLIED="" ; \
			for i in ${PATCHDIR}/patch-*; do \
				case $$i in \
					*.orig|*.rej|*~) \
						${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
						;; \
					*) \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
						fi; \
						if ${PATCH} ${PATCH_ARGS} < $$i ; then \
							PATCHES_APPLIED="$$PATCHES_APPLIED $$i" ; \
						else \
							${ECHO_MSG} `${ECHO} ">> Patch $$i failed to apply cleanly." | ${SED} "s|${PATCHDIR}/||"` ; \
							if [ x"$$PATCHES_APPLIED" != x"" ]; then \
								${ECHO_MSG} `${ECHO} ">> Patch(es) $$PATCHES_APPLIED applied cleanly." | ${SED} "s|${PATCHDIR}/||g"` ; \
							fi; \
							${FALSE} ; \
						fi; \
						;; \
				esac; \
			done; \
		fi; \
	fi
.endif

# Configure

.if !target(do-configure)
do-configure:
.if defined(USE_AUTOMAKE)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
.endif
.if defined(USE_AUTOCONF)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
.endif
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		  ${SCRIPTDIR}/configure; \
	fi
.if defined(HAS_CONFIGURE)
	@(cd ${CONFIGURE_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
			${CAT} ${CONFIGURE_LOG}; \
			${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
			${FALSE}; \
		fi)
.endif
.if defined(PERL_CONFIGURE)
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endif
.if defined(USE_IMAKE)
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})
.endif
.endif

# Build

.if !target(do-build)
do-build:
.if defined(USE_GMAKE)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.else
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif
.endif

# Install

.if !target(do-install)
do-install:
.if defined(USE_GMAKE)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install.man)
.endif
.else defined(USE_GMAKE)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install.man)
.endif
.endif
.endif

# Package

.if !target(do-package)
do-package: ${TMPPLIST}
	@${ECHO_MSG} "===>  Building package for ${PKGNAME}"
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} ">> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi
	@__softMAKEFLAGS='${__softMAKEFLAGS:S/'/'\''/g}'; \
	if ${PKG_CMD} ${PKG_ARGS} ${PKGFILE}; then \
		if [ -d ${PACKAGES} ]; then \
			eval ${MAKE} $${__softMAKEFLAGS} package-links; \
		fi; \
	else \
		eval ${MAKE} $${__softMAKEFLAGS} delete-package; \
		exit 1; \
	fi
.endif

# Some support rules for do-package

.if !target(package-links)
package-links:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} delete-package-links
	@for cat in ${CATEGORIES}; do \
		if [ ! -d ${PACKAGES}/$$cat ]; then \
			if ! ${MKDIR} ${PACKAGES}/$$cat; then \
				${ECHO_MSG} ">> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1; \
			fi; \
		fi; \
		${LN} -sf `${ECHO} $$cat | ${SED} -e 'sa[^/]*a..ag'`/${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done
.if !defined(NO_LATEST_LINK)
	@if [ ! -d ${PKGLATESTREPOSITORY} ]; then \
		if ! ${MKDIR} ${PKGLATESTREPOSITORY}; then \
			${ECHO_MSG} ">> Can't create directory ${PKGLATESTREPOSITORY}."; \
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
delete-package:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} delete-package-links
	@${RM} -f ${PKGFILE}
.endif

.if !target(delete-package-links-list)
delete-package-links-list:
	@for cat in ${CATEGORIES}; do \
		${ECHO} ${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
	done
.if !defined(NO_LATEST_LINK)
	@${ECHO} ${RM} -f ${PKGLATESTFILE}
.endif
.endif

.if !target(delete-package-list)
delete-package-list:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} delete-package-links-list
	@${ECHO} "[ -f ${PKGFILE} ] && (${ECHO} deleting ${PKGFILE}; ${RM} -f ${PKGFILE})"
.endif

################################################################
# This is the "generic" port target, actually a macro used from the
# six main targets.  See below for more.
################################################################

_PORT_USE: .USE
.if make(real-fetch)
.if defined(TRYBROKEN)
	@${ECHO_MSG} "Trying build of ${PKGNAME} even though it is marked BROKEN."
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch-depends
.endif
.if make(real-extract)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} checksum REAL_EXTRACT=yes
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} build-depends lib-depends misc-depends
.endif
.if make(real-install)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} check-categories
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
	@if [ -d ${PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO} "===>  ${PKGNAME} is already installed - perhaps an older version?"; \
		${ECHO} "      If so, you may wish to \`\`make deinstall'' and install"; \
		${ECHO} "      this port again by \`\`make reinstall'' to upgrade it properly."; \
		${ECHO} "      If you really wish to overwrite the old port of ${PKGNAME}"; \
		${ECHO} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
		${ECHO} "      in your environment or the \"make install\" command line."; \
		exit 1; \
	fi
.endif
	@if [ `${SH} -c umask` != 0022 ]; then \
		${ECHO_MSG} "===>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "      If this is not desired, set it to an appropriate value"; \
		${ECHO_MSG} "      and install this port again by \`\`make reinstall''."; \
	fi
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} run-depends lib-depends
.endif
.if make(real-install)
	@${MKDIR} ${PREFIX}
	@if [ `id -u` != 0 ]; then \
		if [ -w ${PREFIX}/ ]; then \
			${ECHO_MSG} "Warning: not superuser, you may get some errors during installation."; \
		else \
			${ECHO_MSG} "Error: ${PREFIX}/ not writable."; \
			${FALSE}; \
		fi; \
	fi
.if !defined(NO_MTREE)
	@if [ `id -u` = 0 ]; then \
		if [ ! -f ${MTREE_FILE} ]; then \
			${ECHO} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			${ECHO} "Copy it from a suitable location (e.g., /usr/src/etc/mtree) and try again."; \
			exit 1; \
		else \
			${MTREE_CMD} ${MTREE_ARGS} ${PREFIX}/ >/dev/null; \
		fi; \
	else \
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "You may want to become root and try again to ensure correct permissions."; \
	fi
.endif
.endif
.if make(real-configure) && defined(USE_LIBTOOL)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} patch-libtool
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} ${.TARGET:S/^real-/pre-/}
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/^real-/pre-/} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/^real-/pre-/}; \
	fi
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} ${.TARGET:S/^real-/do-/}
# put here so ports can change the contents of ${TMPPLIST} if necessary
.if make(real-install)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} generate-plist
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} ${.TARGET:S/^real-/post-/}
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/^real-/post-/} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/^real-/post-/}; \
	fi
.if make(real-install) && (defined(_MANPAGES) || defined(_MLINKS))
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} compress-man
.endif
.if make(real-install) && defined(INSTALLS_SHLIB)
	@${ECHO_MSG} "===>   Running ldconfig"
	${LDCONFIG} -m ${LDCONFIG_RUNLIST}
.endif
.if make(real-install) && !defined(NO_PKG_REGISTER)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fake-pkg
.endif
.if !make(real-fetch) \
	&& (!make(real-patch) || !defined(PATCH_CHECK_ONLY)) \
	&& (!make(real-package) || !defined(PACKAGE_NOINSTALL))
	@${TOUCH} ${TOUCH_FLAGS} ${WRKDIR}/.${.TARGET:S/^real-//}_done.${PKGNAME}
.endif

################################################################
# Skeleton targets start here
# 
# You shouldn't have to change these.  Either add the pre-* or
# post-* targets/scripts or redefine the do-* targets.  These
# targets don't do anything other than checking for cookies and
# call the necessary targets/scripts.
################################################################

.if !target(pre-everything)
pre-everything:
	@${DO_NADA}
.endif

.if !target(fetch)
fetch:	pre-everything
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-fetch
.endif

.if !target(extract)
extract: ${EXTRACT_COOKIE}
.endif

.if !target(patch)
patch: ${PATCH_COOKIE}
.endif

.if !target(configure)
configure: ${CONFIGURE_COOKIE}
.endif

.if !target(build)
build: ${BUILD_COOKIE}
.endif

.if !target(install)
install: ${INSTALL_COOKIE}
.endif

.if !target(package)
package: ${PACKAGE_COOKIE}
.endif

${EXTRACT_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-extract
${PATCH_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} extract
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-patch
${CONFIGURE_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} patch
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-configure
${BUILD_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} configure
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-build
${INSTALL_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} build
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-install
# Scan PLIST for setugid files and startup scripts
	-@for i in `${GREP} -v '^@' ${TMPPLIST}`; do \
		${FIND} ${PREFIX}/$$i -prune -type f \( -perm -4000 -o -perm -2000 \) \( -perm -0010 -o -perm -0001 \) -ls 2>/dev/null; \
	done > ${WRKDIR}/.PLIST.setuid; \
	${GREP} '^etc/rc.d/' ${TMPPLIST} > ${WRKDIR}/.PLIST.startup; \
	if [ -s ${WRKDIR}/.PLIST.setuid -o -s ${WRKDIR}/.PLIST.startup ]; then \
		echo "===>  SECURITY NOTE: "; \
		if [ -s ${WRKDIR}/.PLIST.setuid ] ; then \
			echo "      This port has installed the following binaries which execute with"; \
			echo "      increased privileges."; \
			${CAT} ${WRKDIR}/.PLIST.setuid; \
			echo; \
		fi; \
		if [ -s ${WRKDIR}/.PLIST.startup ] ; then \
			echo "      This port has installed the following startup scripts which may cause"; \
			echo "      network services to be started at boot time."; \
			${SED} s,^,${PREFIX}/, < ${WRKDIR}/.PLIST.startup; \
			echo; \
		fi; \
		echo "      If there are vulnerabilities in these programs there may be a security"; \
		echo "      risk to the system. FreeBSD makes no guarantee about the security of"; \
		echo "      ports included in the Ports Collection. Please type 'make deinstall'"; \
		echo "      to deinstall the port if this is a concern."; \
	    if [ ! -z "`make www-site`" ]; then \
			echo; \
			echo "      For more information, and contact details about the security"; \
			echo "      status of this software, see the following webpage: "; \
			${MAKE} www-site; \
		fi; \
	fi

${PACKAGE_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} install
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} real-package

# And call the macros

real-fetch: _PORT_USE
real-extract: _PORT_USE
	@${ECHO_MSG} "===>  Extracting for ${PKGNAME}"
real-patch: _PORT_USE
	@${ECHO_MSG} "===>  Patching for ${PKGNAME}"
real-configure: _PORT_USE
	@${ECHO_MSG} "===>  Configuring for ${PKGNAME}"
real-build: _PORT_USE
	@${ECHO_MSG} "===>  Building for ${PKGNAME}"
real-install: _PORT_USE
	@${ECHO_MSG} "===>  Installing for ${PKGNAME}"
real-package: _PORT_USE

# Empty pre-* and post-* targets, note we can't use .if !target()
# in the _PORT_USE macro

.for name in fetch extract patch configure build install package

.if !target(pre-${name})
pre-${name}:
	@${DO_NADA}
.endif

.if !target(post-${name})
post-${name}:
	@${DO_NADA}
.endif

.endfor

.if defined(GNOME_OPTION_MSG) && (!defined(PACKAGE_BUILDING) || !defined(BATCH))
pre-everything:: echo-gnome-option-msg

echo-gnome-option-msg:
	@for m in ${GNOME_OPTION_MSG}; do \
		${ECHO_MSG} $$m; \
	done
.endif

# Patch-libtool
#
# Special target to automatically make libtool using ports use the
# libtool port.  See above for default values of LIBTOOLFILES.
#
# This target works by first checking the version of the installed
# libtool shell script, which is not actually used.  Rather its path
# is determined, and used to find the path to ltconfig and ltmain.sh
# (which is ../share/libtool/).  Then the configure script is copied
# and the default paths for ltconfig and ltmain.sh (normally ./) is
# replaced.  The port's configure script therefore uses the files
# installed by the libtool port in place of it's own.
#
# Also passed to ltconfig are ${LIBTOOLFLAGS}, which can be used to
# customise the behaviour of the port.  Besides the normal flags the
# freebsd port of libtool supports three special flags:
#  --disable-ltlibs		Don't install the .la files. (on by default)
#  --release-ignore		Ignore any -release flags. (off by default)
#  --release-suffix		Add the -release to all libraries, not just
#						the shared library. (off by default)
#

.if !target(patch-libtool)
patch-libtool:
	@(if ${LIBTOOL} --version | grep -vq "1\.3\.4-freebsd-ports"; then \
		(${ECHO} "Your libtool installation is out of date. Please remove"; \
		 ${ECHO} "and reinstall ${PORTSDIR}/devel/libtool."; \
		 exit 1); \
	  fi; \
	 LIBTOOLDIR=`${WHICH} ${LIBTOOL} | ${SED} -e 's^/bin/libtool^/share/libtool^'` || ${LOCALBASE}/share/libtool; \
	 cd ${PATCH_WRKSRC}; \
	 for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "s^\$$ac_aux_dir/ltconfig^$${LIBTOOLDIR}/ltconfig^g" \
			-e "s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} $${LIBTOOLDIR}/ltmain.sh^g" \
			$$file.tmp > $$file; \
	 done);
.endif

# Checkpatch
#
# Special target to verify patches

.if !target(checkpatch)
checkpatch:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} PATCH_CHECK_ONLY=yes patch
.endif

# Reinstall
#
# Special target to re-run install

.if !target(reinstall)
reinstall:
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
	@cd ${.CURDIR} && DEPENDS_TARGET="${DEPENDS_TARGET}" ${MAKE} install
.endif

# Deinstall
#
# Special target to remove installation

.if !target(deinstall)
deinstall:
	@${ECHO_MSG} "===>  Deinstalling for ${PKGNAME}"
	@if ${PKG_INFO} -e ${PKGNAME}; then \
		${PKG_DELETE} -f ${PKGNAME}; \
	 else \
		${ECHO_MSG} "===>   ${PKGNAME} not installed, skipping"; \
	 fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif

################################################################
# Some more targets supplied for users' convenience
################################################################

# Cleaning up

.if !target(do-clean)
do-clean:
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
.endif

.if !target(clean)
clean:
.if !defined(NOCLEANDEPENDS)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} clean-depends
.endif
	@${ECHO_MSG} "===>  Cleaning for ${PKGNAME}"
.if target(pre-clean)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} pre-clean
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} do-clean
.if target(post-clean)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} post-clean
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
	@${ECHO} "# ${PKGNAME}"
	@if [ "X${RESTRICTED_FILES}" != "X" ]; then \
		for file in ${RESTRICTED_FILES}; do \
			${ECHO} "[ -f ${_DISTDIR}/$$file ] && (${ECHO} deleting ${_DISTDIR}/$$file; ${RM} -f ${_DISTDIR}/$$file)"; \
			dir=$${file%/*}; \
			if [ "$${dir}" != "$${file}" ]; then \
				${ECHO} "(cd ${_DISTDIR} && ${RMDIR} -p $${dir} 2>/dev/null)"; \
			fi; \
		done; \
	fi
.if defined(DIST_SUBDIR)
	@${ECHO} "${RMDIR} ${_DISTDIR} 2>/dev/null || ${TRUE}"
.endif
.endif

# Prints out a list of files to fetch (useful to do a batch fetch)

.if !target(fetch-list)
fetch-list:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 ${_MASTER_SITES_ENV} ; \
	 for _file in ${DISTFILES}; do \
		file=`echo $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
		select=`echo $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ ! -z "$$select" ] ; then \
				__MASTER_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_MASTER_SITES_$${group}} ] ; then \
						eval ___MASTER_SITES_TMP=\$${_MASTER_SITES_$${group}} ; \
						__MASTER_SITES_TMP="$${__MASTER_SITES_TMP} $${___MASTER_SITES_TMP}" ; \
					fi \
				done; \
				___MASTER_SITES_TMP= ; \
				SORTED_MASTER_SITES_CMD_TMP="echo ${_MASTER_SITE_OVERRIDE} `echo '$${__MASTER_SITES_TMP}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_MASTER_SITES_CMD_TMP="${SORTED_MASTER_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_MASTER_SITES_CMD_TMP`; do \
				DIR=${DIST_SUBDIR}; \
				CKSIZE=`${GREP} "^SIZE ($${DIR:+$$DIR/}$$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO} -n ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO} "echo $${file} not fetched" ; \
		fi \
	done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	 ${_PATCH_SITES_ENV} ; \
	 for _file in ${PATCHFILES}; do \
		file=`echo $$_file | ${SED} -E -e 's/:[^:]+$$//'` ; \
		select=`echo $${_file#$${file}} | ${SED} -e 's/^://' -e 's/,/ /g'` ; \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ ! -z "$$select" ] ; then \
				__PATCH_SITES_TMP= ; \
				for group in $$select; do \
					if [ ! -z \$${_PATCH_SITES_$${group}} ] ; then \
						eval ___PATCH_SITES_TMP=\$${_PATCH_SITES_$${group}} ; \
						__PATCH_SITES_TMP="$${__PATCH_SITES_TMP} $${___PATCH_SITES_TMP}" ; \
					fi \
				done; \
				___PATCH_SITES_TMP= ; \
				SORTED_PATCH_SITES_CMD_TMP="echo ${_MASTER_SITE_OVERRIDE} `echo '$${__PATCH_SITES_TMP}' | ${AWK} '${MASTER_SORT_AWK}'` ${_MASTER_SITE_BACKUP}" ; \
			else \
				SORTED_PATCH_SITES_CMD_TMP="${SORTED_PATCH_SITES_DEFAULT_CMD}" ; \
			fi ; \
			for site in `eval $$SORTED_PATCH_SITES_CMD_TMP`; do \
				DIR=${DIST_SUBDIR}; \
				CKSIZE=`${GREP} "^SIZE ($${DIR:+$$DIR/}$$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
				case $${file} in \
				*/*)	args="-o $${file} $${site}$${file}";; \
				*)		args=$${site}$${file};; \
				esac; \
				${ECHO} -n ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${args} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO} "echo $${file} not fetched" ; \
		fi \
	 done)
.endif
.endif

# Checksumming utilities

.if !target(makesum)
makesum:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch NO_CHECKSUM=yes
	@if [ -f ${MD5_FILE} ]; then ${RM} -f ${MD5_FILE}; fi
	@(cd ${DISTDIR}; \
	 for file in ${_CKSUMFILES}; do \
		${MD5} $$file >> ${MD5_FILE}; \
	 done)
	@for file in ${_IGNOREFILES}; do \
		${ECHO} "MD5 ($$file) = IGNORE" >> ${MD5_FILE}; \
	done
.endif
# this line goes after the ${MD5} above
#		echo "SIZE ($$file) = "`wc -c < $$file` >> ${MD5_FILE}; \


.if !target(checksum)
checksum:
.if !defined(REAL_EXTRACT)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch
.endif
	@if [ ! -f ${MD5_FILE} ]; then \
		${ECHO_MSG} ">> No MD5 checksum file."; \
	else \
		(cd ${DISTDIR}; OK="true"; \
		  for file in ${_CKSUMFILES}; do \
			CKSUM=`${MD5} < $$file`; \
			CKSUM2=`${GREP} "^MD5 ($$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
			if [ "$$CKSUM2" = "" ]; then \
				${ECHO_MSG} ">> No checksum recorded for $$file."; \
				OK="false"; \
			elif [ "$$CKSUM2" = "IGNORE" ]; then \
				${ECHO_MSG} ">> Checksum for $$file is set to IGNORE in distinfo file even though"; \
				${ECHO_MSG} "   the file is not in the "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			elif ${EXPR} "$$CKSUM2" : ".*$$CKSUM" > /dev/null; then \
				${ECHO_MSG} ">> Checksum OK for $$file."; \
			else \
				${ECHO_MSG} ">> Checksum mismatch for $$file."; \
				OK="false"; \
			fi; \
		  done; \
		  for file in ${_IGNOREFILES}; do \
			CKSUM2=`${GREP} "($$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
			if [ "$$CKSUM2" = "" ]; then \
				${ECHO_MSG} ">> No checksum recorded for $$file, file is in "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			elif [ "$$CKSUM2" != "IGNORE" ]; then \
				${ECHO_MSG} ">> Checksum for $$file is not set to IGNORE in distinfo file even though"; \
				${ECHO_MSG} "   the file is in the "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			fi; \
		  done; \
		  if [ "$$OK" != "true" ]; then \
			${ECHO_MSG} "Make sure the Makefile and distinfo file (${MD5_FILE})"; \
			${ECHO_MSG} "are up to date.  If you are absolutely sure you want to override this"; \
			${ECHO_MSG} "check, type \"make NO_CHECKSUM=yes [other args]\"."; \
			exit 1; \
		  fi) ; \
	fi
.endif

################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

# Nobody should want to override this unless PKGNAME is simply bogus.

.if !target(package-name)
package-name:
	@${ECHO} ${PKGNAME}
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
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} PACKAGE_NOINSTALL=yes real-package
	@${RM} -f ${TMPPLIST}
	-@${RMDIR} ${WRKDIR}
.endif

################################################################
# Dependency checking
################################################################

.if !target(depends)
depends: lib-depends misc-depends
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch-depends
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} build-depends
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} run-depends

.if make(fetch-depends)
DEPENDS_TMP+=	${FETCH_DEPENDS}
.endif

.if make(build-depends)
DEPENDS_TMP+=	${BUILD_DEPENDS}
.endif

.if make(run-depends)
DEPENDS_TMP+=	${RUN_DEPENDS}
.endif

.if defined(ALWAYS_BUILD_DEPENDS)
_DEPEND_ALWAYS=	1
.else
_DEPEND_ALWAYS=	0
.endif

_DEPENDS_USE:	.USE
.if defined(DEPENDS_TMP)
.if !defined(NO_DEPENDS)
	@for i in ${DEPENDS_TMP}; do \
		prog=`${ECHO} $$i | ${SED} -e 's/:.*//'`; \
		dir=`${ECHO} $$i | ${SED} -e 's/[^:]*://'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		if ${EXPR} "$$prog" : \\/ >/dev/null; then \
			if [ -e "$$prog" ]; then \
				${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - found"; \
				if [ ${_DEPEND_ALWAYS} = 1 ]; then \
					${ECHO_MSG} "       (but building it anyway)"; \
					notfound=1; \
				else \
					notfound=0; \
				fi; \
			else \
				${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - not found"; \
				notfound=1; \
			fi; \
		else \
			if ${WHICH} "$$prog" > /dev/null 2>&1 ; then \
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
				${ECHO_MSG} "     >> No directory for $$prog.  Skipping.."; \
			else \
				(cd $$dir; ${MAKE} $$target $$depends_args) ; \
				${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"; \
			fi; \
		fi; \
	done
.endif
.else
	@${DO_NADA}
.endif

fetch-depends:	_DEPENDS_USE
build-depends:	_DEPENDS_USE
run-depends:	_DEPENDS_USE

lib-depends:
.if defined(LIB_DEPENDS)
.if !defined(NO_DEPENDS)
	@for i in ${LIB_DEPENDS}; do \
		lib=`${ECHO} $$i | ${SED} -e 's/:.*//'`; \
		dir=`${ECHO} $$i | ${SED} -e 's/[^:]*://'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		if ${LDCONFIG} -r | ${GREP} -qwF -e "-l$$lib"; then \
			${ECHO_MSG} "===>   ${PKGNAME} depends on shared library: $$lib - found"; \
			if [ ${_DEPEND_ALWAYS} = 1 ]; then \
				${ECHO_MSG} "       (but building it anyway)"; \
				notfound=1; \
			else \
				notfound=0; \
			fi; \
		else \
			${ECHO_MSG} "===>   ${PKGNAME} depends on shared library: $$lib - not found"; \
			notfound=1; \
		fi; \
		if [ $$notfound != 0 ]; then \
			${ECHO_MSG} "===>    Verifying $$target for $$lib in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} "     >> No directory for $$lib.  Skipping.."; \
			else \
				(cd $$dir; ${MAKE} $$target $$depends_args) ; \
				${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"; \
				if ${LDCONFIG} -r | ${GREP} -qwF -e "-l$$lib"; then \
					${TRUE}; \
				else \
					${ECHO_MSG} "Error: shared library \"$$lib\" does not exist"; \
					${FALSE}; \
				fi; \
			fi; \
		fi; \
	done
.endif
.else
	@${DO_NADA}
.endif

misc-depends:
.if defined(DEPENDS)
.if !defined(NO_DEPENDS)
	@for dir in ${DEPENDS}; do \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		${ECHO_MSG} "===>   ${PKGNAME} depends on: $$dir"; \
		${ECHO_MSG} "===>    Verifying $$target for $$dir"; \
		if [ ! -d $$dir ]; then \
			${ECHO_MSG} "     >> No directory for $$dir.  Skipping.."; \
		else \
			(cd $$dir; ${MAKE} $$target $$depends_args) ; \
		fi \
	done
	@${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"
.endif
.else
	@${DO_NADA}
.endif

.endif

# Dependency lists: both build and runtime, recursive.  Print out directory names.

all-depends-list:
	@${ALL-DEPENDS-LIST}

ALL-DEPENDS-LIST= \
	checked="${PARENT_CHECKED}"; \
	for dir in $$(${ECHO} "${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS} ${RUN_DEPENDS}" | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//') $$(${ECHO} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/:.*//'); do \
		if [ -d $$dir ]; then \
			if (${ECHO} $$checked | ${GREP} -qwv "$$dir"); then \
				child=$$(cd $$dir; ${MAKE} PARENT_CHECKED="$$checked" all-depends-list); \
				for d in $$child; do ${ECHO} $$d; done; \
				${ECHO} $$dir; \
				checked="$$dir $$child $$checked"; \
			fi; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | sort -u

.if !target(clean-depends)
clean-depends:
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} NOCLEANDEPENDS=yes clean); \
	done
.endif

.if !target(deinstall-depends)
deinstall-depends:
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} deinstall); \
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

.if !target(checksum-recursive)
checksum-recursive:
	@${ECHO_MSG} "===> Fetching and checking checksums for ${PKGNAME} and dependencies"
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} checksum); \
	done
.endif

# Dependency lists: build and runtime.  Print out directory names.

build-depends-list:
	@${BUILD-DEPENDS-LIST}

BUILD-DEPENDS-LIST= \
	for dir in $$(${ECHO} "${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS}" | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u) $$(${ECHO} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/:.*//' | sort -u); do \
		if [ -d $$dir ]; then \
			${ECHO} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | sort -u

run-depends-list:
	@${RUN-DEPENDS-LIST}

RUN-DEPENDS-LIST= \
	for dir in $$(${ECHO} "${LIB_DEPENDS} ${RUN_DEPENDS}" | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u) $$(${ECHO} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/:.*//' | sort -u); do \
		if [ -d $$dir ]; then \
			${ECHO} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | sort -u

# Package (recursive runtime) dependency list.  Print out directory names.

package-depends-list:
	@${PACKAGE-DEPENDS-LIST}

PACKAGE-DEPENDS-LIST= \
	checked="${PARENT_CHECKED}"; \
	for dir in $$(${ECHO} "${LIB_DEPENDS} ${RUN_DEPENDS}" | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//') $$(${ECHO} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/:.*//'); do \
		if [ -d $$dir ]; then \
			if (${ECHO} $$checked | ${GREP} -qwv "$$dir"); then \
				child=$$(cd $$dir; ${MAKE} PARENT_CHECKED="$$checked" package-depends-list); \
				for d in $$child; do ${ECHO} $$d; done; \
				${ECHO} $$dir; \
				checked="$$dir $$child $$checked"; \
			fi; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | sort -u

# Print out package names.

package-depends:
	@for dir in $$(${PACKAGE-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} package-name); \
	done

################################################################
# Everything after here are internal targets and really
# shouldn't be touched by anybody but the release engineers.
################################################################

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|port-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|www site

.if !target(describe)
describe:
	@${ECHO} "`perl -e ' \
		print q{${PKGNAME}|${.CURDIR}|${PREFIX}|}; \
		if (open(COMMENT, q{${COMMENT}})) { \
			$$_ = <COMMENT>; \
			chomp; \
			print; \
		} else { \
			print q{** No Description}; \
		} \
		if ( -f q{${DESCR}} ) { \
			print q{|${DESCR}}; \
		} else { \
			print q{|/dev/null}; \
		} \
		print q{|${MAINTAINER}|${CATEGORIES}|}; \
		@bdirs = map((split /:/)[1], split(q{ }, q{${FETCH_DEPENDS} ${BUILD_DEPENDS}})); \
		@rdirs = map((split /:/)[1], split(q{ }, q{${RUN_DEPENDS}})); \
		@mdirs = ( \
			map((split /:/)[0], split(q{ }, q{${DEPENDS}})), \
			map((split /:/)[1], split(q{ }, q{${LIB_DEPENDS}})) \
		); \
		for my $$i (\@bdirs, \@rdirs, \@mdirs) { \
			my @dirs = @$$i; \
			@$$i = (); \
			for (@dirs) { \
				if (-d $$_) { \
					push @$$i, $$_; \
				} else { \
					print STDERR qq{${PKGNAME}: \"$$_\" non-existent -- dependency list incomplete\n}; \
				} \
			} \
		} \
		for (@bdirs, @mdirs) { \
			$$x{$$_} = 1; \
		} \
		print join(q{ }, sort keys %x), q{|}; \
		for (@rdirs, @mdirs) { \
			$$y{$$_} = 1; \
		} \
		print join(q{ }, sort keys %y), q{|}; \
		if (open(DESCR, q{${DESCR}})) { \
			while (<DESCR>) { \
				if (/^WWW:\s+(\S+)/) { \
					print $$1; \
					last; \
				} \
			} \
		} \
		print qq{\n};'`"
.endif

www-site:
.if exists(${DESCR})
	@${GREP} '^WWW:[ 	]' ${DESCR} | ${AWK} '{print $$2}' | ${HEAD} -1
.else
	@${ECHO}
.endif

.if !target(readmes)
readmes:	readme
.endif

.if !target(readme)
readme:
	@rm -f ${.CURDIR}/README.html
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} ${.CURDIR}/README.html
.endif

${.CURDIR}/README.html:
	@${ECHO_MSG} "===>   Creating README.html for ${PKGNAME}"
	@${CAT} ${TEMPLATES}/README.port | \
		${SED} -e 's%%PORT%%'`${ECHO} ${.CURDIR} | ${SED} -e 's.*/\([^/]*/[^/]*\)$$\1'`'g' \
			-e 's%%PKG%%${PKGNAME}g' \
			-e '/%%COMMENT%%/r${COMMENT}' \
			-e '/%%COMMENT%%/d' \
			-e 's%%DESCR%%'"`${ECHO} ${DESCR} | ${SED} -e 's${.CURDIR}/'`"'' \
			-e 's%%BUILD_DEPENDS%%'"`cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} pretty-print-build-depends-list`"'' \
			-e 's%%RUN_DEPENDS%%'"`cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} pretty-print-run-depends-list`"'' \
			-e 's%%TOP%%'"`${ECHO} ${CATEGORIES} | ${SED} -e 'sa .*aa' -e 'sa[^/]*a..ag'`"'/..' \
		>> $@

# The following two targets require an up-to-date INDEX in ${PORTSDIR}

.if !target(pretty-print-build-depends-list)
pretty-print-build-depends-list:
.if defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || \
	defined(LIB_DEPENDS) || defined(DEPENDS)
	@${ECHO} -n 'This port requires package(s) "'
	@${ECHO} -n `${GREP} '^${PKGNAME}|' ${PORTSDIR}/INDEX | awk -F\| '{print $$8;}'`
	@${ECHO} '" to build.'
.endif
.endif

.if !target(pretty-print-run-depends-list)
pretty-print-run-depends-list:
.if defined(RUN_DEPENDS) || defined(LIB_DEPENDS) || defined(DEPENDS)
	@${ECHO} -n 'This port requires package(s) "'
	@${ECHO} -n `${GREP} '^${PKGNAME}|' ${PORTSDIR}/INDEX | awk -F\| '{print $$9;}'`
	@${ECHO} '" to run.'
.endif
.endif

# Generate packing list.  Also tests to make sure all required package
# files exist.

.if !target(generate-plist)
generate-plist:
	@${ECHO_MSG} "===>   Generating temporary packing list"
	@${MKDIR} `dirname ${TMPPLIST}`
	@if [ ! -f ${PLIST} -o ! -f ${COMMENT} -o ! -f ${DESCR} ]; then ${ECHO} "** Missing package files for ${PKGNAME}."; exit 1; fi
	@>${TMPPLIST}
	@for man in ${__MANPAGES}; do \
		${ECHO} $${man} >> ${TMPPLIST}; \
	done
.for _PREFIX in ${PREFIX}
.if ${_TMLINKS:M${_PREFIX}*}x != x
	@for i in ${_TMLINKS:M${_PREFIX}*:S,^${_PREFIX}/,,}; do \
		${ECHO} "$$i" >> ${TMPPLIST}; \
	done
.endif
.if ${_TMLINKS:N${_PREFIX}*}x != x
	@${ECHO} @cwd / >> ${TMPPLIST}
	@for i in ${_TMLINKS:N${_PREFIX}*:S,^/,,}; do \
		${ECHO} "$$i" >> ${TMPPLIST}; \
	done
	@${ECHO} '@cwd ${PREFIX}' >> ${TMPPLIST}
.endif
.if ${XFREE86_HTML_MAN} == "yes"
.for mansect in 1 2 3 4 5 6 7 8 9 L N
.for man in ${MAN${mansect}}
	@echo lib/X11/doc/html/${man}.html >> ${TMPPLIST}
.endfor
.endfor
.endif
.endfor
	@${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${PLIST} >> ${TMPPLIST}
.if !defined(NO_MTREE)
	@${ECHO} "@unexec if [ -f %D/info/dir ]; then if sed -e '1,/Menu:/d' %D/info/dir | grep -q '^[*] '; then true; else rm %D/info/dir; fi; fi" >> ${TMPPLIST}
.endif
.if defined(INSTALLS_SHLIB)
	@${ECHO} "@exec ${LDCONFIG} -m ${LDCONFIG_PLIST}" >> ${TMPPLIST}
	@${ECHO} "@unexec ${LDCONFIG} -R" >> ${TMPPLIST}
.endif
.if !defined(NO_FILTER_SHLIBS)
.if (${PORTOBJFORMAT} == "aout")
	@${SED} -e 's,\(/lib.*\.so\.[0-9]*\)$$,\1.0,' ${TMPPLIST} > ${TMPPLIST}.tmp
.else
	@${SED} -e 's,\(/lib.*\.so\.[0-9]*\)\.[0-9]*$$,\1,' ${TMPPLIST} > ${TMPPLIST}.tmp
.endif
	@${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
.endif
.endif

${TMPPLIST}:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} generate-plist

# Compress (or uncompress) and symlink manpages.
.if !target(compress-man)
compress-man:
.if ${MANCOMPRESSED} == yes && defined(NOMANCOMPRESS)
	@${ECHO_MSG} "===>   Uncompressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GUNZIP_CMD} $${_manpages} ) || ${TRUE}
.elif ${MANCOMPRESSED} == no && !defined(NOMANCOMPRESS)
	@${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GZIP_CMD} $${_manpages} ) || ${TRUE}
.endif
.if defined(_MLINKS)
	@set ${_MLINKS:S,"",,g:S,//,/,g}; \
	while :; do \
		[ $$# -eq 0 ] && break || ${TRUE}; \
		${RM} -f $${2%.gz}; ${RM} -f $$2.gz; \
		${LN} -fs `${ECHO} $$1 $$2 | ${AWK} '{ \
					z=split($$1, a, /\//); x=split($$2, b, /\//); \
					while (a[i] == b[i]) i++; \
					for (q=i; q<x; q++) printf "../"; \
					for (; i<z; i++) printf a[i] "/"; printf a[z]; }'` $$2; \
		shift; shift; \
	done
.endif
.endif

# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed port is recognized correctly in
# accordance to the @pkgdep directive in the packing lists

.if !target(fake-pkg)
fake-pkg:
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
		${CP} ${COMMENT} ${PKG_DBDIR}/${PKGNAME}/+COMMENT; \
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
		fi; \
		for dep in `cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} package-depends ECHO_MSG=${TRUE} | sort -u`; do \
			if [ -d ${PKG_DBDIR}/$$dep -a -z `echo $$dep | ${GREP} -E ${PKG_IGNORE_DEPENDS}` ]; then \
				if ! ${GREP} ^${PKGNAME}$$ ${PKG_DBDIR}/$$dep/+REQUIRED_BY \
					>/dev/null 2>&1; then \
					${ECHO} ${PKGNAME} >> ${PKG_DBDIR}/$$dep/+REQUIRED_BY; \
				fi; \
			fi; \
		done; \
	fi
	@if [ -e /tmp/${PKGNAME}-required-by ]; then \
		${CAT} /tmp/${PKGNAME}-required-by >> ${PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY; \
		${RM} -f /tmp/${PKGNAME}-required-by; \
	fi
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
.for softvar in CKSUMFILES _MLINKS
.if defined(${softvar})
__softMAKEFLAGS+=      '${softvar}+=${${softvar}:S/'/'\''/g}'
.endif
.endfor
# These won't change, so we can pass them through the environment
.MAKEFLAGS: \
	ARCH="${ARCH:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OPSYS="${OPSYS:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSREL="${OSREL:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSVERSION="${OSVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	PORTOBJFORMAT="${PORTOBJFORMAT:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	SYSTEMVERSION="${SYSTEMVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}"
.endif

.endif
# End of post-makefile section.
