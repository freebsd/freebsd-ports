# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-kmod
PORTVERSION=	g20190710
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Metaport of DRM modules for the linuxkpi-based KMS components

USES=		metaport

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.else
.if ${ARCH} != "amd64"
.if ${OSVERSION} >= 1200080
RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-legacy-kmod
.elif ${OSVERSION} < 1200080
IGNORE=		legacy kmod not required on less than 12.0
.endif
.else
.if ${OSVERSION} >= 1103000 && ${OSVERSION} < 1200000
RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-fbsd11.2-kmod
.elif ${OSVERSION} >= 1200000 && ${OSVERSION} < 1200045
IGNORE=		not supported on older 12, no kernel support
.elif ${OSVERSION} >= 1200045 && ${OSVERSION} < 1200058
RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-fbsd11.2-kmod
.elif ${OSVERSION} >= 1200058 && ${OSVERSION} < 1300000
RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-fbsd12.0-kmod
.elif ${OSVERSION} >= 1300000 && ${OSVERSION} < 1300029
IGNORE=		not supported on older 13, no kernel support
.elif ${OSVERSION} >= 1300029
RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-current-kmod
.else
IGNORE=		not supported for this configuration
.endif
.endif
.endif

.include <bsd.port.mk>
