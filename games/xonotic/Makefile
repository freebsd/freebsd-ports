PORTNAME=	xonotic
PORTVERSION=	0.8.6
CATEGORIES=	games
MASTER_SITES=	https://dl.xonotic.org/ \
		https://download.evil-ant-colony.org/xonotic/ \
		https://xonotic.antzucaro.com/ \
		https://ocv.xonotic.au/downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter
WWW=		https://xonotic.org/

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
		STRIP="${STRIP_CMD}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	# empty

PORTDATA=	*

OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED
OPTIONS_SUB=		yes

CLIENT_DESC=		Build client
CLIENT_LIB_DEPENDS=	libtheora.so:multimedia/libtheora \
			libvorbis.so:audio/libvorbis \
			libvorbisenc.so:audio/libvorbis \
			libvorbisfile.so:audio/libvorbis \
			libogg.so:audio/libogg
CLIENT_USES=		sdl xorg
CLIENT_USE=		SDL=sdl2 XORG=x11
CLIENT_ALL_TARGET=	sdl-release

DEDICATED_DESC=		Build dedicated server
DEDICATED_ALL_TARGET=	sv-release

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${BUILD_WRKSRC}/makefile ${BUILD_WRKSRC}/makefile.inc

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 ${STAGEDIR}${DATADIR}/data/
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk ${STAGEDIR}${DATADIR}/

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-sdl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/misc/logos/xonotic.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/misc/logos/xonotic_icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/xonotic.svg
.for s in 16 22 24 32 48 64 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/misc/logos/icons_png/xonotic_${s}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/xonotic.png
.endfor

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated
	cd ${WRKSRC} && ${COPYTREE_SHARE} "server" ${STAGEDIR}${DATADIR}/
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${STAGEDIR}${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x

.include <bsd.port.mk>
