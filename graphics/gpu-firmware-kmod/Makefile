# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpu-firmware-kmod
PORTVERSION=	g20170829
PORTREVISION=	1
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

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-firmware
GH_TAGNAME=	19fc21e

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200019
IGNORE=		not supported on 11.x or older, no kernel support
.endif

.include <bsd.port.post.mk>
