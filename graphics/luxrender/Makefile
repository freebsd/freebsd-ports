# New ports collection makefile for:	LuxRender
# Date created:				16 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	luxrender
PORTVERSION=	0.6.1
PORTREVISION=	1
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.elif ${ARCH} == "i386" || ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

post-patch:
# Respect our CFLAGS, do not append `64' suffix to `lib' on amd64, do not
# install vendor .desktop file
	@${REINPLACE_CMD} -e \
		's,^ADD_DEFINITIONS(-O3 -msse2 -mfpmath=sse -ftree-vectorize -funroll-loops -Wall ,ADD_DEFINITIONS(, ; /LIB_SUFFIX 64/d ; \
		/luxrender.desktop/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		-e 's|int_p_NULL|NULL|g' \
		${WRKSRC}/core/cimg.h

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

.include <bsd.port.post.mk>
