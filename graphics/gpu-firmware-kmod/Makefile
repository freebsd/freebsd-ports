# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpu-firmware-kmod
PORTVERSION=	g20170829
CATEGORIES=	graphics

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Firmware modules for the linuxkpi-based KMS components

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64

NO_PACKAGE=	Distribution in binary form without license file not allowed

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	kms-firmware
GH_TAGNAME=	3bfbfff

USES=		kmod uidfix

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200019
IGNORE=		not supported on 11.x or older, no kernel support
.endif

.include <bsd.port.post.mk>
