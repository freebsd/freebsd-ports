# Created by: gnn
# $FreeBSD$

PORTNAME=	smhasher
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Hash Algorithm Benchmarking

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	gvnn3
GH_PROJECT=	smhasher
DISTVERSIONPREFIX=	v

USES=		cmake

PLIST_FILES=	bin/SMHasher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SMHasher ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
