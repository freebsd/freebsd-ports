# New ports collection makefile for:   yasnippet
# Date created:		30 Jun 2010
# Whom:			olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yasnippet
PORTVERSION=	0.6.1c
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		yasnippet-doc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	YASnippet is a template system for Emacs

USE_BZIP2=	yes
USE_EMACS=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

post-patch:
	@${FIND} ${WRKSRC}/snippets -type d -empty | ${XARGS} ${RMDIR}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/dropdown-list.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	@${INSTALL_DATA} ${WRKSRC}/yasnippet.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} snippets ${DATADIR}
.if !defined(NOPORTDOCS)
	@cd ${WRKDIR}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
