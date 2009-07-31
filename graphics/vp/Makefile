# New ports collection makefile for:	vp
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	vp
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://bzflag.bz/~erik/files/

MAINTAINER=	erik@smluc.org
COMMENT=	An image viewer for X

USE_SDL=	image
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		vp.1
PLIST_FILES=	bin/vp

.include <bsd.port.mk>
