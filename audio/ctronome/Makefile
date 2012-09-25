# Created by: Charles Mercadal <mercadal@diablonet.net>
# $FreeBSD$

PORTNAME=	ctronome
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ctronome.kign.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A programmable console-based metronome

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/ctronome.h ${WRKSRC}/dsp.c
	@${REINPLACE_CMD} -e 's|/usr/share/ctronome|${DATADIR}|' ${WRKSRC}/ctronome.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctronome ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome1.wav ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome2.wav ${DATADIR}

.include <bsd.port.mk>
