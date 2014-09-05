# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gucharmap/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	gucharmap
PORTVERSION=	3.12.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-Bsymbolic
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml org.gnome.Charmap.gschema.xml

.include <bsd.port.mk>
