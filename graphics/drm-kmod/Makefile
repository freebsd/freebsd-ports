PORTNAME=	drm-kmod
PORTVERSION=	20220907
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Metaport of DRM modules for the linuxkpi-based KMS components
WWW=		https://github.com/freebsd/drm-kmod

USES=		metaport

RUN_DEPENDS=	gpu-firmware-kmod>=20220511:graphics/gpu-firmware-kmod

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.  if ${OSVERSION} >= 1302000 && ${OSVERSION} < 1400097
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-510-kmod
_DRM_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
.  elif ${OSVERSION} >= 1400097 && (${ARCH} == i386 || ${ARCH} == aarch64)
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-510-kmod
_DRM_ARCHS=	aarch64 i386
.  elif ${OSVERSION} >= 1400097
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-515-kmod
_DRM_ARCHS=	amd64 powerpc64 powerpc64le
.  else
_DRM_ARCHS=
.  endif
.  if ! ${_DRM_ARCHS:M${ARCH}}
IGNORE=		not supported for this configuration
.  endif
.endif

.include <bsd.port.mk>
