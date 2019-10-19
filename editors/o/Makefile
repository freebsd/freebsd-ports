# $FreeBSD$

PORTNAME=	o
DISTVERSION=	2.4.9
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small, fast and limited text editor in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	\
		golang:sys:b09406accb47:golang_sys/vendor/golang.org/x/sys \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:syntax:1aa81d747d75:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:textoutput:v1.8.0:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:f1727647a85e:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
