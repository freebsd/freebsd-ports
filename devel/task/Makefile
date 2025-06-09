PORTNAME=	task
DISTVERSIONPREFIX=	v
DISTVERSION=	3.44.0
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Task runner / simpler Make alternative written in Go
WWW=		https://taskfile.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

USE_GITHUB=	yes
GH_ACCOUNT=	go-task
GH_TUPLE=	\
		Ladicle:tabwriter:v1.0.0:ladicle_tabwriter/vendor/github.com/Ladicle/tabwriter \
		Masterminds:semver:v3.3.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.1.6:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		alecthomas:chroma:v2.18.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		chainguard-dev:git-urls:v1.0.2:chainguard_dev_git_urls/vendor/github.com/chainguard-dev/git-urls \
		cloudflare:circl:v1.6.1:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.4.1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.11.5:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dominikbraun:graph:v0.23.0:dominikbraun_graph/vendor/github.com/dominikbraun/graph \
		elliotchance:orderedmap:v3.1.0:elliotchance_orderedmap_v3/vendor/github.com/elliotchance/orderedmap \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		fatih:color:v1.18.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.6.2:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.16.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-task:template:v0.1.0:go_task_template/vendor/github.com/go-task/template \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.37.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.39.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.14.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.32.0:golang_term/vendor/golang.org/x/term \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		imdario:mergo:v1.0.0:imdario_mergo/vendor/dario.cat/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		joho:godotenv:v1.5.1:joho_godotenv/vendor/github.com/joho/godotenv \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:cpuid:v2.2.7:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:hashstructure:v2.0.2:mitchellh_hashstructure_v2/vendor/github.com/mitchellh/hashstructure/v2 \
		mvdan:sh:v3.11.0:mvdan_sh/vendor/mvdan.cc/sh/v3 \
		otiai10:copy:v1.14.1:otiai10_copy/vendor/github.com/otiai10/copy \
		otiai10:mint:v1.6.3:otiai10_mint/vendor/github.com/otiai10/mint \
		pjbgf:sha1cd:v0.3.2:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		puzpuzpuz:xsync:v3.5.1:puzpuzpuz_xsync_v3/vendor/github.com/puzpuzpuz/xsync/v3 \
		sajari:fuzzy:v1.0.0:sajari_fuzzy/vendor/github.com/sajari/fuzzy \
		sebdah:goldie:v2.5.5:sebdah_goldie_v2/vendor/github.com/sebdah/goldie \
		sergi:go-diff:5b0b94c5c0d3:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.3.1:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		zeebo:xxh3:v1.0.2:zeebo_xxh3/vendor/github.com/zeebo/xxh3

GO_TARGET=	./cmd/task

PLIST_FILES=	bin/task
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# target for port maintainer
generate-modules-txt: extract
	@${RM} ${WRKSRC}/vendor/modules.txt
	@${MAKE} gomod-vendor
	@${CP} ${WRKSRC}/vendor/modules.txt ${FILESDIR}

.include <bsd.port.mk>
