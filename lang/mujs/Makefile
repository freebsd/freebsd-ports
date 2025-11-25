PORTNAME=	mujs
DISTVERSION=	1.3.8
CATEGORIES=	lang devel
MASTER_SITES=	https://codeberg.org/ccxvii/mujs/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/ \
		https://www.unicode.org/Public/16.0.0/ucd/:unicode
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
DISTFILES=	UnicodeData.txt:unicode \
		SpecialCasing.txt:unicode \
		${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C
WWW=		https://mujs.com/ \
		https://github.com/ccxvii/mujs \
		https://codeberg.org/ccxvii/mujs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl:ftp/curl
TEST_DEPENDS=	git:devel/git

USES=		compiler:c11 cpe gmake python:build readline # c11 is induced by the FreeBSD headers via isnan(3), etc, otherwise the project is all c99 code
USE_LDCONFIG=	yes

CPE_VENDOR=	artifex

WRKSRC=		${WRKDIR}/${PORTNAME}

LDFLAGS=	-Wl,-soname=libmujs.so

ALL_TARGET=	build/release/mujs \
		build/release/libmujs.so \
		build/release/libmujs.a
INSTALL_TARGET=	install-shared install-static

.if defined(WITH_DEBUG) # this project manages its build options itself
MAKE_ARGS=	build=debug
.endif

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/mujs \
		bin/mujs-pp \
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

post-patch:
	${REINPLACE_CMD} -e 's|https://www.unicode.org/Public/16.0.0/ucd/|file://${DISTDIR}/${DIST_SUBDIR}/|g' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/mujs \
		${STAGEDIR}${PREFIX}/bin/mujs-pp \
		${STAGEDIR}${PREFIX}/lib/libmujs.so

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
