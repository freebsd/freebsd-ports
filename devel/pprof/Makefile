# $FreeBSD$

PORTNAME=	pprof
DISTVERSION=	g20190515
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for visualization and analysis of profiling data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	54271f7
GH_TUPLE=	chzyer:readline:v1.4:readline/vendor/github.com/chzyer/readline \
		ianlancetaylor:demangle:5e5cf60:demangle/vendor/github.com/ianlancetaylor/demangle
GH_SUBDIR=	src/github.com/google/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
