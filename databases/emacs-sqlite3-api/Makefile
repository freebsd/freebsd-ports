PORTNAME=	emacs-sqlite3-api
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18
PORTREVISION=	3
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	SQLite3 API for Emacs 25+
WWW=		https://github.com/pekingduck/emacs-sqlite3-api

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pekingduck

MAKE_ENV+=	LIB="-L${LOCALBASE}/lib -lsqlite3"

CFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

post-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -f batch-byte-compile sqlite3.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sqlite3-api.so ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/sqlite3.el* ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
