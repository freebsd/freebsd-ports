# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutter
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Unit Testing Framework for C and C++

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/license/lgpl-3.txt

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libgstbase-1.0.so:multimedia/gstreamer1 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

CPPFLAGS+=	"-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-gtk-doc-html --with-html-dir=${PREFIX}/share/doc
GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	intlhack gdkpixbuf2 glib20 gtk20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	GOFFICE SOUP LCOV
GOFFICE_DESC=	GOffice support
SOUP_DESC=	libsoup support
LCOV_DESC=	Force dependency on lcov

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOFFICE}
CONFIGURE_ARGS+=--enable-goffice
# the 0.8 is part of the library name don't remove it.
LIB_DEPENDS+=	libgoffice-0.8.so:devel/goffice
PLIST_SUB+=	GOFFICE=""
.else
CONFIGURE_ARGS+=--disable-goffice
PLIST_SUB+=	GOFFICE="@comment "
.endif

.if ${PORT_OPTIONS:MLCOV}
RUN_DEPENDS+=	lcov:devel/lcov
.endif

.if ${PORT_OPTIONS:MSOUP}
CONFIGURE_ARGS+=--enable-libsoup
LIB_DEPENDS+=	libsoup-2.4.so:devel/libsoup
PLIST_SUB+=	SOUP=""
.else
CONFIGURE_ARGS+=--disable-libsoup
PLIST_SUB+=	SOUP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
