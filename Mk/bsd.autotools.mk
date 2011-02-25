#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Please view me with 4 column tabs!
#
# IMPORTANT NOTE:
#	Before making any changes to this file, contact portmgr to arrange
#	for an experimental ports run.
#	Untested commits will almost certainly break the tree, incur the
#	wrath of countless folks, and be unceremoniously backed out by
#	the maintainer and/or portmgr.

Autotools_Include_MAINTAINER=	autotools@FreeBSD.org

#---------------------------------------------------------------------------
# USE_AUTOTOOLS= tool[:env] ...
#
# 'tool' can currently be one of the following:
#		autoconf, autoheader
#		autoconf213, autoheader213 (legacy version)
#		automake, aclocal
#		automake14, aclocal14 (legacy version)
#		libtool, libtoolize, libltdl
#
# ':env' is used to specify that the environmental variables are needed
#		but the relevant tool should NOT be run as part of the
#		'run-autotools' target
#
# In addition, these variables can be set in the port Makefile to be
# passed to the relevant tools:
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
#
# AUTOTOOLSFILES=<list-of-files>
#	- A list of files to further patch with derived information
#	  post-patching to reduce churn during component updates
#
#---------------------------------------------------------------------------

#---------------------------------------------------------------------------
# NO USER-SERVICABLE PARTS BEYOND THIS POINT.  REALLY.  WE MEAN IT.
#---------------------------------------------------------------------------

# Known autotools components
_AUTOTOOLS_ALL=	autoconf autoheader autoconf213 autoheader213 \
				automake aclocal automake14 aclocal14 \
				libtool libtoolize libltdl

# Incompatible autotools mixing
_AUTOTOOLS_IGN_autoconf=		autoconf213 autoheader213
_AUTOTOOLS_IGN_autoheader=		autoconf213 autoheader213
_AUTOTOOLS_IGN_autoconf213=		autoconf autoheader
_AUTOTOOLS_IGN_autoheader213=	autoconf autoheader
_AUTOTOOLS_IGN_automake=		automake14 aclocal14
_AUTOTOOLS_IGN_aclocal=			automake14 aclocal14
_AUTOTOOLS_IGN_automake14=		automake aclocal
_AUTOTOOLS_IGN_aclocal14=		automake aclocal

#---------------------------------------------------------------------------
# Primary magic to break out the USE_AUTOTOOLS stanza into something
# more useful, along with substantial error checking to prevent
# foot-shooting
#---------------------------------------------------------------------------

# Break out the stanza
#
_AUTOTOOLS_IMPL=
.for stanza in ${USE_AUTOTOOLS}
_AUTOTOOLS_IMPL+= ${stanza:C/^([^:]+).*/\1/}
_AUTOTOOL_${stanza:C/^([^:]+).*/\1/}= ${stanza:C/^[^:]+:([^:]+)/\1/}
.endfor

# Verify each component, normalize
#
_AUTOTOOLS_NOCOMP=
.for component in ${_AUTOTOOLS_IMPL}
. if ${_AUTOTOOLS_ALL:M${component}}==""
_AUTOTOOLS_NOCOMP+=	${component}
. endif
. if ${_AUTOTOOL_${component}}==${component}
_AUTOTOOL_${component}=  yes
. elsif ${_AUTOTOOL_${component}}!="env" && ${_AUTOTOOL_${component}}!="yes"
_AUTOTOOLS_BADCOMP+= ${component}:${_AUTOTOOL_${component}}
. endif
.endfor
.if !empty(_AUTOTOOLS_NOCOMP)
IGNORE+=	Unknown autotool: ${_AUTOTOOLS_NOCOMP:O:u}
.endif

# Check for anything other than 'yes' or 'env'
#
_AUTOTOOLS_BADCOMP=
.for component in ${_AUTOTOOLS_IMPL}
. if ${_AUTOTOOL_${component}}!="env" && ${_AUTOTOOL_${component}}!="yes"
_AUTOTOOLS_BADCOMP+= ${component}:${_AUTOTOOL_${component}}
. endif
.endfor
.if !empty(_AUTOTOOLS_BADCOMP)
IGNORE+=	Bad autotool stanza: ${_AUTOTOOLS_BADCOMP:O:u}
.endif

# Check for incompatible mixes of components
#
_AUTOTOOLS_IGN=
.for component in ${_AUTOTOOLS_IMPL}
. for ignore in ${_AUTOTOOLS_IGN_${component}}
.  if defined(_AUTOTOOL_${ignore})
_AUTOTOOLS_IGN+=	${component}
.  endif
. endfor
.endfor
.if !empty(_AUTOTOOLS_IGN)
IGNORE+=	Incompatible autotools: ${_AUTOTOOLS_IGN:O:u}
.endif

#---------------------------------------------------------------------------
# automake and aclocal
#---------------------------------------------------------------------------

.if defined(_AUTOTOOL_aclocal) && ${_AUTOTOOL_aclocal} == "yes"
_AUTOTOOL_automake?=		env
_AUTOTOOL_rule_aclocal=		yes
GNU_CONFIGURE=				yes
.endif

.if defined(_AUTOTOOL_automake)
AUTOMAKE_VERSION=	1.11
AUTOMAKE_APIVER=	1.11.1
AUTOMAKE_PORT=		devel/automake

. if ${_AUTOTOOL_automake} == "yes"
_AUTOTOOL_rule_automake=	yes
GNU_CONFIGURE?=				yes
. endif
.endif

.if defined(_AUTOTOOL_aclocal14) && ${_AUTOTOOL_aclocal14} == "yes"
_AUTOTOOL_automake14?=		env
_AUTOTOOL_rule_aclocal14=	yes
GNU_CONFIGURE?=				yes
.endif

.if defined(_AUTOTOOL_automake14)
AUTOMAKE_VERSION=	1.4
AUTOMAKE_APIVER=	1.4.6
AUTOMAKE_PORT=		devel/automake14
AUTOMAKE_ARGS+=		-i		# backwards compatibility shim

. if ${_AUTOTOOL_automake14} == "yes"
_AUTOTOOL_rule_automake=	yes
GNU_CONFIGURE?=				yes
. endif
.endif

.if defined(AUTOMAKE_VERSION)
AUTOMAKE=			${LOCALBASE}/bin/automake-${AUTOMAKE_VERSION}
AUTOMAKE_DIR=		${LOCALBASE}/share/automake-${AUTOMAKE_VERSION}
ACLOCAL=			${LOCALBASE}/bin/aclocal-${AUTOMAKE_VERSION}
ACLOCAL_DIR=		${LOCALBASE}/share/aclocal-${AUTOMAKE_VERSION}

. if defined(_AUTOTOOL_aclocal) || defined(_AUTOTOOL_aclocal14)
ACLOCAL_ARGS?=		--acdir=${ACLOCAL_DIR}
. endif

AUTOMAKE_VARS=		AUTOMAKE=${AUTOMAKE} \
					AUTOMAKE_DIR=${AUTOMAKE_DIR} \
					AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
					AUTOMAKE_APIVER=${AUTOMAKE_APIVER} \
					ACLOCAL=${ACLOCAL} \
					ACLOCAL_DIR=${ACLOCAL_DIR}

AUTOMAKE_DEPENDS=	${AUTOMAKE}:${PORTSDIR}/${AUTOMAKE_PORT}
BUILD_DEPENDS+=		${AUTOMAKE_DEPENDS}
.endif

#---------------------------------------------------------------------------
# autoconf and autoheader
#---------------------------------------------------------------------------

.if defined(_AUTOTOOL_autoheader) && ${_AUTOTOOL_autoheader} == "yes"
_AUTOTOOL_autoconf=			yes
_AUTOTOOL_rule_autoheader=	yes
GNU_CONFIGURE?=				yes
.endif

.if defined(_AUTOTOOL_autoconf)
AUTOCONF_VERSION=	2.68
AUTOCONF_PORT=		devel/autoconf

. if ${_AUTOTOOL_autoconf} == "yes"
_AUTOTOOL_rule_autoconf=	yes
GNU_CONFIGURE?=				yes
. endif
.endif

.if defined(_AUTOTOOL_autoheader213) && ${_AUTOTOOL_autoheader213} == "yes"
_AUTOTOOL_autoconf213=		yes
_AUTOTOOL_rule_autoheader=	yes
GNU_CONFIGURE?=				yes
.endif

.if defined(_AUTOTOOL_autoconf213)
AUTOCONF_VERSION=	2.13
AUTOCONF_PORT=		devel/autoconf213
AUTOM4TE=			${FALSE}	# doesn't exist here

. if ${_AUTOTOOL_autoconf213} == "yes"
_AUTOTOOL_rule_autoconf=	yes
GNU_CONFIGURE?=				yes
. endif
.endif

.if defined(AUTOCONF_VERSION)
AUTOCONF=			${LOCALBASE}/bin/autoconf-${AUTOCONF_VERSION}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf-${AUTOCONF_VERSION}
AUTOHEADER=			${LOCALBASE}/bin/autoheader-${AUTOCONF_VERSION}
AUTOIFNAMES=		${LOCALBASE}/bin/ifnames-${AUTOCONF_VERSION}
AUTOM4TE?=			${LOCALBASE}/bin/autom4te-${AUTOCONF_VERSION}
AUTORECONF=			${LOCALBASE}/bin/autoreconf-${AUTOCONF_VERSION}
AUTOSCAN=			${LOCALBASE}/bin/autoscan-${AUTOCONF_VERSION}
AUTOUPDATE=			${LOCALBASE}/bin/autoupdate-${AUTOCONF_VERSION}

AUTOCONF_VARS=		AUTOCONF=${AUTOCONF} \
					AUTOCONF_DIR=${AUTOCONF_DIR} \
					AUTOHEADER=${AUTOHEADER} \
					AUTOIFNAMES=${AUTOIFNAMES} \
					AUTOM4TE=${AUTOM4TE} \
					AUTORECONF=${AUTORECONF} \
					AUTOSCAN=${AUTOSCAN} \
					AUTOUPDATE=${AUTOUPDATE} \
					AUTOCONF_VERSION=${AUTOCONF_VERSION}

AUTOCONF_DEPENDS=	${AUTOCONF}:${PORTSDIR}/${AUTOCONF_PORT}
BUILD_DEPENDS+=		${AUTOCONF_DEPENDS}
.endif

#---------------------------------------------------------------------------
# libltdl
#---------------------------------------------------------------------------

.if defined(_AUTOTOOL_libltdl)
LIB_DEPENDS+=		ltdl.7:${PORTSDIR}/devel/libltdl
.endif

#---------------------------------------------------------------------------
# libtool/libtoolize
#---------------------------------------------------------------------------

.if defined(_AUTOTOOL_libtool) || defined(_AUTOTOOL_libtoolize)
LIBTOOL_VERSION=	2.4
LIBTOOL_PORT=		devel/libtool

. if defined(_AUTOTOOL_libtool) && ${_AUTOTOOL_libtool} == "yes"
_AUTOTOOL_rule_libtool=		yes
GNU_CONFIGURE?=				yes
. endif
. if defined(_AUTOTOOL_libtoolize) && ${_AUTOTOOL_libtoolize} == "yes"
_AUTOTOOL_rule_libtoolize=	yes
GNU_CONFIGURE?=				yes
. endif

.endif

.if defined(LIBTOOL_VERSION)
LIBTOOL=			${LOCALBASE}/bin/libtool
LIBTOOLIZE=			${LOCALBASE}/bin/libtoolize
LIBTOOL_LIBEXECDIR=	${LOCALBASE}/libexec/libtool
LIBTOOL_SHAREDIR=	${LOCALBASE}/share/libtool
LIBTOOL_M4=			${LOCALBASE}/share/aclocal/libtool.m4
LTMAIN=				${LOCALBASE}/share/libtool/config/ltmain.sh

LIBTOOL_VARS=		LIBTOOL=${LIBTOOL} \
					LIBTOOLIZE=${LIBTOOLIZE} \
					LIBTOOL_LIBEXECDIR=${LIBTOOL_LIBEXECDIR} \
					LIBTOOL_SHAREDIR=${LIBTOOL_SHAREDIR} \
					LIBTOOL_M4=${LIBTOOL_M4} \
					LTMAIN=${LTMAIN}

LIBTOOLFLAGS?=		# default to empty

. if defined(_AUTOTOOL_rule_autoconf) || defined(_AUTOTOOL_rule_autoconf213)
LIBTOOLFILES?=		aclocal.m4
. elif defined(_AUTOTOOL_rule_libtool)
LIBTOOLFILES?=		${CONFIGURE_SCRIPT}
. endif

LIBTOOL_DEPENDS=	libtool>=2.4:${PORTSDIR}/${LIBTOOL_PORT}
BUILD_DEPENDS+=		${LIBTOOL_DEPENDS}
.endif

#---------------------------------------------------------------------------
# Add to the environment
#---------------------------------------------------------------------------

AUTOTOOLS_VARS=		${AUTOMAKE_VARS} ${AUTOCONF_VARS} ${LIBTOOL_VARS}

.if defined(AUTOTOOLS_VARS) && !empty(AUTOTOOLS_VARS)
. for var in AUTOTOOLS CONFIGURE MAKE SCRIPTS
${var:U}_ENV+=		${AUTOTOOLS_VARS}
. endfor
.endif

#---------------------------------------------------------------------------
# Make targets
#---------------------------------------------------------------------------

.if !target(run-autotools)
.ORDER:			run-autotools run-autotools-aclocal \
				patch-autotools-libtool run-autotools-autoheader \
				run-autotools-libtoolize run-autotools-autoconf \
				run-autotools-automake

run-autotools:: run-autotools-aclocal \
				patch-autotools-libtool run-autotools-autoheader \
				run-autotools-libtoolize run-autotools-autoconf \
				run-autotools-automake
.endif

.if !target(run-autotools-aclocal)
run-autotools-aclocal:
. if defined(_AUTOTOOL_rule_aclocal)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		${ACLOCAL_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-automake)
run-autotools-automake:
. if defined(_AUTOTOOL_rule_automake)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-autoconf)
run-autotools-autoconf:
. if defined(_AUTOTOOL_rule_autoconf)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-autoheader)
run-autotools-autoheader:
. if defined(_AUTOTOOL_rule_autoheader)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(run-autotools-libtoolize)
run-autotools-libtoolize:
. if defined(_AUTOTOOL_rule_libtoolize)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} \
		${LIBTOOLIZE_ARGS})
. else
	@${DO_NADA}
. endif
.endif

.if !target(patch-autotools-libtool)
patch-autotools-libtool::
. if defined(_AUTOTOOL_rule_libtool)
	@for file in ${LIBTOOLFILES}; do \
		${REINPLACE_CMD} -e \
			"/^ltmain=/!s|\$$ac_aux_dir/ltmain.sh|${LIBTOOLFLAGS} ${LTMAIN}|g; \
			/^LIBTOOL=/s|\$$(top_builddir)/libtool|${LIBTOOL}|g" \
			${PATCH_WRKSRC}/$$file; \
	done;
. else
	@${DO_NADA}
. endif
.endif

#---------------------------------------------------------------------------
# Reduce patch churn by auto-substituting data from AUTOTOOLS_VARS
# into the correct places.  Code shamelessly stolen from PLIST_SUB.

AUTOTOOLSFILES?=	# default to empty
AUTOTOOLS_VARS?=	# empty if not already set

.if !target(configure-autotools)
configure-autotools::
. if ${AUTOTOOLS_VARS}!="" && ${AUTOTOOLSFILES} != ""
	@for file in ${AUTOTOOLSFILES}; do \
		${REINPLACE_CMD} ${AUTOTOOLS_VARS:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
			${WRKSRC}/$${file} ; \
	done
. else
	@${DO_NADA}
. endif
.endif
