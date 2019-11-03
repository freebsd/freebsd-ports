# Created by johalun0@gmail.com
# $FreeBSD$

PORTNAME=	libgudev
PORTVERSION=	230
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.gnome.org/sources/libgudev/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	GObject bindings for libudev.

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		gettext-runtime gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
