PORTNAME=	bats-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bash automated testing system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ./install.sh ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
