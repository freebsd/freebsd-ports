# New ports collection makefile for:	LEIM for emacs20
# Date created:		10 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leim
PORTVERSION=	20.7
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	shige@FreeBSD.org
COMMENT=	Libraries of (GNU) Emacs Input Method

LATEST_LINK=	leim20

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

USE_GMAKE=	yes
EMACS_VER=	20.7
WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}/leim
PLIST_SUB=	EMACS_VER=${EMACS_VER}
SCRIPTS_ENV=	EMACS_VER=${EMACS_VER}

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}/leim

.include <bsd.port.mk>
