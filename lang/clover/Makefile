PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
CATEGORIES=	lang

COMMENT=	Mesa OpenCL implementation for AMD GPUs
WWW=		https://dri.freedesktop.org/wiki/GalliumCompute/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	needs a GPU supported by the AMDGPU KMS driver

BUILD_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl

USES=		llvm:lib,max=16,noexport

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dplatforms="" \
		-Dvulkan-drivers="" \
		-Dandroid-libbacktrace=disabled \
		-Dgallium-nine=false \
		-Dgallium-omx=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-va=disabled \
		-Dgallium-vdpau=disabled \
		-Dgallium-xa=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dmicrosoft-clc=disabled \
		-Dopengl=false \
		-Dglx=disabled \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dtools="" \
		-Dxlib-lease=disabled \
		-Dlmsensors=disabled \
		-Dvalgrind=disabled \
		-Dgallium-opencl=icd \
		-Dgallium-drivers=r600,radeonsi

LDFLAGS_i386=		-Wl,-znotext

.include "${MASTERDIR}/Makefile.targets"

pre-patch:
	@if [ -e ${LOCALBASE}/bin/llvm-config${LLVM_VERSION} ] && \
		! [ -e ${LOCALBASE}/bin/clang${LLVM_VERSION} ]; then \
		${ECHO_MSG} "Your llvm${LLVM_VERSION} is not built with clang support, which is required."; \
		${FALSE}; \
	fi

.include <bsd.port.post.mk>
