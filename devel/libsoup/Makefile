# New ports collection makefile for:	libsoup
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libsoup/Makefile,v 1.90 2010/11/16 02:38:21 avl Exp $
#

PORTNAME=	libsoup
PORTVERSION=	2.32.2
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GNOME=	gnomehack glib20 libxml2 ltverhack referencehack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="2.4"

.include <bsd.port.pre.mk>

.if defined(SOUP_SLAVE)
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		proxy.0:${PORTSDIR}/net/libproxy \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--with-gnome
USE_GNOME+=	gconf2
.else
BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
CONFIGURE_ARGS+=--without-gnome
.endif

.if !defined(WITHOUT_SSL)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libsoup has the following configurable option(s):"
	@${ECHO_MSG} "  WITHOUT_SSL     Disable GnuTLS SSL support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g ; \
	    	s|" == "|" = "|g' \
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

.include <bsd.port.post.mk>

.endif
