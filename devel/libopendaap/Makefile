# New ports collection makefile for:	libopendaap
# Date created:		2004-03-10
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libopendaap
PORTVERSION=	0.2.3
CATEGORIES=	devel net
MASTER_SITES=	http://craz.net/programs/itunes/files/

MAINTAINER=	ahze@ahze.net
COMMENT=	C lib used to connect to iTunes(R) music shares

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_INC_LIBTOOL_VER=15
USE_GCC=	3.3

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

INSTALLS_SHLIB=	yes

pre-configure:
# Broken libtool fix
	@cd ${WRKSRC} && \
		${LIBTOOLIZE} --force

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/opendaap.pc.in

.include <bsd.port.mk>
