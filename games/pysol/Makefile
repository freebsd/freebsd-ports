# New ports collection makefile for:    PySol
# Version required:     3.00
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       pysol-3.00
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

MAN6=	pysol.6

CARDSETS=	pysol-cardsets-3.00

do-install:
	${SED} -e "s|@pkgdatadir@|${PREFIX}/share/pysol|" < ${WRKSRC}/pysol > ${PREFIX}/bin/pysol
	${CHMOD} +x ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
