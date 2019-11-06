# Created by: joerg
# $FreeBSD$

PORTNAME=	xpostit
PORTVERSION=	3.3.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	PostIt (R) messages onto your X11 screen

BROKEN=		unfetchable

USES=		imake tar:Z xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
WRKSRC=		${WRKDIR}/xpostit

.include <bsd.port.mk>
