PORTNAME=	go-perf
PORTVERSION=	${MODVERSION:S/-/./g:R}
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Go performance measurement, storage, and analysis tools
WWW=		https://golang.org/x/perf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
MODVERSION=	0.0.0-20250605212013-b481878a17be
GO_MODULE=	golang.org/x/perf@v${MODVERSION}

GO_TARGET=	./cmd/benchsave \
		./cmd/benchseries \
		./cmd/benchstat \
		./cmd/benchfilter

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

OPTIONS_DEFINE=	DEPRECATED
DEPRECATED_DESC=	Install deprecated utilities
DEPRECATED_VARS=	GO_TARGET+="./analysis/localperf ./storage/localperfdata"

.include <bsd.port.mk>
