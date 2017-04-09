# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libnotify/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libnotify
PORTVERSION=	0.7.7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	intlhack glib20 gdkpixbuf2 introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-tests

.include <bsd.port.mk>
