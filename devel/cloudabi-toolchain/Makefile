# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.2
CATEGORIES=	devel

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

USES=		metaport

LIBDIR=		${LOCALBASE}/x86_64-unknown-cloudabi/lib

RUN_DEPENDS+=	aarch64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils-aarch64 \
		x86_64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils-x86_64 \
		x86_64-unknown-cloudabi-cc:${PORTSDIR}/lang/cloudabi-clang

.include <bsd.port.mk>
