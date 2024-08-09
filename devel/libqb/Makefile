PORTNAME=		libqb
DISTVERSION=		2.0.6
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://github.com/ClusterLabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		High performance logging, tracing, ipc, and polling library
WWW=		https://github.com/ClusterLabs/libqb/wiki

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

TEST_DEPENDS=		checkmk:devel/check

GROUPS=			haclient

QB_SOCKET_DIR?=		/var/run/qb
PLIST_SUB+=		QB_SOCKET_DIR=${QB_SOCKET_DIR}

USES=			cpe gmake gnome libtool pkgconfig python tar:xz
CPE_VENDOR=		clusterlabs
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=       ${PREFIX}/share
USE_GNOME=		libxml2
USE_LDCONFIG=		yes

CONFIGURE_ARGS=		--with-socket-dir=${QB_SOCKET_DIR} \
			PACKAGE_STRING="${PORTNAME} ${DISTVERSION}" \
			PACKAGE_VERSION=${DISTVERSION}
LDFLAGS=		-B${LOCALBASE}/bin

INSTALL_TARGET=		install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		DOCS DOXYGEN
OPTIONS_SUB=		yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-configure:
	${REINPLACE_CMD} -e 's/install: install-am/install:/g' ${WRKSRC}/doxygen2man/Makefile

post-configure-DOXYGEN-off:
	${REINPLACE_CMD} -e 's/doxygen2man docs//g' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
