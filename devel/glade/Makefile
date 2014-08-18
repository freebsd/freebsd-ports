# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/glade/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	glade
PORTVERSION=	3.18.3
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+ 3

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	glade3-3.*

USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 gnomeprefix gnomedocutils introspection:build
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
PYTHON_USE=	PYTHON=3 GNOME=py3gobject3

.include <bsd.port.mk>
