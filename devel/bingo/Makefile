# $FreeBSD$

PORTNAME=	bingo
DISTVERSION=	1.1.0-295
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Go language server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2019-10-15

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	saibing
GH_TAGNAME=	76bcd777316dde1684ff59793f695e4337c0e62a
GH_TUPLE=	davecgh:go-spew:v1.1.1:go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsevents:v0.1.1:fsevents/vendor/github.com/fsnotify/fsevents \
		fsnotify:fsnotify:v1.4.7:fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-stack:stack:v1.8.0:stack/vendor/github.com/go-stack/stack \
		golang:crypto:b7391e95e576:crypto/vendor/golang.org/x/crypto \
		golang:net:addf6b3196f6:net/vendor/golang.org/x/net \
		golang:sys:f49334f85ddc:sys/vendor/golang.org/x/sys \
		golang:tools:e65039ee4138:tools/vendor/golang.org/x/tools \
		gorilla:websocket:v1.4.0:websocket/vendor/github.com/gorilla/websocket \
		inconshreveable:log15:67afb5ed74ec:log15/vendor/gopkg.in/inconshreveable/log15.v2 \
		mattn:go-colorable:v0.1.1:go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:go_isatty/vendor/github.com/mattn/go-isatty \
		slimsag:godocmd:a1005ad29fe3:godocmd/vendor/github.com/slimsag/godocmd \
		sourcegraph:go-lsp:0c7d621186c1:go_lsp/vendor/github.com/sourcegraph/go-lsp \
		sourcegraph:jsonrpc2:549eb959f029:jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		stretchr:objx:v0.1.1:objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.3.0:testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/bingo

.include <bsd.port.mk>
