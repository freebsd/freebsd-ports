# New ports collection makefile for:	waon
# Date created:				8 October 2007
# Whom:					Kengo Ichiki <kichiki@users.sourceforge.net>
#
# $FreeBSD$
#

PORTNAME=	waon
PORTVERSION=	0.8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kichiki@users.sourceforge.net
COMMENT=	A Wave-to-Notes transcriber and some utility tools

LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3 \
		ao.3:${PORTSDIR}/audio/libao \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GNOME=	gtk20

PLIST_FILES=	bin/waon bin/pv bin/gwaon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waon  ${PREFIX}/bin/waon
	${INSTALL_PROGRAM} ${WRKSRC}/pv    ${PREFIX}/bin/pv
	${INSTALL_PROGRAM} ${WRKSRC}/gwaon ${PREFIX}/bin/gwaon

.include <bsd.port.mk>
