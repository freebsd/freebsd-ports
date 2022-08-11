PORTNAME=	bluez-firmware
PORTVERSION=	1.2
CATEGORIES=	comms kld
MASTER_SITES=	http://bluez.sourceforge.net/download/

MAINTAINER=	dirkx@webweaving.org
COMMENT=	Firmware for the D-Link BCM2033 bluetooth adaptor for use by bcmfw(1)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
