# $FreeBSD$

PORTNAME=	o
DISTVERSION=	2.6.5
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small, fast and limited text editor in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	\
		golang:sys:c1f44814a5cd:golang_sys/vendor/golang.org/x/sys \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		xyproto:syntax:a179398d46f5:xyproto_syntax/vendor/github.com/xyproto/syntax \
		xyproto:textoutput:v1.8.0:xyproto_textoutput/vendor/github.com/xyproto/textoutput \
		xyproto:vt100:v1.5.1:xyproto_vt100/vendor/github.com/xyproto/vt100

PLIST_FILES=	bin/o

.include <bsd.port.mk>
