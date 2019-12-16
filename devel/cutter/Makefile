# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutter
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Unit Testing Framework for C and C++

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/license/lgpl-3.txt

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

CONFIGURE_ARGS=	--disable-gtk-doc-html --with-html-dir=${PREFIX}/share/doc \
		--disable-gstreamer
GNU_CONFIGURE=	yes
USES=		gettext gnome gmake libtool localbase pathfix pkgconfig
USE_GNOME=	intlhack gdkpixbuf2 glib20 gtk20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	SOUP LCOV NLS
OPTIONS_SUB=	yes
SOUP_DESC=	libsoup support
LCOV_DESC=	Force dependency on lcov

LCOV_RUN_DEPENDS=	lcov:devel/lcov

SOUP_CONFIGURE_ENABLE=	libsoup
SOUP_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
