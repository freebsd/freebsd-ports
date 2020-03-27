# $FreeBSD$

PORTNAME=	compute-runtime
DISTVERSION=	20.12.16259
CATEGORIES=	lang
PKGNAMEPREFIX=	intel-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	OpenCL implementation for Intel HD 5000 (Gen8) or newer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libigc.so:devel/intel-graphics-compiler \
		libigdgmm.so:multimedia/gmmlib

USES=		cmake compiler:c++14-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_ON=	SKIP_UNIT_TESTS
CMAKE_ARGS=	-DNEO_DRIVER_VERSION:STRING="${DISTVERSIONFULL}"
PLIST_FILES=	etc/OpenCL/vendors/intel.icd \
		bin/ocloc \
		lib/intel-opencl/libigdrcl.so

post-patch:
	@${REINPLACE_CMD} -e '/-Werror/d' \
		-e '/FORCE_RESPONSE_FILE/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/OCL_ICD_VENDORDIR/s,/etc,${PREFIX}&,' \
		${WRKSRC}/package.cmake

post-install:
# install/strip has no effect on install(FILES), so strip manually
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/intel-opencl/*.so

.include <bsd.port.mk>
