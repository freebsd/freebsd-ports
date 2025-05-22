PORTNAME=	libretro-shaders-slang
DISTVERSION=	g20250521
CATEGORIES=	games

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Collection of slang shaders from libretro
WWW=		https://github.com/libretro/slang-shaders

# https://github.com/libretro/slang-shaders/issues/150
LICENSE=	GPLv1+ GPLv2+ GPLv3+ MIT PD
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	slang-shaders
GH_TAGNAME=	8c630e0d3234d93b6c2bc847371f86aa4e535686

MAKE_ARGS=	PREFIX=${PREFIX}

DATADIR=	${PREFIX}/share/libretro/shaders/shaders_slang
NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
