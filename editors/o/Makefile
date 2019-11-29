# $FreeBSD$

PORTNAME=	o
DISTVERSION=	2.10.2
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
		golang:sys:8a8471f7e56d:golang_sys/vendor/golang.org/x/sys \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:burnfont:v1.2.2:xyproto_burnfont/vendor/github.com/xyproto/burnfont \
		xyproto:syntax:9809e592290a:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:textoutput:v1.9.1:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:v1.8.1:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
