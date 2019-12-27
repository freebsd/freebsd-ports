# $FreeBSD$

PORTNAME=	dep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	devel

# https://github.com/golang/dep/pull/2228
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	6d3cf343515fe34645284b75819bed3de5ea930e.patch:-p1

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Prototype dependency management tool for Go

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	golang

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/dep

PLIST_FILES=	bin/dep

.include <bsd.port.mk>
