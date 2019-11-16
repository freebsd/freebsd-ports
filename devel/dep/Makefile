# $FreeBSD$

PORTNAME=	dep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prototype dependency management tool for Go

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	golang

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/dep

PLIST_FILES=	bin/dep

.include <bsd.port.mk>
