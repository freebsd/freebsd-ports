# $FreeBSD$

PORTNAME=	go-bindata
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generates Go code from any file

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	jteeuwen
GH_TAGNAME=	a0ff256
GH_SUBDIR=	src/github.com/jteeuwen/go-bindata

GO_TARGET=	./go-bindata

PLIST_FILES=	bin/go-bindata

PORTDOCS=	CONTRIBUTING.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
