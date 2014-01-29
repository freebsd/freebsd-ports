# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spidermonkey170
PORTVERSION=		17.0.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=		mozjs${PORTVERSION}

MAINTAINER=		kwm@FreeBSD.org
COMMENT=		Standalone JavaScript based from Mozilla 17-esr

BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=		libnspr4.so:${PORTSDIR}/devel/nspr

CONFLICTS=		njs-[0-9]*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USES=			pathfix perl5
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_PYTHON_BUILD=	2

WRKSRC=			${WRKDIR}/mozjs${PORTVERSION}/js/src

CONFIGURE_ARGS=		--with-pthreads \
			--with-system-nspr

OPTIONS_DEFINE=		DEBUG GCZEAL JEMALLOC METHODJIT OPTIMIZE READLINE \
			THREADSAFE TRACEJIT UTF8 \

OPTIONS_DEFAULT=	METHODJIT OPTIMIZE READLINE THREADSAFE TRACEJIT

DEBUG_DESC=		Enable Debug build
GCZEAL_DESC=		Enable Zealous garbage collecting
JEMALLOC_DESC=		Use jemalloc as memory allocator
METHODJIT_DESC=		Enable method JIT support
OPTIMIZE_DESC=		Enable compiler optimizations
READLINE_DESC=		Link js shell to system readline library
THREADSAFE_DESC=	Enable multiple thread support
TRACEJIT_DESC=		Enable tracing JIT support
UTF8_DESC=		Treat strings as UTF8 instead of ISO-8859-1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug \
			--enable-debug-symbols
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MGCZEAL}
CONFIGURE_ARGS+=	--enable-gczeal
.else
CONFIGURE_ARGS+=	--disable-gczeal
.endif

.if ${PORT_OPTIONS:MJEMALLOC}
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if ${PORT_OPTIONS:MMETHODJIT}
CONFIGURE_ARGS+=	--enable-methodjit
.else
CONFIGURE_ARGS+=	--disable-methodjit
.endif

.if ${PORT_OPTIONS:MOPTIMIZE}
CONFIGURE_ARGS+=	--enable-optimize
.else
CONFIGURE_ARGS+=	--disable-optimize
.endif

.if ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ARGS+=	--enable-readline
.else
CONFIGURE_ARGS+=	--disable-readline
.endif

.if ${PORT_OPTIONS:MTHREADSAFE}
CONFIGURE_ARGS+=	--enable-threadsafe
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.if ${PORT_OPTIONS:MTRACEJIT}
CONFIGURE_ARGS+=	--enable-tracejit
.else
CONFIGURE_ARGS+=	--disable-tracejit
.endif

.if ${PORT_OPTIONS:MUTF8}
CFLAGS+=		-DJS_C_STRINGS_ARE_UTF8
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	--no-progress ./js17
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	--no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js17
.endif

post-install:
	${LN} -s libmozjs-17.0.so ${PREFIX}/lib/libmozjs-17.0.so.1

.include <bsd.port.post.mk>
