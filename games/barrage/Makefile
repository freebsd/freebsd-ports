# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	barrage
PORTVERSION=	1.0.5
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Destroy as many targets as possible

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake gnome sdl
USE_SDL=	sdl mixer

GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog README
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/configure

post-install:
	${LN} -sf ${PREFIX}/share/icons/${PORTNAME}48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
