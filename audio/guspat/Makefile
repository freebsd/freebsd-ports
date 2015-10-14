# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	guspat
PORTVERSION=	20000706
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://plamo.linet.gr.jp/pub/Plamo-src/contrib/Sound/timidity/ \
		LOCAL/nork
DISTFILES=	${DISTNAME}-required${EXTRACT_SUFX} \
		${DISTNAME}-optional${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Izumo collection of Gravis Ultrasound MIDI patches

NO_BUILD=	yes
NO_ARCH=	yes
NO_CDROM=	Some of the patches are marked no-commercial-use
PLIST_SUB=	TIMIDITY_DATADIR=${TIMIDITY_DATADIR}
WRKSRC=		${WRKDIR}/timidity

TIMIDITY_DATADIR=	share/timidity

post-patch:
	@${REINPLACE_CMD} -e 's|/timidity|/guspat|g' ${WRKSRC}/timidity.cfg
	@${RM} ${WRKSRC}/timidity.cfg.bak

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIMIDITY_DATADIR}
	${INSTALL_DATA} ${WRKSRC}/timidity.cfg \
		${STAGEDIR}${PREFIX}/${TIMIDITY_DATADIR}/timidity.cfg-guspat

.include <bsd.port.mk>
