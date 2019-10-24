# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-fbsd12.0-kmod
PORTVERSION=	4.16.g20191024
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64 and i386

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-devel-kmod \
			drm-fbsd11.2-kmod \
			drm-current-kmod \
			drm-legacy-kmod

OPTIONS_DEFINE=	DEBUG

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-drm
GH_TAGNAME=	9e308e6

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1200058 || ${OSVERSION} > 1300000)
IGNORE=		only supported on FreeBSD 12.
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=     AMDGPU=""
PLIST_SUB+=     AMDKFD=""
PLIST_SUB+=     I915=""
PLIST_SUB+=     VMWGFX=""
.elif ${ARCH} == "i386"
PLIST_SUB+=     AMDGPU="@comment "
PLIST_SUB+=     AMDKFD="@comment "
PLIST_SUB+=     I915=""
PLIST_SUB+=     VMWGFX=""
.elif ${ARCH} == "powerpc64"
PLIST_SUB+=     AMDGPU=""
PLIST_SUB+=     AMDKFD="@comment "
PLIST_SUB+=     I915="@comment "
PLIST_SUB+=     VMWGFX="@comment "
.else
PLIST_SUB+=     AMDGPU="@comment "
PLIST_SUB+=     AMDKFD="@comment "
PLIST_SUB+=     I915="@comment "
PLIST_SUB+=     VMWGFX="@comment "
.endif

.include <bsd.port.mk>
