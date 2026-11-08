PORTNAME=	f.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Modern API for working with files and directories in Emacs Lisp
WWW=		https://github.com/rejeep/f.el

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dash.el>=2.2.0:devel/dash.el \
		s.el>=1.7.0:devel/s.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	rejeep

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${ELISP_FILES:S|^|${ELISPDIR}/|}
PORTDOCS=	CHANGELOG.org README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	f-shortdoc.el f.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${ELISP_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
