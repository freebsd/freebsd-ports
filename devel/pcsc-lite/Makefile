# Created by: Toni Andjelkovic <toni@soth.at>
# $FreeBSD$

PORTNAME=	pcsc-lite
PORTVERSION=	1.8.10
PORTEPOCH=	2
CATEGORIES=	devel security
#MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/3963/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A smartcard development library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake perl5 pathfix pkgconfig
USE_PERL5=	build
USE_RC_SUBR=	pcscd

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/

PKGMESSAGE=	${WRKDIR}/pkg-message

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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/services
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers/.keep_me
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/pcsc/services/.keep_me
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
