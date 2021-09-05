PORTNAME=	gitleaks
DISTVERSIONPREFIX=	v
DISTVERSION=	7.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for detecting hardcoded secrets in git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	zricethezav
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:04723f9f07d7:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		golang:crypto:83a5a9bb288b:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:6b1517762897:golang_net/vendor/golang.org/x/net \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:71e4cd670f79:golang_sys/vendor/golang.org/x/sys \
		hako:durafmt:3f39dc1ed9f4:hako_durafmt/vendor/github.com/hako/durafmt \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kevinburke:ssh_config:4977a11b4351:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		zricethezav:go-git:v5.3.0:zricethezav_go_git_v5/vendor/github.com/go-git/go-git/v5
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
