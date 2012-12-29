# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	libnfc
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
		http://romain.blogreen.org/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Near Field Communication (NFC) library

OPTIONS_DEFINE=	ACR122 ARYGON PN531USB PN532UART PN533USB SERIALPROBE
OPTIONS_DEFAULT=	ACR122 PN531USB PN532UART PN533USB
ACR122_DESC=	ACR122 driver
ARYGON_DESC=	Arygon driver
PN531USB_DESC=	PN531 USB driver
PN532UART_DESC=	PN532 UART driver
PN533USB_DESC=	PN533 USB driver
SERIALPROBE_DESC=	serial auto-probe

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

MAN1=		nfc-anticol.1 nfc-dep-initiator.1 nfc-dep-target.1 \
		nfc-emulate-forum-tag4.1 nfc-emulate-tag.1 nfc-emulate-uid.1 \
		nfc-mfclassic.1 nfc-list.1 nfc-mfultralight.1 nfc-poll.1 \
		nfc-relay.1 nfc-relay-picc.1 pn53x-diagnose.1 pn53x-sam.1 \
		pn53x-tamashell.1

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACR122}
ACR122_DRIVER=	acr122,
.else
ACR122_DRIVER=
.endif

.if ${PORT_OPTIONS:MARYGON}
ARYGON_DRIVER=	arygon,
.else
ARYGON_DRIVER=
.endif

.if ${PORT_OPTIONS:MPN531USB}
PN531USB_DRIVER=pn531_usb,
.else
PN531USB_DRIVER=
.endif

.if ${PORT_OPTIONS:MP532UART}
PN532UART_DRIVER=pn532_uart,
.else
PN532UART_DRIVER=
.endif

.if ${PORT_OPTIONS:MPN533USB}
PN533USB_DRIVER=pn533_usb,
.else
PN533USB_DRIVER=
.endif

CONFIGURE_ARGS+=--with-drivers="${ACR122_DRIVER}${ARYGON_DRIVER}${PN531USB_DRIVER}${PN532UART_DRIVER}${PN533USB_DRIVER}"

.if ${PORT_OPTIONS:MSERIALPROBE}
CONFIGURE_ARGS+=--enable-serial-autoprobe
.else
CONFIGURE_ARGS+=--disable-serial-autoprobe
.endif

.if ${PORT_OPTIONS:MACR122}
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS+=	${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/FreeBSD/libccid.so:${PORTSDIR}/devel/libccid
.endif

.if ${PORT_OPTIONS:MPN531USB} || ${PORT_OPTIONS:MPN533USB}
.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
.endif
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pn53x.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
