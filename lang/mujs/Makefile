PORTNAME=	mujs
DISTVERSION=	1.1.1
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	git:devel/git

USES=		compiler:c11 gmake readline # c11 is induced by the FreeBSD headers via isnan(3), etc, otherwise the project is all c99 code
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ccxvii

ALL_TARGET=	shared static

INSTALL_TARGET=	install-shared install-static

.if defined(WITH_DEBUG) # this project manages its build options itself
MAKE_ARGS=	build=debug
.endif

PLIST_FILES=	bin/mujs \
		include/mujs.h \
		lib/libmujs.so \
		lib/libmujs.a \
		libdata/pkgconfig/mujs.pc

OPTIONS_DEFINE=		32BIT SANITIZED
OPTIONS_DEFAULT=	32BIT

32BIT_DESC=		32-bit address space to allow for larger programs
32BIT_MAKE_ARGS=	XCFLAGS="-DJS_INSTRUCTION=int"

SANITIZED_DESC=		Sanitized build (only for debugging)
SANITIZED_MAKE_ARGS=	build=sanitize

do-test: # Test-262 JavaScript testsuite is downloaded and run.
	# Something is off with the test harness so too many tests fail: https://github.com/ccxvii/mujs/issues/147
	${RM} -r ${WRKDIR}/testing && \
	${MKDIR} -p ${WRKDIR}/testing && \
	cd ${WRKDIR}/testing && \
	git clone https://github.com/tc39/test262.git && \
	fetch https://github.com/ccxvii/mujs/files/2332077/mujs-test262-harness-and-output.zip && \
	unzip mujs-test262-harness-and-output.zip && \
	(${TAIL} -3 mujs-harness-out.txt > mujs-harness-out-3.txt) && \
	cd test262 && \
	git checkout es5-tests && \
	${ECHO} "Running MuJS tests ..." && \
	(${FIND} test/suite -name '*.js' | ${STAGEDIR}${PREFIX}/bin/mujs ../mujs-harness.js > mujs-harness-out-our.txt) && \
	${ECHO} "MuJS tests finished: " && \
	(${TAIL} -3 mujs-harness-out-our.txt | tee mujs-harness-out-our-3.txt) && \
	${ECHO} "" && \
	${ECHO} "Compare with reference results:" && \
	${DIFF} ../mujs-harness-out-3.txt mujs-harness-out-our-3.txt

.include <bsd.port.mk>
