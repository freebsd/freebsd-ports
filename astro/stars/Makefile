# Created by: searle
# $FreeBSD$

PORTNAME=	stars
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://hpux.connect.org.uk/ftp/hpux/X11/Demos/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-11.00

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Star field demo

PLIST_FILES=	bin/stars
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		xorg
USE_XORG=	x11

do-build:
	${CC} -I${PREFIX}/include ${CFLAGS} -c ${WRKSRC}/xwin.c -o ${WRKSRC}/xwin.o
	${CC} -I${PREFIX}/include ${CFLAGS} -c ${WRKSRC}/main.c -o ${WRKSRC}/main.o
	${CC} ${WRKSRC}/main.o ${WRKSRC}/xwin.o -L${PREFIX}/lib -lX11 -lm -o ${WRKSRC}/stars

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stars ${STAGEDIR}${PREFIX}/bin/stars

.include <bsd.port.mk>
