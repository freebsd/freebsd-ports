# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	iortcw
PORTVERSION=	1.42d
CATEGORIES=	games

MAINTAINER=	t@tobik.me
COMMENT=	Game engine for Return to Castle Wolfenstein

LICENSE=	GPLv3

BUILD_DEPENDS=	opusfile>0:audio/opusfile
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libopus.so:audio/opus \
		libfreetype.so:print/freetype2

USES=		jpeg openal pkgconfig gmake
USE_GL=		gl
USE_SDL=	sdl2

USE_GITHUB=	yes

WOLFDIR=	"libexec/${PORTNAME}"
MAKE_ARGS=	BINDIR="${STAGEDIR}${PREFIX}/bin" \
		COPYDIR="${STAGEDIR}${PREFIX}/${WOLFDIR}"

PLIST_SUB=	ARCH="${ARCH}" WOLFDIR="${WOLFDIR}"

SUB_FILES=	iowolfsp iowolfmp iowolfded
SUB_LIST=	ARCH="${ARCH}" WOLFDIR="${PREFIX}/${WOLFDIR}"

OPTIONS_DEFINE=	MP SP
OPTIONS_DEFAULT=	MP SP
OPTIONS_SUB=	yes

MP_DESC=	Build multiplayer support
SP_DESC=	Build singleplayer support

SP_ALL_TARGET=	sp
SP_INSTALL_TARGET=	sp-install

MP_ALL_TARGET=	mp
MP_INSTALL_TARGET=	mp-install

BROKEN_aarch64=		Fails to configure: error: Architecture not supported

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install-MP-on:
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfmp ${STAGEDIR}${PREFIX}/bin/iowolfmp
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfded ${STAGEDIR}${PREFIX}/bin/iowolfded

post-install-SP-on:
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfsp ${STAGEDIR}${PREFIX}/bin/iowolfsp

.include <bsd.port.mk>
