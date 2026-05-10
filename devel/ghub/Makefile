PORTNAME=	ghub
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.0
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Client libraries for the APIs of various Git forges
WWW=		https://github.com/magit/ghub

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		cond-let>0.2:devel/cond-let \
		llama.el>=1.0:devel/llama.el \
		treepy.el>=0.1.3:devel/treepy.el

USES=		emacs:build gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

CONFLICTS_INSTALL=	ghub-emacs_*

NO_ARCH=	yes

INFO=		ghub
PORTDOCS=	CHANGELOG README.org ghub.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_PLIST_FILES=	${DOCSDIR}/ghub.pdf

ELISP_FILES=	ghub-autoloads.el ghub-graphql.el ghub-legacy.el ghub.el gsexp.el

do-build:
	cd ${WRKSRC} && ${MAKE_CMD} info
	cd ${WRKSRC}/lisp && ${MAKE_CMD} autoloads

do-build-DOCS-on:
	cd ${WRKSRC} && SED=gsed ${MAKE_CMD} html

do-build-PDF-on:
	cd ${WRKSRC} && ${MAKE_CMD} pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${ELISP_FILES:C/^/${WRKSRC}\/lisp\//} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.org \
		${WRKSRC}/docs/ghub.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/ghub.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
