PORTNAME=	marginalia.el
DISTVERSION=	2.9
CATEGORIES=	editors elisp

MAINTAINER=	pat@patmaddox.com
COMMENT=	Marginalia in the Emacs minibuffer
WWW=		https://github.com/minad/marginalia

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	marginalia

CONFLICTS_INSTALL=	marginalia.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/marginalia.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
