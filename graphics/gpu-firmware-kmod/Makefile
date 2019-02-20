# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpu-firmware-kmod
PORTVERSION=	g20190219
CATEGORIES=	graphics

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Firmware modules for the linuxkpi-based KMS components

LICENSE=	AMD INTEL
LICENSE_COMB=	multi
LICENSE_NAME_AMD=	AMD firmware license (amdgpu/radeon)
LICENSE_NAME_INTEL=	Intel firmware license (i915)
LICENSE_FILE_AMD=	${WRKSRC}/LICENSE.radeon
LICENSE_FILE_INTEL=	${WRKSRC}/LICENSE.i915
LICENSE_PERMS_AMD=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept
LICENSE_PERMS_INTEL=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-firmware
GH_TAGNAME=	858e54d

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000 && ${OSVERSION} < 1200019
IGNORE=		not supported on older CURRENT, no kernel support
.endif

.include <bsd.port.post.mk>
