PORTNAME=	go-bindata
PORTVERSION=	3.1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generates Go code from any file
WWW=		https://github.com/go-bindata/go-bindata

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:tools:a911d9008d1f:golang_tools/vendor/golang.org/x/tools \
		kisielk:errcheck:v1.2.0:kisielk_errcheck/vendor/github.com/kisielk/errcheck

GO_TARGET=	./go-bindata

PLIST_FILES=	bin/go-bindata

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
