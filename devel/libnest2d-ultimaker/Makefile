PORTNAME=	libnest2d-ultimaker
DISTVERSION=	5.3.0
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	db@FreeBSD.org
COMMENT=	2D irregular bin packaging and nesting library
WWW=		https://github.com/Ultimaker/libnest2d

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libpolyclipping.so:graphics/polyclipping \
		libnlopt.so:math/nlopt

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_PROJECT=	libnest2d
STRIP=

CMAKE_ARGS+=	-DGEOMETRIES=clipper \
		-DOPTIMIZER=nlopt \
		-DTHREADING=omp

NO_ARCH=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@${CP} ${FILESDIR}/Findclipper.cmake ${WRKSRC}/cmake

do-install:
	@${CP} -r ${WRKSRC}/include/libnest2d ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
