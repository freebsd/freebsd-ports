# New ports collection makefile for:	libsoup
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libsoup/Makefile,v 1.81 2010/04/27 18:17:04 kwm Exp $
#

PORTNAME=	libsoup
PORTVERSION=	2.30.1
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
    		proxy.0:${PORTSDIR}/net/libproxy \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GNOME=	gnomehack glib20 libxml2 ltverhack referencehack gconf2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="2.4"

.if !defined(WITHOUT_SSL)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libsoup has the following configurable option(s):"
	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g ; \
	    	s|" == "|" = "|g' \
		${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/libsoup/soup-connection.h \
	    	${PREFIX}/include/libsoup-2.4/libsoup/soup-connection.h

.include <bsd.port.post.mk>

.endif
