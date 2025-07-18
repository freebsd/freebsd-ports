PORTNAME=	0ad
DISTVERSION=	0.27.1
CATEGORIES=	games
MASTER_SITES=	https://releases.wildfiregames.com/
DISTFILES=	${PORTNAME}-${DISTVERSION}-unix-build.tar.xz \
		${PORTNAME}-${DISTVERSION}-unix-data.tar.xz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real-time strategy (RTS) game of ancient warfare
WWW=		https://play0ad.com/

BROKEN_aarch64=		fails to compile: no member named verifyHeapAccessDisassembly
BROKEN_armv6=		fails to link: fatal error: conftest: Unknown error: -1
BROKEN_armv7=		fails to link: fatal error: conftest: Unknown error: -1
BROKEN_powerpc64=	fails to compile: _psutil_bsd.c: error: 'struct xtcpcb' has no member named 'xt_tp'

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.35:lang/${RUST_DEFAULT} \
		zip:archivers/zip \
		cmake:devel/cmake-core
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libpng16.so:graphics/png \
		libvorbisfile.so:audio/libvorbis \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgloox.so:net-im/gloox \
		libminiupnpc.so:net/miniupnpc \
		libenet.so:net/enet \
		libsodium.so:security/libsodium \
		libfmt.so:devel/libfmt \
		libmozjs-115.so:lang/spidermonkey115

USES=		compiler:c++11-lib desktop-file-utils dos2unix gmake gnome \
		iconv openal:al perl5 pkgconfig python:3.9,build sdl tar:xz \
		xorg
USE_GNOME=	libxml2
USE_GL=		gl
USE_SDL=	sdl2
USE_XORG=	x11 xcursor
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/workspaces/gcc
MAKE_ARGS=	config=release verbose=1
CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1
CFLAGS_i386=	-msse2
BUNDLE_LIBS=	yes
DOS2UNIX_REGEX=	.*\.([ch]p{0,2}|make)
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_WX=		3.0+
WX_COMPS=	wx:lib
MAKE_ENV+=	JOBS=${_MAKE_JOBS}

PORTDATA=	*

.include <bsd.port.pre.mk>

post-extract:
	@(cd ${WRKSRC}/libraries/source/nvtt && ${TAR} xf nvtt-28209.tar.xz)

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%CC%%|${CC}|' \
		${WRKSRC}/build/premake/extern_libs5.lua
.if ${ARCH} == i386 && ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e '1130,1530s/-rdynamic/-lssp_nonshared &/' \
			-e '1112,1502s/"execinfo",/& "ssp_nonshared",/' \
		${WRKSRC}/build/premake/premake5.lua
.endif

pre-build:
	(cd ${WRKSRC}/libraries && ${SETENV} ${MAKE_ENV} ./build-source-libs.sh --with-system-mozjs -j ${_MAKE_JOBS})
	(cd ${WRKSRC}/build/workspaces && ${SETENV} ${MAKE_ENV} ./update-workspaces.sh --with-system-mozjs --bindir=${PREFIX}/bin --datadir=${DATADIR} --libdir=${PREFIX}/lib/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${STAGEDIR}${PREFIX}/bin/0ad
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libAtlasUI.so libCollada.so libnvcore.so libnvimage.so libnvmath.so libnvtt.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/binaries/data && ${COPYTREE_SHARE} "config l10n tests tools" ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${DATADIR}/mods/public ${STAGEDIR}${DATADIR}/mods/mod
	${TAR} xf ${WRKSRC}/binaries/data/mods/public/public.zip -C ${STAGEDIR}${DATADIR}/mods/public --no-same-permissions
	${TAR} xf ${WRKSRC}/binaries/data/mods/mod/mod.zip -C ${STAGEDIR}${DATADIR}/mods/mod --no-same-permissions

.include <bsd.port.post.mk>
