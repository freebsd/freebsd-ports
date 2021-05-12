PORTNAME=	qmidinet
DISTVERSION=	0.9.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI network gateway application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		core gui network widgets buildtools_build qmake_build

CMAKE_OFF=	CONFIG_ALSA_MIDI # libalsa doesn't have MIDI functionality on FreeBSD

.include <bsd.port.mk>
