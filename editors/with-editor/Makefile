PORTNAME=	with-editor
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.1
CATEGORIES=	editors elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Use the Emacsclient as the $$EDITOR of child processes
WWW=		https://github.com/magit/with-editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=31.0:misc/compat.el \
		cond-let>=1.0:devel/cond-let

USES=		emacs:build gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

CONFLICTS_INSTALL=	with-editor-devel-emacs*

NO_ARCH=	yes

INFO=		with-editor
PLIST_FILES=	${ELISPDIR}/with-editor-autoloads.el \
		${ELISPDIR}/with-editor.el
PORTDOCS=	README.org with-editor.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_PLIST_FILES=	${DOCSDIR}/with-editor.pdf

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${MAKE_CMD} info
	cd ${WRKSRC}/lisp && ${MAKE_CMD} autoloads

do-build-DOCS-on:
	cd ${WRKSRC} && SED=gsed ${MAKE_CMD} html

do-build-PDF-on:
	cd ${WRKSRC} && ${MAKE_CMD} pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org \
		${WRKSRC}/docs/with-editor.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/with-editor.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
