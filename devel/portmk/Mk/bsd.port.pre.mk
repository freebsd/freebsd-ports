#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

PORTMK_VERSION=	20050202

.if defined(_PREMKINCLUDED)
check-makefile::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: you cannot include bsd.port[.pre].mk twice"
	@${FALSE}
.endif

_PREMKINCLUDED=	yes

.if defined(MAKE_VERSION)
.if ${MAKE_VERSION} >= 5200408030 || ${MAKE_VERSION} >= 4200408030 && ${MAKE_VERSION} < 5000000000
NOPRECIOUSSOFTMAKEVARS= yes
.endif
.endif

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
BRANDELF?=	/usr/bin/brandelf
.if exists(/usr/bin/bzip2)
BZCAT?=		/usr/bin/bzcat
BZIP2_CMD?=	/usr/bin/bzip2
.else
BZCAT?=		${LOCALBASE}/bin/bzcat
BZIP2_CMD?=	${LOCALBASE}/bin/bzip2
BZIP2DEPENDS=	yes
.endif
CAT?=		/bin/cat
CHGRP?=		/usr/bin/chgrp
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHROOT?=	/usr/sbin/chroot
COMM?=		/usr/bin/comm
CP?=		/bin/cp
CPIO?=		/usr/bin/cpio
CUT?=		/usr/bin/cut
DATE?=		/bin/date
DC?=		/usr/bin/dc
DIALOG?=	/usr/bin/dialog
DIRNAME?=	/usr/bin/dirname
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FILE?=		/usr/bin/file
FIND?=		/usr/bin/find
FMT?=		/usr/bin/fmt
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
MKTEMP?=	/usr/bin/mktemp
MV?=		/bin/mv
OBJCOPY?=	/usr/bin/objcopy
OBJDUMP?=	/usr/bin/objdump
PASTE?=		/usr/bin/paste
PAX?=		/bin/pax
PRINTF?=	/usr/bin/printf
REALPATH?=	/bin/realpath
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SORT?=		/usr/bin/sort
STRIP_CMD?=	/usr/bin/strip
SU_CMD?=	/usr/bin/su root -c
TAIL?=		/usr/bin/tail
TEST?=		test				# Shell builtin
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
UNAME?=		/usr/bin/uname
.if exists(/usr/bin/unzip)
UNZIP_CMD?=	/usr/bin/unzip
.else
UNZIP_CMD?=	${LOCALBASE}/bin/unzip
ZIPDEPENDS=	yes
.endif
WHICH?=		/usr/bin/which
XARGS?=		/usr/bin/xargs
YACC?=		/usr/bin/yacc

# ECHO is defined in /usr/share/mk/sys.mk, which can either be "echo",
# or "true" if the make flag -s is given.  Use ECHO_CMD where you mean
# the echo command.
ECHO_CMD?=	echo				# Shell builtin

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO_CMD}

# Get the default maintainer
MAINTAINER?=	ports@FreeBSD.org

# Get the architecture
.if !defined(ARCH)
ARCH!=	${UNAME} -p
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
PORTOBJFORMAT!=		${TEST} -x /usr/bin/objformat && /usr/bin/objformat || ${ECHO_CMD} aout
.endif

MASTERDIR?=	${.CURDIR}

PORTMK_CONF?=	/etc/portmk.conf

.if exists(${PORTMK_CONF})
.include "${PORTMK_CONF}"
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

# where 'make config' records user configuration options
PORT_DBDIR?=	/var/db/ports

.if defined(LATEST_LINK)
UNIQUENAME?=	${LATEST_LINK}
.else
UNIQUENAME?=	${PKGNAMEPREFIX}${PORTNAME}
.endif
OPTIONSFILE?=	${PORT_DBDIR}/${UNIQUENAME}/options
_OPTIONSFILE!=	${ECHO_CMD} "${OPTIONSFILE}"
.if defined(OPTIONS) && !defined(_OPTIONSNG_READ)
.if exists(${_OPTIONSFILE}) && !make(rmconfig)
.include "${_OPTIONSFILE}"
.endif
.if exists(${_OPTIONSFILE}.local)
.include "${_OPTIONSFILE}.local"
.endif
.endif

# check for old, crufty, makefile types, part 1:
.if !defined(PORTNAME) || !( defined(PORTVERSION) || defined (DISTVERSION) ) || defined(PKGNAME)
check-makefile::
	@${ECHO_CMD} "Makefile error: you need to define PORTNAME and PORTVERSION instead of PKGNAME."
	@${ECHO_CMD} "(This port is too old for your bsd.port.mk, please update it to match"
	@${ECHO_CMD} " your bsd.port.mk.)"
	@${FALSE}
.endif

.if defined(PORTVERSION)
.if ${PORTVERSION:M*[-_,]*}x != x
BROKEN=			"PORTVERSION ${PORTVERSION} may not contain '-' '_' or ','"
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

# check for old, crufty, makefile types, part 2.  The "else" case
# should have been handled in part 1, above.
.if !defined(PKGNAME)
PKGNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:C/[-_,]/./g}${_SUF1}${_SUF2}
.endif
DISTNAME?=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

# These need to be absolute since we don't know how deep in the ports
# tree we are and thus can't go relative.  They can, of course, be overridden
# by individual Makefiles or local system make configuration.
PORTSDIR?=		/usr/ports
LOCALBASE?=		/usr/local
X11BASE?=		/usr/X11R6
LINUXBASE?=		/compat/linux
DISTDIR?=		${PORTSDIR}/distfiles
_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
.if ${OSVERSION} >= 600000
INDEXFILE?=		INDEX-6
.elif ${OSVERSION} >= 500036
INDEXFILE?=		INDEX-5
.else
INDEXFILE?=		INDEX
.endif
.if defined(USE_BZIP2)
EXTRACT_SUFX?=			.tar.bz2
.elif defined(USE_ZIP)
EXTRACT_SUFX?=			.zip
.else
EXTRACT_SUFX?=			.tar.gz
.endif
PACKAGES?=		${PORTSDIR}/packages
TEMPLATES?=		${PORTSDIR}/Templates

.if (!defined(PKGDIR) && exists(${MASTERDIR}/pkg/DESCR)) || \
	(!defined(MD5_FILE) && exists(${MASTERDIR}/files/md5))
check-makefile::
	@${ECHO_CMD} "Makefile error: your port uses an old layout.  Please update it to match this bsd.port.mk.  If you have updated your ports collection via cvsup and are still getting this error, see Q12 and Q13 in the cvsup FAQ on http://www.polstra.com for further information."
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
.if defined(USE_X_PREFIX)
PREFIX?=		${X11BASE}
.elif defined(USE_LINUX_PREFIX)
PREFIX?=		${LINUXBASE}
NO_MTREE=		yes
.else
PREFIX?=		${LOCALBASE}
.endif

PKGCOMPATDIR?=		${LOCALBASE}/lib/compat/pkg

.if defined(WITH_APACHE2)
APACHE_PORT?=	www/apache2
.else
APACHE_PORT?=	www/apache13
.endif
APXS?=		${LOCALBASE}/sbin/apxs
.if defined(USE_APACHE)
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
.endif

.if ${OSVERSION} >= 500036
PERL_VERSION?=	5.8.6
PERL_VER?=	5.8.6
.else
.if ${OSVERSION} >= 500032
PERL_VERSION?=	5.6.1
PERL_VER?=		5.6.1
.else
.if ${OSVERSION} >= 500007
PERL_VERSION?=	5.6.0
PERL_VER?=		5.6.0
.else
.if ${OSVERSION} >= 300000
PERL_VERSION?=	5.00503
.else
PERL_VERSION?=	5.00502
.endif
PERL_VER?=		5.005
.endif
.endif
.endif

.if !defined(PERL_LEVEL) && defined(PERL_VERSION)
perl_major=		${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=	00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=		${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=		${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=		${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=	0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=		${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=	${perl_major}${perl_minor}${perl_patch}
.else
PERL_LEVEL=0
.endif # !defined(PERL_LEVEL) && defined(PERL_VERSION)

.if ${PERL_LEVEL} >= 500600
PERL_ARCH?=		mach
.else
PERL_ARCH?=		${ARCH}-freebsd
.endif

.if ${PERL_LEVEL} >= 500800
PERL_PORT?=	perl5.8
.else
PERL_PORT?=	perl5
.endif

SITE_PERL_REL?=	lib/perl5/site_perl/${PERL_VER}
SITE_PERL?=	${LOCALBASE}/${SITE_PERL_REL}

.if ${PERL_LEVEL} < 500600
PERL5=		/usr/bin/perl${PERL_VERSION}
PERL=		/usr/bin/perl
.else
PERL5=		${LOCALBASE}/bin/perl${PERL_VERSION}
PERL=		${LOCALBASE}/bin/perl
.endif

# XXX: (not yet): .if defined(USE_AUTOTOOLS)
# .include "${PORTSDIR}/Mk/bsd.autotools.mk"
# XXX: (not yet): .endif

.if defined(USE_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if defined(EMACS_PORT_NAME)
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
.endif

.if defined(USE_GNUSTEP)
.include "${PORTSDIR}/Mk/bsd.gnustep.mk"
.endif

.if defined(USE_PHP)
.include "${PORTSDIR}/Mk/bsd.php.mk"
.endif

.if defined(USE_PYTHON)
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(USE_JAVA)
.include "${PORTSDIR}/Mk/bsd.java.mk"
.endif

.if defined(USE_RUBY) || defined(USE_LIBRUBY)
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.endif

.if defined(USE_QT_VER) || defined(USE_KDELIBS_VER) || defined(USE_KDEBASE_VER)
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.endif

.if defined(WANT_GNOME) || defined(USE_GNOME) || defined(USE_GTK)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.endif

.if defined(USE_SDL) || defined(WANT_SDL)
.include "${PORTSDIR}/Mk/bsd.sdl.mk"
.endif

.if ${OSVERSION} >= 502123
X_WINDOW_SYSTEM ?= xorg
.elif (${OSVERSION} >= 450005 && !defined(XFREE86_VERSION)) || \
	(defined(XFREE86_VERSION) && ${XFREE86_VERSION} == 4)
X_WINDOW_SYSTEM ?= xfree86-4
.else
X_WINDOW_SYSTEM ?= xfree86-3
.endif

# Location of mounted CDROM(s) to search for files
CD_MOUNTPTS?=	/cdrom ${CD_MOUNTPT}

WANT_OPENLDAP_VER?=	22

# Owner and group of the WWW user
WWWOWN?=	www
WWWGRP?=	www
