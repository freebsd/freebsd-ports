# Created by: Toni Andjelkovic <toni@soth.at>
# $FreeBSD$

PORTNAME=	pcsc-lite
PORTVERSION=	1.8.17
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4173/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Smartcard development library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix perl5 pkgconfig shebangfix tar:bzip2
USE_PERL5=	build
USE_RC_SUBR=	pcscd
SHEBANG_FILES=	${WRKSRC}/src/spy/pcsc-spy

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/ \
		LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s,^datadir,#datadir,; s,^data_DATA,#data_DATA," \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s,libusb-1.0/libusb.h,libusb.h,; \
		s,libusb_strerror(ret),ret," ${WRKSRC}/configure \
			${WRKSRC}/src/hotplug_libusb.c
	${REINPLACE_CMD} -e "s,-ldl,," ${WRKSRC}/src/spy/Makefile.in

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^install-data-am: / s|install-docDATA||' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/services
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message

.include <bsd.port.mk>
