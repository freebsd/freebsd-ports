# New ports collection makefile for:	zimg
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	zimg
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.zellner.org/zimg/download/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Image-generator that uses ASCII input files to create PNGs/EDFs

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	-with-gd-includes=${LOCALBASE}/include/gd

MAN1=		zimg.1

.include <bsd.port.mk>
