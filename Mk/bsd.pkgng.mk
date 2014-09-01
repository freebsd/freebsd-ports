# $FreeBSD$
#

.if defined(_POSTMKINCLUDED)
PKGNG_Include_MAINTAINER=	portmgr@FreeBSD.org

METADIR=		${WRKDIR}/.metadir
MANIFESTF=		${METADIR}/+MANIFEST

PKGPREINSTALL?=		${PKGDIR}/pkg-pre-install
PKGPOSTINSTALL?=	${PKGDIR}/pkg-post-install
PKGPREDEINSTALL?=	${PKGDIR}/pkg-pre-deinstall
PKGPOSTDEINSTALL?=	${PKGDIR}/pkg-post-deinstall
PKGPREUPGRADE?=		${PKGDIR}/pkg-pre-upgrade
PKGPOSTUPGRADE?=	${PKGDIR}/pkg-post-upgrade
PKGUPGRADE?=		${PKGDIR}/pkg-upgrade
_FORCE_POST_PATTERNS=	rmdir kldxref mkfontscale mkfontdir fc-cache \
						fonts.dir fonts.scale gtk-update-icon-cache \
						gio-querymodules \
						gtk-query-immodules \
						ldconfig \
						load-octave-pkg \
						ocamlfind \
						update-desktop-database update-mime-database \
						gdk-pixbuf-query-loaders catalog.ports \
						glib-compile-schemas \
						ccache-update-links

PLIST_REINPLACE:=	${PLIST_REINPLACE:Ndirrmtry}
PLIST_REINPLACE:=	${PLIST_REINPLACE:Nstopdaemon}

ACTUAL-PACKAGE-DEPENDS?= \
	if [ "${_LIB_RUN_DEPENDS}" != "  " ]; then \
		${PKG_QUERY} "\"%n\": {origin: %o, version: \"%v\"}" " " ${_LIB_RUN_DEPENDS:C,[^:]*:([^:]*):?.*,\1,:C,${PORTSDIR}/,,} 2>/dev/null || : ; \
	fi

create-manifest:
	@${MKDIR} ${METADIR}; \
	(\
		echo "name: \"${PKGBASE}\"" ; \
		echo "version: \"${PKGVERSION}\"" ; \
		echo "origin: ${PKGORIGIN}" ; \
		echo "comment: <<EOD" ; \
		echo ${COMMENT:Q} ; \
		echo "EOD" ; \
		echo "maintainer: ${MAINTAINER}" ; \
		echo "prefix: ${PREFIX}" ; \
		[ -z "${WWW}" ] || echo "www: ${WWW}" ; \
		echo "deps: { "; \
		${ACTUAL-PACKAGE-DEPENDS} | ${GREP} -v -E ${PKG_IGNORE_DEPENDS} | ${SORT} -u ; \
		echo "}" ; \
		echo "categories: [ ${CATEGORIES:u:S/$/,/} ]" ; \
		l=${LICENSE_COMB} ; \
		[ -n "${NO_ARCH}" ] && echo "arch : `${PKG_BIN} config abi | ${CUT} -d: -f1,2`:*" ; \
		echo "licenselogic: $${l:-single}" ; \
		[ -z "${LICENSE}" ] || echo "licenses: [ ${LICENSE:u:S/$/,/} ]" ; \
		[ -z "${USERS}" ] || echo "users: [ ${USERS:u:S/$/,/} ]" ; \
		[ -z "${GROUPS}" ] || echo "groups: [ ${GROUPS:u:S/$/,/} ]" ; \
	) > ${MANIFESTF}
	@${ECHO_CMD} -n "options: {" >> ${MANIFESTF}
.for opt in ${COMPLETE_OPTIONS_LIST}
	@[ -z "${PORT_OPTIONS:M${opt}}" ] || match="on" ; ${ECHO_MSG} -n " ${opt}: $${match:-off}," >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} "}" >> ${MANIFESTF}
.if defined(PKG_NOTES)
	@${ECHO_CMD} -n "annotations: {" >> ${MANIFESTF}
.for note in ${PKG_NOTES}
	@${ECHO_CMD} -n ' ${note}: "${PKG_NOTE_${note}:S/"/\"/g}",' >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} " }" >> ${MANIFESTF}
.endif
	@[ -f ${PKGINSTALL} ] && ${CP} ${PKGINSTALL} ${METADIR}/+INSTALL; \
	${RM} -f ${METADIR}/+PRE_INSTALL ; \
	for a in ${PKGPREINSTALL}; do \
		[ -f $$a ] && ${CAT} $$a >> ${METADIR}/+PRE_INSTALL ; \
	done ; \
	${RM} -f ${METADIR}/+POST_INSTALL ; \
	for a in ${PKGPOSTINSTALL}; do \
		[ -f $$a ] && ${CAT} $$a >> ${METADIR}/+POST_INSTALL ; \
	done ; \
	[ -f ${PKGDEINSTALL} ] && ${CP} ${PKGDEINSTALL} ${METADIR}/+DEINSTALL; \
	${RM} -f ${METADIR}/+PRE_DEINSTALL ; \
	for a in ${PKGPREDEINSTALL}; do \
		[ -f $$a ] && ${CAT} $$a >> ${METADIR}/+PRE_DEINSTALL ; \
	done ; \
	${RM} -f ${METADIR}/+POST_DEINSTALL ; \
	for a in ${PKGPOSTDEINSTALL}; do \
		[ -f $$a ] && ${CAT} $$a >> ${METADIR}/+POST_DEINSTALL ; \
	done ; \
	[ -f ${PKGPOSTDEINSTALL} ] && ${CP} ${PKGPOSTDEINSTALL} ${METADIR}/+POST_DEINSTALL; \
	[ -f ${PKGUPGRADE} ] && ${CP} ${PKGUPGRADE} ${METADIR}/+UPGRADE; \
	[ -f ${PKGPREUPGRADE} ] && ${CP} ${PKGPREUPGRADE} ${METADIR}/+PRE_UPGRADE; \
	[ -f ${PKGPOSTUPGRADE} ] && ${CP} ${PKGPOSTUPGRADE} ${METADIR}/+POST_UPGRADE; \
	${CP} ${DESCR} ${METADIR}/+DESC; \
	[ -f ${PKGMESSAGE} ] && ${CP} ${PKGMESSAGE} ${METADIR}/+DISPLAY || return 0
.if !defined(NO_MTREE)
	@[ -f ${MTREE_FILE} ] && ${CP} ${MTREE_FILE} ${METADIR}/+MTREE_DIRS || return 0
.endif


.if !target(fake-pkg)
STAGE_ARGS=		-i ${STAGEDIR}

.if !defined(NO_PKG_REGISTER)
fake-pkg: create-manifest
.if defined(INSTALLS_DEPENDS)
	@${ECHO_MSG} "===>   Registering installation for ${PKGNAME} as automatic"
.else
	@${ECHO_MSG} "===>   Registering installation for ${PKGNAME}"
.endif
.if defined(INSTALLS_DEPENDS)
	@${SETENV} ${PKG_ENV} FORCE_POST="${_FORCE_POST_PATTERNS}" ${PKG_CMD} -d ${STAGE_ARGS} -m ${METADIR} -f ${TMPPLIST}
.else
	@${SETENV} ${PKG_ENV} FORCE_POST="${_FORCE_POST_PATTERNS}" ${PKG_CMD} ${STAGE_ARGS} -m ${METADIR} -f ${TMPPLIST}
.endif
	@${RM} -rf ${METADIR}
.endif
.endif

.if !target(check-build-conflicts)
check-build-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_BUILD) ) && !defined(DISABLE_CONFLICTS) && !defined(DEFER_CONFLICTS_CHECK)
	@conflicts_with=$$( \
	{ ${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} 2>/dev/null || : ; } \
		| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			${ECHO_CMD} -n " $${pkgname}"; \
		fi; \
	done); \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They will not build together."; \
		${ECHO_MSG} "      Please remove them first with pkg delete."; \
		exit 1;\
	fi
.endif
.endif

.if !target(identify-install-conflicts)
identify-install-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_INSTALL) ) && !defined(DISABLE_CONFLICTS)
	@conflicts_with=$$( \
	{ ${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null || : ; } \
		| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			${ECHO_CMD} -n " $${pkgname}"; \
		fi; \
	done); \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      You may want to stop build with Ctrl + C."; \
		sleep 10; \
	fi
.endif
.endif

.if !target(check-install-conflicts)
check-install-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_INSTALL) || ( defined(CONFLICTS_BUILD) && defined(DEFER_CONFLICTS_CHECK) ) ) && !defined(DISABLE_CONFLICTS) 
.if defined(DEFER_CONFLICTS_CHECK)
	@conflicts_with=$$( \
	{ ${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null || : ; } \
	       	| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			${ECHO_CMD} -n " $${pkgname}"; \
		fi; \
	done); \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      Please remove them first with pkg delete."; \
		exit 1; \
	fi
.else
	@conflicts_with=$$( \
	{ ${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} 2>/dev/null || : ; } \
	       	| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			${ECHO_CMD} -n " $${pkgname}"; \
		fi; \
	done); \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      Please remove them first with pkg delete."; \
		exit 1; \
	fi
.endif # defined(DEFER_CONFLICTS_CHECK)
.endif
.endif

.if !target(do-package)
PKG_CREATE_ARGS=	-r ${STAGEDIR} -m ${METADIR} -p ${TMPPLIST}
do-package: create-manifest
do-package: ${TMPPLIST}
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} "=> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi
	@for cat in ${CATEGORIES}; do \
		${RM} -f ${PACKAGES}/$$cat/${PKGNAMEPREFIX}${PORTNAME}*${PKG_SUFX} ; \
	done
	@${MKDIR} ${WRKDIR}/pkg
	@if ${SETENV} ${PKG_ENV} FORCE_POST="${_FORCE_POST_PATTERNS}" ${PKG_CREATE} ${PKG_CREATE_ARGS} -f ${PKG_SUFX:S/.//} -o ${WRKDIR}/pkg ${PKGNAME}; then \
		if [ -d ${PKGREPOSITORY} -a -w ${PKGREPOSITORY} ]; then \
			${LN} -f ${WRKDIR}/pkg/${PKGNAME}${PKG_SUFX} ${PKGFILE} 2>/dev/null \
				|| ${CP} -af ${WRKDIR}/pkg/${PKGNAME}${PKG_SUFX} ${PKGFILE}; \
			if [ "${PKGORIGIN}" = "ports-mgmt/pkg" -o "${PKGORIGIN}" = "ports-mgmt/pkg-devel" ]; then \
				if [ ! -d ${PKGLATESTREPOSITORY} ]; then \
					if ! ${MKDIR} ${PKGLATESTREPOSITORY}; then \
						${ECHO_MSG} "=> Can't create directory ${PKGLATESTREPOSITORY}."; \
						exit 1; \
					fi; \
				fi ; \
				${LN} -sf ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PKGLATESTFILE} ; \
			fi; \
		fi; \
	else \
		cd ${.CURDIR} && eval ${MAKE} delete-package >/dev/null; \
		exit 1; \
	fi
.endif

.if !target(check-already-installed)
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
check-already-installed:
		@${ECHO_MSG} "===>  Checking if ${PKGBASE} already installed"; \
		pkgname=`${PKG_INFO} -q -O ${PKGBASE}`; \
		if [ -n "$${pkgname}" ]; then \
			v=`${PKG_VERSION} -t $${pkgname} ${PKGNAME}`; \
			if [ "$${v}" = "<" ]; then \
				${ECHO_CMD} "===>   An older version of ${PKGBASE} is already installed ($${pkgname})"; \
			else \
				${ECHO_CMD} "===>   ${PKGNAME} is already installed"; \
			fi; \
			${ECHO_MSG} "      You may wish to \`\`make deinstall'' and install this port again"; \
			${ECHO_MSG} "      by \`\`make reinstall'' to upgrade it properly."; \
			${ECHO_MSG} "      If you really wish to overwrite the old port of ${PKGBASE}"; \
			${ECHO_MSG} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
			${ECHO_MSG} "      in your environment or the \"make install\" command line."; \
			exit 1; \
		fi
.endif
.endif


.if !target(deinstall)
deinstall:
.if defined(UID) && ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@${ECHO_MSG} "===>  Deinstalling for ${PKGBASE}"
	@if ${PKG_INFO} -e ${PKGBASE}; then \
		p=`${PKG_INFO} -q -O ${PKGBASE}`; \
		${ECHO_MSG} "===>   Deinstalling $${p}"; \
		${PKG_DELETE} -f ${PKGBASE} ; \
	else \
		${ECHO_MSG} "===>   ${PKGBASE} not installed, skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif
.endif

.endif # defined(_POSTMKINCLUDED)
