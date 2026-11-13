PORTNAME=	ttt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	editors
PKGNAMESUFFIX=	-editor

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	IDE that lives in your terminal
WWW=		https://tttedit.dev/ \
		https://github.com/eugenioenko/ttt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/eugenioenko/ttt
GO_TARGET=	./cmd/ttt
GO_LDFLAGS=	-w -X main.version=${DISTVERSIONFULL}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ARCHITECTURE.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
