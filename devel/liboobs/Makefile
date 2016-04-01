# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/liboobs/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	liboobs
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	system-tools-backends:sysutils/system-tools-backends
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libhal.so:sysutils/hal
RUN_DEPENDS=	system-tools-backends:sysutils/system-tools-backends

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-hal
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
