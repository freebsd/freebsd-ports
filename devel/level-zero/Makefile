PORTNAME=	level-zero
PORTVERSION=	1.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	oneAPI Level Zero Specification Headers and Loader
WWW=		https://spec.oneapi.io/versions/latest/elements/l0/source/index.html \
		https://github.com/oneapi-src/level-zero

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	oneapi-src

post-patch:
	@${ECHO_CMD} ${PORTVERSION:E} > ${WRKSRC}/VERSION_PATCH

.include <bsd.port.mk>
