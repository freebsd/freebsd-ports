PORTNAME=	gptscript
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	lang

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Natural Programming Language
WWW=		https://gptscript.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.22

USE_GITHUB=	yes
GH_ACCOUNT=	gptscript-ai
GH_TUPLE=	AlecAivazis:survey:v2.3.7:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		BurntSushi:locker:a6e239ea1c69:burntsushi_locker/vendor/github.com/BurntSushi/locker \
		acorn-io:baaah:2a58ee757bbd:acorn_io_baaah/vendor/github.com/acorn-io/baaah \
		acorn-io:broadcaster:bfadd4a7b45d:acorn_io_broadcaster/vendor/github.com/acorn-io/broadcaster \
		acorn-io:cmd:e9e631185ddb:acorn_io_cmd/vendor/github.com/acorn-io/cmd \
		adrg:xdg:v0.4.0:adrg_xdg/vendor/github.com/adrg/xdg \
		andybalholm:brotli:v1.0.4:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		bodgit:plumbing:v1.2.0:bodgit_plumbing/vendor/github.com/bodgit/plumbing \
		bodgit:sevenzip:v1.3.0:bodgit_sevenzip/vendor/github.com/bodgit/sevenzip \
		bodgit:windows:v1.0.0:bodgit_windows/vendor/github.com/bodgit/windows \
		bombsimon:logrusr:v4.0.0:bombsimon_logrusr_v4/vendor/github.com/bombsimon/logrusr/v4 \
		connesc:cipherio:v0.2.1:connesc_cipherio/vendor/github.com/connesc/cipherio \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		fatih:color:v1.16.0:fatih_color/vendor/github.com/fatih/color \
		getkin:kin-openapi:v0.123.0:getkin_kin_openapi/vendor/github.com/getkin/kin-openapi \
		go-logr:logr:v1.4.1:go_logr_logr/vendor/github.com/go-logr/logr \
		go-openapi:jsonpointer:v0.20.2:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:swag:v0.22.8:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go4org:go4:f5505b9728dd:go4org_go4/vendor/go4.org \
		golang:exp:be819d1f06fc:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.15.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.20.0:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.6.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.16.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.16.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.17.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-containerregistry:v0.16.1:google_go_containerregistry/vendor/github.com/google/go-containerregistry \
		google:pprof:e6195bd50e26:google_pprof/vendor/github.com/google/pprof \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gptscript-ai:go-openai:d33320ca826f:gptscript_ai_go_openai/vendor/github.com/sashabaranov/go-openai \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hexops:autogold:v2.1.0:hexops_autogold_v2/vendor/github.com/hexops/autogold/v2 \
		hexops:gotextdiff:v1.0.3:hexops_gotextdiff/vendor/github.com/hexops/gotextdiff \
		hexops:valast:v1.4.3:hexops_valast/vendor/github.com/hexops/valast \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		invopop:yaml:v0.2.0:invopop_yaml/vendor/github.com/invopop/yaml \
		jaytaylor:html2text:74c2419ad056:jaytaylor_html2text/vendor/github.com/jaytaylor/html2text \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.16.5:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kubernetes-sigs:controller-runtime:v0.16.3:kubernetes_sigs_controller_runtime/vendor/sigs.k8s.io/controller-runtime \
		kubernetes:klog:v2.110.1:kubernetes_klog/vendor/k8s.io/klog/v2 \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mholt:archiver:v4.0.0-alpha.8:mholt_archiver_v4/vendor/github.com/mholt/archiver/v4 \
		mohae:deepcopy:c48cc78d4826:mohae_deepcopy/vendor/github.com/mohae/deepcopy \
		mvdan:gofumpt:v0.6.0:mvdan_gofumpt/vendor/mvdan.cc/gofumpt \
		nightlyone:lockfile:v1.0.0:nightlyone_lockfile/vendor/github.com/nightlyone/lockfile \
		nwaples:rardecode:v2.0.0-beta.2:nwaples_rardecode_v2/vendor/github.com/nwaples/rardecode/v2 \
		olahol:melody:v1.1.4:olahol_melody/vendor/github.com/olahol/melody \
		olekukonko:tablewriter:df64c4bbad77:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		onsi:ginkgo:v2.13.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.29.0:onsi_gomega/vendor/github.com/onsi/gomega \
		perimeterx:marshmallow:v1.1.5:perimeterx_marshmallow/vendor/github.com/perimeterx/marshmallow \
		pierrec:lz4:v4.1.15:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:cors:v1.10.1:rs_cors/vendor/github.com/rs/cors \
		samber:lo:v1.38.1:samber_lo/vendor/github.com/samber/lo \
		samber:slog-logrus:v1.0.0:samber_slog_logrus/vendor/github.com/samber/slog-logrus \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		ssor:bom:6386211fdfcf:ssor_bom/vendor/github.com/ssor/bom \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify \
		therootcompany:xz:v1.0.1:therootcompany_xz/vendor/github.com/therootcompany/xz \
		tidwall:gjson:v1.17.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's/0.0.0-dev/${PORTVERSION}/1' \
		${WRKSRC}/pkg/version/version.go

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
