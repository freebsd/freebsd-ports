# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	rest
PORTVERSION=	0.7.93
CATEGORIES=	devel www
MASTER_SITES=	GNOME

MAINTAINER=	cmt@burggraben.net
COMMENT=	Easy access to RESTful web services

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>0:security/ca_root_nss
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2 introspection:build
TEST_TARGET=	check

PORTEXAMPLES=	*.c

OPTIONS_DEFINE=	GNOME EXAMPLES
OPTIONS_DEFAULT=	GNOME

GNOME_LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome
GNOME_CONFIGURE_OFF=	--without-gnome
GNOME_LIB_DEPENDS_OFF=	libsoup-2.4.so:devel/libsoup

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librest-0.7.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librest-extras-0.7.so.0

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
