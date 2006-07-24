# New ports collection makefile for:	evas
# Date created:		24 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	0.9.9.032
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A hardware-accelerated canvas API for X-Windows

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb \
		eet.9:${PORTSDIR}/devel/eet

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_FREETYPE2=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

OPTIONS=	GL "Enable GL support" off

PLIST_SUB+=	MODULE_ARCH=freebsd${OSREL}-${ARCH}

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
CONFIGURE_ARGS+=	--enable-gl-x11
PLIST_SUB+=	WITH_GL=""
USE_GL=		yes
.else
PLIST_SUB+=	WITH_GL="@comment "
.endif

.include <bsd.port.post.mk>
