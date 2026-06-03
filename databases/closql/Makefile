PORTNAME=	closql
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	databases elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Store EIEIO objects using EmacSQL
WWW=		https://github.com/magit/closql

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.0.0.0:misc/compat.el \
		cond-let>=0.2.1:devel/cond-let \
		emacsql>=4.3.1:databases/emacsql

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	autoloads

CONFLICTS_INSTALL=	closql-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}/closql-autoloads.el \
		${EMACS_SITE_LISPDIR}/${PORTNAME}/closql.el

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el \
	   ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
