# Created by: Johannes Dieterich <jmd@FreeBSD.org>

PORTNAME=	drm-devel-kmod
PORTVERSION=	5.7.19.g20220126
CATEGORIES=	graphics kld

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components (development version)

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64, arm64, i386, and powerpc64

RUN_DEPENDS=	gpu-firmware-kmod>=g20200914:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-current-kmod

OPTIONS_DEFINE=	DEBUG

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod
GH_TAGNAME=	drm_v5.7.19

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1300525 || \
	(${OSVERSION} < 1400047 && ${OSVERSION} >= 1400000))
IGNORE=		not supported on older CURRENT/STABLE, no kernel support
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915=""
.elif ${ARCH} == "i386"
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915=""
.elif ${ARCH} == "aarch64" || ${ARCH:Mpowerpc*}
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	AMDKFD="@comment " 
PLIST_SUB+=	I915="@comment "
.else
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	AMDKFD="@comment "
PLIST_SUB+=	I915="@comment "
.endif

.include <bsd.port.mk>
