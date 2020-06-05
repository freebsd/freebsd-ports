# $FreeBSD$

PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
CATEGORIES=	lang

COMMENT=	Mesa OpenCL implementation for AMD GPUs

BUILD_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	Clover needs a GPU supported by the Radeon KMS driver

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers=r600,radeonsi \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dgallium-vdpau=false \
		-Dgallium-omx=disabled \
		-Dgallium-va=false \
		-Dgallium-opencl=disabled \
		-Dgallium-xa=false \
		-Dgallium-xvmc=false \
		-Dgallium-nine=false \
		-Dgles1=false \
		-Dgles2=false \
		-Dopengl=false \
		-Dglx=disabled \
		-Degl=false \
		-Dgbm=false \
		-Dgallium-opencl=icd \
		-Dtools=""

LDFLAGS_i386=		-Wl,-znotext

.include "${MASTERDIR}/Makefile.targets"

pre-patch:
	@if [ -e ${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} ] && \
		! [ -e ${LOCALBASE}/bin/clang${LLVM_DEFAULT} ]; then \
		${ECHO_MSG} "Your llvm${LLVM_DEFAULT} is not built with clang support, which is required."; \
		${FALSE}; \
	fi

.include <bsd.port.post.mk>
