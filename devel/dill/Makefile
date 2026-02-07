PORTNAME=	dill
DISTVERSION=	2.4.1-75
DISTVERSIONSUFFIX=	-g2598741
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code generation for generating executable code directly into memory
WWW=		https://github.com/GTkorvo/dill

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake shebangfix perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GTkorvo

SHEBANG_FILES=	dill-config.in

.include <bsd.port.mk>
