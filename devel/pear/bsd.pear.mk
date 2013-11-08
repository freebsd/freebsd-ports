# $FreeBSD$

# Common code for pear- ports.

MASTER_SITES?=	http://pear.php.net/get/ \
		http://us.pear.php.net/get/ \
		http://de.pear.php.net/get/
.if defined(PEAR_DIST_SUFX)
EXTRACT_SUFX=	${PEAR_DIST_SUFX}
.else
EXTRACT_SUFX=	.tgz
.endif
DIST_SUBDIR?=	PEAR

RUN_DEPENDS+=	pear:${PORTSDIR}/devel/pear

.if defined(PEAR_CATSRC)
PEARWRKSRC?=    ${WRKSRC}/${CATEGORY}
.else
PEARWRKSRC?=    ${WRKSRC}
.endif

.if !defined(USE_PHPIZE)
NO_BUILD=	yes
.endif

.if defined(PEAR_CHANNEL) && ${PEAR_CHANNEL} != ""
PKGNAMEPREFIX?=	pear-${PEAR_CHANNEL}-
PEARPKGREF=	${PEAR_CHANNEL}/${PORTNAME}
.else
PKGNAMEPREFIX?=	pear-
PEARPKGREF=	${PORTNAME}
.endif

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPEARDIR=	share/pear
LPKGREGDIR=	${LPEARDIR}/packages/${PKGNAME}
LDATADIR=	${LPEARDIR}/data/${PORTNAME}
LDOCSDIR=	share/doc/pear/${PORTNAME}
LEXAMPLESDIR=	share/examples/pear/${PORTNAME}
LSQLSDIR=	${LPEARDIR}/sql/${PORTNAME}
LSCRIPTSDIR=	bin
LTESTSDIR=	${LPEARDIR}/tests/${PORTNAME}
PEARDIR=	${PHP_BASE}/${LPEARDIR}
PKGREGDIR=	${PHP_BASE}/${LPKGREGDIR}
DATADIR=	${PHP_BASE}/${LDATADIR}
DOCSDIR=	${PHP_BASE}/${LDOCSDIR}
EXAMPLESDIR=	${PHP_BASE}/${LEXAMPLESDIR}
SQLSDIR=	${PHP_BASE}/${LSQLSDIR}
SCRIPTFILESDIR=	${LOCALBASE}/bin
TESTSDIR=	${PHP_BASE}/${LTESTSDIR}
.if defined(CATEGORY) && !empty(CATEGORY)
LINSTDIR=	${LPEARDIR}/${CATEGORY}
.else
LINSTDIR=	${LPEARDIR}
.endif
INSTDIR=	${PHP_BASE}/${LINSTDIR}

SUB_LIST+=	PKG_NAME=${PEARPKGREF}

.if !defined(USE_PHPIZE) && !exists(${.CURDIR}/pkg-plist)
PLIST=		${WRKDIR}/PLIST
.endif
PLIST_SUB+=	PEARDIR=${LPEARDIR} PKGREGDIR=${LPKGREGDIR} \
		TESTSDIR=${LTESTSDIR} INSTDIR=${LINSTDIR} SQLSDIR=${LSQLSDIR} \
		SCRIPTFILESDIR=${LCRIPTSDIR}

PKGINSTALL?=	${PORTSDIR}/devel/pear/pear-install
PKGDEINSTALL?=	${WRKDIR}/pear-deinstall

FILES?=
DATA?=
DOCS?=
EXAMPLES?=
SQLS?=
SCRIPTFILES?=
TESTS?=
_DATADIR?=	data
_DOCSDIR?=	docs
_EXAMPLESDIR?=	examples
_SQLSDIR?=	sql
_TESTSDIR?=	tests

# this is an easy way to eliminate duplicate entries in a variable :)
# if someone knows how to achieve the result without this terrible
# hack, please tell me!
.for v in FILES DOCS TESTS EXAMPLES SQLS SCRIPTFILES DATA
X${v}DIRS=	${${v}:M*/*:C;/[^/]+$;;}
. for XD in ${X${v}DIRS}
ALREADYTHERE=	0
.  for D in ${${v}DIRS}
DD=	${D}
.   if ${DD} == ${XD}
ALREADYTHERE=	1
.   endif
.  endfor
.  if ${ALREADYTHERE} == 0
${v}DIRS+=		${XD}
.  endif
. endfor
.endfor

pear-pre-install:
.if exists(${LOCALBASE}/lib/php.DIST_PHP)	\
	|| exists(${PHP_BASE}/lib/php.DIST_PHP)	\
	|| exists(${LOCALBASE}/.PEAR.pkg)	\
	|| exists(${PHP_BASE}/.PEAR.pkg)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	Sorry, the PEAR structure has been modified;"
	@${ECHO_MSG} "	Please deinstall your installed pear- ports."
	@${ECHO_MSG} ""
	@${FALSE}
.endif

DIRFILTER=	${SED} -En '\:^.*/[^/]*$$:s:^(.+)/[^/]*$$:\1:p' \
		    | ( while read r; do \
			C=1; \
			while [ $$C = 1 ]; do \
			    echo $$r; \
			    if echo $$r | ${GREP} '/' > /dev/null; then \
	                        r=`${DIRNAME} $$r`; \
			    else  \
	                        C=0; \
	                    fi; \
	                done; \
	            done \
	      ) | ${SORT} -ur

.if !defined(USE_PHPIZE)
do-generate-plist:
. if !exists(${.CURDIR}/pkg-plist)
	@${ECHO_MSG} "===>   Generating packing list"; \
	(for file in ${FILES}; do echo "${LINSTDIR}/$${file}"; done; \
	for file in ${TESTS}; do echo "${LTESTSDIR}/$${file}"; done; \
	for file in ${DATA}; do echo "${LDATADIR}/$${file}"; done; \
	for file in ${SQLS}; do echo "${LSQLSDIR}/$${file}"; done; \
	for file in ${SCRIPTFILES}; do echo "${LSCRIPTSDIR}/$${file}"; done; \
	for file in ${DOCS}; do echo "%%PORTDOCS%%${LDOCSDIR}/$${file}"; done; \
	for file in ${EXAMPLES}; do echo "%%PORTDOCS%%${LEXAMPLESDIR}/$${file}"; done; \
	echo "${LPKGREGDIR}/package.xml"; \
	for d in ${FILES} ${FILES:H}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "@dirrmtry ${LINSTDIR}/$${dir}"; done; \
	for d in ${TESTS}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "@dirrm ${LTESTSDIR}/$${dir}"; done; \
	for d in ${DATA}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "@dirrm ${LDATADIR}/$${dir}"; done; \
	for d in ${SQLS}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "@dirrm ${LSQLSDIR}/$${dir}"; done; \
	for d in ${DOCS}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "%%PORTDOCS%%@dirrm ${LDOCSDIR}/$${dir}"; done; \
	for d in ${EXAMPLES}; do echo $${d}; done | ${DIRFILTER} | \
	    while read dir; do echo "%%PORTDOCS%%@dirrm ${LEXAMPLESDIR}/$${dir}"; done; \
	if [ -n "${TESTS}" ]; then echo "@dirrm ${LTESTSDIR}"; fi; \
	if [ -n "${DATA}" ]; then echo "@dirrm ${LDATADIR}"; fi; \
	if [ -n "${SQLS}" ]; then echo "@dirrm ${LSQLSDIR}"; fi; \
	if [ -n "${DOCS}" ]; then echo "%%PORTDOCS%%@dirrm ${LDOCSDIR}"; fi; \
	if [ -n "${EXAMPLES}" ]; then echo "%%PORTDOCS%%@dirrm ${LEXAMPLESDIR}"; fi; \
	echo "@dirrm ${LPKGREGDIR}"; \
	if [ -n "${CATEGORY}" ]; then echo "@dirrmtry ${LINSTDIR}"; fi; \
	if [ -n "${CATEGORY:M*/*}" ]; then echo "@dirrmtry ${LINSTDIR:H}"; fi; \
	echo "@dirrmtry ${LPKGREGDIR:H}"; \
	echo "@dirrmtry ${LDOCSDIR:H}"; \
	echo "@dirrmtry ${LEXAMPLESDIR:H}"; \
	echo "@dirrmtry ${LTESTSDIR:H}"; \
	echo "@dirrmtry ${LDATADIR:H}"; \
	echo "@dirrmtry ${LSQLSDIR:H}") > ${PLIST}
. endif

. for t in files docs tests sqls scriptfiles examples data
.  if !target(do-install-${t}-msg)
do-install-${t}-msg: .USE
.  endif
. endfor

do-autogenerate-plist: patch
	@${ECHO_MSG} "===>   Generating packing list with pear"
	@${LN} -sf ${WRKDIR}/package.xml ${WRKSRC}/package.xml
	@cd ${WRKSRC} && ${PEAR} install -n -f -P ${WRKDIR}/inst package.xml > /dev/null 2> /dev/null
.for R in .channels .depdb .depdblock .filemap .lock .registry
	@${RM} -rf ${WRKDIR}/inst/${PREFIX}/${LPEARDIR}/${R}
.endfor
	@FILES=`cd ${WRKDIR}/inst && ${FIND} . -type f | ${CUT} -c 2- | \
	${GREP} -v -E "^${PREFIX}/"` || exit 0; \
	${ECHO_CMD} $${FILES}; if ${TEST} -n "$${FILES}"; then \
	${ECHO_CMD} "Cannot generate packing list: package files outside PREFIX"; \
	exit 1; fi;
	@${ECHO_CMD} "${LPKGREGDIR}/package.xml" > ${PLIST}
	# pkg_install needs to escape $ in directory name while pkg does not
.if defined(WITH_PKGNG)
	@cd ${WRKDIR}/inst/${PREFIX} && ${FIND} . -type f | ${SORT} \
	| ${CUT} -c 3- >> ${PLIST}
	@DIRS=`cd ${WRKDIR}/inst/${PREFIX} && ${FIND} . -type d | ${SORT} -r | \
	${CUT} -c 3-`; \
	for d in $${DIRS}; do \
		if [ ! -d ${LOCALBASE}/$${d} ]; then \
			${ECHO_CMD} "@dirrmtry $${d}" >> ${PLIST}; \
		fi; \
	done
.else
	@cd ${WRKDIR}/inst/${PREFIX} && ${FIND} . -type f | ${SORT} \
	| ${CUT} -c 3- >> ${PLIST}
	@DIRS=`cd ${WRKDIR}/inst/${PREFIX} && ${FIND} . -type d | ${SORT} -r | \
	${CUT} -c 3- | ${SED} -e 's,\\$$,\\\\$$,g'`; \
	for d in $${DIRS}; do \
		if [ ! -d ${LOCALBASE}/$${d} ]; then \
			${ECHO_CMD} "@dirrmtry $${d}" >> ${PLIST}; \
		fi; \
	done
.endif
	@${ECHO_CMD} "@dirrm ${LPKGREGDIR}" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry ${LPKGREGDIR:H}" >> ${PLIST}

. if defined(PEAR_AUTOINSTALL)
pre-install:	pear-pre-install do-autogenerate-plist do-generate-deinstall-script
do-install:	do-auto-install pear-post-install

. else
pre-install:	pear-pre-install do-generate-plist do-generate-deinstall-script
do-install: 	do-install-files do-install-docs do-install-tests do-install-sqls \
		do-install-scriptfiles do-install-examples do-install-data \
		pear-post-install
. endif

do-auto-install:
	@${ECHO_MSG} "===>   Installing package with pear"
.if defined(NO_STAGE)
	@cd ${WRKSRC} && ${PEAR} install -n -f package.xml
.else
	@cd ${WRKSRC} && ${PEAR} install -n -f -P ${STAGEDIR} package.xml
.endif

do-install-files: do-install-files-msg
	@${MKDIR} ${STAGEDIR}${INSTDIR}
. for dir in ${FILESDIRS}
	@${MKDIR} ${STAGEDIR}${INSTDIR}/${dir}
. endfor
. for file in ${FILES}
	@${INSTALL_DATA} ${PEARWRKSRC}/${file} ${STAGEDIR}${INSTDIR}/${file}
. endfor

do-install-docs: do-install-docs-msg
. if !defined(NOPORTDOCS) && !empty(DOCS)
	@${ECHO_MSG} "===> Installing documentation in ${DOCSDIR}."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.  for dir in ${DOCSDIRS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
.  endfor
.  for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${_DOCSDIR}/${file} ${STAGEDIR}${DOCSDIR}/${file}
.  endfor
. endif

do-install-tests: do-install-tests-msg
. if !empty(TESTS)
	@${ECHO_MSG} "===> Installing tests in ${TESTSDIR}."
	@${MKDIR} ${STAGEDIR}${TESTSDIR}
.  for dir in ${TESTSDIRS}
	@${MKDIR} ${STAGEDIR}${TESTSDIR}/${dir}
.  endfor
.  for file in ${TESTS}
	@${INSTALL_DATA} ${WRKSRC}/${_TESTSDIR}/${file} ${STAGEDIR}${TESTSDIR}/${file}
.  endfor
. endif

do-install-data: do-install-data-msg
. if !empty(DATA)
	@${ECHO_MSG} "===> Installing data in ${DATADIR}."
	@${MKDIR} ${STAGEDIR}${DATADIR}
.  for dir in ${DATADIRS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${dir}
.  endfor
.  for file in ${DATA}
	@${INSTALL_DATA} ${WRKSRC}/${_DATADIR}/${file} ${STAGEDIR}${DATADIR}/${file}
.  endfor
. endif

do-install-sqls: do-install-sqls-msg
. if !empty(SQLS)
	@${ECHO_MSG} "===> Installing sqls in ${SQLSDIR}."
	@${MKDIR} ${STAGEDIR}${SQLSDIR}
.  for dir in ${SQLSDIRS}
	@${MKDIR} ${STAGEDIR}${SQLSDIR}/${dir}
.  endfor
.  for file in ${SQLS}
	@${INSTALL_DATA} ${WRKSRC}/${_SQLSDIR}/${file} ${STAGEDIR}${SQLSDIR}/${file}
.  endfor
. endif

do-install-scriptfiles: do-install-scriptfiles-msg
. if !empty(SCRIPTFILES)
	@${ECHO_MSG} "===> Installing scripts in ${SCRIPTFILESDIR}."
.  for file in ${SCRIPTFILES}
	@${CP} ${WRKSRC}/pear-${file} ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|@php_bin@|${SCRIPTFILESDIR}/php|g" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|@php_dir@|${PREFIX}/lib/php|g" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|@include_path@|${PREFIX}/${LPEARDIR}|g" ${WRKSRC}/${file}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${SCRIPTFILESDIR}/${file}
.  endfor
. endif

do-install-examples: do-install-examples-msg
. if !defined(NOPORTDOCS) && !empty(EXAMPLES)
	@${ECHO_MSG} "===> Installing examples in ${EXAMPLESDIR}."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.  for dir in ${EXAMPLESDIRS}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${dir}
.  endfor
.  for file in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${_EXAMPLESDIR}/${file} ${STAGEDIR}${EXAMPLESDIR}/${file}
.  endfor
. endif
.endif

do-generate-deinstall-script:
	@${SED} ${_SUB_LIST_TEMP} -e '/^@comment /d' ${PORTSDIR}/devel/pear/pear-deinstall.in > ${WRKDIR}/pear-deinstall

pear-post-install:
	@${MKDIR} ${STAGEDIR}${PKGREGDIR}
	@${INSTALL_DATA} ${WRKDIR}/package.xml ${STAGEDIR}${PKGREGDIR}
.if defined(NO_STAGE) && !defined(PEAR_AUTOINSTALL)
	@${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

show-depends: patch
	@${PEAR} package-dependencies ${WRKDIR}/package.xml
