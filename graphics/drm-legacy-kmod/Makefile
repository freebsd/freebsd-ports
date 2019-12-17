# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-legacy-kmod
PORTVERSION=	g20191217
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Legacy DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

BROKEN_aarch64=		src/dev/drm2/ttm/ttm_bo_util.c:453:2: error: Port me

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

USES=		kmod uidfix

OPTIONS_DEFINE=	DEBUG

CONFLICTS_INSTALL=	drm-devel-kmod \
			drm-fbsd11.2-kmod \
			drm-fbsd12.0-kmod \
			drm-current-kmod

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	drm-legacy
GH_TAGNAME=	af3f27b

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200080
IGNORE=		only for 12.0 or higher after removal of base components
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

.include <bsd.port.mk>
