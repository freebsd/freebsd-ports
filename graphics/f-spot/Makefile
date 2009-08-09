# New ports collection makefile for:		f-spot
# Date created:					20041008
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	f-spot
PORTVERSION=	0.6.0.0
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal photo management to the GNOME desktop

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		exif.12:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib

USE_BZIP2=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} 's|#!/bin/bash|#!/usr/bin/env bash|g' \
		${WRKSRC}/src/f-spot.in \
		${WRKSRC}/tools/f-spot-import

.include <bsd.port.mk>
