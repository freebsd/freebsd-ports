# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glade3
PORTVERSION=	3.8.5
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for Gtk+ 2

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

CONFLICTS=	glade-3.*
PORTSCOUT=	ignore

INSTALLS_ICONS=	yes
USE_GNOME=	gtk20 intltool libxml2 gnomedocutils
USES=		desktop-file-utils gettext gmake gnome libtool \
		localbase:ldflags pathfix pkgconfig tar:xz
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/gladeui

OPTIONS_DEFINE=	GNOME PYTHON
OPTIONS_DEFAULT=PYTHON
GNOME_DESC=	GNOME UI widget support
OPTIONS_SUB=	yes

GNOME_CONFIGURE_ENABLE=	gnome
GNOME_USE=	GNOME=libgnomeui
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USE=	GNOME=pygtk2
PYTHON_USES=	python:2.7

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glade3/bindings

.include <bsd.port.mk>
