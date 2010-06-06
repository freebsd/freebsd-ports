# New ports collection makefile for:	mp3blaster
# Date created:		5 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mp3blaster
PORTVERSION=	3.2.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	MP3 console ncurses-based player

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}"
MAKE_JOBS_SAFE=	yes

MAN1=		mp3blaster.1 nmixer.1 splay.1

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS=	LIRC "LIRC support" off \
		SIDPLAY "Sidplayer support" on \
		VORBIS "Ogg Vorbis support" on

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS CREDITS ChangeLog FAQ README TODO
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LIRC)
LIB_DEPENDS+=		lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--with-lirc
.endif

.if !defined(WITHOUT_SIDPLAY)
LIB_DEPENDS+=		sidplay.1:${PORTSDIR}/audio/libsidplay
.else
CONFIGURE_ARGS+=	--without-sidplay
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--without-oggvorbis
.else
LIB_DEPENDS+=		vorbisfile.6:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--with-sdl
USE_SDL=	yes
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if defined(WITH_NAS)
CONFIGURE_ARGS+=	--with-nas
LIB_DEPENDS+=		audio.2:${PORTSDIR}/audio/nas
LDFLAGS+=		-laudio
.else
CONFIGURE_ARGS+=	--without-nas
.endif

.if ${HAVE_GNOME:Mesound} != ""
USE_GNOME+=     	esound
CONFIGURE_ARGS+=	--with-esd
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/mp3blaster/win2koi.tbl|${DATADIR}/charmap/win2koi.tbl|' \
				${WRKSRC}/doc/sample.mp3blasterrc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
