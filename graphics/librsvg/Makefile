# New ports collection makefile for:    librsvg
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/librsvg/Makefile,v 1.2 2006/09/10 00:51:11 mezz Exp $

PORTNAME=	librsvg
PORTVERSION=	1.0.3
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

DEPRECATED=	unmaintained and not used anymore
EXPIRATION_DATE=	2011-11-06

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gdkpixbuf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
