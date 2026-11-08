PORTNAME=	libg722
DISTVERSION=	1.2.8
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sippy/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@sippysoft.com
COMMENT=	Software G.722 decoding/encoding library

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	${LICENSE:S/_/ /}
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:testing
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING \
		ENABLE_STATIC_LIB

.include <bsd.port.mk>
