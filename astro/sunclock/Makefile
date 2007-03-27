# ex:ts=8
# New ports collection makefile for:	sunclock
# Date created:		15 September 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sunclock
PORTVERSION=	3.56
CATEGORIES=	astro x11-clocks
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/sunclock/ \
		http://mbsd.msk.ru/dist/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Shows which portion of the Earth's surface is illuminated by the Sun

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_XPM=	yes
USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include

MAN1=		sunclock.1

.include <bsd.port.mk>
