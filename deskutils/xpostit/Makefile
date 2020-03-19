# Created by: joerg
# $FreeBSD$

PORTNAME=	xpostit
PORTVERSION=	3.3.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
# DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	PostIt (R) messages onto your X11 screen

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

.include <bsd.port.mk>
