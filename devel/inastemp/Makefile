# $FreeBSD$

PORTNAME=	inastemp
DISTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.mpcdf.mpg.de/bbramas/${PORTNAME}/repository/${DISTVERSION}/archive.tar.gz?ref=v${PORTVERSION}&dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to use SIMD vectorization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
NO_ARCH=	yes
CMAKE_ARGS=	-DINASTEMP_DO_INSTALL:BOOL=ON \
		-DINASTEMP_JUST_LIB:BOOL=ON

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}-* ${WRKSRC}

.include <bsd.port.mk>
