# New ports collection makefile for:	kuklomenos
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	kuklomenos
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	http://mbays.freeshell.org/kuklomenos/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but challenging abstract shoot-em-up game

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

OPTIONS=	VORBIS "Enable Ogg/Vorbis support" on

USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--datadir=${DATADIR}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-sound
PLIST_SUB+=	VORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^sounds_DATA/s|Makefile.am||g' ${WRKSRC}/sounds/Makefile.in

.if ${OSVERSION} < 700000
IGNORE=		does not compile
.endif

.include <bsd.port.post.mk>
