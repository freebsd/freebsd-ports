PORTNAME=	perspective.el
DISTVERSION=	2.20
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Perspectives for Emacs
WWW=		https://github.com/nex3/perspective-el

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		emacs

USE_GITHUB=	yes
GH_ACCOUNT=	nex3
GH_PROJECT=	perspective-el

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} -q --batch -f batch-byte-compile ${WRKSRC}/perspective.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/perspective.el ${WRKSRC}/perspective.elc \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
