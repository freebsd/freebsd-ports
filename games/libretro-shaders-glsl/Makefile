PORTNAME=	libretro-shaders-glsl
DISTVERSION=	g20260823
CATEGORIES=	games

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Collection of GLSL shaders from libretro
WWW=		https://github.com/libretro/glsl-shaders

# https://github.com/libretro/glsl-shaders/issues/128
LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	glsl-shaders
GH_TAGNAME=	4f4eb801b2dbcaed0a9669a9deec1a098f3623d8

DATADIR=	${PREFIX}/share/libretro/shaders/shaders_glsl

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/.gitlab-ci.yml \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/Makefile \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/configure \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
