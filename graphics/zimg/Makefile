# New ports collection makefile for:	zimg
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	zimg
PORTVERSION=	2.5.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.zellner.org/zimg/download/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-edf --with-gd-includes=${LOCALBASE}/include
MAN1=		zimg.1

.include <bsd.port.mk>
