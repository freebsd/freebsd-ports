# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	madfufw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/usb-midi-fw/madfu-firmware/1.2/
DISTNAME=	madfuload-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	M-Audio DFU Firmware for Transit, Ozone, Sonica, MobilePre

RUN_DEPENDS=	${LOCALBASE}/bin/dfu-util:comms/dfu-util

WRKSRC=		${WRKDIR}/madfuload-1.2
PLIST_FILES=	share/maudio/ma003101.bin \
		share/maudio/ma004103.bin \
		share/maudio/ma005101.bin \
		share/maudio/ma006100.bin \
		share/maudio/ma008100.bin \
		etc/devd/maudio-devd.conf
USE_RC_SUBR=	maudio
SUB_FILES=	maudio-devd.conf pkg-message
NO_BUILD=	yes
NO_PACKAGE=	redistribution of firmware files not permitted

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/maudio
	${INSTALL_DATA} ${WRKSRC}/ma003101.bin ${WRKSRC}/ma004103.bin \
		${WRKSRC}/ma005101.bin ${WRKSRC}/ma006100.bin \
		${WRKSRC}/ma008100.bin ${STAGEDIR}${PREFIX}/share/maudio
	${INSTALL_DATA} ${WRKDIR}/maudio-devd.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
