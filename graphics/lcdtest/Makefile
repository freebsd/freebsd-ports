# New ports collection makefile for:	lcdtest
# Date created:			23 Mar 2007
# Whom:				Eric P. Scott <eps+pbug0703@ana.com>
#
# $FreeBSD$
#

PORTNAME=	lcdtest
PORTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	LCD monitor test pattern generator

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

USE_SDL=	sdl image ttf

CFLAGS+=	-I${LOCALBASE}/include -DRELEASE=1.18
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lSDL -lSDL_image -lSDL_ttf

PLIST_FILES=	bin/lcdtest
PORTDOCS=	README

MAN1=	lcdtest.1

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/fonts/liberation/|${LOCALBASE}/lib/X11/fonts/Liberation/|' \
		${WRKSRC}/src/lcdtest.c

do-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o lcdtest.o -c lcdtest.c)
	(cd ${WRKSRC}/src && ${CC} ${LDFLAGS} -o lcdtest lcdtest.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lcdtest ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/lcdtest.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
