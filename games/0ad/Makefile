# $FreeBSD$

PORTNAME=	0ad
PORTVERSION=	0.0.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/zero-ad/releases
DISTFILES=	${PORTNAME}-${PORTVERSION}-alpha-unix-build.tar.xz \
		${PORTNAME}-${PORTVERSION}-alpha-unix-data.tar.xz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real-time strategy (RTS) game of ancient warfare

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		zip:${PORTSDIR}/archivers/zip \
		cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		png15:${PORTSDIR}/graphics/png \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		curl:${PORTSDIR}/ftp/curl \
		gamin-1:${PORTSDIR}/devel/gamin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-alpha
BUILD_WRKSRC=	${WRKSRC}/build/workspaces/gcc
MAKE_ARGS=	config=release
USE_GMAKE=	yes
USE_XZ=		yes
USE_SDL=	sdl
USE_GNOME=	libxml2 gtk20
USE_GL=		gl
USE_OPENAL=	al
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.([ch]p{0,2}|make)
MAKE_JOBS_SAFE=	yes

USE_WX=		2.8
WX_COMPS=	wx:lib
WX_UNICODE=	yes
MAKE_ENV+=	JOBS=${_MAKE_JOBS}

MANUAL_PACKAGE_BUILD=	yes # huge

PORTDATA=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800067
BROKEN=		Does not compile on 7.x: Requires wcsnlen(3)
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/build/premake/premake4.lua
	@${REINPLACE_CMD} 's,^\(Exec=\)/usr/local,\1${PREFIX},' \
		${WRKSRC}/build/resources/0ad.desktop

pre-build:
	(cd ${WRKSRC}/build/workspaces && ${SETENV} ${MAKE_ENV} ./update-workspaces.sh --bindir=${PREFIX}/bin --datadir=${DATADIR} --libdir=${PREFIX}/lib/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${PREFIX}/bin/0ad
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libAtlasUI.so libCollada.so libenet.so.1 libmozjs185-ps-release.so.1.0 libnvcore.so libnvimage.so libnvmath.so libnvtt.so ${PREFIX}/lib/${PORTNAME})
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${PREFIX}/share/pixmaps
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/binaries/data && ${COPYTREE_SHARE} "config mods tests tools" ${DATADIR})

.include <bsd.port.post.mk>
