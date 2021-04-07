PORTNAME=	volleyball
PORTVERSION=	0.8.6
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/volleyball/descargas/ \
		http://mirror.amdmi3.ru/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Game similar to GNU Arcade Volleyball

USES=		gmake sdl
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man" --disable-nls # strangeness in nls support
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/volleyball.6.gz
PORTDOCS=	*
PORTDATA=	*

DATAVERSION=	0.8.5

DESKTOP_ENTRIES="Pocket Volleyball" \
		"A game similar to GNU Arcade Volleyball" \
		"" \
		"volleyball" \
		"Game;SportsGame;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/libintl\.h/d' ${WRKSRC}/src/common.h
	@${REINPLACE_CMD} -e '/setlocale/d' -e '/textdomain/d' \
		${WRKSRC}/src/volleyball.c

post-configure:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

post-install:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
