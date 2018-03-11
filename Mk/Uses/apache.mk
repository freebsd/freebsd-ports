#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# apache.mk - Apache related macros.
# Author: Clement Laforet <clement@FreeBSD.org>
# Author: Olli Hauer <ohauer@FreeBSD.org>
# Author: Bernard Spil <brnrd@FreeSBD.org>
#
# Please view me with 4 column tabs!

# Feature:		apache
# Usage:		USES=apache or USES=apache:args
# Valid args:	<version>, build, run, server
#
# version	If your port requires a specific Apache httpd version, you can
#			set this to [min]-[max] or min+ or -max or an explicit version
#
#				USES=apache:2.2		# Only use Apache 2.2
#				USES=apache:2.4+	# Use Apache 2.4 or newer
#				USES=apache:2.2-2.4	# Use Apache 2.2 or 2.4
#				USES=apache:-2.4	# Use Apache 2.4 or earlier
#				USES=apache			# Use the default apache version
#
#			Valid version numbers are specified in the variable
#			APACHE_SUPPORTED_VERSIONS below
#
# build		Indicates that Apache is needed at build time and adds it to
#			BUILD_DEPENDS.
# run		Indicates that Apache is needed at run time and adds it to
#			RUN_DEPENDS.
# server	Indicates that the port is a server port.
#
# If build and run are omitted, Apache will be added as BUILD_DEPENDS and
# RUN_DEPENDS
#
# Variables, which can be set by the port:
#
#  AP_FAST_BUILD	automatic module build
#
#  AP_GENPLIST		automatic PLIST generation plus add
#					the module disabled into httpd.conf
#					(only if no pkg-plist exist)
#
#  MODULENAME		Name of the Apache module
#					default: ${PORTNAME}
#  SHORTMODNAME		Short name of the Apache module
#					default: ${MODULENAME:S/mod_//}
#  SRC_FILE			Source file of the APACHE MODULE
#					default: ${MODULENAME}.c
#
# Variables, for internal use by the Apache ports framework only
#  The following values for USE_APACHE are reserved and only valid
#  in apache-server ports!
#      USES= apache:server,2.2
#
#
# The following variables can be read by ports and must not be modified
# 
#  APACHE_VERSION		The major-minor release version of the chosen
#						Apache server, e.g. 2.2 or 2.4
#
#  APACHEETCDIR			Location of the Apache configuration directory
#						Default: ${LOCALBASE}/etc/apache24
#
#  APACHEINCLUDEDIR		Location of the Apache include files
#						Default: ${LOCALBASE}/include/apache24
#
#  APACHEMODDIR			Location of the Apache modules
#						Default: ${LOCALBASE}/libxexec/apache24
#
#  APACHE_DEFAULT		Default Apache version
#

.if !defined(_INCLUDE_USES_APACHE_PRE_MK)
_INCLUDE_USES_APACHE_PRE_MK=	yes
_USES_POST+=	apache

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_APACHE_SUPPORTED_VERSIONS=	2.4 2.2 2.5	# preferred version first

# Print warnings
_ERROR_MSG=	: Error from apache.mk.

# Important Note:
#  The "+" sign is only valid as last sign, not between
#  two versions or in combination with range!
.if defined(apache_ARGS) && !empty(apache_ARGS)
# Preserve original arguments list
_APACHE_ARGS=		${apache_ARGS}
.	if ${_APACHE_ARGS:Mserver} || ${_APACHE_ARGS:Mcommon}
_APACHE_PORT_IS_SERVER=	yes
_APACHE_ARGS:=		${_APACHE_ARGS:Nserver}
.	endif
.	if ${_APACHE_ARGS:Mbuild}
_APACHE_BUILD_DEP=	yes
_APACHE_ARGS:=		${_APACHE_ARGS:Nbuild}
.	endif
.	if ${_APACHE_ARGS:Mrun}
_APACHE_RUN_DEP=	yes
_APACHE_ARGS:=		${_APACHE_ARGS:Nrun}
.	endif
.	if empty(_APACHE_ARGS)
_APACHE_ARGS=		${APACHE_DEFAULT}
.	endif
# _APACHE_ARGS must now contain a version(-range)
.	if !empty(_APACHE_ARGS:C/^2\.[0-9]//:S/^-//:C/^2\.[0-9]//:C/\+$//) 
IGNORE= ${_ERROR_MSG} Illegal use of USES= ${USES:Mapache*}
# Catch USES= apache:[min]-[max]+
.	elif ${apache_ARGS:C/[.a-z0-9]//g} == "-+"
IGNORE= ${_ERROR_MSG} Illegal use of USES= ${USES:Mapache*}
.	endif
.endif # defined(apache_ARGS)

# The port does not specify a build, run or server dependency, assume both
# build and run are required.
.if !defined(_APACHE_BUILD_DEP) && !defined(_APACHE_RUN_DEP) && \
	!defined(_APACHE_PORT_IS_SERVER)
_APACHE_BUILD_DEP=	yes
_APACHE_RUN_DEP=	yes
.endif

.if defined(DEFAULT_APACHE_VER)
IGNORE+=	"DEFAULT_APACHE_VER is defined, consider using DEFAULT_VERSIONS+=apache=${DEFAULT_APACHE_VER} instead"
.endif

.if defined(WITH_MODULES) || defined(WITHOUT_MODULES)
IGNORE=	${_ERROR_MSG} WITH(OUT)_MODULES has been removed, use www_${PORTNAME}_(UN)SET
.endif

# ===============================================================
.if defined(_APACHE_PORT_IS_SERVER)

# Module selection
.for category in ${DEFAULT_MODULES_CATEGORIES}
DEFAULT_MODULES+=	${${category}_MODULES}
.endfor

.for category in ${ALL_MODULES_CATEGORIES}
AVAILABLE_MODULES+=	${${category}_MODULES}
.endfor

# OPTIONS handling
.for module in ${AVAILABLE_MODULES}
.	if ${PORT_OPTIONS:M${module}}
_APACHE_ENABLED_MODS+=	${module}
.	else
_APACHE_DISABLED_MODS+=	${module}
.	endif
.endfor

.if !defined(WITH_STATIC_APACHE)
CONFIGURE_ARGS+=	--enable-so
.else
CONFIGURE_ARGS+=	--disable-so
WITH_ALL_STATIC_MODULES=	yes
.endif

.if ${PORT_OPTIONS:MSUEXEC}
_APACHE_ENABLED_MODS+=	${SUEXEC_MODULES}
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

.if !defined(_APACHE_DISABLED_MODS)
APACHE_MODULES=		${_APACHE_ENABLED_MODS}
.else
.for module in ${_APACHE_ENABLED_MODS:O:u}
.	if !${_APACHE_DISABLED_MODS:M${module}}
APACHE_MODULES+=	${module}
.	endif
.endfor
.endif

.if defined(WITH_STATIC_APACHE) || defined(WITH_ALL_STATIC_MODULES)
WITH_STATIC_MODULES=	${APACHE_MODULES}
.endif

.for module in ${AVAILABLE_MODULES}
.	if !empty(WITH_STATIC_MODULES:M${module})
CONFIGURE_ARGS+=	--enable-${module:tl}=static
PLIST_SUB+=	MOD_${module}="@comment "
.	elif !empty(APACHE_MODULES:M${module})
CONFIGURE_ARGS+=	--enable-${module:tl}=shared
PLIST_SUB+=	MOD_${module}=""
.	else
CONFIGURE_ARGS+=	--disable-${module:tl}
PLIST_SUB+=	MOD_${module}="@comment "
.	endif
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

#### End of _APACHE_PORT_IS_SERVER ####

# ===============================================================
.else
HTTPD?=		${LOCALBASE}/sbin/httpd

MODULENAME?=	${PORTNAME}
SHORTMODNAME?=	${MODULENAME:S/mod_//}
SRC_FILE?=	${MODULENAME}.c

.if exists(${HTTPD})
_APACHE_VERSION!=	${HTTPD} -v | ${SED} -ne 's/^Server version: Apache\/\([1-9]\.[0-9]*\).*/\1/p'
.endif

# Validate Apache version whether it meets the version restriction.
_APACHE_VERSION_CHECK:=		${_APACHE_ARGS:C/^([1-9]\.[0-9])$/\1-\1/}
_APACHE_VERSION_MIN_TMP:=	${_APACHE_VERSION_CHECK:C/([1-9]\.[0-9])[-+].*/\1/}
_APACHE_VERSION_MIN:=		${_APACHE_VERSION_MIN_TMP:M[1-9].[0-9]}
_APACHE_VERSION_MAX_TMP:=	${_APACHE_VERSION_CHECK:C/.*-([1-9]\.[0-9])/\1/}
_APACHE_VERSION_MAX:=		${_APACHE_VERSION_MAX_TMP:M[1-9].[0-9]}

# Remove from _WANTED_VERSIONS that which is not wanted
_APACHE_WANTED_VERSIONS=	${_APACHE_SUPPORTED_VERSIONS}
.for _ver in ${_APACHE_SUPPORTED_VERSIONS:O}
.	if !empty(_APACHE_VERSION_MIN) && ${_ver} < ${_APACHE_VERSION_MIN}
_APACHE_WANTED_VERSIONS:=	${_APACHE_WANTED_VERSIONS:N${_ver}}
.	endif
.	if !empty(_APACHE_VERSION_MAX) && ${_ver} > ${_APACHE_VERSION_MAX}
_APACHE_WANTED_VERSIONS:=	${_APACHE_WANTED_VERSIONS:N${_ver}}		
.	endif
.endfor

# Check if installed Apache version matches a wanted version
.if defined(_APACHE_VERSION) && $(_APACHE_WANTED_VERSIONS:M${_APACHE_VERSION})
_APACHE_WANTED_VERSION=	${_APACHE_VERSION}
.endif
# Select Apache version if not already set
.for _ver in ${APACHE_DEFAULT} ${_APACHE_SUPPORTED_VERSIONS}
.	if !defined(_APACHE_WANTED_VERSION) && ${_APACHE_WANTED_VERSIONS:M${_ver}}
_APACHE_WANTED_VERSION=	${_ver}
.	endif
.endfor

APACHE_VERSION:=	${_APACHE_WANTED_VERSION}

.if defined(_APACHE_VERSION) && ${_APACHE_VERSION} != ${APACHE_VERSION}
BROKEN=	${_ERROR_MSG} Apache ${_APACHE_VERSION} is installed and port requires ${_APACHE_WANTED_VERSION}
.endif

.if ${APACHE_VERSION} >= 2.5
APXS?=	${LOCALBASE}/bin/apxs
.else
APXS?=	${LOCALBASE}/sbin/apxs
.endif

.if exists(${APXS})
APXS_PREFIX!=	${APXS} -q prefix 2> /dev/null || echo NULL
.	if ${APXS_PREFIX} == NULL
IGNORE=	: Your apache does not support DSO modules
.	endif
.	if defined(AP_GENPLIST) && ${APXS_PREFIX} != ${PREFIX}
IGNORE?=	PREFIX must be equal to APXS_PREFIX.
.	endif
.endif

APACHEMODDIR=		libexec/apache${APACHE_VERSION:S/.//}
APACHEINCLUDEDIR=	include/apache${APACHE_VERSION:S/.//}
APACHEETCDIR=		etc/apache${APACHE_VERSION:S/.//}
.if ${APACHE_VERSION} == 2.5
APACHE_PORT?=		www/apache${APACHE_VERSION:S/.//}-devel
.else
APACHE_PORT?=		www/apache${APACHE_VERSION:S/.//}
.endif

PLIST_SUB+=	APACHEMODDIR="${APACHEMODDIR}" \
		APACHEINCLUDEDIR="${APACHEINCLUDEDIR}" \
		APACHEETCDIR="${APACHEETCDIR}" \
		APACHE_VERSION="${APACHE_VERSION}"

SUB_LIST+=	APACHEMODDIR="${APACHEMODDIR}" \
		APACHEETCDIR="${APACHEETCDIR}" \
		APACHE_VERSION="${APACHE_VERSION}"

APACHE_PKGNAMEPREFIX=	ap${APACHE_VERSION:S/.//}-

.if defined(AP_FAST_BUILD)
PKGNAMEPREFIX?=	${APACHE_PKGNAMEPREFIX}
.endif

.if defined(_APACHE_BUILD_DEP)
BUILD_DEPENDS+=	${APXS}:${APACHE_PORT}
.endif

.if defined(_APACHE_RUN_DEP)
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

.endif # End of _APACHE_PORT_IS_SERVER / _APACHE_PORT_IS_MOULE
.endif # End of !_INCLUDE_USES_APACHE_PRE_MK

# ===============================================================
.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_APACHE_POST_MK)
_INCLUDE_USES_APACHE_POST_MK=	apache.mk
.if defined(NO_BUILD) && !defined(_APACHE_RUN_DEP)
BROKEN=	If NO_BUILD is used, then apache:run is sufficient. Please fix your Makefile
.endif

.if defined(_APACHE_PORT_IS_SERVER)
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

.else

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
.endif          # defined(_APACHE_PORT_IS_SERVER / _APACHE_PORT_IS_MODULE)
.endif          # defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_APACHE_PRE_MK)
