# New ports collection makefile for:	ecasound
# Date created:		22 dec 2000
# Whom:			The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ecasound
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multitrack audio processing software

USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-pyecasound --disable-rubyecasound --with-largefile \
		--enable-sys-readline
INSTALLS_SHLIB=	yes

MAN1=		ecasound-iam.1 ecasound.1 ecatools.1 ecaconvert.1 \
		ecafixdc.1 ecalength.1 ecamonitor.1 ecanormalize.1 \
		ecaplay.1 ecasignalview.1
MAN5=		ecasoundrc.5

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CFLAGS+=	-fpermissive
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if defined(WITH_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--disable-libsamplerate --disable-sndfile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| $$EXTRAGCCFLAGS||g ; \
		 s| -pthread||g ; \
		 s| -D_THREAD_SAFE||g ; \
		 s| -D_P1003_1B_VISIBLE||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
