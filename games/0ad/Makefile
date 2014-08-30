# $FreeBSD$

PORTNAME=	0ad
PORTVERSION=	0.0.14
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/zero-ad/releases
DISTFILES=	${PORTNAME}-${PORTVERSION}-alpha-unix-build.tar.xz \
		${PORTNAME}-${PORTVERSION}-alpha-unix-data.tar.xz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real-time strategy (RTS) game of ancient warfare

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		zip:${PORTSDIR}/archivers/zip \
		cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libpng15.so:${PORTSDIR}/graphics/png \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libgamin-1.so:${PORTSDIR}/devel/gamin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-alpha
BUILD_WRKSRC=	${WRKSRC}/build/workspaces/gcc
MAKE_ARGS=	config=release
USES=		compiler:c++11-lang dos2unix gmake openal:al pkgconfig tar:xz
USE_SDL=	sdl
USE_GNOME=	libxml2 gtk20
USE_GL=		gl
DOS2UNIX_REGEX=	.*\.([ch]p{0,2}|make)

USE_WX=		2.8
WX_COMPS=	wx:lib
WX_UNICODE=	yes
MAKE_ENV+=	JOBS=${_MAKE_JOBS}

MANUAL_PACKAGE_BUILD=	yes # huge

PORTDATA=	*

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900014
FAVORITE_COMPILER=	gcc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%CC%%|${CC}|' \
		${WRKSRC}/build/premake/premake4.lua
	@${REINPLACE_CMD} 's,^\(Exec=\)/usr/local,\1${PREFIX},' \
		${WRKSRC}/build/resources/0ad.desktop

pre-build:
	(cd ${WRKSRC}/build/workspaces && ${SETENV} ${MAKE_ENV} ./update-workspaces.sh --bindir=${PREFIX}/bin --datadir=${DATADIR} --libdir=${PREFIX}/lib/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${STAGEDIR}${PREFIX}/bin/0ad
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libAtlasUI.so libCollada.so libenet.so.1 libmozjs185-ps-release.so.1.0 libnvcore.so libnvimage.so libnvmath.so libnvtt.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/binaries/data && ${COPYTREE_SHARE} "config mods tests tools" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
