# New ports collection makefile for:	mpio-driver
# Date created:				19 Jun 2003
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
CATEGORIES=	audio
MASTER_SITES=	SF/mpio
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digit@lway MPIO MP3 player tool

USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
USE_AUTOTOOLS=	autoconf:262
.endif

post-patch:
.if ${OSVERSION} >= 800069
	${RM} -f ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
