# New ports collection makefile for:	epeg
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	epeg
PORTVERSION=	0.9.0.003
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An IMMENSELY FAST JPEG thumbnailer library API

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
