# New ports collection makefile for:	fmit
# Date created:		2007-09-08
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fmit
PORTVERSION=	0.97.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/fmit/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		fftw3.5:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-alsa bnv_cv_qt_test_result=yes
CONFIGURE_ENV+=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_QT_VER=	3
USE_GL=		glut glu gl

.include <bsd.port.mk>
