PORTNAME=	lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	18.2.0
CATEGORIES=	editors
PKGNAMEPREFIX=	${KAKPKGNAMEPREFIX}

MAINTAINER=	seafork@disroot.org
COMMENT=	Kakoune Language Server Protocol Client
WWW=		https://github.com/kakoune-lsp/kakoune-lsp

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2022.10.31:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kakoune-lsp
GH_PROJECT=	kakoune-lsp

SUB_FILES=	pkg-message

PLIST_FILES=	${KAKDIR}/rc/kak-lsp/lsp.kak \
		${KAKDIR}/rc/kak-lsp/servers.kak \
		bin/kak-lsp

PORTDOCS=	README.asciidoc

.include "../kakoune/Makefile.include"
.include <bsd.port.options.mk>

OPTIONS_DEFINE=	DOCS

pre-install:
	@${MKDIR} ${STAGEDIR}${KAKDIR}/rc/kak-lsp
	${INSTALL_DATA} ${WRKSRC}/rc/lsp.kak \
		${WRKSRC}/rc/servers.kak \
		${STAGEDIR}${KAKDIR}/rc/kak-lsp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
