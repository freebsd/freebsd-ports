# New ports collection makefile for:    duhdraw
# Date created:         March 18 2002
# Whom:                 Kyle Martin <mkm@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	duhdraw
PORTVERSION=	2.7.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/duhdraw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ANSI graphic drawing program

USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC} ${CFLAGS}"

PLIST_FILES=	bin/ansi bin/ansitoc bin/duhdraw

post-patch:
	@${REINPLACE_CMD} -e '/<malloc.h>/d' ${WRKSRC}/duhdraw.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ansi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ansitoc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/duhdraw ${PREFIX}/bin

.include <bsd.port.mk>
