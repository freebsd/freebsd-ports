# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.2.6
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

USES=		tar:bzip2 uidfix
USE_RC_SUBR=	virtual_oss

SUB_LIST+=	LIBSAMPLERATE="${LOCALBASE}/lib/libsamplerate.so:"

OPTIONS_DEFINE=	BLUETOOTH BT_SPEAKER DEBUG EQUALIZER HTTPD
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
EQUALIZER_SUB_LIST=	LIBFFTW3="${LOCALBASE}/lib/libfftw3.so:"
EQUALIZER_SUB_LIST_OFF=	LIBFFTW3=""

HTTPD_DESC=		Build with HTTP server support
HTTPD_MAKE_ARGS=	HAVE_HTTPD="YES"

PLIST_FILES=	sbin/virtual_oss \
		man/man8/virtual_oss.8.gz

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

.include <bsd.port.mk>
