PORTNAME=	spacezero
PORTVERSION=	0.86.00
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION:R}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D Real Time Strategy space combat game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		openal:al,alut gnome pkgconfig xorg
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_XORG=	x11
MAKE_ARGS=	DATADIR="${DATADIR}" \
		INSTALL_DATA_DIR="${DATADIR}"
ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

LDFLAGS+=	-lX11
LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.ico

DESKTOP_ENTRIES="SpaceZero" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/html/manual_files/space.ico ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/dat && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
