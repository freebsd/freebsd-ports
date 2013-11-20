# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/ghex3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	ghex
PORTVERSION=	3.8.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 hex editor

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2:build
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.GHex.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtkhex-3.so.0

.include <bsd.port.mk>
