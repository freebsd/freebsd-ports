# New ports collection makefile for:    PySol
# Version required:     2.01
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1998/12/01 07:16:24 tg Exp $
#

DISTNAME=       pysol-2.01
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/ \
		http://www.freebsd.org/~tg/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

CARDSETS=	pysol-cardsets-2.0

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysol.py ${PREFIX}/bin/pysol
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
