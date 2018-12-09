# $FreeBSD$

PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format shell scripts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.10:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mvdan
GH_PROJECT=	sh
GH_SUBDIR=	src/mvdan.cc/sh

MAKE_ENV=	GOPATH=${WRKSRC}
PLIST_FILES=	bin/shfmt

do-build:
	@cd ${WRKSRC}/cmd/shfmt && ${SETENV} ${MAKE_ENV} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/shfmt/shfmt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
