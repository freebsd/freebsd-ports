PORTNAME=	go-perf
PORTVERSION=	${MODVERSION:S/-/./g:R}
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Go performance measurement, storage, and analysis tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
MODVERSION=	0.0.0-20220411212318-84e58bfe0a7e
GO_MODULE=	golang.org/x/perf@v${MODVERSION}

GO_TARGET=	./cmd/benchsave \
		./cmd/benchseries \
		./cmd/benchstat

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

OPTIONS_DEFINE=	DEPRECATED
DEPRECATED_DESC=	Install deprecated utilities
DEPRECATED_VARS=	GO_TARGET+="./analysis/localperf ./storage/localperfdata"

.include <bsd.port.mk>
