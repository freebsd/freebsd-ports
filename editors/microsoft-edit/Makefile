PORTNAME=	microsoft-edit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
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

PLIST_FILES=	bin/edit \
		bin/msedit \
		share/man/man1/edit.1.gz \
		share/man/man1/msedit.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/bin/edit ${STAGEDIR}${PREFIX}/bin/msedit
	${INSTALL_MAN} ${WRKSRC}/assets/manpage/edit.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/edit.1 ${STAGEDIR}${PREFIX}/share/man/man1/msedit.1

.include <bsd.port.mk>
