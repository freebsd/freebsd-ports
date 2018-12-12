# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spidermonkey
PORTVERSION=	52.9.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${PORTVERSION}esr/source
PKGNAMESUFFIX=	${SP_VER}
DISTNAME=	firefox-${PORTVERSION}esr.source

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 52-esr

BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213
LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libffi.so:devel/libffi \
		libicudata.so:devel/icu

HAS_CONFIGURE=	yes
USES=		compiler:c++14-lang gmake localbase pathfix pkgconfig \
		python:2.7,build tar:xz
#		python:2.7,build readline tar:xz
USE_LDCONFIG=	yes
SP_VER=		52

WRKSRC=		${WRKDIR}/firefox-${PORTVERSION}esr/js/src
PATCH_WRKSRC=	${WRKDIR}/firefox-${PORTVERSION}esr/
INCLUDE=	.cargo Makefile.in build* config* gradle* js memory nsprpub/config
INCLUDE+=	mfbt modules moz* python taskcluster testing
EXTRACT_AFTER_ARGS+=	${INCLUDE:S|^|firefox-${PORTVERSION}esr/|}

CONFIGURE_ARGS=	--with-pthreads \
		--prefix=${PREFIX:Q} \
		--target=${CONFIGURE_TARGET} \
		--with-intl-api \
		--with-system-zlib \
		--disable-gold \
		--with-system-icu \
		--with-system-nspr
CONFIGURE_ENV= HOST_CC=${CC} HOST_CXX=${CXX}

OPTIONS_DEFINE=	DEBUG GCZEAL JEMALLOC OPTIMIZE READLINE UTF8 DTRACE
OPTIONS_DEFAULT=METHODJIT OPTIMIZE READLINE
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug debug-symbols
DEBUG_CONFIGURE_DISABLE=debug

DTRACE_CONFIGURE_ENABLE=dtrace profiling
DTRACE_LIBS=	-lelf

GCZEAL_DESC=	Enable Zealous garbage collecting
GCZEAL_CONFIGURE_ENABLE=gczeal

JEMALLOC_DESC=	Use jemalloc as memory allocator
JEMALLOC_CONFIGURE_ENABLE=	jemalloc

OPTIMIZE_DESC=	Enable compiler optimizations
OPTIMIZE_CONFIGURE_ENABLE=	optimize

READLINE_DESC=	Link js shell to the readline library
READLINE_USES=	readline
READLINE_CONFIGURE_ENABLE=	readline

UTF8_DESC=	Treat strings as UTF8 instead of ISO-8859-1
UTF8_CFLAGS=	-DJS_C_STRINGS_ARE_UTF8

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
# Skip some tests because bundled icu differs from system
	@${RM}  ${WRKSRC}/tests/Intl/Date/toLocaleDateString_timeZone.js \
		${WRKSRC}/tests/Intl/DateTimeFormat/format.js \
		${WRKSRC}/tests/Intl/DateTimeFormat/format_timeZone.js \
		${WRKSRC}/tests/Intl/NumberFormat/StringBuffer.js

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13
# The directory needs to exist, or configure freaks out:
	@${MKDIR} ${WRKSRC:H:H}/intl/icu/source/common/unicode
	${LN} -s ${LOCALBASE}/include/unicode/uvernum.h	\
		${WRKSRC:H:H}/intl/icu/source/common/unicode/

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} LANG=C TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	-d -s --no-progress ./js/src/shell/js

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
.if ! ${PORT_OPTIONS:MDTRACE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js${SP_VER}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*
.endif

.include <bsd.port.post.mk>
