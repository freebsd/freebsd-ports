# New ports collection makefile for:    tksol
# Date created:         26 June 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tksol
PORTVERSION=	1.8.4
CATEGORIES=	games tk84
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/solitaires
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A version of the card game solitaire

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_REINPLACE=	yes

MAN6=		tksol.6

post-patch:
	@${REINPLACE_CMD} -e 's|exec wish|exec ${PREFIX}/bin/wish8.4|g ; \
		 s|/usr/local/lib/tksol|${DATADIR}|g' ${WRKSRC}/tksol

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
