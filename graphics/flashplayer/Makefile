# New ports collection makefile for:	flashplayer
# Date created:		2 October 1999
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplayer
PORTVERSION=	0.4.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.swift-tools.net/Flash/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL standalone Flash (TM) player

LIB_DEPENDS=	flash.0:${.CURDIR}/../libflash

PLIST_FILES=	bin/swfplayer
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Player

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
