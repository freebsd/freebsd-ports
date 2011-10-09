# New ports collection makefile for:	tmw
# Date created:				12 Oktober 2005
# Whom:					Tobias Gion
#
# $FreeBSD$
#

PORTNAME=	tmw
PORTVERSION=	0.5.2
CATEGORIES=	games
MASTER_SITES=	SF/themanaworld/The%20Mana%20World/${PORTVERSION}/:src
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A free open source 2D MMORPG in development

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.6:${PORTSDIR}/graphics/png \
		curl.6:${PORTSDIR}/ftp/curl \
		physfs.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan

USE_CMAKE=	yes
USE_SDL=	sdl gfx image mixer net ttf
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
DATADIR=	${PREFIX}/share/mana

OPTIONS=	MANASERV	"Enable server component" off \
		MUSIC		"Install additional music" on \
		NLS		"Enable gettext support" on \
		OPENGL		"Enable OpenGL support" on \

.include <bsd.port.pre.mk>

.if defined(WITH_MANASERV)
CMAKE_ARGS+=	-DENABLE_MANASERV:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_MANASERV:BOOL=OFF
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=ON
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=OFF
.endif

.if !defined(WITHOUT_MUSIC)
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

.if defined(WITHOUT_OPENGL)
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=ON
USE_OPENGL=	yes
.endif

post-extract:
.if !defined(WITHOUT_MUSIC)
	cd ${WRKDIR} && ${GZIP_CMD} -dc ${DISTDIR}/${MUSICNAME}.tar.gz  | ${TAR} -xf -
.endif

post-install:
.if !defined(WITHOUT_MUSIC)
	${MKDIR} ${DATADIR}/data/music
	${FIND} -E ${MUSICDIR} -type f -iregex ".*\.ogg" \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/${MUSICSUBDIR}" \;
.endif

.include <bsd.port.post.mk>
