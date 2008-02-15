# New ports collection makefile for:	rioutil
# Date created:				01 July 2001
# Whom:					George Reid <greid@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rioutil
PORTVERSION=	1.5.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to inferface with the Rio600, Rio800, and psa[play devices

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		rioutil.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e 's,read_buffer = .*),(&),' \
		${WRKSRC}/librioutil/rio.c

.include <bsd.port.mk>
