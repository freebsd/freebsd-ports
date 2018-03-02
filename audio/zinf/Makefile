# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	zinf
PORTVERSION=	2.2.5
PORTREVISION=	22
CATEGORIES=	audio ipv6
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based MP3 player

LIB_DEPENDS=	libid3.so:audio/id3lib \
		libgdbm.so:databases/gdbm

USES=		alias gettext gmake libtool ncurses pathfix perl5 pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 \
		--disable-arts

CPPFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-D_WANT_SEMUN
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	ESOUND VORBIS
OPTIONS_DEFAULT=VORBIS
OPTIONS_SUB=	yes

ESOUND_CONFIGURE_OFF=	--disable-esd
ESOUND_USE=		GNOME=esound
INSTALL_TARGET=	install-strip

VORBIS_CONFIGURE_OFF=	--disable-vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
CPPFLAGS+=	"-D_M_IX86"
.else
CONFIGURE_ARGS+=	--disable-x86opts
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Player::||' ${WRKSRC}/base/include/player.h

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/sdr/plugins
	${INSTALL_DATA} ${FILESDIR}/sdr2.plugin.S100.audio.rtp.mpa.zinf \
		${STAGEDIR}${PREFIX}/etc/sdr/plugins

.include <bsd.port.post.mk>
