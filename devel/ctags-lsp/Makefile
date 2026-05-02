PORTNAME=	ctags-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	LSP using universal-ctags as a backend
WWW=		https://github.com/netmute/ctags-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	uctags:devel/universal-ctags

USES=		go:modules
GO_MODULE=	github.com/netmute/ctags-lsp

PLIST_FILES=	bin/ctags-lsp

.include <bsd.port.mk>
