# Created by: David Thiel <lx@freebsd.org>
# $FreeBSD$

PORTNAME=	linenoise-ng
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Small, portable readline replacement

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: cc1plus: unrecognized command line option "-std=c++11"
BROKEN_mips64=		fails to compile: cc1plus: unrecognized command line option "-std=c++11"
BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	arangodb
GH_PROJECT=	linenoise-ng

CFLAGS+=	-fPIC

.include <bsd.port.mk>
