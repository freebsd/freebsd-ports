# $FreeBSD$

PORTNAME=	git-bug
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	Distributed, offline-first bug tracker embedded in git, with bridges

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	MichaelMure
GH_TUPLE=	99designs:gqlgen:b7a58a1c0e4b:99designs_gqlgen/vendor/github.com/99designs/gqlgen \
		MichaelMure:go-term-text:v0.2.8:michaelmure_go_term_text/vendor/github.com/MichaelMure/go-term-text \
		agnivade:levenshtein:v1.0.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		araddon:dateparse:0fb0a474d195:araddon_dateparse/vendor/github.com/araddon/dateparse \
		awesome-gocui:gocui:a34ffb055986:awesome_gocui_gocui/vendor/github.com/awesome-gocui/gocui \
		awesome-gocui:termbox-go:c0aef3d18bcc:awesome_gocui_termbox_go/vendor/github.com/awesome-gocui/termbox-go \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		cheekybits:genny:9127e812e1e9:cheekybits_genny/vendor/github.com/cheekybits/genny \
		corpix:uarand:v0.1.1:corpix_uarand/vendor/github.com/corpix/uarand \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.3.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:oauth2:f42d05182288:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:b77594299b42:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		icrowley:fake:4178557ae428:icrowley_fake/vendor/github.com/icrowley/fake \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		phayes:freeport:b8543db493a5:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		shurcooL:githubv4:068505affed7:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:graphql:d48a9a75455f:shurcool_graphql/vendor/github.com/shurcooL/graphql \
		skratchdot:open-golang:79abb63cd66e:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		spf13:cobra:v0.0.6:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		vektah:gqlparser:v1.3.1:vektah_gqlparser/vendor/github.com/vektah/gqlparser \
		xanzy:go-gitlab:v0.29.0:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab

_BUILD_COMMIT=	2d64b85db71a17ff3277bbbf7ac9d8e81f8e416c
GO_BUILDFLAGS=	-ldflags "\
	       -s -w \
	       -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/commands.GitCommit=${_BUILD_COMMIT} \
	       -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/commands.GitLastTag=${DISTVERSION} \
	       -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/commands.GitExactTag=${DISTVERSION}"

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/bash_completion/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh_completion/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
