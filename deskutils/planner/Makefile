# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/deskutils/planner/Makefile,v 1.4 2009/04/16 00:34:24 kwm Exp $

PORTNAME=	planner
PORTVERSION=	0.14.6
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for GNOME 2

USE_XZ=		yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui libgnomeprintui \
		libgsf desktopfileutils
WANT_GNOME=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-python \
		--disable-python-plugin
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	planner.schemas

.include <bsd.port.mk>
