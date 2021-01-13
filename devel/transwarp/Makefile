# $FreeBSD$

PORTNAME=	transwarp
DISTVERSION=	2.2.1-4
DISTVERSIONSUFFIX=	-ge5ce19e
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for task concurrency

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	bloomen

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/transwarp.h

do-install: # https://github.com/bloomen/transwarp/issues/32
	${INSTALL_DATA} ${WRKSRC}/src/transwarp.h ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
