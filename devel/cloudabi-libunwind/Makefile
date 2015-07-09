# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	0.241676
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

PLIST_FILES=	x86_64-unknown-cloudabi/lib/libunwind.a

SRCFILES=	Unwind-EHABI.cpp Unwind-sjlj.c UnwindLevel1-gcc-ext.c \
		UnwindLevel1.c UnwindRegistersRestore.S UnwindRegistersSave.S \
		libunwind.cpp

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-c++ \
		-O2 -std=c++11 -I${WRKSRC}/include \
		-I${WRKDIR}/libc++abi-${PORTVERSION}/include \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/src/$f
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libunwind.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	${INSTALL_DATA} ${WRKSRC}/libunwind.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/

.include <bsd.port.mk>
