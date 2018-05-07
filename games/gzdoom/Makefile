# $FreeBSD$

PORTNAME=	gzdoom
PORTVERSION=	3.3.0
DISTVERSIONPREFIX=	g
CATEGORIES=	games

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GL-enhanced source port for Doom-engine games

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/docs/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/docs/licenses/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/docs/licenses/lgpl.txt

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile \
		libfluidsynth.so:audio/fluidsynth \
		libgme.so:audio/libgme

DATADIR=	${DMDIR}/${PORTNAME}

USES=		cmake:outsource	gettext jpeg openal pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers

USE_GNOME=	atk cairo gdkpixbuf2 gtk20 pango
USE_SDL=	sdl2
USE_GL=		gl glu
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"
LDFLAGS+=	-Wl,--as-needed

DESKTOP_ENTRIES=	"GZDoom" "" "${PORTNAME}" "${PORTNAME}" "Game;Shooter;" ""

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/${PORTNAME}.pk3 \
		share/pixmaps/${PORTNAME}.xpm

.include "${.CURDIR}/../doom-data/Makefile.include"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/${PORTNAME}.pk3 ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
