# Created by: Kyle Evans <bsdports@kyle-evans.net>
# $FreeBSD$

PORTNAME=	zdoom
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Source port for Doom-engine games

LICENSE=	DOOM
LICENSE_NAME=	Limited Use Software License Agreement
LICENSE_FILE=	${WRKSRC}/docs/doomlic.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile

USE_GITHUB=	yes
GH_ACCOUNT=	rheit

PORTSCOUT=	limit:^.+\.[1-9]{1,3}[1-8]?$$

DATADIR=	${DMDIR}/${PORTNAME}

USES=		cmake:outsource	gettext jpeg openal pkgconfig
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 pango
USE_SDL=	sdl2
CMAKE_ARGS=	-DNO_FMOD:BOOL=ON
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"

DESKTOP_ENTRIES=	"ZDoom" "" "${PORTNAME}" "${PORTNAME}" "Game;Shooter;" ""

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/${PORTNAME}.pk3 \
		share/pixmaps/${PORTNAME}.xpm

OPTIONS_DEFINE=	FLUIDSYNTH
OPTIONS_DEFAULT=FLUIDSYNTH

FLUIDSYNTH_DESC=	FluidSynth sound library support
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_BOOL=	WITH_FLUIDSYNTH

.include "${.CURDIR}/../doom-data/Makefile.include"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/${PORTNAME}.pk3 ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
