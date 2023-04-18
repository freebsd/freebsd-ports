PORTNAME=	caterva
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multidimensional data container on top of Blosc2
WWW=		https://github.com/Blosc/caterva

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use archivers/c-blosc2 instead. All the features of Caterva have been included in the C-Blosc2 NDim object
EXPIRATION_DATE=2023-06-30

USES=		cmake:testing pkgconfig

CFLAGS+=	-I${WRKSRC}/contribs/c-blosc2/blosc
CMAKE_OFF=	CATERVA_BUILD_TESTS CATERVA_ENABLE_ASAN CATERVA_ENABLE_COVERAGE CATERVA_PREFER_BLOSC2_EXTERNAL
CMAKE_ON=	CATERVA_BUILD_BENCH CATERVA_BUILD_EXAMPLES CATERVA_SHARED_LIB CATERVA_STATIC_LIB
CMAKE_TESTING_ON=	CATERVA_BUILD_TESTS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_TUPLE=	Blosc:caterva:2db4e9c \
		Blosc:c-blosc2:v2.4.3:c_blosc2/contribs/c-blosc2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
