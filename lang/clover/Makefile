PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	lang

COMMENT=	Mesa OpenCL implementation for AMD GPUs

BUILD_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl

ONLY_FOR_ARCHS=		i386 amd64 powerpc64le powerpc64
ONLY_FOR_ARCHS_REASON=	Clover needs a GPU supported by the Radeon KMS driver
BROKEN_FreeBSD_11=	undefined reference to `vl_video_buffer_plane_order'

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Ddri-drivers="" \
		-Dplatforms="" \
		-Dvulkan-drivers="" \
		-Dgallium-nine=false \
		-Dgallium-omx=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-va=disabled \
		-Dgallium-vdpau=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-xvmc=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dopengl=false \
		-Dglx=disabled \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dtools="" \
		-Dgallium-opencl=icd \
		-Dgallium-drivers=r600,radeonsi

LDFLAGS_i386=		-Wl,-znotext

.include "${MASTERDIR}/Makefile.targets"

pre-patch:
	@if [ -e ${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} ] && \
		! [ -e ${LOCALBASE}/bin/clang${LLVM_DEFAULT} ]; then \
		${ECHO_MSG} "Your llvm${LLVM_DEFAULT} is not built with clang support, which is required."; \
		${FALSE}; \
	fi

.include <bsd.port.post.mk>
