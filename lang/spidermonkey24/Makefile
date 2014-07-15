# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spidermonkey24
PORTVERSION=		24.2.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_MOZILLA}
#http://people.mozilla.org/~sstangl/
MASTER_SITE_SUBDIR=	js
DISTNAME=		mozjs-${PORTVERSION}

MAINTAINER=		kwm@FreeBSD.org
COMMENT=		Standalone JavaScript based from Mozilla 24-esr

BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=		libnspr4.so:${PORTSDIR}/devel/nspr

CONFLICTS=		njs-[0-9]*

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USES=			compiler:c11 gmake pathfix perl5 readline
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_PYTHON_BUILD=	2

WRKSRC=			${WRKDIR}/mozjs-${PORTVERSION}/js/src

CONFIGURE_ARGS=		--with-pthreads \
			--with-system-nspr

OPTIONS_DEFINE=		DEBUG GCZEAL JEMALLOC METHODJIT OPTIMIZE READLINE \
			THREADSAFE TRACEJIT UTF8 \

OPTIONS_DEFAULT=	METHODJIT OPTIMIZE READLINE THREADSAFE TRACEJIT

DEBUG_DESC=		Enable Debug build
DEBUG_CONFIGURE_ENABLE=	debug debug-symbols
DEBUG_CONFIGURE_DISABLE=debug
GCZEAL_DESC=		Enable Zealous garbage collecting
GCZEAL_CONFIGURE_ENABLE=gczeal
JEMALLOC_DESC=		Use jemalloc as memory allocator
JEMALLOC_CONFIGURE_ENABLE=	jemalloc
METHODJIT_DESC=		Enable method JIT support
METHODJIT_CONFIGURE_ENABLE=	methodjit
OPTIMIZE_DESC=		Enable compiler optimizations
OPTIMIZE_CONFIGURE_ENABLE=	optimize
READLINE_DESC=		Link js shell to system readline library
READLINE_CONFIGURE_ENABLE=	readline
THREADSAFE_DESC=	Enable multiple thread support
THREADSAFE_CONFIGURE_ENABLE=	threadsafe
TRACEJIT_DESC=		Enable tracing JIT support
TRACEJIT_CONFIGURE_ENABLE=	tracejit
UTF8_DESC=		Treat strings as UTF8 instead of ISO-8859-1
UTF8_CFLAGS=		-DJS_C_STRINGS_ARE_UTF8

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	--no-progress ./js24
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	--no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js24
.endif

post-install:
	${LN} -s libmozjs-24.so ${STAGEDIR}${PREFIX}/lib/libmozjs-24.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js24
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-24.*

.include <bsd.port.post.mk>
