PORTNAME=	transient
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Emacs key and popup interface for complex keybindings
WWW=		https://github.com/magit/transient

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}
RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ENV+=	LOAD_PATH="-L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat"
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lisp info

CONFLICTS_INSTALL=	transient-devel-emacs*

NO_ARCH=	yes

INFO=		transient

PORTDOCS=	CHANGELOG README.org transient.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf
PDF_PLIST_FILES=	${DOCSDIR}/transient.pdf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${WRKSRC}/CHANGELOG \
		${WRKSRC}/docs/transient.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/transient.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
