# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopensync
PORTVERSION=	0.39
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PIM data synchronization framework

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libexslt.so:${PORTSDIR}/textproc/libxslt

CONFLICTS=	libopensync-0.22*

USE_SQLITE=	3
USE_BZIP2=	yes
USES=		cmake pkgconfig
CMAKE_ARGS+=	-Wno-dev
USE_GNOME=	glib20 libxml2
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPYTHON_INCLUDE_PATH:PATH=${PYTHON_INCLUDEDIR}

OPTIONS_DEFINE=	DOCS

SWIG_VER=	$$(cd ${PORTSDIR}/devel/swig13 && ${MAKE} -V PORTVERSION)
SWIG_DATADIR=	$$(cd ${PORTSDIR}/devel/swig13 && ${MAKE} -V DATADIR)

post-patch:
	@${REINPLACE_CMD} -e "s|\$${LIBDATA_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|" \
		-e "s|FIND_PACKAGE( SWIG|FIND_PACKAGE( SWIG REQUIRED|" \
		-e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s|/usr/local/share/swig1.3|${SWIG_DATADIR}/${SWIG_VER}|g" \
		${WRKSRC}/cmake/modules/FindSWIG.cmake
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/opensync/common/opensync_list.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/OpenSync-WhitePaper.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
