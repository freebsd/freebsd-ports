# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-fbsd11.2-kmod
PORTVERSION=	g20180822
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

CONFLICTS_INSTALL=	drm-fbsd12.0-kmod drm-current-kmod drm-legacy-kmod

OPTIONS_DEFINE=	DEBUG

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-drm
GH_TAGNAME=	ef4d156

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000 && ${OSVERSION} < 1200045
IGNORE=		not supported on older CURRENT, no kernel support
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.include <bsd.port.mk>
