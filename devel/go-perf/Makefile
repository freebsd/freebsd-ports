PORTNAME=	go-perf
PORTVERSION=	${MODVERSION:S/-/./g:R}
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Go performance measurement, storage, and analysis tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
MODVERSION=	0.0.0-20210220033136-40a54f11e909
GO_MODULE=	golang.org/x/perf@v${MODVERSION}

GO_TARGET=	./cmd/benchsave \
		./cmd/benchstat \
		./analysis/localperf \
		./storage/localperfdata

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

.include <bsd.port.mk>
