# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.6.0
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3279/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A smartcard development library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_RC_SUBR=	pcscd

USE_LDCONFIG=	yes
CONFIGURE_ENV+=	LIBS="${LIBS} ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
CONFIGURE_ARGS+=--enable-ipcdir=/var/tmp/ \
		--enable-confdir=${PREFIX}/etc/ \
		--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/ \

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN5=		reader.conf.5
MAN8=		pcscd.8

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_USB)
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
USBBASE=	${LOCALBASE}
. else
USBBASE=	/usr
CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb"
. endif
CONFIGURE_ARGS+=--enable-libusb=${USBBASE} \
		--disable-libhal
.else
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

post-patch:
	${REINPLACE_CMD} -e "s,^datadir,#datadir,; s,^data_DATA,#data_DATA," ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s,^confdir,#sysconfdir,; s,^conf_DATA,#sysconf_DATA,; s,^EXTRA_DIST,#EXTRA_DIST," ${WRKSRC}/etc/Makefile.in

pre-everything::
.if !defined(WITHOUT_USB)
	@${ECHO_MSG}
	@${ECHO_MSG} "pcsc-lite has the following option(s):"
	@${ECHO_MSG} "  WITHOUT_USB=yes            Disable USB support"
	@${ECHO_MSG}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${PREFIX}/lib/pcsc/services
	${TOUCH} ${PREFIX}/lib/pcsc/drivers/.keep_me
	${TOUCH} ${PREFIX}/lib/pcsc/services/.keep_me
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
