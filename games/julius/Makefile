# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	julius
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-caesariii

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source re-implementation of Caesar III

LICENSE=	GPLv3

BROKEN=		use of undeclared identifier 'SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH'

USES=		cmake sdl

USE_GITHUB=	yes
GH_ACCOUNT=	bvschaik

USE_SDL=	mixer2 sdl2

SUB_FILES=	pkg-message

LDFLAGS+=	-lexecinfo
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
