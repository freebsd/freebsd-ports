# New ports collection makefile for:	xmahjongg
# Date created:		16 Aug 1996
# Whom:			joerg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	xmahjongg
PORTVERSION=	3.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.lcdf.org/xmahjongg/

MAINTAINER=	joerg@freebsd.org
COMMENT=	The Chinese game of Mahjongg for X11

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN6=		xmahjongg.6

.include <bsd.port.mk>
