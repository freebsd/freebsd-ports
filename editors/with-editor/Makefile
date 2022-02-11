# Created by: KIMURA Yasuhiro <yasu@utahime.org>

PORTNAME=	with-editor
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Use the Emacsclient as the $$EDITOR of child processes

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	lisp info

NO_ARCH=	yes

INFO=		with-editor
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/with-editor-autoloads.el \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor.el \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor.elc
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
