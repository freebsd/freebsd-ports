# Created by: Ade Lovett <ade@FreeBSD.org>
#   $MCom: ports/trunk/devel/gconf2/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	gconf2
PORTVERSION=	3.2.6
PORTREVISION=	7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Configuration database system for GNOME

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES+=		gettext gmake gnome libtool pathfix pkgconfig python:run \
		shebangfix localbase
USE_GNOME=	libxml2 dconf intltool introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--with-gtk=2.0 \
		--without-openldap \
		--disable-gtk \
		--disable-gtk-doc-html \
		--disable-gtk-doc \
		--disable-orbit \
		--disable-defaults-service
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	gsettings/gsettings-schema-convert

DOCSDIR=	${PREFIX}/share/doc/gconf

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gconf/gconf.xml.system

.include <bsd.port.mk>
