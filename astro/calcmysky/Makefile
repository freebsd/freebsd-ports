PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	astro

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Planetary atmosphere light scattering simulator
WWW=		https://github.com/10110111/CalcMySky

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		cmake:testing eigen:3 localbase qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	10110111
GH_PROJECT=	CalcMySky
USE_QT=		buildtools:build qmake:build core gui opengl widgets

CMAKE_ARGS=	-DQT_VERSION:STRING=5

.include <bsd.port.mk>
