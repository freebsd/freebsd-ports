# New ports collection makefile for:    PySol
# Version required:     2.14
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=       pysol-2.14
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

CARDSETS=	pysol-cardsets-2.14

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysol.py ${PREFIX}/bin/pysol
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
