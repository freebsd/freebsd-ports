# New ports collection makefile for:    librsvg
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsvg
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/librsvg/1.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs gdkpixbuf
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
