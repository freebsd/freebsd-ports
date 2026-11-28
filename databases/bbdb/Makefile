PORTNAME=	bbdb
# Upstream stopped tagging releases after 3.2, so use the version from AC_INIT
# in configure.ac plus the date of the GH_TAGNAME commit.
DISTVERSION=	3.2.2d.20231122
CATEGORIES=	databases elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Big Brother Database
WWW=		https://savannah.nongnu.org/projects/bbdb/

LICENSE=	GPLv3+

USES=		autoreconf emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	emacsmirror
GH_TAGNAME=	53e8ba04c47b3542db75b68f9663941daf2e6ca4

BBDB_LISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	bbdb-emacs_*

# Do not install the info file.  Upstream has yet to add any real content to it.
#INFO=		bbdb
NO_ARCH=	yes
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR}
PORTDOCS=	bbdb.pdf

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	texi2dvi:print/texinfo
DOCS_USES=		tex
DOCS_USE=		TEX=latex:build
DOCS_CONFIGURE_ENABLE=	docs

# Upstream's bbdb-loaddefs.el is not picked up by the FreeBSD autoload loader,
# which only loads *-autoloads.el.  Generate this after the upstream build,
# which refuses to run if bbdb-autoloads.el exists.
post-build:
	${EMACS_CMD} -q --batch --eval '(loaddefs-generate \
		"${WRKSRC}/lisp" "${WRKSRC}/lisp/bbdb-autoloads.el" \
		(list "${WRKSRC}/lisp/bbdb-loaddefs.el"))'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
# Do not install the info file.  Upstream has yet to add any real content to it.
#	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbdb.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
