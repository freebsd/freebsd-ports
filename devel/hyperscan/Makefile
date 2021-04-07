PORTNAME=	hyperscan
PORTVERSION=	5.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc
MASTER_SITES=	SF/boost/boost/${BOOST_VERSION}:boost
DISTFILES=	boost_${BOOST_VERSION_UNDER}.tar.gz:boost

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	High-performance multiple regex matching library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ragel:devel/ragel

USE_GITHUB=	yes
GH_ACCOUNT=	intel
USES=	compiler:c++11-lib cmake pathfix python:build
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	SSSE3 is required for work

OPTIONS_DEFINE=	SHARED NATIVE
SHARED_DESC=		Build shared library
NATIVE_DESC=		Build with native CPU tunes
OPTIONS_DEFAULT=	SHARED

CMAKE_ARGS+=	-DBOOST_ROOT=${WRKDIR}/boost_${BOOST_VERSION_UNDER}

NATIVE_CXXFLAGS=	-march=native -mtune=native
NATIVE_CFLAGS=		-march=native -mtune=native

NATIVE_CXXFLAGS_OFF=	-march=core2
NATIVE_CFLAGS_OFF=	-march=core2

CFLAGS+=	-fPIC
BOOST_VERSION=	1.75.0
BOOST_VERSION_UNDER=	${BOOST_VERSION:C/\./_/g}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED}
CMAKE_ARGS+=	-DBUILD_STATIC_AND_SHARED=ON
PLIST_SUB+=	SHARED="" \
		SOVERSION=${PORTVERSION} \
		SOSHORTVERSION=${PORTVERSION:C/\.[0-9].[0-9]$//}
.else
PLIST_SUB+=	SHARED="@comment "
.endif

# don't build hsbench tool
post-patch:
	${RM} ${WRKSRC}/tools/CMakeLists.txt

do-test:
	cd ${BUILD_WRKSRC} && ${MAKE_CMD} unit

.include <bsd.port.mk>
