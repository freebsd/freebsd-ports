# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gucharmap/Makefile 20060 2014-11-10 21:29:58Z gusi $

PORTNAME=	gucharmap
PORTVERSION=	3.14.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		appdata-tools>=0:${PORTSDIR}/devel/appdata-tools

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-Bsymbolic
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml org.gnome.Charmap.gschema.xml

.include <bsd.port.mk>
