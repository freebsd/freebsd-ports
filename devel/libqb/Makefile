PORTNAME=	libqb
DISTVERSION=	2.0.9
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ClusterLabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	High performance logging, tracing, IPC, and polling library
WWW=		https://github.com/ClusterLabs/libqb/wiki

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	checkmk:devel/check

USES=		autoreconf cpe gmake libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	clusterlabs
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socket-dir=${QB_SOCKET_DIR} \
		PACKAGE_STRING="${PORTNAME} ${DISTVERSION}" \
		PACKAGE_VERSION=${DISTVERSION}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

TESTING_UNSAFE=	yes

GROUPS=		haclient

PLIST_SUB+=	QB_SOCKET_DIR=${QB_SOCKET_DIR}

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_USES=			gnome
DOXYGEN_USES_OFF=		autoreconf
DOXYGEN_USE=			GNOME=libxml2:build
DOXYGEN_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-DOXYGEN_OFF-patch-configure.ac

QB_SOCKET_DIR?=	/var/run/qb

post-extract-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-configure:
	@${REINPLACE_CMD} -e 's/install: install-am/install:/g' ${WRKSRC}/doxygen2man/Makefile

post-configure-DOXYGEN-off:
	@${REINPLACE_CMD} -e 's/doxygen2man docs//g' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
