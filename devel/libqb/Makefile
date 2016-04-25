# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	libqb
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ClusterLabs/libqb/releases/download/v${PORTVERSION}/

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	High performance logging, tracing, ipc, and polling library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GROUPS=		haclient

QB_SOCKET_DIR?=	/var/run/qb
PLIST_SUB+=	QB_SOCKET_DIR=${QB_SOCKET_DIR}

USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --with-socket-dir=${QB_SOCKET_DIR}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
