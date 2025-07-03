PORTNAME=	microsoft-edit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Console text editor written in Rust
WWW=		https://github.com/microsoft/edit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	edit

CARGO_ENV+=	RUSTC_BOOTSTRAP=1

PORTDOCS=	CODE_OF_CONDUCT.md CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/bin/edit ${STAGEDIR}${PREFIX}/bin/msedit
	${INSTALL_MAN} ${WRKSRC}/assets/manpage/edit.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/edit.1 ${STAGEDIR}${PREFIX}/share/man/man1/msedit.1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/com.microsoft.edit.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/edit.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/msedit.svg

.include <bsd.port.mk>
