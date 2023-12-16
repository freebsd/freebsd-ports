PORTNAME=	pprof
DISTVERSION=	g20200905
PORTREVISION=	15
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for visualization and analysis of profiling data
WWW=		https://github.com/google/pprof

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	acf8798
GH_TUPLE=	\
		chzyer:logex:v1.1.10:chzyer_logex/vendor/github.com/chzyer/logex \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		chzyer:test:a1ea475d72b1:chzyer_test/vendor/github.com/chzyer/test \
		golang:sys:ce4227a45e2e:golang_sys/vendor/golang.org/x/sys \
		ianlancetaylor:demangle:5e5cf60278f6:ianlancetaylor_demangle/vendor/github.com/ianlancetaylor/demangle
GH_SUBDIR=	src/github.com/google/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
