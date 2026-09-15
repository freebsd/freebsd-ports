PORTNAME=	mozc-modeless
DISTVERSION=	0.10.0
CATEGORIES=	japanese elisp

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Modeless Japanese input with Mozc for Emacs
WWW=		https://github.com/kiyoka/mozc-modeless-emacs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ja-mozc-el>0:japanese/mozc-el \
		markdown-mode.el>0:textproc/markdown-mode.el

USE_GITHUB=	yes
GH_ACCOUNT=	kiyoka
GH_PROJECT=	mozc-modeless-emacs

NO_ARCH=	yes
NO_BUILD=	yes

ELISPDIR=	share/emacs/site-lisp/${PORTNAME}
PLIST_FILES=	${ELISPDIR}/mozc-modeless-english-words.el \
		${ELISPDIR}/mozc-modeless.el
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${ELISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/docs/* \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
