PORTNAME=	shunit2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.8-93
DISTVERSIONSUFFIX=	-g47be8b2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	xUnit based unit testing for Unix shell scripts
WWW=		https://github.com/kward/shunit2/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	kward

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${REINPLACE_CMD} -e 's|#! /bin/sh|#! ${LOCALBASE}/bin/bash|' \
		${WRKSRC}/shunit2 \
		${WRKSRC}/test_runner

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shunit2 ${STAGEDIR}${PREFIX}/bin

do-test:
	@cd ${WRKSRC} && SHELL=${LOCALBASE}/bin/bash bash ./test_runner -s ${LOCALBASE}/bin/bash

.include <bsd.port.mk>
