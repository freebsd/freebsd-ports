PORTNAME=	rlottie
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2-49
DISTVERSIONSUFFIX=	-g327fb7d
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent standalone library that plays Lottie Animation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/licenses/COPYING.MIT

BROKEN_armv7=	undefined symbol: pixman_composite_src_n_8888_asm_neon

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Samsung

CMAKE_ARGS=	-DLIB_INSTALL_DIR=${PREFIX}/lib
CMAKE_TESTING_ON=	LOTTIE_TEST

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/example/lottie2gif ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
