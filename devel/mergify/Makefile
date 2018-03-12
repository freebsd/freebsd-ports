# $FreeBSD$

PORTNAME=	mergify
PORTVERSION=	g20170106
CATEGORIES=	devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Merge changes from a branch one commit at a time

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	brooksdavis
GH_PROJECT=	mergify
GH_TAGNAME=	02519f69ab096797fc626487610cab9acdcba26f

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
