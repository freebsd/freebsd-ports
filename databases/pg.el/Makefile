PORTNAME=	pg.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.67
CATEGORIES=	databases elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	PostgreSQL Elisp interface
WWW=		https://github.com/emarsden/pg-el

LICENSE=	GPLv2+

USES=		emacs

USE_GITHUB=	yes
GH_ACCOUNT=	emarsden
GH_PROJECT=	pg-el

CONFLICTS_INSTALL=	pg.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB+=	ELISPDIR=${ELISPDIR}

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el \
	    ${STAGEDIR}${PREFIX}/${ELISPDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
