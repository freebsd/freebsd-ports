# New ports collection makefile for: 	emacs-chess
# Date created:				05 March 2003
# Whom:				 	Steffen Mazanek
#
# $FreeBSD$
#

PORTNAME=		emacs-chess
PORTVERSION=		2.0b3
PORTREVISION=	1
CATEGORIES=		games elisp
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	emacs-chess
DISTFILES=		chess-2.0b3.tar.bz2 \
			sounds.tar.bz2 \
			pieces.tar.bz2

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Play chess with emacs

RUN_DEPENDS=		gnuchess:${PORTSDIR}/games/gnuchess

EMACS_PORT_NAME=	emacs21
USE_BZIP2=		yes
PLIST_SUB=		EMACS-CHESS-DIR=${EMACS_VERSION_SITE_LISPDIR}
USE_GMAKE=		yes
WRKSRC=			${WRKDIR}/chess-${PORTVERSION}
LISPDIR=		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

pre-build:
	@(cd ${WRKSRC} && ${RM} -f *.elc)
do-install:
	@(mkdir ${LISPDIR}/${PORTNAME} || ${ECHO} "directory exists")
	${CP} ${WRKSRC}/*.elc ${LISPDIR}/${PORTNAME}
	${CP} -r ${WRKDIR}/sounds ${LISPDIR}/${PORTNAME}
	${CP} -r ${WRKDIR}/pieces ${LISPDIR}/${PORTNAME}

.include <bsd.port.mk>
