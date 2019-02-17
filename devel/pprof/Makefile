# $FreeBSD$

PORTNAME=	pprof
DISTVERSION=	g20190207
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for visualization and analysis of profiling data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	b421f19
GH_TUPLE=	chzyer:readline:v1.4:readline/src/github.com/chzyer/readline \
		ianlancetaylor:demangle:5e5cf60:demangle/src/github.com/ianlancetaylor/demangle
GH_SUBDIR=	src/github.com/google/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
