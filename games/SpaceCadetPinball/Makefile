PORTNAME=	SpaceCadetPinball
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	Release_
CATEGORIES=	games

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Decompilation of 3D Pinball for Windows
WWW=		https://github.com/k4zmu2a/SpaceCadetPinball

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake sdl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	k4zmu2a
GH_PROJECT=	SpaceCadetPinball

USE_SDL=	mixer2 sdl2
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
