PORTNAME=		CuraEngine
PORTVERSION=		5.7.0
PORTREVISION=	4
PORTEPOCH=		1
CATEGORIES=		cad
DIST_SUBDIR=		Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Engine of slicing solution for RepRap 3D printers
WWW=		http://wiki.ultimaker.com/Cura

LICENSE=	AGPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/uuid/uuid.hpp:devel/boost-libs \
		${LOCALBASE}/include/fmt/format.h:devel/libfmt \
		${LOCALBASE}/include/range/v3/range.hpp:devel/range-v3 \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson
LIB_DEPENDS=	libabsl_log_internal_message.so:devel/abseil \
		libArcus.so:net/libarcus \
		libfmt.so:devel/libfmt \
		libpolyclipping.so:graphics/polyclipping \
		libprotobuf.so:devel/protobuf \
		libspdlog.so:devel/spdlog

USES=		compiler:c++20-lang cmake pkgconfig

STB_TAG=	beebb24
SCRIPTA_TAG=	c378c83
GEOMETRYHPP_TAG=3b1a10e
WAGYU_TAG=	0.5.0

USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_PROJECT=	CuraEngine
GH_TUPLE=	mapbox:geometry.hpp:${GEOMETRYHPP_TAG}:geometryhpp \
		mapbox:wagyu:${WAGYU_TAG}:wagyu \
		nothings:stb:${STB_TAG}:stb/include/stb \
		Ultimaker:Scripta_public:${SCRIPTA_TAG}:Scripta_public

CMAKE_ARGS+=	-DUSE_SYSTEM_LIBS:BOOL=ON \
		-DStb_FOUND:BOOL=ON \
		-DStb_INCLUDE_DIRS=${WRKSRC}/include/stb
LDFLAGS+=	-L${LOCALBASE}/lib
WITH_DEBUGINFO=	1 # Will segfault if Release

PLIST_FILES=	bin/CuraEngine

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in FindGMock.cmake FindPolyclipping.cmake FindStb.cmake; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
		done
	@for f in CMakeLists.txt CPackConfig.cmake; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}; \
		done
	@${MV} ${WRKDIR}/Scripta_public-${SCRIPTA_TAG}/include/scripta ${WRKSRC}/include
	@${MV} ${WRKDIR}/geometry.hpp-${GEOMETRYHPP_TAG}/include/mapbox ${WRKSRC}/include
	@${MV} ${WRKDIR}/wagyu-${WAGYU_TAG}/include/mapbox/geometry/wagyu ${WRKSRC}/include/mapbox/geometry

.include <bsd.port.mk>
