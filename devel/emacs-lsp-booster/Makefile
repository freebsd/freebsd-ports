PORTNAME=	emacs-lsp-booster
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	11
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Emacs LSP performance booster
WWW=		https://github.com/blahgeek/emacs-lsp-booster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	blahgeek
PLIST_FILES=	bin/emacs-lsp-booster
PORTDOCS=	README.md

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}/README.md

.include <bsd.port.mk>
