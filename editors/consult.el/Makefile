PORTNAME=	consult.el
DISTVERSION=	3.3
CATEGORIES=	editors elisp

MAINTAINER=	pat@patmaddox.com
COMMENT=	Consulting completing-read
WWW=		https://github.com/minad/consult

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	consult

CONFLICTS_INSTALL=	consult.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

ELISP_FILES=	${WRKSRC}/*.el

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/consult
	${INSTALL_DATA} ${ELISP_FILES} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/consult

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
