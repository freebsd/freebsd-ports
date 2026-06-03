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

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libpng.so:graphics/png \
		libspdlog.so:devel/spdlog

USES=		cmake gl openal sdl
USE_GL=		gl
USE_SDL=	sdl2
SUB_FILES=	pkg-message

CMAKE_OFF=	OE_BUILD_TESTS OE_USE_PREBUILT_DEPENDENCIES
LDFLAGS_i386=	-Wl,-znotext

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth CLIUtils:cli11 vector-of-bool:cmrc fastfloat:ff \
		TartanLlama:gen g-truc:glm ocornut:img Rookfighter:ifcpp \
		boostorg:l2 zhaozg:ljcm LuaJIT:lj Neargye:me mandreyel:mio \
		nlohmann:nj gharveymn:sv ThePhD:sol2
GH_PROJECT=	OpenEnroth backward-cpp:bwcpp cmrc:cmrc CLI11:cli11 \
		fast_float:ff generator:gen glm:glm imgui:img \
		inifile-cpp:ifcpp lambda2:l2 luajit-cmake:ljcm LuaJIT:lj \
		magic_enum:me mio:mio json:nj small_vector:sv sol2:sol2
GH_TAGNAME=	9ba8864 51f0700:bwcpp 9532482:cli11 952ffdd:cmrc 1ea4f27:ff \
		2a91250:gen 0af55cc:glm 1f7f1f5:img 7bb1ec3:ifcpp dddfec6:l2 \
		6446221:ljcm 97813fb:lj d01a4f9:me 8b6b7d8:mio 55f9368:nj \
		e8e63fe:sv 336f76c:sol2
GH_SUBDIR=	thirdparty/backward_cpp:bwcpp thirdparty/cli11:cli11 \
		thirdparty/cmrc:cmrc thirdparty/fast_float:ff \
		thirdparty/generator:gen thirdparty/glm:glm \
		thirdparty/imgui/imgui:img thirdparty/inifile_cpp:ifcpp \
		thirdparty/lambda2:l2 thirdparty/luajit-cmake:ljcm \
		thirdparty/luajit:lj thirdparty/magic_enum:me \
		thirdparty/mio:mio thirdparty/nlohmann_json:nj \
		thirdparty/small_vector:sv thirdparty/sol2:sol2

PORTSCOUT=	skipv:nightly

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake
	@${REINPLACE_CMD} -e '/extern "C"/ { x; \
	    s/^/#define AV_INPUT_BUFFER_MIN_SIZE 16384/; G; }' \
		${WRKSRC}/src/Media/FFmpegBlobInputStream.cpp
	@${REINPLACE_CMD} -e '/target_include_directories(imgui_backends/ \
	    s,), ${LOCALBASE}/include&,' \
		${WRKSRC}/thirdparty/imgui/CMakeLists.txt

do-install:
.for prog in CodeGen LodTool OpenEnroth
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/${prog}/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
