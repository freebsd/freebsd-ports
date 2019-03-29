# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

USES=		tar:bzip2 uidfix

OPTIONS_DEFINE=	BLUETOOTH DEBUG EQUALIZER
OPTIONS_DEFAULT=BLUETOOTH EQUALIZER

.if exists(/usr/lib/libcuse.so)
MAKE_ARGS=	HAVE_CUSE="YES"
.else
BUILD_DEPENDS+=	cuse4bsd-kmod>=0.1.24:multimedia/cuse4bsd-kmod
LIB_DEPENDS+=	libcuse4bsd.so:multimedia/cuse4bsd-kmod
.endif

BLUETOOTH_DESC=	Build with bluetooth support
BLUETOOTH_MAKE_ARGS=	HAVE_BLUETOOTH="YES"
BLUETOOTH_PLIST_FILES=  sbin/virtual_bt_speaker \
                        man/man8/virtual_bt_speaker.8.gz

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

EQUALIZER_DESC=	Build with equalizer utility
EQUALIZER_MAKE_ARGS=	HAVE_EQUALIZER="YES"
EQUALIZER_LIB_DEPENDS=	libfftw3.so:math/fftw3
EQUALIZER_PLIST_FILES=	sbin/virtual_equalizer \
			man/man8/virtual_equalizer.8.gz

PLIST_FILES=	sbin/virtual_oss \
		man/man8/virtual_oss.8.gz

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

.include <bsd.port.mk>
