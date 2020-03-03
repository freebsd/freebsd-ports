# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.2.5
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

USES=		tar:bzip2 uidfix

OPTIONS_DEFINE=	BLUETOOTH BT_SPEAKER DEBUG EQUALIZER
OPTIONS_DEFAULT=BLUETOOTH EQUALIZER

MAKE_ARGS=	HAVE_CUSE="YES"

BLUETOOTH_DESC=	Build with bluetooth support
BLUETOOTH_MAKE_ARGS=	HAVE_BLUETOOTH="YES"

BT_SPEAKER_DESC=	Build with bluetooth speaker utility
BT_SPEAKER_PLIST_FILES= sbin/virtual_bt_speaker \
			man/man8/virtual_bt_speaker.8.gz
BT_SPEAKER_MAKE_ARGS=	HAVE_BLUETOOTH_SPEAKER="YES"

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
