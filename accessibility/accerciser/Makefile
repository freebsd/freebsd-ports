# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/accerciser3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	accerciser
PORTVERSION=	3.6.2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core

USE_XZ=		yes
USE_GNOME=	gtk30 pygobject3 intlhack
USE_PYTHON=	yes
USES=		gettext gmake pkgconfig shebangfix
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	plugins/ipython_view.py

GLIB_SCHEMAS=	org.a11y.Accerciser.gschema.xml

.include <bsd.port.mk>
