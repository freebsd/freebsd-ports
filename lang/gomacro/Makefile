# $FreeBSD$

PORTNAME=	gomacro
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7-304
DISTVERSIONSUFFIX=	-g2f4dc7c
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Interactive Go interpreter and debugger with REPL, generics and macros

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/cosmos72/gomacro
USE_GITHUB=	yes
GH_ACCOUNT=	cosmos72
GH_TUPLE=	golang:sys:b294cbc:golang_sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:v0.0.3:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		peterh:liner:6f820f8:peterh_liner/vendor/github.com/peterh/liner

PLIST_FILES=	bin/gomacro

.include <bsd.port.mk>
