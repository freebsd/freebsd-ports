# $FreeBSD$

PORTNAME=	micro
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Modern and intuitive terminal-based text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	zyedidia
GH_SUBDIR=	src/github.com/zyedidia/${PORTNAME}
GH_TUPLE=	\
		blang:semver:4a1e882:semver/src/github.com/blang/semver \
		gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
		go-errors:errors:8fa88b0:errors/src/github.com/go-errors/errors \
		golang:net:906cda9:net/src/golang.org/x/net \
		golang:text:0ad425f:text/src/golang.org/x/text \
		layeh:gopher-luar:ab3f305:luar/src/layeh.com/gopher-luar \
		lucasb-eyer:go-colorful:c900de9:colorful/src/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:dda3de4:isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:14207d2:runewidth/src/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:b8bc1bf:homedir/src/github.com/mitchellh/go-homedir \
		sergi:go-diff:24e2351:godiff/src/github.com/sergi/go-diff \
		yuin:gopher-lua:eed1c79:gopherlua/src/github.com/yuin/gopher-lua \
		zyedidia:clipboard:adacf41:clipboard/src/github.com/zyedidia/clipboard \
		zyedidia:glob:dd4023a:glob/src/github.com/zyedidia/glob \
		zyedidia:json5:2518f8b:json5/src/github.com/zyedidia/json5 \
		zyedidia:tcell:856dbb2:tcell/src/github.com/zyedidia/tcell

BUILD_HASH=	5dc8fe4
BUILD_DATE=	February 10, 2017

PLIST_FILES=	bin/micro
PORTDOCS=	README.md

do-build:
	@(cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC} go build -ldflags \
		"-s -w -X main.Version=${PORTVERSION} -X main.CommitHash=${BUILD_HASH} -X 'main.CompileDate=${BUILD_DATE}' " ./cmd/micro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
