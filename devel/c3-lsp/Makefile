PORTNAME=	c3-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Language server for the C3 language
WWW=		https://github.com/pherrymason/c3-lsp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	pherrymason

GO_MOD_DIST=	github
GO_MODULE=	github.com/pherrymason/c3-lsp
GO_TARGET=	./cmd/lsp:c3lsp

WRKSRC_SUBDIR=	server

PLIST_FILES=	bin/c3lsp

.include <bsd.port.mk>
