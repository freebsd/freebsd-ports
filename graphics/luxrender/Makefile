# New ports collection makefile for:	LuxRender
# Date created:				16 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	luxrender
PORTVERSION=	0.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/lux/archive/ \
		http://freebsd.nsu.ru/distfiles/luxrender/
DISTNAME=	${HG_NODEID}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A physically based and unbiased rendering system

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR

HG_NODEID=	36533b0843bd

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_WX=		2.8
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
CMAKE_VERBOSE=	yes
WRKSRC=		${WRKDIR}/lux-${HG_NODEID}

DESKTOP_ENTRIES="LuxRender" "${COMMENT}" "luxrender" "luxrender" \
		"Application;Graphics;3DGraphics;" false

post-patch:
# Respect our CFLAGS, do not append `64' suffix to `lib' on amd64, do not
# install vendor .desktop file
	@${REINPLACE_CMD} -e \
		's,^ADD_DEFINITIONS(-O3 -msse2 -mfpmath=sse -ftree-vectorize -funroll-loops -Wall ,ADD_DEFINITIONS(, ; /LIB_SUFFIX 64/d ; \
		/luxrender.desktop/d' ${WRKSRC}/CMakeLists.txt

post-configure:
# Fix CXX_FLAGS in generated files
	@${REINPLACE_CMD} -e \
		's,-pthread;-D_THREAD_SAFE,-pthread -D_THREAD_SAFE,' \
			${WRKSRC}/CMakeFiles/lux.dir/flags.make \
			${WRKSRC}/CMakeFiles/luxconsole.dir/flags.make \
			${WRKSRC}/CMakeFiles/luxconsole.dir/link.txt \
			${WRKSRC}/CMakeFiles/luxmerger.dir/flags.make \
			${WRKSRC}/CMakeFiles/luxmerger.dir/link.txt \
			${WRKSRC}/CMakeFiles/luxrender.dir/flags.make \
			${WRKSRC}/CMakeFiles/luxrender.dir/link.txt

.include <bsd.port.mk>
