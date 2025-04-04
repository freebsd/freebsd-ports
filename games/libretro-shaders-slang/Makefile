PORTNAME=	libretro-shaders-slang
DISTVERSION=	g20250313
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
GH_TAGNAME=	25311dc03332d9ef2dff8d9d06c611d828028fac

MAKE_ARGS=	PREFIX=${PREFIX}

DATADIR=	${PREFIX}/share/libretro/shaders/shaders_slang
NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
