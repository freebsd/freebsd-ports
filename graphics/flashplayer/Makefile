# New ports collection makefile for:	flashplayer
# Date created:		2 October 1999
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplayer
PORTVERSION=	0.4.10
CATEGORIES=	graphics
MASTER_SITES=	http://www.swift-tools.com/Flash/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	flash.0:${.CURDIR}/../libflash

WRKSRC=		${WRKDIR}/${DISTNAME}/Player

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
