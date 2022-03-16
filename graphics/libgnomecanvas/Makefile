# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
#   $MCom: ports/graphics/libgnomecanvas/Makefile,v 1.79 2010/09/28 07:31:27 kwm Exp $

PORTNAME=	libgnomecanvas
PORTVERSION=	2.30.3
PORTREVISION?=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphics library for GNOME

USES+=		tar:bzip2

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	intltool libartlgpl2 gtk20 glib20 pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-glade \
		--disable-gtk-doc
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
