# $FreeBSD$

PORTNAME=	cointop
PORTVERSION=	1.4.6
CATEGORIES=	finance

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Light cryptocurrency coin stats

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	miguelmota

GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		anaskhan96:soup:v1.1.1:anaskhan96_soup/vendor/github.com/anaskhan96/soup \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		golang:net:da137c7871d7:golang_net/vendor/golang.org/x/net \
		golang:sys:51ab0e2deafa:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		maruel:panicparse:f20d4c4d746f:maruel_panicparse/vendor/github.com/maruel/panicparse \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miguelmota:go-coinmarketcap:v0.1.5:miguelmota_go_coinmarketcap/vendor/github.com/miguelmota/go-coinmarketcap \
		miguelmota:gocui:v0.4.2:miguelmota_gocui/vendor/github.com/miguelmota/gocui \
		miguelmota:termbox-go:58d4fcbce2a7:miguelmota_termbox_go/vendor/github.com/miguelmota/termbox-go \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		tomnomnom:xtermcolor:b78803f00a7e:tomnomnom_xtermcolor/vendor/github.com/tomnomnom/xtermcolor

GO_BUILDFLAGS=	-ldflags="-X main.Version=${DISTVERSION}"

PLIST_FILES=	bin/cointop

.include <bsd.port.mk>
