# New ports collection makefile for:    PySol
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol
PORTVERSION=	4.81
CATEGORIES=	games
MASTER_SITES=	http://pysol2.sourceforge.net/download/ \
		http://www.oberhumer.com/opensource/pysol/download/

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_BZIP2=	yes
USE_PYTHON=	yes

NO_BUILD=	yes

MAN6=		pysol.6

do-install:
	${SED}	-e "s|@pkgdatadir@|${PREFIX}/share/pysol|" \
		-e "s|@prefix@|${PREFIX}|" \
		-e "s|@PYTHON@|${PYTHON_CMD}|" \
		< ${WRKSRC}/pysol > ${WRKDIR}/pysol
	${INSTALL_SCRIPT} ${WRKDIR}/pysol ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar -cf - .) | \
		(cd ${PREFIX}/share/pysol; tar --unlink -xf -)

.include <bsd.port.mk>
