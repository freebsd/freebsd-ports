# New ports collection makefile for:   stars-1.0
# Date created:		10 Jul 1996
# Whom:			searle
#
# $FreeBSD$
#

PORTNAME=	stars
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.planetmirror.com/pub/hpux/X11/Demos/stars-1.0/ \
		http://public.www.planetmirror.com/pub/hpux/X11/Demos/stars-1.0/
DISTNAME=	stars-1.0-ss-11.00

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Star field demo

PLIST_FILES=	bin/stars
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes

do-build:
	${CC} -I${PREFIX}/include ${CFLAGS} -c ${WRKSRC}/xwin.c -o ${WRKSRC}/xwin.o
	${CC} -I${PREFIX}/include ${CFLAGS} -c ${WRKSRC}/main.c -o ${WRKSRC}/main.o
	${CC} ${WRKSRC}/main.o ${WRKSRC}/xwin.o -L${PREFIX}/lib -lX11 -lm -o ${WRKSRC}/stars

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stars ${PREFIX}/bin/stars

.include <bsd.port.mk>
