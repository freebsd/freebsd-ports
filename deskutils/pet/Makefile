PORTNAME=	pet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	4
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
		alessio:shellescape:52074bc9df61:alessio_shellescape_1/vendor/gopkg.in/alessio/shellescape.v1 \
		alessio:shellescape:v1.4.1:alessio_shellescape/vendor/github.com/alessio/shellescape \
		briandowns:spinner:48dbb65d7bd5:briandowns_spinner/vendor/github.com/briandowns/spinner \
		chzyer:logex:v1.1.10:chzyer_logex/vendor/github.com/chzyer/logex \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		chzyer:test:061457976a23:chzyer_test/vendor/github.com/chzyer/test \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		golang:appengine:v1.3.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:f5854403a974:golang_net/vendor/golang.org/x/net \
		golang:oauth2:f42d05182288:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:0a5406a5449c:golang_sys/vendor/golang.org/x/sys \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:go-github:v15.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.8:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:21a4d435a862:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:go-gitlab:v0.50.3:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
