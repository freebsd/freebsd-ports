# $FreeBSD$

PORTNAME=	compute-runtime
DISTVERSION=	21.11.19310
CATEGORIES=	lang
PKGNAMEPREFIX=	intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2a423820aaa4.patch:-p1 # https://github.com/intel/compute-runtime/pull/361

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	OpenCL implementation for Intel HD 5000 (Gen8) or newer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libigc.so:devel/intel-graphics-compiler \
		libigdgmm.so:multimedia/gmmlib

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_ON=	SKIP_UNIT_TESTS SUPPORT_DG1
CMAKE_ARGS=	-DNEO_OCL_DRIVER_VERSION:STRING="${DISTVERSIONFULL}"
PLIST_FILES=	bin/ocloc \
		etc/OpenCL/vendors/intel.icd \
		include/ocloc_api.h \
		lib/intel-opencl/libigdrcl.so \
		lib/libocloc.so \
		${NULL}

OPTIONS_DEFINE=	VAAPI
OPTIONS_DEFAULT=VAAPI
OPTIONS_DEFINE_amd64=	L0
OPTIONS_DEFAULT_amd64=	L0

L0_DESC=		oneAPI Level Zero support
L0_BUILD_DEPENDS=	level-zero>=1.0:devel/level-zero
L0_CMAKE_BOOL=		BUILD_WITH_L0
L0_CMAKE_ON=		-DNEO_VERSION_BUILD:STRING="0"
L0_PLIST_FILES=		lib/libze_intel_gpu.so.1 \
			lib/libze_intel_gpu.so.1.0.0

VAAPI_BUILD_DEPENDS=	${LOCALBASE}/include/va/va.h:multimedia/libva
VAAPI_CMAKE_BOOL_OFF=	DISABLE_LIBVA

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
