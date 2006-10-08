# New ports collection makefile for:	esmart
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	20060926
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Evas smart objects development libraries

LIB_DEPENDS=	epsilon.0:${PORTSDIR}/graphics/epsilon

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl:15
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	ecore evas epsilon edje
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
