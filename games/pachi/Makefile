PORTNAME=	pachi
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/dragontech/Pachi%20el%20marciano/Pachi%20el%20marciano%20${PORTVERSION}
DISTNAME=	pachi_source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game similar to Manic Miner

USE_SDL=	mixer sdl
USES=		gmake sdl tar:tgz
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/Pachi

SCOREDIR=	/var/games/${PORTNAME}
SCOREFILE=	${SCOREDIR}/scores.dat

SUB_FILES=      pkg-deinstall pkg-install
SUB_LIST=       SCOREDIR="${SCOREDIR}" SCOREFILE="${SCOREFILE}"

PORTDATA=	*

DESKTOP_ENTRIES="Pachi el marciano" \
		"${COMMENT}" \
		"${DATADIR}/Tgfx/icon.bmp" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/games/$$PACKAGE|${SCOREDIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|SCOREDIR[^,]*|"${SCOREFILE}"|' \
		${WRKSRC}/src/file.c
	@${REINPLACE_CMD} -e 's|:\ install-docDATA|:|' \
		${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e 's|install-scoreDATA\ install-data-local||' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
