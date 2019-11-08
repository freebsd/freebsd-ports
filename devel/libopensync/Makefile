# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopensync
PORTVERSION=	0.39
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/ \
		LOCAL/danilo

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PIM data synchronization framework

LICENSE=	LGPL21

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libexslt.so:textproc/libxslt

CONFLICTS=	libopensync-0.22*

USES=		cmake gnome pkgconfig python sqlite:3 tar:bzip2
CMAKE_ARGS+=	-Wno-dev
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPYTHON_INCLUDE_PATH:PATH=${PYTHON_INCLUDEDIR} \
		-DSWIG_DIR=`swig3.0 -swiglib` \
		-DSWIG_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/swig3.0

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|\$${LIBDATA_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|" \
		-e "s|FIND_PACKAGE( SWIG|FIND_PACKAGE( SWIG REQUIRED|" \
		-e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/opensync/common/opensync_list.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/OpenSync-WhitePaper.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
