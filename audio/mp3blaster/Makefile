# New ports collection makefile for:	mp3blaster
# Date created:		5 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mp3blaster
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP3 console ncurses-based player

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}"

MAN1=		mp3blaster.1 nmixer.1 splay.1

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS=	LIRC "LIRC support" off \
		SIDPLAY "Sidplayer support" on \
		VORBIS "Ogg Vorbis support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.0:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--with-lirc
.endif

.if !defined(WITHOUT_SIDPLAY)
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
.else
CONFIGURE_ARGS+=	--without-sidplay
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--without-oggvorbis
.else
LIB_DEPENDS+=	vorbisfile.4:${PORTSDIR}/audio/libvorbis
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "getopt*" -delete

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/mp3blaster/win2koi.tbl|${DATADIR}/charmap/win2koi.tbl|' \
				${WRKSRC}/doc/sample.mp3blasterrc

.include <bsd.port.post.mk>
