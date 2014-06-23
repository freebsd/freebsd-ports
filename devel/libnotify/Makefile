# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libnotify/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libnotify
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	intlhack glib20 gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
