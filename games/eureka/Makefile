# Created by: Kalten <kalten@gmx.at>

PORTNAME=	eureka
DISTVERSION=	1.27b
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-editor/Eureka/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	kalten@gmx.at
COMMENT=	Map editor for various Doom-derived games

LICENSE=	GPLv2+

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		compiler:c++0x desktop-file-utils gl gmake jpeg xorg
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrender

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
