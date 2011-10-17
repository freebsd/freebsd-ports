# New ports collection makefile for:   paredit-mode.el
# Date created:		05 Aug 2010
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paredit-mode.el
PORTVERSION=	21
PORTREVISION=	4
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni
DISTNAME=	paredit-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minor mode for performing editing of S-expression data

USE_EMACS=	yes

NO_BUILD=	yes

PLIST_FILES=	%%EMACS_SITE_LISPDIR%%/paredit.el

do-install:
	@${INSTALL_DATA} ${WRKSRC}/paredit.el ${PREFIX}/${EMACS_SITE_LISPDIR}/paredit.el

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
