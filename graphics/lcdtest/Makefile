# Created by: Eric P. Scott <eps+pbug0703@ana.com>
# $FreeBSD$

PORTNAME=	lcdtest
PORTVERSION=	1.18
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	LCD monitor test pattern generator

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

USE_SDL=	sdl image ttf

CFLAGS+=	-I${LOCALBASE}/include -DRELEASE=1.18
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lSDL -lSDL_image -lSDL_ttf

PORTDOCS=	README

MAN1=	lcdtest.1

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/liberation/|${LOCALBASE}/lib/X11/fonts/Liberation/|' \
		${WRKSRC}/src/lcdtest.c

do-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o lcdtest.o -c lcdtest.c)
	(cd ${WRKSRC}/src && ${CC} ${LDFLAGS} -o lcdtest lcdtest.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/desktop/${PORTNAME}.svg ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/desktop/${PORTNAME}.desktop ${PREFIX}/share/applications/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
