# Created by: Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
# $FreeBSD$

PORTNAME=	wmGrabImage
PORTVERSION=	0.72
PORTREVISION=	7
CATEGORIES=	graphics windowmaker
MASTER_SITES=	http://dockapps.org/files/12/19/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sascha@root-login.org
COMMENT=	Monitor your favorite web image

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

WRKSRC=		${WRKDIR}/${DISTNAME}/wmGrabImage

USE_XORG=	xpm

MAN1=		wmGrabImage.1

NO_STAGE=	yes
.include <bsd.port.mk>
