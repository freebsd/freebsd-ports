# $FreeBSD$

PORTNAME=	micro
PORTVERSION=	1.4.0
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
		dustin:go-humanize:259d2a1:humanize/src/github.com/dustin/go-humanize \
		flynn:json5:7620272:json5/src/github.com/flynn/json5 \
		gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
		go-errors:errors:8fa88b0:errors/src/github.com/go-errors/errors \
		jtolds:gls:77f1821:gls/src/github.com/jtolds/gls \
		lucasb-eyer:go-colorful:c900de9:colorful/src/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:fc9e8d8:isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:97311d9:runewidth/src/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:b8bc1bf:homedir/src/github.com/mitchellh/go-homedir \
		sergi:go-diff:feef008:godiff/src/github.com/sergi/go-diff \
		smartystreets:assertions:0b37b35:assertions/src/github.com/smartystreets/assertions \
		smartystreets:goconvey:e5b2b7c:goconvey/src/github.com/smartystreets/goconvey \
		yuin:gopher-lua:b402f31:gopherlua/src/github.com/yuin/gopher-lua \
		zyedidia:clipboard:4611e80:clipboard/src/github.com/zyedidia/clipboard \
		zyedidia:glob:dd4023a:glob/src/github.com/zyedidia/glob \
		zyedidia:poller:ab09682:poller/src/github.com/zyedidia/poller \
		zyedidia:pty:3036466:pty/src/github.com/zyedidia/pty \
		zyedidia:tcell:208b6e8:tcell/src/github.com/zyedidia/tcell \
		zyedidia:terminal:1760577:terminal/src/github.com/zyedidia/terminal \
		golang:net:1a68b13:net/src/golang.org/x/net \
		golang:text:210eee5:text/src/golang.org/x/text \
		go-yaml:yaml:cd8b52f:yaml/src/gopkg.in/yaml.v2 \
		layeh:gopher-luar:1628157:luar/src/layeh.com/gopher-luar

BUILD_HASH=	af520cf
BUILD_DATE=	January 26, 2018

PLIST_FILES=	bin/micro
PORTDOCS=	README.md

do-build:
	@(cd ${WRKSRC} ; \
		${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} go build -ldflags \
		"-s -w -X main.Version=${PORTVERSION} -X main.CommitHash=${BUILD_HASH} -X 'main.CompileDate=${BUILD_DATE}' " ./cmd/micro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
