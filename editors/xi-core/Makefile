PORTNAME=	xi-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0.20230412
PORTREVISION=	5
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Modern editor backend written in Rust
WWW=		https://xi-editor.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

DEPRECATED=	Project is currently discontinued, one depend port broken (editors/xi-term set to deprecation too). Upstream recommends editors/lapce
EXPIRATION_DATE=	2023-12-31

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	xi-editor
GH_PROJECT=	xi-editor
GH_TAGNAME=	ec9bf91

WRKSRC_SUBDIR=	rust

PLIST_FILES=	bin/xi-core
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xi-core

.include <bsd.port.mk>
