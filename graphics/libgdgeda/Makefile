# New ports collection makefile for:	libgdgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgdgeda
PORTVERSION=	2.0.15
CATEGORIES=	graphics cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/devel/support/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Special version of the gd graphic lib for use by gEDA programs

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

DEPRECATED=	is not required anymore
EXPIRATION_DATE=	2009-02-22

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
