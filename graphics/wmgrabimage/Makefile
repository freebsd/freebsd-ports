# New ports collection makefile for:	wmGrabImage
# Date created:		4th November 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmGrabImage
PORTVERSION=	0.72
PORTREVISION=	1
CATEGORIES=	graphics windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sascha@root-login.org

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

WRKSRC=		${WRKDIR}/${DISTNAME}/wmGrabImage

USE_X_PREFIX=	YES
USE_XPM=	YES

MAN1=		wmGrabImage.1

.include <bsd.port.mk>
