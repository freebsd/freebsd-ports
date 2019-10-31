# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	iortcw
PORTVERSION=	1.51c
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Game engine for Return to Castle Wolfenstein

LICENSE=	GPLv3

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	fails to configure: Architecture not supported

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile

USES=		gl gmake jpeg openal pkgconfig sdl xorg
USE_GITHUB=	yes
USE_GL=		gl
USE_SDL=	sdl2

WOLFDIR=	"libexec/${PORTNAME}"
MAKE_ARGS=	BINDIR="${STAGEDIR}${PREFIX}/bin" \
		COPYDIR="${STAGEDIR}${PREFIX}/${WOLFDIR}"

# cf. PR 226980
LLD_UNSAFE=	yes

PLIST_SUB=	ARCH="${ARCH}" \
		WOLFDIR="${WOLFDIR}"

SUB_FILES=	iowolfded iowolfmp iowolfsp pkg-message
SUB_LIST=	ARCH="${ARCH}" \
		DISTVERSION="${DISTVERSION}" \
		WOLFDIR="${PREFIX}/${WOLFDIR}"

OPTIONS_DEFINE=		MP SP
OPTIONS_DEFAULT=	MP SP
OPTIONS_SUB=		yes

MP_DESC=	Build multiplayer support
SP_DESC=	Build singleplayer support

SP_ALL_TARGET=		sp
SP_DESKTOP_ENTRIES=	"Return to Castle Wolfenstein" \
			"Return to Castle Wolfenstein" \
			"${DATADIR}/wolf512.png" \
			"iowolfsp" \
			"Game;" \
			false
SP_INSTALL_TARGET=	sp-install

MP_ALL_TARGET=		mp
MP_DESKTOP_ENTRIES=	"Return to Castle Wolfenstein (MP)" \
			"Return to Castle Wolfenstein Multiplayer" \
			"${DATADIR}/wolf512.png" \
			"iowolfmp" \
			"Game;" \
			false
MP_INSTALL_TARGET=	mp-install

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} '/\.git\/index/d' ${WRKSRC}/SP/Makefile
	@${REINPLACE_CMD} '/\.git\/index/d' ${WRKSRC}/MP/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/MP/misc/wolf512.png ${STAGEDIR}${DATADIR}

post-install-MP-on:
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfmp ${STAGEDIR}${PREFIX}/bin/iowolfmp
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfded ${STAGEDIR}${PREFIX}/bin/iowolfded

post-install-SP-on:
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfsp ${STAGEDIR}${PREFIX}/bin/iowolfsp

.include <bsd.port.mk>
