PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20250907
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	82acace66caae3a0c5824b449f79f8bf6b4197b8.patch:-p1 \
		4061bb17317fbc1d2ef515addb18746d42bbc278.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open reimplementation of Might and Magic VI-VIII game engine
WWW=		https://github.com/OpenEnroth/OpenEnroth

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libpng.so:graphics/png \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++23-lang gl openal pkgconfig sdl
USE_GL=		gl
USE_SDL=	sdl2
SUB_FILES=	pkg-message

CMAKE_OFF=	OE_BUILD_TESTS OE_USE_PREBUILT_DEPENDENCIES
LDFLAGS_i386=	-Wl,-znotext

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth
GH_PROJECT=	OpenEnroth
GH_TAGNAME=	9ba8864
GH_TUPLE=	CLIUtils:CLI11:9532482:C_C/thirdparty/cli11 \
		LuaJIT:LuaJIT:97813fb:L_L/thirdparty/luajit \
		Neargye:magic_enum:d01a4f9:N_m/thirdparty/magic_enum \
		OpenEnroth:backward-cpp:51f0700:O_b/thirdparty/backward_cpp \
		Rookfighter:inifile-cpp:7bb1ec3:R_i/thirdparty/inifile_cpp \
		TartanLlama:generator:2a91250:T_g/thirdparty/generator \
		ThePhD:sol2:336f76c:T_s/thirdparty/sol2 \
		boostorg:lambda2:dddfec6:b_l/thirdparty/lambda2 \
		g-truc:glm:0af55cc:g_g/thirdparty/glm \
		gharveymn:small_vector:e8e63fe:g_s/thirdparty/small_vector \
		mandreyel:mio:8b6b7d8:m_m/thirdparty/mio \
		nlohmann:json:55f9368:n_j/thirdparty/nlohmann_json \
		ocornut:imgui:1f7f1f5:o_i/thirdparty/imgui/imgui \
		vector-of-bool:cmrc:952ffdd:v_c/thirdparty/cmrc \
		zhaozg:luajit-cmake:6446221:zh_l/thirdparty/luajit-cmake

PORTSCOUT=	skipv:nightly

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake
	@${REINPLACE_CMD} -e '/assert/s,context,&.operator bool(),' \
		${WRKSRC}/src/Library/Platform/Application/PlatformApplication.cpp
	@${REINPLACE_CMD} -e '/extern "C"/ { x; \
	    s/^/#define AV_INPUT_BUFFER_MIN_SIZE 16384/; G; }' \
		${WRKSRC}/src/Media/FFmpegBlobInputStream.cpp
	@${REINPLACE_CMD} -e '/target_include_directories(imgui_backends/ \
	    s,), ${LOCALBASE}/include&,' \
		${WRKSRC}/thirdparty/imgui/CMakeLists.txt
	@${REINPLACE_CMD} -e 's, empty_string,& = 0,' \
		${WRKSRC_o_i}/imgui_widgets.cpp

do-install:
.for prog in CodeGen LodTool OpenEnroth
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/${prog}/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
