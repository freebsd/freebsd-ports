# New ports collection makefile for:	gThumb2
# Date created:				17 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gthumb
PORTVERSION=	2.10.12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	pav@FreeBSD.org
COMMENT=	An image viewer and browser for the GNOME 2 environment

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui gnomedocutils
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gthumb.schemas
MAN1=		gthumb.1

OPTIONS=	GPHOTO2 "Support loading photos from digital cameras" On \
		IPTCDATA "Support for IPTC metadata" Off \
		OPENRAW "Support for camera RAW files" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
CONFIGURE_ARGS+=--enable-gphoto2
.else
CONFIGURE_ARGS+=--disable-gphoto2
.endif

.if defined(WITH_IPTCDATA)
LIB_DEPENDS+=	iptcdata.3:${PORTSDIR}/graphics/libiptcdata
CONFIGURE_ARGS+=--enable-iptcdata
.else
CONFIGURE_ARGS+=--disable-iptcdata
.endif

.if defined(WITH_OPENRAW)
LIB_DEPENDS+=	openrawgnome.6:${PORTSDIR}/graphics/libopenraw
CONFIGURE_ARGS+=--enable-libopenraw
.else
CONFIGURE_ARGS+=--disable-libopenraw
.endif

.include <bsd.port.post.mk>
