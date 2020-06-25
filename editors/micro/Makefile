# $FreeBSD$

PORTNAME=	micro
PORTVERSION=	2.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Modern and intuitive terminal-based text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	zyedidia
GH_TUPLE=	\
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		layeh:gopher-luar:v1.0.7:layeh_gopher_luar/vendor/layeh.com/gopher-luar \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		yuin:gopher-lua:ab39c6098bdb:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua \
		zyedidia:clipboard:7c45b8673834:zyedidia_clipboard/vendor/github.com/zyedidia/clipboard \
		zyedidia:glob:dd4023a66dc3:zyedidia_glob/vendor/github.com/zyedidia/glob \
		zyedidia:highlight:201131ce5cf5:zyedidia_highlight/vendor/github.com/zyedidia/highlight \
		zyedidia:json5:2da050b1a98d:zyedidia_json5/vendor/github.com/zyedidia/json5 \
		zyedidia:poller:v1.0.1:zyedidia_poller/vendor/github.com/zyedidia/poller \
		zyedidia:pty:v2.0.0:zyedidia_pty/vendor/github.com/zyedidia/pty \
		zyedidia:tcell:v1.4.5:zyedidia_tcell/vendor/github.com/zyedidia/tcell \
		zyedidia:terminal:533c623e2415:zyedidia_terminal/vendor/github.com/zyedidia/terminal

GO_TARGET=	./cmd/micro
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/zyedidia/micro/v2/internal/util.Version=${PORTVERSION} \
		-X github.com/zyedidia/micro/v2/internal/util.CommitHash=${BUILD_HASH} \
		-X 'github.com/zyedidia/micro/v2/internal/util.CompileDate=${BUILD_DATE}'"

BUILD_HASH=	c5b0c2d
BUILD_DATE=	May 23, 2020

PLIST_FILES=	bin/micro
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
