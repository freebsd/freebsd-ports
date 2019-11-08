# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brikx
PORTVERSION=	0.4.5
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		SF/brikx/Brikx/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game - remove all tiles from the table

USES=		sdl tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image ttf
USE_CXXSTD=	c++98

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="Brikx" \
		"Puzzle game" \
		"${DATADIR}/tilesets/stone/49.png" \
		"brikx" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/\/-L\/-R\// d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/DIR_DATA/ s|data/|${DATADIR}/|' \
		${WRKSRC}/src/brikx.h

post-install:
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
