# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	eawplus
PORTVERSION=	12.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/nork

MAINTAINER=	ports@FreeBSD.org
COMMENT=	E.A.W.+Izumo+Tamuki collection of Gravis Ultrasound MIDI patches

# Not useful without timidity.
RUN_DEPENDS=	${LOCALBASE}/share/eawpats/acbass.pat:audio/eawpats \
		${LOCALBASE}/share/guspat/inst/GUS/acbass.pat:audio/guspat

NO_CDROM=	Some of the patches are marked no-commercial-use

NO_WRKSUBDIR=	yes

TIMIDITY_DATADIR=	share/timidity
PLIST_SUB=	TIMIDITY_DATADIR=${TIMIDITY_DATADIR}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -f ${WRKSRC}/timidity/inst/GUS/power/h-hihatp.pat.orig
	@${RM} -f ${WRKSRC}/timidity/inst/GUS/power/h-snare.pat.orig

do-build:
	${SED}	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%TIMIDITY_DATADIR%%|${PREFIX}/${TIMIDITY_DATADIR}|g" \
		${FILESDIR}/timidity.cfg > ${WRKDIR}/timidity.cfg

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -pr ${WRKSRC}/timidity/* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIMIDITY_DATADIR}
	${INSTALL_DATA} ${WRKDIR}/timidity.cfg \
		${STAGEDIR}${PREFIX}/${TIMIDITY_DATADIR}/timidity.cfg-eawplus
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*/*.txt.gz ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
