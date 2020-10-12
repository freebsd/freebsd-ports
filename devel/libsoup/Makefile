# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsoup
PORTVERSION=	2.72.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>=2.29.18:net/glib-networking
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libpsl.so:dns/libpsl
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson \
		pkgconfig python:3.6+,build sqlite ssl tar:xz
USE_GNOME=	glib20 intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Dvapi=disabled \
		-Dsysprof=disabled \
		-Dtests=false \
		-Dgnome=true \
		-Dbrotli=disabled \
		-Dntlm=disabled

LIBVERSION=	1.11.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.include <bsd.port.mk>
