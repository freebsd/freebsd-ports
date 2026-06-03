PORTNAME=	orderless.el
DISTVERSION=	1.6
CATEGORIES=	editors elisp

MAINTAINER=	pat@patmaddox.com
COMMENT=	Emacs completion style that matches multiple regexps in any order
WWW=		https://github.com/oantolin/orderless

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	oantolin
GH_PROJECT=	orderless

CONFLICTS_INSTALL=	orderless.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
