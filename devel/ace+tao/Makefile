# Ports collection makefile for:	ace+tao
# Date created:				26 November 2003
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME?=	ace+tao
PORTVERSION?=	${ACE_VERSION}+${TAO_VERSION}
CATEGORIES=	devel
MASTER_SITES=	ftp://deuce.doc.wustl.edu/pub/previous_versions/ \
		http://deuce.doc.wustl.edu/old_distribution/ \
		http://www.navicon.dk/mirrors/ace/deuce.doc.wustl.edu/old_distribution/
DISTNAME=	ACE-${ACE_VERSION:C/\.0$//}+TAO-${TAO_VERSION:C/\.0$//}

MAINTAINER=	sem@FreeBSD.org
COMMENT?=	The Adaptive Communication Environment (ACE) with The ACE ORB (TAO)

CONFLICTS?=	ace-*

ACE_VERSION=	5.4.1
TAO_VERSION=	1.4.1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

# Code is not 64-bit clean yet
ONLY_FOR_ARCHS=	i386

TESTS=		"@comment "
.if defined(WITH_TESTS)
USE_PERL5_BUILD=	yes
ACE_TESTS_COOKIE=	${WRKDIR}/.ace_tests_done
TAO_TESTS_COOKIE=	${WRKDIR}/.tao_tests_done
TESTS=		""
.endif

WRKSRC=		${WRKDIR}/ACE_wrappers
ACE_ROOT=	${WRKSRC}
TAO_ROOT=	${ACE_ROOT}/TAO

PLIST_SUB+=	TAO=${TAO} TESTS=${TESTS} \
		ACE_VERSION=${ACE_VERSION} TAO_VERSION=${TAO_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502125
WITHOUT_TAO=	yes
pre-extract:
	@${ECHO_MSG} "****************************************************"; \
	 ${ECHO_MSG} "*        TAO is not build with gcc 3.4             *"; \
	 ${ECHO_MSG} "*     so only ACE will build  and install          *"; \
	 ${ECHO_MSG} "****************************************************"
.endif

.if defined(WITHOUT_TAO)
TAO=	"@comment "
PKGNAMESUFFIX?=	-notao
.endif

post-patch:
	@${SED} -e "s#%%CFLAGS%%#${CFLAGS}#;s#%%PREFIX%%#${PREFIX}#; \
	           s#%%PTHREAD_CFLAGS%%#${PTHREAD_CFLAGS}#; \
		   s#%%PTHREAD_LIBS%%#${PTHREAD_LIBS}#" \
	   ${FILESDIR}/platform_macros.GNU > \
	   ${ACE_ROOT}/include/makeinclude/platform_macros.GNU; \
	${CP} ${FILESDIR}/config.h ${ACE_ROOT}/ace; \
	cd ${TAO_ROOT}/orbsvcs; \
	${CHMOD} a-x Logging_Service/Event_Logging_Service/*; \
	${CHMOD} a-x Logging_Service/Notify_Logging_Service/*; \
	${CHMOD} a-x Logging_Service/RTEvent_Logging_Service/*; \
	${CHMOD} a-x orbsvcs/*.mpb; \
	${CHMOD} a-x orbsvcs/FaultTolerance/*; \
	${CHMOD} a-x FT_ReplicationManager/*
.if !defined(WITH_TESTS)
	@${REINPLACE_CMD} -e "21d" ${ACE_ROOT}/Makefile
	@${REINPLACE_CMD} -e "24d" ${TAO_ROOT}/Makefile
	@${REINPLACE_CMD} -e "48d" ${TAO_ROOT}/orbsvcs/Makefile
.endif

pre-build:
	@${ECHO_MSG} "============================================================================"
	@${ECHO_MSG} "Use WITHOUT_TAO=yes to build ACE only. It decreases build time for a few hours."
	@${ECHO_MSG} "Use WITH_TESTS=yes to build ACE+TAO tests. (You need \`make clean' first)."
	@${ECHO_MSG} "    You'll able \`make WITH_TESTS=yes test' then."
	@${ECHO_MSG} "============================================================================"

do-build:
	@${ECHO_MSG} "===> Building ACE"; \
	${GMAKE} -C ${ACE_ROOT} ACE_ROOT=${ACE_ROOT}
.if defined(WITH_TESTS)
	@${TOUCH} ${TOUCH_FLAGS} ${ACE_TESTS_COOKIE}
.endif
.if !defined(WITHOUT_TAO)
	@${ECHO_MSG} "===> Building TAO"; \
	${GMAKE} -C ${TAO_ROOT} ACE_ROOT=${ACE_ROOT} TAO_ROOT=${TAO_ROOT}
.if defined(WITH_TESTS)
	@${TOUCH} ${TOUCH_FLAGS} ${TAO_TESTS_COOKIE}
.endif
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Build done."
.if defined(WITH_TESTS)
	@${ECHO_MSG} "     You can run tests now with \`make WITH_TESTS=yes test'"
.endif
	@${ECHO_MSG} ""

test:
.if defined(WITH_TESTS)
.if ${OSVERSION} >= 500036
	/sbin/kldload aio || ${TRUE}
.endif
	@if [ -f ${ACE_TESTS_COOKIE} ]; then \
		${ECHO_MSG} "===> Running tests."; \
		${ECHO_MSG} "===> ACE tests:"; \
		cd ${ACE_ROOT}/tests; ./run_test.pl; \
		if [ -f ${TAO_TESTS_COOKIE} ]; then \
			${ECHO_MSG} "===> TAO tests:"; \
			${ECHO_MSG} "    NOT IMPLEMENTED YET. Run them with:"; \
			${ECHO_MSG} "cd ${TAO_ROOT}/tests"; \
			${ECHO_MSG} "${FIND} . -name run_test.pl -execdir run_test.pl \;"; \
			${ECHO_MSG} "===>TAO/orbsvcs tests:"; \
			${ECHO_MSG} "    NOT IMPLEMENTED YET. Run them with:"; \
			${ECHO_MSG} "cd ${TAO_ROOT}/orbsvcs/tests"; \
			${ECHO_MSG} "${FIND} . -name run_test.pl -execdir run_test.pl \;"; \
		fi; \
		${ECHO_MSG} "===> Tests done."; \
	else \
		${ECHO_MSG} "===> Tests was not build"; \
		${ECHO_MSG} "     To build tests use \`make WITH_TESTS=yes clean build'"; \
		${ECHO_MSG} ""; \
	fi
.else
	@${ECHO_MSG} ""; \
	${ECHO_MSG} "Run tests with \`make WITH_TESTS=yes test'"; \
	${ECHO_MSG} ""
.endif

do-install:
	@${ECHO_MSG} "Installing ACE headers into ${PREFIX}/include/ace"; \
	cd ${ACE_ROOT}; \
	${FIND} ace -not -path "*.shobj*" -type d -exec \
		${MKDIR} ${PREFIX}/include/\{\} \; ; \
	${FIND} ace -type f \( -name "*.h" -o -name "*.i" -o -name "*.inl" \
		-o -name "*.cpp" \) \( -not -name "config-*.h" \
		-o -name config-all.h -o -name config-lite.h -o \
		-name config-posix.h -o -name config-g++-common.h \) -exec \
			${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;
.if !defined(WITHOUT_TAO)
	@${ECHO_MSG} "Installing TAO headers into ${PREFIX}/include/tao"; \
	cd ${TAO_ROOT}; \
	${FIND} tao -not -path "*.shobj*" -not -name diffs -type d -exec \
		${MKDIR} ${PREFIX}/include/\{\} \; ; \
	${FIND} tao -type f \( -name "*.h" -o -name "*.i" -o -name "*.inl" \
		-o -name "*.idl" -o -name "*.pidl" -o -name "*.cpp" \) -exec \
		${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \; ; \
	cd ${TAO_ROOT}/orbsvcs; \
	${FIND} orbsvcs -not -path "*.shobj*" -type d -exec \
		${MKDIR} ${PREFIX}/include/\{\} \; ; \
	${FIND} orbsvcs -type f \( -name "*.h" -o -name "*.i" -o -name "*.inl" \
		-o -name "*.idl" -o -name "*.pidl" -o -name "*.cpp" \) -exec \
		${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;
.endif

	@${ECHO_MSG} "Installing libraries into ${PREFIX}/lib"; \
	cd ${ACE_ROOT}/ace; \
	for f in `${FIND} . -maxdepth 1 -name "lib*.so.${ACE_VERSION}" -o \
		-name "lib*.so.${TAO_VERSION}" -not -name "*Test*"`; do \
			${INSTALL_DATA} $${f} ${PREFIX}/lib; \
			lib=`${ECHO} $${f} | ${SED} -e s#.*/##`; \
			(cd ${PREFIX}/lib; \
			${LN} -fs $${lib} `${ECHO} $${lib} | ${SED} -e \
				's/.${ACE_VERSION}//;s/.${TAO_VERSION}//'`); \
	done

	@${ECHO_MSG} "Installing executables into ${PREFIX}/bin"; \
	${INSTALL_PROGRAM} ${ACE_ROOT}/bin/gperf ${PREFIX}/bin
.if !defined(WITHOUT_TAO)
	@cd ${TAO_ROOT}; \
	for f in `${FIND} orbsvcs -type f -perm +a+x -not -name "lib*" | \
			${GREP} -v test | ${GREP} -v FTRT_Event_Service`; do \
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin; \
	done; \
	for f in `find utils  -type f -perm +a+x`; do \
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin; \
	done; \
	for f in `${FIND} orbsvcs/FTRT_Event_Service -type f -perm +a+x`; do \
		${INSTALL_SCRIPT} $${f} ${PREFIX}/bin; \
	done; \
	${INSTALL_PROGRAM} TAO_IDL/tao_idl ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing documentation into ${DOCSDIR}"; \
	${MKDIR} ${DOCSDIR}/ACE; \
	cd ${ACE_ROOT}/docs; ${TAR} cf - . | ${TAR} xUCf ${DOCSDIR}/ACE -
.if !defined(WITHOUT_TAO)
	@${MKDIR} ${DOCSDIR}/TAO; \
	cd ${TAO_ROOT}/docs; ${TAR} cf - . | ${TAR} xUCf ${DOCSDIR}/TAO -
.endif
.endif

.include <bsd.port.post.mk>
