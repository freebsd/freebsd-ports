PORTNAME=	go-git
DISTVERSIONPREFIX=	v
DISTVERSION=	5.19.2
CATEGORIES=	devel

MAINTAINER=	gareev@aydar.me
COMMENT=	Highly extensible git library in pure Go
WWW=		https://github.com/go-git/go-git

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

USES=		cpe go:modules
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	go-git
GH_TUPLE=	Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.1.6:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		cloudflare:circl:v1.6.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.6.1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.9.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.19.1:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		golang:crypto:v0.53.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.56.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.46.0:golang_sys/vendor/golang.org/x/sys \
		imdario:mergo:v1.0.0:imdario_mergo/vendor/dario.cat/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jessevdk:go-flags:v1.6.1:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:cpuid:v2.3.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		pjbgf:sha1cd:v0.6.0:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		sergi:go-diff:5b0b94c5c0d3:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.3.1:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent
GO_TARGET=	.
GO_BUILDFLAGS=	-ldflags=" \
			-X main.version=${DISTVERSION} \
			-X main.build=FreeBSD"

WRKSRC_SUBDIR=	cli/go-git

PLIST_FILES=	bin/go-git

post-patch:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>
