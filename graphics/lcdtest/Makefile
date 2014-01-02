# Created by: Eric P. Scott <eps+pbug0703@ana.com>
# $FreeBSD$

PORTNAME=	lcdtest
PORTVERSION=	1.18
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	LCD monitor test pattern generator

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

USE_SDL=	sdl image ttf

CFLAGS+=	-I${LOCALBASE}/include -DRELEASE=1.18
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lSDL -lSDL_image -lSDL_ttf

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/liberation/|${LOCALBASE}/lib/X11/fonts/Liberation/|' \
		${WRKSRC}/src/lcdtest.c

do-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o lcdtest.o -c lcdtest.c)
	(cd ${WRKSRC}/src && ${CC} ${LDFLAGS} -o lcdtest lcdtest.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/desktop/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
