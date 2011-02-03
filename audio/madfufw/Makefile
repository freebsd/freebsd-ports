# New ports collection makefile for:   madfufw
# Date created:                July 6, 2010
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	madfufw
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	SF/usb-midi-fw/madfu-firmware/1.2/
DISTNAME=	madfuload-1.2

MAINTAINER=	aragon@phat.za.net
COMMENT=	M-Audio DFU Firmware for Transit, Ozone, Sonica, MobilePre

RUN_DEPENDS=	${LOCALBASE}/bin/dfu-util:${PORTSDIR}/comms/dfu-util

WRKSRC=		${WRKDIR}/madfuload-1.2
PLIST_FILES=	share/maudio/ma003101.bin \
		share/maudio/ma004103.bin \
		share/maudio/ma005101.bin \
		share/maudio/ma006100.bin \
		share/maudio/ma008100.bin \
		etc/devd/maudio-devd.conf
PLIST_DIRS=	share/maudio
USE_RC_SUBR=	maudio
SUB_FILES=	maudio-devd.conf pkg-message
NO_BUILD=	yes
NO_PACKAGE=	redistribution of firmware files not permitted

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800064
BROKEN=		port requires FreeBSD 8.x
.endif

do-install:
	@${MKDIR} ${LOCALBASE}/share/maudio && \
	${INSTALL_DATA} ${WRKSRC}/ma003101.bin ${WRKSRC}/ma004103.bin \
		${WRKSRC}/ma005101.bin ${WRKSRC}/ma006100.bin \
		${WRKSRC}/ma008100.bin ${LOCALBASE}/share/maudio
	@${INSTALL_DATA} ${WRKDIR}/maudio-devd.conf ${LOCALBASE}/etc/devd

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
