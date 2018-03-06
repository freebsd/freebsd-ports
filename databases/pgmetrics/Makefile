# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgmetrics
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect and display info & stats from a running PostgreSQL server

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	rapidloop

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

BUILD_AS_NON_ROOT=yes

do-build:
	@cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ./cmd/pgmetrics

do-install:
	@cd ${GO_WRKSRC}; ${INSTALL} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
