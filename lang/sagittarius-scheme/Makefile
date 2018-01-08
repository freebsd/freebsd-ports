# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sagittarius
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/ktakashi/sagittarius-scheme/downloads/ \
		LOCAL/ashish
PKGNAMESUFFIX=	-scheme

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	R6RS/R7RS Scheme system

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libffi.pc:devel/libffi
LIB_DEPENDS=	libffi.so:devel/libffi \
		libgc-threaded.so:devel/boehm-gc-threaded

USE_LDCONFIG=	yes
USES=		cmake pkgconfig
ONLY_FOR_ARCHS=	amd64 i386
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ODBC SIMD

PLIST_SUB=	PORTNAME=sagittarius PORTVERSION=${PORTVERSION}

ODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
ODBC_CMAKE_ON=		-DODBC_INCLUDE_DIR:STRING=${LOCALBASE}/include/libiodbc
SIMD_CMAKE_BOOL=	USE_SSE
OPTIONS_SUB=		yes

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
PLIST_ARCH=	i386
USE_GCC=	yes
.else
PLIST_ARCH=	x86_64
.endif

PLIST_SUB+=	PLIST_ARCH=${PLIST_ARCH}

pre-configure:
	@${CC} ${CFLAGS} -o ${WRKDIR}/cpuid ${FILESDIR}/cpuid.c
	@${REINPLACE_CMD} -e 's,cpuid,${WRKDIR}/cpuid,' ${WRKSRC}/cmake/FindSSE.cmake

post-patch-ODBC-off:
	@${REINPLACE_CMD} -e '/odbc odbc/d' ${WRKSRC}/ext/CMakeLists.txt

post-install:
	@${LN} -sf ${PREFIX}/bin/sagittarius ${STAGEDIR}${PREFIX}/bin/sash

.include <bsd.port.post.mk>
