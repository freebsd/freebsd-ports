PORTNAME=	mergify
PORTVERSION=	g20180512
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Merge changes from a branch one commit at a time
WWW=		https://github.com/brooksdavis/mergify

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	brooksdavis
GH_TAGNAME=	606ffbe2df73e4c4edfe399573d2f1df782aefbc

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mergify
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mergify ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
