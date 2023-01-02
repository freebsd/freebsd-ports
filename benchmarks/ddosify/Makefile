PORTNAME=	ddosify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	benchmarks

MAINTAINER=	0xdutra@gmail.com
COMMENT=	High-performance load testing tool
WWW=		https://github.com/ddosify/ddosify

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		antchfx:xmlquery:v1.3.13:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.2.1:antchfx_xpath/vendor/github.com/antchfx/xpath \
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		ddosify:go-faker:v0.1.1:ddosify_go_faker/vendor/github.com/ddosify/go-faker \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.7.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.3.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.3.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.5.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.4.0:golang_tools/vendor/golang.org/x/tools \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		jaswdr:faker:v1.10.2:jaswdr_faker/vendor/github.com/jaswdr/faker \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		tidwall:gjson:v1.14.4:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		yuin:goldmark:v1.4.13:yuin_goldmark/vendor/github.com/yuin/goldmark

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EMOJI
OPTIONS_DEFAULT=EMOJI

EMOJI_DESC=	Enable emojis in console output
EMOJI_RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

.include <bsd.port.mk>
