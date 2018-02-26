# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	devhelp
PORTVERSION=	3.24.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LICENSE=	GPLv2
LICENSE_FILES=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool localbase \
		pathfix pkgconfig python:3.3+,build tar:xz
USE_GNOME=	cairo gtk30 introspection
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-Werror

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.devhelp.gschema.xml

.include <bsd.port.mk>
