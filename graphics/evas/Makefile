# New ports collection makefile for:	evas
# Date created:		24 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	0.9.9.013
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A hardware-accelerated canvas API for X-Windows

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb \
		eet.9:${PORTSDIR}/devel/eet

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_FREETYPE2=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=        --enable-mmx
.endif

.include <bsd.port.post.mk>
