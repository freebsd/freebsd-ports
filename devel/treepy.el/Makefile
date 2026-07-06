PORTNAME=	treepy.el
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Generic tree traversing tools for Emacs Lisp
WWW=		https://github.com/volrath/treepy.el

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	volrath

CONFLICTS_INSTALL=	treepy.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${ELISPDIR}/treepy.el

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	treepy.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
