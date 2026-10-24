PORTNAME=	libretro-shaders-slang
DISTVERSION=	g20261022
CATEGORIES=	games

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Collection of Vulkan GLSL (slang) shaders from libretro
WWW=		https://github.com/libretro/slang-shaders

# https://github.com/libretro/slang-shaders/issues/150
LICENSE=	GPLv1+ GPLv2+ GPLv3+ MIT PD
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	slang-shaders
GH_TAGNAME=	2b0530bac0e8083d9d643c194929dc0a6b69bd35

DATADIR=	${PREFIX}/share/libretro/shaders/shaders_slang

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/.gitlab-ci.yml \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/Makefile \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/configure \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
