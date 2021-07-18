PORTNAME=	forge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1-7
DISTVERSIONSUFFIX=	-g84ef3a7
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Work with Git forges from the comfort of Magit (Development Version)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	closql${EMACS_PKGNAMESUFFIX}>=1.0.0:databases/closql@${EMACS_FLAVOR} \
		magit-devel${EMACS_PKGNAMESUFFIX}>=2.90.1:devel/magit-devel@${EMACS_FLAVOR} \
		markdown-mode.el${EMACS_PKGNAMESUFFIX}>=2.3:textproc/markdown-mode.el@${EMACS_FLAVOR} \
		yaml.el${EMACS_PKGNAMESUFFIX}>=0.3.3:textproc/yaml.el@${EMACS_FLAVOR}
RUN_DEPENDS=	closql${EMACS_PKGNAMESUFFIX}>=1.0.0:databases/closql@${EMACS_FLAVOR} \
		magit-devel${EMACS_PKGNAMESUFFIX}>=2.90.1:devel/magit-devel@${EMACS_FLAVOR} \
		markdown-mode.el${EMACS_PKGNAMESUFFIX}>=2.3:textproc/markdown-mode.el@${EMACS_FLAVOR} \
		yaml.el${EMACS_PKGNAMESUFFIX}>=0.3.3:textproc/yaml.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ENV+=	INSTALL_INFO=install-info \
		LOAD_PATH="${_LOAD_PATH}"
ALL_TARGET=	lisp info

CONFLICTS=	forge-emacs*

INFO=		forge
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

_LOAD_PATH=	-L ${PREFIX}/${EMACS_SITE_LISPDIR} -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/closql -L \
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
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
