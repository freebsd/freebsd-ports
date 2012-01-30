#-*- mode: Makefile: tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
PKGNG_MAINTAINER=	portmgr@FreeBSD.org

PKG_BIN?=		${LOCALBASE}/sbin/pkg
PKG_CMD=		${PKG_BIN} register
PKG_DELETE=		${PKG_BIN} delete -y
PKG_INFO=		${PKG_BIN} info -g
PKG_VERSION=		${PKG_BIN} version
PKG_CREATE=		${PKG_BIN} create
PKG_ADD=		${PKG_BIN} add
PKG_QUERY=		${PKG_BIN} query

PKG_SUFX=		.txz

METADIR=		${WRKDIR}/.metadir
MANIFESTF=		${METADIR}/+MANIFEST

PKGPREINSTALL?=		${PKGDIR}/pkg-pre-install
PKGPOSTINSTALL?=	${PKGDIR}/pkg-post-install
PKGPREDEINSTALL?=	${PKGDIR}/pkg-pre-deinstall
PKGPOSTDEINSTALL?=	${PKGDIR}/pkg-post-deinstall
PKGPREUPGRADE?=		${PKGDIR}/pkg-pre-upgrade
PKGPOSTUPGRADE?=	${PKGDIR}/pkg-post-upgrade
PKGUPGRADE?=		${PKGDIR}/pkg-upgrade
PLIST_REINPLACE:=	${PLIST_REINPLACE:Ndirrmtry}
PLIST_REINPLACE:=	${PLIST_REINPLACE:Nstopdaemon}

ACTUAL-PACKAGE-DEPENDS?= \
	if [ "${_LIB_RUN_DEPENDS}" != "  " ]; then \
		${PKG_QUERY} "  %n: {origin: %o, version: \"%v\"}" " " ${_LIB_RUN_DEPENDS:C,[^:]*:([^:]*):?.*,\1,:C,${PORTSDIR}/,,} ; \
		${PKG_QUERY} "  %dn: {origin: %do, version: \"%dv\"}" " " ${_LIB_RUN_DEPENDS:C,[^:]*:([^:]*):?.*,\1,:C,${PORTSDIR}/,,} ; \
	fi


.if !target(fake-pkg)
fake-pkg:
.if !defined(NO_PKG_REGISTER)
	@${ECHO_MSG} "===>   Registering installation for ${PKGNAME}"
	@${MKDIR} ${METADIR}
	@${ECHO_CMD} "name: ${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}" > ${MANIFESTF} 
	@${ECHO_CMD} "version: ${PKGVERSION}" >> ${MANIFESTF} 
	@${ECHO_CMD} "origin: ${PKGORIGIN}" >> ${MANIFESTF} 
	@${ECHO_CMD} "comment: |" >> ${MANIFESTF}
	@${ECHO_CMD} "  "${COMMENT:Q} >> ${MANIFESTF}
	@${ECHO_CMD} "maintainer: ${MAINTAINER}" >> ${MANIFESTF}
	@${ECHO_CMD} "prefix: ${PREFIX}" >> ${MANIFESTF}
.if defined(WWW)
	@${ECHO_CMD} "www: ${WWW}" >> ${MANIFESTF}
.endif
	@${ECHO_CMD} "deps: " >> ${MANIFESTF}

	@${MAKE} -C ${.CURDIR} actual-package-depends | ${GREP} -v -E ${PKG_IGNORE_DEPENDS} | sort -u >> ${MANIFESTF}
	@${ECHO_CMD} -n "categories: [" >> ${MANIFESTF}
.for cat in ${CATEGORIES:u}
	@${ECHO_CMD} -n "${cat}," >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} "]" >> ${MANIFESTF}
.if defined(LICENSE_COMB)
	@${ECHO_CMD} "licenselogic: ${LICENSE_COMB}" >> ${MANIFESTF}
.else
	@${ECHO_CMD} "licenselogic: single" >> ${MANIFESTF}
.endif
	@${ECHO_CMD} -n "licenses: [" >> ${MANIFESTF}
.for lic in ${LICENSE:u}
	@${ECHO_CMD} -n "${lic}," >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} "]" >> ${MANIFESTF}
	@${ECHO_CMD} -n "users: [" >> ${MANIFESTF}
.for user in ${USERS:u}
	@${ECHO_CMD} -n "${user}, " >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} "]" >> ${MANIFESTF}
	@${ECHO_CMD} -n "groups: [" >> ${MANIFESTF}
.for group in ${GROUPS:u}
	@${ECHO_CMD} -n "${group}, " >> ${MANIFESTF}
.endfor
	@${ECHO_CMD} "]" >> ${MANIFESTF}
	@${ECHO_CMD} -n "options: {" >> ${MANIFESTF}
	-@if [ -e ${OPTIONSFILE} ]; then \
		. ${OPTIONSFILE}; \
	fi; \
	set -- ${OPTIONS} XXX; \
	while [ $$# -gt 3 ]; do \
		defaultval=$$3 \
		withvar=WITH_$$1; \
		withoutvar=WITHOUT_$$1; \
		withval=$$(eval ${ECHO_CMD} $$\{$${withvar}\}); \
		withoutval=$$(eval ${ECHO_CMD} $$\{$${withoutvar}\}); \
		if [ ! -z "$${withval}" ]; then \
			val=on; \
		elif [ ! -z "$${withoutval}" ]; then \
			val=off; \
		else \
			val="$${defaultval}"; \
		fi; \
		${ECHO_MSG} -n "$$1: $${val},"; \
		shift 3; \
	done >> ${MANIFESTF}
	@${ECHO_CMD} "}" >> ${MANIFESTF}
	@${CAT} ${MANIFESTF}
	@[ -f ${PKGINSTALL} ] && ${CP} ${PKGINSTALL} ${METADIR}/+INSTALL; \
	[ -f ${PKGPREINSTALL} ] && ${CP} ${PKGPREINSTALL} ${METADIR}/+PRE_INSTALL; \
	[ -f ${PKGPOSTINSTALL} ] && ${CP} ${PKGPOSTINSTALL} ${METADIR}/+POST_INSTALL; \
	[ -f ${PKGDEINSTALL} ] && ${CP} ${PKGDEINSTALL} ${METADIR}/+DEINSTALL; \
	[ -f ${PKGPREDEINSTALL} ] && ${CP} ${PKGPREDEINSTALL} ${METADIR}/+PRE_DEINSTALL; \
	[ -f ${PKGPOSTDEINSTALL} ] && ${CP} ${PKGPOSTDEINSTALL} ${METADIR}/+POST_DEINSTALL; \
	[ -f ${PKGUPGRADE} ] && ${CP} ${PKGUPGRADE} ${METADIR}/+UPGRADE; \
	[ -f ${PKGPREUPGRADE} ] && ${CP} ${PKGPREUPGRADE} ${METADIR}/+PRE_UPGRADE; \
	[ -f ${PKGPOSTUPGRADE} ] && ${CP} ${PKGPOSTUPGRADE} ${METADIR}/+POST_UPGRADE; \
	${CP} ${DESCR} ${METADIR}/+DESC; \
	[ -f ${PKGMESSAGE} ] && ${CP} ${PKGMESSAGE} ${METADIR}/+DISPLAY || return 0
.if !defined(NO_MTREE)
	@[ -f ${MTREE_FILE} ] && ${CP} ${MTREE_FILE} ${METADIR}/+MTREE_DIRS || return 0
.endif
.if defined(INSTALLS_DEPENDS)
	@${PKG_CMD} -d -l -m ${METADIR} -f ${TMPPLIST}
.else
	@${PKG_CMD} -l -m ${METADIR} -f ${TMPPLIST}
.endif
.else
	@${DO_NADA}
.endif
.endif

.if !target(check-build-conflicts)
check-build-conflicts:
.if ( defined(CONFLICTS) || defined(CONFLICTS_BUILD) ) && !defined(DISABLE_CONFLICTS) && !defined(DEFER_CONFLICTS_CHECK)
	@conflicts_with=; \
	${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} \
		| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			conflicts_with="$${conflicts_with} $${pkgname}"; \
		fi; \
	done; \
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
	@conflicts_with=; \
	${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} \
		| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			conflicts_with="$${conflicts_with} $${pkgname}"; \
		fi; \
	done; \
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
	@conflicts_with; \
	${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} \
	       	| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			conflicts_with="$${conflicts_with} $${pkgname}"; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.else
	@conflicts_with=; \
	${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_INSTALL:C/.+/'&'/} \
	       	| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			conflicts_with="$${conflicts_with} $${pkgname}"; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${found}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.endif # defined(DEFER_CONFLICTS_CHECK)
.endif
.endif

.if !target(do-package)
do-package: ${TMPPLIST}
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} "=> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi;
	@if ${PKG_CREATE} -o ${PKGREPOSITORY} ${PKGNAME}; then \
		if [ -d ${PACKAGES} ]; then \
			cd ${.CURDIR} && eval ${MAKE} package-links; \
		fi; \
	else \
		cd ${.CURDIR} && eval ${MAKE} delete-package; \
		exit 1; \
	fi
.endif

.if !target(check-already-installed)
check-already-installed:
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
		@${ECHO_MSG} "===>  Checking if ${PKGORIGIN} already installed"; \
		pkgname=`${PKG_INFO} -q -O ${PKGORIGIN}`; \
		if [ -n "$${pkgname}" ]; then \
			v=`${PKG_VERSION} -t $${pkgname} ${PKGNAME}`; \
			if [ "w$${v}" = "x<" ]; then \
				${ECHO_CMD} "===>   An older version of ${PKGORIGIN} is already installed ($${found_package})"; \
			else \
				${ECHO_CMD} "===>   ${PKGNAME} is already installed"; \
			fi; \
			${ECHO_MSG} "      You may wish to \`\`make deinstall'' and install this port again"; \
			${ECHO_MSG} "      by \`\`make reinstall'' to upgrade it properly."; \
			${ECHO_MSG} "      If you really wish to overwrite the old port of ${PKGORIGIN}"; \
			${ECHO_MSG} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
			${ECHO_MSG} "      in your environment or the \"make install\" command line."; \
			exit 1; \
		fi
.else
	@${DO_NADA}
.endif
.endif


.if !target(deinstall)
deinstall:
	@${ECHO_MSG} "===>  Deinstalling for ${PKGORIGIN}"
	@if ${PKG_INFO} -e ${PKGORIGIN}; then \
		p=`${PKG_INFO} -q ${PKGORIGIN}`; \
		${ECHO_MSG} "===>   Deinstalling $${p}"; \
		${PKG_DELETE} -f ${PKGORIGIN} ; \
	else \
		${ECHO_MSG} "===>   ${PKGBASE} not installed, skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif

