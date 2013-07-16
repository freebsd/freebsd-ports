# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darkice
PORTVERSION=	1.1
PORTREVISION?=	2
CATEGORIES=	audio net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IceCast, IceCast2, and ShoutCast live audio streamer

LICENSE=	GPLv3

OPTIONS_DEFINE=	JACK
OPTIONS_MULTI=	CODEC
OPTIONS_MULTI_CODEC=	VORBIS LAME TWOLAME FAAC AACPLUS
OPTIONS_DEFAULT=	VORBIS

AACPLUS_DESC=	AAC HEv2 and libsamplerate support

USE_AUTOTOOLS=	aclocal autoconf
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_acx_pthread_config=no
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS=	--without-alsa

SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

MAN1=		darkice.1
MAN5=		darkice.cfg.5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=	twolame:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--with-twolame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-twolame
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	faac:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${PORT_OPTIONS:MAACPLUS}
LIB_DEPENDS+=	aacplus:${PORTSDIR}/audio/libaacplus \
		samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--with-aacplus-prefix=${LOCALBASE} \
			--with-samplerate-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-aacplus --without-samplerate
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g'\
	 -e 's/sbr_main.h/libaacplus\/sbr_main.h/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2 -pedantic||g' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg \
		${PREFIX}/etc/${PORTNAME}.cfg.dist
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.cfg.5 ${MAN5PREFIX}/man/man5

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
	@if [ ! -f ${PREFIX}/etc/darkice.cfg ]; then \
		${CP} -p ${PREFIX}/etc/darkice.cfg.dist ${PREFIX}/etc/darkice.cfg ; \
	fi

.include <bsd.port.mk>
