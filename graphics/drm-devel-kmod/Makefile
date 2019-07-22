# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-devel-kmod
PORTVERSION=	5.0.g20190722
CATEGORIES=	graphics kld

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components (development version)

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64, i386 and powerpc64

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-current-kmod \
			drm-fbsd11.2-kmod \
			drm-fbsd12.0-kmod \
			drm-legacy-kmod

OPTIONS_DEFINE=	DEBUG

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-drm
GH_TAGNAME=	938547c

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300029
IGNORE=		not supported on older CURRENT, no kernel support
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915=""
PLIST_SUB+=	VMWGFX=""
.  if ${OSVERSION} >= 1300033
PLIST_SUB+=	VBOXVIDEO=""
.  else
PLIST_SUB+=	VBOXVIDEO="@comment "
.  endif
.elif ${ARCH} == "i386"
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915=""
PLIST_SUB+=     VMWGFX=""
.  if ${OSVERSION} >= 1300033
PLIST_SUB+=	VBOXVIDEO=""
.  else
PLIST_SUB+=	VBOXVIDEO="@comment "
.  endif
.elif ${ARCH} == "powerpc64"
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	AMDKFD="@comment " 
PLIST_SUB+=	I915="@comment "
PLIST_SUB+=     VMWGFX="@comment "
.else
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915="@comment "
PLIST_SUB+=     VMWGFX="@comment "
.endif

.include <bsd.port.mk>
