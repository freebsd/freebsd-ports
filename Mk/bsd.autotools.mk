# $FreeBSD$
#
# IMPORTANT NOTE:
#	Before making any changes to this file, contact portmgr to arrange
#	for an experimental ports run.
#	Untested commits will almost certainly break the tree, incur the
#	wrath of countless folks, and be unceremoniously backed out by
#	the maintainer and/or portmgr.

Autotools_Include_MAINTAINER=	tijl@FreeBSD.org

#---------------------------------------------------------------------------
# USE_AUTOTOOLS= tool[:env] ...
#
# 'tool' can currently be one of the following:
#	autoconf
#
# ':env' is used to specify that the environmental variables are needed
#	but the relevant tool should NOT be run as part of the
#	'run-autotools' target
#
# In addition, these variables can be set in the port Makefile to be
# passed to the relevant tools:
#
# AUTOCONF_ARGS=...
#	- Extra arguments passed to autoconf during configure step
#
#---------------------------------------------------------------------------

#---------------------------------------------------------------------------
# NO USER-SERVICABLE PARTS BEYOND THIS POINT.  REALLY.  WE MEAN IT.
#---------------------------------------------------------------------------

# Known autotools components
_AUTOTOOLS_ALL=	autoconf

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

#---------------------------------------------------------------------------
# autoconf
#---------------------------------------------------------------------------

.if defined(_AUTOTOOL_autoconf)
AUTOCONF_VERSION=	2.69
AUTOCONF_PORT=		devel/autoconf

. if ${_AUTOTOOL_autoconf} == "yes"
_AUTOTOOL_rule_autoconf=	yes
GNU_CONFIGURE?=			yes
. endif
.endif

.if defined(AUTOCONF_VERSION)
AUTOCONF=		${LOCALBASE}/bin/autoconf-${AUTOCONF_VERSION}
AUTOCONF_DIR=		${LOCALBASE}/share/autoconf-${AUTOCONF_VERSION}
AUTOIFNAMES=		${LOCALBASE}/bin/ifnames-${AUTOCONF_VERSION}
AUTOM4TE?=		${LOCALBASE}/bin/autom4te-${AUTOCONF_VERSION}
AUTORECONF=		${LOCALBASE}/bin/autoreconf-${AUTOCONF_VERSION}
AUTOSCAN=		${LOCALBASE}/bin/autoscan-${AUTOCONF_VERSION}
AUTOUPDATE=		${LOCALBASE}/bin/autoupdate-${AUTOCONF_VERSION}

AUTOCONF_VARS=		AUTOCONF=${AUTOCONF} \
			AUTOCONF_DIR=${AUTOCONF_DIR} \
			AUTOIFNAMES=${AUTOIFNAMES} \
			AUTOM4TE=${AUTOM4TE} \
			AUTORECONF=${AUTORECONF} \
			AUTOSCAN=${AUTOSCAN} \
			AUTOUPDATE=${AUTOUPDATE} \
			AUTOCONF_VERSION=${AUTOCONF_VERSION}

AUTOCONF_DEPENDS=	${AUTOCONF}:${AUTOCONF_PORT}
BUILD_DEPENDS+=		${AUTOCONF_DEPENDS}
.endif

#---------------------------------------------------------------------------
# Add to the environment
#---------------------------------------------------------------------------

AUTOTOOLS_VARS=		${AUTOCONF_VARS}

.if defined(AUTOTOOLS_VARS) && !empty(AUTOTOOLS_VARS)
. for var in AUTOTOOLS CONFIGURE MAKE SCRIPTS
${var:tu}_ENV+=		${AUTOTOOLS_VARS}
. endfor
.endif

#---------------------------------------------------------------------------
# Make targets
#---------------------------------------------------------------------------

_USES_configure+=461:run-autotools-autoconf

.if defined(_AUTOTOOL_rule_autoconf) && !target(run-autotools-autoconf)
run-autotools-autoconf:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
.endif
