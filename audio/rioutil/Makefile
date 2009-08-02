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

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		rioutil.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=  ${FILESDIR}/extra-patch-configure.ac
USE_AUTOTOOLS=	autoconf:262
.endif

post-extract:
#	@${RM} -f ${WRKSRC}/src/getopt*
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e 's,read_buffer = .*),(&),' \
		${WRKSRC}/librioutil/rio.c

.include <bsd.port.post.mk>
