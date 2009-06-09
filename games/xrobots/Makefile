# New ports collection makefile for:    xrobots
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xrobots
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ss-10.20

MAINTAINER=	edwin@mavetju.org
COMMENT=	Fight off villainous robots (X version)

USE_IMAKE=	yes
USE_XORG=	x11 xaw xext xmu xt sm ice
WRKSRC=		${WRKDIR}/xrobots-1.0
MAN6=		xrobots.6

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xrobotscores ${PREFIX}/lib/X11

post-patch:
	${REINPLACE_CMD} -e 's|__PREFIX__|${PREFIX}|g' \
		${WRKSRC}/xrobots.man ${WRKSRC}/Imakefile

.include <bsd.port.mk>
