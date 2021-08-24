PORTNAME=	o
DISTVERSION=	2.43.1
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small, fast and limited text editor in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	\
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		golang:sys:1e6c022a8912:golang_sys/vendor/golang.org/x/sys \
		jung-kurt:gofpdf:v1.16.2:jung_kurt_gofpdf/vendor/github.com/jung-kurt/gofpdf \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.13:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pkg:term:v1.2.0-beta.2:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:benchmarked:v0.1.0:xyproto_benchmarked/vendor/github.com/xyproto/benchmarked \
		xyproto:env:v1.1.0:xyproto_env/vendor/github.com/xyproto/env \
		xyproto:guessica:v1.1.0:xyproto_guessica/vendor/github.com/xyproto/guessica \
		xyproto:syntax:v1.7.3:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:termtitle:v1.3.0:xyproto_termtitle/vendor/github.com/xyproto/termtitle \
		xyproto:textoutput:b3f0f5b63cef:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:v1.9.5:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
