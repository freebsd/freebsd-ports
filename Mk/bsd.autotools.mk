#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Please view me with 4 column tabs!
#
# Please make sure all changes to this file are passed either through
# the maintainer, or portmgr@FreeBSD.org

Autotools_Include_MAINTAINER=	ade@FreeBSD.org

#---------------------------------------------------------------------------
# IMPORTANT!  READ ME!  YES, THAT MEANS YOU!
#
# The "versioned" autotools referenced here are for BUILDING other ports
# only.  THIS CANNOT BE STRESSED HIGHLY ENOUGH.  Things WILL BREAK if you
# try to use them for anything other than ports/ work.  This particularly
# includes use as a run-time dependency.
#
# If you need unmodified versions of autotools, such as for use in an
# IDE, then you MUST use the devel/gnu-* equivalents, and NOT these.
# See devel/anjuta and devel/kdevelop for examples.
#
# You have been WARNED!
#---------------------------------------------------------------------------

#---------------------------------------------------------------------------
# Compatibility shims for the old method of using autotools.  These are
# slated for removal on January 1st 2006
#---------------------------------------------------------------------------

USE_AUTOTOOLS_COMPAT=

.if defined(USE_AUTOMAKE_VER)
USE_AUTOTOOLS_COMPAT+=	automake:${USE_AUTOMAKE_VER}
.endif

.if defined(WANT_AUTOMAKE_VER)
USE_AUTOTOOLS_COMPAT+=	automake:${WANT_AUTOMAKE_VER}:env
.endif

.if defined(USE_ACLOCAL_VER)
USE_AUTOTOOLS_COMPAT+=	aclocal:${USE_ACLOCAL_VER}
.endif

.if defined(USE_AUTOHEADER_VER)
USE_AUTOTOOLS_COMPAT+=	autoheader:${USE_AUTOHEADER_VER}
.endif

.if defined(USE_AUTOCONF_VER)
USE_AUTOTOOLS_COMPAT+=	autoconf:${USE_AUTOCONF_VER}
.endif

.if defined(WANT_AUTOCONF_VER)
USE_AUTOTOOLS_COMPAT+=	autoconf:${WANT_AUTOCONF_VER}:env
.endif

.if defined(USE_LIBLTDL)
USE_AUTOTOOLS_COMPAT+=	libltdl:15
.endif

.if defined(USE_LIBTOOL_VER)
USE_AUTOTOOLS_COMPAT+=	libtool:${USE_LIBTOOL_VER}
.endif

.if defined(USE_INC_LIBTOOL_VER)
USE_AUTOTOOLS_COMPAT+=	libtool:${USE_INC_LIBTOOL_VER}:inc
.endif

.if defined(WANT_LIBTOOL_VER)
USE_AUTOTOOLS_COMPAT+=	libtool:${WANT_LIBTOOL_VER}:env
.endif

# Ensure that we're not mixing and matching old and new systems
#
.if ${USE_AUTOTOOLS_COMPAT}!=""
. if defined(USE_AUTOTOOLS)
BROKEN+=	"Mix and match of old and new autotools system prohibited"
. else
USE_AUTOTOOLS=	${USE_AUTOTOOLS_COMPAT}
. endif
.endif

#---------------------------------------------------------------------------
# Entry point into the autotools system
#---------------------------------------------------------------------------
#
# USE_AUTOTOOLS= tool:version[:inc | :env]  ...
#
# 'tool' can currently be one of:
#	libtool, libltdl, autoconf, autoheader, automake, aclocal
#
# 'version' is tool dependent
#
# ':inc' is for libtool only, and is used to modify the patch-autotools
#	target to use the relevant included version of libtool
#
# ':env' is for autoconf/autoheader/automake/aclocal and is used to
#	specify that the environment variables are needed, but the relevant
#	tool should NOT be run as part of the run-autotools target
#
# XXX: there is currently no sanity checking of the supplied variables
#	other than to detect actually available versions.  This should
#	probably be fixed at some point.
#
# In addition, the following variables can be set in the port Makefile
# to be passed to the relevant tools:
#
# AUTOMAKE_ARGS=...
#	- Extra arguments passed to automake during configure step
#
# ACLOCAL_ARGS=...
#   - Arguments passed to aclocal during configure step
#
# AUTOCONF_ARGS=...
#	- Extra arguments passed to autoconf during configure step
#
# AUTOHEADER_ARGS=...
#	- Extra arguments passed to autoheader during configure step
#
# LIBTOOLFLAGS=<value>
#	- Arguments passed to libtool during configure step
#	  Currently defaults to "--disable-ltlibs", but this will be going
#	  away when libtool .la files are brought back
#
# LIBTOOLFILES=<list-of-files>
#	- A list of files to patch during libtool pre-configuration
#	  Defaults to "aclocal.m4" if autoconf is in use, otherwise "configure"
#
#---------------------------------------------------------------------------

# XXX: here be dragons :)
#
.for item in ${USE_AUTOTOOLS}
AUTOTOOL_${item:C/^([^:]+).*/\1/}${item:M*\:*\:*:C/^[^:]+:[^:]+:([^:]+)/_\1/}= ${item:C/^[^:]+:([^:]+).*/\1/}
.endfor

#---------------------------------------------------------------------------
# AUTOMAKE/ACLOCAL
#---------------------------------------------------------------------------

.if defined(AUTOTOOL_automake)
AUTOTOOL_automake_env=	${AUTOTOOL_automake}
GNU_CONFIGURE?=			yes
.endif

.if defined(AUTOTOOL_aclocal)
AUTOTOOL_automake_env=	${AUTOTOOL_aclocal}
GNU_CONFIGURE?=			yes
.endif

.if defined(AUTOTOOL_automake_env)
AUTOMAKE_VERSION=	${AUTOTOOL_automake_env}

# Make sure we specified a legal version of automake
#
. if !exists(${PORTSDIR}/devel/automake${AUTOMAKE_VERSION}/Makefile)
BROKEN+=	"Unknown AUTOMAKE version: ${AUTOMAKE_VERSION}"
. endif

# Set up the automake environment
#
AUTOMAKE=			${LOCALBASE}/bin/automake${AUTOMAKE_VERSION}
AUTOMAKE_DIR=		${LOCALBASE}/share/automake${AUTOMAKE_VERSION}
ACLOCAL=			${LOCALBASE}/bin/aclocal${AUTOMAKE_VERSION}
ACLOCAL_DIR=		${LOCALBASE}/share/aclocal${AUTOMAKE_VERSION}
AUTOMAKE_PATH=		${LOCALBASE}/libexec/automake${AUTOMAKE_VERSION}:
AUTOMAKE_VARS=		ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE}

AUTOMAKE_DEPENDS=	${AUTOMAKE}:${PORTSDIR}/devel/automake${AUTOMAKE_VERSION}
BUILD_DEPENDS+=		${AUTOMAKE_DEPENDS}

# XXX: backwards compatibility shim
#
. if ${AUTOMAKE_VERSION} == 14
AUTOMAKE_ARGS+=		-i
. endif

. if defined(AUTOTOOL_aclocal)
ACLOCAL_ARGS?=		--acdir=${ACLOCAL_DIR}
. endif

.endif

#---------------------------------------------------------------------------
# AUTOCONF/AUTOHEADER
#---------------------------------------------------------------------------

.if defined(AUTOTOOL_autoheader)
AUTOTOOL_autoconf=	${AUTOTOOL_autoheader}
.endif

.if defined(AUTOTOOL_autoconf)
AUTOTOOL_autoconf_env=	${AUTOTOOL_autoconf}
GNU_CONFIGURE?=			yes
.endif

.if defined(AUTOTOOL_autoconf_env)
AUTOCONF_VERSION=	${AUTOTOOL_autoconf_env}

# Make sure we specified a legal version of autoconf
#
. if !exists(${PORTSDIR}/devel/autoconf${AUTOCONF_VERSION}/Makefile)
BROKEN+=	"Unknown AUTOCONF version: ${AUTOCONF_VERSION}"
. endif

# Set up the autoconf/autoheader environment
#
AUTOCONF=			${LOCALBASE}/bin/autoconf${AUTOCONF_VERSION}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf${AUTOCONF_VERSION}
AUTOHEADER=			${LOCALBASE}/bin/autoheader${AUTOCONF_VERSION}
AUTOIFNAMES=		${LOCALBASE}/bin/ifnames${AUTOCONF_VERSION}
AUTOM4TE=			${LOCALBASE}/bin/autom4te${AUTOCONF_VERSION}
AUTORECONF=			${LOCALBASE}/bin/autoreconf${AUTOCONF_VERSION}
AUTOSCAN=			${LOCALBASE}/bin/autoscan${AUTOCONF_VERSION}
AUTOUPDATE=			${LOCALBASE}/bin/autoupdate${AUTOCONF_VERSION}
AUTOCONF_PATH=		${LOCALBASE}/libexec/autoconf${AUTOCONF_VERSION}:
AUTOCONF_VARS=		AUTOCONF=${AUTOCONF} AUTOHEADER=${AUTOHEADER} AUTOIFNAMES=${AUTOIFNAMES} AUTOM4TE=${AUTOM4TE} AUTORECONF=${AUTORECONF} AUTOSCAN=${AUTOSCAN} AUTOUPDATE=${AUTOUPDATE}

AUTOCONF_DEPENDS=	${AUTOCONF}:${PORTSDIR}/devel/autoconf${AUTOCONF_VERSION}
BUILD_DEPENDS+=		${AUTOCONF_DEPENDS}

.endif

#---------------------------------------------------------------------------
# LIBTOOL/LIBLTDL
#---------------------------------------------------------------------------

# Convenience function to save people having to depend directly on
# devel/libltdl15
#
.if defined(AUTOTOOL_libltdl)
LIB_DEPENDS+=	ltdl.4:${PORTSDIR}/devel/libltdl15
.endif

.if defined(AUTOTOOL_libtool)
GNU_CONFIGURE?=			YES
AUTOTOOL_libtool_env=	${AUTOTOOL_libtool}
.endif

.if defined(AUTOTOOL_libtool_inc)
GNU_CONFIGURE?=			YES
AUTOTOOL_libtool_env=	${AUTOTOOL_libtool_inc}
.endif

.if defined(AUTOTOOL_libtool_env)
LIBTOOL_VERSION=		${AUTOTOOL_libtool_env}

# Make sure we specified a legal version of libtool
#
. if !exists(${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}/Makefile)
BROKEN+=	"Unknown LIBTOOL version: ${LIBTOOL_VERSION}"
. endif

# Set up the libtool environment
#
LIBTOOL=			${LOCALBASE}/bin/libtool${LIBTOOL_VERSION}
LIBTOOLIZE=			${LOCALBASE}/bin/libtoolize${LIBTOOL_VERSION}
LIBTOOL_LIBEXECDIR=	${LOCALBASE}/libexec/libtool${LIBTOOL_VERSION}
LIBTOOL_SHAREDIR=	${LOCALBASE}/share/libtool${LIBTOOL_VERSION}
LIBTOOL_M4=			${LOCALBASE}/share/aclocal/libtool${LIBTOOL_VERSION}.m4
LTMAIN=				${LIBTOOL_SHAREDIR}/ltmain.sh
. if ${LIBTOOL_VERSION} == 13
LTCONFIG=			${LIBTOOL_SHAREDIR}/ltconfig${LIBTOOL_VERSION}
. else
LTCONFIG=			${TRUE}
. endif
LIBTOOL_PATH=		${LIBTOOL_LIBEXECDIR}:
LIBTOOL_VARS=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} LIBTOOL_M4=${LIBTOOL_M4} LTCONFIG=${LTCONFIG}

LIBTOOL_DEPENDS=	${LIBTOOL}:${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}
BUILD_DEPENDS+=		${LIBTOOL_DEPENDS}

# XXX: do we really need this?
#
LIBTOOLFLAGS?=		--disable-ltlibs

. if defined(AUTOTOOL_autoconf)
LIBTOOLFILES?=		aclocal.m4
. else
LIBTOOLFILES?=		configure
. endif

.endif

#---------------------------------------------------------------------------
# Environmental handling
# Now that we've got our environments defined for autotools, add them
# in so that the rest of the world can handle them
#
AUTOTOOLS_PATH=	${AUTOMAKE_PATH}${AUTOCONF_PATH}${LIBTOOL_PATH}
AUTOTOOLS_VARS=	${AUTOMAKE_VARS} ${AUTOCONF_VARS} ${LIBTOOL_VARS}

.if defined(AUTOTOOLS_PATH) && (${AUTOTOOLS_PATH} != "")
AUTOTOOLS_ENV+=	PATH=${AUTOTOOLS_PATH}${PATH}
CONFIGURE_ENV+=	PATH=${AUTOTOOLS_PATH}${PATH}
MAKE_ENV+=		PATH=${AUTOTOOLS_PATH}${PATH}
SCRIPTS_ENV+=	PATH=${AUTOTOOLS_PATH}${PATH}
. for item in automake aclocal autoconf autoheader libtool
.  if defined(AUTOTOOL_${item}_env)
${item:U}_ENV+=	PATH=${AUTOTOOLS_PATH}${PATH}
.  endif
. endfor
.endif

.if defined(AUTOTOOLS_VARS) && (${AUTOTOOLS_VARS} != "")
AUTOTOOLS_ENV+=	${AUTOTOOLS_VARS}
CONFIGURE_ENV+=	${AUTOTOOLS_VARS}
MAKE_ENV+=		${AUTOTOOLS_VARS}
SCRIPTS_ENV+=	${AUTOTOOLS_VARS}
. for item in automake aclocal autoconf autoheader libtool
.  if defined(AUTOTOOL_${item}_env)
${item:U}_ENV+=	${AUTOTOOLS_VARS}
.  endif
. endfor
.endif

#---------------------------------------------------------------------------
# Make targets
#---------------------------------------------------------------------------

# run-autotools
#
# Part of the configure set - run appropriate programs prior to
# the actual configure target if autotools are in use
#
.if !target(run-autotools)
run-autotools:
. if defined(AUTOTOOL_aclocal)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		${ACLOCAL_ARGS})
. endif
. if defined(AUTOTOOL_automake)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
. endif
. if defined(AUTOTOOL_autoconf)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
. endif
. if defined(AUTOTOOL_autoheader)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
. endif
.endif

# patch-autotools
#
# Special target to automatically make libtool using ports use the
# libtool port.  See above for default values of LIBTOOLFILES.
#
.if !target(patch-autotools)
patch-autotools:
. if defined(AUTOTOOL_libtool_inc)
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
			   -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);
. elif defined(AUTOTOOL_libtool)
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
			     -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			     -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);
. else
	@${DO_NADA}
. endif
.endif
