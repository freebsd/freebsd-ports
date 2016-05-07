# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.5.2
PORTREVISION=   2
CATEGORIES=	emulators

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen Hyvervisor meta port

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	/boot/xen:emulators/xen-kernel \
		xl:sysutils/xen-tools

USES=		metaport

.include <bsd.port.mk>
