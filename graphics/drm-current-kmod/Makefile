# Created by: Johannes Dieterich <jmd@FreeBSD.org>

PORTNAME=	drm-current-kmod
PORTVERSION=	5.4.144.g20220128
CATEGORIES=	graphics kld

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64, i386, aarch64, and powerpc64

RUN_DEPENDS=	gpu-firmware-kmod>=g20200914:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-devel-kmod

OPTIONS_DEFINE=	DEBUG SOURCE

SOURCE_DESC=	Install kernel module sources

OPTIONS_SUB=	yes

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod
GH_TAGNAME=	drm_v5.4.144_5

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400000
IGNORE=		not supported on older CURRENT, no kernel support
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	I915=""
.elif ${ARCH} == "i386"
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	I915=""
.elif ${ARCH} == "aarch64" || ${ARCH:Mpowerpc*}
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	I915="@comment "
.else
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	I915="@comment "
.endif

KMODSRC=	${STAGEDIR}${PREFIX}/sys/modules/${PORTNAME}
SRCDIRS=	amd drivers drm i915 include linuxkpi radeon ttm vmwgfx vboxvideo

PLIST_SUB+=	KMODSRC="sys/modules/${PORTNAME}"

MAKE_ENV+=	MAKEOBJDIRPREFIX=${WRKSRC}/obj

pre-build:
		${MKDIR} ${WRKSRC}/obj
		(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} obj)

post-install-SOURCE-on:
		${MKDIR} ${KMODSRC}
		${INSTALL_DATA} ${WRKSRC}/Makefile ${KMODSRC}
		${INSTALL_DATA} ${WRKSRC}/kconfig.mk ${KMODSRC}
.for dir in ${SRCDIRS}
		cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${KMODSRC}
.endfor

.include <bsd.port.mk>
