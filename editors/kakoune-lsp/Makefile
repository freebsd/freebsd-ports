PORTNAME=	kakoune-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	17.1.1
CATEGORIES=	editors

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client
WWW=		https://github.com/kakoune-lsp/kakoune-lsp

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2022.10.31:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kakoune-lsp

SUB_FILES=	pkg-message

PLIST_FILES=	bin/kak-lsp \
		"@sample ${ETCDIR}/kak-lsp.toml.sample"
PORTDOCS=	README.asciidoc

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak-lsp
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/kak-lsp.toml ${STAGEDIR}${ETCDIR}/kak-lsp.toml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
