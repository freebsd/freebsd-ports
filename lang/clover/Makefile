# $FreeBSD$

PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
CATEGORIES=	lang

COMMENT=	Mesa "Clover" OpenCL library

BUILD_DEPENDS=	libclc>=0.2.0.20160915:devel/libclc \
		opencl>=0:devel/opencl \
		${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	Clover needs a GPU supported by the Radeon KMS driver

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--enable-opencl --enable-opencl-icd --disable-dri \
			--disable-egl --disable-gbm --disable-glx \
			--disable-va --disable-vdpau --disable-xvmc \
			--with-gallium-drivers=r600,radeonsi

#MESA_BUILD_WRKSRC=	src/util src/compiler src/mesa src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/targets/opencl src/gallium/targets/pipe-loader

.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.targets"

pre-configure:
	@if [ -e ${LOCALBASE}/bin/llvm-config${MESA_LLVM_VER} ] && \
		! [ -e ${LOCALBASE}/bin/clang${MESA_LLVM_VER} ]; then \
		${ECHO_MSG} "Your llvm${MESA_LLVM_VER} is not built with clang support, which is required."; \
		${FALSE}; \
	fi

post-install:
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
