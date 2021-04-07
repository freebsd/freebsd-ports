PORTNAME=	simde
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for SIMD intrinsics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	simd-everywhere
GH_TUPLE=	nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/test/munit

MESON_ARGS=	-Dtests=false

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
	@${RM} -r ${BUILD_WRKSRC}/*
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS:S/Dtests=false/Dtests=true/}
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${TEST_TARGET}

.include <bsd.port.mk>
