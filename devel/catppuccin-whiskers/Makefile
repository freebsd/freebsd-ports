PORTNAME=	whiskers
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
CATEGORIES=	devel
PKGNAMEPREFIX=	catppuccin-

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Soothing port creation tool for the high-spirited!
WWW=		https://whiskers.catppuccin.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	catppuccin

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
