PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	g20260716
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	f1a415ebe08c01ccf317.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable version of the original C&C engine
WWW=		https://github.com/TheAssemblyArmada/Vanilla-Conquer

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	TheAssemblyArmada
GH_PROJECT=	Vanilla-Conquer
GH_TAGNAME=	ce83b59

USES=		cmake openal sdl
USE_SDL=	sdl2
CMAKE_ON=	BUILD_TOOLS
CONFIGURE_ENV=	GIT_HEAD_SHA1=ce83b59edd99cccac6cebaae054ca04962c744b7 \
		GIT_HEAD_SHORT_SHA1=${GH_TAGNAME} \
		GIT_COMMIT_DATE_ISO8601=${_GET_DATE:sh} \
		GIT_AUTHOR_NAME=\<irrelevant\> GIT_TAG=latest \
		GIT_COMMIT_TSTAMP=${_GET_TSTAMP:sh} GIT_IS_DIRTY=true \
		GIT_RETRIEVED_STATE=true GIT_REV_LIST_COUNT=973
LDFLAGS_i386=	-Wl,-znotext

PLIST_FILES=	bin/vanillamix bin/vanillara bin/vanillatd \
		share/icons/hicolor/scalable/apps/vanillara_icon.svg \
		share/icons/hicolor/scalable/apps/vanillatd_icon.svg

PORTSCOUT=	skipv:latest

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/vanilla* \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/resources/*.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %FT%TZ ${WRKSRC}/.gitignore
_GET_TSTAMP=	TZ= ${STAT} -f %m ${WRKSRC}/.gitignore
