PORTNAME=	closql
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Store EIEIO objects using EmacSQL
WWW=		https://github.com/magit/closql

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.0.0.0:misc/compat.el@${EMACS_FLAVOR} \
		emacsql${EMACS_PKGNAMESUFFIX}>=4.3.1:databases/emacsql@${EMACS_FLAVOR}
RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.0.0.0:misc/compat.el@${EMACS_FLAVOR} \
		emacsql${EMACS_PKGNAMESUFFIX}>=4.3.1:databases/emacsql@${EMACS_FLAVOR}

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ENV+=	LOAD_PATH="${LOAD_PATH}"
MAKE_JOBS_UNSAFE=	Opening input file: No such file or directory, /wrkdirs/usr/ports/databases/closql/work-full/closql-2.2.0/.#closql-autoloads.el

CONFLICTS_INSTALL=	closql closql-devel* closql-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/closql-autoloads.el \
		${EMACS_VERSION_SITE_LISPDIR}/closql.el \
		${EMACS_VERSION_SITE_LISPDIR}/closql.elc

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

LOAD_PATH=	-L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacsql

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el* \
	   ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
