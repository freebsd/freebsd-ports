PORTNAME=	pipewalker
DISTVERSIONPREFIX=v
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the NetWalk game
WWW=		https://github.com/artemsen/pipewalker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson sdl pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	artemsen
MESON_ARGS=	-Dversion=${DISTVERSION}
USE_SDL=	sdl2 image2

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/pipewalker|${DATADIR}|' \
		${WRKSRC}/extra/pipewalker.6

.include <bsd.port.mk>
