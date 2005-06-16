# New ports collection makefile for:	epsilon
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	epsilon
PORTVERSION=	0.3.0.003
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A small, display independent, and quick thumbnailing library

LIB_DEPENDS=	epeg.9:${PORTSDIR}/graphics/epeg

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
