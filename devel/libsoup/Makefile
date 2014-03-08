# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libsoup/Makefile 19016 2014-03-08 09:05:27Z kwm $

PORTNAME=	libsoup
PORTVERSION=	2.40.3
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

BUILD_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomehier glib20 libxml2 referencehack intltool
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON_BUILD=	2
CONFIGURE_ARGS=	--disable-more-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIBVERSION=	1.5.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.if defined(SOUP_SLAVE)
USE_SQLITE=	3
LIB_DEPENDS+=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
CONFIGURE_ARGS+=--with-gnome
.else
USE_GNOME+=	introspection:build
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	 @${REINPLACE_CMD} -e 's|env python|env ${PYTHON_VERSION}|g' \
		${WRKSRC}/libsoup/tld-parser.py

.if defined(SOUP_SLAVE)
do-build:
	cd ${WRKSRC}/libsoup && ${GMAKE} libsoup-gnome-2.4.la

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.la ${STAGEDIR}${PREFIX}/lib/
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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsoup*.so*
.endif

.include <bsd.port.mk>

.endif
