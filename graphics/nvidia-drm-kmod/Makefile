PORTNAME=	nvidia-drm-kmod
PORTVERSION=	${NVIDIA_DISTVERSION}
CATEGORIES=	graphics kld

MAINTAINER=	ashafer@badland.io
COMMENT=	NVIDIA DRM Kernel Module
WWW=		https://github.com/amshafer/nvidia-driver

USES=		metaport

RUN_DEPENDS+=	${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-510-kmod

.include "${.CURDIR}/../../x11/nvidia-driver/Makefile.version"
.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.include <bsd.port.post.mk>
