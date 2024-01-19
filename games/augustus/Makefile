PORTNAME=	augustus
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source re-implementation of Caesar III
WWW=		https://github.com/Keriew/augustus

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libpng.so:graphics/png

USES=		cmake sdl

USE_GITHUB=	yes
GH_ACCOUNT=	Keriew

USE_SDL=	mixer2 sdl2

SUB_FILES=	pkg-message

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
