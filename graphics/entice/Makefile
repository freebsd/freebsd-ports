# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	20070915
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An image viewer written using libraries for Enlightenment 0.17

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	imlib2 evas edb ecore edje epsilon
USE_EFL_ECORE=	ipc
USE_EFL_ESMART=	thumb container draggies trans_x11

DEPRECATED=	Broken and unmaintained
EXPIRATION_DATE=	2008-03-20
BROKEN=		don't work with current EFL

.include <bsd.port.mk>
