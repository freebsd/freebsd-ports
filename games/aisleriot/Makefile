# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aisleriot
PORTVERSION=	3.22.5
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of patience games written in guile scheme

BUILD_DEPENDS=	itstool:textproc/itstool \
		bash:shells/bash
LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgc-threaded.so:devel/boehm-gc-threaded

CONFLICTS_INSTALL=	sol-[0-9]*
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome pathfix pkgconfig \
		tar:xz xorg
USE_GNOME=	cairo gconf2 gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-card-theme-formats=svg
# work around because configure needs bash
CONFIGURE_SHELL=${LOCALBASE}/bin/bash

GCONF_SCHEMAS=	aisleriot.schemas
GLIB_SCHEMAS=	org.gnome.Patience.WindowState.gschema.xml

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
