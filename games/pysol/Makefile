# New ports collection makefile for:    PySol
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol
PORTVERSION=	4.41
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS_DISTFILE} \
		${MUSIC_DISTFILE}

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${SOUND_DEPENDS}

NO_BUILD=	yes
PLIST=		${WRKDIR}/PLIST

CARDSETS=	pysol-cardsets-4.20
MUSIC=		pysol-music-4.30

.if !defined(WITHOUT_CARDSETS)
CARDSETS_DISTFILE=${CARDSETS}${EXTRACT_SUFX}
PLISTS+=	${PKGDIR}/PLIST.cardsets
.else
CARDSETS_DISTFILE=
.endif

.if defined(WITH_SOUND)
SOUND_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/pysolsoundservermodule.so:${PORTSDIR}/audio/pysol-sound-server
MUSIC_DISTFILE=	${MUSIC}${EXTRACT_SUFX}
PLISTS+=	${PKGDIR}/PLIST.music
.else
SOUND_DEPENDS=
MISIC_DISTFILE=
.endif

PLISTS+=	${PKGDIR}/PLIST

MAN6=		pysol.6

.if !defined(WITHOUT_CARDSETS)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you do not want to download/install optional cardsets (12MB) please use"
	@${ECHO_MSG} "\"make -DWITHOUT_CARDSETS\" instead."
	@${ECHO_MSG}
.endif

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
.if !defined(WITHOUT_CARDSETS)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
.endif
.if defined(WITH_SOUND)
	(cd ${WRKDIR}/${MUSIC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
.endif
	@cat ${PLISTS} > ${PLIST}

.include <bsd.port.mk>
