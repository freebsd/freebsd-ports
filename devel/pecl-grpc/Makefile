# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.25.0
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	High performance, general RPC framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_mips64=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_powerpc64=	fails to compile: cc1: error: unrecognized command line option "-Wno-parentheses-equality"

USES=		php:pecl

.include <bsd.port.pre.mk>

.if ${FLAVOR} == php72 && ${ARCH} == i386
BROKEN=		error: fastcall calling convention ignored on variadic function [-Werror,-Wignored-attributes]
.endif

.include <bsd.port.post.mk>
