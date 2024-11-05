PORTNAME=		libqb
DISTVERSION=		2.0.8
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://github.com/ClusterLabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=		alster@vinterdalen.se
COMMENT=		High performance logging, tracing, IPC, and polling library
WWW=			https://github.com/ClusterLabs/libqb/wiki

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

# HACK, see https://github.com/freebsd/poudriere/issues/1131#issuecomment-2073099527
BUILD_DEPENDS=		${TEST_DEPENDS}
TEST_DEPENDS=		checkmk:devel/check

USES=			cpe gmake libtool pkgconfig python tar:xz
CPE_VENDOR=		clusterlabs
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

OPTIONS_DEFINE=		DOCS DOXYGEN EXAMPLES
OPTIONS_SUB=		yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			libxml2>0:textproc/libxml2
DOXYGEN_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-DOXYGEN_OFF-patch-configure.ac

QB_SOCKET_DIR?=		/var/run/qb

TESTING_UNSAFE=		yes

post-extract-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-configure:
	${REINPLACE_CMD} -e 's/install: install-am/install:/g' ${WRKSRC}/doxygen2man/Makefile

post-configure-DOXYGEN-off:
	${REINPLACE_CMD} -e 's/doxygen2man docs//g' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${QB_SOCKET_DIR}

.include <bsd.port.mk>
