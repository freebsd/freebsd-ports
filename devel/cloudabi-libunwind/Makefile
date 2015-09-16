# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libunwind
CATEGORIES=	devel
DISTFILES=	libcxxabi-${DISTVERSION}.src${EXTRACT_SUFX} \
		libunwind-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C++ exception handling for CloudABI

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc++.a:${PORTSDIR}/devel/cloudabi-libc++

PLIST_FILES=	x86_64-unknown-cloudabi/lib/libunwind.a

SRCFILES=	Unwind-EHABI.cpp Unwind-sjlj.c UnwindLevel1-gcc-ext.c \
		UnwindLevel1.c UnwindRegistersRestore.S UnwindRegistersSave.S \
		libunwind.cpp

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-c++ \
		-O2 -std=c++11 -I${WRKSRC}/include \
		-I${WRKDIR}/libcxxabi-${DISTVERSION}.src/include \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/src/$f
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libunwind.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	${INSTALL_DATA} ${WRKSRC}/libunwind.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/

.include "${.CURDIR}/../cloudabi-libc++/Makefile.common"

.include <bsd.port.mk>
