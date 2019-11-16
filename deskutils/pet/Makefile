# $FreeBSD$

PORTNAME=	pet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple command-line snippet manager, written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	knqyf263
GH_TUPLE=	\
		BurntSushi:toml:v0.3.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		briandowns:spinner:48dbb65d7bd5:briandowns_spinner/vendor/github.com/briandowns/spinner \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		golang:appengine:v1.0.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:8ac0e0d97ce4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:1e491301e022:golang_net/vendor/golang.org/x/net \
		golang:oauth2:1e0a3fa8ba9a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.1.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:9527bec2660b:golang_sys/vendor/golang.org/x/sys \
		google:go-github:v15.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:53e6ce116135:google_go_querystring/vendor/github.com/google/go-querystring \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:21a4d435a862:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:go-gitlab:v0.10.5:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
