PORTNAME=	bats-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bash automated testing system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash \
		flock:sysutils/flock

USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	PARALLEL

PARALLEL_DESC=		Install sysutils/parallel to enable parallel runs
PARALLEL_RUN_DEPENDS=	parallel:sysutils/parallel

do-install:
	cd ${WRKSRC} && ./install.sh ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
