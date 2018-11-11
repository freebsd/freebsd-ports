# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsoup
PORTVERSION=	2.62.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>=2.29.18:net/glib-networking
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig python:3.6+,build sqlite ssl tar:xz
USE_GNOME=	glib20 intlhack introspection:build \
		libxml2 referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-more-warnings \
		--disable-vala
INSTALL_TARGET=	install-strip

LIBVERSION=	1.8.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.if defined(SOUP_SLAVE)
USES+=		sqlite
LIB_DEPENDS+=	libsoup-2.4.so:devel/libsoup
CONFIGURE_ARGS+=--with-gnome
.else
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|env python3|env ${PYTHON_VERSION}|g' \
		${WRKSRC}/libsoup/tld-parser.py
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/configure

.if defined(SOUP_SLAVE)
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gir-1.0/
	${INSTALL_DATA} ${WRKSRC}/libsoup/SoupGNOME-2.4.gir ${STAGEDIR}${PREFIX}/share/gir-1.0/
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/girepository-1.0/
	${INSTALL_DATA} ${WRKSRC}/libsoup/SoupGNOME-2.4.typelib ${STAGEDIR}${PREFIX}/lib/girepository-1.0/
	${INSTALL_PROGRAM} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so.1 ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so.${LIBVERSION} ${STAGEDIR}${PREFIX}/lib/
	cd ${WRKSRC}/libsoup && DESTDIR=${STAGEDIR} ${GMAKE} install-libsoupgnomeincludeHEADERS
.endif

post-install:
.if defined(SOUP_SLAVE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libsoup-gnome-2.4.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.else
	${INSTALL_DATA} ${WRKSRC}/libsoup/soup-connection.h \
		${STAGEDIR}${PREFIX}/include/libsoup-2.4/libsoup/soup-connection.h
.endif

.include <bsd.port.mk>
