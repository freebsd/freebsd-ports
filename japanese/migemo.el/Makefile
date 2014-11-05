# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	migemo.el
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	japanese elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Japanese incremental search tool for Emacs

LICENSE=	GPLv2

USE_EMACS=	yes
USE_GITHUB=	yes

RUN_DEPENDS=	cmigemo:${PORTSDIR}/japanese/cmigemo

GH_ACCOUNT=	emacs-jp
GH_PROJECT=	migemo
GH_TAGNAME=	38f4756abaa5d0f363126b85c873f1e1b08b50ee
GH_COMMIT=	38f4756

CONFLICTS=	ja-migemo-emacs24-[0-9]*

NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/migemo.el
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTINOS_DEFAULT=	DOCS

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
