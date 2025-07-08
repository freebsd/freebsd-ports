PORTNAME=	ghub
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.2
DISTVERSIONSUFFIX=
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Client libraries for the APIs of various Git forges
WWW=		https://github.com/magit/ghub

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use devel/ghub instead
EXPIRATION_DATE=	2025-08-31

BUILD_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR} \
		llama.el${EMACS_PKGNAMESUFFIX}>=0.6.3:devel/llama.el@${EMACS_FLAVOR} \
		treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.2:devel/treepy.el@${EMACS_FLAVOR}
RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR} \
		llama.el${EMACS_PKGNAMESUFFIX}>=0.6.3:devel/llama.el@${EMACS_FLAVOR} \
		treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.2:devel/treepy.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ARGS=	LOAD_PATH=" -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat -L ."
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lisp info

CONFLICTS_INSTALL=	ghub-emacs*

NO_ARCH=	yes

INFO=		ghub
PORTDOCS=	CHANGELOG README.org ghub.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf
PDF_PLIST_FILES=	${DOCSDIR}/ghub.pdf

ELISP_FILES=	buck.el buck.elc ghub-autoloads.el ghub-graphql.el \
		ghub-graphql.elc ghub.el ghub.elc glab.el glab.elc gogs.el \
		gogs.elc gsexp.el gsexp.elc gtea.el gtea.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${ELISP_FILES:C/^/${WRKSRC}\/lisp\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.org \
		${WRKSRC}/docs/ghub.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/ghub.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
