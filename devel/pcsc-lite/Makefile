# Created by: Toni Andjelkovic <toni@soth.at>
# $FreeBSD$

PORTNAME=	pcsc-lite
PORTVERSION=	1.8.24
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	https://pcsclite.apdu.fr/files/

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Middleware library to access a smart card using SCard API (PC/SC)

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix perl5 pkgconfig python:2.7,build shebangfix tar:bzip2
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	pcscd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-libsystemd \
		--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/

INSTALL_TARGET=	install-strip
SHEBANG_FILES=	src/spy/pcsc-spy
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_GROUP=		FEATURES
OPTIONS_GROUP_FEATURES=	FILTER
FEATURES_DESC=		Default features knobs
FILTER_DESC=		Control (Ignore or Extend) reader names reported by PCSC
FILTER_CONFIGURE_ENABLE=	filter

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/services

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.in ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
