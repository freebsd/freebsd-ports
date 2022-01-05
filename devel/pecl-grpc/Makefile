# Created by: vanilla@

PORTNAME=	grpc
PORTVERSION=	1.42.0
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	High performance, general RPC framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: fatal error: sys/auxv.h file not found
BROKEN_mips64=		fails to compile: fatal error: sys/auxv.h file not found

USES=		compiler:c++11-lang php:pecl

.include <bsd.port.mk>
