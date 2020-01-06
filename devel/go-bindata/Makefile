# $FreeBSD$

PORTNAME=	go-bindata
PORTVERSION=	3.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generates Go code from any file

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/go-bindata/go-bindata

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
