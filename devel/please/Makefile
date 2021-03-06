# $FreeBSD$

PORTNAME=	please
DISTVERSIONPREFIX=	v
DISTVERSION=	15.17.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	.build

MAINTAINER=	swills@FreeBSD.org
COMMENT=	High-performance extensible build system for reproducible builds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go \
		bash:shells/bash \
		ca_root_nss>0:security/ca_root_nss \
		git:devel/git \
		protoc:devel/protobuf

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	thought-machine
GH_TUPLE=	StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		Workiva:go-datastructures:v1.0.50:workiva_go_datastructures/vendor/github.com/Workiva/go-datastructures \
		alecthomas:gometalinter:v2.0.11:alecthomas_gometalinter/vendor/github.com/alecthomas/gometalinter \
		alecthomas:kingpin:95d230a53780:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v3-unstable \
		alecthomas:units:1786d5ef83d4:alecthomas_units/vendor/github.com/alecthomas/units \
		bazelbuild:buildtools:4bcdbd1064fc:bazelbuild_buildtools/vendor/github.com/bazelbuild/buildtools \
		bazelbuild:remote-apis-sdks:81a3a82fc300:bazelbuild_remote_apis_sdks/vendor/github.com/bazelbuild/remote-apis-sdks \
		bazelbuild:remote-apis:1aeb39973178:bazelbuild_remote_apis/vendor/github.com/bazelbuild/remote-apis \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		client9:misspell:v0.3.4:client9_misspell/vendor/github.com/client9/misspell \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		djherbis:atime:v1.0.0:djherbis_atime/vendor/github.com/djherbis/atime \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.0:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:lint:738671d3881b:golang_lint_1/vendor/golang.org/x/lint \
		golang:lint:c67002cb31c3:golang_lint/vendor/github.com/golang/lint \
		golang:net:62affa334b73:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d4d67f95c62d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:b303f430e36d:golang_tools/vendor/golang.org/x/tools \
		google:go-genproto:0bd0a958aa1d:google_go_genproto/vendor/google.golang.org/genproto \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:google-cloud-go:v0.65.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gordonklaus:ineffassign:1003c8bd00dc:gordonklaus_ineffassign/vendor/github.com/gordonklaus/ineffassign \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.31.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.7:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		karrick:godirwalk:v1.7.8:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		klauspost:compress:v1.10.11:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		lukechampine:blake3:v1.1.4:lukechampine_blake3/vendor/lukechampine.com/blake3 \
		lunixbochs:vtclean:2d01aacdc34a:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.3.2:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mostynb:go-grpc-compression:v1.1.2:mostynb_go_grpc_compression/vendor/github.com/mostynb/go-grpc-compression \
		nicksnyder:go-i18n:v1.10.1:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n \
		op:go-logging:b2cb9fa56473:op_go_logging/vendor/gopkg.in/op/go-logging.v1 \
		pborman:uuid:v1.2.1:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterebden:ar:a0ae3a11a518:peterebden_ar/vendor/github.com/peterebden/ar \
		peterebden:gcfg:v1.3.0:peterebden_gcfg/vendor/github.com/peterebden/gcfg \
		peterebden:go-cli-init:v3.0.0:peterebden_go_cli_init_v3/vendor/github.com/peterebden/go-cli-init/v3 \
		peterebden:go-sri:v1.0.0:peterebden_go_sri/vendor/github.com/peterebden/go-sri \
		peterebden:tools:b2a0db951d2a:peterebden_tools/vendor/github.com/peterebden/tools \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:xattr:v0.4.0:pkg_xattr/vendor/github.com/pkg/xattr \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		shirou:gopsutil:v2.18.12:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		sourcegraph:go-diff:v0.5.1:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		sourcegraph:go-lsp:0c7d621186c1:sourcegraph_go_lsp/vendor/github.com/sourcegraph/go-lsp \
		sourcegraph:jsonrpc2:35a74f039c6a:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		sqs:pbtypes:d3ebe8f20ae4:sqs_pbtypes/vendor/sourcegraph.com/sqs/pbtypes \
		streamrail:concurrent-map:8bf1e9bacbf6:streamrail_concurrent_map/vendor/github.com/streamrail/concurrent-map \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		texttheater:golang-levenshtein:d188e65d659e:texttheater_golang_levenshtein/vendor/github.com/texttheater/golang-levenshtein \
		thought-machine:go-flags:v1.5.0:thought_machine_go_flags/vendor/github.com/thought-machine/go-flags \
		tsenart:deadcode:210d2dc333e9:tsenart_deadcode/vendor/github.com/tsenart/deadcode \
		ulikunitz:xz:v0.5.6:ulikunitz_xz/vendor/github.com/ulikunitz/xz

GO_TARGET=	src/please.go:please \
		tools/build_langserver/langserver_main.go:build_langserver \
		tools/jarcat/main.go:jarcat \
		tools/please_go_filter/please_go_filter.go:please_go_filter \
		tools/please_go_install/please_go_install.go:please_go_install \
		tools/please_go_test/plz_go_test_main.go:please_go_test \
		tools/please_pex/pex_main.go:please_pex \
		tools/release_signer/main.go:release_signer

post-extract:
	${CP} ${WRKSRC}/tools/please_go_test/plz_go_test.go ${WRKSRC}/tools/please_go_test/plz_go_test_main.go

post-build:
	cd ${WRKSRC} ; ${SETENV} ${CC} ${CFLAGS} -o please_sandbox tools/sandbox/main.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/please_sandbox ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
