PORTNAME=	libg722
DISTVERSIONPREFIX=	v_
DISTVERSION=	1_0_3-11
DISTVERSIONSUFFIX=	-gf29ac9b
CATEGORIES=	audio

MAINTAINER=	ports@sippysoft.com
COMMENT=	Software G.722 decoding/encoding library

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	${LICENSE:S/_/ /}
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sippy

TEST_TARGET=	test

.include <bsd.port.mk>
