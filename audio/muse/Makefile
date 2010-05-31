# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MuSE
PORTVERSION=	0.9.2
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.dyne.org/muse/releases/ \
		http://www.ljudmila.org/~jaromil/muse/releases/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.6:${PORTSDIR}/audio/libogg

BROKEN=		does not compile

USE_GETTEXT=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug --disable-lubrify --disable-rpath
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT -DHAVE_SYS_UIO_H \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl

OPTIONS=	X11	"Build with X11 support" on \
		MP3	"Build with MP3 support" on \
		SNDFILE	"Build with sndfile support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--without-x --with-rubik
.else
USE_GNOME+=	gtk20
.endif

.if !defined(WITHOUT_MP3) || exists(${LOCALBASE}/lib/libmp3lame.so.0)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.endif

.if !defined(WITHOUT_SNDFILE) || exists(${LOCALBASE}/lib/libsndfile.so.1)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.endif

MAN1=		muse.1

post-patch:
.if exists(/usr/include/sys/soundcard.h)
	${REINPLACE_CMD} -e "s,machine/soundcard.h,sys/soundcard.h,g" \
		${WRKSRC}/src/portaudio/pa_unix_oss.c
.endif

.include <bsd.port.post.mk>
