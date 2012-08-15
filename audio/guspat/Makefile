# New ports collection makefile for:	guspat
# Date created:				2004/07/04
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	guspat
PORTVERSION=	20000706
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.linet.gr.jp/~tamuki/timidity/eawplus/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
DISTFILES=	${PORTNAME}-${PORTVERSION}-required${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-optional${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Izumo collection of Gravis Ultrasound MIDI patches

# Not useful without timidity.
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity++

NO_CDROM=	Some of the patches are marked no-commercial-use

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/timidity
PLIST_SUB=	TIMIDITY_DATADIR=${TIMIDITY_DATADIR}

TIMIDITY_DATADIR=	share/timidity

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -pr ${WRKSRC}/* ${DATADIR}
	@${MKDIR} ${PREFIX}/${TIMIDITY_DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/timidity.cfg ${PREFIX}/${TIMIDITY_DATADIR}/timidity.cfg-guspat

.include <bsd.port.mk>
