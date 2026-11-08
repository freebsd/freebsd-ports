PORTNAME=	sagittarius
PORTVERSION=	0.9.13
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ktakashi/sagittarius-scheme/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	-scheme

PATCH_SITES=	https://github.com/ktakashi/sagittarius-scheme/commit/
PATCHFILES=	87300eac81f3a3bd869e5c70f22cf1fdec0ab64e.patch:-p1 \
		88e6dde7e155a00404c771a0560245f459da8d18.patch:-p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	R6RS/R7RS Scheme system
WWW=		https://github.com/ktakashi/sagittarius-scheme

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libffi.pc:devel/libffi
LIB_DEPENDS=	libffi.so:devel/libffi \
		libgc-threaded.so:devel/boehm-gc-threaded

USES=		cmake pkgconfig ssl
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ODBC SIMD

PLIST_SUB=	PORTNAME=sagittarius PORTVERSION=${PORTVERSION}

ODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
ODBC_CMAKE_ON=		-DODBC_INCLUDE_DIR:STRING=${LOCALBASE}/include/libiodbc
SIMD_CMAKE_BOOL=	USE_SSE
OPTIONS_SUB=		yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

.if ${ARCH}=="i386"
PLIST_ARCH=	i386
USE_GCC=	yes
.elif ${ARCH} == "amd64"
PLIST_ARCH=	x86_64
.else
PLIST_ARCH=	${ARCH}
.endif

PLIST_SUB+=	PLIST_ARCH=${PLIST_ARCH}

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
# FindSSE.cmake runs cpuid(1) on FreeBSD/x86; provide our own copy
pre-configure:
	@${CC} ${CFLAGS} -o ${WRKDIR}/cpuid ${FILESDIR}/cpuid.c
	@${REINPLACE_CMD} -e 's,cpuid,${WRKDIR}/cpuid,' ${WRKSRC}/cmake/FindSSE.cmake
.endif

post-patch-ODBC-off:
	@${REINPLACE_CMD} -e '/odbc odbc/d' ${WRKSRC}/ext/CMakeLists.txt

post-install:
	@${LN} -sf sagittarius ${STAGEDIR}${PREFIX}/bin/sash

.include <bsd.port.post.mk>
