#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
# Please view me with 4 column tabs!
# Please make sure all changes to this file are passed either through
# the maintainer, or portmgr

Autotools_Include_MAINTAINER=	ade@FreeBSD.org

# USE_AUTOCONF_VER (PORT MAY SET THIS VALUE)
#				- Implies USE_AUTOCONF.
#				- Implies WANT_AUTOCONF_VER=(value)
# USE_AUTOCONF (PORT MAY SET THIS VALUE)
#				- Implies WANT_AUTOCONF_VER?=213.
#				- Causes autoconf execution prior to configure step.
# USE_AUTOHEADER (PORT MAY SET THIS VALUE)
#				- Implies USE_AUTOCONF.
# WANT_AUTOCONF_VER (PORT MAY SET THIS VALUE)
#				- Implies GNU_CONFIGURE=yes.
#				- Says that the port wants autoconf; legal values
#				  are: 213, 253, 257.
#				- Each specify a version of autoconf to use
#				  and appropriatly set AUTOCONF{,_DIR} and other
#				  autoconf-related program paths.
#				- If set with an unknown value, the port is marked BROKEN.
# AUTOCONF_ARGS (PORT MAY ALTER THIS VALUE)
#				- Pass these args to ${AUTOCONF} if ${USE_AUTOCONF_VER}
#				  is set. If an application sets this value, it should
#				  use the += form of assignment to append, not overwrite.
# AUTOHEADER_ARGS (PORT MAY ALTER THIS VALUE)
#				- Pass these args to ${AUTOHEADER} if ${USE_AUTOHEADER}
#				  is set. If an application sets this value, it should
#				  use the += form of assignment to append, not overwrite.
##
# AUTOMAKE (READ-ONLY)
#				- Set to path of GNU automake (default:
#				  according to USE_AUTOMAKE_VER value)
# AUTOMAKE_ENV (READ-ONLY)
#				- Pass these env var=value pairs (shell-like)
#				  to ${AUTOMAKE} if ${USE_AUTOMAKE_VER} is set.
# ACLOCAL (READ-ONLY)
#				- Set to path of GNU automake aclocal (default:
#				  according to USE_AUTOMAKE_VER value)
# ACLOCAL_DIR (READ-ONLY)
#				- Set to path of GNU automake aclocal shared directory
#                 (default:	according to USE_AUTOMAKE_VER value)
# AUTOMAKE_DIR (READ-ONLY)
#				- Set to path of GNU automake shared directory (default:
#				  according to USE_AUTOMAKE_VER value)
##
# AUTOCONF (READ-ONLY)
#				- Set to path of GNU autoconf (default:
#				  according to USE_AUTOCONF_VER value)
# AUTOCONF_ENV (READ-ONLY)
#				- Pass these env var=value pairs (shell-like)
#				  to ${AUTOCONF} if ${USE_AUTOCONF_VER} is set.
# AUTOHEADER (READ-ONLY)
#				- Set to path of GNU autoconf autoheader
#				  (default: according to USE_AUTOCONF_VER value)
# AUTORECONF (READ-ONLY)
#				- Set to path of GNU autoconf autoreconf
#				  (default: according to USE_AUTOCONF_VER value)
# AUTOSCAN (READ-ONLY)
#				- Set to path of GNU autoconf autoscan
#				  (default: according to USE_AUTOCONF_VER value)
# AUTOIFNAMES (READ-ONLY)
#				- Set to path of GNU autoconf autoifnames
#				  (default: according to USE_AUTOCONF_VER value)
# AUTOCONF_DIR (READ-ONLY)
#				- Set to path of GNU autoconf shared directory (default:
#				  according to USE_AUTOCONF_VER value)
##
# USE_LIBTOOL_VER (PORT MAY SET THIS VALUE)
#				- Implies USE_LIBTOOL.
#				- Implies WANT_LIBTOOL_VER=(value)
# USE_LIBTOOL (PORT MAY SET THIS VALUE)
#				- Says that the port uses Libtool.
#				- Implies GNU_CONFIGURE.
#				- Implies WANT_LIBTOOL_VER?=13
# LIBTOOL (READ-ONLY)
#				- Set to path of libtool (default:
#				  according to USE_LIBTOOL_VER value)
# LIBTOOLIZE (READ-ONLY)
#				- Set to path of libtoolize (default:
#				  according to USE_LIBTOOL_VER value)
# LIBTOOL_VERSION (READ-ONLY)
#				- Exported version of USE_LIBTOOL_VER
# LIBTOOL_SHAREDIR (READ-ONLY)
#				- Set to path of GNU libtool shared directory (default:
#				  according to USE_LIBTOOL_VER value)
# LIBTOOL_LIBEXECDIR (READ-ONLY)
#				- Set to path of GNU libtool libexec directory (default:
#				  according to USE_LIBTOOL_VER value)
# LIBTOOLFILES	- Files to patch for libtool (defaults: "aclocal.m4" if
#				  USE_AUTOCONF is set, "configure" otherwise).
# LIBTOOLFLAGS	- Additional flags to pass to ltconfig
#				  (default: --disable-ltlibs)

######################################################################
# AUTOMAKE/AUTOCONF
# current => non-renamed, non-relocated version

########## private variables
#	old_{am,ac}ver		==>	numeric version of "old" port[*]
#	cur_{am,ac}ver		==>	numeric version of "current" port
#	dev_{am,ac}ver		==>	numeric version of "devel" port
#	use_{am,ac}path		==> numeric version we are using here
#	{am,ac}path			==> path to non-suffixed binary, if any
#	autotools_path		==> string to prepend to PATH, if any
#
# [*] "default" version in case of USE_AUTOMAKE or USE_AUTOCONF w/o version

##########
#.if defined(AUTOMAKE) || defined(AUTOCONF)
#BROKEN="AUTOMAKE and AUTOCONF are read-only values. \
#	You may not assign to them"
#.endif # defined(AUTOMAKE) || defined(AUTOCONF)

########## versions
old_amver=	14
cur_amver=	15
dev_amver=	17
old_acver=	213
cur_acver=	253
dev_acver=	257

########## automake setup
.if defined(USE_AUTOMAKE_VER)
USE_AUTOMAKE?=		yes
WANT_AUTOMAKE_VER?=	${USE_AUTOMAKE_VER}
.endif # defined(USE_AUTOMAKE_VER)
.if defined(USE_AUTOMAKE)
USE_AUTOCONF?=		yes
WANT_AUTOMAKE_VER?=	${old_amver}
.endif # defined(USE_AUTOMAKE)
.if defined(WANT_AUTOMAKE_VER)
GNU_CONFIGURE?=		yes
use_amver=			${WANT_AUTOMAKE_VER:L}
.if ${use_amver} == ${cur_amver}
ACLOCAL_DIR=		${LOCALBASE}/share/aclocal
AUTOMAKE_DIR=		${LOCALBASE}/share/automake
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake
WANT_AUTOCONF_VER?=	${cur_acver}
.elif ${use_amver} == ${old_amver} || ${use_amver} == ${dev_amver}
ACLOCAL_DIR=	${LOCALBASE}/share/aclocal${use_amver}
AUTOMAKE_DIR=	${LOCALBASE}/share/automake${use_amver}
.if ${use_amver} == ${old_amver}
ampath=			${LOCALBASE}/libexec/automake${use_amver}:
BUILD_DEPENDS+=	${ampath:S/://}/automake:${PORTSDIR}/devel/automake${use_amver}
AUTOMAKE_ARGS+=	-i
WANT_AUTOCONF_VER?=${old_acver}
.else
BUILD_DEPENDS+=         ${LOCALBASE}/bin/automake${dev_amver}:${PORTSDIR}/devel/automake${dev_amver}
WANT_AUTOCONF_VER?=${dev_acver}
.endif # ${use_amver} == ${old_amver}
.else # bad automake version
BROKEN="unknown AUTOMAKE version: ${use_amver}"
.endif # ${use_amver} == ${cur_amver}
.endif # defined(WANT_AUTOMAKE_VER)

########## autoconf setup
.if defined(USE_AUTOCONF_VER)
USE_AUTOCONF?=		yes
WANT_AUTOCONF_VER?=	${USE_AUTOCONF_VER}
.endif # defined(USE_AUTOCONF_VER)
.if defined(USE_AUTOHEADER)
USE_AUTOCONF?=		yes
.endif # defined(USE_AUTOHEADER)
.if defined(USE_AUTOCONF)
WANT_AUTOCONF_VER?=	${old_acver}
.endif # defined(USE_AUTOCONF)
.if defined(WANT_AUTOCONF_VER)
GNU_CONFIGURE?=		yes
use_acver=			${WANT_AUTOCONF_VER:L}
.if ${use_acver} == ${cur_acver}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf
.elif ${use_acver} == ${old_acver}
AUTOCONF_DIR=	${LOCALBASE}/share/autoconf${use_acver}
acpath=			${LOCALBASE}/libexec/autoconf${use_acver}
BUILD_DEPENDS+=	${acpath}/autoconf:${PORTSDIR}/devel/autoconf${use_acver}
.elif ${use_acver} == ${dev_acver}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf${dev_acver}
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf${dev_acver}:${PORTSDIR}/devel/autoconf${dev_acver}
.else # bad autoconf version
BROKEN="unknown AUTOCONF version: ${use_acver}"
.endif # ${use_acver} == ${cur_acver}
.endif # defined(WANT_AUTOCONF_VER)

########## set up paths to tools
.if defined(ampath)
autotools_path=${ampath}${acpath}
.elif defined(acpath)
autotools_path=${acpath}
.endif # defined(ampath)

########## prefix to path, add to env vars
.if defined(autotools_path)
MAKE_ENV+=	PATH=${autotools_path}:${PATH}
CONFIGURE_ENV+=	PATH=${autotools_path}:${PATH}
SCRIPTS_ENV+=	PATH=${autotools_path}:${PATH}
AUTOCONF_ENV+=	PATH=${autotools_path}:${PATH}
AUTOMAKE_ENV+=	PATH=${autotools_path}:${PATH}
AUTOHEADER_ENV+=	PATH=${autotools_path}:${PATH}
AUTOTOOLS_ENV+=	PATH=${autotools_path}:${PATH}
.endif # defined(autotools_path)

########## set up automake "names"
.if defined(use_amver)
.if !defined(ampath)
.if ${use_amver} == ${cur_amver}
ACLOCAL?=	aclocal
AUTOMAKE?=	automake
.else
ACLOCAL?=	aclocal${dev_amver}
AUTOMAKE?=	automake${dev_amver}
.endif
.else # defined(ampath)
ACLOCAL?=	${ampath:S/://}/aclocal
AUTOMAKE?=	${ampath:S/://}/automake
.endif # !defined(ampath)
.endif # defined(use_amver)

########## set up autoconf "names"
.if defined(use_acver)
.if !defined(acpath)
.if ${use_acver} == ${cur_acver}
AUTOCONF?=		autoconf
AUTOHEADER?=	autoheader
AUTOIFNAMES?=	ifnames
AUTORECONF?=	autoreconf
AUTOSCAN?=		autoscan
AUTOUPDATE?=	autoupdate
.else
AUTOCONF?=		autoconf${dev_acver}
AUTOHEADER?=	autoheader${dev_acver}
AUTOIFNAMES?=	ifnames${dev_acver}
AUTORECONF?=	autoreconf${dev_acver}
AUTOSCAN?=		autoscan${dev_acver}
AUTOUPDATE?=	autoupdate${dev_acver}
.endif
.else # defined(acpath)
AUTOCONF?=		${acpath}/autoconf
AUTOHEADER?=	${acpath}/autoheader
AUTOIFNAMES?=	${acpath}/ifnames
AUTORECONF?=	${acpath}/autoreconf
AUTOSCAN?=		${acpath}/autoscan
AUTOUPDATE?=	${acpath}/autoupdate
.endif # !defined(acpath)
.endif # defined(use_acver)

########## stupid port error checking
# Set all unset vars for the programs to ${FALSE}. This way
# we can catch a certain class of port Makefile errors quickly.
ACLOCAL?=	${FALSE}
AUTOMAKE?=	${FALSE}
AUTOCONF?=	${FALSE}
AUTOHEADER?=${FALSE}
AUTOIFNAMES?=${FALSE}
AUTORECONF?=${FALSE}
AUTOSCAN?=	${FALSE}
AUTOUPDATE?=${FALSE}
ACLOCAL_DIR?=${NONEXISTENT}
AUTOMAKE_DIR?=${NONEXISTENT}
AUTOCONF_DIR?=${NONEXISTENT}

# END AUTOMAKE/AUTOCONF
######################################################################

######################################################################
# LIBTOOL

.if defined(USE_LIBTOOL_VER)
USE_LIBTOOL?=		yes
WANT_LIBTOOL_VER?=	${USE_LIBTOOL_VER}
.endif

.if defined(USE_LIBTOOL)
GNU_CONFIGURE=	yes
WANT_LIBTOOL_VER?=	13
.endif

.if defined(WANT_LIBTOOL_VER)
LIBTOOL_VERSION=	${WANT_LIBTOOL_VER:L}

.if exists(${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}/Makefile)
LIBTOOL_SHAREDIR=	${LOCALBASE}/share/libtool${LIBTOOL_VERSION}
LIBTOOL_LIBEXECDIR=	${LOCALBASE}/libexec/libtool${LIBTOOL_VERSION}
BUILD_DEPENDS+=		${LIBTOOL_LIBEXECDIR}/libtool:${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}
.else
BROKEN="unknown LIBTOOL version: ${USE_LIBTOOL_VER}"
.endif

.if defined(USE_AUTOCONF)
LIBTOOLFILES?=		aclocal.m4
.else
LIBTOOLFILES?=		configure
.endif

LIBTOOLFLAGS?=		--disable-ltlibs
.endif

########## prefix to path, add to env vars
.if defined(LIBTOOL_LIBEXECDIR)
MAKE_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
CONFIGURE_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
SCRIPTS_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
AUTOCONF_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
AUTOMAKE_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
AUTOTOOLS_ENV+=	PATH=${LIBTOOL_LIBEXECDIR}:${PATH}
.endif # defined(ltpath)

LIBTOOL?=	${LIBTOOL_LIBEXECDIR}/libtool
LIBTOOLIZE?=	${LIBTOOL_LIBEXECDIR}/libtoolize

# END LIBTOOL
######################################################################

.if !target(run-autotools)
run-autotools:
.if defined(USE_AUTOMAKE)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
.endif
.if defined(USE_AUTOCONF)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
.endif
.if defined(USE_AUTOHEADER)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOHEADER_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
.endif
.endif

# patch-autools
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

.if !target(patch-autotools)
patch-autotools:
.if defined(USE_LIBTOOL)
	 @(cd ${PATCH_WRKSRC}; \
	 for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "s^\$$ac_aux_dir/ltconfig^${LIBTOOL_SHAREDIR}/ltconfig${LIBTOOL_VERSION}^g" \
			-e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LIBTOOL_SHAREDIR}/ltmain.sh^g" \
			$$file.tmp > $$file; \
	 done);
.else
	@${DO_NADA}
.endif
.endif
