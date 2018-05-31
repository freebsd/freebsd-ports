# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	migemo.el
PORTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	japanese elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Japanese incremental search tool for Emacs

LICENSE=	GPLv2

RUN_DEPENDS=	cmigemo:japanese/cmigemo

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-jp
GH_PROJECT=	migemo

CONFLICTS=	ja-migemo-emacs
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/migemo.el
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
