# New ports collection makefile for:    PySol
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol
PORTVERSION=	4.40
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

.if defined(WITH_SOUND)
RUN_DEPENDS+=	${LOCALBASE}/lib/python1.5/site-packages/pysolsoundservermodule.so:${PORTSDIR}/audio/pysol-sound-server
.endif

NO_BUILD=	yes

MAN6=	pysol.6

CARDSETS=	pysol-cardsets-4.20

.if !defined(WITH_SOUND)
post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want install sound support please use \"make -DWITH_SOUND\""
	@${ECHO_MSG}
.endif

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
