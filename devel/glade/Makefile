# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glade
PORTVERSION=	3.18.3
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+ 3

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	glade3-3.*
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 gnomedocutils intlhack
#		introspection:build
# temp disable, introspection generation crashes with GNOME 3.15
CONFIGURE_ARGS=	--disable-introspection
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES=	python:3
PYTHON_USE=	GNOME=py3gobject3

.include <bsd.port.mk>
