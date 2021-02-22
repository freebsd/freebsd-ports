# $FreeBSD$

PORTNAME=	golangci-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	1.37.1
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Linters Runner for Go

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:S/-lint//}
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Djarvur:go-err113:5174e21577d5:djarvur_go_err113/vendor/github.com/Djarvur/go-err113 \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		OpenPeeDeeP:depguard:v1.0.1:openpeedeep_depguard/vendor/github.com/OpenPeeDeeP/depguard \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		alexkohler:prealloc:77a5b5dd9799:alexkohler_prealloc/vendor/github.com/alexkohler/prealloc \
		ashanbrown:forbidigo:v1.1.0:ashanbrown_forbidigo/vendor/github.com/ashanbrown/forbidigo \
		ashanbrown:makezero:7b7cdbb3025a:ashanbrown_makezero/vendor/github.com/ashanbrown/makezero \
		bkielbasa:cyclop:v1.2.0:bkielbasa_cyclop/vendor/github.com/bkielbasa/cyclop \
		bombsimon:wsl:v3.1.0:bombsimon_wsl_v3/vendor/github.com/bombsimon/wsl/v3 \
		charithe:durationcheck:v0.0.4:charithe_durationcheck/vendor/github.com/charithe/durationcheck \
		daixiang0:gci:v0.2.8:daixiang0_gci/vendor/github.com/daixiang0/gci \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denis-tingajkin:go-header:v0.4.2:denis_tingajkin_go_header/vendor/github.com/denis-tingajkin/go-header \
		dominikh:go-tools:v0.0.1-2020.1.6:dominikh_go_tools/vendor/honnef.co/go/tools \
		esimonov:ifshort:v1.0.1:esimonov_ifshort/vendor/github.com/esimonov/ifshort \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fzipp:gocyclo:v0.3.1:fzipp_gocyclo/vendor/github.com/fzipp/gocyclo \
		go-critic:go-critic:v0.5.4:go_critic_go_critic/vendor/github.com/go-critic/go-critic \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-toolsmith:astcast:v1.0.0:go_toolsmith_astcast/vendor/github.com/go-toolsmith/astcast \
		go-toolsmith:astcopy:v1.0.0:go_toolsmith_astcopy/vendor/github.com/go-toolsmith/astcopy \
		go-toolsmith:astequal:v1.0.0:go_toolsmith_astequal/vendor/github.com/go-toolsmith/astequal \
		go-toolsmith:astfmt:v1.0.0:go_toolsmith_astfmt/vendor/github.com/go-toolsmith/astfmt \
		go-toolsmith:astp:v1.0.0:go_toolsmith_astp/vendor/github.com/go-toolsmith/astp \
		go-toolsmith:strparse:v1.0.0:go_toolsmith_strparse/vendor/github.com/go-toolsmith/strparse \
		go-toolsmith:typep:v1.0.2:go_toolsmith_typep/vendor/github.com/go-toolsmith/typep \
		go-xmlfmt:xmlfmt:d5b6f63a941b:go_xmlfmt_xmlfmt/vendor/github.com/go-xmlfmt/xmlfmt \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:flock:v0.8.0:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:b64e53b001e4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		golangci:check:cfe4005ccda2:golangci_check/vendor/github.com/golangci/check \
		golangci:dupl:3e9179ac440a:golangci_dupl/vendor/github.com/golangci/dupl \
		golangci:errcheck:ef45e06d44b6:golangci_errcheck/vendor/github.com/golangci/errcheck \
		golangci:go-misc:927a3d87b613:golangci_go_misc/vendor/github.com/golangci/go-misc \
		golangci:gofmt:244bba706f1a:golangci_gofmt/vendor/github.com/golangci/gofmt \
		golangci:ineffassign:42439a7714cc:golangci_ineffassign/vendor/github.com/golangci/ineffassign \
		golangci:lint-1:297bf364a8e0:golangci_lint_1/vendor/github.com/golangci/lint-1 \
		golangci:maligned:b1d89398deca:golangci_maligned/vendor/github.com/golangci/maligned \
		golangci:misspell:950f5d19e770:golangci_misspell/vendor/github.com/golangci/misspell \
		golangci:revgrep:cd28932614b5:golangci_revgrep/vendor/github.com/golangci/revgrep \
		golangci:unconvert:28b1c447d1f4:golangci_unconvert/vendor/github.com/golangci/unconvert \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		gostaticanalysis:analysisutil:v0.4.1:gostaticanalysis_analysisutil/vendor/github.com/gostaticanalysis/analysisutil \
		gostaticanalysis:comment:v1.4.1:gostaticanalysis_comment/vendor/github.com/gostaticanalysis/comment \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jgautheron:goconst:ccae5bf973f3:jgautheron_goconst/vendor/github.com/jgautheron/goconst \
		jingyugao:rowserrcheck:c6a0c12dd98d:jingyugao_rowserrcheck/vendor/github.com/jingyugao/rowserrcheck \
		jirfag:go-printf-func-name:45db9963cdd3:jirfag_go_printf_func_name/vendor/github.com/jirfag/go-printf-func-name \
		kisielk:gotool:v1.0.0:kisielk_gotool/vendor/github.com/kisielk/gotool \
		kulti:thelper:v0.3.1:kulti_thelper/vendor/github.com/kulti/thelper \
		kunwardeep:paralleltest:v1.0.2:kunwardeep_paralleltest/vendor/github.com/kunwardeep/paralleltest \
		kyoh86:exportloopref:v0.1.8:kyoh86_exportloopref/vendor/github.com/kyoh86/exportloopref \
		leighmcculloch:gochecknoglobals:acfc0b28355a:leighmcculloch_gochecknoglobals/vendor/4d63.com/gochecknoglobals \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		maratori:testpackage:v1.0.1:maratori_testpackage/vendor/github.com/maratori/testpackage \
		matoous:godox:5d6d842e92eb:matoous_godox/vendor/github.com/matoous/godox \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mbilski:exhaustivestruct:v1.2.0:mbilski_exhaustivestruct/vendor/github.com/mbilski/exhaustivestruct \
		mgechev:dots:c36f7dcfbb81:mgechev_dots/vendor/github.com/mgechev/dots \
		mgechev:revive:v1.0.3:mgechev_revive/vendor/github.com/mgechev/revive \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:v1.0.0:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moricho:tparallel:v0.2.1:moricho_tparallel/vendor/github.com/moricho/tparallel \
		mvdan:gofumpt:v0.1.0:mvdan_gofumpt/vendor/mvdan.cc/gofumpt \
		mvdan:interfacer:c20040233aed:mvdan_interfacer/vendor/mvdan.cc/interfacer \
		mvdan:lint:adc824a0674b:mvdan_lint/vendor/mvdan.cc/lint \
		mvdan:unparam:b37ab49443f7:mvdan_unparam/vendor/mvdan.cc/unparam \
		nakabonne:nestif:v0.3.0:nakabonne_nestif/vendor/github.com/nakabonne/nestif \
		nbutton23:zxcvbn-go:e56b841a3c88:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		nishanths:exhaustive:v0.1.0:nishanths_exhaustive/vendor/github.com/nishanths/exhaustive \
		nishanths:predeclared:v0.2.1:nishanths_predeclared/vendor/github.com/nishanths/predeclared \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:checkstyle:bfd46e6a821d:phayes_checkstyle/vendor/github.com/phayes/checkstyle \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		polyfloyd:go-errorlint:19bd8db6546f:polyfloyd_go_errorlint/vendor/github.com/polyfloyd/go-errorlint \
		quasilyte:go-ruleguard:v0.3.0:quasilyte_go_ruleguard/vendor/github.com/quasilyte/go-ruleguard \
		quasilyte:regex:30656e2c4a95:quasilyte_regex_syntax/vendor/github.com/quasilyte/regex \
		ryancurrah:gomodguard:v1.2.0:ryancurrah_gomodguard/vendor/github.com/ryancurrah/gomodguard \
		ryanrolds:sqlclosecheck:v0.3.0:ryanrolds_sqlclosecheck/vendor/github.com/ryanrolds/sqlclosecheck \
		securego:gosec:v2.6.1:securego_gosec_v2/vendor/github.com/securego/gosec/v2 \
		shazow:go-diff:b6b7b6733b8c:shazow_go_diff/vendor/github.com/shazow/go-diff \
		shirou:gopsutil:e4ec7b275ada:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sonatard:noctx:v0.0.1:sonatard_noctx/vendor/github.com/sonatard/noctx \
		sourcegraph:go-diff:v0.6.1:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		ssgreg:nlreturn:v2.1.0:ssgreg_nlreturn_v2/vendor/github.com/ssgreg/nlreturn/v2 \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdakkota:asciicheck:d7f85be797a2:tdakkota_asciicheck/vendor/github.com/tdakkota/asciicheck \
		tetafro:godot:v1.4.4:tetafro_godot/vendor/github.com/tetafro/godot \
		timakin:bodyclose:f7f2e9bca95e:timakin_bodyclose/vendor/github.com/timakin/bodyclose \
		tomarrell:wrapcheck:df9e8bcb914d:tomarrell_wrapcheck/vendor/github.com/tomarrell/wrapcheck \
		tommy-muehle:go-mnd:v2.3.1:tommy_muehle_go_mnd_v2/vendor/github.com/tommy-muehle/go-mnd/v2 \
		ultraware:funlen:v0.0.3:ultraware_funlen/vendor/github.com/ultraware/funlen \
		ultraware:whitespace:v0.0.4:ultraware_whitespace/vendor/github.com/ultraware/whitespace \
		uudashr:gocognit:v1.0.1:uudashr_gocognit/vendor/github.com/uudashr/gocognit \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:quicktemplate:v1.6.3:valyala_quicktemplate/vendor/github.com/valyala/quicktemplate

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	b39dbcd
_BUILD_DATE=	$$(date -u "+%Y-%m-%dT%H:%M:%SZ")

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.commit=${_BUILD_COMMIT} \
		-X main.date=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME} \
		share/zsh/site_functions/_${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md
PORTEXAMPLES=	.golangci.example.yml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
.for SHELL in bash zsh
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_WRKDIR_BIN}/${PORTNAME} completion ${SHELL} > ${GO_WRKSRC}/${SHELL}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${GO_WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${INSTALL_DATA} ${GO_WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${GO_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${GO_WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
