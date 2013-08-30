# Created by: Michael Vasilenko <acid@stu.cn.ua>
# $FreeBSD$

PORTNAME=	mp3blaster
PORTVERSION=	3.2.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	MP3 console ncurses-based player

USES=		gmake
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}"

MAN1=		mp3blaster.1 nmixer.1 splay.1

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	LIRC SIDPLAY VORBIS DOCS
OPTIONS_DEFAULT=	SIDPLAY VORBIS
SIDPLAY_DESC=	Sidplayer support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS CREDITS ChangeLog FAQ README TODO
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=		lirc_client.2:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--with-lirc
.endif

.if ${PORT_OPTIONS:MSIDPLAY}
LIB_DEPENDS+=		sidplay.1:${PORTSDIR}/audio/libsidplay
.else
CONFIGURE_ARGS+=	--without-sidplay
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=		vorbisfile.6:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=	--with-sdl
USE_SDL=	yes
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if ${PORT_OPTIONS:MNAS}
CONFIGURE_ARGS+=	--with-nas
LIB_DEPENDS+=		audio.2:${PORTSDIR}/audio/nas
LDFLAGS+=		-laudio
.else
CONFIGURE_ARGS+=	--without-nas
.endif

.include <bsd.port.pre.mk>
.if ${HAVE_GNOME:Mesound} != ""
USE_GNOME+=		esound
CONFIGURE_ARGS+=	--with-esd
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/mp3blaster/win2koi.tbl|${DATADIR}/charmap/win2koi.tbl|' \
				${WRKSRC}/doc/sample.mp3blasterrc

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
