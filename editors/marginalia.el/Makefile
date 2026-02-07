PORTNAME=	marginalia.el
DISTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Marginalia in the Emacs minibuffer
WWW=		https://github.com/minad/marginalia

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	marginalia

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} -q --batch -f batch-byte-compile ${WRKSRC}/marginalia.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/marginalia.el ${WRKSRC}/marginalia.elc \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
