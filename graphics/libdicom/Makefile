PORTNAME=	libdicom
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading DICOM files
WWW=		https://libdicom.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/utarray.h:devel/uthash
TEST_DEPENDS=	check>0:devel/check

USES=		localbase meson pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ImagingDataCommons

MESON_ARGS=	-Dtests=false

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} configure . -Dtests=true && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_ARGS} meson-test-prereq test

# tests as of 1.3.0: Ok: 1, Fail: 0

.include <bsd.port.mk>
