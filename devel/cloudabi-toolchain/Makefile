# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

USES=		metaport

LIBDIR=		${LOCALBASE}/x86_64-unknown-cloudabi/lib

RUN_DEPENDS+=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-cc:${PORTSDIR}/lang/cloudabi-clang

.include <bsd.port.mk>
