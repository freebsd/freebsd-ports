PORTNAME=	pprof
DISTVERSION=	2024.12.09 # the upstream has no plans to make releases: https://github.com/google/pprof/issues/714#issuecomment-1192930097
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for visualization and analysis of profiling data
WWW=		https://github.com/google/pprof

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	40e02aa
GH_TUPLE=	chzyer:readline:v1.5.1:chzyer_readline/vendor/github.com/chzyer/readline \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		ianlancetaylor:demangle:bd984b5ce465:ianlancetaylor_demangle/vendor/github.com/ianlancetaylor/demangle
GH_SUBDIR=	src/github.com/google/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
