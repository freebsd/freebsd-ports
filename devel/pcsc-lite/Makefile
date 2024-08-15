PORTNAME=	pcsc-lite
PORTVERSION=	2.3.0
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	https://pcsclite.apdu.fr/files/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Middleware library to access a smart card using SCard API (PC/SC)
WWW=		https://pcsclite.apdu.fr/

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson perl5 pkgconfig python:env shebangfix tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	pcscd

SHEBANG_FILES=	src/spy/pcsc-spy

.include "Makefile.common"

MESON_ARGS=	-Dlibsystemd=false \
		-Dlibudev=false \
		-Dlibusb=true \
		-Dusb=true \
		-Dusbdropdir=${USBDROPDIR}/ \
		-Dipcdir=/var/run

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES POLKIT
OPTIONS_DEFAULT=	POLKIT
OPTIONS_GROUP=		FEATURES
OPTIONS_GROUP_FEATURES=	FILTER
OPTIONS_SUB=	yes

FEATURES_DESC=	Default features knobs
FILTER_DESC=	Control (Ignore or Extend) reported reader names
POLKIT_DESC=	Polkit authorization support

FILTER_MESON_TRUE=	filter_names

POLKIT_LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit
POLKIT_MESON_TRUE=	polkit

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/services

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/Makefile.am ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example/pcsc_demo.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
