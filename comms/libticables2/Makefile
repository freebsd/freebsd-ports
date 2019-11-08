# $FreeBSD$

PORTNAME=	libticables2
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.18

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	TI calculator link cables library

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's/libusb >= 0\.1\.[0-9]*/libusb-0.1/' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/cuad/cuau/' \
		${WRKSRC}/src/linux/link_ser.c ${WRKSRC}/src/linux/link_gry.c

.include <bsd.port.mk>
