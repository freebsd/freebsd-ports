# $FreeBSD$

PORTNAME=	o
DISTVERSION=	2.29.2
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
		golang:sys:fe76b779f299:golang_sys/vendor/golang.org/x/sys \
		jung-kurt:gofpdf:v1.16.2:jung_kurt_gofpdf/vendor/github.com/jung-kurt/gofpdf \
		pkg:term:c3ffed290a03:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:syntax:236883b630eb:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:textoutput:v1.11.1:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:v1.8.4:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
