# Created by: Emmanuel Vadot <manu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	VVVVVV
PORTVERSION=	v2.2
CATEGORIES=	games

MAINTAINER=	manu@FreeBSD.org
COMMENT=	2D Platformer game

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/../LICENSE.md
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		sdl cmake
USE_GITHUB=	yes
GH_ACCOUNT=	TerryCavanagh
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	cb3640e5

WRKSRC_SUBDIR=	desktop_version

USE_SDL=	sdl2 mixer2

PLIST_FILES=	bin/vvvvvv

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/vvvvvv.x86_64 ${STAGEDIR}${PREFIX}/bin/vvvvvv
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vvvvvv

.include <bsd.port.mk>
