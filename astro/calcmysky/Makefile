PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	astro

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Planetary atmosphere light scattering simulator
WWW=		https://github.com/10110111/CalcMySky

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Dense:math/eigen3 \
		${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		cmake:testing localbase qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	10110111
GH_PROJECT=	CalcMySky
USE_QT=		buildtools:build qmake:build core gui opengl widgets

CMAKE_ARGS=	-DQT_VERSION:STRING=5

.include <bsd.port.mk>
