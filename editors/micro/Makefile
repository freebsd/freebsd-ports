PORTNAME=	micro
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.10
PORTREVISION=	4
CATEGORIES=	editors

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Modern and intuitive terminal-based text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	zyedidia
GH_TUPLE=	blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		layeh:gopher-luar:v1.0.7:layeh_gopher_luar/vendor/layeh.com/gopher-luar \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xo:terminfo:454e5b68f9e8:xo_terminfo/vendor/github.com/xo/terminfo \
		yuin:gopher-lua:ab39c6098bdb:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua \
		zyedidia:clipboard:v1.0.3:zyedidia_clipboard/vendor/github.com/zyedidia/clipboard \
		zyedidia:glob:dd4023a66dc3:zyedidia_glob/vendor/github.com/zyedidia/glob \
		zyedidia:go-runewidth:v0.0.12:zyedidia_go_runewidth/vendor/github.com/mattn/go-runewidth \
		zyedidia:go-shellquote:eccd813c0655:zyedidia_go_shellquote/vendor/github.com/kballard/go-shellquote \
		zyedidia:highlight:201131ce5cf5:zyedidia_highlight/vendor/github.com/zyedidia/highlight \
		zyedidia:json5:2da050b1a98d:zyedidia_json5/vendor/github.com/zyedidia/json5 \
		zyedidia:poller:v1.0.1:zyedidia_poller/vendor/github.com/zyedidia/poller \
		zyedidia:pty:v1.1.15:zyedidia_pty/vendor/github.com/zyedidia/pty \
		zyedidia:tcell:v2.0.8:zyedidia_tcell_v2/vendor/github.com/zyedidia/tcell/v2 \
		zyedidia:terminal:533c623e2415:zyedidia_terminal/vendor/github.com/zyedidia/terminal

_BUILD_VERSION=	${DISTVERSION}
_BUILD_HASH=	b976385
_BUILD_DATE=	$$(date '+%B %d, %Y')
_BUILD_DEBUG=	OFF

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/util.Version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/util.CommitHash=${_BUILD_HASH} \
		-X 'github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/util.CompileDate=${_BUILD_DATE}' \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/util.Debug=${_BUILD_DEBUG}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_DESC=	Enable debug logging
DEBUG_VARS=	_BUILD_DEBUG=ON

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
