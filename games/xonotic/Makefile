# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xonotic
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://nl.dl.xonotic.org/ \
		http://mirror.bitmissile.com/xonotic/releases/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpng.so:${PORTSDIR}/graphics/png

#MANUAL_PACKAGE_BUILD=	huge (930M)

USES=		jpeg shebangfix zip:infozip
SHEBANG_FILES=	server/rcon.pl server/rcon2irc/rcon2irc.pl
WRKSRC=		${WRKDIR}/Xonotic
BUILD_WRKSRC=	${WRKSRC}/source/darkplaces
MAKEFILE=	BSDmakefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" \
		DP_PRELOAD_DEPENDENCIES=yes \
		CFLAGS_LIBJPEG="-I${LOCALBASE}/include -DLINK_TO_LIBJPEG" \
		OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops" \
		STRIP="${STRIP_CMD}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	# empty
USE_GCC=	yes

PORTDATA=	*

OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED ENCRYPTION
OPTIONS_DEFAULT=CLIENT DEDICATED ENCRYPTION

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
ENCRYPTION_DESC=Build encryption (required for stats submission)

CLIENT_LIB_DEPENDS+=	libmodplug.so:${PORTSDIR}/audio/libmodplug \
			libtheora.so:${PORTSDIR}/multimedia/libtheora \
			libvorbis.so:${PORTSDIR}/audio/libvorbis \
			libogg.so:${PORTSDIR}/audio/libogg

ENCRYPTION_LIB_DEPENDS=	libd0_rijndael.so:${PORTSDIR}/security/d0_blind_id

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
PLIST_FILES+=	bin/${PORTNAME}

DESKTOP_ENTRIES="Xonotic" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;Shooter;" \
		""

PLIST_FILES+=	share/pixmaps/${PORTNAME}.ico
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	sv-release
PLIST_FILES+=	bin/${PORTNAME}-dedicated
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${BUILD_WRKSRC}/${MAKEFILE} ${BUILD_WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e '/LDFLAGS_BSDSV/s,$$,-L${LOCALBASE}/lib,' \
		${BUILD_WRKSRC}/makefile.inc
	@${ECHO_CMD} >> ${BUILD_WRKSRC}/prvm_offsets.h # silence 'no newline' warnings

do-install:
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-sdl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/misc/logos/icons_ico/xonotic.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated
	cd ${WRKSRC} && ${COPYTREE_SHARE} "server" ${STAGEDIR}${DATADIR}/
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${STAGEDIR}${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x
.endif
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 ${STAGEDIR}${DATADIR}/data/
.if ${PORT_OPTIONS:MENCRYPTION}
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk ${STAGEDIR}${DATADIR}/
.endif

.include <bsd.port.mk>
