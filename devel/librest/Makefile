# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	rest
PORTVERSION=	0.7.90
CATEGORIES=	devel www
MASTER_SITES=	GNOME

MAINTAINER=	cmt@burggraben.net
COMMENT=	Easy access to RESTful web services

LICENSE=	LGPL21

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USES=		pkgconfig
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 intlhack libxml2

CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

PORTEXAMPLES=	*.c

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
