# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libsoup/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libsoup
PORTVERSION=	2.46.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

BUILD_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USES+=		gettext gmake libtool pathfix pkgconfig \
		python:3:build tar:xz
USE_GNOME=	glib20 gnomehier intltool introspection:build \
		libxml2 referencehack
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-more-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

LIBVERSION=	1.7.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.if defined(SOUP_SLAVE)
USE_SQLITE=	yes
LIB_DEPENDS+=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
CONFIGURE_ARGS+=--with-gnome
.else
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	 @${REINPLACE_CMD} -e 's|env python|env ${PYTHON_VERSION}|g' \
		${WRKSRC}/libsoup/tld-parser.py

.if defined(SOUP_SLAVE)
do-install:
	@${SED} '/^relink_command/d' ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.la
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.la ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/SoupGNOME-2.4.gir ${STAGEDIR}${PREFIX}/share/gir-1.0/
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

.endif
