# New ports collection makefile for:	mpio-driver
# Date created:				19 Jun 2003
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/mpio
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digit@lway MPIO MP3 player tool

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
.endif

post-patch:
.if ${OSVERSION} >= 800069
	${RM} -f ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
