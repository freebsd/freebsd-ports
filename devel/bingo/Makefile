# $FreeBSD$

PORTNAME=	bingo
DISTVERSION=	1.1.0-241
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Go language server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.11,1:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	saibing
GH_TAGNAME=	ea0a232011dae8376468035f1e3ebc46d23bc9c0

# generated with gomod-deps below
GH_TUPLE=	fsnotify:fsevents:v0.1.1:fsevents/vendor/github.com/fsnotify/fsevents \
		fsnotify:fsnotify:v1.4.7:fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-stack:stack:v1.8.0:stack/vendor/github.com/go-stack/stack \
		golang:sys:cd391775e71e:sys/vendor/golang.org/x/sys \
		golang:tools:97f80cd5504d:tools/vendor/golang.org/x/tools \
		gorilla:websocket:v1.4.0:websocket/vendor/github.com/gorilla/websocket \
		inconshreveable:log15:67afb5ed74ec:log15/vendor/gopkg.in/inconshreveable/log15.v2 \
		mattn:go-colorable:v0.1.1:go_colorable/vendor/github.com/mattn/go-colorable \
		slimsag:godocmd:a1005ad29fe3:godocmd/vendor/github.com/slimsag/godocmd \
		sourcegraph:go-lsp:0c7d621186c1:go_lsp/vendor/github.com/sourcegraph/go-lsp \
		sourcegraph:jsonrpc2:549eb959f029:jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		stretchr:testify:v1.3.0:testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/bingo

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -mod=vendor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bingo ${STAGEDIR}${PREFIX}/bin

# XXX: Check if useful for other ports and maybe put it in a USES=gomod
gomod-deps: patch
	@${AWK} -f ${FILESDIR}/gomod.awk ${WRKSRC}/go.mod

.include <bsd.port.mk>
