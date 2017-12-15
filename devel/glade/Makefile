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

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	glade3-3.*
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool \
		localbase:ldflags pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 gnomedocutils intlhack
#		introspection:build
# temp disable, introspection generation crashes with GNOME 3.15
CONFIGURE_ARGS=	--disable-introspection
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-Wno-error=format-nonliteral
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES=	python:3.4+
PYTHON_USE=	GNOME=py3gobject3

.include <bsd.port.mk>
