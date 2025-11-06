PORTNAME=	zk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
PORTREVISION=	3
CATEGORIES=	deskutils

MAINTAINER=	pat@patmaddox.com
COMMENT=	Plain text note-taking assistant
WWW=		https://zk-org.github.io/zk/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	zk-org
GH_TUPLE=	AlecAivazis:survey:v2.3.4:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		alecthomas:kong:v0.5.0:alecthomas_kong/vendor/github.com/alecthomas/kong \
		aymerick:raymond:v2.0.2:aymerick_raymond/vendor/github.com/aymerick/raymond \
		bmatcuk:doublestar:v4.0.2:bmatcuk_doublestar_v4/vendor/github.com/bmatcuk/doublestar/v4 \
		djherbis:times:v1.3.0:djherbis_times/vendor/gopkg.in/djherbis/times.v1 \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-testfixtures:testfixtures:v3.6.1:go_testfixtures_testfixtures_v3/vendor/github.com/go-testfixtures/testfixtures/v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:v0.31.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.28.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.27.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.21.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosimple:slug:v1.12.0:gosimple_slug/vendor/github.com/gosimple/slug \
		gosimple:unidecode:v1.0.1:gosimple_unidecode/vendor/github.com/gosimple/unidecode \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lestrrat-go:strftime:v1.0.6:lestrrat_go_strftime/vendor/github.com/lestrrat-go/strftime \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.22:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mvdan:xurls:v1.1.0:mvdan_xurls/vendor/github.com/mvdan/xurls \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		petermattis:goid:07eaf5d0b9f4:petermattis_goid/vendor/github.com/petermattis/goid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		relvacode:iso8601:v1.1.0:relvacode_iso8601/vendor/github.com/relvacode/iso8601 \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.9.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rvflash:elapsed:v0.2.0:rvflash_elapsed/vendor/github.com/rvflash/elapsed \
		sasha-s:go-deadlock:v0.3.1:sasha_s_go_deadlock/vendor/github.com/sasha-s/go-deadlock \
		schollz:progressbar:v3.8.6:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		sourcegraph:jsonrpc2:v0.1.0:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		tj:go-naturaldate:v1.3.0:tj_go_naturaldate/vendor/github.com/tj/go-naturaldate \
		tliron:glsp:v0.1.1:tliron_glsp/vendor/github.com/tliron/glsp \
		tliron:kutil:v0.1.59:tliron_kutil/vendor/github.com/tliron/kutil \
		yuin:goldmark-meta:v1.1.0:yuin_goldmark_meta/vendor/github.com/yuin/goldmark-meta \
		yuin:goldmark:v1.4.12:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zchee:color:v2.0.6:zchee_color_v2/vendor/github.com/zchee/color/v2 \
		zk-org:pretty:v0.2.4:zk_org_pretty/vendor/github.com/zk-org/pretty

GO_BUILDFLAGS+=	-tags "fts5" -ldflags "-X=main.Version=${DISTVERSION}"
GO_TESTFLAGS+=	-tags "fts5"

PLIST_FILES=	bin/zk

.include <bsd.port.mk>
