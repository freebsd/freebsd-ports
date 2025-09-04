PORTNAME=	gopls
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Go language LSP server
WWW=		https://pkg.go.dev/golang.org/x/tools/gopls

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	golang.org/x/tools/gopls

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md doc" ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/doc/*.go

.include <bsd.port.mk>
