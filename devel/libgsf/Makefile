# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgsf/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	libgsf
PORTVERSION=	1.14.28
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 glib20 gnomeprefix intlhack introspection:build \
		libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
