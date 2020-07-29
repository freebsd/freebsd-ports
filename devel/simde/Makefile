# $FreeBSD$

PORTNAME=	simde
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for SIMD intrinsics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	simd-everywhere
GH_TUPLE=	nemequ:munit:fbbdf1467eb0d04a6ee465def2e529e4c87f2118:nemequ_munit/test/munit

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
	cd ${WRKSRC}
	rm -rf _build
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dbuild_tests=true
	cd ${BUILD_WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
