# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	tmw
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/themanaworld/The%20Mana%20World/${PORTVERSION}/:src
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Free open source 2D MMORPG in development

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		png15:${PORTSDIR}/graphics/png \
		curl:${PORTSDIR}/ftp/curl \
		physfs:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan

USES=		cmake gettext
USE_SDL=	sdl gfx image mixer net ttf
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
DATADIR=	${PREFIX}/share/mana

OPTIONS_DEFINE=	MANASERV MUSIC NLS OPENGL
OPTIONS_DEFAULT=	MUSIC OPENGL
MANASERV_DESC=	Server component
MUSIC_DESC=	Install additional music

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANASERV}
CMAKE_ARGS+=	-DENABLE_MANASERV:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_MANASERV:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=ON
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMUSIC}
MUSICVERSION=	0.3
MASTER_SITES+=	SF/themanaworld/TMW%20Music/${MUSICVERSION}/:data
MUSICNAME=	tmwmusic-${MUSICVERSION}
MUSICSUBDIR=	data/music
DISTFILES+=	${MUSICNAME}.tar.gz:data
MUSICDIR=	${WRKDIR}/${MUSICNAME}/${MUSICSUBDIR}
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=ON
USE_GL=		yes
.endif

post-extract:
.if ${PORT_OPTIONS:MMUSIC}
	cd ${WRKDIR} && ${GZIP_CMD} -dc ${DISTDIR}/${MUSICNAME}.tar.gz  | ${TAR} -xf -
.endif

post-install:
.if ${PORT_OPTIONS:MMUSIC}
	${MKDIR} ${DATADIR}/data/music
	${FIND} -E ${MUSICDIR} -type f -iregex ".*\.ogg" \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/${MUSICSUBDIR}" \;
.endif

.include <bsd.port.mk>
