# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++
PORTVERSION=	0.241676
CATEGORIES=	devel
MASTER_SITES=	https://nuxi.nl/distfiles/libc++/:libcxx \
		https://nuxi.nl/distfiles/libc++abi/:libcxxabi
PKGNAMEPREFIX=	cloudabi-
DISTFILES=	libc++-${PORTVERSION}${EXTRACT_SUFX}:libcxx \
		libc++abi-${PORTVERSION}${EXTRACT_SUFX}:libcxxabi

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C++ standard template library for CloudABI

LICENSE=	MIT

BUILD_DEPENDS=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-c++:${PORTSDIR}/lang/cloudabi-clang \
		${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc.a:${PORTSDIR}/devel/cloudabi-cloudlibc

USES=		tar:xz

SRCFILES=	algorithm bind chrono condition_variable debug exception \
		future hash ios iostream locale memory mutex new optional \
		random regex shared_mutex stdexcept string strstream \
		system_error thread typeinfo utility valarray

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-c++ \
		-g -O2 -nostdinc++ -std=c++11 -I${WRKSRC}/include \
		-I${WRKDIR}/libc++abi-${PORTVERSION}/include \
		-D_LIBCPP_BUILD_STATIC -DLIBCXX_BUILDING_LIBCXXABI \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/src/$f.cpp
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libc++.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/ \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/include/c++/
	${INSTALL_DATA} ${WRKSRC}/libc++.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	@${CP} -r ${WRKSRC}/include \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/include/c++/v1

.include <bsd.port.mk>
