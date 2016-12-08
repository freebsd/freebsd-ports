# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/deskutils/planner/Makefile,v 1.4 2009/04/16 00:34:24 kwm Exp $

PORTNAME=	planner
PORTVERSION=	0.14.6
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for GNOME 2

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_GNOME=	gnomeprefix intlhack libgnomeui libgnomeprintui \
		libgsf
WANT_GNOME=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-python \
		--disable-python-plugin \
		--disable-update-mimedb
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	planner.schemas

.include <bsd.port.mk>
