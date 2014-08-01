# $FreeBSD$

X_TARGET=	arm
X_TARGET_ARCH=	armv6

.include "${.CURDIR}/Makefile.shared"

.include <bsd.port.options.mk>

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=Used on i386/amd64 to cross compile arm

.if ${OPSYS} != FreeBSD
IGNORE=	Only supported on FreeBSD
.endif

.if ${OSVERSION} < 1000510
IGNORE=	Only supported on FreeBSD 10+
.endif

.include <bsd.port.mk>

MAKE_ENV:=	${MAKE_ENV:N*FLAGS=*}
MAKE_ENV:=	${MAKE_ENV:NCC=*}
MAKE_ENV:=	${MAKE_ENV:NCPP=*}
MAKE_ENV:=	${MAKE_ENV:NCXX=*}
