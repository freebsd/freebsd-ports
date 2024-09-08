PORTNAME=	virtual_oss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	christos@FreeBSD.org
COMMENT=	Virtual OSS multi device mixer application
WWW=		https://github.com/freebsd/virtual_oss

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

USES=		uidfix
USE_RC_SUBR=	virtual_oss

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

SUB_LIST+=	LIBSAMPLERATE="${LOCALBASE}/lib/libsamplerate.so:"

OPTIONS_DEFINE=	BLUETOOTH BT_SPEAKER COMMAND DEBUG EQUALIZER HTTPD SNDIO
OPTIONS_DEFAULT=BLUETOOTH BT_SPEAKER COMMAND EQUALIZER

.if exists(/usr/include/sys/sndstat.h)
MAKE_ARGS+=	HAVE_SNDSTAT="YES"
.endif

BLUETOOTH_DESC=	Build with bluetooth support
BLUETOOTH_MAKE_ARGS=	HAVE_BLUETOOTH="YES"

BT_SPEAKER_DESC=	Build with bluetooth speaker utility
BT_SPEAKER_PLIST_FILES=	sbin/virtual_bt_speaker \
			share/man/man8/virtual_bt_speaker.8.gz
BT_SPEAKER_MAKE_ARGS=	HAVE_BLUETOOTH_SPEAKER="YES"

COMMAND_DESC=		Build with command utility
COMMAND_MAKE_ARGS=	HAVE_COMMAND="YES"
COMMAND_PLIST_FILES=	sbin/virtual_oss_cmd \
			share/man/man8/virtual_oss_cmd.8.gz

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

EQUALIZER_DESC=	Build with equalizer utility
EQUALIZER_MAKE_ARGS=	HAVE_EQUALIZER="YES"
EQUALIZER_LIB_DEPENDS=	libfftw3.so:math/fftw3
EQUALIZER_PLIST_FILES=	sbin/virtual_equalizer \
			share/man/man8/virtual_equalizer.8.gz
EQUALIZER_SUB_LIST=	LIBFFTW3="${LOCALBASE}/lib/libfftw3.so:"
EQUALIZER_SUB_LIST_OFF=	LIBFFTW3=""

HTTPD_DESC=		Build with HTTP server support
HTTPD_MAKE_ARGS=	HAVE_HTTPD="YES"

SNDIO_DESC=		Build with sndio(7) backend support
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_MAKE_ARGS=	HAVE_SNDIO="YES"

PLIST_FILES=	sbin/virtual_oss \
		share/man/man8/virtual_oss.8.gz

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

post-patch:
	${REINPLACE_CMD} -e 's|$${PREFIX}/man/man|$${PREFIX}/share/man/man|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
