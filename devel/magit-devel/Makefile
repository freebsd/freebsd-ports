PORTNAME=	magit
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
DISTVERSIONSUFFIX=
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Interface to Git for Emacs (Development Version)
WWW=		https://magit.vc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.0.0.0:misc/compat.el@${EMACS_FLAVOR} \
		dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		git:devel/git \
		transient-devel${EMACS_PKGNAMESUFFIX}>=0.7.4:devel/transient-devel@${EMACS_FLAVOR} \
		with-editor-devel${EMACS_PKGNAMESUFFIX}>=3.4.1:editors/with-editor-devel@${EMACS_FLAVOR}
RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.0.0.0:misc/compat.el@${EMACS_FLAVOR} \
		dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		git:devel/git \
		transient-devel${EMACS_PKGNAMESUFFIX}>=0.7.4:devel/transient-devel@${EMACS_FLAVOR} \
		with-editor-devel${EMACS_PKGNAMESUFFIX}>=3.4.1:editors/with-editor-devel@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes

MAKE_ENV+=	docdir=${DOCSDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		INSTALL_INFO=install-info \
		lispdir=${PREFIX}/${ELISPDIR} \
		LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat" \
		VERSION=${PORTVERSION}
# Parallel build fails if Emacs is built with native compilation enabled
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lisp info
INSTALL_TARGET=	install-lisp install-info

CONFLICTS_INSTALL=	magit-emacs*

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

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/RelNotes
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/docs/RelNotes ${STAGEDIR}${DOCSDIR}/RelNotes

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
