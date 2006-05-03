# New ports collection makefile for:	eawplus
# Date created:				2004/07/04
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eawplus
PORTVERSION=	12.1
CATEGORIES=	audio
MASTER_SITES=	http://www.linet.gr.jp/~tamuki/timidity/eawplus/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	E.A.W.+Izumo+Tamuki collection of Gravis Ultrasound MIDI patches

# Not useful without timidity.
RUN_DEPENDS=	${LOCALBASE}/share/eawpats/acbass.pat:${PORTSDIR}/audio/eawpats \
		${LOCALBASE}/share/guspat/inst/GUS/acbass.pat:${PORTSDIR}/audio/guspat

RESTRICTED=	Some of the patches are marked no-commercial-use

NO_WRKSUBDIR=	yes

TIMIDITY_DATADIR=	share/timidity
PLIST_SUB=	TIMIDITY_DATADIR=${TIMIDITY_DATADIR}

post-extract:
	@${RM} -f ${WRKSRC}/timidity/inst/GUS/power/h-hihatp.pat.orig
	@${RM} -f ${WRKSRC}/timidity/inst/GUS/power/h-snare.pat.orig

do-build:
	${SED}	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%TIMIDITY_DATADIR%%|${PREFIX}/${TIMIDITY_DATADIR}|g" \
		${FILESDIR}/timidity.cfg > ${WRKDIR}/timidity.cfg

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -pr ${WRKSRC}/timidity/* ${DATADIR}
	@${MKDIR} ${PREFIX}/${TIMIDITY_DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/timidity.cfg \
			${PREFIX}/${TIMIDITY_DATADIR}/timidity.cfg-eawplus
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/doc/*/*.txt.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
