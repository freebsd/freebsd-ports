# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	with-editor
PORTVERSION=	2.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Use the Emacsclient as the $$EDITOR of child processes

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

INFO=		with-editor
MAKE_ENV+=	EFLAGS="-L ${PREFIX}/${EMACS_SITE_LISPDIR}"
NO_ARCH=	yes
PORTDOCS=	README.md

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/with-editor.el \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor.elc \
		${EMACS_VERSION_SITE_LISPDIR}/with-editor-autoloads.el

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
