PORTNAME=	play
PORTVERSION=	0.48
PORTREVISION=	4
CATEGORIES=	games
PKGNAMEPREFIX=	libretro-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Play! - PlayStation 2 Emulator
WWW=		https://purei.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BROKEN_aarch64=	linker error: uunable to find library -lGLESv2

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake ssl gl compiler:c++17-lang
USE_GL=		egl gl glew glu
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	jpd002 \
		jpd002:codegen \
		jpd002:libchdr \
		jpd002:framework \
		jpd002:dependencies \
		gulrak:ghc_filesystem
GH_PROJECT=	Play- \
		Play--CodeGen:codegen \
		libchdr:libchdr \
		Play--Framework:framework \
		Play-Dependencies:dependencies \
		filesystem:ghc_filesystem
GH_TAGNAME=	448bac159733c6799a451ac75a18ce04aff5e223:codegen \
		532a3f60f75eec3454ff4e52cad8862afc40e65f:libchdr \
		faa4c23a2e96ba42b6ff1438bf33f111295c55cf:framework \
		636810ead6f1a3c8ee8006a3b9a698a81a0efbf6:dependencies \
		2a8b380f8d4e77b389c42a194ab9c70d8e3a0f1e:ghc_filesystem
GH_SUBDIR=	deps/CodeGen:codegen \
		deps/libchdr:libchdr \
		deps/Framework:framework \
		deps/Dependencies:dependencies \
		deps/Dependencies/ghc_filesystem:ghc_filesystem

PLIST_FILES=	lib/libretro/play_libretro.so

CMAKE_ON=	BUILD_LIBRETRO_CORE
CMAKE_OFF=	BUILD_AOT_CACHE \
		BUILD_PLAY \
		BUILD_PSFPLAYER \
		BUILD_TESTS \
		USE_AOT_CACHE \
		ENABLE_AMAZON_S3
CMAKE_ARGS=	-DGIT_TAG=${GH_TAGNAME_DEFAULT} \
		-DGIT_DESCRIBE_RESULT=0 \
		-DOpenGL_GL_PREFERENCE="GLVND"

post-patch:
	@${REINPLACE_CMD} -e 's|execute_process(COMMAND git.*||g' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKDIR}/.build/Source/ui_libretro/play_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
