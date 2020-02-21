# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-fbsd11.2-kmod
PORTVERSION=	4.11g20200221
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-devel-kmod \
			drm-fbsd12.0-kmod \
			drm-current-kmod \
			drm-legacy-kmod

OPTIONS_DEFINE=	DEBUG

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-drm
GH_TAGNAME=	c1b4d3a

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1200000
IGNORE=		only supported on FreeBSD 11.
.endif

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.include <bsd.port.mk>
