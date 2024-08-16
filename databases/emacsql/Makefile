PORTNAME=	emacsql
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	High-level Emacs Lisp RDBMS front-end
WWW=		https://github.com/magit/emacsql

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

BUILD_DEPENDS=	emacs-sqlite3-api${EMACS_PKGNAMESUFFIX}>=0.18:databases/emacs-sqlite3-api@${EMACS_FLAVOR} \
		pg.el${EMACS_PKGNAMESUFFIX}>=0.39:databases/pg.el@${EMACS_FLAVOR}
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	emacs-sqlite3-api${EMACS_PKGNAMESUFFIX}>=0.18:databases/emacs-sqlite3-api@${EMACS_FLAVOR} \
		pg.el${EMACS_PKGNAMESUFFIX}>=0.39:databases/pg.el@${EMACS_FLAVOR}

USES=		emacs gmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ENV+=	LOAD_PATH="-L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}"
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	test

CONFLICTS_INSTALL=	emacsql emacsql-devel* emacsql-emacs_*

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${RM} ${WRKSRC}/sqlite/sqlite3.[ch]
	${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/emacsql-sqlite.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/sqlite/emacsql-sqlite \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
