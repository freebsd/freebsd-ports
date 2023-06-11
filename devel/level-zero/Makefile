PORTNAME=	level-zero
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	oneAPI Level Zero Specification Headers and Loader
WWW=		https://spec.oneapi.io/versions/latest/elements/l0/source/index.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	oneapi-src

post-extract:
	@${ECHO_CMD} ${DISTVERSION:E} >${WRKSRC}/VERSION_PATCH

.include <bsd.port.mk>
