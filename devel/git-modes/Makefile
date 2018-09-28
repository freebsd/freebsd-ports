# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	git-modes
DISTVERSION=	1.2.8
PORTEPOCH=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	GNU Emacs modes for Git-related files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	magit
NO_ARCH=	yes
ALL_TARGET=	lisp

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS GIT_SUBVERSION

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB=	ELISPDIR=${ELISPDIR}
GIT_SUBVERSION_DESC=		Use devel/git-subversion as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git>0:devel/git

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
