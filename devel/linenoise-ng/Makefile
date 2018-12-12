# Created by: David Thiel <lx@freebsd.org>
# $FreeBSD$

PORTNAME=	linenoise-ng
PORTVERSION=	1.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Small, portable readline replacement

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	arangodb
GH_PROJECT=	linenoise-ng

CFLAGS+=	-fPIC

.include <bsd.port.mk>
