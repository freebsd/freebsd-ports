# $FreeBSD$

PORTNAME=	mergify
PORTVERSION=	g20180512
CATEGORIES=	devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Merge changes from a branch one commit at a time

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	brooksdavis
GH_PROJECT=	mergify
GH_TAGNAME=	606ffbe2df73e4c4edfe399573d2f1df782aefbc

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mergify
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS GIT_SUBVERSION

GIT_SUBVERSION_DESC=	Use devel/git-subversion as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git:devel/git

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mergify ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
