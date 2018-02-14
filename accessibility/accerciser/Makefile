# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/accerciser/Makefile 19980 2014-10-17 06:01:57Z gusi $

PORTNAME=	accerciser
PORTVERSION=	3.14.0
PORTREVISION=	1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		at-spi2-core>=2.1.5:accessibility/at-spi2-core
RUN_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		at-spi2-core>=2.1.5:accessibility/at-spi2-core

NO_ARCH=	yes
USES=		gettext gmake localbase:ldflags pkgconfig python:3.4+ shebangfix tar:xz
USE_GNOME=	gtk30 intlhack pygobject3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	plugins/ipython_view.py

GLIB_SCHEMAS=	org.a11y.Accerciser.gschema.xml

.include <bsd.port.mk>
