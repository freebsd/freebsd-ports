PORTNAME=	NBlood
DISTVERSION=	g20220210
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Reverse-engineered ports of Build games using EDuke32 engine

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
GH_TAGNAME=	d2c0ef3
USE_GL=		glu
USE_SDL=	sdl2

MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX}
PLIST_FILES=	bin/pcexhumed \
		bin/nblood \
		bin/rednukem

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
MAKE_ARGS+=	LTO=0
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcexhumed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nblood ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rednukem ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
