PORTNAME=	nvidia-drm-kmod
PORTVERSION=	${NVIDIA_DISTVERSION}
CATEGORIES=	graphics kld

MAINTAINER=	ashafer@badland.io
COMMENT=	NVIDIA DRM Kernel Module
WWW=		https://github.com/amshafer/nvidia-driver

USES=		metaport

.include "${.CURDIR}/../../x11/nvidia-driver/Makefile.version"
.include <bsd.port.pre.mk>

# Only supported on FreeBSD 13.1+
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.  if ${OSVERSION} >= 1301000
RUN_DEPENDS+=	${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-510-kmod
.  else
IGNORE=		not supported for this FreeBSD version
.  endif
.endif

.include <bsd.port.post.mk>
