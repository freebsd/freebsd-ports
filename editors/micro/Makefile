# $FreeBSD$

PORTNAME=	micro
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Modern and intuitive terminal-based text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	zyedidia
GH_SUBDIR=	src/github.com/zyedidia/${PORTNAME}
GH_TUPLE=	\
		blang:semver:4a1e882:semver/vendor/github.com/blang/semver \
		dustin:go-humanize:259d2a1:humanize/vendor/github.com/dustin/go-humanize \
		flynn:json5:7620272:json5/vendor/github.com/flynn/json5 \
		gdamore:encoding:b23993c:encoding/vendor/github.com/gdamore/encoding \
		go-errors:errors:8fa88b0:errors/vendor/github.com/go-errors/errors \
		jtolds:gls:77f1821:gls/vendor/github.com/jtolds/gls \
		lucasb-eyer:go-colorful:c900de9:colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:fc9e8d8:isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:97311d9:runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:b8bc1bf:homedir/vendor/github.com/mitchellh/go-homedir \
		sergi:go-diff:feef008:godiff/vendor/github.com/sergi/go-diff \
		smartystreets:assertions:0b37b35:assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:e5b2b7c:goconvey/vendor/github.com/smartystreets/goconvey \
		yuin:gopher-lua:b402f31:gopherlua/vendor/github.com/yuin/gopher-lua \
		zyedidia:clipboard:4611e80:clipboard/vendor/github.com/zyedidia/clipboard \
		zyedidia:glob:dd4023a:glob/vendor/github.com/zyedidia/glob \
		zyedidia:poller:ab09682:poller/vendor/github.com/zyedidia/poller \
		zyedidia:pty:3036466:pty/vendor/github.com/zyedidia/pty \
		zyedidia:tcell:208b6e8:tcell/vendor/github.com/zyedidia/tcell \
		zyedidia:terminal:1760577:terminal/vendor/github.com/zyedidia/terminal \
		golang:net:1a68b13:net/vendor/golang.org/x/net \
		golang:text:210eee5:text/vendor/golang.org/x/text \
		go-yaml:yaml:cd8b52f:yaml/vendor/gopkg.in/yaml.v2 \
		layeh:gopher-luar:1628157:luar/vendor/layeh.com/gopher-luar

GO_TARGET=	./cmd/micro
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${PORTVERSION} \
		-X main.CommitHash=${BUILD_HASH} \
		-X 'main.CompileDate=${BUILD_DATE}'"

BUILD_HASH=	1856891
BUILD_DATE=	August 9, 2018

PLIST_FILES=	bin/micro
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
