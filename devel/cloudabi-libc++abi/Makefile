# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++abi
PORTVERSION=	0.240527
CATEGORIES=	devel
MASTER_SITES=	https://nuxi.nl/distfiles/libc++abi/:libcxxabi \
		https://nuxi.nl/distfiles/libunwind/:libunwind
PKGNAMEPREFIX=	cloudabi-
DISTFILES=	libc++abi-${PORTVERSION}${EXTRACT_SUFX}:libcxxabi \
		libunwind-${PORTVERSION}${EXTRACT_SUFX}:libunwind

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C++ standard library support for CloudABI

LICENSE=	MIT

BUILD_DEPENDS=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-c++:${PORTSDIR}/lang/cloudabi-clang \
		${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc.a:${PORTSDIR}/devel/cloudabi-cloudlibc \
		${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc++.a:${PORTSDIR}/devel/cloudabi-libc++

USES=		tar:xz

PLIST_FILES=	x86_64-unknown-cloudabi/lib/libc++abi.a

SRCFILES=	abort_message cxa_aux_runtime cxa_default_handlers \
		cxa_demangle cxa_exception cxa_exception_storage cxa_guard \
		cxa_handlers cxa_new_delete cxa_personality cxa_thread_atexit \
		cxa_unexpected cxa_vector cxa_virtual exception \
		private_typeinfo stdexcept typeinfo

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-c++ \
		-O2 -std=c++11 -I${WRKSRC}/include \
		-I${WRKDIR}/libunwind-${PORTVERSION}/include \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/src/$f.cpp
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libc++abi.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	${INSTALL_DATA} ${WRKSRC}/libc++abi.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/

.include <bsd.port.mk>
