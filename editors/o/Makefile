# $FreeBSD$

PORTNAME=	o
DISTVERSION=	2.35.1
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small, fast and limited text editor in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	\
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		golang:sys:489259a85091:golang_sys/vendor/golang.org/x/sys \
		jung-kurt:gofpdf:v1.16.2:jung_kurt_gofpdf/vendor/github.com/jung-kurt/gofpdf \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pkg:term:v1.2.0-beta.1:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:env:dd84be2a4935:xyproto_env/vendor/github.com/xyproto/env \
		xyproto:syntax:v1.7.3:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:termtitle:v1.1.0:xyproto_termtitle/vendor/github.com/xyproto/termtitle \
		xyproto:textoutput:v1.12.2:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:1c2ef2e081cd:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
