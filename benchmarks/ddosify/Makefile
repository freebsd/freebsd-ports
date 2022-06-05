# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	ddosify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.9
CATEGORIES=	benchmarks

MAINTAINER=	0xdutra@gmail.com
COMMENT=	High-performance load testing tool

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		golang:net:2871e0cb64e4:golang_net/vendor/golang.org/x/net \
		golang:sys:9388b58f7150:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EMOJI
OPTIONS_DEFAULT=EMOJI

EMOJI_DESC=	Enable emojis in console output
EMOJI_RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

.include <bsd.port.mk>
