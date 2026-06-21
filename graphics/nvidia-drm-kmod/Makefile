PORTNAME=	nvidia-drm-kmod
DISTVERSION?=	${NVIDIA_DISTVERSION}
PORTREVISION?=	0
CATEGORIES=	graphics kld

MAINTAINER=	x11@FreeBSD.org
COMMENT=	NVIDIA DRM kernel module
WWW=		https://www.nvidia.com/object/unix.html

FLAVORS=	default 580 devel
FLAVOR?=	default
.if ${FLAVOR} != default
NVIDIA_DISTVERSION=	${NVIDIA_${FLAVOR}_DISTVERSION}
PKGNAMESUFFIX=		-${FLAVOR}
.endif

USES=		metaport

.include "${.CURDIR}/../../x11/nvidia-driver/Makefile.version"
.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=         not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.  if ${OSVERSION} >= 1500509 && ${ARCH} == amd64
RUN_DEPENDS+=	${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-612-kmod@${FLAVOR}
.  elif ${OSVERSION} >= 1500031 && ${ARCH} == amd64
RUN_DEPENDS+=	${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-66-kmod@${FLAVOR}
.  else
RUN_DEPENDS+=  ${KMODDIR}/nvidia-drm.ko:graphics/nvidia-drm-61-kmod@${FLAVOR}
.  endif
.endif

RUN_DEPENDS+=  nvidia-driver${FLAVOR:S/^/-&/:S/-default//}>0:x11/nvidia-driver${FLAVOR:S/^/-&/:S/-default//}

CONFLICTS_INSTALL=	nvidia-drm-kmod*

.include <bsd.port.post.mk>
