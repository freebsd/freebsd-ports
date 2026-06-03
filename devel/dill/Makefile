PORTNAME=	dill
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code generation for generating executable code directly into memory
WWW=		https://github.com/GTkorvo/dill

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing shebangfix perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GTkorvo

SHEBANG_FILES=	dill-config.in

CMAKE_OFF=		BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

# tests as of 3.5.0: 100% tests passed, 0 tests failed out of 18

.include <bsd.port.mk>
