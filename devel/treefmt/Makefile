PORTNAME=	treefmt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	One CLI to format the code tree
WWW=		https://treefmt.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

USE_GITHUB=	yes
GH_ACCOUNT=	numtide
GH_TUPLE=	\
		BurntSushi:toml:v1.3.2:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.0.0:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		adrg:xdg:v0.4.0:adrg_xdg/vendor/github.com/adrg/xdg \
		alecthomas:kong:v0.9.0:alecthomas_kong/vendor/github.com/alecthomas/kong \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:lipgloss:v0.10.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:log:v0.4.0:charmbracelet_log/vendor/github.com/charmbracelet/log \
		cloudflare:circl:v1.3.8:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.2.5:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		etcd-io:bbolt:v1.3.10:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.5.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:cd6633c3c665:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-logfmt:logfmt:v0.6.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:crypto:v0.23.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9bf2ced13842:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.25.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.20.0:golang_sys/vendor/golang.org/x/sys \
		imdario:mergo:v1.0.0:imdario_mergo/vendor/dario.cat/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		otiai10:copy:v1.14.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pjbgf:sha1cd:v0.3.0:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sergi:go-diff:5b0b94c5c0d3:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.2.2:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		vmihailenco:msgpack:v5.4.1:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
