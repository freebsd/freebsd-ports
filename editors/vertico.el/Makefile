PORTNAME=	vertico.el
DISTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	VERTical Interactive COmpletion for Emacs
WWW=		https://github.com/minad/vertico

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	vertico

NO_ARCH=	yes

ELISP_FILES=	${WRKSRC}/*.el ${WRKSRC}/extensions/*.el

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} -q --batch -L ${WRKSRC} -L ${WRKSRC}/extensions \
		-f batch-byte-compile ${ELISP_FILES}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vertico
	${INSTALL_DATA} ${ELISP_FILES} ${ELISP_FILES:S/.el$$/.elc/} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vertico

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
