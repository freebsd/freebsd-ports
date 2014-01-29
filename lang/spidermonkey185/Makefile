# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spidermonkey185
PORTVERSION=		1.8.5
PORTREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=		js185-1.0.0

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		Standalone JavaScript (1.8.5) interpreter from Mozilla

BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=		nspr4:${PORTSDIR}/devel/nspr

CONFLICTS=		njs-[0-9]*

USES=			gmake pathfix perl5 pkgconfig
USE_AUTOTOOLS=		autoconf213:env
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
USE_PERL5=		build
USE_PYTHON_BUILD=	2

WRKSRC=			${WRKDIR}/js-${PORTVERSION}/js/src

CONFIGURE_ARGS=		--with-pthreads \
			--with-system-nspr

# This comes from bsd.gecko.mk, fixes linking issues on 9.0 and higher.
NO_STAGE=	yes
post-configure:
	${ECHO_CMD} "fenv.h" >> ${WRKSRC}/config/system-headers
	${ECHO_CMD} "pthread_np.h" >> ${WRKSRC}/config/system-headers

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

.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=			Does not build on sparc64-9: fails to link
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == "arm"
PLIST_SUB+=	ARM=""
.else
PLIST_SUB+=	ARM="@comment "
.endif

.if ${ARCH} == "mips"
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "powerpc64"
PLIST_SUB+=	PPC=""
.else
PLIST_SUB+=	PPC="@comment "
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	--no-progress --worker-count=${MAKE_JOBS_NUMBER} ./js
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	--no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js
.endif

post-install:
	${LN} -s libmozjs185.so.1.0 ${PREFIX}/lib/libmozjs185.so.1

.include <bsd.port.post.mk>
