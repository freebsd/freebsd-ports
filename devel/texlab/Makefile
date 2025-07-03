PORTNAME=	texlab
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
PORTREVISION=	27
CATEGORIES=	devel

MAINTAINER=	kfv@kfv.io
COMMENT=	Language Server Protocol for LaTeX
WWW=		https://texlab.netlify.app/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	latex-lsp

# Fixes: error: the linked panic runtime `panic_unwind` is not compiled with
# this crate's panic strategy `abort`
WITHOUT_LTO=	yes # XXX bug 277333

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG.md README.md docs/*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
