# New ports collection makefile for:	zimg
# Version required:	2.4.0
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	zimg-2.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.zellner.org/zimg/download/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	gd.0:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-edf --with-gd-includes=${LOCALBASE}/include
MAN1=		zimg.1

.include <bsd.port.mk>
