# Created by: Charles Mercadal <mercadal@diablonet.net>
# $FreeBSD$

PORTNAME=	ctronome
PORTVERSION=	0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://ctronome.kign.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programmable console-based metronome

LICENSE=	GPLv2

NO_STAGE=	yes
PLIST_FILES=	bin/ctronome \
		%%DATADIR%%/metronome1.wav \
		%%DATADIR%%/metronome2.wav
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/ctronome.h ${WRKSRC}/dsp.c
	@${REINPLACE_CMD} -e 's|/usr/share/ctronome|${DATADIR}|' ${WRKSRC}/ctronome.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctronome ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome1.wav ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metronome2.wav ${DATADIR}

.include <bsd.port.mk>
