PORTNAME=		libqb
DISTVERSION=		2.0.8
CATEGORIES=		devel
MASTER_SITES=		https://github.com/ClusterLabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=		alster@vinterdalen.se
COMMENT=		High performance logging, tracing, ipc, and polling library
WWW=			https://github.com/ClusterLabs/libqb/wiki

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

TEST_DEPENDS=		checkmk:devel/check

USES=			cpe gmake gnome libtool pkgconfig python tar:xz
CPE_VENDOR=		clusterlabs
USE_GNOME=		libxml2
USE_LDCONFIG=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-socket-dir=${QB_SOCKET_DIR} \
			PACKAGE_STRING="${PORTNAME} ${DISTVERSION}" \
			PACKAGE_VERSION=${DISTVERSION}

INSTALL_TARGET=		install-strip
TEST_TARGET=		check

LDFLAGS+=		-B${LOCALBASE}/bin

GROUPS=			haclient

PLIST_SUB+=		QB_SOCKET_DIR=${QB_SOCKET_DIR}

OPTIONS_DEFINE=		DOCS DOXYGEN
OPTIONS_SUB=		yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

QB_SOCKET_DIR?=		/var/run/qb

post-configure:
	${REINPLACE_CMD} -e 's/install: install-am/install:/g' ${WRKSRC}/doxygen2man/Makefile

post-configure-DOXYGEN-off:
	${REINPLACE_CMD} -e 's/doxygen2man docs//g' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
