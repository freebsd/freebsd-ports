# Created by: Sean Bruno <sbruno@freebsd.org>
# $FreeBSD$

PORTNAME=	idjc
PORTVERSION=	0.8.14
CATEGORIES=	audio python
MASTER_SITES=	SF/idjc/idjc/0.8

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Shoutcast/Icecast DJ Console

LICENSE=	LGPL20

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libavutil.so:${PORTSDIR}/multimedia/ffmpeg \
		libjack.so:${PORTSDIR}/audio/jack \
		libtwolame.so:${PORTSDIR}/audio/twolame \
		libspeex.so:${PORTSDIR}/audio/speex \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libmpg123.so:${PORTSDIR}/audio/mpg123 \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libmp3lame.so:${PORTSDIR}/audio/lame \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libshout-idjc.so:${PORTSDIR}/audio/shout-idjc
RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus

USES=			desktop-file-utils gettext gmake pathfix pkgconfig
CONFIGURE_ENV+=		PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man
MAKE_JOBS_UNSAFE=	yes
HAS_CONFIGURE=		yes
USE_PYTHON=		2.7
USE_PYTHON_PREFIX=	yes
USE_GNOME=		glib20 pygtk2
USE_GCC=		4.6+

MANLANG=		"" fr it
PLIST_SUB+=		PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	audio/shout-idjc IPv6 problem on compile in sock.c
.endif

pre-install:
	${REINPLACE_CMD} 's|libvorbis.so.0|libvorbis.so|' \
		${WRKSRC}/python/format.py
	${REINPLACE_CMD} 's|#! /usr/local/bin/python2.72.7|#\!${LOCALBASE}/bin/${PYTHON_VERSION}|' \
		${WRKSRC}/idjc

.include <bsd.port.post.mk>
