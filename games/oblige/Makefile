PORTNAME=	oblige
PORTVERSION=	7.70
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Oblige/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Random map generator for classic FPS games
WWW=		https://oblige.sourceforge.net/

LICENSE=	GPLv2+

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		gmake jpeg xorg zip
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender
MAKE_ARGS=	CXX="${CXX}"
WRKSRC=		${WRKDIR}/Oblige-${PORTVERSION}-source

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Oblige ${STAGEDIR}${PREFIX}/bin/oblige
	cd ${WRKSRC} && ${COPYTREE_SHARE} "addons data engines games \
		language modules scripts" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/misc/oblige.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/misc/oblige.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/misc/icon_128x128.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/oblige.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} changelogs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
