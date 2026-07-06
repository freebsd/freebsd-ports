PORTNAME=	transient
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.5
CATEGORIES=	devel elisp
MASTER_SITES=	https://raw.githubusercontent.com/magit/magit.vc/${_ASSETS_VER}/assets/:assets
DISTFILES=	${_ASSETS:@.a.@${.a.}:assets@}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Emacs key and popup interface for complex keybindings
WWW=		https://github.com/magit/transient

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

_BR_DEPENDS=	compat.el>=31.0.0.0:misc/compat.el \
		cond-let>=1.0.0:devel/cond-let \
		llama.el>=1.0.0:devel/llama.el
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		emacs:build gmake

USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	autoloads

CONFLICTS_INSTALL=	transient-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${ELISPDIR}/transient-autoloads.el \
		${ELISPDIR}/transient.el
PORTDOCS=	CHANGELOG README.org transient.html ${_ASSETS:@.a.@assets/${.a.}@}

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

OPTIONS_DEFINE=		DOCS INFO PDF
OPTIONS_DEFAULT=	INFO

PDF_DESC=		Build and install PDF documentation

DOCS_USES=		makeinfo
DOCS_ALL_TARGET=	html

INFO_ALL_TARGET=	info
INFO_INFO=		transient

PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_ALL_TARGET=		pdf
PDF_PLIST_FILES=	${DOCSDIR}/transient.pdf

_ASSETS=	magit_alt1.ico \
		page.css \
		themes/black-on-white.css \
		themes/default-high-contrast.css \
		themes/default.css \
		themes/solarized-dark-xterm.css \
		js/simple-css-switch.js
_ASSETS_VER=	66bd1a1fa6a05e6905b556929516929d41b53784 # 2025-11-16

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/assets/js ${STAGEDIR}${DOCSDIR}/assets/themes
	${INSTALL_DATA} ${WRKSRC}/README.org ${WRKSRC}/CHANGELOG \
		${WRKSRC}/docs/transient.html ${STAGEDIR}${DOCSDIR}
.for a in ${_ASSETS}
	${INSTALL_DATA} ${_DISTDIR}/${a} ${STAGEDIR}${DOCSDIR}/assets/${a}
.endfor

do-install-INFO-on:
	${INSTALL_DATA} ${WRKSRC}/docs/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/transient.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
