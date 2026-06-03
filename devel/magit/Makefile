PORTNAME=	magit
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Interface to Git for Emacs
WWW=		https://magit.vc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		cond-let>=0.1:devel/cond-let \
		git:devel/git \
		llama.el>=1.0.0:devel/llama.el \
		transient>=0.10.0:devel/transient \
		with-editor>=3.4.4:editors/with-editor
RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		cond-let>=0.1:devel/cond-let \
		git:devel/git \
		llama.el>=1.0.0:devel/llama.el \
		transient>=0.10.0:devel/transient \
		with-editor>=3.4.4:editors/with-editor

USES=		emacs:build gmake makeinfo
USE_GITHUB=	yes

MAKE_ENV+=	docdir=${DOCSDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		INSTALL_INFO=install-info \
		lispdir=${PREFIX}/${ELISPDIR} \
		LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_SITE_LISPDIR}/compat" \
		VERSION=${PORTVERSION}
# Parallel build fails if Emacs is built with native compilation enabled
MAKE_JOBS_UNSAFE=	yes
#ALL_TARGET=	lisp info
#INSTALL_TARGET=	install-lisp install-info

CONFLICTS_INSTALL=	magit-emacs_*

NO_ARCH=	yes

INFO=		magit magit-section
PLIST_SUB+=	ELISPDIR=${ELISPDIR}
PORTDOCS=	*.html *.md RelNotes/*

OPTIONS_DEFINE=	DOCS PDF
OPTIONS_SUB=	yes

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-build:
	${GMAKE} -C ${WRKSRC}/lisp autoloads versionlib
	${GMAKE} -C ${WRKSRC}/docs info

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/info
	${INSTALL_DATA} ${WRKSRC}/docs/magit.info \
		${WRKSRC}/docs/magit-section.info \
		${STAGEDIR}${PREFIX}/share/info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/RelNotes
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/docs/RelNotes ${STAGEDIR}${DOCSDIR}/RelNotes

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
