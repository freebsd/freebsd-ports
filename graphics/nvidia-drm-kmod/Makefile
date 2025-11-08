PORTNAME=	nvidia-drm-kmod
DISTVERSION?=	${NVIDIA_DISTVERSION}
PORTREVISION?=	0
CATEGORIES=	graphics kld

MAINTAINER=	x11@FreeBSD.org
COMMENT=	NVIDIA DRM Kernel Module
WWW=		https://www.nvidia.com/object/unix.html

USES=		metaport

.include "${.CURDIR}/../../x11/nvidia-driver/Makefile.version"
.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=         not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.  if ${OSVERSION} >= 1302000 && ${OSVERSION} < 1400097
RUN_DEPENDS+=  ${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-510-kmod${PKGNAMESUFFIX}
.  elif ${OSVERSION} >= 1400097 && (${ARCH} == i386 || ${ARCH} == aarch64)
RUN_DEPENDS+=  ${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-510-kmod${PKGNAMESUFFIX}
.  elif ${OSVERSION} >= 1500031 && ${ARCH} == amd64
RUN_DEPENDS+=	${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-66-kmod${PKGNAMESUFFIX}
.  elif ${OSVERSION} >= 1400508
RUN_DEPENDS+=  ${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-61-kmod${PKGNAMESUFFIX}
.  endif
.endif

RUN_DEPENDS+=  nvidia-driver${PKGNAMESUFFIX}>0:x11/nvidia-driver${PKGNAMESUFFIX}

CONFLICTS_INSTALL=	nvidia-drm-kmod*

.include <bsd.port.post.mk>
