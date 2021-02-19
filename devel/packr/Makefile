# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/gobuffalo/packr/v2
GO_TARGET=	./packr2

PLIST_FILES=	bin/packr2

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
