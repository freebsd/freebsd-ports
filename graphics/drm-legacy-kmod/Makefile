# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-legacy-kmod
PORTVERSION=	g20181031
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Legacy DRM modules for the linuxkpi-based KMS components

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	gpu-firmware-kmod>=g20180319:graphics/gpu-firmware-kmod

USES=		kmod uidfix

OPTIONS_DEFINE=	DEBUG

CONFLICTS_INSTALL=	drm-fbsd11.2-kmod drm-fbsd12.0-kmod drm-current-kmod

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	drm-legacy
GH_TAGNAME=	a6fcc19

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200080
IGNORE=		only for 12.0 or higher after removal of base components
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

.include <bsd.port.mk>
