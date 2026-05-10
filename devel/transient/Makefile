PORTNAME=	transient
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.3
CATEGORIES=	devel elisp

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Emacs key and popup interface for complex keybindings
WWW=		https://github.com/magit/transient

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

_BR_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		cond-let>=0.2:devel/cond-let
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	magit

CONFLICTS_INSTALL=	transient-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${ELISPDIR}/transient-autoloads.el \
		${ELISPDIR}/transient.el
PORTDOCS=	CHANGELOG README.org transient.html

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

OPTIONS_DEFINE=		DOCS INFO PDF
OPTIONS_DEFAULT=	INFO

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_USES=		makeinfo

INFO_BUILD_DEPENDS=	gsed:textproc/gsed
INFO_INFO=		transient

PDF_BUILD_DEPENDS=	gsed:textproc/gsed \
			texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_PLIST_FILES=	${DOCSDIR}/transient.pdf

do-build:
	cd ${WRKSRC}/lisp && ${MAKE_CMD} autoloads

do-build-DOCS-on:
	cd ${WRKSRC}/docs && SED=gsed ${MAKE_CMD} html

do-build-INFO-on:
	cd ${WRKSRC} && SED=gsed ${MAKE_CMD} info

do-build-PDF-on:
	cd ${WRKSRC}/docs && SED=gsed ${MAKE_CMD} pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${WRKSRC}/CHANGELOG \
		${WRKSRC}/docs/transient.html ${STAGEDIR}${DOCSDIR}

do-install-INFO-on:
	${INSTALL_DATA} ${WRKSRC}/docs/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/transient.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
