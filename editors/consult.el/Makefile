PORTNAME=	consult.el
DISTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Consulting completing-read
WWW=		https://github.com/minad/consult

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	minad
GH_PROJECT=	consult

NO_ARCH=	yes

ELISP_FILES=	${WRKSRC}/*.el

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} -q --batch -L ${WRKSRC} -f batch-byte-compile ${ELISP_FILES}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/consult
	${INSTALL_DATA} ${ELISP_FILES} ${ELISP_FILES:S/.el$$/.elc/} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/consult

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
