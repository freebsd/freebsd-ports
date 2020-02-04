# Created by: David Shane Holden <dpejesh@yahoo.com>
# $FreeBSD$

PORTNAME=		libqb
PORTVERSION=		1.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=		devel

MAINTAINER=		egypcio@FreeBSD.org
COMMENT=		High performance logging, tracing, ipc, and polling library

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

TEST_DEPENDS=		checkmk:devel/check

GROUPS=			haclient

QB_SOCKET_DIR?=		/var/run/qb
PLIST_SUB+=		QB_SOCKET_DIR=${QB_SOCKET_DIR}

USES=			autoreconf gmake libtool pathfix pkgconfig tar:xz
USE_BINUTILS=		yes
USE_LDCONFIG=		yes
USE_GITHUB=		yes
GH_ACCOUNT=		ClusterLabs

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-socket-dir=${QB_SOCKET_DIR}
LDFLAGS+=		-B${LOCALBASE}/bin
PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=		install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		DOCS DOXYGEN
OPTIONS_SUB=		yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
