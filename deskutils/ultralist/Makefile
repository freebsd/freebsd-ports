# $FreeBSD$

PORTNAME=	ultralist
DISTVERSION=	0.9.5
CATEGORIES=	deskutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Simple, powerful, task management system for the command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_GITHUB=	yes
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
