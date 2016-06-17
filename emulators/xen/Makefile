# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.7.0
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen Hypervisor meta port

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	/boot/xen:emulators/xen-kernel \
		xl:sysutils/xen-tools

USES=		metaport

.include <bsd.port.mk>
