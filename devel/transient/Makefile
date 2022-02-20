PORTNAME=	transient
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
PORTREVISION=	2
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Emacs key and popup interface for complex keybindings

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	lisp info

NO_ARCH=	yes

INFO=		transient

PORTDOCS=	CHANGELOG README.md transient.html

OPTIONS_DEFINE=	DOCS PDF

PDF_DESC=	Build and install PDF document

DOCS_BUILD_DEPENDS=	gsed:textproc/gsed
DOCS_ALL_TARGET=	html
DOCS_BINARY_ALIAS=	sed=gsed
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
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
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/docs/CHANGELOG \
		${WRKSRC}/docs/transient.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/transient.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
