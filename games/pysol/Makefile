# New ports collection makefile for:    PySol
# Version required:     2.13
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1999/04/21 16:39:38 mharo Exp $
#

DISTNAME=       pysol-2.13
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

CARDSETS=	pysol-cardsets-2.11

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysol.py ${PREFIX}/bin/pysol
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
