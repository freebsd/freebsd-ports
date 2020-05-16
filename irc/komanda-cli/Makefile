# $FreeBSD$

PORTNAME=	komanda-cli
DISTVERSION=	g20190920
CATEGORIES=	irc

MAINTAINER=	vulcan@wired.sh
COMMENT=	Komanda command-line IRC client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mephux
GH_TAGNAME=	b5ba03b
GH_TUPLE=	0xAX:notificator:d81462e38c21:0xax_notificator/vendor/github.com/0xAX/notificator \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fluffle:goirc:v1.0.1:fluffle_goirc/vendor/github.com/fluffle/goirc \
		golang:mock:v1.1.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:sys:953cdadca894:golang_sys/vendor/golang.org/x/sys \
		hectane:go-nonblockingchan:v0.1.0:hectane_go_nonblockingchan/vendor/github.com/hectane/go-nonblockingchan \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mephux:common:c3a670c8b76e:mephux_common/vendor/github.com/mephux/common \
		nsf:termbox-go:93860e161317:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		worg:merger:94181de72ed1:worg_merger/vendor/github.com/worg/merger

_BUILD_SHA=	${GH_TAGNAME}
_BUILD_COUNT=	138
_BUILD_TAG=	${_BUILD_COUNT}.${_BUILD_SHA}

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Build=${_BUILD_TAG}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
