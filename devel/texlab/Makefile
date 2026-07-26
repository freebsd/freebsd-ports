PORTNAME=	texlab
DISTVERSIONPREFIX=	v
DISTVERSION=	5.26.0
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
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

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
