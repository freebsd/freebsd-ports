PORTNAME=	forge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.6
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Work with Git forges from the comfort of Magit
WWW=		https://github.com/magit/forge

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	closql>=2.4:databases/closql \
		compat.el>=30.1.0.0:misc/compat.el \
		cond-let>=0.2:devel/cond-let \
		emacsql>=4.3.1:databases/emacsql \
		ghub>=5.1:devel/ghub \
		llama.el>=1.0:devel/llama.el \
		magit>=4.5:devel/magit \
		markdown-mode.el>=2.7:textproc/markdown-mode.el \
		transient>=0.12:devel/transient \
		yaml.el>=1.2.0:textproc/yaml.el

USES=		emacs:build gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

CONFLICTS_INSTALL=	forge-emacs_*

NO_ARCH=	yes

INFO=		forge
PORTDOCS=	CHANGELOG README.org forge.html

OPTIONS_DEFINE=	DOCS PDF
OPTIONS_SUB=	yes

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build

do-build:
	${GMAKE} -C ${WRKSRC}/lisp autoloads
	${GMAKE} -C ${WRKSRC}/docs info

do-build-DOCS-on:
	${GMAKE} -C ${WRKSRC}/docs html

do-build-PDF-on:
	${GMAKE} -C ${WRKSRC}/docs pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
	${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.org \
		${WRKSRC}/docs/forge.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/forge.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
