PORTNAME=	julius
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-caesariii

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source re-implementation of Caesar III
WWW=		https://github.com/bvschaik/julius

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_INSTALL=	julius

LIB_DEPENDS=	libpng.so:graphics/png

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
