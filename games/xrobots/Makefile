# New ports collection makefile for:    xrobots
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xrobots
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PKGNAME}-ss-10.20

MAINTAINER=	edwin@mavetju.org
COMMENT=	Fight off villainous robots (X version)

USE_REINPLACE=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xrobots-1.0
MAN6=		xrobots.6

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xrobotscores ${PREFIX}/lib/X11

post-patch:
	${REINPLACE_CMD} -e 's|__PREFIX__|${PREFIX}|g' \
		${WRKSRC}/xrobots.man ${WRKSRC}/Imakefile

.include <bsd.port.mk>
