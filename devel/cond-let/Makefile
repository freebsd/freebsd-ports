PORTNAME=	cond-let
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Additional and improved binding conditionals in Emacs Lisp
WWW=		https://github.com/tarsius/cond-let

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tarsius

CONFLICTS_INSTALL=	cond-let-emacs_*

NO_ARCH=	yes
PLIST_FILES=	${ELISPDIR}/cond-let-autoloads.el \
		${ELISPDIR}/cond-let.el

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	cond-let-autoloads.el cond-let.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
