# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libpeas/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libpeas
PORTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USES=		gettext gmake libtool pathfix pkgconfig \
		python:3 tar:xz
USE_GNOME=	gtk30 introspection:build
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--disable-glade-catalog \
		--disable-python2

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PYTHON SEED
OPTIONS_DEFAULT=PYTHON SEED
SEED_DESC=	JavaScript support based on webkit-gtk3
SEED_LIB_DEPENDS=	libseed-gtk3.so:${PORTSDIR}/devel/seed
SEED_CONFIGURE_ENABLE=	seed	
PYTHON_USE=	GNOME=py3gobject3
PYTHON_CONFIGURE_ENABLE=	python3

.include <bsd.port.mk>
