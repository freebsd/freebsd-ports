# New ports collection makefile for:	LEIM for emacs20
# Version required:	20.6
# Date created:		10 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	leim-20.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	shige@FreeBSD.org

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

USE_GMAKE=	yes
EMACS_VER=	20.6
WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}/leim
PLIST_SUB=	EMACS_VER=${EMACS_VER}
SCRIPTS_ENV=	EMACS_VER=${EMACS_VER}

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}/leim

.include <bsd.port.mk>
