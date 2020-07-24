# $FreeBSD$

PORTNAME=	golangci-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	1.29.0
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
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
		bombsimon:wsl:v3.1.0:bombsimon_wsl_v3/vendor/github.com/bombsimon/wsl/v3 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denis-tingajkin:go-header:v0.3.1:denis_tingajkin_go_header/vendor/github.com/denis-tingajkin/go-header \
		dominikh:go-tools:v0.0.1-2020.1.4:dominikh_go_tools/vendor/honnef.co/go/tools \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-critic:go-critic:v0.5.0:go_critic_go_critic/vendor/github.com/go-critic/go-critic \
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
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:flock:v0.7.1:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:f1c4188a97a1:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		golangci:check:cfe4005ccda2:golangci_check/vendor/github.com/golangci/check \
		golangci:dupl:3e9179ac440a:golangci_dupl/vendor/github.com/golangci/dupl \
		golangci:errcheck:ef45e06d44b6:golangci_errcheck/vendor/github.com/golangci/errcheck \
		golangci:go-misc:927a3d87b613:golangci_go_misc/vendor/github.com/golangci/go-misc \
		golangci:goconst:041c5f2b40f3:golangci_goconst/vendor/github.com/golangci/goconst \
		golangci:gocyclo:0a533e8fa43d:golangci_gocyclo/vendor/github.com/golangci/gocyclo \
		golangci:gofmt:244bba706f1a:golangci_gofmt/vendor/github.com/golangci/gofmt \
		golangci:ineffassign:42439a7714cc:golangci_ineffassign/vendor/github.com/golangci/ineffassign \
		golangci:lint-1:297bf364a8e0:golangci_lint_1/vendor/github.com/golangci/lint-1 \
		golangci:maligned:b1d89398deca:golangci_maligned/vendor/github.com/golangci/maligned \
		golangci:misspell:950f5d19e770:golangci_misspell/vendor/github.com/golangci/misspell \
		golangci:prealloc:215b22d4de21:golangci_prealloc/vendor/github.com/golangci/prealloc \
		golangci:revgrep:d9c87f5ffaf0:golangci_revgrep/vendor/github.com/golangci/revgrep \
		golangci:unconvert:28b1c447d1f4:golangci_unconvert/vendor/github.com/golangci/unconvert \
		google:go-cmp:v0.5.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gostaticanalysis:analysisutil:v0.0.3:gostaticanalysis_analysisutil/vendor/github.com/gostaticanalysis/analysisutil \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jingyugao:rowserrcheck:72ab7603b68a:jingyugao_rowserrcheck/vendor/github.com/jingyugao/rowserrcheck \
		jirfag:go-printf-func-name:45db9963cdd3:jirfag_go_printf_func_name/vendor/github.com/jirfag/go-printf-func-name \
		kisielk:gotool:v1.0.0:kisielk_gotool/vendor/github.com/kisielk/gotool \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kyoh86:exportloopref:v0.1.7:kyoh86_exportloopref/vendor/github.com/kyoh86/exportloopref \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		maratori:testpackage:v1.0.1:maratori_testpackage/vendor/github.com/maratori/testpackage \
		matoous:godox:5d6d842e92eb:matoous_godox/vendor/github.com/matoous/godox \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:v1.0.0:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mvdan:gofumpt:4fd085cb6d5f:mvdan_gofumpt/vendor/mvdan.cc/gofumpt \
		mvdan:interfacer:c20040233aed:mvdan_interfacer/vendor/mvdan.cc/interfacer \
		mvdan:lint:adc824a0674b:mvdan_lint/vendor/mvdan.cc/lint \
		mvdan:unparam:d51796306d8f:mvdan_unparam/vendor/mvdan.cc/unparam \
		nakabonne:nestif:v0.3.0:nakabonne_nestif/vendor/github.com/nakabonne/nestif \
		nbutton23:zxcvbn-go:ae427f1e4c1d:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		nishanths:exhaustive:8866003e3856:nishanths_exhaustive/vendor/github.com/nishanths/exhaustive \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:checkstyle:bfd46e6a821d:phayes_checkstyle/vendor/github.com/phayes/checkstyle \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		quasilyte:go-ruleguard:b00d7a75d3d8:quasilyte_go_ruleguard/vendor/github.com/quasilyte/go-ruleguard \
		quasilyte:regex:30656e2c4a95:quasilyte_regex_syntax/vendor/github.com/quasilyte/regex \
		ryancurrah:gomodguard:v1.1.0:ryancurrah_gomodguard/vendor/github.com/ryancurrah/gomodguard \
		ryanrolds:sqlclosecheck:v0.3.0:ryanrolds_sqlclosecheck/vendor/github.com/ryanrolds/sqlclosecheck \
		securego:gosec:v2.3.0:securego_gosec_v2/vendor/github.com/securego/gosec/v2 \
		shazow:go-diff:b6b7b6733b8c:shazow_go_diff/vendor/github.com/shazow/go-diff \
		shirou:gopsutil:e4ec7b275ada:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sonatard:noctx:v0.0.1:sonatard_noctx/vendor/github.com/sonatard/noctx \
		sourcegraph:go-diff:v0.5.3:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		sqs:pbtypes:d3ebe8f20ae4:sqs_pbtypes/vendor/sourcegraph.com/sqs/pbtypes \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdakkota:asciicheck:d7f85be797a2:tdakkota_asciicheck/vendor/github.com/tdakkota/asciicheck \
		tetafro:godot:v0.4.2:tetafro_godot/vendor/github.com/tetafro/godot \
		timakin:bodyclose:f7f2e9bca95e:timakin_bodyclose/vendor/github.com/timakin/bodyclose \
		tommy-muehle:go-mnd:e6f9a994e8fa:tommy_muehle_go_mnd/vendor/github.com/tommy-muehle/go-mnd \
		ultraware:funlen:v0.0.2:ultraware_funlen/vendor/github.com/ultraware/funlen \
		ultraware:whitespace:v0.0.4:ultraware_whitespace/vendor/github.com/ultraware/whitespace \
		uudashr:gocognit:v1.0.1:uudashr_gocognit/vendor/github.com/uudashr/gocognit \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:quicktemplate:v1.5.1:valyala_quicktemplate/vendor/github.com/valyala/quicktemplate

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	6a68907
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
