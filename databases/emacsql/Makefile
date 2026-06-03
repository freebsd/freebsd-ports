PORTNAME=	emacsql
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.6
CATEGORIES=	databases elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	High-level Emacs Lisp RDBMS front-end
WWW=		https://github.com/magit/emacsql

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	pg.el>=0.39:databases/pg.el

USES=		emacs:build gmake

USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	autoloads
TEST_TARGET=	test

CONFLICTS_INSTALL=	emacsql-emacs_*

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
