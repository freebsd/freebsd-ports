# New ports collection makefile for:	libnfc
# Date created:		2009-06-17
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	libnfc
PORTVERSION=	1.3.3
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
    		http://romain.blogreen.org/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Near Field Communication (NFC) library

OPTIONS=	PCSC "Compile with PC/SC Lite support" on \
		USB  "Compile with libusb support" on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

MAN1=		nfc-mfclassic.1 nfc-emulate.1 nfc-list.1 nfc-mfultralight.1 \
		nfc-relay.1 nfc-anticol.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_PCSC)
CONFIGURE_ARGS+=--disable-pcsc-lite
.else
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS+=	RSA_SecurID_getpasswd:${PORTSDIR}/devel/libccid
CONFIGURE_ARGS+=--enable-pcsc-lite
.endif

.if defined(WITHOUT_USB)
CONFIGURE_ARGS+=--disable-libusb
.else
CONFIGURE_ARGS+=--enable-libusb
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
