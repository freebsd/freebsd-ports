# New ports collection makefile for:    PySol
# Version required:     1.10
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/10/07 08:03:03 tg Exp $
#

DISTNAME=       pysol-1.10
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

BROKEN=		fetch

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysol.py ${PREFIX}/bin/pysol
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
