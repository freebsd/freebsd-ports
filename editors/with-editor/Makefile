# Created by: KIMURA Yasuhiro <yasu@utahime.org>

PORTNAME=	with-editor
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Use the Emacsclient as the $$EDITOR of child processes

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	lisp info

NO_ARCH=	yes

INFO=		with-editor
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/with-editor-autoloads.el \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor.el \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor.elc
PORTDOCS=	AUTHORS.md README.md with-editor.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf
PDF_PLIST_FILES=	${DOCSDIR}/with-editor.pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/docs/AUTHORS.md \
		${WRKSRC}/docs/with-editor.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/with-editor.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
