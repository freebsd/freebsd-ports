PORTNAME=	drm-61-kmod
PORTVERSION=	${DRM_KMOD_DISTVERSION}
PORTREVISION=	6
CATEGORIES=	graphics kld

.include "Makefile.version"

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM drivers modules
WWW=		https://github.com/freebsd/drm-kmod/

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64 and powerpc64

CONFLICTS_INSTALL=	drm-510-kmod \
			drm-515-kmod \
			drm-66-kmod

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod
GH_TAGNAME=	${DRM_KMOD_GH_TAGNAME}

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message
SUB_LIST=	OPSYS=${OPSYS} OSREL=${OSREL}

.if ${OPSYS} == FreeBSD && !( ${OSVERSION} >= 1500008 || ( ${OSVERSION} >= 1400508 && ${OSVERSION} < 1500000 ))
IGNORE=		not supported on older than 14-STABLE 1400508, no kernel support
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

MAKE_ENV+=	MAKEOBJDIRPREFIX=${WRKSRC}/obj

pre-build:
		${MKDIR} ${WRKSRC}/obj
		(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} obj)

.include <bsd.port.mk>
