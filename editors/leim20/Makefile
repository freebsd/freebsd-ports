# New ports collection makefile for:	LEIM for emacs20
# Version required:	20.3
# Date created:		10 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.2 1999/01/27 07:41:11 fenner Exp $
#

DISTNAME=	leim-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	shige@FreeBSD.ORG

BUILD_DEPENDS=	emacs-20.3:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs-20.3:${PORTSDIR}/editors/emacs20

USE_GMAKE=	yes

EMACS_VER=	20.3
WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}/leim
PLIST_SUB=	EMACS_VER=${EMACS_VER}
SCRIPTS_ENV=	EMACS_VER=${EMACS_VER}

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}/leim

.include <bsd.port.mk>
