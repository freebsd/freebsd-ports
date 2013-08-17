# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libsoup/Makefile 18456 2013-05-12 14:40:21Z kwm $

PORTNAME=	libsoup
PORTVERSION=	2.40.3
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

BUILD_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking \
		python2:${PORTSDIR}/lang/python2
LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USES=		gettext pathfix
USE_GNOME=	gnomehier glib20 libxml2 ltverhack referencehack intltool
USE_SQLITE=	3
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_PYTHON_BUILD=	-2.7
CONFIGURE_ARGS=	--disable-more-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="2.4"

.if defined(SOUP_SLAVE)
USE_SQLITE=	yes
LIB_DEPENDS+=	soup-2.4:${PORTSDIR}/devel/libsoup \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring
CONFIGURE_ARGS+=--with-gnome
.else
BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.if defined(SOUP_SLAVE)
do-build:
	cd ${WRKSRC}/libsoup && ${GMAKE} libsoup-gnome-2.4.la

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.la ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so.1 ${PREFIX}/lib/
	cd ${WRKSRC}/libsoup && ${GMAKE} install-libsoupgnomeincludeHEADERS
.endif

post-install:
.if defined(SOUP_SLAVE)
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_DATA} ${WRKSRC}/libsoup-gnome-2.4.pc \
		${PREFIX}/libdata/pkgconfig/
.else
	@${INSTALL_DATA} ${WRKSRC}/libsoup/soup-connection.h \
	    	${PREFIX}/include/libsoup-2.4/libsoup/soup-connection.h
.endif

.include <bsd.port.mk>

.endif
