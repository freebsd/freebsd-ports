# New ports collection makefile for:	theora
# Date created:				09 februari 2003
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	libtheora
PORTVERSION=	1.0.a3
CATEGORIES=	graphics
MASTER_SITES=	http://www.theora.org/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a3/alpha3/}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Theora video codec for the Ogg multimedia streaming system

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHEAD_LIBS}"
CONFIGURE_ARGS=	--disable-sdltest \
		--enable-shared

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g; \
		s|-O2||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL11/SDL.h|g; \
		s|machine/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/examples/player_example.c
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/examples/Makefile.in

do-install:
	for i in ${WRKSRC}/lib/.libs/libtheora.so.0		\
			${WRKSRC}/lib/.libs/libtheora.so	\
			${WRKSRC}/lib/.libs/libtheora.a ; do	\
		${INSTALL_DATA} $$i ${PREFIX}/lib ;		\
	done
	@${MKDIR} ${PREFIX}/include/theora
	@${INSTALL_DATA} ${WRKSRC}/include/theora/theora.h	\
		${PREFIX}/include/theora/

.include <bsd.port.mk>
