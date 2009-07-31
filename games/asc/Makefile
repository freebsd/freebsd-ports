# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	1.16.4.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	asc-hq
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn based, multiplayer strategic game with very nice graphics

LIB_DEPENDS=	paragui.4:${PORTSDIR}/x11-toolkits/paragui \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	image mm mixer sdl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		CXXFLAGS="-D_UNICODE_BROKEN_" \
		LIBS="`${SDL_CONFIG} --libs` -lm"

CONFIGURE_ARGS=	--disable-paraguitest	\
		--prefix=${PREFIX}

OPTIONS=	MUSIC "Install extra music files" off

MAN6=		asc.6 asc_demount.6 asc_mount.6 asc_mapedit.6 asc_makegfx.6 asc_weaponguide.6

.include <bsd.port.pre.mk>

.if defined(WITH_MUSIC)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 time_to_strike.mp3 machine_wars.mp3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUB+=	MUSIC:=""
.else
PLIST_SUB+=	MUSIC:="@comment "
.endif

pre-configure:
.if defined(WITH_MUSIC)
	${CP}  ${DISTDIR}/frontiers.mp3 ${WRKSRC}/data/music
	${CP}  ${DISTDIR}/time_to_strike.mp3 ${WRKSRC}/data/music
	${CP}  ${DISTDIR}/machine_wars.mp3 ${WRKSRC}/data/music
.endif

pre-build:
	@${FIND} ${WRKSRC}/source -name \*.cpp | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<malloc.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC}/source -name \*.h | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<malloc.h>|<stdlib.h>|'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
