# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.4.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	eXtace

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_ESOUND=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_LIBFFTW" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g'

.include <bsd.port.post.mk>
