# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	rest
PORTVERSION=	0.7.91
CATEGORIES=	devel www
MASTER_SITES=	GNOME

MAINTAINER=	cmt@burggraben.net
COMMENT=	Easy access to RESTful web services

LICENSE=	LGPL21

BUILD_DEPENDS=	ca_root_nss>0:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	ca_root_nss>0:${PORTSDIR}/security/ca_root_nss

USES=		pathfix pkgconfig gmake tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2 introspection:build

CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

PORTEXAMPLES=	*.c

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librest-0.7.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librest-extras-0.7.so.0

.include <bsd.port.mk>
