# New ports collection makefile for:	libopendaap
# Date created:		2004-03-10
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libopendaap
PORTVERSION=	0.1.2
CATEGORIES=	devel net
MASTER_SITES=	http://crazney.net/programs/itunes/files/

MAINTAINER=	ahze@ahze.net
COMMENT=	C lib used to connect to iTunes(R) music shares

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack pkgconfig lthack
USE_LIBTOOL=	yes
USE_GCC=	3.3

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DNOT_HAVE_SA_LEN||' \
		${WRKSRC}/mDNS/Makefile.am \
		${WRKSRC}/mDNS/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
