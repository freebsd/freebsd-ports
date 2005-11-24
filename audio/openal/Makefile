# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	20050401
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://math.missouristate.edu/~erik/files/fbsd/\
		http://www.smluc.org/~erik/files/fbsd/

MAINTAINER=	erik@smluc.org
COMMENT=	A 3D positional spatialized sound library

INFO=		openal

WRKSRC=		${WRKDIR}/${DISTNAME}/linux
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-capture
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
WANT_SDL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

OPTIONS=	ARTS "aRts backend" off \
		ESD "esd backend" off \
		SDL "SDL backend" off \
		VORBIS "vorbis support" off \
		SMPEG "smpeg support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SMPEG)
WITH_SDL=	yes	# smpeg requires SDL
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
.endif

.if defined(WITH_ESD)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ENV+=	HAVESDL="${SDL_CONFIG}"
CONFIGURE_ARGS+=--enable-sdl
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.endif

.if defined(WITH_SMPEG)
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--enable-smpeg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/; \
		/CPPFLAGS=/ d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/#include/ s|SDL/||' \
		${WRKSRC}/src/extensions/al_ext_mp3.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include <bsd.port.post.mk>
