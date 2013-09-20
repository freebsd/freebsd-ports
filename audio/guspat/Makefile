# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	guspat
PORTVERSION=	20000706
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://plamo.linet.gr.jp/pub/Plamo-src/contrib/Sound/timidity/ \
		RINGSERVER/linux/Plamo/Plamo-src/contrib/Sound/timidity \
		LOCAL/nork
DISTFILES=	${PORTNAME}-${PORTVERSION}-required${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-optional${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Izumo collection of Gravis Ultrasound MIDI patches

# Not useful without timidity.
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity++

NO_CDROM=	Some of the patches are marked no-commercial-use

NO_BUILD=	yes
NO_STAGE=	yes

WRKSRC=		${WRKDIR}/timidity
PLIST_SUB=	TIMIDITY_DATADIR=${TIMIDITY_DATADIR}

TIMIDITY_DATADIR=	share/timidity

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	@${MKDIR} ${PREFIX}/${TIMIDITY_DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} timidity.cfg \
		${PREFIX}/${TIMIDITY_DATADIR}/timidity.cfg-guspat

.include <bsd.port.mk>
