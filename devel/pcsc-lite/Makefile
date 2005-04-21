# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.2.9.b.7
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	http://alioth.debian.org/download.php/975/
DISTNAME=	pcsc-lite-${PORTVERSION:S/.b./-beta/}

MAINTAINER=	toni@soth.at
COMMENT=	A smartcard development library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_INC_LIBTOOL_VER=	15

WRKSRC=		${WRKDIR}/pcsc-lite-1.2.9-beta7
INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--enable-debug \
		--enable-syslog \
		--enable-runpid=/var/run/pcscd.pid \
		--enable-ipcdir=/var/tmp/ \
		--enable-confdir=${PREFIX}/etc/ \
		--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/ \
		--enable-muscledropdir=${PREFIX}/lib/pcsc/services/ \
		--enable-threadsafe
USE_REINPLACE=	yes
USE_GETOPT_LONG=yes

PKGMESSAGE=	${WRKDIR}/pkg-message
MAN1=		formaticc.1
MAN5=		reader.conf.5
MAN8=		pcscd.8

.if !defined(WITHOUT_USB)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=--enable-libusb=${PREFIX}
.endif

post-patch:
	${REINPLACE_CMD} -e "s,^datadir,#datadir,; s,^data_DATA,#data_DATA," ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s,^confdir,#sysconfdir,; s,^conf_DATA,#sysconf_DATA,; s,^EXTRA_DIST,#EXTRA_DIST," ${WRKSRC}/etc/Makefile.in

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "pcsc-lite has the following option(s):"
	@${ECHO_MSG} "  WITHOUT_USB=yes            Disable USB support"
	@${ECHO_MSG}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcsc-lite.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ifdhandler-3.pdf ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${PREFIX}/lib/pcsc/services
	${TOUCH} ${PREFIX}/lib/pcsc/drivers/.keep_me
	${TOUCH} ${PREFIX}/lib/pcsc/services/.keep_me
	${MKDIR} ${PREFIX}/etc/reader.conf.d
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.d/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
