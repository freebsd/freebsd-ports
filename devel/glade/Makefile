# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glade
PORTVERSION=	3.22.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+ 3

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	glade3-3.*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gmake gnome libtool \
		localbase:ldflags pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 gnomedocutils intlhack \
		introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PYTHON WEBKIT
OPTIONS_DEFAULT=PYTHON WEBKIT

PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES=	python:3.4+
PYTHON_USE=	GNOME=pygobject3

WEBKIT_DESC=	Webkit glade support
WEBKIT_CONFIGURE_ENABLE=	webkit2gtk
WEBKIT_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk3

.include <bsd.port.mk>
