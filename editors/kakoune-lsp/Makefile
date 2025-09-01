PORTNAME=	kakoune-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	18.1.3
PORTREVISION=	4
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client
WWW=		https://github.com/kakoune-lsp/kakoune-lsp

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2022.10.31:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kakoune-lsp

SUB_FILES=	pkg-message

PLIST_FILES=	bin/kak-lsp
PORTDOCS=	README.asciidoc

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
