# $FreeBSD$

PORTNAME=	armagetronad
DISTVERSION=	0.2.8.3.5
DISTVERSIONSUFFIX=	.src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/stable/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tron clone in 3D

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf desktop-file-utils gl gmake gnome jpeg sdl
GNU_CONFIGURE=	yes
USE_SDL=	image mixer sdl
USE_GL=		gl glu
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CONFIGURE_ARGS=	--disable-etc --disable-games --enable-music

INSTALLS_ICONS=	yes

BINARY_ALIAS=	sdl11-config=sdl-config

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/desktop/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop
.for SZ in 16 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
.endfor
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/small/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/${PORTNAME}.png
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/medium/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/large/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	@${RM} -r ${STAGEDIR}${DATADIR}/desktop

.include <bsd.port.mk>
