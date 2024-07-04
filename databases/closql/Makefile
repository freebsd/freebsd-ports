PORTNAME=	closql
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	10
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Store EIEIO objects using EmacSQL
WWW=		https://github.com/magit/closql

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	emacsql${EMACS_PKGNAMESUFFIX}>=3.0.0:databases/emacsql@${EMACS_FLAVOR}
RUN_DEPENDS=	emacsql${EMACS_PKGNAMESUFFIX}>=3.0.0:databases/emacsql@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magit

CONFLICTS_INSTALL=	closql closql-devel* closql-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/closql.el \
		${EMACS_VERSION_SITE_LISPDIR}/closql.elc

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . \
		-L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacsql \
		-f batch-byte-compile closql.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} closql.el* \
	   ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
