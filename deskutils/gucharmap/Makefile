# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gucharmap
PORTVERSION=	11.0.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD>=0:textproc/UCD \
		gtkdocize:textproc/gtk-doc \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools
LIB_DEPENDS+=	libfreetype.so:print/freetype2

PORTSCOUT=	limitw:1,even

USES=		autoreconf:build desktop-file-utils gettext gmake gnome \
		libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unicode-data=${LOCALBASE}/share/unicode/ucd/
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	061cf7c0ba4ce62d2ce5743313a71cb272a5f82e

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml \
		org.gnome.Charmap.gschema.xml

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include <bsd.port.mk>
