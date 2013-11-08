# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xonotic
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://nl.dl.xonotic.org/ \
		http://mirror.bitmissile.com/xonotic/releases/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

MANUAL_PACKAGE_BUILD=	huge

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Xonotic/source/darkplaces
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
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=CLIENT DEDICATED

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

CLIENT_LIB_DEPENDS+=	libmodplug.so:${PORTSDIR}/audio/libmodplug \
			libtheora.so:${PORTSDIR}/multimedia/libtheora \
			libvorbis.so:${PORTSDIR}/audio/libvorbis \
			libogg.so:${PORTSDIR}/audio/libogg

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
		${WRKSRC}/${MAKEFILE} ${WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e '/LDFLAGS_BSDSV/s,$$,-L${LOCALBASE}/lib,' \
		${WRKSRC}/makefile.inc
	@${ECHO_CMD} >> ${WRKSRC}/prvm_offsets.h # silence 'no newline' warnings

do-install:
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/darkplaces-sdl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/Xonotic/misc/logos/icons_ico/xonotic.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated
	cd ${WRKDIR}/Xonotic && ${COPYTREE_SHARE} "server" ${STAGEDIR}${DATADIR}/
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${STAGEDIR}${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x
.endif
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKDIR}/Xonotic/data/*.pk3 ${STAGEDIR}${DATADIR}/data/

.include <bsd.port.mk>
