# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xonotic
PORTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	http://nl.dl.xonotic.org/ \
		http://mirror.bitmissile.com/xonotic/releases/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png

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

OPTIONS_DEFINE=		ENCRYPTION
OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED ENCRYPTION

CLIENT_DESC=		Build client
CLIENT_LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
			libtheora.so:multimedia/libtheora \
			libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
CLIENT_USE=		SDL=sdl
CLIENT_ALL_TARGET=	sdl-release
CLIENT_PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.ico
CLIENT_DESKTOP_ENTRIES=	"Xonotic" \
			"" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
			"${PORTNAME}" \
			"Game;Shooter;" \
			""

DEDICATED_DESC=		Build dedicated server
DEDICATED_ALL_TARGET=	sv-release
DEDICATED_PLIST_FILES=	bin/${PORTNAME}-dedicated

ENCRYPTION_DESC=	Build encryption (required for stats submission)
ENCRYPTION_LIB_DEPENDS=	libd0_rijndael.so:security/d0_blind_id

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${BUILD_WRKSRC}/${MAKEFILE} ${BUILD_WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e '/LDFLAGS_BSDSV/s,$$,-L${LOCALBASE}/lib,' \
		${BUILD_WRKSRC}/makefile.inc
	@${ECHO_CMD} >> ${BUILD_WRKSRC}/prvm_offsets.h # silence 'no newline' warnings

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 ${STAGEDIR}${DATADIR}/data/

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-sdl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/misc/logos/icons_ico/xonotic.ico ${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated
	cd ${WRKSRC} && ${COPYTREE_SHARE} "server" ${STAGEDIR}${DATADIR}/
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${STAGEDIR}${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x

do-install-ENCRYPTION-on:
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
