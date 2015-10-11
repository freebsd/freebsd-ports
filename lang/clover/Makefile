# $FreeBSD$

PORTNAME=	clover
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	lang

COMMENT=	Mesa "Clover" OpenCL library

BUILD_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl
LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libOpenCL.so:${PORTSDIR}/devel/ocl-icd \
		libexpat.so:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Clover needs a graphics driver supported by the Radeon KMS driver

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#MESA_BUILD_WRKSRC=	src/util src/glsl src/mesa src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/targets/opencl src/gallium/targets/pipe-loader

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1001000
IGNORE=		Clover is only supported on FreeBSD 10.1 and newer
.endif

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MV} ${STAGEDIR}/etc/OpenCL ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
