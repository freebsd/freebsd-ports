# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	migemo.el
PORTVERSION=	1.9.1
CATEGORIES=	japanese elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Japanese incremental search tool for Emacs

LICENSE=	GPLv2

USE_EMACS=	yes
USE_GITHUB=	yes

RUN_DEPENDS=	cmigemo:japanese/cmigemo

GH_ACCOUNT=	emacs-jp
GH_PROJECT=	migemo
GH_TAGNAME=	97e0779

CONFLICTS=	ja-migemo-emacs24-[0-9]*

NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/migemo.el
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTINOS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
