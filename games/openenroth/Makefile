PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20230128
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open reimplementation of Might and Magic VI-VIII game engine
WWW=		https://github.com/OpenEnroth/OpenEnroth

LICENSE=	LGPL3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt

USES=		cmake gl openal sdl
USE_GL=		gl
USE_SDL=	sdl2
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth CLIUtils:cli11 fastfloat:ff g-truc:glm \
		LuaJIT:lj Neargye:me pulzed:mini nlohmann:nj
GH_PROJECT=	OpenEnroth CLI11:cli11 fast_float:ff glm:glm \
		LuaJIT:lj magic_enum:me mINI:mini json:nj
GH_TAGNAME=	093e253 a227cd1:cli11 1ea4f27:ff 6ad79aa:glm \
		03080b7:lj d01a4f9:me a1ff72e:mini 4c6cde7:nj
GH_SUBDIR=	thirdparty/cli11:cli11 thirdparty/fast_float:ff \
		thirdparty/glm:glm thirdparty/luajit/luajit:lj \
		thirdparty/magic_enum:me thirdparty/mini:mini \
		thirdparty/nlohmann_json:nj

.include <bsd.port.options.mk>

.if !exists(/usr/include/c++/v1/concepts)
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/unordered_map.hpp:devel/boost-libs
USES+=		llvm:13
CXX=		${LLVM_PREFIX}/bin/clang++
.endif

.if ${ARCH} == i386
LLD_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_CXX_STANDARD/s,23,20,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake
	@${REINPLACE_CMD} -e '/fmt/d' \
		${WRKSRC}/thirdparty/CMakeLists.txt
	@${REINPLACE_CMD} -e '/^target_link_libraries/s,fmt::,pthread ,' \
		${WRKSRC}/src/Utility/CMakeLists.txt
	@${REINPLACE_CMD} -e 's, c++abi,,' \
		${WRKSRC}/thirdparty/luajit/cmake/src/CMakeLists.txt
.if !exists(/usr/include/c++/v1/concepts)
	@${REINPLACE_CMD} -e '/#include/s,unordered_map,boost/&.hpp,' \
	    -e 's,std::unordered_map,boost::unordered_map,' \
		${WRKSRC}/src/Library/Serialization/EnumSerializer.h
	@${REINPLACE_CMD} -e '/#ifdef/s,ANDROID,${OPSYS},' \
		${WRKSRC}/src/Utility/FileSystem.cpp
.endif

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/OpenEnroth \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/resources/shaders ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
