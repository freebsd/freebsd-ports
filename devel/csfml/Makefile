PORTNAME=	csfml
DISTVERSION=	2.5.2
CATEGORIES=	devel games graphics multimedia

MAINTAINER=	agh@riseup.net
COMMENT=	C bindings to the Simple and Fast Multimedia Library (SFML)
WWW=		https://www.sfml-dev.org/download/csfml/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.md

LIB_DEPENDS=	libsfml-audio.so:devel/sfml \
		libsfml-graphics.so:devel/sfml \
		libsfml-network.so:devel/sfml \
		libsfml-system.so:devel/sfml \
		libsfml-window.so:devel/sfml

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	SFML
GH_PROJECT=	${PORTNAME:tu}

.include <bsd.port.mk>
