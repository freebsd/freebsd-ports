PORTNAME=	ddosify
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	7
CATEGORIES=	benchmarks

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	High-performance load testing tool, part of anteon
WWW=		https://github.com/getanteon/anteon/ddosify_engine

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	getanteon
GH_PROJECT=	anteon
GH_TAGNAME=	selfhosted-${DISTVERSION}
GITID=		b38549c259cf8

GH_TUPLE=	\
		antchfx:htmlquery:v1.3.0:antchfx_htmlquery/vendor/github.com/antchfx/htmlquery \
		antchfx:xmlquery:v1.3.13:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.2.3:antchfx_xpath/vendor/github.com/antchfx/xpath \
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		ddosify:go-faker:v0.1.1:ddosify_go_faker/vendor/github.com/ddosify/go-faker \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		golang:exp:4b8118a2686a:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.8.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		jaswdr:faker:v1.10.2:jaswdr_faker/vendor/github.com/jaswdr/faker \
		lufia:plan9stats:39d0f177ccd0:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		power-devops:perfstat:5aafc221ea8c:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		shirou:gopsutil:v3.22.12:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		tidwall:gjson:v1.14.4:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tklauser:go-sysconf:v0.3.11:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.6.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

GO_BUILDFLAGS=	-ldflags='\
		-s -w \
		-X main.GitVersion=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X main.GitCommit=${GITID}'

WRKSRC_SUBDIR=	ddosify_engine

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EMOJI ZSH
OPTIONS_DEFAULT=EMOJI ZSH

EMOJI_DESC=	Enable emojis in console output
EMOJI_RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
