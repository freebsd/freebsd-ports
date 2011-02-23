# New ports collection makefile for:	libnfc
# Date created:		2009-06-17
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	libnfc
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
    		http://romain.blogreen.org/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Near Field Communication (NFC) library

OPTIONS=	ACR122      "Enable ACR122 driver"     on \
		ARYGON      "Enable Arygon driver"     off \
		PN531USB    "Enable PN531 USB driver"  on \
		PN532UART   "Enable PN532 UART driver" on \
		PN533USB    "Enable PN533 USB driver"  on \
		SERIALPROBE "Enable serial auto-probe" off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

MAN1=		nfc-anticol.1 nfc-dep-initiator.1 nfc-dep-target.1 \
		nfc-emulate-forum-tag4.1 nfc-emulate-tag.1 nfc-emulate-uid.1 \
		nfc-mfclassic.1 nfc-list.1 nfc-mfultralight.1 nfc-poll.1 \
		nfc-relay.1 nfc-relay-picc.1 pn53x-diagnose.1 pn53x-sam.1 \
		pn53x-tamashell.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ACR122)
ACR122_DRIVER=	acr122,
.else
ACR122_DRIVER=
.endif

.if defined(WITH_ARYGON)
ARYGON_DRIVER=	arygon,
.else
ARYGON_DRIVER=
.endif

.if !defined(WITHOUT_PN531USB)
PN531USB_DRIVER=pn531_usb,
.else
PN531USB_DRIVER=
.endif

.if !defined(WITHOUT_PN532UART)
PN532UART_DRIVER=pn532_uart,
.else
PN532UART_DRIVER=
.endif

.if !defined(WITHOUT_PN533USB)
PN533USB_DRIVER=pn533_usb,
.else
PN533USB_DRIVER=
.endif

CONFIGURE_ARGS+=--with-drivers="${ACR122_DRIVER}${ARYGON_DRIVER}${PN531USB_DRIVER}${PN532UART_DRIVER}${PN533USB_DRIVER}"

.if defined(WITH_SERIALPROBE)
CONFIGURE_ARGS+=--enable-serial-autoprobe
.else
CONFIGURE_ARGS+=--disable-serial-autoprobe
.endif

.if defined(WITH_ACR122)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS+=	RSA_SecurID_getpasswd:${PORTSDIR}/devel/libccid
.endif

.if defined(WITH_PN531USB) || defined(WITH_PN533USB)
.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
.endif
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pn53x.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
