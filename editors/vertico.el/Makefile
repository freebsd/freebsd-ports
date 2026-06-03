PORTNAME=	vertico.el
DISTVERSION=	2.7
CATEGORIES=	editors elisp

MAINTAINER=	pat@patmaddox.com
COMMENT=	VERTical Interactive COmpletion for Emacs
WWW=		https://github.com/minad/vertico

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	vertico

CONFLICTS_INSTALL=	vertico.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

ELISP_FILES=	${WRKSRC}/*.el ${WRKSRC}/extensions/*.el

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vertico
	${INSTALL_DATA} ${ELISP_FILES} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vertico

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
