# $FreeBSD$

PORTNAME=	gllvm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Whole Program LLVM: wllvm ported to Go

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	SRI-CSL

GO_PKGNAME=	github.com/SRI-CSL/gllvm
GO_TARGET=	./cmd/gclang++ \
		./cmd/gclang \
		./cmd/get-bc \
		./cmd/gsanity-check

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

PORTDOCS=	README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
