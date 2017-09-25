# $FreeBSD$

PORTNAME=	0ad
PORTVERSION=	0.0.22
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://releases.wildfiregames.com/ \
		SF/zero-ad/releases
DISTFILES=	${PORTNAME}-${PORTVERSION}-alpha-unix-build.tar.xz \
		${PORTNAME}-${PORTVERSION}-alpha-unix-data.tar.xz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real-time strategy (RTS) game of ancient warfare

BUILD_DEPENDS=	zip:archivers/zip \
		python:lang/python \
		cmake:devel/cmake
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libcurl.so:ftp/curl \
		libgloox.so:net-im/gloox \
		libminiupnpc.so:net/miniupnpc \
		libnspr4.so:devel/nspr \
		libenet.so:net/enet \
		libtiff.so:graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-alpha
BUILD_WRKSRC=	${WRKSRC}/build/workspaces/gcc
MAKE_ARGS=	config=release
USES=		compiler:c++11-lib dos2unix gmake iconv jpeg openal:al \
		pkgconfig tar:xz
USE_GNOME=	libxml2 gtk20
USE_GL=		gl
USE_SDL=	sdl2
USE_XORG=	x11 xcursor
BUNDLE_LIBS=	yes
DOS2UNIX_REGEX=	.*\.([ch]p{0,2}|make)

USE_WX=		2.8+
WX_COMPS=	wx:lib
MAKE_ENV+=	JOBS=${_MAKE_JOBS}

BROKEN_aarch64=		fails to compile: no member named verifyHeapAccessDisassembly
BROKEN_armv6=		fails to link: fatal error: conftest: Unknown error: -1
BROKEN_powerpc64=	fails to compile: _psutil_bsd.c: error: 'struct xtcpcb' has no member named 'xt_tp'

PORTDATA=	*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%CC%%|${CC}|' \
		${WRKSRC}/build/premake/premake4.lua
.if ${ARCH} == i386 && ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e '1055,1251s/-rdynamic/-lssp_nonshared &/' \
			-e '1441s/"execinfo",/& "ssp_nonshared",/' \
		${WRKSRC}/build/premake/premake4.lua
.endif
	@${REINPLACE_CMD} 's,^\(Exec=\)/usr/local,\1${PREFIX},' \
		${WRKSRC}/build/resources/0ad.desktop
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/build/resources/0ad.sh
	@${CP} ${FILESDIR}/psutil.diff ${WRKSRC}/libraries/source/spidermonkey/

pre-build:
	(cd ${WRKSRC}/build/workspaces && ${SETENV} ${MAKE_ENV} ./update-workspaces.sh ${0ADSDLARG} --bindir=${PREFIX}/bin --datadir=${DATADIR} --libdir=${PREFIX}/lib/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${STAGEDIR}${PREFIX}/bin/0ad
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libAtlasUI.so libCollada.so libnvcore.so libnvimage.so libnvmath.so libnvtt.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libmozjs38-ps-release.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/binaries/data && ${COPYTREE_SHARE} "config l10n tests tools" ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${DATADIR}/mods/public ${STAGEDIR}${DATADIR}/mods/mod
	${TAR} xf ${WRKSRC}/binaries/data/mods/public/public.zip -C ${STAGEDIR}${DATADIR}/mods/public --no-same-permissions
	${TAR} xf ${WRKSRC}/binaries/data/mods/mod/mod.zip -C ${STAGEDIR}${DATADIR}/mods/mod --no-same-permissions

.include <bsd.port.post.mk>
