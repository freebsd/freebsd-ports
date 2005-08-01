# New ports collection makefile for:	esmart
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	0.9.0.004
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Evas smart objects development libraries

LIB_DEPENDS=	epsilon.0:${PORTSDIR}/graphics/epsilon

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_LIBLTDL=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
