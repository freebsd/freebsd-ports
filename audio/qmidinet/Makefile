# $FreeBSD$

PORTNAME=	qmidinet
PORTVERSION=	0.2.0
CATEGORIES=	audio net
MASTER_SITES=	SF

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sends and receives MIDI over the network using UDP multicast

LICENSE=	GPLv2

BROKEN=		Fails to configure
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-01-26

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

# Perfectly compatible with qt5 as well; just needs a configure fiddle, and
# edit the patchfiles for configure.ac
USE_QT4=	gui
USE_AUTOTOOLS=	autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa-midi
INSTALLS_ICONS=	yes

post-patch:
# What is 'export' doing in a Makefile???
	${REINPLACE_CMD} 's,^export ,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
