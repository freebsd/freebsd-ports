# New ports collection makefile for:	gdk-pixbuf
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME?=	gdk-pixbuf
PORTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES?=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gdk-pixbuf/0.22
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	A graphic library for GTK+

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME+=	gnomehack gtk12
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		BUILD_CANVAS="${BUILD_CANVAS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

BUILD_CANVAS?=	no

.include <bsd.port.mk>
