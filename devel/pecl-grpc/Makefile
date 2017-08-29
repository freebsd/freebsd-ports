# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.4.6
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	High performance, general RPC framework

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_mips=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_mips64=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_powerpc64=	fails to compile: cc1: error: unrecognized command line option "-Wno-parentheses-equality"

USES=		php:pecl

.include <bsd.port.mk>
