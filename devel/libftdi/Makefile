# New ports collection makefile for:	libftdi
# Date created:				2006-07-27
# Whom:					Olexandr Davydenko <o.davydenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libftdi
PORTVERSION=	0.10
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/de/produkte/opensource/ftdi/TGZ/

MAINTAINER=	o.davydenko@gmail.com
COMMENT=	A library (using libusb) to talk to FTDI chips

LIB_DEPENDS=	usb-0.1:${PORTSDIR}/devel/libusb

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=		yes
USE_GNOME=		pkgconfig gnomehack

PORTDOCS=		COPYING.LIB ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
