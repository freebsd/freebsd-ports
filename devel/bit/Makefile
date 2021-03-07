# $FreeBSD$

PORTNAME=	bit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Bit is a modern Git CLI

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	chriswalz
GH_TUPLE=	\
		AlecAivazis:survey:v2.2.2:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		bradfitz:iter:e8f45d346db8:bradfitz_iter/vendor/github.com/bradfitz/iter \
		c-bata:go-prompt:v0.2.5:c_bata_go_prompt/vendor/github.com/c-bata/go-prompt \
		c4milo:unpackit:4ed373e9ef1c:c4milo_unpackit/vendor/github.com/c4milo/unpackit \
		chriswalz:complete:v3.0.13:chriswalz_complete_v3/vendor/github.com/chriswalz/complete/v3 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:f99c8df09eb5:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:af09f7315aff:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-github:v32.1.0:google_go_github_v32/vendor/github.com/google/go-github/v32 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:v0.0.1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hooklift:assert:v0.1.0:hooklift_assert/vendor/github.com/hooklift/assert \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.4.1:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.0:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		lithammer:fuzzysearch:v1.1.1:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:v0.0.3:mattn_go_tty/vendor/github.com/mattn/go-tty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:v1.1.0:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:script:v1.1.5:posener_script/vendor/github.com/posener/script \
		rs:zerolog:v1.20.0:rs_zerolog/vendor/github.com/rs/zerolog \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		thoas:go-funk:v0.7.0:thoas_go_funk/vendor/github.com/thoas/go-funk \
		tj:go-update:v2.2.4:tj_go_update/vendor/github.com/tj/go-update \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz

GO_TARGET=	.
PLIST_FILES=	bin/bit
SUB_FILES=	pkg-message

.include <bsd.port.mk>
