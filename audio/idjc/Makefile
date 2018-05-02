# Created by: Sean Bruno <sbruno@freebsd.org>
# $FreeBSD$

PORTNAME=	idjc
PORTVERSION=	0.8.16
PORTREVISION=	9
CATEGORIES=	audio python
MASTER_SITES=	SF/idjc/idjc/0.8

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Shoutcast/Icecast DJ Console

LICENSE=	LGPL20

BROKEN=		fails to build with ffmpeg 4.0

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		libtwolame.so:audio/twolame \
		libspeex.so:audio/speex \
		libsndfile.so:audio/libsndfile \
		libmpg123.so:audio/mpg123 \
		libFLAC.so:audio/flac \
		libmp3lame.so:audio/lame \
		libvorbis.so:audio/libvorbis \
		libsamplerate.so:audio/libsamplerate \
		libshout-idjc.so:audio/shout-idjc
RUN_DEPENDS=	oggenc:audio/vorbis-tools \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	YES

USES=		compiler:nestedfct desktop-file-utils gettext gmake \
		libtool pathfix pkgconfig python:2.7
LDFLAGS+=	-L${LOCALBASE}/lib
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=		yes
USE_PYTHON=		pythonprefix
USE_GNOME=		glib20 pygtk2

BROKEN_powerpc64=	Does not build

PLIST_SUB+=		PORTVERSION="${PORTVERSION}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's,PYTHON=python,PYTHON=${PYTHON_CMD},' ${WRKSRC}/py-compile

pre-install:
	${REINPLACE_CMD} 's|libvorbis.so.0|libvorbis.so|' \
		${WRKSRC}/python/format.py
	${REINPLACE_CMD} 's|#! /usr/local/bin/python2.72.7|#\!${PYTHON_CMD}|' \
		${WRKSRC}/idjc

.include <bsd.port.mk>
