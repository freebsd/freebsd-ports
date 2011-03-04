# New ports collection makefile for:		f-spot
# Date created:					20041008
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	f-spot
PORTVERSION=	0.8.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal photo management to the GNOME desktop

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		exif.12:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-sharp-1.0.pc:${PORTSDIR}/security/gnome-keyring-sharp \
		${LOCALBASE}/libdata/pkgconfig/flickrnet.pc:${PORTSDIR}/devel/flickrnet
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-sharp-1.0.pc:${PORTSDIR}/security/gnome-keyring-sharp \
		${LOCALBASE}/libdata/pkgconfig/flickrnet.pc:${PORTSDIR}/devel/flickrnet

USE_BZIP2=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	f-spot.schemas

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS+=--with-vendor-build-id=FreeBSD\ BSD\#\ Project

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

post-patch:
	@${REINPLACE_CMD} 's|#!/bin/bash|#!/usr/bin/env bash|g' \
		${WRKSRC}/src/Clients/MainApp/f-spot.in

.include <bsd.port.mk>
