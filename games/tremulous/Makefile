# Created by: Alejandro Pulver <alepulver@FreeBSD.org>

PORTNAME=	tremulous
PORTVERSION=	1.1.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free FPS game featuring two opposing teams: humans and aliens

LICENSE=	GPLv2

USES=		gmake zip
MAKE_ENV=	DEFAULT_BASEDIR="${DATADIR}" PTHREAD_LIBS="-lpthread"

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${DISTNAME}-src

VM_ARCHS=	amd64 i386

OPTIONS_DEFINE=		GAMELIBS OPENAL OPENAL_DLOPEN OPTIMIZED_CFLAGS \
			SDL_AUDIO SDL_VIDEO VORBIS
OPTIONS_MULTI=		FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED SMP_CLIENT MASTER_SERVER
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS SMP_CLIENT

FLAVOR_DESC=		Clients and servers
CLIENT_DESC=		Build client
GAMELIBS_DESC=		Force building game libraries
DEDICATED_DESC=		Build dedicated server
MASTER_SERVER_DESC=	Build master server
OPENAL_DLOPEN_DESC=	Enable dinamic loading of OpenAL
SDL_AUDIO_DESC=		Use SDL for audio
SDL_VIDEO_DESC=		Use SDL for video
SMP_CLIENT_DESC=	Build SMP (threaded) client

.include <bsd.port.options.mk>

.for arch in ${ARCH}
.  if ${VM_ARCHS:M${arch}}
HAVE_VM_COMPILED=	yes
.  endif
.endfor

.if defined(HAVE_VM_COMPILED)
MAKE_ENV+=	HAVE_VM_COMPILED=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP_CLIENT}
# OpenAL
.  if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
MAKE_ENV+=	USE_OPENAL=1
.    if ${PORT_OPTIONS:MOPENAL_DLOPEN}
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.    endif
.  endif
# SDL
.  if ${PORT_OPTIONS:MSDL_AUDIO}
USES+=		sdl
USE_SDL=	sdl
MAKE_ENV+=	USE_SDL_AUDIO=1
.  endif
.  if ${PORT_OPTIONS:MSDL_VIDEO}
USES+=		sdl
USE_SDL=	sdl
MAKE_ENV+=	USE_SDL_VIDEO=1
.  else
USES+=		gl xorg
USE_GL=		gl
USE_XORG=	x11 xxf86dga xxf86vm
.  endif
# Vorbis
.  if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
MAKE_ENV+=	USE_CODEC_VORBIS=1
.  endif
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
TRBIN+=		tremulous
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
TRBIN+=		tremded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if ${PORT_OPTIONS:MMASTER_SERVER}
LIB_DEPENDS+=	libtdb.so:databases/tdb
MAKE_ENV+=	BUILD_MASTER_SERVER=1
PLIST_SUB+=	MASTER_SERVER=""
.else
PLIST_SUB+=	MASTER_SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if ${PORT_OPTIONS:MSMP_CLIENT}
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
TRBIN+=		tremulous-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} zxf ${DISTNAME}-src.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${BUILD_WRKSRC}/src/botlib/be_interface.c
	@${REINPLACE_CMD} -e '/callMask = 0/s|^static||' \
		${BUILD_WRKSRC}/src/qcommon/vm_x86.c

do-install:
.for bin in ${TRBIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/build/release/${bin} \
		${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MMASTER_SERVER}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/master/release/tremmaster \
		${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${DATADIR}/base
	${INSTALL_DATA} ${WRKSRC}/base/* ${STAGEDIR}${DATADIR}/base
	${INSTALL_DATA} ${WRKSRC}/tremulous.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
