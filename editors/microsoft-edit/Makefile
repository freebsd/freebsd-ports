PORTNAME=	microsoft-edit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	editors

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Console text editor written in Rust
WWW=		https://github.com/microsoft/edit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	edit

BUILD_DEPENDS=	rust-nightly>0:lang/rust-nightly
CARGO_BUILDDEP=	no

PORTDOCS=	CODE_OF_CONDUCT.md CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=		DOCS

PLIST_FILES=	bin/edit bin/msedit

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	${LN} -sf ${PREFIX}/bin/edit ${STAGEDIR}/${PREFIX}/bin/msedit

.include <bsd.port.mk>
