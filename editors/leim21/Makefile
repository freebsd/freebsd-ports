# New ports collection makefile for:	LEIM for emacs21
# Date created:		10 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leim
PORTVERSION=	21.3
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries of (GNU) Emacs Input Method

LATEST_LINK=	leim21

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs

USE_GMAKE=	yes
EMACS_VER=	21.3
WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}/leim
PLIST_SUB=	EMACS_VER=${EMACS_VER}
SCRIPTS_ENV=	EMACS_VER=${EMACS_VER}

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}/leim

.include <bsd.port.mk>
