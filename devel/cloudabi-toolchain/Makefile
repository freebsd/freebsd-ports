# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

USES=		metaport

LIBDIR=		${LOCALBASE}/x86_64-unknown-cloudabi/lib

# C and C++ compiler to be run on the development system.
RUN_DEPENDS+=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-cc:${PORTSDIR}/lang/cloudabi-clang

# Libraries for C language support.
RUN_DEPENDS+=	${LIBDIR}/libc.a:${PORTSDIR}/devel/cloudabi-cloudlibc \
		${LIBDIR}/libcompiler_rt.a:${PORTSDIR}/devel/cloudabi-compiler-rt

# Libraries for C++ language support.
RUN_DEPENDS+=	${LIBDIR}/libc++.a:${PORTSDIR}/devel/cloudabi-libc++ \
		${LIBDIR}/libc++abi.a:${PORTSDIR}/devel/cloudabi-libc++abi \
		${LIBDIR}/libunwind.a:${PORTSDIR}/devel/cloudabi-libunwind

.include <bsd.port.mk>
