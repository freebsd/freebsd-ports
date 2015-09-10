# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++abi
CATEGORIES=	devel
DISTNAME=	libcxxabi-${DISTVERSION}.src
DISTFILES=	libcxxabi-${DISTVERSION}.src${EXTRACT_SUFX} \
		libunwind-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C++ standard library support for CloudABI

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc++.a:${PORTSDIR}/devel/cloudabi-libc++

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
		-I${WRKDIR}/libunwind-${DISTVERSION}.src/include \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/src/$f.cpp
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libc++abi.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	${INSTALL_DATA} ${WRKSRC}/libc++abi.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/

.include "${.CURDIR}/../cloudabi-libc++/Makefile.common"

.include <bsd.port.mk>
