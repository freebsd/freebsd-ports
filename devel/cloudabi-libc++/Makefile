# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++
CATEGORIES=	devel
DISTNAME=	libcxx-${DISTVERSION}.src
DISTFILES=	libcxx-${DISTVERSION}.src${EXTRACT_SUFX} \
		libcxxabi-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C++ standard template library for CloudABI

LICENSE=	MIT

SRCFILES=	algorithm bind chrono condition_variable debug exception \
		future hash ios iostream locale memory mutex new optional \
		random regex shared_mutex stdexcept string strstream \
		system_error thread typeinfo utility valarray

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-c++ \
		-g -O2 -nostdinc++ -std=c++11 -I${WRKSRC}/include \
		-I${WRKDIR}/libcxxabi-${DISTVERSION}.src/include \
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

.include "${.CURDIR}/Makefile.common"

.include <bsd.port.mk>
