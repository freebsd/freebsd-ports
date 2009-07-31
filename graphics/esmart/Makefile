# New ports collection makefile for:	esmart
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	0.9.0.042
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Evas smart objects development libraries


GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	ecore evas epsilon edje imlib2
USE_EFL_ECORE=	x11 evas
USE_EFL_EVAS_LOADERS=	png jpeg
USE_LDCONFIG=	yes

.include <bsd.port.mk>
