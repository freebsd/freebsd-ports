#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.apache.mk - Apache related macros.
# Author: Clement Laforet <clement@FreeBSD.org>
# Author: Olli Hauer <ohauer@FreeBSD.org>
#
# Please view me with 4 column tabs!

# =========================================================================
# Parameter APACHE_PORT (user controlled):
#
# The parameter APACHE_PORT can be used in /etc/make.conf to
# overwrite the default apache port.
#
# This parameter should never be used in the Makefile of a port!
#
# Example entry in /etc/make.conf:
#  APACHE_PORT=	www/apache22
#
# To get a list of "possible" valid values execute the command:
#  $> egrep 'apache[12]' ports/www/Makefile | awk '{print "www/" $3}'
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
#  USE_APACHE= 20+      # specify [min] version, no [max] version
#  USE_APACHE= 20-22    # specify [min]-[max] range
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
#      USE_APACHE= common20, and common22
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

DEFAULT_APACHE_VERSION=		22
APACHE_SUPPORTED_VERSION=	22 20 # preferred version first

# Print warnings
_ERROR_MSG=	: Error from bsd.apache.mk.

# Important Note:
#  Keep apache version in ascending order!
#  The "+" sign is only valid as last sign, not between
#  two versions or in combination with range!
.if defined(USE_APACHE) && !empty(USE_APACHE)
.	if ${USE_APACHE:Mcommon*} != ""
AP_PORT_IS_SERVER=	YES
.	elif ${USE_APACHE:C/\-//:S/^20//:S/^22//:C/\+$//} == ""
AP_PORT_IS_MODULE=	YES
.		if ${USE_APACHE:C/\-//:S/^20//:S/^22//} == "+"
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
# For slave ports:
.if defined(SLAVE_DESIGNED_FOR) && ${PORTVERSION} != ${SLAVE_DESIGNED_FOR}
IGNORE=	Sorry, ${SLAVENAME} and ${PORTNAME} versions are out of sync ${PORTVERSION} != ${SLAVE_DESIGNED_FOR}
.endif

# used by www/cakeph* ports
.if defined(SLAVE_PORT_MODULES)
DEFAULT_MODULES_CATEGORIES+=	SLAVE_PORT
ALL_MODULES_CATEGORIES+=		SLAVE_PORT
.endif

# Module selection
.for category in ${DEFAULT_MODULES_CATEGORIES}
DEFAULT_MODULES+=			${${category}_MODULES}
WITH_${category}_MODULES= 	YES
.endfor

.for category in ${ALL_MODULES_CATEGORIES}
AVAILABLE_MODULES+=			${${category}_MODULES}
.endfor

# Setting "@comment " as default.
.for module in ${AVAILABLE_MODULES}
${module}_PLIST_SUB=		"@comment "
.endfor

# Configure
# dirty hacks to make sure all modules are disabled before we select them
.if ${USE_APACHE} == common20
CONFIGURE_ARGS+=	--disable-access --disable-auth \
			--disable-charset-lite --disable-include \
			--disable-log-config --disable-env --disable-setenvif \
			--disable-mime --disable-status --disable-autoindex \
			--disable-asis --disable-cgid --disable-cgi \
			--disable-negotiation --disable-dir --disable-imap \
			--disable-actions --disable-userdir --disable-alias
.elif ${USE_APACHE} == common22
CONFIGURE_ARGS+=	--disable-authn-file --disable-authn-default \
			--disable-authz-host --disable-authz-groupfile \
			--disable-authz-user --disable-authz-default \
			--disable-auth-basic --disable-charset-lite \
			--disable-include --disable-log-config --disable-env \
			--disable-setenvif --disable-mime --disable-status \
			--disable-autoindex --disable-asis --disable-cgid \
			--disable-cgi --disable-negotiation --disable-dir \
			--disable-imagemap --disable-actions --disable-userdir \
			--disable-alias --disable-filter --disable-substitute \
			--disable-proxy --disable-proxy-connect \
			--disable-proxy-ftp --disable-proxy-http \
			--disable-proxy-ajp --disable-proxy-balancer \
			--disable-proxy-scgi --disable-reqtimeout
.endif

.if defined(OPTIONS) && !(make(make-options-list))
.for module in ${AVAILABLE_MODULES}
.	if defined(WITH_${module:U})
_APACHE_MODULES+=	${module}
.	endif
.	if defined(WITHOUT_${module:U})
WITHOUT_MODULES+=	 ${module}
.	endif
.endfor
.elif defined(WITH_MODULES)
_APACHE_MODULES+=	${WITH_MODULES}
.else
.for category in ${ALL_MODULES_CATEGORIES}
.	if defined (WITHOUT_${category}_MODULES) || defined (WITH_CUSTOM_${category})
.		if defined(WITH_${category}_MODULES})
.			undef WITH_${category}_MODULES
.		endif
.		if defined (WITH_CUSTOM_${category})
_APACHE_MODULES+=	${WITH_CUSTOM_${category}}
.		endif
.	elif defined(WITH_${category}_MODULES)
_APACHE_MODULES+=	${${category}_MODULES}
.	endif
.endfor
.if defined(WITH_EXTRA_MODULES)
_APACHE_MODULES+=	${WITH_EXTRA_MODULES}
.endif
.endif

.if !defined(WITH_STATIC_APACHE)
.	if ${USE_APACHE:Mcommon2*} != ""
# FYI
#DYNAMIC_MODULES=	so
CONFIGURE_ARGS+=	--enable-so
.	endif
.else
.	if ${USE_APACHE:Mcommon2*} != ""
CONFIGURE_ARGS+=	--disable-so
.	endif
WITH_ALL_STATIC_MODULES=	YES
.endif

.if defined(WITH_SUEXEC) || defined(WITH_SUEXEC_MODULES)
.	if ${USE_APACHE:Mcommon2*} != ""
_APACHE_MODULES+=		${SUEXEC_MODULES}
SUEXEC_CONFARGS=	with-suexec
.	endif

# From now we're defaulting to apache 2.*
SUEXEC_DOCROOT?=		${PREFIX}/www/data
SUEXEC_USERDIR?=		public_html
SUEXEC_SAFEPATH?=		${PREFIX}/bin:${LOCALBASE}/bin:/usr/bin:/bin
SUEXEC_LOGFILE?=		/var/log/httpd-suexec.log
SUEXEC_UIDMIN?=			1000
SUEXEC_GIDMIN?=			1000
SUEXEC_CALLER?=			${WWWOWN}
CONFIGURE_ARGS+=		--${SUEXEC_CONFARGS}-caller=${SUEXEC_CALLER} \
				--${SUEXEC_CONFARGS}-uidmin=${SUEXEC_UIDMIN} \
				--${SUEXEC_CONFARGS}-gidmin=${SUEXEC_GIDMIN} \
				--${SUEXEC_CONFARGS}-userdir="${SUEXEC_USERDIR}" \
				--${SUEXEC_CONFARGS}-docroot="${SUEXEC_DOCROOT}" \
				--${SUEXEC_CONFARGS}-safepath="${SUEXEC_SAFEPATH}" \
				--${SUEXEC_CONFARGS}-logfile="${SUEXEC_LOGFILE}"
.	if ${USE_APACHE:Mcommon2*} != ""
CONFIGURE_ARGS+=	--${SUEXEC_CONFARGS}-bin="${PREFIX}/sbin/suexec"
.	endif

.	if defined(WITH_SUEXEC_UMASK)
CONFIGURE_ARGS+=		--${SUEXEC_CONFARGS}-umask=${SUEXEC_UMASK}
.	endif
.endif

.if !defined(WITHOUT_MODULES)
APACHE_MODULES=		${_APACHE_MODULES}
.else
APACHE_MODULES!=	\
			for module in ${_APACHE_MODULES}; do \
				${ECHO_CMD} ${WITHOUT_MODULES} | ${GREP} -wq $${module} 2> /dev/null || \
				${ECHO_CMD} $${module}; \
			done
.endif

.if defined(WITH_STATIC_MODULES)
STATIC_MODULE_CONFARG=	--enable-$${module}
DSO_MODULE_CONFARG=		--enable-$${module}=shared
_CONFIGURE_ARGS!=	\
			for module in ${APACHE_MODULES} ; do \
				${ECHO_CMD} ${WITH_STATIC_MODULES} | \
					${GREP} -wq $${module} 2> /dev/null ; \
				if [ "$${?}" = "0" ] ; then \
						${ECHO_CMD} "${STATIC_MODULE_CONFARG}"; \
					else \
						${ECHO_CMD} "${DSO_MODULE_CONFARG}"; \
					fi; done
CONFIGURE_ARGS+=	${_CONFIGURE_ARGS}
.elif defined(WITH_STATIC_APACHE) || defined(WITH_ALL_STATIC_MODULES)
WITH_STATIC_MODULES=	${APACHE_MODULES}
CONFIGURE_ARGS+=	--enable-modules="${APACHE_MODULES}"
.else
CONFIGURE_ARGS+=	--enable-mods-shared="${APACHE_MODULES}"
.endif

.if defined(WITH_STATIC_MODULES)
_SHARED_MODULES!=	\
			for module in ${APACHE_MODULES} ; do \
				${ECHO_CMD} ${WITH_STATIC_MODULES} | ${GREP} -wq $${module} 2> /dev/null || \
				${ECHO_CMD} $${module}; \
			done
SHARED_MODULES=		${_SHARED_MODULES}
.elif !defined(WITH_ALL_STATIC_MODULES)
SHARED_MODULES=		${APACHE_MODULES}
.endif

.for module in ${SHARED_MODULES}
${module}_PLIST_SUB=	""
.endfor

.for module in ${AVAILABLE_MODULES}
PLIST_SUB+=	MOD_${module:U}=${${module}_PLIST_SUB}
.endfor
#### End of AP_PORT_IS_SERVER ####

# ===============================================================
.elif defined(AP_PORT_IS_MODULE) || defined(USE_APACHE_RUN) || defined(USE_APACHE_BUILD)
APXS?=		${LOCALBASE}/sbin/apxs
HTTPD?=		${LOCALBASE}/sbin/httpd

MODULENAME?=	${PORTNAME}
SHORTMODNAME?=	${MODULENAME:S/mod_//}
SRC_FILE?=	${MODULENAME}.c

.if exists(${HTTPD})
_APACHE_VERSION!=	${HTTPD} -V | ${SED} -ne 's/^Server version: Apache\/\([0-9]\)\.\([0-9]*\).*/\1\2/p'
# Apache 2.4 and onwards doesn't require linking the MPM module
# directly in the httpd binary anymore. APXS lost the MPM_NAME query,
# so we can't assume a given MPM anymore.
.	if ${_APACHE_VERSION} <= 22
APACHE_MPM!=		${APXS} -q MPM_NAME
.	endif
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

_APACHE_VERSION_CHECK:=			${_USE_APACHE:C/^([1-9][0-9])$/\1-\1/}
_APACHE_VERSION_MINIMUM_TMP:=	${_APACHE_VERSION_CHECK:C/([1-9][0-9])[-+].*/\1/}
_APACHE_VERSION_MINIMUM:=		${_APACHE_VERSION_MINIMUM_TMP:M[1-9][0-9]}
_APACHE_VERSION_MAXIMUM_TMP:=	${_APACHE_VERSION_CHECK:C/.*-([1-9][0-9])/\1/}
_APACHE_VERSION_MAXIMUM:=		${_APACHE_VERSION_MAXIMUM_TMP:M[1-9][0-9]}

.if defined(_APACHE_VERSION)
# Validate Apache version whether it meets USE_APACHE version restriction.
.	if !empty(_APACHE_VERSION_MINIMUM) && (${_APACHE_VERSION} < ${_APACHE_VERSION_MINIMUM})
_APACHE_VERSION_NONSUPPORTED=	${_APACHE_VERSION_MINIMUM} at least
.	elif !empty(_APACHE_VERSION_MAXIMUM) && (${_APACHE_VERSION} > ${_APACHE_VERSION_MAXIMUM})
_APACHE_VERSION_NONSUPPORTED=	${_APACHE_VERSION_MAXIMUM} at most
.	endif

.	if defined(_APACHE_VERSION_NONSUPPORTED) && !defined(AP_IGNORE_VERSION_CHECK)
IGNORE=	${_ERROR_MSG} apache${_APACHE_VERSION} is installed (or APACHE_PORT is defined) and port requires apache${_APACHE_VERSION_NONSUPPORTED}
.	 endif
.else 		# defined(_APACHE_VERSION)
.	for ver in ${APACHE_SUPPORTED_VERSION}
__VER=	${ver}
.		if !defined(_APACHE_VERSION) && \
			!(!empty(_APACHE_VERSION_MINIMUM) && ( ${__VER} < ${_APACHE_VERSION_MINIMUM} )) && \
			!(!empty(_APACHE_VERSION_MAXIMUM) && ( ${__VER} > ${_APACHE_VERSION_MAXIMUM} ))
_APACHE_VERSION=	${ver}
.		endif
.	endfor
.endif 		# defined(_APACHE_VERSION)

APACHE_VERSION:=	${_APACHE_VERSION}

.if exists(${APXS})
APXS_PREFIX!=	${APXS} -q prefix 2> /dev/null || echo NULL
.	if ${APXS_PREFIX} == NULL
IGNORE=	: Your apache does not support DSO modules
.	endif
.	if defined(AP_GENPLIST) && ${APXS_PREFIX} != ${PREFIX}
IGNORE?=	PREFIX must be equal to APXS_PREFIX.
.	endif
.endif

.if ${APACHE_VERSION} == 20
AP_BUILDEXT=	la
APACHEMODDIR=	libexec/apache2
APACHEINCLUDEDIR=include/apache2
APACHEETCDIR=	etc/apache2
APACHE_PORT?=	www/apache${APACHE_VERSION}
.elif ${APACHE_VERSION} >= 22
AP_BUILDEXT=	la
APACHEMODDIR=	libexec/apache${APACHE_VERSION}
APACHEINCLUDEDIR=include/apache${APACHE_VERSION}
APACHEETCDIR=	etc/apache${APACHE_VERSION}
APACHE_PORT?=	www/apache${APACHE_VERSION}
.endif

PLIST_SUB+=	APACHEMODDIR="${APACHEMODDIR}" \
		APACHEINCLUDEDIR="${APACHEINCLUDEDIR}" \
		APACHEETCDIR="${APACHEETCDIR}"

APACHE_PKGNAMEPREFIX=	ap${APACHE_VERSION}-
.if defined(AP_FAST_BUILD)
PKGNAMEPREFIX?=	${APACHE_PKGNAMEPREFIX}
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_BUILD)
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
.endif

.if defined(USE_APACHE) || defined(USE_APACHE_RUN)
RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
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
.	if ${USE_APACHE_RUN:C/\-//:S/^20//:S/^22//:C/\+$//} != ""
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_RUN ( ${USE_APACHE_RUN} )
.	endif
.elif defined(USE_APACHE_RUN)
IGNORE=	${_ERROR_MSG} Illegal use of USE_APACHE_RUN ( no valid version specified )
.endif

.if defined(USE_APACHE_BUILD) && !empty(USE_APACHE_BUILD)
.	if ${USE_APACHE_BUILD:C/\-//:S/^20//:S/^22//:C/\+$//} != ""
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

.if !target(show-categories)
show-categories:
.for category in ${ALL_MODULES_CATEGORIES}
	@${ECHO_MSG} "${category} contains these modules:"
	@${ECHO_MSG} "  ${${category}_MODULES}"
.endfor
.endif

.if !target(show-modules)
show-modules:
	@for module in ${AVAILABLE_MODULES} ; do \
	${ECHO_MSG} -n "$${module}: "; \
	if ${ECHO_CMD} ${APACHE_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; \
	then \
		${ECHO_CMD} -n "enabled "; \
			if ${ECHO_CMD} ${WITH_STATIC_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; then \
				${ECHO_CMD} "(static)" ; \
			else \
				${ECHO_CMD} "(shared)" ;\
			fi;\
	else \
		${ECHO_CMD} disabled ;\
	fi;\
	done
.endif

.if !target(make-options-list)
make-options-list:
	@${ECHO_CMD} OPTIONS+= \\;
	@for module in ${AVAILABLE_MODULES} ; do \
	if ${ECHO_CMD} ${APACHE_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; \
	then \
		${PRINTF} "\t `${ECHO_CMD} $${module} | ${TR} '[:lower:]' '[:upper:]'` \"Enable mod_$${module}\" ON \\"; \
		${ECHO_CMD}; \
	else \
		${PRINTF} "\t `${ECHO_CMD} $${module} | ${TR} '[:lower:]' '[:upper:]'` \"Enable mod_$${module}\" OFF \\";\
		${ECHO_CMD}; \
	fi;\
	done; \
	${ECHO_CMD};
.endif

.elif defined(AP_PORT_IS_MODULE)

.if defined(AP_FAST_BUILD)
.if !target(ap-gen-plist)
ap-gen-plist:
.if defined(AP_GENPLIST)
.	if !exists(${PLIST})
	@${ECHO} "===>  Generating apache plist"
# apache22/20
	@${ECHO} "@unexec ${SED} -i '' -E '/LoadModule[[:blank:]]+%%AP_NAME%%_module/d' %D/%%APACHEETCDIR%%/httpd.conf" >> ${PLIST}
	@${ECHO} "%%APACHEMODDIR%%/%%AP_MODULE%%" >> ${PLIST}
	@${ECHO} "@exec %D/sbin/apxs -e -A -n %%AP_NAME%% %D/%F" >> ${PLIST}
	@${ECHO} "@unexec echo \"Don't forget to remove all ${MODULENAME}-related directives in your httpd.conf\"">> ${PLIST}
.	endif
.else
	@${DO_NADA}
.endif
.endif

.if !target(do-build)
do-build: ap-gen-plist
	@cd ${WRKSRC} && ${APXS} -c ${AP_EXTRAS} -o ${MODULENAME}.${AP_BUILDEXT} ${SRC_FILE}
.endif

.if !target(do-install)
do-install:
	@${APXS} -i -A -n ${SHORTMODNAME} ${WRKSRC}/${MODULENAME}.${AP_BUILDEXT}
.endif
.endif
.endif
.endif          # defined(_POSTMKINCLUDED) && !defined(Apache_Post_Include)
