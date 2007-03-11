# New ports collection makefile for:	esmart
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	20070223
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Evas smart objects development libraries

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl:15
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	ecore evas epsilon edje
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
