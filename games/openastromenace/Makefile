# Created by: Oleg Alexeenkov
# $FreeBSD$

PORTNAME=	openastromenace
PORTVERSION=	1.3.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	astromenace-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LICENSE=	GPLv3

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cmake openal:al,alut tar:bzip2
USE_XORG=	x11 xinerama
USE_GL=		gl glu
USE_SDL=	sdl
WRKSRC=		${WRKDIR}/AstroMenace
CMAKE_ARGS=	-DDATADIR="${DATADIR}"

PLIST_FILES=	bin/AstroMenace \
		share/pixmaps/${PORTNAME}.png
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="AstroMenace" "" \
		"${PORTNAME}" "AstroMenace" \
		"Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC} && ./AstroMenace dos2unix --pack --rawdata=./RAW_VFS_DATA --dir="${WRKSRC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AstroMenace ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gamedata.vfs ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/astromenace_128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
