PORTNAME=	weebsay
PORTVERSION=	0.0.20210508
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Like cowsay but with random anime quotes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	irevenko
GH_TAGNAME=	8107cc5

GH_TUPLE=	fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
