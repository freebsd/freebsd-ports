# $FreeBSD$

PORTNAME=	delve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	devel

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Debugger for the Go programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	go-delve

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/dlv

CONFLICTS_INSTALL=	dlv # bin/dlv

PLIST_FILES=	bin/dlv

.include <bsd.port.mk>
