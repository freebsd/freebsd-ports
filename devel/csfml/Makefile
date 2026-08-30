PORTNAME=	csfml
DISTVERSION=	3.0.0
CATEGORIES=	devel games graphics multimedia

MAINTAINER=	wen@FreeBSD.org
COMMENT=	C bindings to the Simple and Fast Multimedia Library (SFML)
WWW=		https://www.sfml-dev.org/download/csfml/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.md

LIB_DEPENDS=	libsfml-audio.so:multimedia/sfml3 \
		libsfml-graphics.so:multimedia/sfml3 \
		libsfml-network.so:multimedia/sfml3 \
		libsfml-system.so:multimedia/sfml3 \
		libsfml-window.so:multimedia/sfml3

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	SFML
GH_PROJECT=	${PORTNAME:tu}

PLIST_SUB=	SO_RELEASE=${_SO_RELEASE} \
		SO_VERSION=${_SO_VERSION}

_SO_RELEASE=	${DISTVERSION:R}
_SO_VERSION=	${DISTVERSION}

.include <bsd.port.mk>
