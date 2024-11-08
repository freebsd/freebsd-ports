PORTNAME=	task
DISTVERSIONPREFIX=	v
DISTVERSION=	3.39.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Task runner / simpler Make alternative written in Go
WWW=		https://taskfile.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

USE_GITHUB=	yes
GH_ACCOUNT=	go-task
GH_TUPLE=	\
		Ladicle:tabwriter:v1.0.0:ladicle_tabwriter/vendor/github.com/Ladicle/tabwriter \
		Masterminds:semver:v3.3.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		alecthomas:chroma:v2.14.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dominikbraun:graph:v0.23.0:dominikbraun_graph/vendor/github.com/dominikbraun/graph \
		fatih:color:v1.17.0:fatih_color/vendor/github.com/fatih/color \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-task:template:v0.1.0:go_task_template/vendor/github.com/go-task/template \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.25.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.24.0:golang_term/vendor/golang.org/x/term \
		joho:godotenv:v1.5.1:joho_godotenv/vendor/github.com/joho/godotenv \
		klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-zglob:v0.0.6:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		mitchellh:hashstructure:v2.0.2:mitchellh_hashstructure_v2/vendor/github.com/mitchellh/hashstructure/v2 \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		mvdan:sh:v3.9.0:mvdan_sh/vendor/mvdan.cc/sh/v3 \
		otiai10:copy:v1.14.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		radovskyb:watcher:v1.0.7:radovskyb_watcher/vendor/github.com/radovskyb/watcher \
		sajari:fuzzy:v1.0.0:sajari_fuzzy/vendor/github.com/sajari/fuzzy \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		zeebo:xxh3:v1.0.2:zeebo_xxh3/vendor/github.com/zeebo/xxh3

GO_TARGET=	./cmd/task

PLIST_FILES=	bin/task
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
