# Created by: gnn
# $FreeBSD$

PORTNAME=	smhasher
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	benchmarks

PATCH_SITES=	https://github.com/gvnn3/${PORTNAME}/commit/
PATCHFILES=	8d752bd051d43772b92019a65afe3ab6dcbf4b7a.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hash Algorithm Benchmarking

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	gvnn3

USES=		cmake:insource

PLIST_FILES=	bin/SMHasher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SMHasher ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
