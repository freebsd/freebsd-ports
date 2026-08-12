PORTNAME=	TRX
DISTVERSIONPREFIX=	trx-
DISTVERSION=	1.10
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Open source re-implementation of Tomb Raider I, II and III
WWW=		https://github.com/LostArtefacts/TRX

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING.md

BUILD_DEPENDS=	uthash>0:devel/uthash
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpcre2-8.so:devel/pcre2

USES=		gl localbase:ldflags lua meson pkgconfig python:build sdl
USE_GITHUB=	yes
GH_ACCOUNT=	LostArtefacts
USE_GL=		gl glew
USE_SDL=	sdl2

MESON_ARGS=	-Dlua_dep=lua-${LUA_VER} \
		-Dstaticdeps=false \
		-Dtrx_version=${DISTVERSION}

PORTSCOUT=	limit:^1\.
SUB_FILES=	pkg-message trx.sh
SUB_LIST=	PORTNAME=${PORTNAME}

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}.bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.bin
	${INSTALL_SCRIPT} ${WRKDIR}/trx.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
