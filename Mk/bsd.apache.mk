# $FreeBSD$
#
# bsd.apache.mk - Apache related macros.
# Author: Clement Laforet <clement@FreeBSD.org>
# Author: Olli Hauer <ohauer@FreeBSD.org>
#
# Please view me with 4 column tabs!

# =========================================================================
# User controlled parameters for usage in /etc/make.conf:
#
#  DEFAULT_VERSIONS  - define the default apache version
#                      valid args: apache=2.2, apache=2.4
#
#  APACHE_PORT       - use www/apache22-(event|itk|peruser|worker)-mpm
#                      instead www/apache22.  Use this parameter only in
#                      combination with "DEFAULT_VERSIONS+= apache=2.2"
#
# Example entry in /etc/make.conf:
# - Set apache22 as default version
#    DEFAULT_VERSIONS+= apache=2.2
#
# - Additional use a special www/apache22-$MPM port
#    APACHE_PORT= www/apache22-event-mpm
#
# Note:
#  - This parameters should never be used in the Makefile of a port!
#  - To get a list of "possible" APACHE_PORT values execute the command:
#    $> awk '/apache22-/ {print "www/" $3}' ports/www/Makefile
#
# =========================================================================
#
# This script will be included if one of the following parameter
# is defined in the Makefile of the port
#
# USE_APACHE         - Set apache and apxs as build and run dependency
# USE_APACHE_BUILD   - Set apache and apxs as build dependency
# USE_APACHE_RUN     - Set apache and apxs as run dependency
#
# The following example is representative of all three possible
# parameters to use.
#
# Examples:
#  USE_APACHE= 22       # specify exact version
#  USE_APACHE= 22+      # specify [min] version, no [max] version
#  USE_APACHE= 22-24    # specify [min]-[max] range
#  USE_APACHE= -22      # specify [max] version, no [min] version
#
# Note:
#  - If "+" is specified and no apache is installed, then
#    ${DEFAULT_APACHE_VERSION} will be used.
#
#  - Valid version numbers are specified in the variable
#    APACHE_SUPPORTED_VERSION below
#
#  - The following values for USE_APACHE are reserverd and only valid
#    in apache-server ports!
#      USE_APACHE= common22
#
#
# The following variables can be used (ro) in ports Makefile
# =========================================================================
#  - APACHE_VERSION
#  - APACHEETCDIR
#  - APACHEINCLUDEDIR
#  - APACHEMODDIR
#  - DEFAULT_APACHE_VERSION
#
#
# Parameters for building third party apache modules:
# =========================================================================
#  - AP_FAST_BUILD      # automatic module build
#
#  - AP_GENPLIST        # automatic PLIST generation plus add
#                       # the module disabled into httpd.conf
#                       # (only if no pkg-plist exist)
#
#  - MODULENAME         # default: ${PORTNAME}
#  - SHORTMODNAME       # default: ${MODULENAME:S/mod_//}
#  - SRC_FILE           # default: ${MODULENAME}.c
#
#

.if !defined(Apache_Pre_Include)

Apache_Pre_Include=		bsd.apache.mk

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if defined(DEFAULT_APACHE_VER)
WARNING+=	"DEFAULT_APACHE_VER is defined, consider using DEFAULT_VERSIONS+=apache=${DEFAULT_APACHE_VER} instead"
.endif

DEFAULT_APACHE_VERSION?=	${APACHE_DEFAULT:S/.//}
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
APACHE_SUPPORTED_VERSION=	24 22 # preferred version first

# Print warnings
_ERROR_MSG=	: Error from bsd.apache.mk.

# Important Note:
#  Keep apache version in ascending order!
#  The "+" sign is only valid as last sign, not between
#  two versions or in combination with range!
.if defined(USE_APACHE) && !empty(USE_APACHE)
.	if ${USE_APACHE:Mcommon*} != ""
AP_PORT_IS_SERVER=	yes
.	elif ${USE_APACHE:C/\-//:S/^22//:S/^24//:C/\+$//} == ""
AP_PORT_IS_MODULE=	yes
.		if ${USE_APACHE:C/\-//:S/^22//:S/^24//} == "+"
AP_PLUS=	yes
.		endif
.	else
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE ( ${USE_APACHE} )
.	endif
# Catch unknown apache versions and silly USE_APACHE constructs
.	if empty(AP_PORT_IS_SERVER) && empty(AP_PORT_IS_MODULE)
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE ( ${USE_APACHE} )
.	endif
# Catch USE_APACHE [min]-[max]+
.	if defined(AP_PLUS) && ${USE_APACHE:C/[.+0-9]//g} == "-"
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE ( ${USE_APACHE} )
.	endif
.elif defined(USE_APACHE)
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE ( no version specified )
.endif # defined(USE_APACHE)

# ===============================================================
.if defined(AP_PORT_IS_SERVER)
# Module selection
.for category in ${DEFAULT_MODULES_CATEGORIES}
DEFAULT_MODULES+=	${${category}_MODULES}
.endfor

.for category in ${ALL_MODULES_CATEGORIES}
AVAILABLE_MODULES+=	${${category}_MODULES}
.endfor

# detect invalid lowercase params in make.conf
# keep this check until end of 2012
.if defined(WITH_STATIC_MODULES) && ${WITH_STATIC_MODULES:M[a-z]*}
IGNORE=		lowercase WITH_STATIC_MODULES="${WITH_STATIC_MODULES}"\
		detected (make.conf), they shoud be UPPERCASE
.endif

# Setting "@comment " as default.
.for module in ${AVAILABLE_MODULES:O}
${module}PLIST_SUB=	"@comment "
_DISABLE_MODULES+=	--disable-${module:tl}
.endfor

# Configure
# dirty hacks to make sure all modules are disabled before we select them
.if ${USE_APACHE:Mcommon2*}
CONFIGURE_ARGS+= 	${_DISABLE_MODULES:O:u}
.endif

# OPTIONS handling
.for module in ${AVAILABLE_MODULES}
.	if ${PORT_OPTIONS:M${module}}
_APACHE_MODULES+=	${module}
.	else
WITHOUT_MODULES+=	${module}
.	endif
.endfor

.if !defined(WITH_STATIC_APACHE)
# FYI
#DYNAMIC_MODULES=	so
CONFIGURE_ARGS+=	--enable-so
.else
CONFIGURE_ARGS+=	--disable-so
WITH_ALL_STATIC_MODULES=	yes
.endif

.if ${PORT_OPTIONS:MSUEXEC}
_APACHE_MODULES+=	${SUEXEC_MODULES}
SUEXEC_CONFARGS=	with-suexec

# SUEXEC_DOCROOT should exist
SUEXEC_DOCROOT?=	${PREFIX}/www/data
#SUEXEC_DOCROOT?=	${WWWDIR}
SUEXEC_USERDIR?=	public_html
# avoid duplicate search paths
.if ${LOCALBASE} == ${PREFIX}
SUEXEC_SAFEPATH?=	${LOCALBASE}/bin:/usr/bin:/bin
.else
SUEXEC_SAFEPATH?=	${PREFIX}/bin:${LOCALBASE}/bin:/usr/bin:/bin
.endif
SUEXEC_LOGFILE?=	/var/log/httpd-suexec.log
SUEXEC_UIDMIN?=		1000
SUEXEC_GIDMIN?=		1000
SUEXEC_CALLER?=		${WWWOWN}
CONFIGURE_ARGS+=	--${SUEXEC_CONFARGS}-caller=${SUEXEC_CALLER} \
			--${SUEXEC_CONFARGS}-uidmin=${SUEXEC_UIDMIN} \
			--${SUEXEC_CONFARGS}-gidmin=${SUEXEC_GIDMIN} \
			--${SUEXEC_CONFARGS}-userdir="${SUEXEC_USERDIR}" \
			--${SUEXEC_CONFARGS}-docroot="${SUEXEC_DOCROOT}" \
			--${SUEXEC_CONFARGS}-safepath="${SUEXEC_SAFEPATH}" \
			--${SUEXEC_CONFARGS}-logfile="${SUEXEC_LOGFILE}" \
			--${SUEXEC_CONFARGS}-bin="${PREFIX}/sbin/suexec"

.	if defined(WITH_SUEXEC_UMASK)
CONFIGURE_ARGS+=	--${SUEXEC_CONFARGS}-umask=${SUEXEC_UMASK}
.	endif
.endif

.if !defined(WITHOUT_MODULES)
APACHE_MODULES=		${_APACHE_MODULES}
.else
.for module in ${_APACHE_MODULES:O:u}
.	if !${WITHOUT_MODULES:M${module}}
APACHE_MODULES+=	${module}
.	endif
.endfor
.endif

.if defined(WITH_STATIC_MODULES)
.for module in ${APACHE_MODULES}
.	if ${WITH_STATIC_MODULES:M${module}}
_CONFIGURE_ARGS+=	--enable-${module:tl}=static
.	else
_CONFIGURE_ARGS+=	--enable-${module:tl}=shared
.	endif
.endfor
CONFIGURE_ARGS+=	${_CONFIGURE_ARGS:O}
.elif defined(WITH_STATIC_APACHE) || defined(WITH_ALL_STATIC_MODULES)
WITH_STATIC_MODULES=	${APACHE_MODULES}
CONFIGURE_ARGS+=	--enable-modules="${APACHE_MODULES:O:tl}"
.else
CONFIGURE_ARGS+=	--enable-mods-shared="${APACHE_MODULES:O:tl}"
.endif

# ====================================
# start pkg-plist adjustments
.if defined(WITH_STATIC_MODULES)
.for module in ${APACHE_MODULES}
.	if !${WITH_STATIC_MODULES:M${module}}
_SHARED_MODULES+=	${module}
.	endif
.endfor

SHARED_MODULES=		${_SHARED_MODULES}
.elif !defined(WITH_ALL_STATIC_MODULES)
SHARED_MODULES=		${APACHE_MODULES}
.endif

.for module in ${SHARED_MODULES}
${module}PLIST_SUB=	""
.endfor

.for module in ${AVAILABLE_MODULES:O:u}
PLIST_SUB+=	MOD_${module}=${${module}PLIST_SUB}
.endfor

# pkg-plist workaround STATIC support
.if ${PORT_OPTIONS:MSUEXEC}
PLIST_SUB+=	SUEXEC=""
.else
PLIST_SUB+=	SUEXEC="@comment "
.endif

.if ${PORT_OPTIONS:MLOG_FORENSIC}
PLIST_SUB+=	FORENSIC=""
.else
PLIST_SUB+=	FORENSIC="@comment "
.endif

# end pkg-plist adjustments

#### End of AP_PORT_IS_SERVER ####

# ===============================================================
.elif defined(AP_PORT_IS_MODULE) || defined(USE_APACHE_RUN) || defined(USE_APACHE_BUILD)
APXS?=		${LOCALBASE}/sbin/apxs
HTTPD?=		${LOCALBASE}/sbin/httpd

MODULENAME?=	${PORTNAME}
SHORTMODNAME?=	${MODULENAME:S/mod_//}
SRC_FILE?=	${MODULENAME}.c

.if exists(${HTTPD})
_APACHE_VERSION!=	${HTTPD} -v | ${SED} -ne 's/^Server version: Apache\/\([0-9]\)\.\([0-9]*\).*/\1\2/p'
.elif defined(APACHE_PORT)
_APACHE_VERSION!=	${ECHO_CMD} ${APACHE_PORT} | ${SED} -ne 's,.*/apache\([0-9]*\).*,\1,p'
.endif

.if defined(USE_APACHE)
_USE_APACHE:=	${USE_APACHE}
.elif defined(USE_APACHE_BUILD)
_USE_APACHE:=	${USE_APACHE_BUILD}
.elif defined(USE_APACHE_RUN)
_USE_APACHE:=	${USE_APACHE_RUN}
.endif

_APACHE_VERSION_CHECK:=		${_USE_APACHE:C/^([1-9][0-9])$/\1-\1/}
_APACHE_VERSION_MINIMUM_TMP:=	${_APACHE_VERSION_CHECK:C/([1-9][0-9])[-+].*/\1/}
_APACHE_VERSION_MINIMUM:=	${_APACHE_VERSION_MINIMUM_TMP:M[1-9][0-9]}
_APACHE_VERSION_MAXIMUM_TMP:=	${_APACHE_VERSION_CHECK:C/.*-([1-9][0-9])/\1/}
_APACHE_VERSION_MAXIMUM:=	${_APACHE_VERSION_MAXIMUM_TMP:M[1-9][0-9]}

# ==============================================================
# num+
.if ${_USE_APACHE:M*+}
_APACHE_WANTED_VERSIONS=	${DEFAULT_APACHE_VERSION}

# -num
.elif ${_USE_APACHE:M\-[0-9][0-9]}
.for _v in ${APACHE_SUPPORTED_VERSION:O}
.	if ${_APACHE_VERSION_MAXIMUM} >= ${_v}
_APACHE_WANTED_VERSIONS+=	${_v}
.	endif
.endfor

# num-num
.elif ${_USE_APACHE:M[0-9][0-9]-[0-9][0-9]}
.for _v in ${APACHE_SUPPORTED_VERSION}
.	if ${_APACHE_VERSION_MINIMUM} <= ${_v} && ${_APACHE_VERSION_MAXIMUM} >= ${_v}
_APACHE_WANTED_VERSIONS+=	${_v}
.	endif
.endfor

# num
.elif ${_USE_APACHE:M[0-9][0-9]}
_APACHE_WANTED_VERSIONS=	${_USE_APACHE:M[0-9][0-9]}
.endif
# ==============================================================

.if !defined(_APACHE_WANTED_VERSIONS)
_APACHE_WANTED_VERSIONS=	${DEFAULT_APACHE_VERSION}
.endif

.for _v in ${_APACHE_WANTED_VERSIONS:O:u}
_APACHE_HIGHEST_VERSION:=	${_v}
.	if defined (_APACHE_VERSION) && ${_APACHE_VERSION} == ${_v}
_APACHE_WANTED_VERSION:=	${_v}
.	endif
.endfor

.if !defined(_APACHE_WANTED_VERSION)
# next line is broken on 8.x and 9.x but working on 10
#_APACHE_WANTED_VERSION:=	${_APACHE_WANTED_VERSIONS:O:u:M${DEFAULT_APACHE_VERSION}}
# working line on 8.x, 9.x, 10
_APACHE_WANTED_VERSION:=	${_APACHE_WANTED_VERSIONS:O:u:MDEFAULT_APACHE_VERSION}
.	if empty(_APACHE_WANTED_VERSION)
_APACHE_WANTED_VERSION:=	${_APACHE_HIGHEST_VERSION}
.	endif
.endif

.if defined(_APACHE_VERSION) && ${_APACHE_VERSION} != ${_APACHE_WANTED_VERSION}
BROKEN=	${_ERROR_MSG} apache${_APACHE_VERSION} is installed (or APACHE_PORT is defined) and port requires apache${_APACHE_VERSION_NONSUPPORTED}
.endif

APACHE_VERSION:=	${_APACHE_WANTED_VERSION}

.if exists(${APXS})
APXS_PREFIX!=	${APXS} -q prefix 2> /dev/null || echo NULL
.	if ${APXS_PREFIX} == NULL
IGNORE=	: Your apache does not support DSO modules
.	endif
.	if defined(AP_GENPLIST) && ${APXS_PREFIX} != ${PREFIX}
IGNORE?=	PREFIX must be equal to APXS_PREFIX.
.	endif
.endif

APACHEMODDIR=	libexec/apache${APACHE_VERSION}
APACHEINCLUDEDIR=include/apache${APACHE_VERSION}
APACHEETCDIR=	etc/apache${APACHE_VERSION}
APACHE_PORT?=	www/apache${APACHE_VERSION}

PLIST_SUB+=	APACHEMODDIR="${APACHEMODDIR}" \
		APACHEINCLUDEDIR="${APACHEINCLUDEDIR}" \
		APACHEETCDIR="${APACHEETCDIR}" \
		APACHE_VERSION="${APACHE_VERSION}"

SUB_LIST+=	APACHEMODDIR="${APACHEMODDIR}" \
		APACHEETCDIR="${APACHEETCDIR}" \
		APACHE_VERSION="${APACHE_VERSION}"

APACHE_PKGNAMEPREFIX=	ap${APACHE_VERSION}-

.if defined(AP_FAST_BUILD)
PKGNAMEPREFIX?=	${APACHE_PKGNAMEPREFIX}
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_BUILD)
BUILD_DEPENDS+=	${APXS}:${APACHE_PORT}
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_RUN)
RUN_DEPENDS+=	${APXS}:${APACHE_PORT}
.endif

PLIST_SUB+=	AP_NAME="${SHORTMODNAME}"
PLIST_SUB+=	AP_MODULE="${MODULENAME}.so"

.if defined(AP_GENPLIST)
PLIST?=		${WRKDIR}/ap-plist
.endif

.if defined(AP_INC)
AP_EXTRAS+=	-I ${AP_INC}
.endif
.if defined(AP_LIB)
AP_EXTRAS+=	-L ${AP_LIB}
.endif

.endif # End of AP_PORT_IS_SERVER   / AP_PORT_IS_MOULE
.endif # End of !Apache_Pre_Include

# ===============================================================
.if defined(_POSTMKINCLUDED) && !defined(Apache_Post_Include)
Apache_Post_Include=	bsd.apache.mk

.if defined(USE_APACHE_RUN) && !empty(USE_APACHE_RUN)
.	if ${USE_APACHE_RUN:C/\-//:S/^22//:S/^24//:C/\+$//} != ""
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_RUN ( ${USE_APACHE_RUN} )
.	endif
.elif defined(USE_APACHE_RUN)
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_RUN ( no valid version specified )
.endif

.if defined(USE_APACHE_BUILD) && !empty(USE_APACHE_BUILD)
.	if ${USE_APACHE_BUILD:C/\-//:S/^22//:S/^24//:C/\+$//} != ""
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_BUILD ( ${USE_APACHE_BUILD} )
.	endif
.elif defined(USE_APACHE_BUILD)
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_BUILD ( no valid version specified )
.endif

# Check if USE_APACHE(_BUILD|_RUN) are mixed together
.if defined(USE_APACHE) && ( defined(USE_APACHE_BUILD) || defined(USE_APACHE_RUN) )
IGNORE=	${_ERROR_MSG} specify only one of: USE_APACHE USE_APACHE_BUILD USE_APACHE_RUN
.elif defined(USE_APACHE_BUILD) && defined(USE_APACHE_RUN)
IGNORE= ${_ERROR_MSG} use USE_APACHE instead of USE_APACHE_BUILD and USE_APACHE_RUN together
.endif

.if defined(NO_BUILD) && defined(USE_APACHE)
BROKEN=	If NO_BUILD is used, then USE_APACHE_RUN is sufficient. Please fix your Makefile
.endif

.if defined(AP_PORT_IS_SERVER)
.if !target(print-closest-mirrors)
print-closest-mirrors:
	@${ECHO_MSG} -n "Fetching list of nearest mirror: " >&2
	@MIRRORS=`${FETCH_CMD} -T 30 -qo - http://www.apache.org/dyn/closer.cgi/httpd/ 2> /dev/null\
	| ${GREP} /httpd/ | ${SED} 's/.*href="\(.*\)"><str.*/\1/g' | \
	${HEAD} -7 | ${TAIL} -6` ; \
	${ECHO_MSG} done >&2; if [ "x$$MIRRORS" != "x" ]; then \
	${ECHO_MSG} -n "MASTER_SITE_APACHE_HTTPD?= ";\
	${ECHO_MSG} $$MIRRORS; else \
	${ECHO_MSG} "No mirrors found!">&2 ; fi
.endif

.if !target(show-modules)
show-modules:
.if !empty(APACHE_MODULES)
.for module in ${AVAILABLE_MODULES}
	@${PRINTF} "%-20s : " ${module}
.	if ${APACHE_MODULES:M${module}}
		@${ECHO} -n "enabled "
.		if !empty(WITH_STATIC_MODULES) && ${WITH_STATIC_MODULES:M${module}}
			@${ECHO_CMD} " (static)"
.		else
			@${ECHO_CMD} "(shared)"
.		endif
.	else
		@${ECHO_CMD} disabled
.	endif
.endfor
.else
.for module in ${AVAILABLE_MODULES}
	@${PRINTF} "%-20s : disabled\n" ${module}
.endfor
.endif
.endif

.elif defined(AP_PORT_IS_MODULE)

.if defined(AP_MODENABLE)
AP_MOD_EN=	-a
.else
AP_MOD_EN=	-A
.endif
PLIST_SUB+=	AP_MOD_EN="${AP_MOD_EN}"

.if defined(AP_FAST_BUILD)
.if !target(ap-gen-plist)
_USES_build+=	490:ap-gen-plist
ap-gen-plist:
.if defined(AP_GENPLIST)
.	if !exists(${PLIST})
	@${ECHO} "===>  Generating apache plist"
	@${ECHO} "%%APACHEMODDIR%%/%%AP_MODULE%%" >> ${PLIST}
	@${ECHO} "@postexec %D/sbin/apxs -e ${AP_MOD_EN} -n %%AP_NAME%% %D/%F" >> ${PLIST}
	@${ECHO} "@postunexec ${SED} -i '' -E '/LoadModule[[:blank:]]+%%AP_NAME%%_module/d' %D/%%APACHEETCDIR%%/httpd.conf" >> ${PLIST}
	@${ECHO} "@postunexec echo \"Don't forget to remove all ${MODULENAME}-related directives in your httpd.conf\"">> ${PLIST}
.	endif
.endif
.endif

.if !target(do-build)
do-build:
	(cd ${WRKSRC} && ${APXS} -c ${AP_EXTRAS} -o ${MODULENAME}.la ${SRC_FILE})
.endif

.if !target(do-install)
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i -n ${SHORTMODNAME} ${WRKSRC}/${MODULENAME}.la
.	if !defined(DEBUG)
		@${ECHO_MSG} "===> strip ${APACHEMODDIR}/${MODULENAME}.so"
		@[ -e ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so ] && ${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
.	else
		@${ECHO_MSG} "===> DEBUG is set, will not strip ${APACHEMODDIR}/${MODULENAME}.so"
.	endif
.endif

.endif          # defined(AP_FAST_BUILD)
.endif          # defined(AP_PORT_IS_SERVER / AP_PORT_IS_MODULE)
.endif          # defined(_POSTMKINCLUDED) && !defined(Apache_Post_Include)
