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
# Entry point into the autotools system
#---------------------------------------------------------------------------
#
# USE_AUTOTOOLS= tool:version[:env]  ...
#
# 'tool' can currently be one of:
#	libtool, libltdl, autoconf, autoheader, automake, aclocal
#
#	There is also a special tool, called 'autotools', which is
#	a convenience function to simply bring in dependencies of
#	all the autotools.
#
# 'version' is tool dependent
#
# ':env' is used to pecify that the environment variables are needed,
#	but the relevant tool should NOT be run as part of the
#	run-autotools target
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
#	- Arguments passed to aclocal during configure step
#
# AUTOCONF_ARGS=...
#	- Extra arguments passed to autoconf during configure step
#
# AUTOHEADER_ARGS=...
#	- Extra arguments passed to autoheader during configure step
#
# LIBTOOLFLAGS=<value>
#	- Arguments passed to libtool during configure step
#
# LIBTOOLFILES=<list-of-files>
#	- A list of files to patch during libtool pre-configuration
#	  Defaults to "aclocal.m4" if autoconf is in use, otherwise
#	  ${CONFIGURE_SCRIPT} (usually "configure")
#
#---------------------------------------------------------------------------

# XXX: here be dragons :)
#
.for item in ${USE_AUTOTOOLS}
AUTOTOOL_${item:C/^([^:]+).*/\1/}${item:M*\:*\:*:C/^[^:]+:[^:]+:([^:]+)/_\1/}= ${item:C/^[^:]+:([^:]+).*/\1/}
.endfor

#---------------------------------------------------------------------------
# AUTOTOOLS handling (for build, runtime, and both)
#---------------------------------------------------------------------------
.if defined(AUTOTOOL_autotools)
AUTOTOOLS_DEPENDS=	${LOCALBASE}/share/autotools:${PORTSDIR}/devel/autotools

. if ${AUTOTOOL_autotools} == "build"
BUILD_DEPENDS+=	${AUTOTOOLS_DEPENDS}
. elif ${AUTOTOOL_autotools} == "run"
RUN_DEPENDS+=	${AUTOTOOLS_DEPENDS}
. elif ${AUTOTOOL_autotools} == "both"
BUILD_DEPENDS+=	${AUTOTOOLS_DEPENDS}
RUN_DEPENDS+=	${AUTOTOOLS_DEPENDS}
. else
IGNORE+=  Unknown autotools stanza: ${AUTOTOOL_autotools}
. endif

.endif

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
AUTOMAKE_SUFFIX=	${AUTOMAKE_VERSION:C/([0-9])(.*)/\1.\2/}

# Make sure we specified a legal version of automake
#
. if !exists(${PORTSDIR}/devel/automake${AUTOMAKE_VERSION}/Makefile)
IGNORE+=	cannot install: unknown AUTOMAKE version: ${AUTOMAKE_VERSION}
. endif

# Set up the automake environment
#
AUTOMAKE=			${LOCALBASE}/bin/automake-${AUTOMAKE_SUFFIX}
AUTOMAKE_DIR=		${LOCALBASE}/share/automake-${AUTOMAKE_SUFFIX}
ACLOCAL=			${LOCALBASE}/bin/aclocal-${AUTOMAKE_SUFFIX}
ACLOCAL_DIR=		${LOCALBASE}/share/aclocal-${AUTOMAKE_SUFFIX}
AUTOMAKE_VARS=		ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} AUTOMAKE_VERSION=${AUTOMAKE_VERSION}

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
AUTOCONF_SUFFIX=	${AUTOCONF_VERSION:C/([0-9])(.*)/\1.\2/}

# Make sure we specified a legal version of autoconf
#
. if !exists(${PORTSDIR}/devel/autoconf${AUTOCONF_VERSION}/Makefile)
IGNORE+=	cannot install: unknown AUTOCONF version: ${AUTOCONF_VERSION}
. endif

# Set up the autoconf/autoheader environment
#
AUTOCONF=			${LOCALBASE}/bin/autoconf-${AUTOCONF_SUFFIX}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf-${AUTOCONF_SUFFIX}
AUTOHEADER=			${LOCALBASE}/bin/autoheader-${AUTOCONF_SUFFIX}
AUTOIFNAMES=		${LOCALBASE}/bin/ifnames-${AUTOCONF_SUFFIX}
AUTOM4TE=			${LOCALBASE}/bin/autom4te-${AUTOCONF_SUFFIX}
AUTORECONF=			${LOCALBASE}/bin/autoreconf-${AUTOCONF_SUFFIX}
AUTOSCAN=			${LOCALBASE}/bin/autoscan-${AUTOCONF_SUFFIX}
AUTOUPDATE=			${LOCALBASE}/bin/autoupdate-${AUTOCONF_SUFFIX}
AUTOCONF_VARS=		AUTOCONF=${AUTOCONF} AUTOHEADER=${AUTOHEADER} AUTOIFNAMES=${AUTOIFNAMES} AUTOM4TE=${AUTOM4TE} AUTORECONF=${AUTORECONF} AUTOSCAN=${AUTOSCAN} AUTOUPDATE=${AUTOUPDATE} AUTOCONF_VERSION=${AUTOCONF_VERSION}

AUTOCONF_DEPENDS=	${AUTOCONF}:${PORTSDIR}/devel/autoconf${AUTOCONF_VERSION}
BUILD_DEPENDS+=		${AUTOCONF_DEPENDS}

.endif

#---------------------------------------------------------------------------
# LIBTOOL/LIBLTDL
#---------------------------------------------------------------------------

# Convenience function to save people having to depend directly on
# devel/libltdl22
#
.if defined(AUTOTOOL_libltdl)
LIB_DEPENDS+=	ltdl.7:${PORTSDIR}/devel/libltdl22
.endif

.if defined(AUTOTOOL_libtool)
GNU_CONFIGURE?=			YES
AUTOTOOL_libtool_env=	${AUTOTOOL_libtool}
.endif

.if defined(AUTOTOOL_libtool_env)
LIBTOOL_VERSION=		${AUTOTOOL_libtool_env}

# Make sure we specified a legal version of libtool
#
. if !exists(${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}/Makefile)
IGNORE+=	cannot install: unknown LIBTOOL version: ${LIBTOOL_VERSION}
. endif

# Set up the libtool environment
#
LIBTOOL=			${LOCALBASE}/bin/libtool
LIBTOOLIZE=			${LOCALBASE}/bin/libtoolize
LIBTOOL_LIBEXECDIR=	${LOCALBASE}/libexec/libtool
LIBTOOL_SHAREDIR=	${LOCALBASE}/share/libtool
LIBTOOL_M4=			${LOCALBASE}/share/aclocal/libtool.m4
LTMAIN=				${LIBTOOL_SHAREDIR}/config/ltmain.sh
LIBTOOL_VARS=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} LIBTOOL_M4=${LIBTOOL_M4}

LIBTOOL_DEPENDS=	${LIBTOOL}:${PORTSDIR}/devel/libtool${LIBTOOL_VERSION}
BUILD_DEPENDS+=		${LIBTOOL_DEPENDS}

LIBTOOLFLAGS?=		# default to empty

. if defined(AUTOTOOL_autoconf)
LIBTOOLFILES?=		aclocal.m4
. else
LIBTOOLFILES?=		${CONFIGURE_SCRIPT}
. endif

.endif

#---------------------------------------------------------------------------
# Environmental handling
# Now that we've got our environments defined for autotools, add them
# in so that the rest of the world can handle them
#
AUTOTOOLS_VARS=	${AUTOMAKE_VARS} ${AUTOCONF_VARS} ${LIBTOOL_VARS}

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
# the actual configure target if autotools are in use.
# If needed, this target can be overridden, for example to change
# the order of autotools running.

.if !target(run-autotools)
.ORDER: run-autotools run-autotools-aclocal patch-autotools run-autotools-autoheader run-autotools-autoconf run-autotools-automake

run-autotools:: run-autotools-aclocal patch-autotools run-autotools-autoheader \
		run-autotools-autoconf run-autotools-automake
.endif

.if !target(run-autotools-aclocal)
run-autotools-aclocal:
. if defined(AUTOTOOL_aclocal)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		${ACLOCAL_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-automake)
run-autotools-automake:
. if defined(AUTOTOOL_automake)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-autoconf)
run-autotools-autoconf:
. if defined(AUTOTOOL_autoconf)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-autoheader)
run-autotools-autoheader:
. if defined(AUTOTOOL_autoheader)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
. else
	@${DO_NADA}
. endif
.endif

# patch-autotools
#
# Special target to automatically make libtool using ports use the
# libtool port.  See above for default values of LIBTOOLFILES.

.if !target(patch-autotools)
patch-autotools::
. if defined(AUTOTOOL_libtool)
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			     -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);
. else
	@${DO_NADA}
. endif
.endif
