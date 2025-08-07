PORTNAME=	task
DISTVERSIONPREFIX=	v
DISTVERSION=	3.44.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Task runner / simpler Make alternative written in Go
WWW=		https://taskfile.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/go-task/task/v3
GO_TARGET=	./cmd/task

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
