PORTNAME=	treepy.el
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Generic tree traversing tools for Emacs Lisp

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	volrath

NO_ARCH=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/treepy.el \
		${EMACS_VERSION_SITE_LISPDIR}/treepy.elc

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

do-build:
	(cd ${WRKSRC} ; ${EMACS_CMD} -batch -q -f batch-byte-compile treepy.el)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/treepy.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
