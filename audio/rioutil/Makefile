# New ports collection makefile for:   rioutil
# Date created:        01 July 2001
# Whom:                greid
#
# $FreeBSD$
#

PORTNAME=	rioutil
PORTVERSION=	1.4.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to inferface with the Rio600, Rio800 and psa[play devices

LIB_DEPENDS=	usb-0.1.7:${PORTSDIR}/devel/libusb

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		rioutil.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

.include <bsd.port.mk>
