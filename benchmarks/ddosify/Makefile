PORTNAME=	ddosify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	0xdutra@gmail.com
COMMENT=	High-performance load testing tool

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		ddosify:go-faker:v0.1.1:ddosify_go_faker/vendor/github.com/ddosify/go-faker \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		golang:net:2871e0cb64e4:golang_net/vendor/golang.org/x/net \
		golang:sys:9388b58f7150:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		jaswdr:faker:v1.10.2:jaswdr_faker/vendor/github.com/jaswdr/faker \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.2.1:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EMOJI
OPTIONS_DEFAULT=EMOJI

EMOJI_DESC=	Enable emojis in console output
EMOJI_RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

.include <bsd.port.mk>
