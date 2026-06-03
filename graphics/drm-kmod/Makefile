PORTNAME=	drm-kmod
PORTVERSION=	20260508
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Direct Rendering Manager (DRM) GPU drivers metaport
WWW=		https://github.com/freebsd/drm-kmod

USES=		metaport

RUN_DEPENDS=	gpu-firmware-kmod>=20220511:graphics/gpu-firmware-kmod

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.  if ${OSVERSION} >= 1500509 && ${ARCH} == amd64
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-612-kmod
_DRM_ARCHS=	amd64
.  elif ${OSVERSION} >= 1500031 && ${ARCH} == amd64
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-66-kmod
_DRM_ARCHS=	amd64
.  else
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-61-kmod
_DRM_ARCHS=	amd64 powerpc64 powerpc64le
.  endif
.  if ! ${_DRM_ARCHS:M${ARCH}}
IGNORE=		not supported for this configuration
.  endif
.endif

.include <bsd.port.mk>
