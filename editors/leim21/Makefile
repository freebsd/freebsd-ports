# New ports collection makefile for:	LEIM for emacs21
# Date created:		10 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leim
PORTVERSION=	21.3
PORTREVISION=	5
CATEGORIES=	editors
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries of (GNU) Emacs Input Method

DEPRECATED=	Distfile is no more available
EXPIRATION_DATE=	2011-05-01

LATEST_LINK=	leim21

USE_EMACS=		yes
EMACS_PORT_NAME=	emacs21

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}/leim
PLIST_SUB=	EMACS_VER=${EMACS_VER}
SCRIPTS_ENV=	EMACS_VER=${EMACS_VER}

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}/leim

.include <bsd.port.mk>
