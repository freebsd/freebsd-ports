# $FreeBSD$

CATEGORIES=	devel www
PKGNAMESUFFIX=	-gn

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Gn meta build framework

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

MASTERDIR=	${.CURDIR}/../../www/chromium

BROKEN_FreeBSD_11_powerpc64=	fails to compile: safe_math_clang_gcc_impl.h:132:45: '__builtin_subcb' was not declared in this scope
BROKEN_FreeBSD_12_powerpc64=	fails to compile: safe_math_clang_gcc_impl.h:132:45: '__builtin_subcb' was not declared in this scope

BUILDTYPE=	Release
NO_BUILD=	yes

PLIST=	${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message
DESCR=	${.CURDIR}/pkg-descr
PLIST_FILES=	bin/gn

GN_ONLY=	yes

post-extract:
	@${CP} ${WRKSRC}/base/numerics/safe_math_arm_impl.h ${WRKSRC}/tools/gn/base/numerics
	@${CP} ${WRKSRC}/base/numerics/safe_conversions_arm_impl.h ${WRKSRC}/tools/gn/base/numerics

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/gn ${STAGEDIR}${PREFIX}/bin

.include "${MASTERDIR}/Makefile"
