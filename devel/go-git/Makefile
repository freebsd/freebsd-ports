PORTNAME=	go-git
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.2
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Highly extensible git library in pure Go
WWW=		https://github.com/go-git/go-git

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
#GO_MODULE=	github.com/go-git/go-git/v5 # Fails to build, see https://github.com/go-git/go-git/issues/626
USE_GITHUB=	yes
GH_TUPLE=	Microsoft:go-winio:v0.5.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:cf6655e29de4:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		cloudflare:circl:v1.1.0:cloudflare_circl/vendor/github.com/cloudflare/circl \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		gliderlabs:ssh:v0.3.5:gliderlabs_ssh/vendor/github.com/gliderlabs/ssh \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.4.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git-fixtures:v4.3.1:go_git_go_git_fixtures_v4/vendor/github.com/go-git/go-git-fixtures/v4 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		golang:crypto:v0.3.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.2.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.3.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		imdario:mergo:v0.3.13:imdario_mergo/vendor/github.com/imdario/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		pjbgf:sha1cd:v0.2.3:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.1.0:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent
GO_TARGET=	./cli/go-git
GO_BUILDFLAGS=	-ldflags=" \
			-X main.version=${DISTVERSION} \
			-X main.build=FreeBSD"

PLIST_FILES=	bin/go-git

.include <bsd.port.mk>
