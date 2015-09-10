# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-autoar
PORTVERSION=	0.1
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/kwm
#MASTER_SITES=	GNOME
#DISTDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper around libarchives

USES=		gmake libarchive libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 introspection:build
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.desktop.archives.enums.xml \
		org.gnome.desktop.archives.gschema.xml

.include <bsd.port.mk>
