# New ports collection makefile for:	gThumb2
# Date created:				17 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gthumb2
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.3
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	pav@FreeBSD.org
COMMENT=	An image viewer and browser for the GNOME 2 environment

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack lthack libgnomeui libgnomeprintui
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gthumb.1

.include <bsd.port.pre.mk>

.if defined(WITH_EXIF) || exists(${LOCALBASE}/lib/libexif.so.10)
LIB_DEPENDS+=	exif.10:${PORTSDIR}/graphics/libexif
.endif

.if defined(WITH_GPHOTO2) || exists(${LOCALBASE}/lib/libgphoto2.so.2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
.endif

.include <bsd.port.post.mk>
