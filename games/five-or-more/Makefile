# $FreeBSD$
#   $MCom: ports/trunk/games/five-or-more/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	five-or-more
PORTVERSION=	3.10.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Form a line of 5 or more colored balls

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.five-or-more.gschema.xml

.include <bsd.port.mk>
