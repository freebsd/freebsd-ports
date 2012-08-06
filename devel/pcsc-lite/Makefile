# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.8.5
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	https://alioth.debian.org/frs/download.php/3741/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A smartcard development library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gnomehack pkgconfig
USE_RC_SUBR=	pcscd

USE_LDCONFIG=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="${LIBS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-ipcdir=/var/tmp/ \
		--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		pcsc-spy.1
MAN5=		reader.conf.5
MAN8=		pcscd.8

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_USB) && ${OSVERSION} >= 800069
CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb"
CONFIGURE_ARGS+=--enable-libusb=/usr
.else
BROKEN=		FreeBSD 7.x does not ship with a supported libusb
.endif

post-patch:
	${REINPLACE_CMD} -e "s,^datadir,#datadir,; s,^data_DATA,#data_DATA," \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s,libusb-1.0/libusb.h,libusb.h,; \
		s,libusb_strerror(ret),ret," ${WRKSRC}/configure \
			${WRKSRC}/src/hotplug_libusb.c
	${REINPLACE_CMD} -e "s,-ldl,," ${WRKSRC}/src/spy/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install-data-am: / s|install-docDATA||' ${WRKSRC}/doc/Makefile.in
.endif

pre-everything::
.if !defined(WITHOUT_USB) && ${OSVERSION} >= 800069
	@${ECHO_MSG}
	@${ECHO_MSG} "pcsc-lite has the following option(s):"
	@${ECHO_MSG} "  WITHOUT_USB=yes            Disable USB support"
	@${ECHO_MSG}
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${EXAMPLESDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${PREFIX}/lib/pcsc/services
	${TOUCH} ${PREFIX}/lib/pcsc/drivers/.keep_me
	${TOUCH} ${PREFIX}/lib/pcsc/services/.keep_me
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
