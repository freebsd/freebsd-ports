# $FreeBSD$

X_TARGET=	arm
X_TARGET_ARCH=	armv6

.include "${.CURDIR}/Makefile.shared"

.include <bsd.port.mk>

MAKE_ENV:=	${MAKE_ENV:N*FLAGS=*}
MAKE_ENV:=	${MAKE_ENV:NCC=*}
MAKE_ENV:=	${MAKE_ENV:NCPP=*}
MAKE_ENV:=	${MAKE_ENV:NCXX=*}
