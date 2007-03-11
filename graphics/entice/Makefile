# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	20070223
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An image viewer written using libraries for Enlightenment 0.17

LIB_DEPENDS=	esmart_thumb.0:${PORTSDIR}/graphics/esmart

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	imlib2 evas edb ecore edje epsilon
USE_EFL_ESMART=	thumb

.include <bsd.port.pre.mk>

.if ${ARCH}==ia64
BROKEN=		does not install on ${ARCH}
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
