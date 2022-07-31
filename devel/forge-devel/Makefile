PORTNAME=	forge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1-65
DISTVERSIONSUFFIX=	-ged8abda
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Work with Git forges from the comfort of Magit (Development Version)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	closql${EMACS_PKGNAMESUFFIX}>=1.2.0:databases/closql@${EMACS_FLAVOR} \
		compat.el${EMACS_PKGNAMESUFFIX}>=28.1.1.0:misc/compat.el@${EMACS_FLAVOR} \
		dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		emacsql${EMACS_PKGNAMESUFFIX}>=3.0.0:databases/emacsql@${EMACS_FLAVOR} \
		ghub-devel${EMACS_PKGNAMESUFFIX}>=3.5.4:devel/ghub-devel@${EMACS_FLAVOR} \
		magit-devel${EMACS_PKGNAMESUFFIX}>=3.3.0:devel/magit-devel@${EMACS_FLAVOR} \
		markdown-mode.el${EMACS_PKGNAMESUFFIX}>=2.4:textproc/markdown-mode.el@${EMACS_FLAVOR} \
		transient-devel${EMACS_PKGNAMESUFFIX}>=0.3.6:devel/transient-devel@${EMACS_FLAVOR} \
		yaml.el${EMACS_PKGNAMESUFFIX}>=0.3.4:textproc/yaml.el@${EMACS_FLAVOR}
RUN_DEPENDS=	closql${EMACS_PKGNAMESUFFIX}>=1.2.0:databases/closql@${EMACS_FLAVOR} \
		compat.el${EMACS_PKGNAMESUFFIX}>=28.1.1.0:misc/compat.el@${EMACS_FLAVOR} \
		dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		emacsql${EMACS_PKGNAMESUFFIX}>=3.0.0:databases/emacsql@${EMACS_FLAVOR} \
		ghub-devel${EMACS_PKGNAMESUFFIX}>=3.5.4:devel/ghub-devel@${EMACS_FLAVOR} \
		magit-devel${EMACS_PKGNAMESUFFIX}>=3.3.0:devel/magit-devel@${EMACS_FLAVOR} \
		markdown-mode.el${EMACS_PKGNAMESUFFIX}>=2.4:textproc/markdown-mode.el@${EMACS_FLAVOR} \
		transient-devel${EMACS_PKGNAMESUFFIX}>=0.3.6:devel/transient-devel@${EMACS_FLAVOR} \
		yaml.el${EMACS_PKGNAMESUFFIX}>=0.3.4:textproc/yaml.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ENV+=	INSTALL_INFO=install-info \
		LOAD_PATH="${LOAD_PATH}"
# Parallel build fails if Emacs is built with native compilation enabled
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lisp info

CONFLICTS=	forge-emacs*

NO_ARCH=	yes

INFO=		forge
PORTDOCS=	CHANGELOG README.org forge.html

OPTIONS_DEFINE=	DOCS PDF
OPTIONS_SUB=	yes

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf

LOAD_PATH=	-L ${PREFIX}/${EMACS_SITE_LISPDIR} -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/closql -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacsql -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/ghub -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/magit

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el* \
	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.org \
		${WRKSRC}/docs/forge.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/forge.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
