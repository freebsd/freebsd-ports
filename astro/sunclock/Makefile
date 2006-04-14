# ex:ts=8
# New ports collection makefile for:	sunclock
# Date created:		15 September 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sunclock
PORTVERSION=	3.54.1
CATEGORIES=	astro x11-clocks
MASTER_SITES=	http://frmas.free.fr/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows which portion of the Earth's surface is illuminated by the Sun

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_XPM=	yes
USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		sunclock.1 emx.1

.include <bsd.port.mk>
