# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/eggdbus/Makefile,v 1.3 2009/11/24 01:46:27 marcus Exp $

PORTNAME=	eggdbus
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus bindings for GObject

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USE_GNOME=	glib20
USES=		gettext gmake libtool:keepla pathfix pkgconfig
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS+=	docbook-sgml>0:textproc/docbook-sgml \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch:
	@${REINPLACE_CMD} -e 's|-Wl,--as-needed||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
