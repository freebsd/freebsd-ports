PORTNAME=	bbdb
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2a
PORTREVISION=	13
CATEGORIES=	databases elisp

MAINTAINER=	emacs@FreeBSD.org
COMMENT=	Big Brother Database
WWW=		https://savannah.nongnu.org/projects/bbdb/

LICENSE=	GPLv3+

BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		autoreconf emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	emacsmirror
GH_TAGNAME=	a50c89a

CONFLICTS_INSTALL=	bbdb-emacs_*

BBDB_LISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

# Do not install the info file.  Upstream has yet to add any real content to it.
#INFO=		bbdb
PORTDOCS=	bbdb.pdf
NO_ARCH=	yes
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR}

OPTIONS_DEFINE=	DOCS
DOCS_USES=	tex
DOCS_USE=	TEX=latex:build
DOCS_CONFIGURE_ENABLE=	docs

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
# Do not install the info file.  Upstream has yet to add any real content to it.
#	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
#		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbdb.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
