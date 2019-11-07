# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xonotic
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://nl.dl.xonotic.org/ \
		http://mirror.bitmissile.com/xonotic/releases/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libd0_blind_id.so:security/d0_blind_id \
		libd0_rijndael.so:security/d0_blind_id \
		libode.so:devel/ode

USES=		compiler:features gmake jpeg localbase shebangfix zip:infozip
SHEBANG_FILES=	server/rcon.pl server/rcon2irc/rcon2irc.pl
WRKSRC=		${WRKDIR}/Xonotic
BUILD_WRKSRC=	${WRKSRC}/source/darkplaces
MAKEFILE=	makefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" \
		DP_PRELOAD_DEPENDENCIES=yes \
		OPTIM_RELEASE="${CFLAGS}" \
		STRIP="${STRIP_CMD}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	# empty

PORTDATA=	*

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED

CLIENT_DESC=		Build client
CLIENT_LIB_DEPENDS=	libtheora.so:multimedia/libtheora \
			libvorbis.so:audio/libvorbis \
			libvorbisenc.so:audio/libvorbis \
			libvorbisfile.so:audio/libvorbis \
			libogg.so:audio/libogg
CLIENT_USES=		sdl xorg
CLIENT_USE=		SDL=sdl2 XORG=x11
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

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fno-strict-aliasing -fno-math-errno -ffinite-math-only -fno-rounding-math -fno-signaling-nans -fno-trapping-math

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${BUILD_WRKSRC}/makefile ${BUILD_WRKSRC}/makefile.inc

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 ${STAGEDIR}${DATADIR}/data/
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk ${STAGEDIR}${DATADIR}/

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-sdl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/misc/logos/icons_ico/xonotic.ico ${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated
	cd ${WRKSRC} && ${COPYTREE_SHARE} "server" ${STAGEDIR}${DATADIR}/
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${STAGEDIR}${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x

.include <bsd.port.mk>
