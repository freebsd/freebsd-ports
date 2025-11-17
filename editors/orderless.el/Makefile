PORTNAME=	orderless.el
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Emacs completion style that matches multiple regexps in any order
WWW=		https://github.com/oantolin/orderless

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	oantolin
GH_PROJECT=	orderless

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} -q --batch -L ${WRKSRC} -f batch-byte-compile ${WRKSRC}/*.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
