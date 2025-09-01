PORTNAME=	pg.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.59
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	PostgreSQL Elisp interface
WWW=		https://github.com/emarsden/pg-el

LICENSE=	GPLv2+

USES=		emacs

USE_GITHUB=	yes
GH_ACCOUNT=	emarsden
GH_PROJECT=	pg-el

CONFLICTS_INSTALL=	pg.el pg.el-emacs_* # share/doc/pg.el/README

NO_ARCH=	yes

PLIST_SUB+=	ELISPDIR=${ELISPDIR}

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
	-f batch-byte-compile *.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el* \
	    ${STAGEDIR}${PREFIX}/${ELISPDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
