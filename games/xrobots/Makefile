# Created by: swallace
# $FreeBSD$

PORTNAME=	xrobots
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ss-10.20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fight off villainous robots (X version)

USES=		imake xorg
USE_XORG=	x11 xaw xext xmu xt sm ice
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${CP} ${FILESDIR}/xrobotscores ${STAGEDIR}${PREFIX}/lib/X11

pre-build:
	${REINPLACE_CMD} -e 's|__PREFIX__|${PREFIX}|g' \
		${WRKSRC}/xrobots.man ${WRKSRC}/Imakefile

.include <bsd.port.mk>
