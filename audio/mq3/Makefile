# New ports collection makefile for:	mq3
# Date created:				16 Jan 2001
# Whom:					Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	mq3
PORTVERSION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.mq3.org/source/

MAINTAINER=	erich@tacni.net

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		vorbis.1:${PORTSDIR}/audio/libvorbis \
		qthreads.0:${PORTSDIR}/lang/guile
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_QT_VER=	2
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	CPPFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib}" \
		INCDIR_QT="${X11BASE}/include/qt2" \
		LIBDIR_QT="${X11BASE}/lib" \
		QTDIR="${X11BASE}"
CONFIGURE_ARGS=	-prefix ${PREFIX} -platform FreeBSD

.include <bsd.port.mk>
