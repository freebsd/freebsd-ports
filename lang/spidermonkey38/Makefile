# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spidermonkey38
PORTVERSION=	38.8.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${PORTVERSION}esr/source
DISTNAME=	firefox-${PORTVERSION}esr.source

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 38-esr

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libffi.so:devel/libffi \
		libicudata.so:devel/icu

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake pathfix perl5 pkgconfig \
		python:2.7,build readline tar:bzip2
USE_PERL5=	build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/mozilla-esr38/js/src

CONFIGURE_ARGS=	--with-pthreads \
		--with-intl-api \
		--with-system-zlib \
		--enable-system-ffi \
		--with-system-icu \
		--with-system-nspr

OPTIONS_DEFINE=	DEBUG GCZEAL JEMALLOC METHODJIT OPTIMIZE READLINE \
		THREADSAFE TRACEJIT UTF8 DTRACE
OPTIONS_DEFAULT=METHODJIT OPTIMIZE READLINE THREADSAFE TRACEJIT
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug debug-symbols
DEBUG_CONFIGURE_DISABLE=debug

DTRACE_CONFIGURE_ENABLE=dtrace profiling
DTRACE_LIBS=	-lelf

GCZEAL_DESC=	Enable Zealous garbage collecting
GCZEAL_CONFIGURE_ENABLE=gczeal

JEMALLOC_DESC=	Use jemalloc as memory allocator
JEMALLOC_CONFIGURE_ENABLE=	jemalloc

METHODJIT_DESC=	Enable method JIT support
METHODJIT_CONFIGURE_ENABLE=	methodjit

OPTIMIZE_DESC=	Enable compiler optimizations
OPTIMIZE_CONFIGURE_ENABLE=	optimize

READLINE_DESC=	Link js shell to system readline library
READLINE_CONFIGURE_ENABLE=	readline

THREADSAFE_DESC=Enable multiple thread support
THREADSAFE_CONFIGURE_ENABLE=	threadsafe

TRACEJIT_DESC=	Enable tracing JIT support
TRACEJIT_CONFIGURE_ENABLE=	tracejit

UTF8_DESC=	Treat strings as UTF8 instead of ISO-8859-1
UTF8_CFLAGS=	-DJS_C_STRINGS_ARE_UTF8

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
# Skip some tests because bundled icu differs from system
	@${RM}  ${WRKSRC}/tests/test262/intl402/ch10/10.2/10.2.3_b.js \
		${WRKSRC}/tests/Intl/DateTimeFormat/format.js \
		${WRKSRC}/tests/ecma_6/String/normalize-generateddata-part1-not-listed.js

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	-d -s --no-progress ./js/src/shell/js
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	-d -s --no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js/src/shell/js
.endif

.include "Makefile.filelist"

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-38.so ${STAGEDIR}${PREFIX}/lib/libmozjs-38.so.1
# the build installs symlinks, replace them with real files.
# fedora has a nice for loop, but I can't get it to work in make, ideas?
	${RM} -rf ${STAGEDIR}${PREFIX}/include/mozjs-38/*
	${INSTALL_DATA} ${WRKSRC}/js/src/js-config.h \
		${STAGEDIR}${PREFIX}/include/mozjs-38/
.for file in ${BASEFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${STAGEDIR}${PREFIX}/include/mozjs-38/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/include/mozjs-38/js
.for file in ${JSFILES}
	${INSTALL_DATA} ${WRKSRC}/../public/${file} \
		${STAGEDIR}${PREFIX}/include/mozjs-38/js/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/include/mozjs-38/mozilla
.for file in ${MOZILLAFILES}
	${INSTALL_DATA} ${WRKSRC}/../../mfbt/${file} \
		${STAGEDIR}${PREFIX}/include/mozjs-38/mozilla/
.endfor
# Install files, not symlinks to build directory
#.for link in `find ${STAGEDIR}${PREFIX} -type l`; do
#	header=`readlink ${link}`; \
#	rm -f ${link}; \
#	cp -p ${header} ${link}
#.endfor
.if ! ${PORT_OPTIONS:MDTRACE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js38
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-38.*
.endif

.include <bsd.port.post.mk>
