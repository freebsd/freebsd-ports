PORTNAME=	NBlood
DISTVERSION=	r14262
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Reverse-engineered ports of Build games using EDuke32 engine
WWW=		https://github.com/nukeykt/NBlood

LICENSE=	GPLv2 BUILDLIC
LICENSE_COMB=	multi
LICENSE_NAME_BUILDLIC=	BUILD SOURCE CODE LICENSE
LICENSE_FILE_BUILDLIC=	${WRKSRC}/source/build/buildlic.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/source/duke3d/gpl-2.0.txt
LICENSE_PERMS_BUILDLIC=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libvpx.so:multimedia/libvpx \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++14-lang gl gmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	nukeykt
USE_GL=		glu
USE_SDL=	sdl2

MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX} CLANG=1 PRETTY_OUTPUT=0 USE_MIMALLOC=0
PLIST_FILES=	bin/pcexhumed \
		bin/nblood \
		bin/rednukem

.include <bsd.port.options.mk>

.if ${ARCH} == riscv64
MAKE_ARGS+=	LTO=0
.endif

post-patch:
	${MV} ${WRKSRC}/source/build/include/lz4.h ${WRKSRC}/source/build/include/my_lz4.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcexhumed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nblood ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rednukem ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
