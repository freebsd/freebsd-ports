# New ports collection makefile for:    tksol
# Date created:         26 June 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tksol
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	games tk
MASTER_SITES=	SUNSITE/games/solitaires
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A version of the card game solitaire

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_TK_WRAPPER=	yes

MAN6=		tksol.6

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#/bin/sh|#!/bin/sh| ; \
		 s|/usr/local/lib/tksol|${DATADIR}|' ${WRKSRC}/tksol

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tksol ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${DATADIR}
.for dir in cardbacks cards pictures
	${TAR} -C ${WRKSRC} --exclude ".xvpics" -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.mk>
