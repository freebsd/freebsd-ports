# Created by: Charles Mercadal <mercadal@diablonet.net>
# $FreeBSD$

PORTNAME=	ctronome
PORTVERSION=	0.5.6
CATEGORIES=	audio
MASTER_SITES=	http://ctronome.kign.org/source/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Programmable console-based metronome

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/ctronome \
		%%DATADIR%%/metronome1.wav \
		%%DATADIR%%/metronome2.wav

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/ctronome.h ${WRKSRC}/dsp.c
	@${REINPLACE_CMD} -e 's|/usr/share/ctronome|${DATADIR}|' ${WRKSRC}/ctronome.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctronome ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome1.wav ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome2.wav ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
