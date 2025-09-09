PORTNAME=	cond-let
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Additional and improved binding conditionals in Emacs Lisp
WWW=		https://github.com/tarsius/cond-let

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tarsius

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/cond-let-autoloads.el \
		${EMACS_VERSION_SITE_LISPDIR}/cond-let.el \
		${EMACS_VERSION_SITE_LISPDIR}/cond-let.elc

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	cond-let-autoloads.el cond-let.el cond-let.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
