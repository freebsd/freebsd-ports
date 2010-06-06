# New ports collection makefile for:	waon
# Date created:				8 October 2007
# Whom:					Kengo Ichiki <kichiki@users.sourceforge.net>
#
# $FreeBSD$
#

PORTNAME=	waon
PORTVERSION=	0.9
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kichiki@users.sourceforge.net
COMMENT=	A Wave-to-Notes transcriber and some utility tools

LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3 \
		ao.4:${PORTSDIR}/audio/libao \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GNOME=	gtk20

MAN1=		waon.1 pv.1 gwaon.1
PLIST_FILES=	bin/waon bin/pv bin/gwaon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waon  ${PREFIX}/bin/waon
	${INSTALL_PROGRAM} ${WRKSRC}/pv    ${PREFIX}/bin/pv
	${INSTALL_PROGRAM} ${WRKSRC}/gwaon ${PREFIX}/bin/gwaon
	${INSTALL_MAN} ${WRKSRC}/waon.1  ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pv.1    ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gwaon.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
