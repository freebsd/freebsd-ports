# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.7.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	extace

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gtk12 imlib esound
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_LIBFFTW" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"  \
		-e "s|DATADIRNAME=lib|DATADIRNAME=share|g"  ${WRKSRC}/configure

.include <bsd.port.mk>
