# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/aisleriot/Makefile 19848 2014-09-05 10:39:20Z kwm $

PORTNAME=	aisleriot
PORTVERSION=	3.12.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of patience games written in guile scheme

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libguile-2.0.so:${PORTSDIR}/lang/guile2 \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

CONFLICTS=	sol-*

USES=		desktop-file-utils gmake pathfix pkgconfig tar:xz
USE_GNOME=	gconf2 gtk30 librsvg2 libxml2:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-card-theme-formats=svg \
		--with-guile=2.0

GCONF_SCHEMAS=	aisleriot.schemas
GLIB_SCHEMAS=	org.gnome.Patience.WindowState.gschema.xml

.include <bsd.port.mk>
