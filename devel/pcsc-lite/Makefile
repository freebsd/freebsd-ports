# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.2.0.r1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	http://alioth.debian.org/download.php/373/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	toni@soth.at
COMMENT=	A smartcard development library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--enable-debug \
		--enable-syslog \
		--enable-runpid=/var/run/pcscd.pid \
		--enable-ipcdir=/var/tmp/ \
		--enable-confdir=${PREFIX}/etc/ \
		--enable-usbdropdir=${PREFIX}/pcsc/drivers/ \
		--enable-muscledropdir=${PREFIX}/pcsc/services/ \
		--enable-threadsafe
PKGMESSAGE=	${WRKDIR}/pkg-message
MAN1=		formaticc.1
MAN8=		bundleTool.8 pcscd.8

.if defined(WITH_USB)
LIB_DEPENDS+=	usb-0.1.7:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=--enable-libusb=${PREFIX}
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "pcsc-lite has the following option(s):"
	@${ECHO_MSG} "  WITH_USB=yes            Enable USB support"
	@${ECHO_MSG}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcsc-lite-0.8.7.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/muscle-api-1.3.0.pdf ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/pcsc/drivers
	@${MKDIR} ${PREFIX}/pcsc/services
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
